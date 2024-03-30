function init_star_model(o)
    o.oAnimState = clamp(gNetworkPlayers[0].currCourseNum, 0, 16)
end

hook_behavior(id_bhvActSelectorStarType, OBJ_LIST_DEFAULT, false, init_star_model, nil)
hook_behavior(id_bhvStar, OBJ_LIST_LEVEL, false, init_star_model, nil)