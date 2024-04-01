-- Colored Stars
E_MODEL_WFSTAR = smlua_model_util_get_id("wfstar_geo")
E_MODEL_JRBSTAR = smlua_model_util_get_id("jrbstar_geo")
E_MODEL_CCMSTAR = smlua_model_util_get_id("ccmstar_geo")
E_MODEL_BBHSTAR = smlua_model_util_get_id("bbhstar_geo")
E_MODEL_HMCSTAR = smlua_model_util_get_id("hmcstar_geo")
E_MODEL_LLLSTAR = smlua_model_util_get_id("llLstar_geo")
E_MODEL_SSLSTAR = smlua_model_util_get_id("sslstar_geo")
E_MODEL_DDDSTAR = smlua_model_util_get_id("dddstar_geo")
E_MODEL_SLSTAR = smlua_model_util_get_id("slstar_geo")
E_MODEL_WDWSTAR = smlua_model_util_get_id("wdwstar_geo")
E_MODEL_TTMSTAR = smlua_model_util_get_id("ttmstar_geo")
E_MODEL_THISTAR = smlua_model_util_get_id("thistar_geo")
E_MODEL_TTCSTAR = smlua_model_util_get_id("ttcstar_geo")
E_MODEL_RRSTAR = smlua_model_util_get_id("rrstar_geo")

starStateTable = {
    [LEVEL_BOB] = E_MODEL_STAR,
    [LEVEL_WF] = E_MODEL_WFSTAR,
    [LEVEL_JRB] = E_MODEL_SSLSTAR,
    [LEVEL_CCM] = E_MODEL_CCMSTAR,
    [LEVEL_BBH] = E_MODEL_BBHSTAR,
    [LEVEL_HMC] = E_MODEL_HMCSTAR,
    [LEVEL_LLL] = E_MODEL_LLLSTAR,
    [LEVEL_SSL] = E_MODEL_SSLSTAR,
    [LEVEL_DDD] = E_MODEL_DDDSTAR,
    [LEVEL_SL] = E_MODEL_SLSTAR,
    [LEVEL_WDW] = E_MODEL_WDWSTAR,
    [LEVEL_TTM] = E_MODEL_TTMSTAR,
    [LEVEL_THI] = E_MODEL_WFSTAR,
    [LEVEL_TTC] = E_MODEL_TTCSTAR,
    [LEVEL_RR] = E_MODEL_RRSTAR,
    [LEVEL_WMOTR] = E_MODEL_JRBSTAR
    [LEVEL_TOTWC] = E_MODEL_WDWSTAR
    [LEVEL_COTMC] = E_MODEL_JRBSTAR
    [LEVEL_BOWSER_1] = E_MODEL_TTMSTAR
    [LEVEL_BITDW] = E_MODEL_JRBSTAR
    [LEVEL_BITFS] = E_MODEL_JRBSTAR
    [LEVEL_BITS] = E_MODEL_WSTAR
    [LEVEL_BOWSER_2] = E_MODEL_RRSTAR
    [LEVEL_BOWSER_3] = E_MODEL_JRBSTAR
    [LEVEL_BOWSER_3] = E_MODEL_SLSTAR
    [LEVEL_PSS] = E_MODEL_STAR
}

---@param obj Object
---@type NetworkPlayer
local np = gNetworkPlayers[0]
function init_star_model(o)
    local obox = obj_get_first_with_behavior_id(id_bhvExclamationBox)
    if obj_has_model_extended(o, E_MODEL_TRANSPARENT_STAR) == 0 then
        if obj_has_behavior_id(o, id_bhvActSelectorStarType) == 0 then
            obj_set_model_extended(o, starStateTable[np.currLevelNum])

        if obj_has_behavior_id(o, id_bhvActSelectorStarType) ~= 0 and starStateTable[np.currLevelNum] ~= nil then
            obj_set_model_extended(o, starStateTable[np.currLevelNum])
            end
        end
    end
end

hook_behavior(id_bhvActSelectorStarType, OBJ_LIST_DEFAULT, false, nil, init_star_model)
hook_behavior(id_bhvStar, OBJ_LIST_LEVEL, false, init_star_model, nil)
hook_behavior(id_bhvCelebrationStar, OBJ_LIST_GENACTOR, false, nil, init_star_model)
hook_behavior(id_bhvStarSpawnCoordinates, OBJ_LIST_GENACTOR, false, nil, init_star_model)
hook_behavior(id_bhvSpawnedStar, OBJ_LIST_GENACTOR, false, nil, init_star_model)
