-- name: Romhack Camera

sOverrideCameraModes = {
    [CAMERA_MODE_RADIAL]            = true,
    [CAMERA_MODE_OUTWARD_RADIAL]    = true,
    [CAMERA_MODE_BEHIND_MARIO]      = true,
    [CAMERA_MODE_CLOSE]             = true,
    --[CAMERA_MODE_C_UP]              = true,
    --[CAMERA_MODE_WATER_SURFACE]     = true,
    [CAMERA_MODE_SLIDE_HOOT]        = true,
    --[CAMERA_MODE_INSIDE_CANNON]     = true,
    --[CAMERA_MODE_BOSS_FIGHT]        = true,
    [CAMERA_MODE_PARALLEL_TRACKING] = true,
    [CAMERA_MODE_FIXED]             = true,
    [CAMERA_MODE_8_DIRECTIONS]      = true,
    [CAMERA_MODE_FREE_ROAM]         = true,
    [CAMERA_MODE_SPIRAL_STAIRS]     = true,
}

camera_set_use_course_specific_settings(0)
camera_set_romhack_override(RCO_ALL)
rom_hack_cam_set_collisions(0)
camera_romhack_allow_centering(0)
camera_set_use_course_specific_settings(false)
camera_romhack_allow_dpad_usage(1)

function override_camera()
    local m = gMarioStates[0]
    local np = gNetworkPlayers[0]

    if sOverrideCameraModes[m.area.camera.mode] == nil then
        return
    end

    if (np.currLevelNum == LEVEL_BOWSER_1 or np.currLevelNum == LEVEL_BOWSER_2 or np.currLevelNum == LEVEL_BOWSER_3) then
        return
    end

    set_camera_mode(m.area.camera, CAMERA_MODE_ROM_HACK, 0)
end

function on_set_camera_mode(c, mode, frames)
    local m = gMarioStates[0]

    if mode == CAMERA_MODE_ROM_HACK then
        return true
    end

    if sOverrideCameraModes[mode] ~= nil then
        -- do not allow change
        if mode ~= CAMERA_MODE_ROM_HACK then
            set_camera_mode(c, CAMERA_MODE_ROM_HACK, frames)
            return false
        end
        return false
    end

    -- allow camera change
    return true
end

function mario_update(m)
    if m.playerIndex == 0 then
        override_camera()
    end
end

hook_event(HOOK_ON_SET_CAMERA_MODE, on_set_camera_mode)
hook_event(HOOK_MARIO_UPDATE, mario_update)