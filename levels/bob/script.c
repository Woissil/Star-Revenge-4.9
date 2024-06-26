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
#include "levels/bob/header.h"
extern u8 _bob_segment_ESegmentRomStart[]; 
extern u8 _bob_segment_ESegmentRomEnd[];
#include "levels/bbh/header.h"
const LevelScript level_bob_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
LOAD_RAW(0x0E, _bob_segment_ESegmentRomStart, _bob_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom20454912_skybox_mio0SegmentRomStart,_SkyboxCustom20454912_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group1_mio0SegmentRomStart,_group1_mio0SegmentRomEnd),
LOAD_RAW(12,_group1_geoSegmentRomStart,_group1_geoSegmentRomEnd),
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
LOAD_MODEL_FROM_GEO(7, box7star),  ////   0xe0000
LOAD_MODEL_FROM_GEO(8, boxstar),   ////
LOAD_MODEL_FROM_GEO(9, metalbox),
LOAD_MODEL_FROM_GEO(10, vanishbox),
LOAD_MODEL_FROM_GEO(11, wingbox),
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
JUMP_LINK(script_func_global_15),
JUMP_LINK(local_area_bob_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bob_1_[] = {
AREA(1,Geo_bob_1_0x13a7d20),
TERRAIN(col_bob_1_0xe0efb50),
SET_BACKGROUND_MUSIC(0,46),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bob_1_),
JUMP_LINK(local_warps_bob_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bob_1_[] = {
OBJECT_WITH_ACTS(0,1124,540,181,0,180,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,1139,223,-2418,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(122,3224,3782,-682,0,0,0,0x3000000, bhvStar,31),
OBJECT_WITH_ACTS(122,-9191,2112,-2647,0,0,0,0x4000000, bhvStar,31),
OBJECT_WITH_ACTS(0,9769,4578,-9003,0,0,0,0x5000000, bhvHiddenStar,31),
OBJECT_WITH_ACTS(7,1938,12,3703,0,0,0,0xe0000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(122,1126,5364,-3488,0,0,0,0x2000000, bhvStar,31),
OBJECT_WITH_ACTS(122,7052,4121,-15705,0,0,0,0x1000000, bhvStar,31),
OBJECT_WITH_ACTS(122,-7702,2999,759,0,0,0,0x0, bhvStar,31),
OBJECT_WITH_ACTS(0,-1726,0,131,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,2180,90,2035,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,7691,1050,-1094,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,2511,570,-16178,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-8003,2250,-16533,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-8248,2550,-14997,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1094,883,-3580,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,431,883,1973,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1809,211,-8068,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,1407,211,-13368,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-3621,997,-14114,0,0,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-9738,2845,-9576,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-9767,2845,-5055,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-10131,2845,-11575,0,129,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(223,-6670,3383,-9974,0,129,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,-7713,3383,-7112,0,129,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,5949,2188,-13893,0,129,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(223,1018,2337,-4108,0,129,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,1109,4124,-3503,0,129,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(188,6142,1295,456,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(188,8875,2303,-3249,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(188,6905,3009,-4869,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(188,5473,3512,-3746,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(194,6523,3867,-1923,0,0,0,0x0, bhvCirclingAmp,31),
OBJECT_WITH_ACTS(88,3691,3600,-679,0,90,0,0x0, bhvThwomp,31),
OBJECT_WITH_ACTS(194,5832,4092,-987,0,0,0,0x0, bhvHomingAmp,31),
OBJECT_WITH_ACTS(137,2800,1227,3626,0,0,0,0x60000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(212,-8544,4662,-7192,0,0,0,0x6080000, bhv1Up,23),
OBJECT_WITH_ACTS(195,-4394,972,-8194,0,0,0,0x50000, bhvBobombBuddy,23),
OBJECT_WITH_ACTS(188,-1327,767,2256,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(188,-4101,1627,-831,0,0,0,0x0, bhvBobomb,31),
OBJECT_WITH_ACTS(0,-5629,1963,-56,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(124,-9464,2744,-913,0,90,0,0x640000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,232,1809,-14964,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,4389,1809,-14594,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-9112,3184,-2721,0,302,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(188,-8835,2083,-2860,0,0,0,0x20000, bhvBobomb,31),
OBJECT_WITH_ACTS(188,-5306,2909,-5759,0,0,0,0x20000, bhvBobomb,31),
OBJECT_WITH_ACTS(0,-3740,3145,-19793,0,0,0,0x20000, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,-5343,1770,-14964,0,0,0,0x20000, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(180,1012,1886,-16979,0,0,0,0x20000, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,2464,1886,-14597,0,0,0,0x20000, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,8655,362,-6218,0,0,0,0x20000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(137,8649,277,-6232,0,0,0,0x10000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(0,-4544,3072,-20526,0,0,0,0xf060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-4675,3579,-20054,0,0,0,0x10000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,7140,580,-15886,0,0,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(0,6740,1023,-15754,0,270,0,0x20000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,-11065,2944,-4943,0,310,0,0xf050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-10536,3458,-5399,0,130,0,0x30000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(124,-10503,2850,-5047,0,130,0,0x220000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(124,-5152,3000,-20250,0,0,0,0x310000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(124,6901,450,-16164,0,270,0,0x320000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,-4623,-1378,-8330,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(212,-8196,3534,-14618,0,219,0,0xa0000, bhv1Up,31),
OBJECT_WITH_ACTS(123,-8937,2580,-15237,0,219,0,0xa0000, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(123,-8622,2580,-15420,0,219,0,0xa0000, bhvNoteblock_MOP,31),
OBJECT_WITH_ACTS(212,-773,-626,-6722,0,236,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(0,2006,1240,-18797,0,236,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(195,1471,0,-1473,0,0,0,0x650000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(0,-11083,3192,-4984,0,0,0,0xf050000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-4840,3132,-20479,0,0,0,0xf060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-4840,3348,-20479,0,0,0,0xf060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,-4547,3348,-20468,0,0,0,0xf060000, bhvWarp,31),
OBJECT_WITH_ACTS(0,7166,870,-15887,0,0,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(0,7155,870,-15594,0,0,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(0,7155,576,-15594,0,0,0,0xf040000, bhvWarp,31),
OBJECT_WITH_ACTS(129,6347,3437,-1679,0,324,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,5268,3447,-750,0,293,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,4723,3634,-566,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(207,6372,3450,-3786,0,180,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(129,5451,3447,-827,0,293,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,6465,3378,-2852,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(0,-9013,4894,-6371,0,0,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(180,5239,648,-15739,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-2357,1470,-518,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,-1566,1170,125,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(195,2173,0,3799,0,0,0,0x9a0000, bhvBobombBuddy,31),
OBJECT_WITH_ACTS(0,-5,4,15,0,0,20,27, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-5,5,15,0,0,20,28, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-7,4,15,0,0,20,29, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_bob_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(0,9,1,0,0),
WARP_NODE(1,9,1,0,0),
WARP_NODE(2,9,1,0,0),
WARP_NODE(3,9,1,0,0),
WARP_NODE(4,24,1,10,0),
WARP_NODE(5,12,1,10,0),
WARP_NODE(6,4,1,10,0),
WARP_NODE(15,24,1,10,0),
WARP_NODE(16,12,1,10,0),
WARP_NODE(240,26,1,3,0),
WARP_NODE(241,26,1,4,0),
RETURN()
};
