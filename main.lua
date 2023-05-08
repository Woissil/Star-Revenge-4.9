-- name: Star Revenge 4.9
-- description: Star Revenge 4.9 Ported by Woissil and Blocky
-- incompatible: romhack

gLevelValues.entryLevel             = LEVEL_CASTLE_GROUNDS
gLevelValues.exitCastleLevel        = LEVEL_CASTLE_GROUNDS
gLevelValues.exitCastleWarpNode     = 0x0A

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

---Yellow / Red coin star Code by Sunk---

gLevelValues.coinsRequiredForCoinStar = 80

---@param obj Object
function bhv_custom_red_coin_star_loop(obj)
    if obj.oHiddenStarTriggerCounter >= gMarioStates[0].area.numRedCoins - 6 then
        obj.oAction = 1
    end
end

-- These both need to be changed, though they share a lot of the same code so the function can be reused
hook_behavior(id_bhvHiddenRedCoinStar, OBJ_LIST_LEVEL, false, nil, bhv_custom_red_coin_star_loop)
hook_behavior(id_bhvBowserCourseRedCoinStar, OBJ_LIST_LEVEL, false, nil, bhv_custom_red_coin_star_loop)

----No Fall Damage---

function no_fall_damage(m)
 m.peakHeight = m.pos.y
end
hook_event(HOOK_MARIO_UPDATE, no_fall_damage)

---music---

smlua_audio_utils_replace_sequence(0x01, 0x0C, 75, "01_Seq_custom")
smlua_audio_utils_replace_sequence(0x02, 0x1A, 75, "02_Seq_custom")
smlua_audio_utils_replace_sequence(0x04, 0x1A, 75, "04_Seq_custom")
smlua_audio_utils_replace_sequence(0x06, 0x25, 75, "06_Seq_custom")
smlua_audio_utils_replace_sequence(0x0B, 0x14, 75, "0B_Seq_custom")
smlua_audio_utils_replace_sequence(0x0D, 0x0C, 75, "0D_Seq_custom")
smlua_audio_utils_replace_sequence(0x0E, 0x25, 75, "0E_Seq_custom")
smlua_audio_utils_replace_sequence(0x0F, 0x18, 75, "0F_Seq_custom")
smlua_audio_utils_replace_sequence(0x10, 0x12, 75, "10_Seq_custom")
smlua_audio_utils_replace_sequence(0x12, 0x1F, 75, "12_Seq_custom")
smlua_audio_utils_replace_sequence(0x14, 0x1A, 75, "14_Seq_custom")
smlua_audio_utils_replace_sequence(0x15, 0x0E, 75, "15_Seq_custom")
smlua_audio_utils_replace_sequence(0x16, 0x0C, 75, "16_Seq_custom")
smlua_audio_utils_replace_sequence(0x17, 0x1A, 75, "17_Seq_custom")
smlua_audio_utils_replace_sequence(0x1B, 0x14, 75, "1B_Seq_custom")
smlua_audio_utils_replace_sequence(0x1C, 0x20, 75, "1C_Seq_custom")
smlua_audio_utils_replace_sequence(0x1D, 0x1E, 75, "1D_Seq_custom")
smlua_audio_utils_replace_sequence(0x1E, 0x1B, 75, "1E_Seq_custom")
smlua_audio_utils_replace_sequence(0x1F, 0x1A, 75, "1F_Seq_custom")
smlua_audio_utils_replace_sequence(0x20, 0x23, 75, "20_Seq_custom")
smlua_audio_utils_replace_sequence(0x21, 0x0C, 75, "21_Seq_custom")
smlua_audio_utils_replace_sequence(0x24, 0x0C, 75, "24_Seq_custom")
smlua_audio_utils_replace_sequence(0x27, 0x25, 75, "27_Seq_custom")
smlua_audio_utils_replace_sequence(0x28, 0x25, 75, "28_Seq_custom")
smlua_audio_utils_replace_sequence(0x29, 0x19, 75, "29_Seq_custom")
smlua_audio_utils_replace_sequence(0x2A, 0x25, 75, "2A_Seq_custom")
smlua_audio_utils_replace_sequence(0x2C, 0x25, 75, "2C_Seq_custom")
smlua_audio_utils_replace_sequence(0x2E, 0x1A, 75, "2E_Seq_custom")
smlua_audio_utils_replace_sequence(0x30, 0x0B, 75, "30_Seq_custom")
smlua_audio_utils_replace_sequence(0x32, 0x25, 75, "32_Seq_custom")
smlua_audio_utils_replace_sequence(0x34, 0x25, 75, "34_Seq_custom")
smlua_audio_utils_replace_sequence(0x3C, 0x25, 75, "3C_Seq_custom")
smlua_audio_utils_replace_sequence(0x3D, 0x25, 75, "3D_Seq_custom")
smlua_audio_utils_replace_sequence(0x3F, 0x19, 75, "3F_Seq_custom")
smlua_audio_utils_replace_sequence(0x41, 0x25, 75, "41_Seq_custom")
smlua_audio_utils_replace_sequence(0x42, 0x0C, 75, "42_Seq_custom")
smlua_audio_utils_replace_sequence(0x43, 0x0C, 75, "43_Seq_custom")
smlua_audio_utils_replace_sequence(0x44, 0x0C, 75, "44_Seq_custom")
smlua_audio_utils_replace_sequence(0x45, 0x25, 75, "45_Seq_custom")
smlua_audio_utils_replace_sequence(0x47, 0x25, 75, "47_Seq_custom")
smlua_audio_utils_replace_sequence(0x48, 0x0C, 75, "48_Seq_custom")
smlua_audio_utils_replace_sequence(0x49, 0x0C, 75, "49_Seq_custom")
smlua_audio_utils_replace_sequence(0x4B, 0x19, 75, "4B_Seq_custom")
smlua_audio_utils_replace_sequence(0x4C, 0x1E, 75, "4C_Seq_custom")
smlua_audio_utils_replace_sequence(0x4D, 0x0C, 75, "4D_Seq_custom")
smlua_audio_utils_replace_sequence(0x4E, 0x25, 75, "4E_Seq_custom")

---star pos---

starPositions = gLevelValues.starPositions

vec3f_set(starPositions.KingWhompStarPos, -512.0, 5325.0, 5840.0)
vec3f_set(starPositions.BigBullyTrioStarPos, -1754.0, 223.0, 5773.0)
vec3f_set(starPositions.TuxieMotherStarPos, 3130.0, 845.0, 3256.0)
vec3f_set(starPositions.KoopaBobStarPos, -2091.0, 2790.0, -1464.0)
vec3f_set(starPositions.KoopaThiStarPos, -5074.0, 822.0, 8084.0)

--bob waterfall text--

add_scroll_target(28, "VB_bob_1_0xe0758f0", 0, 10)
add_scroll_target(28, "VB_bob_1_0xe075990", 0, 11)
add_scroll_target(28, "VB_bob_1_0xe075a40", 0, 10)
add_scroll_target(28, "VB_bob_1_0xe075ae0", 0, 11)
add_scroll_target(28, "VB_bob_1_0xe075b90", 0, 10)
add_scroll_target(28, "VB_bob_1_0xe075c30", 0, 9)
add_scroll_target(28, "VB_bob_1_0xe075cc0", 0, 11)
add_scroll_target(28, "VB_bob_1_0xe075d70", 0, 3)

--bob water--

add_scroll_target(29, "VB_bob_1_0xe09d0b0", 0, 8)

--bob blue grass weird thing--

add_scroll_target(27, "VB_bob_1_0xe04a3e0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04a490", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04a520", 0, 7)
add_scroll_target(27, "VB_bob_1_0xe04a590", 0, 8)
add_scroll_target(27, "VB_bob_1_0xe04a610", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04a6c0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04a770", 0, 10)
add_scroll_target(27, "VB_bob_1_0xe04a810", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04a8c0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04a950", 0, 12)
add_scroll_target(27, "VB_bob_1_0xe04aa10", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04aac0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04ab50", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04abe0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04ac70", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04ad00", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04adb0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04ae40", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04af30", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04b000", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b0b0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b160", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04b1f0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b2a0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04b330", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04b3c0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b470", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04b500", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04b590", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04b620", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b6d0", 0, 7)
add_scroll_target(27, "VB_bob_1_0xe04b740", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04b810", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b8c0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04b970", 0, 10)
add_scroll_target(27, "VB_bob_1_0xe04ba10", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04bae0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04bb70", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04bc00", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04bc90", 0, 7)
add_scroll_target(27, "VB_bob_1_0xe04bd00", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04bdb0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04be40", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04bed0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04bf80", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04c030", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c100", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c1d0", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c2a0", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04c370", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04c460", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04c4f0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04c5a0", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c670", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c740", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c810", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04c900", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04c9d0", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04caa0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04cb50", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04cc40", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04cd10", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04cdc0", 0, 9)
add_scroll_target(27, "VB_bob_1_0xe04ce50", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04cf40", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04cff0", 0, 11)
add_scroll_target(27, "VB_bob_1_0xe04d0a0", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04d170", 0, 15)
add_scroll_target(27, "VB_bob_1_0xe04d260", 0, 12)
add_scroll_target(27, "VB_bob_1_0xe04d320", 0, 13)
add_scroll_target(27, "VB_bob_1_0xe04d3f0", 0, 8)
