-- Colored Stars
E_MODEL_WFSTAR = smlua_model_util_get_id("wfstar_geo")
E_MODEL_JRBSTAR = smlua_model_util_get_id("jrbstar_geo")
E_MODEL_CCMSTAR = smlua_model_util_get_id("ccmstar_geo")
E_MODEL_BBHSTAR = smlua_model_util_get_id("bbhstar_geo")
E_MODEL_HMCSTAR = smlua_model_util_get_id("hmcstar_geo")
E_MODEL_LLLSTAR = smlua_model_util_get_id("llstar_geo")
E_MODEL_SSLSTAR = smlua_model_util_get_id("sslstar_geo")
E_MODEL_DDDSTAR = smlua_model_util_get_id("dddstar_geo")
E_MODEL_SLSTAR = smlua_model_util_get_id("slstar_geo")
E_MODEL_WDWSTAR = smlua_model_util_get_id("wdwstar_geo")
E_MODEL_TTMSTAR = smlua_model_util_get_id("ttmstar_geo")
E_MODEL_THISTAR = smlua_model_util_get_id("thistar_geo")
E_MODEL_TTCSTAR = smlua_model_util_get_id("ttcstar_geo")
E_MODEL_RRSTAR = smlua_model_util_get_id("rrstar_geo")

starStateTable = {
    [COURSE_BOB] = E_MODEL_STAR,
    [COURSE_WF] = E_MODEL_WFSTAR,
    [COURSE_JRB] = E_MODEL_JRBSTAR,
    [COURSE_CCM] = E_MODEL_CCMSTAR,
    [COURSE_BBH] = E_MODEL_BBHSTAR,
    [COURSE_HMC] = E_MODEL_HMCSTAR,
    [COURSE_LLL] = E_MODEL_LLLSTAR,
    [COURSE_SSL] = E_MODEL_SSLSTAR,
    [COURSE_DDD] = E_MODEL_DDDSTAR,
    [COURSE_SL] = E_MODEL_SLSTAR,
    [COURSE_WDW] = E_MODEL_WDWSTAR,
    [COURSE_TTM] = E_MODEL_TTMSTAR,
    [COURSE_THI] = E_MODEL_THISTAR,
    [COURSE_TTC] = E_MODEL_TTCSTAR,
    [COURSE_RR] = E_MODEL_RRSTAR,
}

function init_star_model(o)
    local starId = (o.oBehParams >> 24) & 0xFF
    local currentLevelStarFlags = save_file_get_star_flags(get_current_save_file_num() - 1, gNetworkPlayers[0].currCourseNum - 1)
    
    if gNetworkPlayers[0].currLevelNum and starStateTable[gNetworkPlayers[0].currLevelNum] then
        obj_set_model_extended(o, starStateTable[gNetworkPlayers[0].currLevelNum])
    end
end

hook_behavior(id_bhvActSelectorStarType, OBJ_LIST_DEFAULT, false, init_star_model, nil)
hook_behavior(id_bhvStar, OBJ_LIST_LEVEL, false, init_star_model, nil)