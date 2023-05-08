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
#include "levels/bits/header.h"
extern u8 _bits_segment_ESegmentRomStart[]; 
extern u8 _bits_segment_ESegmentRomEnd[];
#include "levels/bob/header.h"
const LevelScript level_bits_entry[] = {
INIT_LEVEL(),
LOAD_MIO0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd),
LOAD_RAW(0x1A, _bobSegmentRomStart, _bobSegmentRomEnd),
LOAD_RAW(0x0E, _bits_segment_ESegmentRomStart, _bits_segment_ESegmentRomEnd),
LOAD_MIO0(0xA,_water_skybox_mio0SegmentRomStart,_water_skybox_mio0SegmentRomEnd),
LOAD_MIO0(8,_common0_mio0SegmentRomStart,_common0_mio0SegmentRomEnd),
LOAD_RAW(15,_common0_geoSegmentRomStart,_common0_geoSegmentRomEnd),
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
JUMP_LINK(local_area_bits_2_),
FREE_LEVEL_POOL(),
MARIO_POS(1,0,0,0,0),
CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
CLEAR_LEVEL(),
SLEEP_BEFORE_EXIT(/*frames*/ 1),
EXIT(),
};
const LevelScript local_area_bits_2_[] = {
AREA(2,Geo_bits_2_0x2da25b0),
TERRAIN(col_bits_2_0xe0babc0),
SET_BACKGROUND_MUSIC(0,2),
TERRAIN_TYPE(0),
JUMP_LINK(local_objects_bits_2_),
JUMP_LINK(local_warps_bits_2_),
END_AREA(),
RETURN()
};
const LevelScript local_objects_bits_2_[] = {
OBJECT_WITH_ACTS(137,-12486,5349,6822,0,0,0,0x10000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(137,2882,8590,11062,0,344,0,0x50000, bhvExclamationBox,31),
OBJECT_WITH_ACTS(207,-12890,4470,16193,0,0,0,0x0, bhvFloorSwitchGrills,31),
OBJECT_WITH_ACTS(212,-7080,2112,3551,0,0,0,0x20000, bhv1Up,31),
OBJECT_WITH_ACTS(120,-6355,5516,207,0,0,0,0x0, bhvRecoveryHeart,31),
OBJECT_WITH_ACTS(38,-6363,5442,-660,0,0,0,0x20000, bhvDoorWarp,31),
OBJECT_WITH_ACTS(129,-10400,4865,11494,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10400,4865,10700,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10400,4865,9747,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10400,4865,8857,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10200,4865,7839,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10200,4865,8857,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10000,4865,7839,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(124,-11075,4950,3615,0,0,0,0x4b0000, bhvMessagePanel,31),
OBJECT_WITH_ACTS(0,-2717,3696,14935,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-2727,5330,13671,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-3879,4399,13632,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-4550,1917,14936,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(0,-3696,5065,14497,0,0,0,0x0, bhvHiddenStarTrigger,31),
OBJECT_WITH_ACTS(116,-2717,3696,14935,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-2727,5330,13671,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-3879,4399,13632,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-4550,1917,14936,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(116,-3696,5065,14497,0,0,0,0x0, bhvOneCoin,31),
OBJECT_WITH_ACTS(0,-3844,4698,14903,0,0,0,0x0, bhvHiddenStar,31),
OBJECT_WITH_ACTS(0,-4541,4923,15825,0,0,0,0x10000, bhvAirborneStarCollectWarp,31),
OBJECT_WITH_ACTS(0,-4541,4923,15825,0,0,0,0xa0000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(0,-2721,4800,14393,0,0,0,0x30000, bhvSpinAirborneWarp,31),
OBJECT_WITH_ACTS(207,-12955,5100,13191,0,0,0,0x0, bhvFloorSwitchHiddenObjects,31),
OBJECT_WITH_ACTS(0,-12958,5130,13460,0,180,0,0x0, bhvOpenableGrill,31),
OBJECT_WITH_ACTS(129,-10000,4865,6714,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10000,4865,6514,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10000,4865,5365,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10000,4865,5165,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(129,-10200,4865,5165,0,0,0,0x0, bhvHiddenObject,31),
OBJECT_WITH_ACTS(0,-6355,5712,58,0,0,0,0xf0000, bhvAirborneDeathWarp,31),
OBJECT_WITH_ACTS(0,-10,4,228,0,0,20,176, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,96,0,0,20,177, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,14,0,0,20,178, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,138,0,0,20,179, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,147,0,0,20,180, RM_Scroll_Texture,31),
OBJECT_WITH_ACTS(0,-10,4,43,0,0,20,181, RM_Scroll_Texture,31),
RETURN()
};
const LevelScript local_warps_bits_2_[] = {
WARP_NODE(10,9,2,0,0),
WARP_NODE(0,21,2,0,0),
WARP_NODE(1,21,2,0,0),
WARP_NODE(2,34,1,10,0),
WARP_NODE(3,21,2,0,0),
WARP_NODE(15,21,2,0,0),
WARP_NODE(240,21,2,1,0),
WARP_NODE(241,13,1,22,0),
RETURN()
};
