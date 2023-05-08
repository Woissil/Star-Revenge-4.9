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
#include "levels/rr/header.h"
extern u8 _rr_segment_ESegmentRomStart[]; 
extern u8 _rr_segment_ESegmentRomEnd[];
#include "levels/bbh/header.h"
const LevelScript level_rr_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
LOAD_RAW(0x0E, _rr_segment_ESegmentRomStart, _rr_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom35931280_skybox_mio0SegmentRomStart,_SkyboxCustom35931280_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group9_mio0SegmentRomStart,_group9_mio0SegmentRomEnd),
LOAD_RAW(12,_group9_geoSegmentRomStart,_group9_geoSegmentRomEnd),
LOAD_MIO0(6,_group14_mio0SegmentRomStart,_group14_mio0SegmentRomEnd),
LOAD_RAW(13,_group14_geoSegmentRomStart,_group14_geoSegmentRomEnd),
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
JUMP_LINK(script_func_global_10),
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_rr_1_),
JUMP_LINK(local_area_rr_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_rr_1_[] = {
AREA(1,Geo_rr_1_0x226a3b0),
TERRAIN(col_rr_1_0xe09ca50),
SET_BACKGROUND_MUSIC(0,48),
TERRAIN_TYPE(1),
JUMP_LINK(local_objects_rr_1_),
JUMP_LINK(local_warps_rr_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_rr_1_[] = {
OBJECT_WITH_ACTS(0,3888,-32,-860,0,135,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(137,12852,1346,-11283,0,0,0,0x50000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(137,13609,3098,-13230,0,0,0,0x50000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(212,226,4923,1389,0,0,0,0x10000, bhv1Up,31),
OBJECT_WITH_ACTS(137,9181,2386,-9450,0,0,0,0x50000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(123,13113,7122,2986,0,0,0,0x32000000, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(42,9199,2111,-9059,0,0,0,0x0, bhvFlipswitch_Panel_MOP,31),
OBJECT_WITH_ACTS(0,12326,2765,-7302,0,0,0,0x4000000, bhvFlipswitch_Panel_StarSpawn_MOP,31),
OBJECT_WITH_ACTS(0,-3507,8578,-10522,0,271,0,0x2000000, bhvHiddenStar,31),
OBJECT_WITH_ACTS(122,-3672,10239,-10493,0,294,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-8566,10833,-8802,0,89,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-7869,11403,-10510,0,90,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-1640,11955,-10474,0,266,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,-7740,12717,-12287,0,77,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(122,5313,8940,-15111,0,0,0,0x0, bhvStar,31),
OBJECT_WITH_ACTS(122,550,3750,7499,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(137,10890,6790,3464,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(137,-7872,13218,-10496,0,0,0,0x10000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(123,14406,6792,2986,0,0,0,0x280000, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(123,13599,7122,2986,0,0,0,0x0, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(123,12626,7122,2986,0,0,0,0x0, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(123,15396,7290,2986,0,0,0,0x0, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(212,11863,5040,-10329,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,12807,4800,-11392,0,0,0,0xd0000, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(137,12333,5057,-7998,0,0,0,0xe0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,12039,8796,3585,0,0,0,0x3000000, bhvHiddenRedCoinStar,31),
OBJECT_WITH_ACTS(215,16667,7922,3001,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,16938,10015,-402,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,14608,10520,561,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,15029,9878,-3341,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,15591,8952,-978,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,15599,8952,-2109,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,14481,8952,-2121,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,14476,8952,-974,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,365,3821,1604,0,0,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(0,244,4140,892,0,0,0,0xc0000, bhvAirborneDeathWarp,31),
OBJECT_WITH_ACTS(137,14832,8553,2991,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(180,12018,7816,4477,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(194,12374,5886,2957,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,12459,6612,4653,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,11249,7177,4473,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,11427,5454,2972,0,0,0,0x10000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,9617,3661,6067,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,7862,3771,5275,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,8824,3538,4944,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,6764,4767,5783,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,7195,4973,5445,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,7779,5030,5154,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,7866,5116,4724,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,8813,4649,6095,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(180,7668,1242,-4094,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(212,-8017,7208,-8493,0,0,0,0x60000, bhv1Up,31),
OBJECT_WITH_ACTS(137,-8712,8027,-12771,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,-8589,7240,-10640,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-4565,7420,-9794,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(180,-1396,7663,-6250,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,602,6643,-5675,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,602,5401,-5675,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(137,750,5130,-6926,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(223,397,4971,-4922,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,-1469,3767,-5189,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(223,-1921,1050,-6409,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,3246,1525,-6373,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5420,1785,-6987,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5420,1207,-6987,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,5420,494,-6987,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,10742,1846,-1191,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,8761,2940,2856,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,10263,3750,3603,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,1125,4800,-5506,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,2051,750,-7307,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,4720,3450,-13721,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,6751,3450,-14029,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,15618,450,-10765,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,11663,2550,-5286,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(104,15157,450,-14933,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(103,8847,2100,1756,0,180,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(180,9487,2259,-4876,0,180,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(104,-711,1236,-6034,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,-864,8073,-10160,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,6311,3750,4748,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,10411,3750,7057,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,11688,2550,-1056,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,10018,2550,-810,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,5752,3450,-12830,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,5481,3465,-8301,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,5769,-71,-7662,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(104,2958,750,-7609,0,180,0,0x0, bhvKoopa,31),
OBJECT_WITH_ACTS(103,15361,9566,93,0,0,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(192,14657,8966,-216,0,180,0,0x110000, bhvGoomba,31),
OBJECT_WITH_ACTS(180,12715,9620,-1528,0,180,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,15588,8492,1570,0,180,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(103,15137,9195,-2976,0,180,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(194,-3658,11900,-10738,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-4476,12262,-10376,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-7922,12624,-12267,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-6659,12624,-12434,0,225,0,0x0, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5680,12624,-11703,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-6101,12624,-11534,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-6838,13028,-10510,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5581,12645,-10331,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-4661,11005,-10502,0,225,0,0x0, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5562,11111,-10653,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-6826,11238,-10712,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-6723,11238,-10348,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-7671,11365,-10704,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-7423,10684,-8647,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-6194,10894,-9029,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5444,10654,-9419,0,225,0,0x0, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-2526,11314,-10676,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-1994,11554,-10325,0,225,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(103,-3016,7420,-8652,0,225,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(103,13553,1950,-7636,0,90,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(103,5936,3450,-15226,0,270,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(103,4271,-71,-7081,0,315,0,0x0, bhvSmallWhomp,31),
OBJECT_WITH_ACTS(194,3085,3821,7546,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,5214,3821,7546,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,3879,3821,7546,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(129,2081,3581,7546,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2675,3581,7546,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,3513,3581,7546,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,4235,3581,7546,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,4786,3581,7546,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,5764,3581,7546,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(207,8823,1350,6104,0,0,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(0,14349,1617,-5876,0,153,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(120,-3506,8256,-10515,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(120,862,2094,-5509,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(120,3222,2556,-6958,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(0,-3600,8169,-10530,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(194,-4996,12252,-10512,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-7980,10884,-8359,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5847,11082,-10409,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5388,10860,-10059,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-3694,11292,-10494,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-1854,11592,-10752,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-3466,11952,-10407,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-5963,12582,-10665,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-8758,10692,-8627,0,0,0,0x0, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(194,-7346,10692,-9183,0,0,0,0x30000, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(0,359,4116,1609,0,357,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(0,61,4116,1591,0,357,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(0,61,3822,1591,0,357,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(46,15107,4896,4156,0,98,0,0x0, bhvCheckpoint_Flag_MOP,31),
OBJECT_WITH_ACTS(0,11442,5366,2992,0,0,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(124,15862,4896,3419,0,0,0,0x390000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(46,8242,1350,-3491,0,0,0,0x10000, bhvCheckpoint_Flag_MOP,31),
OBJECT_WITH_ACTS(0,13845,4896,5165,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(46,237,3679,901,0,0,0,0x10000, bhvCheckpoint_Flag_MOP,31),
OBJECT_WITH_ACTS(120,12042,9511,-1503,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(0,68,-24556,-8,0,0,0,0xe03af60, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe043450, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe043930, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe043e10, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe0442f0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe0447d0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe044cb0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe045190, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe045670, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe045b50, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe046030, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe046510, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe0469f0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe046ed0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe0473b0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe047890, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe047d70, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe048250, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,18,-24556,-12,0,0,1,0xe048730, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,4,-24556,-12,0,0,1,0xe063b80, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-24556,-8,0,0,0,0xe072750, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,486,-24556,-8,0,0,0,0xe078f20, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,30,-24556,-8,0,0,0,0xe06cbe0, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_rr_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(4,15,2,10,128),
WARP_NODE(12,15,1,0,0),
WARP_NODE(69,15,1,69,0),
WARP_NODE(240,16,1,16,0),
WARP_NODE(241,16,1,17,0),
RETURN()
};
const LevelScript local_area_rr_2_[] = {
AREA(2,Geo_rr_2_0x226a2a0),
TERRAIN(col_rr_2_0xe033260),
SET_BACKGROUND_MUSIC(0,6),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_rr_2_),
JUMP_LINK(local_warps_rr_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_rr_2_[] = {
OBJECT_WITH_ACTS(0,304,14,2271,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(84,-958,9330,-4009,0,0,0,0x0, bhvGhostHuntBoo,31),
OBJECT_WITH_ACTS(84,7186,1440,-682,0,0,0,0x0, bhvGhostHuntBoo,31),
OBJECT_WITH_ACTS(84,2653,4320,-1622,0,0,0,0x0, bhvGhostHuntBoo,31),
OBJECT_WITH_ACTS(84,1911,690,-9057,0,0,0,0x0, bhvGhostHuntBoo,31),
OBJECT_WITH_ACTS(84,-1793,1590,-4844,0,0,0,0x0, bhvGhostHuntBoo,31),
OBJECT_WITH_ACTS(84,6142,7920,-4173,0,0,0,0x5000000, bhvGhostHuntBigBoo,31),
OBJECT_WITH_ACTS(0,1829,2423,-5970,0,271,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(129,6658,4518,-3104,0,271,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,7192,5454,-695,0,226,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,7830,6438,-40,0,226,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(207,8648,6810,766,0,0,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(116,4,7350,-2654,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(129,6696,4692,-1455,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(116,4009,4794,-1502,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(124,8627,6810,400,0,0,0,0x490000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,6293,5016,-3225,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(212,305,-403,2276,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,504,-32748,16,0,0,0,0xe00c820, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,753,-32748,16,0,0,1,0xe017bf0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-24556,10,0,0,2,0xe01ab00, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,24,-24556,10,0,0,3,0xe01ae00, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,30,-32748,16,0,0,0,0xe01af80, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,54,-32748,16,0,0,0,0xe01b3a0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,72,-32748,16,0,0,0,0xe01b9a0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe01c0c0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe01cde0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe020cb0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,84,-32748,16,0,0,0,0xe026350, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,24,-32748,16,0,0,1,0xe0273d0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe028810, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe028db0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe0294d0, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,48,-32748,16,0,0,0,0xe029a70, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,66,-32748,16,0,0,0,0xe02a190, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,24,-32748,16,0,0,1,0xe02b3f0, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_rr_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(240,16,1,16,0),
WARP_NODE(241,6,4,79,0),
RETURN()
};
