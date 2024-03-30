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

#include "areas/2/custom.model.inc.h"

#include "levels/totwc/header.h"
#include "levels/bbh/header.h"

extern u8 _totwc_segment_ESegmentRomStart[];
extern u8 _totwc_segment_ESegmentRomEnd[];

const LevelScript level_totwc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _totwc_segment_ESegmentRomStart, _totwc_segment_ESegmentRomEnd),
	LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom45303424_skybox_mio0SegmentRomStart, _SkyboxCustom45303424_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group8_mio0SegmentRomStart, _group8_mio0SegmentRomEnd),
	LOAD_RAW(12, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd),
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
	// LOAD_MODEL_FROM_DL(84, 0x05002e00, 4),
	// LOAD_MODEL_FROM_DL(86, 0x05003120, 4),
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
	JUMP_LINK(script_func_global_9),
	JUMP_LINK(local_area_totwc_1_),
	JUMP_LINK(local_area_totwc_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_totwc_1_[] = {
	AREA(1, Geo_totwc_1_0x2b5a5b0),
	TERRAIN(col_totwc_1_0xe0410e0),
	SET_BACKGROUND_MUSIC(0, 77),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_totwc_1_),
	JUMP_LINK(local_warps_totwc_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_totwc_1_[] = {
	OBJECT_WITH_ACTS(120, 1959, 4729, -2299, 0, 180, 0, 0xa0000,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(85, 2709, 6900, -3064, 0, 0, 0, 0x10000,  bhvCapSwitch, 31),
	OBJECT_WITH_ACTS(137, 1728, 7241, -2530, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, 4061, 1870, -4405, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, 1849, 7649, -3324, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 2407, 1065, -1106, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(116, 2410, 1028, -1110, 0, 0, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(129, 2412, -249, -1094, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(137, 2412, 241, -1095, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(207, 259, 1500, -1979, 0, 180, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(0, -1326, 1953, 1664, 0, 0, 0, 0x1000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(0, 247, 1500, 4302, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, -1049, 1500, 2384, 0, 0, 0, 0x80000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 2409, 458, -1087, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(215, -3078, 798, -4617, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 3759, 1687, -9496, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 8085, 1915, -2889, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 5692, 2462, 4550, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -2647, 2439, 4426, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -9472, 1983, -2019, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 2335, 3396, 3033, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 3084, 1536, -2264, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(0, 1063, 1953, 4301, 0, 0, 0, 0x2000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(137, 3168, 3275, -3502, 0, 0, 0, 0x130000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(180, 2407, 5108, -3918, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(137, -496, 1870, -1994, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -49, 1341, -8438, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 1074, 2040, 5495, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 3, 5, 15, 0, 0, 20, 357,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 3, 5, 15, 0, 0, 20, 358,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 3, 5, 15, 0, 0, 20, 359,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 3, 5, 15, 0, 0, 20, 360,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_totwc_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(2, 22, 1, 44, 0),
	WARP_NODE(240, 22, 1, 6, 0),
	WARP_NODE(241, 22, 1, 5, 0),
	RETURN()
};

const LevelScript local_area_totwc_2_[] = {
	AREA(2, Geo_totwc_2_0x2b5a490),
	TERRAIN(col_totwc_2_0xe056990),
	SET_BACKGROUND_MUSIC(0, 50),
	TERRAIN_TYPE(1),
	JUMP_LINK(local_objects_totwc_2_),
	JUMP_LINK(local_warps_totwc_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_totwc_2_[] = {
	OBJECT_WITH_ACTS(0, -565, 3630, -2842, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 10900, 4070, -17297, 0, 90, 0, 0x1000000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(122, 15145, 6332, -17204, 0, 7, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 14233, 5786, -17196, 0, 7, 0, 0x0,  bhvBouncingFireball, 31),
	OBJECT_WITH_ACTS(0, 13868, 5726, -17155, 0, 175, 0, 0x0,  bhvBouncingFireball, 31),
	OBJECT_WITH_ACTS(0, 13494, 5726, -17208, 0, 5, 0, 0x0,  bhvBouncingFireball, 31),
	OBJECT_WITH_ACTS(192, 3806, 4628, -14077, 0, 5, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(0, 800, 4722, -11294, 0, 180, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 1133, 4500, -9569, 0, 180, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, 2299, 4200, -8608, 0, 180, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, 5370, 4682, -3929, 0, 180, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, 5133, 4800, -8246, 0, 85, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(212, 3362, 3770, -3080, 0, 85, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 1266, 4250, -3271, 0, 85, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 1065, 3860, -2333, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(122, 3346, 6440, 5873, 0, 0, 0, 0x6000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(192, 3346, 5990, 5902, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 572, 4500, 3952, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(223, -180, 3750, 3696, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, 2726, 5478, 3663, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(194, 3066, 5920, 5080, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(180, 3178, 6060, 5452, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 2900, 5850, 4682, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 965, 3930, 853, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 102, 4260, -1834, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(42, 12906, 1998, -4583, 0, 323, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 13612, 2196, -5310, 0, 319, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 14167, 1794, -4793, 0, 340, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 14842, 1560, -4711, 0, 326, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 13312, 1560, -4144, 0, 90, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(0, 12572, 3990, -2920, 0, 90, 0, 0x5000000,  bhvFlipswitch_Panel_StarSpawn_MOP, 31),
	OBJECT_WITH_ACTS(223, 13769, 4238, -4687, 0, 90, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, 11751, 4121, -9014, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 11389, 4247, -2612, 0, 90, 0, 0x20000,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 12398, 4247, -2792, 0, 90, 0, 0x20000,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 14736, 4565, -7360, 0, 90, 0, 0x10000,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(187, 4746, 4565, -15943, 0, 90, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 1384, 4500, -11243, 0, 90, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 4662, 4800, -8864, 0, 90, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 5876, 4800, -8078, 0, 90, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 10623, 4800, -10665, 0, 90, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(187, 11703, 4800, -10881, 0, 90, 0, 0x0,  bhvButterfly, 31),
	OBJECT_WITH_ACTS(0, 8980, 5316, -10819, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 8347, 3768, -10159, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, 5537, 4464, -7415, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(122, 15441, 4078, 1839, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 14842, 3960, -4711, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 4318, 5334, -1223, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(85, 14384, 4500, 1828, 0, -90, 0, 0x20000,  bhvCapSwitch, 31),
	OBJECT_WITH_ACTS(180, 11862, 4746, -9910, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, 11475, 4500, 1803, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(137, 9734, 4963, 3631, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 8312, 3709, -2498, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 12668, 5118, -4596, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 12917, 2538, -4571, 0, 0, 0, 0x50000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(116, 15345, 4408, 1853, 0, 0, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(212, 9417, 6374, -8017, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, -10, 4, 15, 0, 0, 20, 361,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 19, 5, 15, 0, 0, 20, 362,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_totwc_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(240, 23, 1, 20, 0),
	WARP_NODE(241, 23, 1, 21, 0),
	RETURN()
};