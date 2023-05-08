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

#include "areas/3/custom.model.inc.h"

#include "areas/4/custom.model.inc.h"

#include "levels/ttc/header.h"
#include "levels/bbh/header.h"

extern u8 _ttc_segment_ESegmentRomStart[];
extern u8 _ttc_segment_ESegmentRomEnd[];

const LevelScript level_ttc_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _ttc_segment_ESegmentRomStart, _ttc_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom34823824_skybox_mio0SegmentRomStart, _SkyboxCustom34823824_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd),
	LOAD_RAW(12, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd),
	LOAD_MIO0(6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
	LOAD_RAW(13, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
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
	// LOAD_MODEL_FROM_GEO(88, 0x0500c778),
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
	JUMP_LINK(script_func_global_12),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_ttc_1_),
	JUMP_LINK(local_area_ttc_2_),
	JUMP_LINK(local_area_ttc_3_),
	JUMP_LINK(local_area_ttc_4_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ttc_1_[] = {
	AREA(1, Geo_ttc_1_0x215bdb0),
	TERRAIN(col_ttc_1_0xe093a70),
	SET_BACKGROUND_MUSIC(0, 62),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ttc_1_),
	JUMP_LINK(local_warps_ttc_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ttc_1_[] = {
	OBJECT_WITH_ACTS(0, 0, 360, 0, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(137, 5885, 1944, -13307, 0, 0, 0, 0x50000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -2663, 3748, -14816, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, 10229, 3143, 3487, 0, 340, 0, 0xa0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, 7422, 7333, -6837, 0, 0, 0, 0xe0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -3547, 7320, -9467, 0, 0, 0, 0xc0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(215, 6956, 3063, -4856, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 2375, 1852, -5796, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 5121, 5258, -2152, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 8891, 3641, -4602, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 9887, 3842, -1087, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 5469, 5335, 447, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 5488, 3779, 3649, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(0, 2359, 2960, -5784, 0, 0, 0, 0x2000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(215, 2783, 4441, 3620, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(22, 4742, 2100, -6943, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(116, -2931, 4523, -6323, 0, 0, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(0, 11114, 591, -8891, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(201, -1324, 2848, -13835, 0, 0, 0, 0x0,  bhvCannonClosed, 31),
	OBJECT_WITH_ACTS(201, 5886, 2843, -10685, 0, 270, 0, 0x0,  bhvCannonClosed, 31),
	OBJECT_WITH_ACTS(137, -2338, 4544, -435, 0, 0, 0, 0x120000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(120, 4962, 4128, -13830, 0, 1, 0, 0x130000,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(180, 3906, 3972, -13853, 0, 50, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 2003, 2850, -13846, 0, 50, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(124, -2947, 2700, -9464, 0, 50, 0, 0x770000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(123, -1923, 1500, -14140, 0, 91, 0, 0x32000000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(192, 6122, 2850, -10465, 0, 91, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 6143, 2250, -9532, 0, 91, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 6559, 2250, -8138, 0, 91, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(0, 5449, 1398, -9867, 0, 91, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2163, 2070, -8741, 0, 91, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -309, 2130, -6513, 0, 179, 0, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(100, 3553, 2100, -6644, 0, 212, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(100, 561, 5070, -9433, 0, 212, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(223, 187, 4800, -8297, 0, 212, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -1685, 4800, -8781, 0, 212, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, -3302, 5400, -5245, 0, 212, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(103, -3167, 5624, -3533, 0, 359, 0, 0x0,  bhvSmallWhomp, 31),
	OBJECT_WITH_ACTS(84, -3408, 2849, 779, 0, 359, 0, 0x0,  bhvEnemyLakitu, 31),
	OBJECT_WITH_ACTS(100, -3717, 2807, -876, 0, 359, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(0, -2544, 2718, -2575, 0, 359, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(116, -2884, 2370, -3619, 0, 92, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, -3263, 1950, -4506, 0, 92, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(100, -3463, 1800, -6112, 0, 92, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(0, 2897, 1962, -5987, 0, 92, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 5716, 4326, 447, 0, 92, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(100, 2629, 4050, 2170, 0, 92, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(223, 3545, 3501, 1121, 0, 92, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, 5436, 3861, 1533, 0, 92, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 9216, 4281, 1145, 0, 92, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(137, 6119, 5654, -4937, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 5541, 1590, -4671, 0, 92, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(103, -413, 600, -4153, 0, 92, 0, 0x0,  bhvSmallWhomp, 31),
	OBJECT_WITH_ACTS(100, 4586, 1097, -3456, 0, 92, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(180, 4124, 828, -1917, 0, 92, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 4001, 450, -360, 0, 92, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(84, 3443, 1296, 5270, 0, 92, 0, 0x0,  bhvEnemyLakitu, 31),
	OBJECT_WITH_ACTS(100, 2484, 450, 4147, 0, 92, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(0, 5360, 1669, 4070, 0, 92, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3315, 1801, 6785, 0, 92, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3579, 1201, 10526, 0, 135, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 4134, 1650, 12762, 0, 179, 0, 0x130000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(100, 3552, 1350, 14342, 0, 140, 0, 0x0,  bhvPiranhaPlant, 31),
	OBJECT_WITH_ACTS(180, 2991, 1590, 11754, 0, 140, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 9119, 3510, 8386, 0, 140, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 9575, 3300, 6635, 0, 140, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, 9507, 3150, 11811, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, 6178, 2400, 14478, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 4896, 901, 9462, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -223, 1800, -5313, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(22, 5661, 4050, -14061, 0, 0, 0, 0x20000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, 5148, 4530, -13831, 0, 90, 0, 0x40000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 4142, 2532, -7143, 0, 90, 0, 0x30000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(195, -219, 270, -2124, 0, 0, 0, 0x870000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(124, 2197, 6348, -10063, 0, 0, 0, 0x830000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(207, 2198, 6348, -9802, 0, 180, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(129, 944, 4590, -7378, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 1450, 4590, -7593, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(124, 2933, 1350, 5382, 0, 180, 0, 0x820000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 5854, 5218, -1629, 0, 183, 0, 0x810000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 5422, 5218, -1796, 0, 326, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(152, 706, 2023, -8889, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(0, 2581, 2214, -9034, 0, 0, 0, 0x4000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(116, 11104, 566, -8886, 0, 0, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(0, 4142, 2532, -7143, 0, 90, 0, 0x50000,  bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(152, 0, 96, -1324, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 62),
	OBJECT_WITH_ACTS(152, 5435, 1061, -9851, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 62),
	RETURN()
};

const LevelScript local_warps_ttc_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(0, 14, 1, 0, 0),
	WARP_NODE(1, 14, 2, 10, 0),
	WARP_NODE(2, 14, 3, 10, 0),
	WARP_NODE(3, 14, 1, 0, 0),
	WARP_NODE(4, 14, 1, 0, 0),
	WARP_NODE(5, 14, 1, 0, 0),
	WARP_NODE(240, 16, 1, 14, 0),
	WARP_NODE(241, 16, 1, 15, 0),
	RETURN()
};

const LevelScript local_area_ttc_2_[] = {
	AREA(2, Geo_ttc_2_0x215bca0),
	TERRAIN(col_ttc_2_0xe026270),
	SET_BACKGROUND_MUSIC(0, 59),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ttc_2_),
	JUMP_LINK(local_warps_ttc_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ttc_2_[] = {
	OBJECT_WITH_ACTS(0, 154, 576, 662, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, 150, 11225, 9350, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(124, 151, 600, -2102, 0, 0, 0, 0xa50000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 2702, 3000, -8400, 0, 270, 0, 0xa60000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 9001, 5400, -5855, 0, 180, 0, 0xa70000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 6448, 7800, 452, 0, 90, 0, 0xa00000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 148, 10200, 3005, 0, 180, 0, 0xa90000,  bhvMessagePanel, 31),
	RETURN()
};

const LevelScript local_warps_ttc_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(240, 14, 1, 5, 0),
	WARP_NODE(241, 14, 1, 3, 0),
	RETURN()
};

const LevelScript local_area_ttc_3_[] = {
	AREA(3, Geo_ttc_3_0x215bb80),
	TERRAIN(col_ttc_3_0xe0136c0),
	SET_BACKGROUND_MUSIC(0, 2),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ttc_3_),
	JUMP_LINK(local_warps_ttc_3_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ttc_3_[] = {
	OBJECT_WITH_ACTS(0, 3, -132, 755, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, 6065, 4637, -5461, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(212, 5535, 4485, 4596, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 7776, 5069, -5458, 0, 270, 0, 0x20000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(180, 331, 405, -1423, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 8299, 4037, -5692, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 2799, 4250, 1274, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	RETURN()
};

const LevelScript local_warps_ttc_3_[] = {
	WARP_NODE(10, 9, 3, 0, 0),
	WARP_NODE(0, 14, 3, 0, 0),
	WARP_NODE(1, 14, 4, 2, 0),
	WARP_NODE(2, 14, 3, 0, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 14, 1, 4, 0),
	RETURN()
};

const LevelScript local_area_ttc_4_[] = {
	AREA(4, Geo_ttc_4_0x215ba60),
	TERRAIN(col_ttc_4_0xe019990),
	SET_BACKGROUND_MUSIC(0, 2),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ttc_4_),
	JUMP_LINK(local_warps_ttc_4_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ttc_4_[] = {
	OBJECT_WITH_ACTS(0, 6063, 1496, 9724, 0, 90, 0, 0x20000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(122, -1, 6890, 3500, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(180, 3374, 2002, 3639, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 3865, 2002, 1019, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -529, -908, -1046, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 686, 6808, 5298, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(212, -447, 3043, 4329, 0, 180, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(153, 463, 2916, 4711, 0, 0, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(153, 994, 3210, 4874, 0, 0, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(153, 1503, 3774, 5728, 0, 0, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(153, 1771, 4212, 6123, 0, 0, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(152, 4803, 1860, 5432, 0, 39, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(152, 5039, 1860, 5240, 0, 39, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(153, 1214, 3573, 5314, 0, 0, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(212, 5572, 1413, -329, 0, 0, 0, 0x0,  bhv1Up, 31),
	RETURN()
};

const LevelScript local_warps_ttc_4_[] = {
	WARP_NODE(10, 9, 4, 0, 0),
	WARP_NODE(0, 14, 4, 0, 0),
	WARP_NODE(1, 14, 4, 0, 0),
	WARP_NODE(2, 14, 3, 0, 0),
	WARP_NODE(240, 26, 4, 10, 0),
	WARP_NODE(241, 14, 3, 2, 0),
	RETURN()
};