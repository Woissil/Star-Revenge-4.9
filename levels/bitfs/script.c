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
#include "levels/bitfs/header.h"
extern u8 _bitfs_segment_ESegmentRomStart[]; 
extern u8 _bitfs_segment_ESegmentRomEnd[];
#include "levels/bbh/header.h"
const LevelScript level_bitfs_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
LOAD_RAW(0x0E, _bitfs_segment_ESegmentRomStart, _bitfs_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_water_skybox_mio0SegmentRomStart,_water_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group3_mio0SegmentRomStart,_group3_mio0SegmentRomEnd),
LOAD_RAW(12,_group3_geoSegmentRomStart,_group3_geoSegmentRomEnd),
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
JUMP_LINK(script_func_global_4),
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_bitfs_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bitfs_1_[] = {
AREA(1,Geo_bitfs_1_0x2cd20c0),
TERRAIN(col_bitfs_1_0xe061aa0),
SET_BACKGROUND_MUSIC(0,68),
TERRAIN_TYPE(2),
JUMP_LINK(local_objects_bitfs_1_),
JUMP_LINK(local_warps_bitfs_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bitfs_1_[] = {
OBJECT_WITH_ACTS(0,1634,-1519,6148,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(207,5788,787,9983,0,0,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(129,4395,-899,7140,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(122,2633,478,5238,0,0,0,0x0, bhvStar,31),
OBJECT_WITH_ACTS(122,-4309,4847,-3674,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(242,2484,973,-10502,0,0,0,0x10000, bhvSwitchblock_Switch_MOP,31),
OBJECT_WITH_ACTS(242,3082,5177,-10575,0,0,0,0x0, bhvSwitchblock_Switch_MOP,31),
OBJECT_WITH_ACTS(241,-114,987,-10291,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-1070,1884,-8019,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-586,2031,-7364,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,2620,4404,-10568,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,240,3960,-7769,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3371,4230,-9972,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3370,4535,-10275,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3357,4534,-9977,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3355,4533,-9681,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3365,4230,-9679,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3370,4230,-10275,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3370,3926,-10275,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3370,3926,-9974,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(241,-3363,3926,-9677,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(137,-4306,1060,-10572,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(241,-2032,1136,-10307,0,0,0,0x20000, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(180,-6878,3675,-6219,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(192,-6609,4927,-2533,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,2663,3577,2366,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,2790,6192,2928,0,0,0,0x40000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(124,2718,3118,-2548,0,126,0,0x6e0000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(137,2709,3610,-3601,0,0,0,0x40000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,-5087,4212,-9974,0,0,0,0x10000, bhvFadingWarp,31),
OBJECT_WITH_ACTS(180,1819,1804,-5891,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,842,4852,-5023,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(180,187,4838,-7719,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(192,2557,3776,-8597,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(137,4436,704,7162,0,0,0,0x130000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(212,4357,-1916,9082,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,4837,-1705,3859,0,90,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(188,6175,-544,3077,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(215,-4559,3997,-821,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3130,2261,-4578,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-7007,2306,-5578,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-5507,826,-10795,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-348,3020,-2261,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-3806,4932,-5324,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,-1631,1958,-8540,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(215,1433,4203,-7200,0,0,0,0x0, bhvRedCoin,31),
OBJECT_WITH_ACTS(0,2527,5839,-9435,0,0,0,0x2000000, bhvBowserCourseRedCoinStar,31),
OBJECT_WITH_ACTS(241,-826,4508,-8016,0,0,0,0x0, bhvSwitchblock_MOP,31),
OBJECT_WITH_ACTS(46,-811,3367,-1845,0,-90,0,0x0, bhvCheckpoint_Flag_MOP,31),
OBJECT_WITH_ACTS(0,-4382,4530,-9979,0,-90,0,0xf0000, bhvAirborneDeathWarp,31),
OBJECT_WITH_ACTS(0,-4382,4530,-9979,0,-90,0,0x100000, bhvAirborneStarCollectWarp,31),
OBJECT_WITH_ACTS(129,2538,-1198,6767,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2538,-998,6567,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2538,-798,6367,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2538,-598,6167,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2538,-398,5967,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2738,-1198,6767,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2738,-998,6567,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2738,-798,6367,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2738,-598,6167,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,2738,-398,5967,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(120,-3064,2803,-3228,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(0,2634,1266,-10719,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(194,6502,-98,2943,0,0,0,0x0, bhvHomingAmp,31),
OBJECT_WITH_ACTS(212,2195,5160,2528,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,3230,3517,-1813,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-3265,4440,-5860,0,90,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10,4,5,0,0,20,165, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-3,4,63,0,0,20,166, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_bitfs_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(0,19,1,0,0),
WARP_NODE(1,33,1,10,0),
WARP_NODE(15,19,1,0,0),
WARP_NODE(16,19,1,0,0),
WARP_NODE(240,7,1,16,0),
WARP_NODE(241,7,1,15,0),
RETURN()
};
