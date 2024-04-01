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

#include "levels/ttm/header.h"
#include "levels/bob/header.h"

extern u8 _ttm_segment_ESegmentRomStart[];
extern u8 _ttm_segment_ESegmentRomEnd[];

const LevelScript level_ttm_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bobSegmentRomStart, _bobSegmentRomEnd),
	LOAD_RAW(0x0E, _ttm_segment_ESegmentRomStart, _ttm_segment_ESegmentRomEnd),
	LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom32210944_skybox_mio0SegmentRomStart, _SkyboxCustom32210944_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group1_mio0SegmentRomStart, _group1_mio0SegmentRomEnd),
	LOAD_RAW(12, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd),
	LOAD_MIO0(6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd),
	LOAD_RAW(13, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE,      bubbly_tree_geo),
	    LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440),
	    LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM,  bob_geo_000458),
	    LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS,      bob_geo_000470),
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
	LOAD_MODEL_FROM_GEO(7, box7star),
	LOAD_MODEL_FROM_GEO(8, boxstar),
	LOAD_MODEL_FROM_GEO(9, wingbox),
	LOAD_MODEL_FROM_GEO(10, vanishbox),
	LOAD_MODEL_FROM_GEO(11, metalbox),
	LOAD_MODEL_FROM_GEO(12, warpbox),
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
	JUMP_LINK(script_func_global_2),
	JUMP_LINK(script_func_global_18),
	JUMP_LINK(local_area_ttm_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(/* area */ 1, /* yaw */ 0, /* pos */ 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ttm_1_[] = {
	AREA(1, Geo_ttm_1_0x1eddf20),
	TERRAIN(col_ttm_1_0xe1042c0),
	SET_BACKGROUND_MUSIC(0, 38),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ttm_1_),
	JUMP_LINK(local_warps_ttm_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ttm_1_[] = {
	OBJECT_WITH_ACTS(0, 2458, 2376, -2077, 0, 51, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 21376, 7294, -4078, 0, 67, 0, 0xf030000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(124, 21244, 7140, -4233, 0, 247, 0, 0x2a0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 1791, 1800, -2177, 0, 51, 0, 0x280000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 20926, 7534, -4125, 0, 245, 0, 0x10000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(180, 10354, 9218, 10384, 0, 180, 0, 0x100000,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 7867, 7763, 13316, 0, 180, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 12573, 8277, 11598, 0, 180, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, 13061, 8240, 12912, 0, 180, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(188, 12532, 7650, 11854, 0, 180, 0, 0x0,  bhvBobomb, 31),
	OBJECT_WITH_ACTS(192, 13731, 7650, 6636, 0, 180, 0, 0x10000,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(46, 10701, 7200, 4618, 0, 135, 0, 0x0,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(212, 16857, 7719, 5434, 0, 180, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(116, 24476, 10536, 2768, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, 24959, 10105, 3385, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, 24992, 9435, 3639, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, 24993, 8703, 3940, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, 24062, 8433, 4031, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, 23059, 8196, 4174, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(116, 21848, 7869, 3607, 0, 180, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(212, 19554, 7363, -974, 0, 180, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(223, 19854, 7303, -2982, 0, 152, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, 14419, 7050, 419, 0, 152, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, 14352, 7572, -678, 0, 152, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 15207, 7782, -2195, 0, 152, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(194, 16494, 6522, -5079, 0, 181, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(0, 17735, 6762, -7631, 0, 181, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 17738, 6762, -8749, 0, 181, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, 19386, 5832, -12958, 0, 157, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(212, 12888, 6014, -2958, 0, 157, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(194, 19418, 9420, -17625, 0, 157, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 16392, 10362, -16852, 0, 157, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 19610, 10362, -17869, 0, 157, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(192, 20729, 9672, -16202, 0, 157, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(122, 17978, 6158, -17371, 0, 79, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, 19806, 10500, -16575, 0, 246, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, 21034, 9744, -16039, 0, 246, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, 18359, 10458, -18265, 0, 158, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(122, 15561, 11226, -18398, 0, 68, 0, 0x0,  bhvHiddenStarTrigger, 31),
	OBJECT_WITH_ACTS(0, 17196, 9090, -16443, 0, 0, 0, 0x640000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(194, 17583, 9042, -18689, 0, 0, 0, 0x640000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(0, 18364, 7938, -18239, 0, 0, 0, 0x640000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 17914, 7290, -18036, 0, 0, 0, 0x690000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 17274, 7290, -18150, 0, 0, 0, 0x690000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(0, 19370, 5898, -16803, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 16652, 5898, -17952, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 13022, 4950, -13128, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(192, 5190, 6600, -477, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(46, 10759, 7050, 6819, 0, 0, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(0, 20438, 7260, 1461, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 15284, 7260, -4035, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 11491, 5100, -1767, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 3538, 2130, -2177, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(212, 7012, 6119, 6048, 0, 36, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(192, 7319, 6006, 4197, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(180, 7903, 6006, 5364, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 10093, 7668, 2626, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 10051, 7200, 861, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(137, 10051, 7728, 861, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 4764, 9873, -13630, 0, 261, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, 4891, 9873, -8856, 0, 261, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(11, 10749, 3009, -6012, 0, 261, 0, 0x50000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(206, 12904, 6219, -2962, 0, 270, 0, 0x0,  bhvSnufit, 31),
	OBJECT_WITH_ACTS(124, 10537, 6459, 538, 0, 270, 0, 0x560000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 9445, 3920, 837, 0, 270, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 10188, 3380, 861, 0, 270, 0, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, 2936, 7502, -4614, 0, 270, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 1035, 7094, -3377, 0, 270, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, -117, 6692, -3042, 0, 270, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 3444, 7088, -1695, 0, 270, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(101, 16580, 6750, 655, 0, 0, 0, 0x0,  bhvScuttlebug, 31),
	OBJECT_WITH_ACTS(101, 9469, 6780, -13165, 0, 0, 0, 0x0,  bhvScuttlebug, 31),
	OBJECT_WITH_ACTS(101, 10800, 5100, -4220, 0, 0, 0, 0x0,  bhvScuttlebug, 31),
	OBJECT_WITH_ACTS(101, 1443, 7650, -4103, 0, 0, 0, 0x0,  bhvScuttlebug, 31),
	OBJECT_WITH_ACTS(101, 5768, 6600, -508, 0, 0, 0, 0x0,  bhvScuttlebug, 31),
	OBJECT_WITH_ACTS(0, 7068, 5998, 10672, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 7068, 7228, 10672, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 7068, 8230, 10672, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 7068, 9100, 10672, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(212, 5160, 9637, 10316, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(195, 4797, 7753, 10573, 0, 0, 0, 0x4e0000,  bhvBobombBuddy, 31),
	OBJECT_WITH_ACTS(0, 6114, 8796, 11398, 0, 0, 0, 0x100000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(212, 5959, 7725, 8502, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(192, 6397, 9004, 12839, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(194, 7509, 9077, 12504, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 8587, 8431, 13558, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(0, 5703, 2760, -4392, 0, 359, 0, 0x1000000,  bhvHiddenRedCoinStar, 31),
	OBJECT_WITH_ACTS(122, 2408, 9954, -4208, 0, 359, 0, 0x2000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(122, 23748, 11124, 2502, 0, 359, 0, 0x3000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 6083, 2550, -2296, 0, 180, 0, 0x40000,  bhvCoinFormation, 2),
	OBJECT_WITH_ACTS(212, 18138, 5479, -12717, 0, 4, 0, 0x20000,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 4849, 9954, -10908, 0, 4, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(7, 4849, 10302, -10908, 0, 4, 0, 0xe0000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(122, 7030, 5576, 10676, 0, 359, 0, 0x4000000,  bhvStar, 31),
	OBJECT_WITH_ACTS(0, 17737, 7870, -16795, 0, 338, 0, 0x0,  bhvHiddenStar, 31),
	OBJECT_WITH_ACTS(0, 16953, 3660, -1701, 0, 353, 0, 0x5000000,  bhvStar, 31),
	// OBJECT_WITH_ACTS(42, 18662, 3156, -2111, 0, 353, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	// OBJECT_WITH_ACTS(42, 15962, 3153, 2075, 0, 353, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	// OBJECT_WITH_ACTS(42, 20646, 3158, -6396, 0, 335, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(0, 14126, 5232, -13625, 0, 0, 0, 0x110000,  bhvFadingWarp, 31),
	OBJECT_WITH_ACTS(0, 6386, 2280, -4392, 0, 0, 0, 0x100000,  bhvFadingWarp, 62),
	OBJECT_WITH_ACTS(194, 18537, 3270, -857, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 19484, 3270, -5724, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 17508, 3270, -3792, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(0, 9920, 9054, 10735, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(212, 13144, 3720, -3390, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(194, 17023, 3270, -1859, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 18674, 3270, -2175, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 18288, 3270, -5011, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 16738, 3270, 3003, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 18953, 3270, 689, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 17787, 3240, 3280, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 18920, 3240, 1028, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 18803, 3240, -5954, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(194, 17178, 3210, -2938, 0, 0, 0, 0x0,  bhvHomingAmp, 31),
	OBJECT_WITH_ACTS(120, 16618, 3210, -2695, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(116, 15985, 3510, 2045, 0, 0, 0, 0x0,  bhvOneCoin, 31),
	OBJECT_WITH_ACTS(217, 6372, 2142, -4401, 0, 0, 0, 0x0,  bhvPushableMetalBox, 1),
	OBJECT_WITH_ACTS(0, 21406, 7556, -4062, 0, 66, 0, 0xf030000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 21275, 7556, -3805, 0, 66, 0, 0xf030000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 21275, 7295, -3793, 0, 66, 0, 0xf030000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 1796, 2249, -2608, 0, 52, 0, 0xf090000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 1974, 2249, -2841, 0, 52, 0, 0xf090000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, 1974, 1949, -2841, 0, 52, 0, 0xf090000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(46, 21287, 7218, -4106, 0, 334, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 21171, 7218, -3835, 0, 334, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 21171, 7517, -3842, 0, 334, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 21309, 7517, -4099, 0, 334, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 21316, 7809, -4092, 0, 334, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 10751, 2780, -5978, 0, 334, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 1946, 1926, -2473, 0, 51, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 2131, 1926, -2706, 0, 51, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 2131, 2228, -2706, 0, 51, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 1942, 2228, -2473, 0, 51, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 14614, 3203, -3406, 0, 51, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 14147, 4860, -13633, 0, 51, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(46, 13716, 6077, -1905, 0, 0, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(0, 17838, 9087, -16165, 0, 0, 0, 0x640000,  bhvPoleGrabbing, 31),
	OBJECT_WITH_ACTS(215, 2463, 3765, -8087, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 4061, 3435, -6826, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 4137, 6111, -12696, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 0, 0, 0, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(215, 0, 0, 0, 0, 0, 0, 0x0,  bhvRedCoin, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 72, 0, 0, 20, 390,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 345, 0, 0, 20, 391,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 210, 0, 0, 20, 392,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 2592, 0, 0, 20, 393,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 128, 5, 390, 0, 2, 9, 394,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 395,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 396,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 397,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 398,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 399,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 400,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 401,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 402,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 403,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 404,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 405,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -15, 4, 36, 0, 0, 20, 406,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 60, 5, 36, 0, 0, 20, 407,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_ttm_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(1, 36, 1, 0, 0),
	WARP_NODE(2, 11, 1, 11, 0),
	WARP_NODE(3, 13, 1, 10, 0),
	WARP_NODE(4, 9, 1, 0, 0),
	WARP_NODE(0, 36, 1, 0, 0),
	WARP_NODE(17, 36, 1, 16, 0),
	WARP_NODE(16, 36, 1, 17, 0),
	WARP_NODE(9, 11, 1, 11, 0),
	WARP_NODE(5, 36, 1, 0, 0),
	WARP_NODE(240, 26, 1, 25, 0),
	WARP_NODE(241, 26, 1, 26, 0),
	RETURN()
};
