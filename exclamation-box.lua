-- exclamation box, ported to Lua by Agent X
-- credit me if you use this, also let me know if there are any issues or inaccuracies.

sExclamationBoxHitbox = {
    interactType = INTERACT_BREAKABLE,
    downOffset = 5,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 0,
    radius = 40,
    height = 30,
    hurtboxRadius = 40,
    hurtboxHeight = 30,
}

----------
--models--
----------

E_MODEL_WSTAR = smlua_model_util_get_id("wstar_geo")

D_8032F0C0 = { [0] = SAVE_FLAG_HAVE_WING_CAP, [1] = SAVE_FLAG_HAVE_METAL_CAP, [2] = SAVE_FLAG_HAVE_VANISH_CAP }

sExclamationBoxActions = {
    [0] = function(o) exclamation_box_act_0(o) end,
    [1] = function(o) exclamation_box_act_1(o) end,
    [2] = function(o) exclamation_box_act_2(o) end,
    [3] = function(o) exclamation_box_act_3(o) end,
    [4] = function(o) exclamation_box_act_4(o) end,
    [5] = function(o) exclamation_box_act_5(o) end,
    [6] = function(o) exclamation_box_act_6(o) end
}

function switch(param, case_table)
    local case = case_table[param]
    if case then return case() end
    local def = case_table['default']
    return def and def() or nil
end

function if_then_else(cond, if_true, if_false)
    if cond then return if_true end
    return if_false
end

--- @param o Object
function obj_call_action_function(o, actionFunctions)
    local actionFunction = actionFunctions[o.oAction]
    actionFunction(o)
end

--- @param obj Object
function obj_set_hitbox(obj, hitbox)
    if obj == nil or hitbox == nil then return end
    if (obj.oFlags & OBJ_FLAG_30) == 0 then
        obj.oFlags = obj.oFlags | OBJ_FLAG_30

        obj.oInteractType = hitbox.interactType
        obj.oDamageOrCoinValue = hitbox.damageOrCoinValue
        obj.oHealth = hitbox.health
        obj.oNumLootCoins = hitbox.numLootCoins

        cur_obj_become_tangible()
    end

    obj.hitboxRadius = obj.header.gfx.scale.x * hitbox.radius
    obj.hitboxHeight = obj.header.gfx.scale.y * hitbox.height
    obj.hurtboxRadius = obj.header.gfx.scale.x * hitbox.hurtboxRadius
    obj.hurtboxHeight = obj.header.gfx.scale.y * hitbox.hurtboxHeight
    obj.hitboxDownOffset = obj.header.gfx.scale.y * hitbox.downOffset
end

-- unk0: unused
-- unk1: unused
-- unk2: *usually* spawned star id, ranges from stars 0-6
-- model: which model to use for the spawned object
-- behavior: which behavior for the object to use
local sExclamationBoxContents = {
    [0] =  { unk0 = 0,  unk1 = 0, unk2 = 0, model = E_MODEL_MARIOS_WING_CAP,  behavior = id_bhvWingCap },
    [1] =  { unk0 = 1,  unk1 = 0, unk2 = 0, model = E_MODEL_MARIOS_METAL_CAP, behavior = id_bhvMetalCap },
    [2] =  { unk0 = 2,  unk1 = 0, unk2 = 0, model = E_MODEL_MARIOS_CAP,       behavior = id_bhvVanishCap },
    [3] =  { unk0 = 3,  unk1 = 0, unk2 = 0, model = E_MODEL_KOOPA_SHELL,      behavior = id_bhvKoopaShell },
    [4] =  { unk0 = 4,  unk1 = 0, unk2 = 0, model = E_MODEL_YELLOW_COIN,      behavior = id_bhvSingleCoinGetsSpawned },
    [5] =  { unk0 = 5,  unk1 = 0, unk2 = 0, model = E_MODEL_NONE,             behavior = id_bhvThreeCoinsSpawn },
    [6] =  { unk0 = 6,  unk1 = 0, unk2 = 0, model = E_MODEL_NONE,             behavior = id_bhvTenCoinsSpawn },
    [7] =  { unk0 = 7,  unk1 = 0, unk2 = 0, model = E_MODEL_1UP,              behavior = id_bhv1upWalking },
    [8] =  { unk0 = 8,  unk1 = 0, unk2 = 0, model = E_MODEL_STAR,             behavior = id_bhvSpawnedStar },
    [9] =  { unk0 = 9,  unk1 = 0, unk2 = 0, model = E_MODEL_1UP,              behavior = id_bhv1upRunningAway },
    [10] = { unk0 = 10, unk1 = 0, unk2 = 1, model = E_MODEL_STAR,             behavior = id_bhvSpawnedStar },
    [11] = { unk0 = 11, unk1 = 0, unk2 = 2, model = E_MODEL_STAR,             behavior = id_bhvSpawnedStar },
    [12] = { unk0 = 12, unk1 = 0, unk2 = 3, model = E_MODEL_STAR,             behavior = id_bhvSpawnedStar },
    [13] = { unk0 = 13, unk1 = 0, unk2 = 4, model = E_MODEL_STAR,             behavior = id_bhvSpawnedStar },
    [14] = { unk0 = 14, unk1 = 0, unk2 = 5, model = E_MODEL_WSTAR,             behavior = id_bhvSpawnedStar },
    [15] = { unk0 = 15, unk1 = 0, unk2 = 0, model = E_MODEL_WF_BREAKABLE_WALL_RIGHT,             behavior = id_bhvWfBreakableWallRight },
    [16] = { unk0 = 16, unk1 = 0, unk2 = 0, model = E_MODEL_BOBOMB_BUDDY,             behavior = id_bhvBobombBuddyOpensCannon },
    [17] = { unk0 = 17, unk1 = 0, unk2 = 15, model = E_MODEL_STAR,             behavior = id_bhvWarp },
    [18] = { unk0 = 99, unk1 = 0, unk2 = 0, model = 0,                        behavior = nil }
    -- [15] = { unk0 = 99, unk1 = 0, unk2 = 0, model = E_MODEL_CHUCKYA,          behavior = id_bhvChuckya } -- custom
}

--- @param parent Object
--- @param model ModelExtendedId
--- @param behavior BehaviorId
function spawn_object(parent, model, behavior)
    local obj = spawn_sync_object(
        behavior,
        model,
        0, 0, 0,
        --- @param o Object
        function(o)
            o.parentObj = parent
        end
    )

    obj_copy_pos_and_angle(obj, parent)

    return obj
end

--- @param o Object
function exclamation_box_act_0(o)
    o.oExclamationBoxForce = 0
    if o.oBehParams2ndByte < 3 then
        o.oAnimState = o.oBehParams2ndByte
        if (save_file_get_flags() & D_8032F0C0[o.oBehParams2ndByte]) ~= 0
            or ((o.oBehParams >> 24) & 0xFF) ~= 0 then
            o.oAction = 2
        else
            o.oAction = 1
        end
    else
        o.oAnimState = 3
        o.oAction = 2
    end
end

--- @param o Object
function exclamation_box_act_1(o)
    cur_obj_become_intangible()
    if o.oTimer == 0 then
        spawn_object(o, E_MODEL_EXCLAMATION_POINT, id_bhvRotatingExclamationMark)
        obj_set_model_extended(o, E_MODEL_EXCLAMATION_BOX_OUTLINE)
    end
    if (save_file_get_flags() & D_8032F0C0[o.oBehParams2ndByte]) ~= 0
        or ((o.oBehParams >> 24) & 0xFF) ~= 0 then
        o.oAction = 2
        obj_set_model_extended(o, E_MODEL_EXCLAMATION_BOX)
    end
end

--- @param o Object
function exclamation_box_act_2(o)
    obj_set_hitbox(o, sExclamationBoxHitbox)
    if o.oTimer == 0 then
        cur_obj_unhide()
        cur_obj_become_tangible()
        o.oInteractStatus = 0
        o.oPosY = o.oHomeY
        o.oGraphYOffset = 0
    end

    local isNearest = nearest_mario_state_to_object(o) == gMarioStates[0]
    if o.oExclamationBoxForce or isNearest then
        if o.oExclamationBoxForce ~= 0 or (isNearest and cur_obj_was_attacked_or_ground_pounded() ~= 0) then
            if o.oExclamationBoxForce == 0 then
                o.oExclamationBoxForce = 1
                network_send_object(o, true)
                o.oExclamationBoxForce = 0
            end
            cur_obj_become_intangible()
            o.oExclamationBoxUnkFC = 0x4000
            o.oVelY = 30
            o.oGravity = -8
            o.oFloorHeight = o.oPosY
            o.oAction = 3
            queue_rumble_data_object(o, 5, 80)
        end
    end
    load_object_collision_model()
end

--- @param o Object
function exclamation_box_act_3(o)
    cur_obj_move_using_fvel_and_gravity()
    if o.oVelY < 0 then
        o.oVelY = 0
        o.oGravity = 0
    end
    o.oExclamationBoxUnkF8 = (sins(o.oExclamationBoxUnkFC) + 1) * 0.3 + 0.0
    o.oExclamationBoxUnkF4 = (-sins(o.oExclamationBoxUnkFC) + 1) * 0.5 + 1.0
    o.oGraphYOffset = (-sins(o.oExclamationBoxUnkFC) + 1) * 26.0
    o.oExclamationBoxUnkFC = o.oExclamationBoxUnkFC + 0x1000
    o.header.gfx.scale.x = o.oExclamationBoxUnkF4 * 2
    o.header.gfx.scale.y = o.oExclamationBoxUnkF8 * 2
    o.header.gfx.scale.z = o.oExclamationBoxUnkF4 * 2
    if o.oTimer == 7 then
        o.oAction = 4
    end
end

--- @param m MarioState
--- @param model ModelExtendedId
function exclamation_replace_model(m, model)
    if m == nil then return model end
    switch(model, {
        [E_MODEL_MARIOS_CAP] = function()              return m.character.capModelId end,
        [E_MODEL_MARIOS_METAL_CAP] = function()        return m.character.capMetalModelId end,
        [E_MODEL_MARIOS_WING_CAP] = function()         return m.character.capWingModelId end,
        [E_MODEL_MARIOS_WINGED_METAL_CAP] = function()         return m.character.capMetalWingModelId end,

    })
    return model
end

--- @param o Object
function exclamation_box_spawn_contents(o, a0, a1)
    local marioState = nearest_mario_state_to_object(o)
    local player = nil
    if marioState ~= nil then player = marioState.marioObj end
    local sp1C = nil

    if o.oExclamationBoxForce ~= 0 then
        return
    end

    local model = exclamation_replace_model(marioState, a0.model)

    -- simplified from the original code
    sp1C = spawn_object(o, model, a0.behavior)
    if sp1C ~= nil then
        sp1C.oVelY = 20
        sp1C.oForwardVel = 3
        if player ~= nil then
            sp1C.oMoveAngleYaw = player.oMoveAngleYaw
            sp1C.globalPlayerIndex = player.globalPlayerIndex
        end
    end
    o.oBehParams = o.oBehParams | a0.unk2 << 24
    if a0.model == E_MODEL_STAR then
        o.oFlags = o.oFlags | 0x4000
    end
end

--- @param o Object
function exclamation_box_act_4(o)
    exclamation_box_spawn_contents(o, sExclamationBoxContents[o.oBehParams2ndByte], o.oBehParams2ndByte)
    spawn_mist_particles_variable(0, 0, 46)
    spawn_triangle_break_particles(20, 139, 0.3, o.oAnimState)
    play_sound(SOUND_GENERAL_BREAK_BOX, o.header.gfx.cameraToObject)
    if o.oBehParams2ndByte <= 3 then
        o.oAction = 5
        cur_obj_hide()
    else
        o.oAction = 6
        cur_obj_become_intangible()
        cur_obj_hide()
    end
end

--- @param o Object
function exclamation_box_act_5(o)
    o.oExclamationBoxForce = 0
    if o.oTimer > 300 then
        o.oAction = 2
        -- sync_object_forget_last_reliable_packet(o.oSyncID)
    end
end

--- @param o Object
function exclamation_box_act_6(o)
    o.oExclamationBoxForce = 0
    if (o.oTimer > 1000) then
        obj_mark_for_deletion(o)
    end
end

--- @param o Object
function bhv_exclamation_box_init(o)
    o.oFlags = (OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    o.collisionData = gGlobalObjectCollisionData.exclamation_box_outline_seg8_collision_08025F78
    o.oCollisionDistance = 300
    o.oHomeX = o.oPosX
    o.oHomeY = o.oPosY
    o.oHomeZ = o.oPosZ

    o.areaTimerType = AREA_TIMER_TYPE_MAXIMUM
    o.areaTimer = 0
    o.areaTimerDuration = 300

    network_init_object(o, true, { "oExclamationBoxForce", "areaTimer" })
end

--- @param o Object
function bhv_exclamation_box_loop(o)
    cur_obj_scale(2)
    obj_call_action_function(o, sExclamationBoxActions)
end

id_bhvExclamationBox = hook_behavior(id_bhvExclamationBox, OBJ_LIST_SURFACE, true, bhv_exclamation_box_init, bhv_exclamation_box_loop)

function update()
    if gNetworkPlayers[0].currAreaSyncValid and obj_get_next_with_same_behavior_id(obj_get_first_with_behavior_id(id_bhvExclamationBox)) == nil then
        spawn_sync_object(
            id_bhvExclamationBox,
            E_MODEL_EXCLAMATION_BOX,
            0, 1050, 0,
            --- @param o Object
            function(o)
                o.oBehParams2ndByte = 15
            end
        )
    end
end

hook_event(HOOK_UPDATE, update)