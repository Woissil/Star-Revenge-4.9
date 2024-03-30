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

#include "areas/3/custom.model.inc.h"

#include "areas/4/custom.model.inc.h"

#include "areas/7/custom.model.inc.h"

#include "levels/ending/header.h"
#include "levels/bbh/header.h"

extern u8 _ending_segment_ESegmentRomStart[];
extern u8 _ending_segment_ESegmentRomEnd[];

const LevelScript level_ending_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _ending_segment_ESegmentRomStart, _ending_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group3_mio0SegmentRomStart, _group3_mio0SegmentRomEnd),
	LOAD_RAW(12, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd),
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
	JUMP_LINK(script_func_global_4),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_ending_3_),
	JUMP_LINK(local_area_ending_4_),
	JUMP_LINK(local_area_ending_7_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_ending_3_[] = {
	AREA(3, Geo_ending_3_0x252ef40),
	TERRAIN(col_ending_3_0xe022bc0),
	SET_BACKGROUND_MUSIC(0, 75),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ending_3_),
	JUMP_LINK(local_warps_ending_3_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ending_3_[] = {
	OBJECT_WITH_ACTS(0, 6, 447, 3284, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(103, 0, 0, 0, 0, 0, 0, 0x1000000,  bhvWhompKingBoss, 31),
	OBJECT_WITH_ACTS(207, 0, 75, 4027, 0, 180, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(129, -100, -319, 325, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 100, -319, 325, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(124, 374, 75, 4103, 0, 180, 0, 0x930000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(207, -4034, 75, 7, 0, 90, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(207, -1, 75, -4028, 0, 0, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(207, 4032, 75, 3, 0, -90, 0, 0x0,  bhvFloorSwitchHiddenObjects, 31),
	OBJECT_WITH_ACTS(129, -325, -319, 100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -325, -319, -100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -525, -319, -100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -525, -319, 100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 325, -319, 100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 325, -319, -100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(137, -376, 361, -4037, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, -4040, 361, 370, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(137, 4036, 391, -366, 0, 0, 0, 0x60000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(129, 525, -319, -100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 525, -319, 100, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 100, -319, 525, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -100, -319, 525, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 100, -319, -525, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -100, -319, -525, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, 100, -319, -325, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(129, -100, -319, -325, 0, 0, 0, 0x0,  bhvHiddenObject, 31),
	OBJECT_WITH_ACTS(0, -12, 4, 15, 0, 0, 20, 202,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -12, 4, 15, 0, 0, 20, 203,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 204,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 205,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 206,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 207,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 208,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_ending_3_[] = {
	WARP_NODE(10, 9, 3, 0, 0),
	WARP_NODE(240, 6, 2, 5, 0),
	WARP_NODE(241, 27, 6, 6, 0),
	RETURN()
};

const LevelScript local_area_ending_4_[] = {
	AREA(4, Geo_ending_4_0x252ee30),
	TERRAIN(col_ending_4_0xe027990),
	SET_BACKGROUND_MUSIC(0, 75),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ending_4_),
	JUMP_LINK(local_warps_ending_4_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ending_4_[] = {
	OBJECT_WITH_ACTS(0, 0, 564, 1068, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(86, -30, 300, -103, 0, 0, 0, 0x0,  bhvKingBobomb, 31),
	OBJECT_WITH_ACTS(0, 4, 5, 253, 0, 0, 20, 209,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -12, 4, 78, 0, 0, 20, 210,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_ending_4_[] = {
	WARP_NODE(10, 9, 4, 0, 0),
	WARP_NODE(240, 27, 6, 5, 0),
	WARP_NODE(241, 25, 7, 6, 0),
	RETURN()
};

const LevelScript local_area_ending_7_[] = {
	AREA(7, Geo_ending_7_0x252ed20),
	TERRAIN(col_ending_7_0xe006890),
	SET_BACKGROUND_MUSIC(0, 72),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_ending_7_),
	JUMP_LINK(local_warps_ending_7_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_ending_7_[] = {
	OBJECT_WITH_ACTS(0, 293, 0, 1766, 0, 206, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, -819, -1454, -490, 0, 238, 0, 0x46020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, -1601, 0, -78, 0, 168, 0, 0x60000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 1333, 0, 1415, 0, 238, 0, 0x50000,  bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(22, 1686, -850, 268, 0, 0, 0, 0xc0000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(124, 1436, -850, 505, 0, 272, 0, 0x710000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -7, 5, 52, 0, 0, 20, 211,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_ending_7_[] = {
	WARP_NODE(10, 9, 7, 0, 0),
	WARP_NODE(2, 25, 4, 10, 0),
	WARP_NODE(6, 25, 7, 1, 0),
	WARP_NODE(5, 25, 7, 5, 0),
	WARP_NODE(12, 16, 1, 12, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	RETURN()
};