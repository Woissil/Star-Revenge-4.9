-- door system

level_table = { [12] = COURSE_BOB, [13] = COURSE_WF, [14] = COURSE_JRB, [15] = COURSE_CCM, [16] = COURSE_BBH, [17] = COURSE_HMC, [18] = COURSE_LLL, [19] = COURSE_SSL, [20] = COURSE_DDD, [21] = COURSE_SL, [22] = COURSE_WDW, [23] = COURSE_TTM, [24] = COURSE_THI}

--- @param obj Object
function bhv_door_open_or_not_loop(obj)
    if gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE then
        if save_file_get_course_star_count(get_current_save_file_num() - 1, level_table[obj.oBehParams >> 24] - 1) > 0 then
            obj.oBehParams = 0
        end
    end
end

hook_behavior(id_bhvDoor, OBJ_LIST_SURFACE, false, nil, bhv_door_open_or_not_loop)