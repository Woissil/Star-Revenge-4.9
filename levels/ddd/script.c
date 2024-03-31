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
#include "levels/ddd/header.h"
extern u8 _ddd_segment_ESegmentRomStart[]; 
extern u8 _ddd_segment_ESegmentRomEnd[];
#include "levels/bob/header.h"
const LevelScript level_ddd_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bobSegmentRomStart, _bobSegmentRomEnd),
LOAD_RAW(0x0E, _ddd_segment_ESegmentRomStart, _ddd_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_bbh_skybox_mio0SegmentRomStart,_bbh_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
LOAD_MIO0(6,_group17_mio0SegmentRomStart,_group17_mio0SegmentRomEnd),
LOAD_RAW(13,_group17_geoSegmentRomStart,_group17_geoSegmentRomEnd),
ALLOC_LEVEL_POOL(),
MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE,      bubbly_tree_geo),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM,  bob_geo_000458),
    LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS,      bob_geo_000470),
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
JUMP_LINK(local_area_ddd_1_),
JUMP_LINK(local_area_ddd_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_ddd_1_[] = {
AREA(1,Geo_ddd_1_0x1b61a90),
TERRAIN(col_ddd_1_0xe088e20),
SET_BACKGROUND_MUSIC(0,42),
TERRAIN_TYPE(1),
JUMP_LINK(local_objects_ddd_1_),
JUMP_LINK(local_warps_ddd_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ddd_1_[] = {
OBJECT_WITH_ACTS(0,2469,708,4435,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,2656,138,4954,0,0,0,0x14060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-12689,2060,-5835,0,90,0,0x30000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,-13452,1584,-5647,0,0,0,0x14050000, bhvWarp,31),
OBJECT_WITH_ACTS(137,-12051,1869,-5421,0,0,0,0x20000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(201,-2946,1997,2464,0,0,0,0x0, bhvCannonClosed,31),
OBJECT_WITH_ACTS(137,-6941,-747,-2007,0,0,0,0x10000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(11,-995,1192,-10801,0,0,0,0x50000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(11,4004,2272,-5201,0,0,0,0x50000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,5134,901,-8197,0,0,0,0x10000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(215,-3394,-1474,-9397,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3033,-1115,-4195,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-4606,-1471,-4196,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-7798,-1471,-4999,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-6006,-1471,-8200,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-7807,-1536,-9001,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3011,-1536,-6001,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-7796,-1537,-10595,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,-5614,-1600,-10592,0,0,0,0x40000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-7603,-1501,-9698,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(153,3521,-120,-2189,0,0,0,0x0, bhvSandBlock_MOP,31),
OBJECT_WITH_ACTS(9,829,4677,-10278,0,0,0,0xf0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(207,534,800,-10605,0,0,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(129,3300,44,-8368,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,4012,277,-8140,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(180,1365,946,-8513,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(129,886,1363,-8477,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,505,1830,-9079,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,826,2248,-9467,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(8,153,3990,-1198,0,0,0,0xc0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(124,-13074,1482,-6299,0,90,0,0x220000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(37,-2748,1200,3419,0,116,0,0x2070000, bhvDoorWarp,31),
OBJECT_WITH_ACTS(37,-2814,1200,3283,0,296,0,0x2120000, bhvDoorWarp,31),
OBJECT_WITH_ACTS(37,-12650,1482,-5179,0,0,0,0x2080000, bhvDoorWarp,31),
OBJECT_WITH_ACTS(37,-12498,1482,-5179,0,180,0,0x2130000, bhvDoorWarp,31),
OBJECT_WITH_ACTS(124,1949,0,4639,0,180,0,0x4d0000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,277,-3440,-10642,0,0,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-1966,-3440,-9315,0,90,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,4299,-3121,-4523,0,270,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,581,-3440,-4798,0,180,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,430,-3440,-6700,0,90,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,1203,-3440,-8812,0,270,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-607,-3440,-10630,0,0,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,3213,-3121,-5527,0,0,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(124,4396,3200,-5516,0,90,0,0x330000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(8,-1027,8421,-8912,0,0,0,0x5080000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(146,-1230,7627,-1197,0,135,0,0x5faf0000, bhvSpring_MOP,31),
OBJECT_WITH_ACTS(0,2842,3576,-2025,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-5729,4244,-7465,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(129,1494,2599,-9291,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(0,-4199,6200,-1173,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,4894,1830,-5162,0,180,0,0x90000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(8,-703,4307,-8418,0,0,0,0x80000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(8,-1577,-1054,-3855,0,0,0,0xd0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(8,-8120,1821,-10600,0,0,0,0xa0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,-7396,-1135,-8982,0,0,0,0x2000000, bhvHiddenRedCoinStar,31),
OBJECT_WITH_ACTS(22,5380,-1360,-10972,0,0,0,0xb0000, bhvWarpPipe,31),
OBJECT_WITH_ACTS(22,2213,-223,-3216,0,0,0,0xc0000, bhvWarpPipe,31),
OBJECT_WITH_ACTS(124,5070,-1360,-10948,0,315,0,0x340000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(124,1289,4144,-9863,0,0,0,0x300000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(242,-4800,1416,-3196,0,0,0,0x10000, bhvSwitchblock_Switch_MOP,31),
OBJECT_WITH_ACTS(241,-5571,1311,-10609,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-6393,1311,-10611,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-7217,1311,-10612,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(0,-3605,-667,-10602,0,0,0,0xd0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(0,-4005,2160,-10601,0,0,180,0xe0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(47,-603,-1315,-2606,0,0,0,0x0, bhvFlipswap_Platform_MOP,31),
OBJECT_WITH_ACTS(0,1200,-932,-206,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(7,522,3575,-11815,0,0,0,0xe0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(89,-707,0,-5668,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,963,400,-5015,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(180,597,182,-200,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(89,2081,800,-8940,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,-2586,800,-8884,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(89,5983,0,-6179,0,0,0,0x0, bhvHeaveHo,31),
OBJECT_WITH_ACTS(206,683,3840,-3729,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(206,1784,1009,-10520,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(206,1734,-100,-7070,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(180,-6808,3676,-1486,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(206,-5061,3929,-1857,0,0,0,0x0, bhvSnufit,31),
OBJECT_WITH_ACTS(192,-1728,-1424,-358,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,-1895,217,-3464,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-30,800,-6988,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(101,544,-1406,-7145,0,0,0,0x0, bhvScuttlebug,31),
OBJECT_WITH_ACTS(192,3983,-1924,-7682,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(180,3729,-2455,-1715,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,3852,-3029,-5125,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,823,-3326,-7584,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-1568,-2931,-8293,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-1408,-2338,-7014,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-3393,-1428,-4991,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-1744,-2338,-7013,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,-5604,-3857,-6986,0,0,0,0xf0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(0,-7792,-1112,-10606,0,0,0,0x100000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(241,-8119,1820,-10599,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(0,-12294,3207,-5723,0,0,0,0x110000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(137,4888,1998,-5168,0,0,0,0x0, bhvExclamationBox,31),
OBJECT_WITH_ACTS(124,3904,3200,-5008,0,270,0,0x330000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,-13474,1926,-5668,0,0,0,0x14050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-13452,1926,-6007,0,0,0,0x14050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-13448,1596,-5995,0,0,0,0x14050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,2628,462,4954,0,0,0,0x14060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,2275,462,4916,0,0,0,0x14060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,2275,126,4916,0,0,0,0x14060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,4774,1346,-8195,0,90,0,0x140000, bhvAirborneStarCollectWarp,31),
OBJECT_WITH_ACTS(0,4774,1346,-8195,0,90,0,0x150000, bhvAirborneDeathWarp,31),
OBJECT_WITH_ACTS(217,-3035,1150,3135,0,296,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(217,-2906,1456,3411,0,296,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(217,-3035,1456,3135,0,296,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(217,-12267,1434,-5048,0,0,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(217,-12267,1738,-5048,0,0,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(217,-12574,1738,-5046,0,0,0,0x0, bhvPushableMetalBox,31),
OBJECT_WITH_ACTS(0,218,-858,-7676,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,189, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,190, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,191, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-2,4,15,0,0,20,192, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-4,4,15,0,0,20,193, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,15,0,0,20,194, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,15,0,0,20,195, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,4,5,15,0,0,20,196, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_ddd_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(0,26,2,10,0),
WARP_NODE(1,29,2,10,0),
WARP_NODE(2,9,1,0,0),
WARP_NODE(3,9,1,0,0),
WARP_NODE(4,26,2,10,0),
WARP_NODE(5,12,1,4,0),
WARP_NODE(6,8,1,2,0),
WARP_NODE(7,23,1,8,0),
WARP_NODE(8,23,1,7,0),
WARP_NODE(9,23,1,0,0),
WARP_NODE(11,23,1,12,0),
WARP_NODE(12,23,1,11,0),
WARP_NODE(13,23,1,14,0),
WARP_NODE(14,23,1,13,0),
WARP_NODE(15,23,1,16,0),
WARP_NODE(16,23,1,15,0),
WARP_NODE(17,23,2,11,0),
WARP_NODE(18,23,1,19,0),
WARP_NODE(19,23,1,18,0),
WARP_NODE(20,23,1,0,0),
WARP_NODE(21,23,1,0,0),
WARP_NODE(240,26,1,19,0),
WARP_NODE(241,26,1,20,0),
RETURN()
};
const LevelScript local_area_ddd_2_[] = {
AREA(2,Geo_ddd_2_0x1b61980),
TERRAIN(col_ddd_2_0xe0069c0),
SET_BACKGROUND_MUSIC(0,0),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_ddd_2_),
JUMP_LINK(local_warps_ddd_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_ddd_2_[] = {
OBJECT_WITH_ACTS(0,81,87,536,0,0,0,0xc0000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(124,81,0,-582,0,0,0,0x2e0000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,81,294,145,0,180,0,0xb0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,2,5,14,0,0,20,197, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_ddd_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(0,23,2,0,0),
WARP_NODE(11,23,1,0,0),
WARP_NODE(12,23,1,10,0),
WARP_NODE(240,6,1,50,0),
WARP_NODE(241,26,1,20,0),
RETURN()
};
