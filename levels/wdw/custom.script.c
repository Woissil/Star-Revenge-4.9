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

#include "levels/wdw/header.h"
#include "levels/bbh/header.h"

extern u8 _wdw_segment_ESegmentRomStart[];
extern u8 _wdw_segment_ESegmentRomEnd[];

const LevelScript level_wdw_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _wdw_segment_ESegmentRomStart, _wdw_segment_ESegmentRomEnd),
	LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom30848096_skybox_mio0SegmentRomStart, _SkyboxCustom30848096_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd),
	LOAD_RAW(12, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd),
	LOAD_MIO0(6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd),
	LOAD_RAW(13, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd),
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
	JUMP_LINK(script_func_global_18),
	JUMP_LINK(local_area_wdw_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_wdw_1_[] = {
	AREA(1, Geo_wdw_1_0x1d91380),
	TERRAIN(col_wdw_1_0xe08ecc0),
	SET_BACKGROUND_MUSIC(0, 41),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_wdw_1_),
	JUMP_LINK(local_warps_wdw_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_wdw_1_[] = {
	OBJECT_WITH_ACTS(0, 423, -2146, -2367, 0, 90, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 10579, 4506, -4349, 0, 0, 0, 0x14010000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(124, 10019, 4387, -3627, 0, 270, 0, 0x2b0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 9915, 5108, -4183, 0, 270, 0, 0xb0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, -4361, -549, 630, 0, 202, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2594, 817, -5398, 0, 178, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, 4142, 817, -2423, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 6155, 817, -12222, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, 3150, 487, -11259, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(122, 9205, 6526, -12174, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -5625, 5086, -934, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, -10281, -4006, 1925, 0, 0, 0, 0x50000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 1683, -2190, -3697, 0, 0, 0, 0x40000,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -3109, -3780, 7460, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, -3109, -3780, 7460, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 1303, -2400, 4013, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(207, -4381, 4058, -2017, 0, 90, 0, 0xff0000,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(0, 8999, 1944, 7066, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 8419, 1555, 7718, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 7793, 1464, 8262, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 6755, 1647, 8019, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 5410, 1289, 8014, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 5247, 1347, 7030, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 4289, 986, 6472, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 4285, 673, 5482, 0, 211, 0, 0x5f0000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, -1424, 145, -3742, 0, 211, 0, 0x0,  bhvMrI, 31),
	OBJECT_WITH_ACTS(122, -2240, -1417, -8800, 0, 192, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(194, -2526, 4439, -14771, 0, 211, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -2911, 4439, -10590, 0, 211, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(124, -4870, 5354, -5464, 0, 202, 0, 0x7c0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -4489, 3385, -10394, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -6577, 548, -3241, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 8140, 4079, -4459, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 3259, 203, 3424, 0, 0, 0, 0x4000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(116, 8879, 1869, 545, 0, 0, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(0, 8879, 1869, 545, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(137, 11442, -1531, -1589, 0, 0, 0, 0xe0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, 2317, 8245, -4256, 0, 0, 0, 0x50000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, -1209, 3470, 4042, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(137, 1304, 8245, 4092, 0, 0, 0, 0x40000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -2607, -4087, 15417, 0, 0, 0, 0x40000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, -10047, 168, -8520, 0, 313, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(195, -10854, 168, -11275, 0, 323, 0, 0x7d0000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(194, -8128, 240, -5384, 0, 91, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 8365, 3381, 4952, 0, 91, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 4828, 1827, 6691, 0, 91, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 8745, 2346, 7488, 0, 91, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 7203, 2058, 7964, 0, 91, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(153, 6608, 3008, 369, 0, 91, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(0, -4979, 5428, -6553, 0, 91, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -6824, 3384, -10163, 0, 91, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(124, -5810, 4248, -14903, 0, 91, 0, 0x670000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(100, -4042, 1426, -15145, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, -4065, -1598, -15409, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, -4986, -1454, -13439, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, -3601, -1972, -12756, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, -3707, -1195, -11112, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, -3458, -1195, -10019, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, 2255, 360, -2401, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(100, 967, 3929, -3233, 0, 358, 0, 0x0,  bhvSwoop, 31),
	OBJECT_WITH_ACTS(129, 830, 3902, -2213, 0, 358, 0, 0x0,  bhvHiddenObject, 30),
	OBJECT_WITH_ACTS(217, 409, 5554, -2025, 0, 358, 0, 0x0,  bhvPushableMetalBox, 1),
	OBJECT_WITH_ACTS(217, 668, 5554, -2017, 0, 358, 0, 0x0,  bhvPushableMetalBox, 1),
	OBJECT_WITH_ACTS(0, 4069, 4238, -5062, 0, 89, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(129, -3577, 3351, 1385, 0, 36, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -4211, 3221, 527, 0, 36, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -4843, 4061, -366, 0, 32, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(180, -1569, 4470, -3649, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(206, 3988, 639, -161, 0, 59, 0, 0x110000,  bhvSnufit, 31),
	OBJECT_WITH_ACTS(206, -4577, 3892, -4503, 0, 59, 0, 0x110000,  bhvSnufit, 31),
	OBJECT_WITH_ACTS(124, 2672, 5476, -10266, 0, 59, 0, 0x9d0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 9052, 4950, -11120, 0, 253, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 9136, 2186, -13069, 0, 253, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(188, 9090, 427, -13139, 0, 253, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 1614, 427, -8878, 0, 253, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(192, 2633, 427, -4501, 0, 253, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -277, 432, -4819, 0, 253, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -1058, 519, -2306, 0, 253, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(0, -6801, 539, 892, 0, 253, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6801, -1477, 892, 0, 253, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -6801, -3291, 892, 0, 253, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(188, -7473, -4442, 778, 0, 253, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -6642, -4442, 1830, 0, 253, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -8135, -4442, 1658, 0, 253, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -10766, -4442, 2106, 0, 253, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(180, -10228, -4119, 3904, 0, 253, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, -9259, -4464, 6719, 0, 253, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -1236, -1957, 3630, 0, 253, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6718, 535, -548, 0, 271, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6718, -655, -548, 0, 271, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6718, -1757, -548, 0, 271, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 3088, 7832, -5428, 0, 271, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 4484, 7832, -3565, 0, 180, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 2184, 7832, -1282, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 914, 7832, -649, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(188, 3243, -232, 3412, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 4612, 686, 4089, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -4605, 168, -3658, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(0, 505, -3074, 2837, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(194, 1947, -2816, 1837, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(137, 6182, -2697, 50, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(188, 5573, -3125, 163, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 2553, -2507, -2254, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -768, -2507, -4202, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 1167, -2966, -6624, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(206, -1100, -2304, -6954, 0, 0, 0, 0x0,  bhvSnufit, 31),
	OBJECT_WITH_ACTS(206, -7363, -3829, 5176, 0, 0, 0, 0x0,  bhvSnufit, 31),
	OBJECT_WITH_ACTS(206, 1618, -2994, 6246, 0, 0, 0, 0x0,  bhvSnufit, 31),
	OBJECT_WITH_ACTS(0, 6737, 7591, -564, 0, 2, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6737, 6310, -564, 0, 2, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6737, 4591, -564, 0, 2, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6737, 2780, -564, 0, 2, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6732, 1463, -557, 0, 2, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5887, 4657, -8459, 0, 113, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -5911, 1638, -11229, 0, 113, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -8733, 1638, -7119, 0, 113, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(188, -11221, 168, -10695, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -12525, 816, -9031, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -11705, 816, -6934, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -5954, 816, -9663, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, -6732, 816, -9706, 0, 0, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(0, 6844, 1974, -3952, -23, 24, 17, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 6255, 1644, -5271, 0, 24, 0, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(192, 5961, 748, -7585, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(180, 3841, 676, -8343, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(122, -4534, 4637, -4324, 0, 0, 0, 0x5000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(37, -10, -2507, -2445, 0, 270, 0, 0x40000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(37, -10, -2507, -2293, 0, 90, 0, 0x40000,  bhvDoorWarp, 31),
	OBJECT_WITH_ACTS(217, 671, 5856, -2024, 0, 0, 0, 0x0,  bhvPushableMetalBox, 1),
	OBJECT_WITH_ACTS(217, 415, 5856, -2025, 0, 0, 0, 0x0,  bhvPushableMetalBox, 1),
	OBJECT_WITH_ACTS(124, 7781, 3664, 3876, 0, 67, 0, 0x3b0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 10575, 4866, -4344, 0, 0, 0, 0x14010000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 10582, 4866, -3925, 0, 0, 0, 0x14010000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 10582, 4488, -3925, 0, 0, 0, 0x14010000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 4751, 379, 2775, 0, 4, 0, 0x0,  bhvPushableMetalBox, 31),
	OBJECT_WITH_ACTS(0, 5021, 379, 2762, 0, 4, 0, 0x0,  bhvPushableMetalBox, 31),
	OBJECT_WITH_ACTS(0, -3474, 4478, -2018, 0, 270, 0, 0x450000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, -1325, -3074, 2590, 0, 0, 0, 0x450000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(241, -1325, -2939, 2590, 0, 0, 0, 0x0,  bhvSwitchblock_MOP, 31),
	OBJECT_WITH_ACTS(242, -5022, 4060, -985, 0, 13, 0, 0x10000,  bhvSwitchblock_Switch_MOP, 31),
	OBJECT_WITH_ACTS(124, -1094, -3075, 2940, 0, 104, 0, 0x900000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(212, -3479, 4109, -2008, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 7499, 1760, 550, 0, 90, 0, 0x40000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 10, 5, 15, 0, 0, 20, 43,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 15, 0, 0, 20, 44,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 5, 5, 15, 0, 0, 20, 45,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_wdw_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(0, 11, 1, 0, 0),
	WARP_NODE(1, 36, 1, 10, 0),
	WARP_NODE(2, 8, 1, 0, 0),
	WARP_NODE(11, 9, 1, 0, 0),
	WARP_NODE(3, 10, 1, 1, 0),
	WARP_NODE(69, 6, 4, 69, 0),
	WARP_NODE(4, 10, 1, 1, 0),
	WARP_NODE(240, 26, 1, 23, 0),
	WARP_NODE(241, 26, 1, 24, 0),
	RETURN()
};