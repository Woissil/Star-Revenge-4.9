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

#include "areas/2/custom.model.inc.h"

#include "levels/wmotr/header.h"
#include "levels/bbh/header.h"

extern u8 _wmotr_segment_ESegmentRomStart[];
extern u8 _wmotr_segment_ESegmentRomEnd[];

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _wmotr_segment_ESegmentRomStart, _wmotr_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom38444832_skybox_mio0SegmentRomStart, _SkyboxCustom38444832_skybox_mio0SegmentRomEnd),
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
	JUMP_LINK(local_area_wmotr_2_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, -7516, 442, 1353),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_wmotr_2_[] = {
	AREA(2, Geo_wmotr_2_0x24cfe50),
	TERRAIN(col_wmotr_2_0xe0e7de0),
	SET_BACKGROUND_MUSIC(0, 73),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_wmotr_2_),
	JUMP_LINK(local_warps_wmotr_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_wmotr_2_[] = {
	OBJECT_WITH_ACTS(0, -7516, 442, 1353, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(146, 6477, 10072, -26592, -20, 0, 0, 0x5a000000,  bhvSpring_MOP, 31),
	OBJECT_WITH_ACTS(146, 6489, 7290, -14963, 0, 180, 0, 0x90000000,  bhvSpring_MOP, 31),
	OBJECT_WITH_ACTS(0, -22315, 1698, -3856, 0, 0, 0, 0x5000000,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(122, -23665, 4200, 9279, 0, 0, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 11961, 15510, -12575, 0, 0, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 6467, 12703, -23917, 0, 0, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -20439, 15120, -17878, 0, 0, 0, 0x1000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, -3005, 18810, 6769, 0, 0, 0, 0x0,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, -22315, 1422, -3857, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(122, -21642, 1149, -3873, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, -20317, 2430, -3859, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, -20548, 4440, -2402, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, -19049, 6120, -2446, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, -18734, 8460, -613, 0, 0, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, -10572, 3780, -734, 0, 90, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10522, 630, 977, 0, 90, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -10522, 3000, 977, 0, 90, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -14998, 8850, -837, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(195, -4027, 0, -4378, 0, 90, 0, 0x580000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(195, -9372, 2480, -22919, 0, 90, 0, 0x590000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(0, -8846, 590, -14469, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2810, 11930, -16878, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2809, 10850, -13300, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2776, 8630, -8154, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3465, 8630, -8201, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3419, 10940, -13271, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3386, 11900, -16871, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, -3661, 16241, 11829, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3689, 16241, 13506, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, -2792, 11990, 15561, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -2822, 10100, 12959, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(120, -2977, 9320, 9131, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(0, -17420, 5370, 14557, 0, 87, 0, 0x10000,  bhvFlamethrower, 31),
	OBJECT_WITH_ACTS(0, -17425, 5370, 15865, 0, 89, 0, 0x0,  bhvBobBowlingBallSpawner, 31),
	OBJECT_WITH_ACTS(0, -7294, 429, 3908, 0, 1, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -7285, 429, 8319, 0, 1, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(84, -9473, 1419, 11860, 0, 1, 0, 0x0,  bhvEnemyLakitu, 31),
	OBJECT_WITH_ACTS(84, -12837, 3549, 15147, 0, 1, 0, 0x0,  bhvEnemyLakitu, 31),
	OBJECT_WITH_ACTS(0, -22082, 5049, 14663, 0, 1, 0, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -22124, 5049, 11839, 0, 1, 0, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(124, -24836, 5821, 9264, 0, 267, 0, 0x570000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -16305, 10255, -1504, 0, 270, 0, 0x110000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, -10584, 4900, 1151, 0, 270, 0, 0x100000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(137, -3998, -121, -5036, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(215, -3998, -121, -5036, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(137, 6495, 1415, -226, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(215, 6495, 1415, -226, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -10022, 2529, 10139, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(137, -10022, 2529, 10139, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(215, -617, 2, -1283, 0, 180, 0, 0xf0000,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -3713, 1202, -4534, 0, 180, 0, 0xf0000,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(137, -3713, 1202, -4534, 0, 180, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -619, 2, -1281, 0, 180, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 8571, 0, 9730, 0, 180, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 6201, 0, 6845, 0, 180, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -3924, 0, -1637, 0, 180, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -4170, 0, 3772, 0, 180, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -4170, 0, 3772, 0, 270, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, -3708, 16241, 8425, 0, 300, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(124, -3225, 16241, 8301, 0, 300, 0, 0x5e0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -3058, 16470, 20099, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -3058, 14700, 20099, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, -2500, 13020, 18248, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(212, -2824, 11250, 14247, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(223, -3618, 16350, 10990, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3628, 16350, 12721, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3590, 16350, 16322, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3457, 16350, 17253, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3528, 16350, 15497, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3623, 16350, 14415, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3591, 16350, 8841, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -3555, 16350, 10064, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, -4413, 512, -4415, 0, 0, 0, 0x6000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(0, 21485, 11541, -10672, 0, 180, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 14830, 11541, -11150, 0, 180, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 18658, 11541, -7644, 0, 91, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, -16284, 8915, -2724, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(215, -16284, 8915, -2724, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, -4745, -1000, 3219, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(137, -4745, -1000, 3219, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 18100, 11541, -14271, 0, 90, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 4981, 1984, -20033, 0, 91, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -6613, 1828, -21247, 0, 91, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(103, -5873, 780, -19284, 0, 91, 0, 0x0,  bhvSmallWhomp, 31),
	OBJECT_WITH_ACTS(103, -11871, 530, -19280, 0, 91, 0, 0x0,  bhvSmallWhomp, 31),
	OBJECT_WITH_ACTS(223, 17615, 14971, -12156, 0, 91, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, 19589, 14541, -9669, 0, 91, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 17875, 9708, 8045, 0, 91, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 19322, 9708, -1463, 0, 91, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 19298, 9866, 149, 0, 91, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(223, 18131, 9708, 6980, 0, 91, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, 16310, 10372, 11192, 0, 91, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 12913, 9864, 12828, 0, 91, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 11147, 7265, 12872, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 10104, 6538, 10899, 0, 0, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(102, 11145, 7163, 12877, 0, 0, 0, 0x0,  bhvChainChomp, 31),
	OBJECT_WITH_ACTS(188, 6452, 9299, -20593, 0, 316, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 6443, 9299, -22000, 0, 316, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 6406, 9299, -24973, 0, 316, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(188, 6290, 9299, -24608, 0, 316, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(180, 6791, 9585, -23707, 0, 316, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 6491, 10953, -23275, 0, 316, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 6465, 12350, -23612, 0, 316, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, 6408, 6549, -16954, 0, 316, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, 6101, 6724, -18151, 0, 316, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 6489, 5007, -20544, 0, 316, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(194, -22091, 11239, -16027, 0, 316, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -22785, 9904, -15460, 0, 316, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(0, -22110, 12034, -16163, 0, 316, 0, 0x0,  bhvBetaFishSplashSpawner, 31),
	OBJECT_WITH_ACTS(192, -19405, 1715, -16042, 0, 316, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -19343, 1715, -14360, 0, 316, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -21419, 1715, -13882, 0, 316, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -21731, 1715, -12832, 0, 316, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -21297, 1715, -11366, 0, 316, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(84, -15283, 506, -15140, 0, 316, 0, 0x0,  bhvEnemyLakitu, 31),
	OBJECT_WITH_ACTS(0, -14899, 1046, -18691, 0, 316, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(192, 6484, 7174, -17601, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 4688, 9362, -18683, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 2747, 9362, -21164, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -493, 9362, -18009, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 1616, 9362, -14381, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(153, 6469, 8766, -19825, 0, 0, 0, 0x0,  bhvSandBlock_MOP, 31),
	OBJECT_WITH_ACTS(124, 20424, 9552, -7571, 0, 191, 0, 0x5f0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 16513, 9838, 13176, 0, 305, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 9781, 4965, 13727, 0, 305, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2790, 11751, 15270, 0, 305, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2857, 12516, 15901, 0, 35, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2910, 10777, 13149, 0, 35, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, -2792, 9977, 12765, 0, 319, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(102, 6542, 1415, -243, 0, 0, 0, 0x0,  bhvChainChomp, 31),
	OBJECT_WITH_ACTS(46, 5388, 9207, -17096, 0, -90, 0, 0x0,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, -16296, 9540, -697, 0, 0, 0, 0x0,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(192, 21333, 10442, -4742, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, 21264, 11231, -6418, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(194, 20516, 11820, -7285, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 20477, 11010, -5606, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 20498, 10290, -3952, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(192, 21272, 9548, -3161, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(223, -21343, 12725, -17207, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(194, -21348, 11523, -17090, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(192, -23365, 10383, -15017, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -22024, 9775, -16281, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(124, -3610, 12299, -18726, 0, 90, 0, 0x380000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(194, 6567, 11400, -20858, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 6386, 11400, -21848, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(46, -20493, 2282, -17837, 0, -135, 0, 0x0,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(152, 6059, 8741, -17716, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(180, -3185, 1783, -21598, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -854, 2631, -24722, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 3840, 2631, -21468, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -14619, 4428, 15101, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -10481, 2664, 15627, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(152, 19158, 13440, -11195, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(152, 19700, 13400, -11500, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(152, 19939, 13440, -10745, 0, 0, 0, 0x0,  bhvShrink_Platform_MOP, 31),
	OBJECT_WITH_ACTS(0, -10, 4, 15, 0, 0, 20, 366,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -18, 4, 15, 0, 0, 20, 367,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -22, 4, 15, 0, 0, 20, 368,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -18, 4, 15, 0, 0, 20, 369,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -18, 4, 15, 0, 0, 20, 370,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -22, 4, 15, 0, 0, 20, 371,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -18, 4, 15, 0, 0, 20, 372,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -10, 4, 15, 0, 0, 20, 373,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -10, 4, 15, 0, 0, 20, 374,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -10, 4, 15, 0, 0, 20, 375,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_wmotr_2_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(16, 31, 2, 17, 0),
	WARP_NODE(17, 31, 2, 16, 0),
	WARP_NODE(240, 16, 2, 42, 0),
	WARP_NODE(241, 16, 2, 43, 0),
	RETURN()
};