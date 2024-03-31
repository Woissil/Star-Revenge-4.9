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
#include "levels/ccm/header.h"
extern u8 _ccm_segment_ESegmentRomStart[]; 
extern u8 _ccm_segment_ESegmentRomEnd[];
#include "levels/bbh/header.h"
const LevelScript level_ccm_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
LOAD_RAW(0x0E, _ccm_segment_ESegmentRomStart, _ccm_segment_ESegmentRomEnd),
LOAD_MIO0(        /*seg*/ 0x0B, _effect_mio0SegmentRomStart, _effect_mio0SegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom23975312_skybox_mio0SegmentRomStart,_SkyboxCustom23975312_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
LOAD_MIO0(6,_group17_mio0SegmentRomStart,_group17_mio0SegmentRomEnd),
LOAD_RAW(13,_group17_geoSegmentRomStart,_group17_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(MODEL_BBH_HAUNTED_DOOR,           haunted_door_geo),
LOAD_MODEL_FROM_GEO(MODEL_BBH_STAIRCASE_STEP,         geo_bbh_0005B0),
LOAD_MODEL_FROM_GEO(MODEL_BBH_TILTING_FLOOR_PLATFORM, geo_bbh_0005C8),
LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM,      geo_bbh_0005E0),
LOAD_MODEL_FROM_GEO(MODEL_BBH_TUMBLING_PLATFORM_PART, geo_bbh_0005F8),
LOAD_MODEL_FROM_GEO(MODEL_BBH_MOVING_BOOKSHELF,       geo_bbh_000610),
LOAD_MODEL_FROM_GEO(MODEL_BBH_MESH_ELEVATOR,          geo_bbh_000628),
LOAD_MODEL_FROM_GEO(MODEL_BBH_MERRY_GO_ROUND,         geo_bbh_000640),
LOAD_MODEL_FROM_GEO(MODEL_BBH_WOODEN_TOMB,            geo_bbh_000658),
LOAD_MODEL_FROM_GEO(22, warp_pipe_geo),
LOAD_MODEL_FROM_GEO(23, bubbly_tree_geo),
LOAD_MODEL_FROM_GEO(24, spiky_tree_geo),
LOAD_MODEL_FROM_GEO(25, snow_tree_geo),
LOAD_MODEL_FROM_GEO(27, palm_tree_geo),
LOAD_MODEL_FROM_GEO(31, metal_door_geo),
LOAD_MODEL_FROM_GEO(32, hazy_maze_door_geo),
LOAD_MODEL_FROM_GEO(34, castle_door_0_star_geo),
LOAD_MODEL_FROM_GEO(35, castle_door_1_star_geo),
LOAD_MODEL_FROM_GEO(36, castle_door_3_stars_geo),
LOAD_MODEL_FROM_GEO(37, key_door_geo),
LOAD_MODEL_FROM_GEO(38, castle_door_geo),
LOAD_MODEL_FROM_GEO(7, box7star),
LOAD_MODEL_FROM_GEO(8, boxstar),
LOAD_MODEL_FROM_GEO(9, wingbox),
LOAD_MODEL_FROM_GEO(10, vanishbox),
LOAD_MODEL_FROM_GEO(11, metalbox),
LOAD_MODEL_FROM_GEO(12, warpbox),
// LOAD_MODEL_FROM_GEO(131,0x0404fe00),
// LOAD_MODEL_FROM_DL(132,0x08025f08,4),
// LOAD_MODEL_FROM_GEO(137,0x04050000),
// LOAD_MODEL_FROM_DL(158,0x0302c8a0,4),
// LOAD_MODEL_FROM_DL(159,0x0302bcd0,4),
// LOAD_MODEL_FROM_DL(161,0x0301cb00,4),
// LOAD_MODEL_FROM_DL(164,0x04032a18,4),
// LOAD_MODEL_FROM_DL(201,0x080048e0,4),
// LOAD_MODEL_FROM_DL(218,0x08024bb8,4),
JUMP_LINK(script_func_global_1),
JUMP_LINK(script_func_global_2),
JUMP_LINK(script_func_global_18),
JUMP_LINK(local_area_ccm_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ccm_1_[] = {
AREA(1,Geo_ccm_1_0x17034b0),
TERRAIN(col_ccm_1_0xe0dc8d0),
SET_BACKGROUND_MUSIC(0,60),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ccm_1_),
JUMP_LINK(local_warps_ccm_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ccm_1_[] = {
OBJECT_WITH_ACTS(0,16628,3458,-93,0,273,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(223,11753,4883,6990,0,272,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,5442,4027,-7660,0,272,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,-6185,4715,-7671,0,272,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(180,-9219,2971,-3421,0,272,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-8996,3200,-5149,0,272,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,-2977,2956,12625,0,272,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,9551,3292,5142,0,272,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,1163,3292,3125,0,272,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-9090,4470,886,0,272,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-2018,4929,-7613,0,272,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(146,3960,5556,-19965,0,293,0,0x46320000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(146,1001,4622,-19108,0,107,0,0x503c0000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(146,4008,3933,-19154,0,270,0,0x463c0000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(146,984,3384,-16809,0,126,0,0x505a0000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(146,4131,1962,-17515,0,282,0,0x695a0000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(122,-2445,6871,-19271,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-345,6871,-17196,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-318,7471,-19280,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-2482,7471,-17184,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-1384,8491,-18216,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,3898,6242,-19969,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1040,4957,-19141,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,3913,4696,-19168,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,3994,1469,-17497,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1049,3886,-16840,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1370,8001,-18220,0,0,0,0x4000000, bhvHiddenStar,31),
OBJECT_WITH_ACTS(88,15767,3000,975,0,4,0,0x8a0000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(195,3748,4173,-12825,0,347,0,0x7b0000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(0,2656,1907,-17349,0,347,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(180,-8391,5049,-5422,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-6404,5283,-4505,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(89,-5716,2850,4109,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(180,-4965,7069,13053,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,9403,4722,9192,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,16165,4317,6291,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(88,11293,4364,-6016,0,347,0,0x0, bhvThwomp,31),
OBJECT_WITH_ACTS(223,-9273,4080,1833,0,351,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,7190,6510,-8327,0,90,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(187,2544,1680,-19964,0,90,0,0x0, bhvButterfly,31),
OBJECT_WITH_ACTS(187,2525,1680,-20240,0,90,0,0x0, bhvButterfly,31),
OBJECT_WITH_ACTS(187,2279,1680,-19932,0,90,0,0x0, bhvButterfly,31),
OBJECT_WITH_ACTS(187,1234,2850,2385,0,90,0,0x0, bhvButterfly,31),
OBJECT_WITH_ACTS(187,3150,3364,-919,0,90,0,0x0, bhvButterfly,31),
OBJECT_WITH_ACTS(101,-116,2850,9950,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,-5557,3043,11465,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,-7910,5250,-2076,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,-4189,2850,-9130,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,1159,3645,-6223,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,7410,4003,10970,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,10487,4426,320,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,12816,5670,-8800,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(101,8098,4350,-12593,0,90,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(0,4698,3694,-9557,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-4596,6020,13923,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5905,3149,13841,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5480,2284,10745,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-7352,4460,-8812,0,87,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,10269,5068,-13057,0,60,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1745,3026,-12246,0,180,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-4200,3026,-2166,0,180,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,2528,3026,4128,0,270,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,12207,3026,4100,0,270,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(88,14532,2940,4140,0,270,0,0x0, bhvThwomp,31),
OBJECT_WITH_ACTS(88,14552,2940,-1888,0,270,0,0x0, bhvThwomp,31),
OBJECT_WITH_ACTS(88,8608,2940,-1876,0,0,0,0x0, bhvThwomp,31),
OBJECT_WITH_ACTS(88,8564,2940,4150,0,0,0,0x0, bhvThwomp,31),
OBJECT_WITH_ACTS(101,11866,6624,-6463,0,270,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(180,-8247,1675,11564,0,270,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,1150,4645,10984,0,270,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(124,16824,3300,248,0,270,0,0x320000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(124,16489,6510,-8256,0,270,0,0x310000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,1426,6317,-8316,0,347,0,0x20000, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-414,6317,-5788,0,347,0,0x20000, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(180,184,6317,-9996,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-1029,5780,-7794,0,347,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,-4161,4860,-7211,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-7939,3408,4837,0,0,0,0x5000000, bhvStar,31),
OBJECT_WITH_ACTS(0,14749,6144,-4847,0,0,0,0x3000000, bhvStar,31),
OBJECT_WITH_ACTS(7,-707,981,-20420,0,0,0,0xe0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,-10696,3609,11551,0,0,0,0x0, bhvStar,31),
OBJECT_WITH_ACTS(0,-3214,8100,13870,0,0,0,0x2000000, bhvStar,31),
OBJECT_WITH_ACTS(8,-1605,8054,-4579,0,0,0,0xa0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(137,6175,7032,-7499,0,0,0,0x130000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(180,9447,4568,-8275,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,12647,4569,2189,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(223,11472,3000,1096,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,17043,3450,-240,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17121,4650,-2391,0,0,0,0x90000, bhvWarp,31),
OBJECT_WITH_ACTS(0,16279,7380,-8671,0,271,0,0xc0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,16685,6630,-8826,0,0,0,0xf0c0000, bhvWarp,31),
OBJECT_WITH_ACTS(0,16704,6912,-8829,0,0,0,0xf0c0000, bhvWarp,31),
OBJECT_WITH_ACTS(0,16696,6912,-8533,0,0,0,0xf0c0000, bhvWarp,31),
OBJECT_WITH_ACTS(0,16696,6618,-8533,0,0,0,0xf0c0000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17052,3738,-247,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17061,3738,46,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17061,3450,46,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17061,3450,46,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17061,3450,46,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17061,3450,46,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,17061,3450,46,0,0,0,0xf070000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,23, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,30,5,15,0,0,20,24, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_ccm_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(7,24,1,11,0),
WARP_NODE(9,16,3,10,0),
WARP_NODE(12,4,1,9,0),
WARP_NODE(240,26,1,9,0),
WARP_NODE(241,26,1,10,0),
RETURN()
};