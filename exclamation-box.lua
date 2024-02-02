-- thanks André
---@param o Object

local E_MODEL_WSTAR = smlua_model_util_get_id("wstar_geo")


---@type ExclamationBoxContents
local sExclamationBoxContents = {
    --[[
        Accessing keys is slower than accessing indicies, which is why this is like this
        1st element: index
        2nd element: oBehParams2ndByte
        3rd element: oBehParams1stByte
        4th element: model
        5th element: behavior id
    ]]
    { 0, 14, 14, E_MODEL_STAR,  bhvWarp },
    { 1, 0, 0, E_MODEL_KOOPA_SHELL,  bhvKoopaShell },
    { 2, 0, 0, E_MODEL_BOBOMB_BUDDY,  bhvBobombBuddyOpensCannon },
    { 3, 15, 15, E_MODEL_STAR,  bhvWarp },
    { 4, 0, 0, E_MODEL_MARIOS_CAP,  bhvVanishCap },
    { 5, 0, 0, E_MODEL_MARIOS_METAL_CAP,  bhvMetalCap },
    { 6, 0, 0, E_MODEL_NONE,  bhvTenCoinsSpawn },
    { 7, 0, 0, E_MODEL_1UP,  bhv1upWalking },
    { 8, 0, 0, E_MODEL_STAR,  bhvSpawnedStar },
    { 9, 0, 0, E_MODEL_1UP,  bhv1upRunningAway },
    { 10, 0, 1, E_MODEL_STAR,  bhvSpawnedStar },
    { 11, 0, 2, E_MODEL_STAR,  bhvSpawnedStar },
    { 12, 0, 3, E_MODEL_STAR,  bhvSpawnedStar },
    { 13, 0, 4, E_MODEL_STAR,  bhvSpawnedStar },
    { 14, 0, 6, E_MODEL_WSTAR,  bhvSpawnedStar },
    { 15, 0, 0, E_MODEL_MARIOS_WING_CAP,  bhvWingCap },
    { 16, 0, 0, E_MODEL_MARIOS_WING_CAP,  bhvWingCap },
    { 17, 0, 0, E_MODEL_MARIOS_METAL_CAP,  bhvMetalCap },
    { 18, 0, 0, E_MODEL_YELLOW_COIN,  bhvSingleCoinGetsSpawned },
    { 19, 0, 0, E_MODEL_NONE,  bhvThreeCoinsSpawn },
    { 20, 0, 0, E_MODEL_WF_BREAKABLE_WALL_RIGHT,  bhvWfBreakableWallRight },
    { 21, 0, 0, E_MODEL_KOOPA_SHELL,  bhvKoopaShell },
    { 99, 0, 0, E_MODEL_NONE, nil }
}

function bhv_custom_exclamation_box_init(o)
    if o.oBehParams2ndByte == 3 then
        if yellow_pressed() then
            o.oAction = 2
        else
            o.oAction = 1
        end
    end
end

---@param o Object
function bhv_custom_exclamation_box_loop(o)
    if o.oBehParams2ndByte == 3 and o.oAction == 1 then
        if yellow_pressed() then
            o.oAction = 2
            obj_set_model_extended(o,E_MODEL_EXCLAMATION_BOX)
        end
    end
end

id_bhvExclamationBox = hook_behavior(id_bhvExclamationBox, OBJ_LIST_SURFACE, false, bhv_custom_exclamation_box_init, bhv_custom_exclamation_box_loop, "bhvExclamationBox")