-- AFK Bowser -- Star road code

--    function bhv_custom_bowser_loop(obj)
--        local np = gNetworkPlayers[0]
--        if np.currAreaSyncValid and np.currLevelSyncValid and np.currLevelNum ~= LEVEL_BOWSER_3 then
--            -- force bowser into do nothing action when not displaying cutscene
--            if obj.oAction ~= 5 and obj.oAction ~= 6 and obj.oAction ~= 20 then
--                obj.oAction = 4
--                obj.oSubAction = 11
--            end
--        end
--    end

    -- hook the behavior
--    id_bhvBowserCustom = hook_behavior(id_bhvBowser, OBJ_LIST_GENACTOR, false, nil, bhv_custom_bowser_loop)

function remove_timestop()
    ---@type MarioState
    local m = gMarioStates[0]
    ---@type Camera
    local c = gMarioStates[0].area.camera

    if m == nil or c == nil then
        return
    end

    if (c.cutscene == CUTSCENE_BOWSER_ARENA_END) then
        disable_time_stop_including_mario()
        m.freeze = 0
        c.cutscene = 0
    end
end
hook_event(HOOK_UPDATE, remove_timestop)