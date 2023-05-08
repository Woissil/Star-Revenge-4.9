-- star ported to lua

sCollectStarHitbox = {
    interactType      = INTERACT_STAR_OR_KEY,  --thank you agent basedtie
    downOffset        = 0,
    damageOrCoinValue = 0,
    health            = 0,
    numLootCoins      = 0,
    radius            = 80,
    height            = 50,
    hurtboxRadius     = 0,
    hurtboxHeight     = 0,
}

----------
--models--
----------

E_MODEL_PURPLESTAR = smlua_model_util_get_id("starpurple_geo")
E_MODEL_PURPSTAR = smlua_model_util_get_id("starpurp_geo")
E_MODEL_DARKBLUESTAR = smlua_model_util_get_id("stardarkblue_geo")
E_MODEL_BLUEWHITESTAR = smlua_model_util_get_id("starbluewhite_geo")
E_MODEL_GREENSTAR = smlua_model_util_get_id("stargreen_geo")
E_MODEL_BLUESTAR = smlua_model_util_get_id("starblue_geo")
E_MODEL_BROWNSTAR = smlua_model_util_get_id("starbrown_geo")
E_MODEL_REDSTAR = smlua_model_util_get_id("starred_geo")
E_MODEL_PINKSTAR = smlua_model_util_get_id("starpink_geo")
E_MODEL_GREYSTAR = smlua_model_util_get_id("stargrey_geo")
E_MODEL_YELLOWSTAR = smlua_model_util_get_id("staryellow_geo")
E_MODEL_BLUEREDSTAR = smlua_model_util_get_id("starbluered_geo")
E_MODEL_BLACKSTAR = smlua_model_util_get_id("starblack_geo")


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

function bhv_collect_star_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    local starId = (o.oBehParams >> 24) & 0xFF
    local currentLevelStarFlags = save_file_get_star_flags(get_current_save_file_num() - 1, gNetworkPlayers[0].currCourseNum - 1)
    if (currentLevelStarFlags & (1 << starId)) ~= 0 then
        obj_set_model_extended(o, E_MODEL_TRANSPARENT_STAR)
	else
        obj_set_model_extended(o, E_MODEL_STAR)
    end
    obj_set_hitbox(o, sCollectStarHitbox)
end

function bhv_collect_star_loop(o)
    o.oFaceAngleYaw = o.oFaceAngleYaw + 0x800
    if (o.oInteractStatus & INT_STATUS_INTERACTED) ~= 0 then
        obj_mark_for_deletion(o)
        o.oInteractStatus = 0
    end

    if gNetworkPlayers[0].currLevelNum == LEVEL_WF then
        obj_set_model_extended(o, E_MODEL_PURPLESTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_JRB then
        obj_set_model_extended(o, E_MODEL_BROWNSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_CCM then
        obj_set_model_extended(o, E_MODEL_BLACKSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_BBH then
        obj_set_model_extended(o, E_MODEL_GREENSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_HMC then
        obj_set_model_extended(o, E_MODEL_BLUESTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_LLL then
        obj_set_model_extended(o, E_MODEL_PINKSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_SSL then
        obj_set_model_extended(o, E_MODEL_REDSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_DDD then
        obj_set_model_extended(o, E_MODEL_GREYSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_SL then
        obj_set_model_extended(o, E_MODEL_YELLOWSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_WDW then
        obj_set_model_extended(o, E_MODEL_DARKBLUESTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_TTM then
        obj_set_model_extended(o, E_MODEL_PURPSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_THI then
        obj_set_model_extended(o, E_MODEL_BLUEREDSTAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_TTC then
        obj_set_model_extended(o, E_MODEL_BROWN)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_RR then
        obj_set_model_extended(o, E_MODEL_STAR)
    elseif gNetworkPlayers[0].currLevelNum == LEVEL_BOB then
        obj_set_model_extended(o, E_MODEL_STAR)
    end
    return 0
end

id_bhvStar = hook_behavior(id_bhvStar, OBJ_LIST_LEVEL, true, bhv_collect_star_init, bhv_collect_star_loop)