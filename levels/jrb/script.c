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
#include "levels/jrb/header.h"
extern u8 _jrb_segment_ESegmentRomStart[]; 
extern u8 _jrb_segment_ESegmentRomEnd[];
#include "levels/lll/header.h"
const LevelScript level_jrb_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _lllSegmentRomStart, _lllSegmentRomEnd),
LOAD_RAW(0x0E, _jrb_segment_ESegmentRomStart, _jrb_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom22824736_skybox_mio0SegmentRomStart,_SkyboxCustom22824736_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group2_mio0SegmentRomStart,_group2_mio0SegmentRomEnd),
LOAD_RAW(12,_group2_geoSegmentRomStart,_group2_geoSegmentRomEnd),
LOAD_MIO0(6,_group14_mio0SegmentRomStart,_group14_mio0SegmentRomEnd),
LOAD_RAW(13,_group14_geoSegmentRomStart,_group14_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,                  lll_geo_0009E0),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04,                  lll_geo_0009F8),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05,                  lll_geo_000A10),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06,                  lll_geo_000A28),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07,                  lll_geo_000A40),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08,                  lll_geo_000A60),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A,                  lll_geo_000A90),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0B,                  lll_geo_000AA8),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C,                  lll_geo_000AC0),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0D,                  lll_geo_000AD8),
    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E,                  lll_geo_000AF0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_DRAWBRIDGE_PART,                lll_geo_000B20),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_ROTATING_BLOCK_FIRE_BARS,       lll_geo_000B38),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_ROTATING_HEXAGONAL_RING,        lll_geo_000BB0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_RECTANGULAR_PLATFORM,   lll_geo_000BC8),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_SQUARE_PLATFORMS,       lll_geo_000BE0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_TILTING_SQUARE_PLATFORM,        lll_geo_000BF8),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_1,                 lll_geo_000C10),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_2,                 lll_geo_000C30),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_3,                 lll_geo_000C50),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_4,                 lll_geo_000C70),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_5,                 lll_geo_000C90),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_6,                 lll_geo_000CB0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_7,                 lll_geo_000CD0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_8,                 lll_geo_000CF0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_9,                 lll_geo_000D10),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_10,                lll_geo_000D30),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_11,                lll_geo_000D50),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_12,                lll_geo_000D70),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_13,                lll_geo_000D90),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_BOWSER_PIECE_14,                lll_geo_000DB0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_MOVING_OCTAGONAL_MESH_PLATFORM, lll_geo_000B08),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_SINKING_ROCK_BLOCK,             lll_geo_000DD0),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_ROLLING_LOG,                    lll_geo_000DE8),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_ROTATING_HEXAGONAL_PLATFORM,    lll_geo_000A78),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_WOOD_BRIDGE,                    lll_geo_000B50),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_LARGE_WOOD_BRIDGE,              lll_geo_000B68),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_FALLING_PLATFORM,               lll_geo_000B80),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_LARGE_FALLING_PLATFORM,         lll_geo_000B98),
    LOAD_MODEL_FROM_GEO(MODEL_LLL_VOLCANO_FALLING_TRAP,           lll_geo_000EA8),
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
JUMP_LINK(script_func_global_3),
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_jrb_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_jrb_1_[] = {
AREA(1,Geo_jrb_1_0x15ea640),
TERRAIN(col_jrb_1_0xe0b2d20),
SET_BACKGROUND_MUSIC(0,36),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_jrb_1_),
JUMP_LINK(local_warps_jrb_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_jrb_1_[] = {
OBJECT_WITH_ACTS(0,-3623,1128,9510,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(241,16724,111,1443,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(7,16726,22,1442,0,0,0,0xe0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(242,1819,0,-4963,0,0,0,0x10000, bhvSwitchblock_Switch_MOP,31),
OBJECT_WITH_ACTS(120,1811,91,-3168,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(207,11634,-1290,-946,0,90,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(129,10763,-1491,-1485,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10537,-1491,-3514,0,21,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9400,-1491,-5168,0,1,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9396,-1491,-5366,0,1,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9293,-1313,-5563,0,1,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10329,-1491,-7201,0,300,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10498,-1491,-7298,0,300,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9731,-1491,-6787,0,320,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9197,-1491,-5362,0,1,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9200,-1491,-5163,0,1,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(124,11425,625,-8137,0,318,0,0x8d0000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(122,11097,-894,-7777,0,0,0,0x3000000, bhvStar,31),
OBJECT_WITH_ACTS(0,19427,6137,-3249,0,0,0,0x5000000, bhvFlipswitch_Panel_StarSpawn_MOP,31),
OBJECT_WITH_ACTS(42,13719,3165,-6427,0,344,0,0x0, bhvFlipswitch_Panel_MOP,31),
OBJECT_WITH_ACTS(0,15190,4038,9531,0,0,0,0xf010000, bhvWarp,31),
OBJECT_WITH_ACTS(124,14665,3900,8481,0,90,0,0x10000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(137,12518,-966,-1284,0,31,0,0x10000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(137,13895,986,2699,0,0,0,0x20000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(201,1621,3900,7006,0,90,0,0x690000, bhvCannonClosed,31),
OBJECT_WITH_ACTS(116,-11292,1442,1741,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-13863,122,-1380,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-15562,2854,10313,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-11029,1242,-3505,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-7737,2017,1013,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(0,-11292,1442,1741,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-13861,122,-1383,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-15560,2854,10310,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-11031,1242,-3514,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-7735,2017,1010,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-8507,3265,870,0,0,0,0x0, bhvHiddenStar,31),
OBJECT_WITH_ACTS(195,-7030,0,5670,0,0,0,0x20000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(201,14482,3150,-6267,0,270,0,0x0, bhvCannonClosed,31),
OBJECT_WITH_ACTS(241,-4276,691,-8445,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3969,691,-8443,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(137,-9241,1144,8938,0,0,0,0x130000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(241,-4276,386,-8445,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3971,386,-8444,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3969,78,-8445,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-4261,78,-8447,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(137,-5112,240,1854,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,8393,-806,1166,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(116,13194,-874,1868,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(0,11683,-879,2207,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(137,4817,3421,-210,0,23,0,0x130000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(116,7332,-840,256,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,6503,-868,-605,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(8,-4885,6436,9733,0,333,0,0xd0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(207,10053,5040,10640,0,0,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(55,1719,2362,-10111,0,106,0,0x0, bhvLllSinkingRockBlock,31),
OBJECT_WITH_ACTS(120,3854,4265,-8341,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(0,10041,5681,2886,0,0,0,0x1000000, bhvHiddenRedCoinStar,31),
OBJECT_WITH_ACTS(124,7658,1950,5607,0,270,0,0x30000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(129,10053,4822,8403,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10053,4822,7301,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,8934,4941,6999,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,7840,4941,6999,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,7640,4941,7000,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(8,7188,5958,7012,0,0,0,0xb0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,10782,5190,10582,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(223,16552,3150,7098,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(137,13436,3629,-5868,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,-5092,0,4883,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(192,-1900,600,7250,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(55,2992,2370,-9974,0,353,0,0x0, bhvLllSinkingRockBlock,31),
OBJECT_WITH_ACTS(55,4537,2370,-10169,0,3,0,0x0, bhvLllSinkingRockBlock,31),
OBJECT_WITH_ACTS(55,5517,2370,-9166,0,50,0,0x0, bhvLllSinkingRockBlock,31),
OBJECT_WITH_ACTS(55,11497,477,7112,0,80,0,0x0, bhvLllSinkingRockBlock,31),
OBJECT_WITH_ACTS(180,-1281,2643,-10260,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(207,-16279,1500,-1873,0,180,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(129,-14272,97,-101,0,0,0,0x0, bhvHiddenObject,31),
// OBJECT_WITH_ACTS(84,-350,-900,-6907,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,-898,-874,-5057,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,16097,-874,-1510,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,10505,509,7599,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,10579,509,6259,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,-2731,-905,-6788,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,5865,2571,-6943,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,2725,2442,-8764,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,14538,-907,3074,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
// OBJECT_WITH_ACTS(84,1750,2376,-11110,0,0,0,0x0, bhvBeta_Blarrg_MOP,31),
OBJECT_WITH_ACTS(180,-4023,842,-9434,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(241,9781,3842,-1102,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,9522,4144,-592,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,9400,4435,-71,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,9265,4705,470,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,9268,4910,1033,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,9251,5039,1583,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,9308,5147,2151,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(137,10048,5482,-6160,0,0,0,0x120000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(120,7402,2561,-12194,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(215,1818,66,-4056,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(152,5156,690,10824,0,0,0,0x0, bhvShrink_Platform_MOP,31),
OBJECT_WITH_ACTS(123,2688,2847,8578,0,180,0,0x460000, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(120,1381,312,10710,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(146,6357,1140,9478,0,270,0,0x32520000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(124,10238,3660,-1809,0,180,0,0xf0000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(192,298,3030,4536,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,6346,1982,5529,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(223,7954,4770,9546,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,-6840,0,6202,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-9057,150,9828,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(192,3897,3540,-7784,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(180,-16709,1851,3845,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-8257,1736,-2911,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,6841,2664,-10391,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,11875,910,5274,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(152,18599,3900,-2273,0,0,0,0x0, bhvShrink_Platform_MOP,31),
OBJECT_WITH_ACTS(129,-14051,464,582,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(180,2176,400,11699,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(223,10106,3673,-3442,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(152,2688,1913,9401,0,0,0,0x0, bhvShrink_Platform_MOP,31),
OBJECT_WITH_ACTS(192,-7965,2440,-1168,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(120,-12823,59,-1391,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(0,1500,1007,5798,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(124,9579,5040,-6676,0,0,0,0x100000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,15036,4429,9065,0,180,0,0x20000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,9894,5108,-6859,0,0,0,0xf030000, bhvWarp,31),
OBJECT_WITH_ACTS(0,10042,5666,-6461,0,0,0,0x40000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,-3460,681,9875,0,0,0,0xf050000, bhvWarp,31),
OBJECT_WITH_ACTS(124,-3225,600,9645,0,180,0,0x240000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(195,1588,0,-2959,0,0,0,0x620000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(241,-4274,993,-8445,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3972,993,-8444,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3972,1291,-8448,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-4274,1291,-8447,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(0,9880,5400,-6867,0,0,0,0xf030000, bhvWarp,31),
OBJECT_WITH_ACTS(0,10187,5400,-6862,0,0,0,0xf030000, bhvWarp,31),
OBJECT_WITH_ACTS(0,10187,5106,-6862,0,0,0,0xf030000, bhvWarp,31),
OBJECT_WITH_ACTS(0,15188,4332,9533,0,0,0,0xf010000, bhvWarp,31),
OBJECT_WITH_ACTS(0,14889,4332,9535,0,0,0,0xf010000, bhvWarp,31),
OBJECT_WITH_ACTS(0,14889,4038,9535,0,0,0,0xf010000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-3451,972,9868,0,0,0,0xf050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-3760,972,9874,0,0,0,0xf050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-3760,678,9874,0,0,0,0xf050000, bhvWarp,31),
OBJECT_WITH_ACTS(129,7440,4741,7000,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,7240,4741,7000,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,7040,4741,7000,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(0,3854,3605,-8345,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,9216,902,6870,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(129,10960,-1497,-1489,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10762,-1497,-1294,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10960,-1497,-1294,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10515,-1497,-3300,0,21,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,10699,-1497,-3370,0,21,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(0,2490,1686,4516,0,306,0,0x70000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(212,10037,7102,2875,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(215,0,-4156,0,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,0,-4156,0,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(116,7332,-749,257,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(46,15038,3978,9067,0,0,0,0x10000, bhvCheckpoint_Flag_MOP,31),
OBJECT_WITH_ACTS(129,10053,4822,7102,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,9604,-1491,-6634,0,320,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(120,14798,3662,-6093,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(124,6616,1102,9311,0,0,0,0x520000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,46, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-5,4,15,0,0,20,47, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,48, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-5,4,15,0,0,20,49, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,80,5,15,0,0,20,50, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_jrb_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(0,4,1,0,0),
WARP_NODE(1,4,1,11,0),
WARP_NODE(2,9,1,0,0),
WARP_NODE(3,23,1,3,0),
WARP_NODE(4,9,1,0,0),
WARP_NODE(5,9,1,3,0),
WARP_NODE(240,26,1,7,0),
WARP_NODE(241,26,1,8,0),
RETURN()
};
