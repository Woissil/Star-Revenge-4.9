-- name: \\#0035ff\\Star Revenge 4.9:\\#8500af\\ Adulterated Reality
-- description: Star Revenge 4.9 Adulterated Reality is a romhack created by Brodute\n\n\nThere are 150 stars.\n\nPorted to Coop by Woissil, Blocky\n\nContributors: Andre\nI'mYourCat\nAgent X\nLeonitz\nFlipFlop Bell\nSarah/TikalSM64\nDrahnokks\nSunk\nCoolioKid956\nFearl\n\nTheir contributions are in the contributor file
-- incompatible: romhack

gLevelValues.coinsRequiredForCoinStar = 512

--cam--

camera_set_use_course_specific_settings(false)

---water scrolling--

movtexqc_register('castle_grounds_1_Movtex_0',    LEVEL_CASTLE_GROUNDS, 1, 0)
movtexqc_register('bbh_1_Movtex_0',               LEVEL_BBH, 1, 0)
movtexqc_register('ccm_1_Movtex_0',               LEVEL_CCM, 1, 0)
movtexqc_register('hmc_1_Movtex_0',               LEVEL_HMC, 1, 0)
movtexqc_register('ssl_1_Movtex_0',               LEVEL_SSL, 1, 0)
movtexqc_register('ssl_2_Movtex_0',               LEVEL_SSL, 2, 0)
movtexqc_register('bob_1_Movtex_0',               LEVEL_BOB, 1, 0)
movtexqc_register('sl_1_Movtex_0',                LEVEL_SL, 1, 0)
movtexqc_register('sl_2_Movtex_0',                LEVEL_SL, 2, 0)
movtexqc_register('wdw_1_Movtex_0',               LEVEL_WDW, 1, 0)
movtexqc_register('jrb_1_Movtex_0',               LEVEL_JRB, 1, 0)
movtexqc_register('bitfs_1_Movtex_0',             LEVEL_BITFS, 1, 0)
movtexqc_register('ddd_1_Movtex_0',               LEVEL_DDD, 1, 0)
movtexqc_register('castle_courtyard_1_Movtex_0',  LEVEL_CASTLE_COURTYARD, 1, 0)
movtexqc_register('wmotr_1_Movtex_0',             LEVEL_WMOTR, 1, 0)
movtexqc_register('wf_1_Movtex_0',                LEVEL_WF, 1, 0)

---------------------
---Small Functions---
---------------------

function set_dialog_color_to_blue()
    set_dialog_override_color(25, 28, 97, 180, 255, 255, 255, 255)
end

hook_event(HOOK_ON_DIALOG, set_dialog_color_to_blue)

---@param obj Object
function bhv_custom_red_coin_star_loop(obj)
    if obj.oHiddenStarTriggerCounter >= gMarioStates[0].area.numRedCoins - 2 then
        obj.oAction = 1
    end
end

hook_event(HOOK_MARIO_UPDATE, function(m) m.numLives = 10 end)

--NoD Code
local once = true 
hook_event(HOOK_MARIO_UPDATE,
function(m)
    if m.playerIndex ~= 0 then return end
    if once then
        m.numLives = 100
        once = true
    end
end)

-- These both need to be changed, though they share a lot of the same code so the function can be reused
hook_behavior(id_bhvHiddenRedCoinStar, OBJ_LIST_LEVEL, false, nil, bhv_custom_red_coin_star_loop)
hook_behavior(id_bhvBowserCourseRedCoinStar, OBJ_LIST_LEVEL, false, nil, bhv_custom_red_coin_star_loop)

function no_fall_damage(m)
    m.peakHeight = m.pos.y
end

hook_event(HOOK_MARIO_UPDATE, no_fall_damage)

---star pos---

starPositions = gLevelValues.starPositions

vec3f_set(starPositions.KingWhompStarPos, -512.0, 5325.0, 5840.0)
vec3f_set(starPositions.BigBullyTrioStarPos, -1754.0, 223.0, 5773.0)
vec3f_set(starPositions.TuxieMotherStarPos, 3130.0, 845.0, 3256.0)
vec3f_set(starPositions.KoopaBobStarPos, -2091.0, 2790.0, -1464.0)
vec3f_set(starPositions.KoopaThiStarPos, -5074.0, 822.0, 8084.0)

-- disable caps in cap courses
gLevelValues.wingCapDurationTotwc = 1
gLevelValues.vanishCapDurationVcutm = 1
gLevelValues.metalCapDurationCotmc = 1
