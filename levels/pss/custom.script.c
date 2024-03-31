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

#include "areas/3/custom.model.inc.h"

#include "areas/5/custom.model.inc.h"

#include "areas/6/custom.model.inc.h"

#include "levels/pss/header.h"
#include "levels/bbh/header.h"

extern u8 _pss_segment_ESegmentRomStart[];
extern u8 _pss_segment_ESegmentRomEnd[];

const LevelScript level_pss_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _bbh_segment_7SegmentRomStart, _bbh_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _bbhSegmentRomStart, _bbhSegmentRomEnd),
	LOAD_RAW(0x0E, _pss_segment_ESegmentRomStart, _pss_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group11_mio0SegmentRomStart, _group11_mio0SegmentRomEnd),
	LOAD_RAW(12, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd),
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
	// LOAD_MODEL_FROM_GEO(88, 0x0500c778),
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
	JUMP_LINK(script_func_global_12),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_pss_1_),
	JUMP_LINK(local_area_pss_2_),
	JUMP_LINK(local_area_pss_3_),
	JUMP_LINK(local_area_pss_5_),
	JUMP_LINK(local_area_pss_6_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_pss_1_[] = {
	AREA(1, Geo_pss_1_0x23a7540),
	TERRAIN(col_pss_1_0xe00cf40),
	SET_BACKGROUND_MUSIC(0, 72),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_pss_1_),
	JUMP_LINK(local_warps_pss_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_pss_1_[] = {
	OBJECT_WITH_ACTS(0, 29, 0, 201, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	// OBJECT_WITH_ACTS(0, -851, -672, -6033, 0, 0, 0, 0x29101,  Bhv_Custom_0x13005748, 31),
	// OBJECT_WITH_ACTS(0, -639, -672, -6222, 0, 0, 0, 0x29101,  Bhv_Custom_0x13005748, 31),
	OBJECT_WITH_ACTS(22, 1703, 129, -5262, 0, 0, 0, 0x30000,  bhvWarpPipe, 31),
	// OBJECT_WITH_ACTS(0, -667, -672, -5935, 0, 0, 0, 0x29101,  Bhv_Custom_0x13005748, 31),
	// OBJECT_WITH_ACTS(0, -925, -672, -5830, 0, 0, 0, 0x29101,  Bhv_Custom_0x13005748, 31),
	// OBJECT_WITH_ACTS(0, -1062, -672, -6021, 0, 0, 0, 0x29101,  Bhv_Custom_0x13005748, 31),
	// OBJECT_WITH_ACTS(0, -943, -672, -6281, 0, 0, 0, 0x29101,  Bhv_Custom_0x13005748, 31),
	OBJECT_WITH_ACTS(124, 17, 0, -1354, 0, 0, 0, 0x440000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(124, 325, 0, -4902, 0, 0, 0, 0x480000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, 7, 600, -4193, 0, 180, 0, 0x40000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, 11, 594, -4193, 0, 180, 0, 0x50000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(212, -17, 1681, -1554, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 4, 5, 15, 0, 0, 20, 312,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_pss_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(0, 27, 1, 0, 0),
	WARP_NODE(1, 27, 5, 10, 0),
	WARP_NODE(2, 16, 1, 12, 0),
	WARP_NODE(3, 16, 1, 12, 0),
	WARP_NODE(4, 27, 1, 0, 0),
	WARP_NODE(5, 27, 1, 0, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 16, 1, 13, 0),
	RETURN()
};

const LevelScript local_area_pss_2_[] = {
	AREA(2, Geo_pss_2_0x23a7430),
	TERRAIN(col_pss_2_0xe007150),
	SET_BACKGROUND_MUSIC(0, 72),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_pss_2_),
	JUMP_LINK(local_warps_pss_2_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_pss_2_[] = {
	OBJECT_WITH_ACTS(0, -460, -318, -243, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(22, 1213, -812, -1706, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(124, 997, -812, -1466, 0, 270, 0, 0x710000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -1320, -1543, -2462, 0, 0, 0, 0x46020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, -450, -371, -1264, 0, 180, 0, 0x30000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 7, 5, 15, 0, 0, 20, 313,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_pss_2_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(0, 27, 2, 0, 0),
	WARP_NODE(1, 27, 1, 4, 0),
	WARP_NODE(2, 27, 3, 10, 0),
	WARP_NODE(3, 27, 2, 0, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 6, 1, 100, 0),
	RETURN()
};

const LevelScript local_area_pss_3_[] = {
	AREA(3, Geo_pss_3_0x23a7100),
	TERRAIN(col_pss_3_0xe028d80),
	SET_BACKGROUND_MUSIC(0, 75),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_pss_3_),
	JUMP_LINK(local_warps_pss_3_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_pss_3_[] = {
	OBJECT_WITH_ACTS(0, -1006, 483, -1048, 0, 42, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(87, 0, 1200, 0, 0, 0, 0, 0x0,  bhvWigglerHead, 31),
	OBJECT_WITH_ACTS(123, -6, 209, -1128, 0, 0, 0, 0x730000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(123, 1124, 209, 3, 0, 0, 0, 0x730000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(123, 1, 209, 1133, 0, 0, 0, 0x730000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(123, -1114, 209, 0, 0, 0, 0, 0x730000,  bhvNoteblock_MOP, 31),
	OBJECT_WITH_ACTS(146, 14, 1185, 278, -90, 180, 0, 0xf0000,  bhvSpring_MOP, 31),
	OBJECT_WITH_ACTS(146, -289, 1185, -16, -90, 90, 0, 0xf0000,  bhvSpring_MOP, 31),
	OBJECT_WITH_ACTS(146, 16, 1185, -309, -90, 0, 0, 0xf0000,  bhvSpring_MOP, 31),
	OBJECT_WITH_ACTS(146, 316, 1185, -15, -90, 270, 0, 0xf0000,  bhvSpring_MOP, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 314,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -12, 4, 15, 0, 0, 20, 315,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 316,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 317,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 318,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 319,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 320,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 321,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 322,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 4, 4, 15, 0, 0, 20, 323,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -12, 15, 78, 0, 0, 20, 324,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_pss_3_[] = {
	WARP_NODE(10, 9, 2, 0, 0),
	WARP_NODE(240, 25, 7, 5, 0),
	WARP_NODE(241, 27, 2, 3, 0),
	RETURN()
};

const LevelScript local_area_pss_5_[] = {
	AREA(5, Geo_pss_5_0x23a7320),
	TERRAIN(col_pss_5_0xe006890),
	SET_BACKGROUND_MUSIC(0, 72),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_pss_5_),
	JUMP_LINK(local_warps_pss_5_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_pss_5_[] = {
	OBJECT_WITH_ACTS(0, -83, -403, 1792, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(124, 1401, -812, 470, 0, 270, 0, 0x710000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(22, 1689, -850, 252, 0, 0, 0, 0x10000,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -806, -1590, -500, 0, 0, 0, 0x46020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(0, -7, 5, 15, 0, 0, 20, 325,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_pss_5_[] = {
	WARP_NODE(10, 9, 5, 0, 0),
	WARP_NODE(0, 27, 5, 0, 0),
	WARP_NODE(1, 27, 1, 4, 0),
	WARP_NODE(5, 27, 5, 0, 0),
	WARP_NODE(6, 27, 5, 0, 0),
	WARP_NODE(2, 27, 3, 10, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 27, 1, 5, 0),
	RETURN()
};

const LevelScript local_area_pss_6_[] = {
	AREA(6, Geo_pss_6_0x23a7210),
	TERRAIN(col_pss_6_0xe008a60),
	SET_BACKGROUND_MUSIC(0, 72),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_pss_6_),
	JUMP_LINK(local_warps_pss_6_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_pss_6_[] = {
	OBJECT_WITH_ACTS(0, -471, -403, -233, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(124, -550, -941, -1286, 0, 21, 0, 0x450000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(0, -1336, -1602, -2474, 0, 0, 0, 0x46020000,  bhvWarp, 31),
	OBJECT_WITH_ACTS(124, 997, -812, -1466, 0, 270, 0, 0x710000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(22, 1212, -812, -1703, 0, 0, 0, 0x0,  bhvWarpPipe, 31),
	OBJECT_WITH_ACTS(0, -1534, -210, -1450, 0, 194, 0, 0x60000,  bhvAirborneDeathWarp, 31),
	OBJECT_WITH_ACTS(0, 1129, -210, -758, 0, 222, 0, 0x50000,  bhvAirborneStarCollectWarp, 31),
	OBJECT_WITH_ACTS(0, -7, 4, 15, 0, 0, 20, 326,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 7, 5, 15, 0, 0, 20, 327,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_pss_6_[] = {
	WARP_NODE(10, 9, 6, 0, 0),
	WARP_NODE(0, 27, 6, 0, 0),
	WARP_NODE(1, 27, 1, 4, 0),
	WARP_NODE(2, 25, 3, 10, 0),
	WARP_NODE(5, 27, 6, 5, 0),
	WARP_NODE(6, 27, 6, 6, 0),
	WARP_NODE(240, 6, 1, 50, 0),
	WARP_NODE(241, 27, 1, 5, 0),
	RETURN()
};