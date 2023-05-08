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

#include "levels/bowser_3/header.h"
#include "levels/thi/header.h"

extern u8 _bowser_3_segment_ESegmentRomStart[];
extern u8 _bowser_3_segment_ESegmentRomEnd[];

const LevelScript level_bowser_3_entry[] = {
	INIT_LEVEL(),
	LOAD_MIO0(0x07, _thi_segment_7SegmentRomStart, _thi_segment_7SegmentRomEnd),
	LOAD_RAW(0x1A, _thiSegmentRomStart, _thiSegmentRomEnd),
	LOAD_RAW(0x0E, _bowser_3_segment_ESegmentRomStart, _bowser_3_segment_ESegmentRomEnd),
	LOAD_MIO0(0xA, _SkyboxCustom50560592_skybox_mio0SegmentRomStart, _SkyboxCustom50560592_skybox_mio0SegmentRomEnd),
	LOAD_MIO0(8, _common0_mio0SegmentRomStart, _common0_mio0SegmentRomEnd),
	LOAD_RAW(15, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd),
	LOAD_MIO0(5, _group3_mio0SegmentRomStart, _group3_mio0SegmentRomEnd),
	LOAD_RAW(12, _group3_geoSegmentRomStart, _group3_geoSegmentRomEnd),
	LOAD_MIO0(6, _group17_mio0SegmentRomStart, _group17_mio0SegmentRomEnd),
	LOAD_RAW(13, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd),
	ALLOC_LEVEL_POOL(),
	MARIO(/*model*/ MODEL_MARIO, /*behParam*/ 0x00000001, /*beh*/ bhvMario),
	// Level Specific Models
	LOAD_MODEL_FROM_GEO(MODEL_THI_BUBBLY_TREE,     bubbly_tree_geo),
	    LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03,   thi_geo_0005F0),
	    LOAD_MODEL_FROM_GEO(MODEL_THI_WARP_PIPE,       warp_pipe_geo),
	    LOAD_MODEL_FROM_GEO(MODEL_THI_HUGE_ISLAND_TOP, thi_geo_0005B0),
	    LOAD_MODEL_FROM_GEO(MODEL_THI_TINY_ISLAND_TOP, thi_geo_0005C8),
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
	JUMP_LINK(script_func_global_18),
	JUMP_LINK(local_area_bowser_3_1_),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(/*arg*/ 0, /*func*/ lvl_init_or_update),
	CALL_LOOP(/*arg*/ 1, /*func*/ lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(/*frames*/ 1),
	EXIT(),
};

const LevelScript local_area_bowser_3_1_[] = {
	AREA(1, Geo_bowser_3_1_0x305dd70),
	TERRAIN(col_bowser_3_1_0xe0bd7a0),
	SET_BACKGROUND_MUSIC(0, 69),
	TERRAIN_TYPE(0),
	JUMP_LINK(local_objects_bowser_3_1_),
	JUMP_LINK(local_warps_bowser_3_1_),
	END_AREA(),
	RETURN()
};

const LevelScript local_objects_bowser_3_1_[] = {
	OBJECT_WITH_ACTS(0, 1, 903, -3905, 0, 0, 0, 0xa0000,  bhvSpinAirborneWarp, 31),
	OBJECT_WITH_ACTS(124, -229, 525, -3371, 0, 135, 0, 0x5d0000,  bhvMessagePanel, 31),
	OBJECT_WITH_ACTS(137, -6030, 294, 30, 0, 0, 0, 0x10000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(129, -1236, 4921, -8846, 0, 0, 0, 0x0,  bhvJumpingBox, 31),
	OBJECT_WITH_ACTS(120, -10197, 3366, -1736, 0, 0, 0, 0x0,  bhvRecoveryHeart, 31),
	OBJECT_WITH_ACTS(137, -486, 6413, -911, 0, 0, 0, 0x20000,  bhvExclamationBox, 31),
	OBJECT_WITH_ACTS(0, 0, 975, 3884, 0, 0, 0, 0x1000000,  bhvFlipswitch_Panel_StarSpawn_MOP, 31),
	OBJECT_WITH_ACTS(42, 11186, 3756, -3307, 0, 225, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 7218, 2859, 667, 0, 45, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 8498, 2859, 664, 0, 135, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 8511, 2859, -640, 0, 225, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, 7195, 2859, -624, 0, -45, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(0, -3845, 3900, 2309, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -3729, 3900, 3, 0, 0, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(194, -2964, 4699, -3683, 0, 0, 0, 0x0,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(180, -3809, 5593, -4353, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, -4557, 6082, -5550, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(192, -831, 6532, -5604, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(194, -490, 6886, -4811, 0, 0, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -547, 6310, -4107, 0, 0, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -416, 6196, -3636, 0, 0, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(194, -556, 5881, -3251, 0, 0, 0, 0x30000,  bhvCirclingAmp, 31),
	OBJECT_WITH_ACTS(180, -190, 6394, -1205, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 1617, 6844, -3466, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, 1624, 6124, -4753, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, 1594, 6082, -6222, 0, 0, 0, 0x110000,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, -3917, 3762, -8844, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, -10416, 2400, -97, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, -8702, 2646, -3, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -7792, 1272, -2238, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -3772, 135, 0, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(0, 0, 21, 0, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(223, 10473, 3750, -2818, 0, 1, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, 7783, 2325, 3631, 0, 1, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, 7846, 3138, 6409, 0, 1, 0, 0x0,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(0, 87, 5322, 6916, 0, 315, 0, 0x0,  bhvGoombaTripletSpawner, 31),
	OBJECT_WITH_ACTS(0, -3554, 5472, 7126, 0, 315, 0, 0x0,  bhvMrI, 31),
	OBJECT_WITH_ACTS(0, -6116, 5772, 8599, 0, 315, 0, 0x0,  bhvMrI, 31),
	OBJECT_WITH_ACTS(212, -5843, 6162, 10897, 0, 315, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(212, -5982, 4524, 10576, 0, 315, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, -5917, 3372, 8366, 0, 0, 0, 0x20000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(201, -8325, 3138, 10955, 0, 0, 0, 0x0,  bhvCannonClosed, 31),
	OBJECT_WITH_ACTS(192, -8794, 3150, 11480, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(192, -9106, 3150, 11287, 0, 0, 0, 0x0,  bhvGoomba, 31),
	OBJECT_WITH_ACTS(180, -10901, 2866, 11497, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -11375, 2550, 10171, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, -10556, 1950, 8284, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(0, -10196, 3786, 5309, 0, 0, 0, 0x110000,  bhvCoinFormation, 31),
	OBJECT_WITH_ACTS(180, -7096, 4272, 2147, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -6571, 4122, 2870, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -5307, 4122, 3440, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(180, -3864, 4020, 2611, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(223, -6909, 3900, 2749, 0, 67, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(223, -4698, 3900, 3150, 0, 0, 0, 0x0,  bhvChuckya, 31),
	OBJECT_WITH_ACTS(180, -7440, 4206, 2675, 0, 0, 0, 0x0,  bhvFireSpitter, 31),
	OBJECT_WITH_ACTS(42, -10205, 3900, 3620, 0, 90, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -8304, 3150, 10092, 0, -90, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -5357, 4122, 10853, 0, 135, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(42, -12, 5724, 6938, 0, 180, 0, 0x0,  bhvFlipswitch_Panel_MOP, 31),
	OBJECT_WITH_ACTS(212, 1251, 7129, -8404, 0, 0, 0, 0x0,  bhv1Up, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 24, 0, 0, 20, 376,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 377,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 378,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 379,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 380,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 381,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 382,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 4, 0, 0, 20, 383,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 22, 0, 0, 20, 384,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 22, 0, 0, 20, 385,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -20, 4, 32, 0, 0, 20, 386,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, -20, 4, 40, 0, 0, 20, 387,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 94, 0, 0, 20, 388,  RM_Scroll_Texture, 31),
	OBJECT_WITH_ACTS(0, 12, 5, 12, 0, 0, 20, 389,  RM_Scroll_Texture, 31),
	RETURN()
};

const LevelScript local_warps_bowser_3_1_[] = {
	WARP_NODE(10, 9, 1, 0, 0),
	WARP_NODE(240, 6, 3, 10, 0),
	WARP_NODE(241, 21, 2, 15, 0),
	RETURN()
};