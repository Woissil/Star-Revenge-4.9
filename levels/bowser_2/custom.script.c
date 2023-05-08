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

#include "levels/bowser_2/header.h"
#include "levels/ssl/header.h"

extern u8 _bowser_2_segment_ESegmentRomStart[];
extern u8 _bowser_2_segment_ESegmentRomEnd[];

const LevelScript level_bowser_2_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _ssl_segment_7SegmentRomStart, _ssl_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _sslSegmentRomStart, _sslSegmentRomEnd),
	LOAD_RAW(0x0E, _bowser_2_segment_ESegmentRomStart, _bowser_2_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group5_mio0SegmentRomStart, _group5_mio0SegmentRomEnd),
	LOAD_RAW(12, _group5_geoSegmentRomStart, _group5_geoSegmentRomEnd),
	LOAD_MIO0(6, _group14_mio0SegmentRomStart, _group14_mio0SegmentRomEnd),
	LOAD_RAW(13, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PALM_TREE,           palm_tree_geo),
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,       ssl_geo_0005C0),
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04,       ssl_geo_0005D8),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_TOP,         ssl_geo_000618),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_GRINDEL,             ssl_geo_000734),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_SPINDEL,             ssl_geo_000764),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_MOVING_PYRAMID_WALL, ssl_geo_000794),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_PYRAMID_ELEVATOR,    ssl_geo_0007AC),
	LOAD_MODEL_FROM_GEO(MODEL_SSL_TOX_BOX,             ssl_geo_000630),
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
	// LOAD_MODEL_FROM_GEO(86, 0x05014630),
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
	JUMP_LINK(script_func_global_6),
	JUMP_LINK(script_func_global_15),
	JUMP_LINK(local_area_bowser_2_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bowser_2_1_[] = {
	AREA(1, Geo_bowser_2_1_0x2f66800),
	TERRAIN(col_bowser_2_1_0xe0123b0),
	SET_BACKGROUND_MUSIC(0, 68),
	TERRAIN_TYPE(0),
//	JUMP_LINK(local_objects_bowser_2_1_),
//	JUMP_LINK(local_warps_bowser_2_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bowser_2_1_[] = {
	OBJECT_WITH_ACTS(0, -454, 1650, 2099, 0, 180, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(0, -454, 690, -3180, 0, 0, 0, 0x3000000,  bhvEyerokBoss, 31),
	OBJECT_WITH_ACTS(194, 7, 726, -1775, 0, 0, 0, 0x20000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -967, 726, -1790, 0, 0, 0, 0x20000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, 254, 726, -2977, 0, 0, 0, 0x20000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(46, -452, 1650, 2108, 0, 0, 0, 0x10000,  bhvCheckpoint_Flag_MOP, 31),
	OBJECT_WITH_ACTS(194, -1186, 726, -2995, 0, 0, 0, 0x20000,  bhvCirclingAmp, 31),
	RETURN()
};

const LevelScript local_warps_bowser_2_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 7, 1, 16, 0),
	WARP_NODE(241, 19, 1, 15, 0),
	RETURN()
};