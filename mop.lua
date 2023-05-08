-------------
--behaviors--
-------------

------ Spring ------
-- Upon touching the spring, get launched in a set direction with a set speed, both horizontal and vertical.

---@param obj Object
function spring_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.hitboxRadius = 160
    o.hitboxHeight = 160
    o.oInteractType = INTERACT_COIN
    o.oIntangibleTimer = 0
end

function spring_loop(o)

    obj_set_model_extended(o, E_MODEL_SPRING)

    local gMarioObject = gMarioStates[0].marioObj
    local gMarioState = gMarioStates[0]
    local Yspd = 56.0
	local CarmackMeme = nil;
	local Tmp = nil;
	if (o.oAction == 0)then
		if (obj_check_if_collided_with_object(o,gMarioObject)==1) then
			set_mario_action(gMarioState,ACT_FREEFALL,0);
            gMarioState.actionTimer = 1000 -- star revenge 4.9 is free hehe
			gMarioStates[0].faceAngle.y=o.oFaceAngleYaw;
			CarmackMeme = Yspd;
			Tmp=CarmackMeme+(o.oBehParams2ndByte);
			gMarioStates[0].forwardVel=Tmp;
			CarmackMeme = CarmackMeme+((((o.oBehParams)>>24)&0xFF)>>1);
            djui_chat_message_create(tostring(CarmackMeme))
			bounce_off_object(gMarioState,o,CarmackMeme);
			gMarioStates[0].vel.y=CarmackMeme;
			o.oAction=1;
			do_fall_damage=1;
        end
	else
		if (o.oTimer==15) then
			o.oAction=0;
        end
	end
end

bhvSpring_MOP = hook_behavior(nil, OBJ_LIST_LEVEL, false, spring_init, spring_loop)

------ Flipblock ------
-- Hitting this block will cause it to spin, losing its collision until it stops spinning.

---@param obj Object
function flip_block_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.oAction = 0
    obj.oCollisionDistance = 500
    obj.collisionData = COL_FLIPBLOCK_MOP
end

---@param obj Object
function flip_block_loop(obj)
    obj_set_model_extended(obj, E_MODEL_FLIPBLOCK)

    -- Setting a temporary hitbox allows this object to not have collision for some time
    local oHitbox = get_temp_object_hitbox()
    oHitbox.interactType = INTERACT_BREAKABLE
    oHitbox.downOffset = 0
    oHitbox.damageOrCoinValue = 0
    oHitbox.health = 0
    oHitbox.numLootCoins = 0
    oHitbox.radius = 64
    oHitbox.height = 64
    oHitbox.hurtboxHeight = 0
    oHitbox.hurtboxRadius = 0

    obj.oInteractStatus = 0

    if obj.oTimer == 0 and obj.oAction == FLIP_BLOCK_ACT_INACTIVE then
        obj_set_hitbox(obj, oHitbox)
        obj.oAction = FLIP_BLOCK_ACT_IDLE
    end
    -- Do things if it starts flipping
    if obj.oAction == FLIP_BLOCK_ACT_FLIPPING then
        -- Stop flipping and prepare it for next time
        if obj.oTimer == FLIP_TIMER then
            obj.oAction = FLIP_BLOCK_ACT_IDLE
            obj.oSubAction = 0
            -- Reset size
            obj.header.gfx.scale.y = 1
        end

        -- Flips the block
        obj.oFaceAnglePitch = obj.oFaceAnglePitch + (FLIP_TIMER - obj.oTimer) * 16
        if ((obj.oFaceAnglePitch / 0x8000) - obj.oSubAction) > 0 then
            cur_obj_play_sound_1(SOUND_GENERAL_SWISH_WATER)
            -- The subaction is basically used as a timer so the condition will eventually fail
            obj.oSubAction = obj.oSubAction + 1
        end
    else
        -- Flip whenever it becomes attacked
        if cur_obj_was_attacked_or_ground_pounded() ~= 0 then
            obj.oAction = FLIP_BLOCK_ACT_FLIPPING
            obj.oIntangibleTimer = FLIP_TIMER
            obj.header.gfx.scale.y = 0.1

            cur_obj_play_sound_1(SOUND_GENERAL_SWISH_WATER)
        else
            obj.oFaceAnglePitch = 0
            obj.header.gfx.scale.z = 1.0

            load_object_collision_model()
        end
    end
end

bhvFlipBlock_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, flip_block_init, flip_block_loop)

------ Noteblock ------
-- Jumping onto this block will cause Mario to jump higher.

---@param obj Object
function noteblock_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_NOTEBLOCK_MOP
    obj.oHomeX = obj.oPosX
    obj.oHomeY = obj.oPosY
    obj.oHomeZ = obj.oPosZ

    -- I guess it's slightly larger than intended
    cur_obj_scale(0.64)
end

---@param obj Object
function noteblock_loop(obj)
    obj_set_model_extended(obj, E_MODEL_NOTEBLOCK)

    load_object_collision_model()

    local m = gMarioStates[0]

    local y_spd = 64

    if cur_obj_is_mario_on_platform() == 1 then
        --this is awful -- It really is -Sunk
        -- Jump. If A is pressed during the jump, increase y_spd.
        if m.controller.buttonPressed & A_BUTTON ~= 0 then
            y_spd = y_spd + 12
            spawn_mist_particles()
        end
        set_mario_action(m, ACT_DOUBLE_JUMP, 0)

        -- Calculates y speed
        m.vel.y = y_spd + obj.oBehParams2ndByte
        obj.oAction = NOTEBLOCK_ACT_BOUNCE
        do_fall_damage = true
    end
    if obj.oAction == NOTEBLOCK_ACT_BOUNCE then
        if obj.oTimer == 4 then
            obj.oAction = NOTEBLOCK_ACT_IDLE
            obj.oPosY = obj.oHomeY
        else
            -- Moves the noteblock slightly up and down, to give it a "bounce"
            if obj.oTimer > 2 then
                obj.oPosY = obj.oHomeY + (obj.oTimer % 3) * 6
            else
                obj.oPosY = obj.oHomeY - (obj.oTimer) * 6
            end
        end
    end
end

bhvNoteblock_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, noteblock_init, noteblock_loop)

------ Sandblock ------
-- Standing on this block causes it to slowly fall to pieces, eventually no longer becoming a platform.

---@param obj Object
function sandblock_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_SANDBLOCK_MOP
end

---@param obj Object
function sandblock_loop(obj)
    obj_set_model_extended(obj, E_MODEL_SANDBLOCK)

    -- Only activate collision if the sandblock has not disappeared
    if obj.oAction < SANDBLOCK_ACT_DISAPPEARED then
        load_object_collision_model()
    end
    -- Disappearing
    switch(obj.oAction, {
        [SANDBLOCK_ACT_DISAPPEARING] = function()
            if obj.oTimer == 300 then
                obj.oAction = SANDBLOCK_ACT_DISAPPEARED
            end
            -- Causes the sandblock to appear smaller and smaller on the y axis
            obj.header.gfx.scale.y = ((300 - obj.oTimer) / 300.0)

            -- Spawn effects
            spawn_non_sync_object(id_bhvDirtParticleSpawner, E_MODEL_NONE, obj.oPosX, obj.oPosY, obj.oPosZ, nil)
            cur_obj_play_sound_1(SOUND_ENV_MOVINGSAND)
        end,
        -- Respawns the block after it disappears
        [SANDBLOCK_ACT_DISAPPEARED] = function()
            cur_obj_hide()
            if obj.oTimer == 301 then
                obj.oAction = SANDBLOCK_ACT_IDLE
                obj.header.gfx.scale.y = 1.0
                cur_obj_unhide()
            end
        end
    })

    if cur_obj_is_mario_on_platform() == 1 and obj.oAction == SANDBLOCK_ACT_IDLE then
        obj.oAction = SANDBLOCK_ACT_DISAPPEARING
    end
end

bhvSandBlock_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, sandblock_init, sandblock_loop)

------ Flipswap platform ------
-- Jumping will cause this platform to spin, moving the land somewhere else.

---@param obj Object
function flipswap_platform_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.oFaceAngleRoll = 0
    obj.collisionData = COL_FLIPSWAP_PLATFORM_MOP
    -- Spawns the border
    local childObj = spawn_non_sync_object(bhvFlipswap_Platform_Border_MOP, E_MODEL_FLIPSWAP_PLATFORM_BORDER, obj.oPosX, obj.oPosY, obj.oPosZ, nil)
    childObj.parentObj = obj
end

---@param obj Object
function flipswap_platform_loop(obj)
    -- Make sure the border's parent object is the flipswap platforn
    local border = obj_get_first_with_behavior_id(bhvFlipswap_Platform_Border_MOP)
    border.oFaceAngleYaw = obj.oFaceAngleYaw

    obj_set_model_extended(obj, E_MODEL_FLIPSWAP_PLATFORM)

    load_object_collision_model()

    local m = gMarioStates[0]

    switch(obj.oAction, {
        [FLIPSWAP_PLATFORM_ACT_IDLE] = function ()
            -- If Mario enters an air action, start flipping
            if m.prevAction & ACT_GROUP_MASK ~= ACT_GROUP_AIRBORNE and m.action & ACT_GROUP_MASK == ACT_GROUP_AIRBORNE then
                --sloth brain it
                if obj.oFaceAngleRoll == 0 then
                    obj.oMoveAngleRoll = -2048
                else
                    obj.oMoveAngleRoll = 2048
                end
                obj.oAction = FLIPSWAP_PLATFORM_ACT_FLIPPING
            end
        end,
        [FLIPSWAP_PLATFORM_ACT_FLIPPING] = function ()
            -- Flip the platform
            if obj.oTimer < 16 then
                obj.oFaceAngleRoll = obj.oFaceAngleRoll + obj.oMoveAngleRoll
            -- Disallow flipping again until Mario lands
            elseif m.action & ACT_GROUP_MASK ~= ACT_GROUP_AIRBORNE then
                obj.oAction = FLIPSWAP_PLATFORM_ACT_IDLE
            end
        end
    })
end

bhvFlipswap_Platform_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, flipswap_platform_init, flipswap_platform_loop)

------ Checkpoint flag ------
-- Dying will cause the player to respawn at this point
-- ! gWarpCheckpoint is not exposed to lua, so this MOP doesn't really work
-- ! MOP actor doesn't seem to compile the model

gWarpCheckpoint = {
    actNum = 0,
    courseNum = 0,
    levelID = 0,
    areaNum = 0,
    warpNode = 0,
}

---@param obj Object
function bhv_checkpoint_flag_init(obj)
    local m = gMarioStates[0]
    if gWarpCheckpoint.actNum == 64 and obj.oBehParams == 0 then
        m.pos.x = obj.oPosX
        m.pos.y = obj.oPosY
        m.pos.z = obj.oPosZ
    end
end

---@param obj Object
function checkpoint_flag_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO
    obj.oInteractType = INTERACT_POLE
    obj.hitboxRadius = 64
    obj.hitboxHeight = 650
    bhv_checkpoint_flag_init(obj)
    obj.oIntangibleTimer = -1
end

---@param obj Object
function checkpoint_flag_loop(obj)
    -- Great design choice
    obj_mark_for_deletion(obj)

    obj_set_model_extended(obj, E_MODEL_CHECKPOINT)

    -- ??? No idea what this is for
    if obj.oBehParams > 0 then
        if dist_between_objects(obj, gMarioStates[0].marioObj) < 150.0 then
            gWarpCheckpoint.actNum = 0
            gWarpCheckpoint.courseNum = COURSE_NONE
        end
    -- Activates a checkpoint if Mario gets near the flag
    else
        obj.oIntangibleTimer = 0
        if dist_between_objects(obj, gMarioStates[0].marioObj) < 150.0 then
            --don't set a real checkpoint because we don't have a real
            --warp node to set it to. Instead abuse the fact that
            --in game checkopints only set the course num
            if obj.oAction == CHECKPOINT_FLAG_ACT_IDLE then
                gWarpCheckpoint.actNum = 64
                gWarpCheckpoint.courseNum = COURSE_NONE
                -- I believe this is done so the game doesn't set values every frame someone is near the flag
                obj.oAction = CHECKPOINT_FLAG_ACT_ACTIVATED
                cur_obj_play_sound_1(SOUND_GENERAL_OPEN_CHEST)
            end
        else
            obj.oAction = CHECKPOINT_FLAG_ACT_IDLE
        end
    end
end

bhvCheckpoint_Flag_MOP = hook_behavior(nil, OBJ_LIST_GENACTOR, false, checkpoint_flag_init, checkpoint_flag_loop)

------ Green switchboard ------
-- The platform moves depending on where the player is on it. Similar to the rolling log.

---@param obj Object
function green_switchboard_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL
    obj.collisionData = COL_GREEN_SWITCHBOARD_MOP
    -- Spawns gears
    -- Don't know why it uses intro lakitu cloud
    obj.oIntroLakituCloud = spawn_non_sync_object(bhvGreen_Switchboard_Gear_MOP, E_MODEL_GREEN_SWITCHBOARD_GEARS, obj.oPosX, obj.oPosY, obj.oPosZ, nil)
    obj.oIntroLakituCloud.parentObj = obj
    obj.oHomeX = obj.oPosX
    obj.oHomeY = obj.oPosY
    obj.oHomeZ = obj.oPosZ
end

---@param obj Object
function green_switchboard_loop(obj)
    obj_set_model_extended(obj, E_MODEL_GREEN_SWITCHBOARD)

    load_object_collision_model()

    local MAX_SPEED = 20.0
    local SPEED_INC = 2.0
    local child = obj.oIntroLakituCloud
    local dot = 0
    local dotH = 0
    local m = gMarioStates[0]

    if cur_obj_is_mario_on_platform() == 1 then
        local dx = m.pos.x - obj.oPosX
        local dz = m.pos.z - obj.oPosZ
        local dHx = obj.oPosX - obj.oHomeX
        local dHz = obj.oPosZ - obj.oHomeZ
        local facingZ = coss(obj.oFaceAngleYaw)
        local facingX = sins(obj.oFaceAngleYaw)

        --if dot is positive, mario is on front arrow
        dot = facingZ * dz + facingX * dx
        dotH = facingZ * dHz + facingX * dHx
        if dot > 0 then
            -- ??? Why check the behavior parameter for this?
            --if dotH < ((obj.oBehParams >> 24) & 0xFF) * 16 then
                obj.oForwardVel = approach_by_increment(MAX_SPEED, obj.oForwardVel, SPEED_INC)
            --else
            --    obj.oForwardVel = 0
            --end
            obj.oFaceAnglePitch = approach_by_increment(2048.0, obj.oFaceAnglePitch, 128.0)
        else
            -- ??? Why check the second byte of the behavior paramter for this?
            --if dotH > obj.oBehParams2ndByte * -16 then
                obj.oForwardVel = approach_by_increment(-MAX_SPEED, obj.oForwardVel, SPEED_INC)
            --else
            --    obj.oForwardVel = 0
            --end
            --this function doesn't work well with negatives thanks nintendo
            if (obj.oFaceAnglePitch > -2048) then
                obj.oFaceAnglePitch = approach_by_increment( -2048.0, obj.oFaceAnglePitch, 128.0)
            end
        end
    else
        -- Slowly resets the pitch and speed back to 0
        obj.oForwardVel = approach_by_increment(0.0, obj.oForwardVel, SPEED_INC)
        obj.oFaceAnglePitch = approach_by_increment(0.0, obj.oFaceAnglePitch, 128.0)
    end
    -- Moves the gears along with the platform
    child.oFaceAnglePitch = child.oFaceAnglePitch + (obj.oForwardVel * 200)
    obj_copy_pos(child, obj)
end

bhvGreen_Switchboard_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, green_switchboard_init, green_switchboard_loop)

------ Shrink platform ------

---@param obj Object
function shrink_platform_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_SHRINK_PLATFORM
    -- Spawns border
    local childObj = spawn_non_sync_object(bhvShrink_Platform_Border_MOP, E_MODEL_SHRINK_PLATFORM_BORDER, obj.oPosX, obj.oPosY, obj.oPosZ, nil)
    childObj.parentObj = obj
end

---@param obj Object
function shrink_platform_loop(obj)
    -- Make sure the border's parent object is the shrink platform
    obj_set_model_extended(obj, E_MODEL_SHRINK_PLATFORM)

    local border = obj_get_first_with_behavior_id(bhvShrink_Platform_Border_MOP)
    border.oFaceAngleYaw = obj.oFaceAngleYaw

    -- Only activate collision if the model is still visible
    if obj.oAction < SHRINK_PLATFORM_ACT_DISAPPEARED then
        load_object_collision_model()
    end
    --disappearing
    switch(obj.oAction, {
        [SHRINK_PLATFORM_ACT_DISAPPEARING] = function()
            if obj.oTimer == SHRINK_TIME then
                obj.oAction = SHRINK_PLATFORM_ACT_DISAPPEARED
            end
            -- Slowly shrinks the size of the platform horizontally
            obj.header.gfx.scale.x = (SHRINK_TIME - obj.oTimer) / SHRINK_TIME
            obj.header.gfx.scale.z = (SHRINK_TIME - obj.oTimer) / SHRINK_TIME
        end,
        [SHRINK_PLATFORM_ACT_DISAPPEARED] = function()
            -- Reset after the platform has fully disappeared
            cur_obj_hide()
            if obj.oTimer == SHRINK_TIME + 1 then
                obj.oAction = SHRINK_PLATFORM_ACT_IDLE
                obj.header.gfx.scale.x = 1.0
                obj.header.gfx.scale.z = 1.0
                cur_obj_unhide()
            end
        end
    })
    -- Start disappearing once Mario gets on it
    if cur_obj_is_mario_on_platform() == 1 and obj.oAction == SHRINK_PLATFORM_ACT_IDLE then
        obj.oAction = SHRINK_PLATFORM_ACT_DISAPPEARING
        cur_obj_play_sound_1(SOUND_OBJ_UNK23)
    end
end

bhvShrink_Platform_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, shrink_platform_init, shrink_platform_loop)

------ Flipswitch panel ------
-- Jumping onto a panel activates it. Activating all panels spawns a star. Jumping onto a panel while it's activated with deactivate it.

StarSpawned = false

---@param obj Object
function flipswitch_panel_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_FLIPSWITCH_PANEL_MOP
    obj.oCollisionDistance = 1024
    obj.parentObj = cur_obj_nearest_object_with_behavior(get_behavior_from_id(bhvFlipswitch_Panel_StarSpawn_MOP))
end

---@param obj Object
function flipswitch_panel_loop(obj)
    obj_set_model_extended(obj, E_MODEL_FLIPSWITCH_PANEL)

    load_object_collision_model()

    -- Always checks for the starspawn mop
    if obj.parentObj == nil then
        obj.parentObj = cur_obj_nearest_object_with_behavior(get_behavior_from_id(bhvFlipswitch_Panel_StarSpawn_MOP))
        if obj.parentObj then
            return
        end
    end

    -- Turn green and don't allow further change
    if StarSpawned then
        obj.oAnimState = 2
    else
        switch(obj.oAction, {
            [FLIPSWITCH_PANEL_ACT_IDLE] = function()
                if cur_obj_is_mario_on_platform() == 1 then
                    obj.oAction = FLIPSWITCH_PANEL_ACT_ACTIVE

                    -- Causes the panel to change colors upon being pressed multiple times
                    obj.parentObj.oHiddenStarTriggerCounter = obj.parentObj.oHiddenStarTriggerCounter + 1 - (2 * obj.oAnimState)
                    switch(obj.oAnimState, {
                        [0] = function()
                            obj.oAnimState = 1
                        end,
                        [1] = function()
                            obj.oAnimState = 0
                        end
                    })
                    -- Using xor doesn't really work well here since this is not C
                    -- flipswitch_panel_obj.oAnimState = flipswitch_panel_obj.oAnimState &~ 1

                    cur_obj_play_sound_1(SOUND_GENERAL_BIG_CLOCK)
                end
            end,
            [FLIPSWITCH_PANEL_ACT_ACTIVE] = function()
                if cur_obj_is_mario_on_platform() == 0 then
                    obj.oAction = FLIPSWITCH_PANEL_ACT_IDLE
                end
            end
        })
    end
end

bhvFlipswitch_Panel_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, flipswitch_panel_init, flipswitch_panel_loop)

---@param obj Object
function flipswitch_panel_starspawn_init(obj)
    obj.oHealth = count_objects_with_behavior(get_behavior_from_id(bhvFlipswitch_Panel_MOP))
end

---@param obj Object
function flipswitch_panel_starspawn_loop(obj)
    if obj.oHealth == obj.oHiddenStarTriggerCounter and not StarSpawned then
        spawn_default_star(obj.oPosX, obj.oPosY, obj.oPosZ)
        StarSpawned = true
        obj.activeFlags = obj.activeFlags | ACTIVE_FLAG_DEACTIVATED
    end
end

bhvFlipswitch_Panel_StarSpawn_MOP = hook_behavior(nil, OBJ_LIST_GENACTOR, false, flipswitch_panel_starspawn_init, flipswitch_panel_starspawn_loop)

------ Switchblock ------
-- This block is either red or blue. If the corresponding switch is pressed, activate blocks of one color and deactivate blocks of another color.
-- The color of each block and switch depends ont the 2nd byte.
-- 2nd byte of 0 spawns red; 2nd byte of 1 spawns blue.
-- Anim state 0 is red, 1 is red deactivated, 2 is blue, 3 is blue deactivated.

SwitchBlockState = 0

-- Reset values if none exists
hook_event(HOOK_UPDATE, function()
    if find_object_with_behavior(get_behavior_from_id(bhvSwitchblock_MOP)) == nil then
        SwitchBlockState = 0
    end
end)

---@param obj Object
function switchblock_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_SWITCHBLOCK_MOP
end

---@param obj Object
function switchblock_loop(obj)
    obj_set_model_extended(obj, E_MODEL_SWITCHBLOCK)

    -- Determines which block color this becomes
    local params_2nd_byte = obj.oBehParams2ndByte
    -- obj.oAnimState = params_2nd_byte + obj.oAction -- Doesn't seem to work
    -- Force anim states (Switch could be used here, but it looks really terrible)
    if params_2nd_byte == 0 then -- Red
        if SwitchBlockState == 0 then
            obj.oAnimState = 0 -- Red activated
        elseif SwitchBlockState == 1 then
            obj.oAnimState = 1 -- Red deactivated
        end
    elseif params_2nd_byte == 1 then -- Blue
        if SwitchBlockState == 0 then
            obj.oAnimState = 3 -- Blue deactivated
        elseif SwitchBlockState == 1 then
            obj.oAnimState = 2 -- Blue activated
        end
    end

    -- Only loads collision if the corresponding switch is pressed
    if SwitchBlockState == params_2nd_byte then
        load_object_collision_model()
        obj.oAction = SWITCHBLOCK_ACT_ACTIVE
    else
        obj.oAction = SWITCHBLOCK_ACT_INACTIVE
    end
end

bhvSwitchblock_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, switchblock_init, switchblock_loop)

---@param obj Object
function switchblock_switch_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.collisionData = COL_SWITCHBLOCK_SWITCH_MOP
end

---@param obj Object
function switchblock_switch_loop(obj)
    obj_set_model_extended(obj, E_MODEL_SWITCHBLOCK_SWITCH)

    local params_2nd_byte = obj.oBehParams2ndByte
    load_object_collision_model()

    obj.oAnimState = params_2nd_byte
    if cur_obj_is_mario_on_platform() == 1 then
        SwitchBlockState = params_2nd_byte
    end

    local mathNum = 0
    if SwitchBlockState ~= params_2nd_byte then
        mathNum = 1
    else
        mathNum = 0
    end

    -- Make smaller if the switch is pressed
    obj.header.gfx.scale.y = mathNum * 0.9 + 0.1
end

bhvSwitchblock_Switch_MOP = hook_behavior(nil, OBJ_LIST_SURFACE, false, switchblock_switch_init, switchblock_switch_loop)

-- Huh?
--bhvBeta_Blarrg_MOP = hook_behavior(nil, OBJ_LIST_UNIMPORTANT, false, function(obj) obj_mark_for_deletion(obj) end, nil)

------ Fake star ------
-- A fake star is like a normal star except it does not add to the star counter

---@param obj Object
function fake_star_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_ACTIVE_FROM_AFAR
    local oHitbox = get_temp_object_hitbox()
    oHitbox.interactType = INTERACT_COIN
    oHitbox.downOffset = 0
    oHitbox.damageOrCoinValue = 0
    oHitbox.health = 0
    oHitbox.numLootCoins = 0
    oHitbox.radius = 80
    oHitbox.height = 50
    oHitbox.hurtboxHeight = 0
    oHitbox.hurtboxRadius = 0
    obj_set_hitbox(obj, oHitbox)
end

---@param obj Object
function fake_star_loop(obj)
    -- Get star ID
    local star_id = (obj.oBehParams >> 24) & 0xFF
    local current_level_star_flags = save_file_get_star_flags(get_current_save_file_num() - 1, gNetworkPlayers[0].currCourseNum - 1)
    -- Turn transparent if this star's ID has already been flagged as gotten
    if current_level_star_flags & (1 << star_id) then
        obj_set_model_extended(obj, E_MODEL_TRANSPARENT_STAR)
    else
        obj_set_model_extended(obj, E_MODEL_STAR)
    end

    obj.oFaceAngleYaw = obj.oFaceAngleYaw + 0x800

    if obj.oInteractStatus & INT_STATUS_INTERACTED ~= 0 then
        obj_mark_for_deletion(obj)
        obj.oInteractStatus = 0
    end
end

bhvFakeStar = hook_behavior(nil, OBJ_LIST_LEVEL, false, fake_star_init, fake_star_loop)
