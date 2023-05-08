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
#include "levels/bowser_1/header.h"
extern u8 _bowser_1_segment_ESegmentRomStart[]; 
extern u8 _bowser_1_segment_ESegmentRomEnd[];
#include "levels/bbh/header.h"
const LevelScript level_bowser_1_custom_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
LOAD_RAW(0x0E, _bowser_1_segment_ESegmentRomStart, _bowser_1_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_SkyboxCustom49426848_skybox_mio0SegmentRomStart,_SkyboxCustom49426848_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
LOAD_MIO0(5,_group3_mio0SegmentRomStart,_group3_mio0SegmentRomEnd),
LOAD_RAW(12,_group3_geoSegmentRomStart,_group3_geoSegmentRomEnd),
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
JUMP_LINK(local_area_bowser_1_1_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bowser_1_1_[] = {
AREA(1,Geo_bowser_1_1_0x2f490c0),
TERRAIN(col_bowser_1_1_0xe064930),
SET_BACKGROUND_MUSIC(0,55),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bowser_1_1_),
JUMP_LINK(local_warps_bowser_1_1_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bowser_1_1_[] = {
OBJECT_WITH_ACTS(0,476,1890,1299,0,269,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(212,1500,5820,-8661,0,0,0,0x0, bhv1Up,31),
OBJECT_WITH_ACTS(180,-5824,2748,-10190,0,180,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,-6072,2376,-8939,0,180,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-6066,2969,-6695,0,180,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5419,2807,-6750,0,180,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-4288,2633,-4491,0,180,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(180,-4944,2633,-5664,0,180,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(0,-5099,2201,-4008,0,180,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-5524,2339,-1393,0,180,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-4193,2339,-1627,0,0,0,0x40000, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-3143,2567,-2183,0,0,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(180,-1791,2471,-1635,0,0,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(192,-315,1721,-1685,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(192,453,1650,-1313,0,0,0,0x0, bhvGoomba,31),
OBJECT_WITH_ACTS(0,444,1680,606,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(122,4818,3225,-2964,0,0,0,0x5000000, bhvStar,31),
OBJECT_WITH_ACTS(0,4151,2640,-2409,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,5445,2640,-3687,0,0,0,0x0, bhvGoombaTripletSpawner,31),
OBJECT_WITH_ACTS(0,4797,3704,-7135,0,0,0,0x0, bhvCoinFormation,31),
OBJECT_WITH_ACTS(180,4664,4200,-8782,0,90,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(180,3918,3960,-9570,0,90,0,0x0, bhvFireSpitter,31),
OBJECT_WITH_ACTS(223,2579,3750,-9650,0,90,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,1024,3845,-9736,0,90,0,0x100000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1066,3845,-9690,0,180,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(0,-1066,2933,-9690,0,180,0,0x110000, bhvCoinFormation,31),
OBJECT_WITH_ACTS(223,-2102,2897,-10140,0,180,0,0x0, bhvChuckya,31),
OBJECT_WITH_ACTS(0,-3332,3174,-9165,0,180,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-4526,3174,-9168,0,180,0,0x0, bhvFlamethrower,31),
OBJECT_WITH_ACTS(0,-3930,3324,-10305,0,0,0,0x0, bhvFlamethrower,31),
// OBJECT_WITH_ACTS(0,73,-24556,-22,0,0,0,0xe0146a0, RM_Scroll_Texture,31),
// OBJECT_WITH_ACTS(0,319,-24556,-22,0,0,0,0xe025b40, RM_Scroll_Texture,31),
// OBJECT_WITH_ACTS(0,1168,-32748,18,0,0,1,0xe032b50, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_bowser_1_1_[] = {
WARP_NODE(10,9,1,0,0),
WARP_NODE(240,4,1,3,0),
WARP_NODE(241,17,1,1,0),
RETURN()
};
