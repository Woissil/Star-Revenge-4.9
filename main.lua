-- name: \\#0035ff\\Star Revenge 4.9:\\#8500af\\ Adulterated Reality
-- description: Star Revenge 4.9 Adulterated Reality is a romhack created by Brodute\n\n\nThere are 150 stars.\n\nPorted to Coop by Woissil, Blocky\n\nContributors: Andre\nI'mYourCat\nAgent X\nLeonitz\nFlipFlop Bell\nSarah/TikalSM64\nDrahnokks\nSunk\nCoolioKid956\nFearl\n\nTheir contributions are in the contributor file
-- incompatible: romhack

gLevelValues.coinsRequiredForCoinStar = 512
gBehaviorValues.KingBobombFVel = 2048

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

save_file_set_flags(SAVE_FLAG_HAVE_METAL_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_VANISH_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_WING_CAP)

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

function change_vanish_floor(m)
    if m.playerIndex ~= 0 then return end  
        if (m.flags & MARIO_VANISH_CAP ~= 0 and m.floor.type == SURFACE_VANISH_CAP_WALLS) then
            m.floor.type = SURFACE_INTANGIBLE
            if (m.floor.type == SURFACE_INTANGIBLE) then
        m.floor.type = SURFACE_VANISH_CAP_WALLS
        end
    end
end
   
hook_event(HOOK_MARIO_UPDATE, change_vanish_floor)

-- These both need to be changed, though they share a lot of the same code so the function can be reused
hook_behavior(id_bhvHiddenRedCoinStar, OBJ_LIST_LEVEL, false, nil, bhv_custom_red_coin_star_loop)
hook_behavior(id_bhvBowserCourseRedCoinStar, OBJ_LIST_LEVEL, false, nil, bhv_custom_red_coin_star_loop)

function no_fall_damage(m)
    m.peakHeight = m.pos.y
end

hook_event(HOOK_MARIO_UPDATE, no_fall_damage)

---star pos---

starPositions = gLevelValues.starPositions

vec3f_set(gLevelValues.starPositions.KoopaBobStarPos, 3030, 4500, -4600)
vec3f_set(gLevelValues.starPositions.KoopaThiStarPos, 7100, -1300, -6000)
vec3f_set(gLevelValues.starPositions.KingBobombStarPos, 0.0, 720.0, 0.0)
vec3f_set(gLevelValues.starPositions.KingWhompStarPos, 0.0, 78.0, 0.0)
vec3f_set(gLevelValues.starPositions.EyerockStarPos, -440.0, 1032.0, -2274.0)
vec3f_set(gLevelValues.starPositions.BigBullyStarPos, 0.0, 950.0, -6800.0)
vec3f_set(gLevelValues.starPositions.ChillBullyStarPos, 130.0, 1600.0, -4335.0)
vec3f_set(gLevelValues.starPositions.BigPiranhasStarPos, -6300.0, -1850.0, -6300.0)
vec3f_set(gLevelValues.starPositions.TuxieMotherStarPos, 3167.0, -4300.0, 5108.0)
vec3f_set(gLevelValues.starPositions.WigglerStarPos, -1006.0, 483.0, -1048.0)
vec3f_set(gLevelValues.starPositions.PssSlideStarPos, -6358.0, -4300.0, 4700.0)
vec3f_set(gLevelValues.starPositions.RacingPenguinStarPos, -7339.0, -5700.0, -6774.0)
vec3f_set(gLevelValues.starPositions.TreasureChestStarPos, -1800.0, -2500.0, -1700.0)
vec3f_set(gLevelValues.starPositions.GhostHuntBooStarPos, 6142.0, 7920.0, -4173.0)
vec3f_set(gLevelValues.starPositions.KleptoStarPos, -5550.0, 300.0, -930.0)
vec3f_set(gLevelValues.starPositions.MerryGoRoundStarPos, -1600.0, -2100.0, 205.0)
vec3f_set(gLevelValues.starPositions.MrIStarPos, 1370.0, 2000.0, -320.0)
vec3f_set(gLevelValues.starPositions.BalconyBooStarPos, 700.0, 3200.0, 1900.0)
vec3f_set(gLevelValues.starPositions.BigBullyTrioStarPos, 3700.0, 600.0, -5500.0)

-- disable caps in cap courses
gLevelValues.wingCapDurationTotwc = 1
gLevelValues.vanishCapDurationVcutm = 1
gLevelValues.metalCapDurationCotmc = 1
