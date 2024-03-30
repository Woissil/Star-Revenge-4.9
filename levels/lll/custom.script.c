#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"
#include "game/level_update.h"
#include "levels/scripts.h"
#include "actors/common1.h"
#include "make_const_nonconst.h"

#include "areas/1/custom.model.inc.h"

#include "levels/lll/header.h"
#include "levels/bbh/header.h"

extern u8 _lll_segment_ESegmentRomStart[];
extern u8 _lll_segment_ESegmentRomEnd[];

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _lll_segment_ESegmentRomStart, _lll_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom27481760_skybox_mio0SegmentRomStart, _SkyboxCustom27481760_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group7_mio0SegmentRomStart, _group7_mio0SegmentRomEnd),
	LOAD_RAW(12, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd),
	LOAD_MIO0(6, _group13_mio0SegmentRomStart, _group13_mio0SegmentRomEnd),
	LOAD_RAW(13, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR,           haunted_door_geo),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP,         geo_bbh_0005B0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM,      geo_bbh_0005E0),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF,       geo_bbh_000610),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR,          geo_bbh_000628),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND,         geo_bbh_000640),
	LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB,            geo_bbh_000658),
	// Unspecified Models
	LOAD_MODEL_FROM_GEO(22,  warp_pipe_geo),
	LOAD_MODEL_FROM_GEO(23,  bubbly_tree_geo),
	LOAD_MODEL_FROM_GEO(24,  spiky_tree_geo),
	LOAD_MODEL_FROM_GEO(25,  snow_tree_geo),
	LOAD_MODEL_FROM_GEO(27,  palm_tree_geo),
	LOAD_MODEL_FROM_GEO(31,  metal_door_geo),
	LOAD_MODEL_FROM_GEO(32,  hazy_maze_door_geo),
	LOAD_MODEL_FROM_GEO(34,  castle_door_0_star_geo),
	LOAD_MODEL_FROM_GEO(35,  castle_door_1_star_geo),
	LOAD_MODEL_FROM_GEO(36,  castle_door_3_stars_geo),
	LOAD_MODEL_FROM_GEO(37,  key_door_geo),
	LOAD_MODEL_FROM_GEO(38,  castle_door_geo),
	// LOAD_MODEL_FROM_GEO(131, 0x0404fe00),
	// LOAD_MODEL_FROM_DL(132, 0x08025f08, 4),
	// LOAD_MODEL_FROM_GEO(137, 0x04050000),
	// LOAD_MODEL_FROM_DL(158, 0x0302c8a0, 4),
	// LOAD_MODEL_FROM_DL(159, 0x0302bcd0, 4),
	// LOAD_MODEL_FROM_DL(161, 0x0301cb00, 4),
	// LOAD_MODEL_FROM_DL(164, 0x04032a18, 4),
	// LOAD_MODEL_FROM_DL(201, 0x080048e0, 4),
	// LOAD_MODEL_FROM_DL(218, 0x08024bb8, 4),
	JUMP_LINK(script_func_global_1),
	JUMP_LINK(script_func_global_8),
	JUMP_LINK(script_func_global_14),
	JUMP_LINK(local_area_lll_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_lll_1_[] = {
	AREA(1, Geo_lll_1_0x1a5b5d0),
	TERRAIN(col_lll_1_0xe0dbe50),
	SET_BACKGROUND_MUSIC(0, 61),
	TERRAIN_TYPE(2),
	JUMP_LINK(local_objects_lll_1_),
	JUMP_LINK(local_warps_lll_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_lll_1_[] = {
	OBJECT_WITH_ACTS(0, -720, 420, -1800, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(223, 5038, 600, 8539, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -2026, 3150, 6764, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -13838, 1290, 10756, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(124, -1249, 6148, 8091, 0, 8, 0, 0x5c0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(223, -8185, 990, 3501, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, -13944, 2760, 5515, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 8371, 3180, 12223, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 7406, 90, 9363, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 223, 1050, 4006, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(105, -12696, 480, 8002, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, 902, 2108, 13413, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, 11549, 150, 8944, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, 3616, 582, 4021, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -8301, 1455, 10557, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(105, -2821, 450, 3993, 0, 0, 0, 0x0,  bhvSkeeter, 31),
	OBJECT_WITH_ACTS(0, -12527, 3300, 7993, 0, 247, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -12189, 1452, 11940, 0, 247, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10270, 891, 8948, 0, 247, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, -10270, 891, 8948, 0, 247, 0, 0x2000000,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -16389, 709, 9769, 0, 247, 0, 0x2000000,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -11278, 2820, 9380, 0, 247, 0, 0x2000000,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(129, -11266, 2050, 4489, 0, 247, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -11169, 2050, 4629, 0, 299, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -11325, 2050, 4660, 0, 299, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -11202, 2050, 4790, 0, 0, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -11026, 2050, 4766, 0, 0, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -10989, 2050, 4572, 0, 0, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(129, -11080, 2050, 4492, 0, 0, 0, 0x2000000,  bhvBreakableBox, 31),
	OBJECT_WITH_ACTS(0, -14291, 3060, 5300, 0, 0, 0, 0x2000000,  bhvFlipswitch_Panel_StarSpawn_MOP, 31),
	OBJECT_WITH_ACTS(42, -11176, 1652, 4643, 0, 0, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -13758, 2677, 10813, 0, 0, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -14305, 1256, 5303, 0, 0, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -12512, 2286, 7991, 0, 0, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -11163, 742, 4628, 0, 0, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -8685, 882, 7427, 0, 0, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(137, -14540, 7576, 13018, 0, 270, 0, 0xe0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, -8292, 2217, 13885, 0, 275, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -1201, 8188, 16361, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 7175, 7306, 5613, 0, 275, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 7538, 5330, 1874, 0, 275, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(129, 11487, 4237, 652, 0, 0, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(47, 11764, 4274, 576, 0, 5, 0, 0x0,  bhvFlipswap_Platform_MOP, 31),
	OBJECT_WITH_ACTS(47, 12836, 4042, 735, 0, 342, 0, 0x0,  bhvFlipswap_Platform_MOP, 31),
	OBJECT_WITH_ACTS(47, 13747, 3932, 1522, 0, 319, 0, 0x0,  bhvFlipswap_Platform_MOP, 31),
	OBJECT_WITH_ACTS(47, 12958, 3932, 2235, 0, 14, 0, 0x0,  bhvFlipswap_Platform_MOP, 31),
	OBJECT_WITH_ACTS(47, 11893, 3932, 2316, 0, 17, 0, 0x0,  bhvFlipswap_Platform_MOP, 31),
	OBJECT_WITH_ACTS(47, 12295, 3674, 3105, 0, 124, 0, 0x0,  bhvFlipswap_Platform_MOP, 31),
	OBJECT_WITH_ACTS(0, 9375, 3282, 9621, 0, 219, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6932, 2704, 10517, 0, 81, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2251, 2200, 12179, 0, 127, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 2582, 2727, -1173, 0, 154, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 8618, 94, 8611, 0, 134, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 10194, 413, 7802, 0, 75, 0, 0x50000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(201, -12271, 694, 13319, 0, 0, 0, 0xa00000,  bhvCannonClosed, 31),
	OBJECT_WITH_ACTS(0, 2094, 762, 5156, 0, 67, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(195, 5639, 0, 12175, 0, 67, 0, 0x940000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(0, 2492, 670, 2240, 0, 67, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3135, 4254, 8596, 0, 301, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(123, -1238, 6208, 17118, 0, 135, 0, 0x320000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(0, -4562, 5775, 16437, 0, 46, 0, 0x280000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(0, -4201, 5498, 16111, 0, 1, 0, 0x50000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(0, -4210, 5112, 14220, 0, 1, 0, 0x1e0000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(0, -11614, 1278, 11390, 0, 314, 0, 0x460000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(122, -49, 3861, -12, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(120, -13043, 1714, 14289, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(86, 8676, 2250, 6360, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 12710, 3390, 6703, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 11727, 2963, 2190, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -3692, 2898, 8119, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -6119, 1200, 5655, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 1093, 2100, 12614, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 10388, 3470, 10385, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 7027, 0, 11069, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 3567, 660, 5869, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 2332, 300, 101, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(137, 10441, -21, 7655, 0, 75, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 1502, 2100, 14065, 0, 20, 0, 0x6e0000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(212, 3300, 4656, 6179, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(212, 4260, 4656, 6093, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(212, 4524, 4656, 6533, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(212, 4919, 4656, 5699, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 6641, 2638, 13141, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(86, 11039, 3628, 11727, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 8776, 2250, 8230, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, 4262, 540, 2545, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -2549, 1165, 6308, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -6187, 1380, 9457, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -6405, 900, 3520, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -7181, 6027, 12620, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -6145, 5877, 13526, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(0, -4829, 2940, 13826, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(86, 1020, 2100, 14056, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -298, 1429, 8020, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -4630, 4622, 16148, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -3966, 4172, 18087, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -3437, 2841, 14906, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(86, -4113, 2841, 12142, 0, 0, 0, 0x0,  bhvMrBlizzard, 31),
	OBJECT_WITH_ACTS(129, 7202, 6420, 5537, 0, 165, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 7254, 6420, 5343, 0, 165, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(207, 2719, 5070, 6972, 0, 90, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(212, -2357, 6397, 17853, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(212, 3548, 4662, 6697, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, -745, 6973, 15897, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, -7167, 4398, 1893, 0, 93, 0, 0x950000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(38, -818, 300, -2071, 0, 0, 0, 0x2c0000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(38, -666, 300, -2071, 0, 180, 0, 0x2c0000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(124, -465, 300, -1997, 0, 0, 0, 0x7f0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 8781, 3573, 13481, 0, 260, 0, 0x30000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 9277, 3255, 13416, 0, 350, 0, 0xf020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 1850, 4025, 15942, 0, 0, 0, 0x40000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 1841, 4372, 15508, 0, 0, 0, 0x50000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(124, 8799, 3150, 13962, 0, 258, 0, 0x4d0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -12482, 1044, 7996, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2555, 4068, 17763, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 9283, 3570, 13421, 0, 353, 0, 0xf020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 9238, 3570, 13714, 0, 353, 0, 0xf020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 9238, 3264, 13714, 0, 353, 0, 0xf020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 1841, 4372, 15508, 0, 0, 0, 0x60000,  bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(120, -1, 4217, 17260, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(212, 3087, 2536, -756, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, -4, 4, 15, 0, 0, 20, 183,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -4, 4, 15, 0, 0, 20, 184,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -4, 4, 15, 0, 0, 20, 185,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -4, 4, 15, 0, 0, 20, 186,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -5, 4, 15, 0, 0, 20, 187,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -4, 4, 15, 0, 0, 20, 188,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -4, 4, 15, 0, 0, 20, 189,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_lll_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(0, 22, 1, 0, 0),
	WARP_NODE(1, 7, 1, 11, 0),
	WARP_NODE(2, 8, 1, 10, 0),
	WARP_NODE(3, 22, 1, 0, 0),
	WARP_NODE(4, 29, 1, 10, 0),
	WARP_NODE(5, 22, 1, 0, 0),
	WARP_NODE(6, 22, 1, 0, 0),
	WARP_NODE(44, 7, 1, 11, 0),
	WARP_NODE(240, 26, 1, 15, 0),
	WARP_NODE(241, 26, 1, 16, 0),
	RETURN()
};