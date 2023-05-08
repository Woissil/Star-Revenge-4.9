-- door ported to lua

local DoorAction = {
    { flag = 0x40000, action = 3 },
    { flag = 0x80000, action = 4 },
    { flag = 0x10000, action = 1 },
    { flag = 0x20000, action = 2 },
    { flag = 0xFFFFFFFF, action = 0 },
  }
  
local DoorOpenSounds = { SOUND_GENERAL_OPEN_WOOD_DOOR, SOUND_GENERAL_OPEN_IRON_DOOR }
  
local DoorCloseSounds = { SOUND_GENERAL_CLOSE_WOOD_DOOR, SOUND_GENERAL_CLOSE_IRON_DOOR }
  
function door_animation_and_reset(sp18)
    cur_obj_init_animation_with_sound(sp18)
    if cur_obj_check_if_near_animation_end() then
      o.oAction = 0
    end
end
  
function set_door_camera_event()
    local gPlayerCameraState
    if segmented_to_virtual(bhvDoor) == o.behavior then
        gPlayerCameraState.cameraEvent = CAM_EVENT_DOOR
    else
        gPlayerCameraState.cameraEvent = CAM_EVENT_DOOR_WARP
    end
    gPlayerCameraState.usedObj = o
end
  
function play_door_open_noise()
    local sp1C = cur_obj_has_model(MODEL_HMC_METAL_DOOR)
    if o.oTimer == 0 then
      cur_obj_play_sound_2(DoorOpenSounds[sp1C])
      gTimeStopState = bit.bor(gTimeStopState, TIME_STOP_MARIO_OPENED_DOOR)
    end
    if o.oTimer == 70 then
      cur_obj_play_sound_2(DoorCloseSounds[sp1C])
    end
end
  
function play_warp_door_open_noise()
    local sp1C = cur_obj_has_model(MODEL_HMC_METAL_DOOR)
    if o.oTimer == 30 then
      cur_obj_play_sound_2(DoorCloseSounds[sp1C])
    end
end
  
function bhv_door_loop()
    local sp1C = 0
    while sDoorActions[sp1C] ~= nil and sDoorActions[sp1C].flag ~= 0xFFFFFFFF do
        if cur_obj_clear_interact_status_flag(sDoorActions[sp1C].flag) then
            set_door_camera_event()
            cur_obj_change_action(sDoorActions[sp1C].action)
        end
        sp1C = sp1C + 1
    end
  
    if o.oAction == 0 then
      cur_obj_init_animation_and_sound(0)
    elseif o.oAction == 1 or o.oAction == 2 then
      door_animation_and_reset(o.oAction)
      play_door_open_noise()
    elseif o.oAction == 3 or o.oAction == 4 then
      door_animation_and_reset(o.oAction)
      play_warp_door_open_noise()
    end
  
    if o.oAction == 0 then
      load_object_collision_model()
    end
    bhv_star_door_loop_2()
  
    local x = o.rawData[oPosX]
    local z = o.rawData[oPosZ]
    local floor = {}
    find_floor(x, o.rawData[oPosY], z, floor)
    if floor[1] ~= nil then 
      o.rawData[oDoorUnkF8] = floor[1].room 
    end
end
  
function bhv_door_init()
    local x, z = o.posX, o.posZ
    local floor = {}
    find_floor(x, o.posY, z, floor)
    if floor.room ~= nil then
        o.doorUnkF8 = floor.room
    end
  
    x = o.posX + math.sin(o.moveAngleYaw) * 200.0
    z = o.posZ + math.cos(o.moveAngleYaw) * 200.0
    find_floor(x, o.posY, z, floor)
    if floor ~= nil then
        o.doorUnkFC = floor.room
    end
  
    x = o.posX + math.sin(o.moveAngleYaw) * -200.0
    z = o.posZ + math.cos(o.moveAngleYaw) * -200.0
    find_floor(x, o.posY, z, floor)
    if floor ~= nil then
        o.doorUnk100 = floor.room
    end
  
    if o.doorUnkF8 > 0 and o.doorUnkF8 < 60 then
        gDoorAdjacentRooms[o.doorUnkF8][0] = o.doorUnkFC
        gDoorAdjacentRooms[o.doorUnkF8][1] = o.doorUnk100
    end
end
  
function bhv_star_door_loop_2()
    local sp4 = false
    local D_8035FEE4
    if gMarioCurrentRoom ~= 0 then
        if o.oDoorUnkF8 == gMarioCurrentRoom then
            sp4 = true
        elseif gMarioCurrentRoom == o.oDoorUnkFC then
            sp4 = true
        elseif gMarioCurrentRoom == o.oDoorUnk100 then
            sp4 = true
        elseif gDoorAdjacentRooms[gMarioCurrentRoom][0] == o.oDoorUnkFC then
            sp4 = true
        elseif gDoorAdjacentRooms[gMarioCurrentRoom][0] == o.oDoorUnk100 then
            sp4 = true
        elseif gDoorAdjacentRooms[gMarioCurrentRoom][1] == o.oDoorUnkFC then
            sp4 = true
        elseif gDoorAdjacentRooms[gMarioCurrentRoom][1] == o.oDoorUnk100 then
            sp4 = true
        end
    else
        sp4 = true
    end
  
    if sp4 then
        o.header.gfx.node.flags = bit.bor(o.header.gfx.node.flags, GRAPH_RENDER_ACTIVE)
        D_8035FEE4 = D_8035FEE4 + 1
    end
  
    if not sp4 then
        o.header.gfx.node.flags = bit.band(o.header.gfx.node.flags, bit.bnot(GRAPH_RENDER_ACTIVE))
    end
  
    o.oDoorUnk88 = sp4
end
  
id_bhvDoor = hook_behavior(id_bhvDoor, OBJ_LIST_LEVEL, true, bhv_door_init, bhv_door_loop) -- I'm here - Woissil 2023