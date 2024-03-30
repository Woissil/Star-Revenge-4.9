#include "src/game/envfx_snow.h"

const GeoLayout star_001_displaylist_opt1[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt2[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt3[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt4[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt5[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt6[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt7[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt8[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt9[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt10[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt11[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt12[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt13[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt14[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt15[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_001_displaylist_opt16[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout star_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(0, 155, 100),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_FORCE, 16384),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE, star_000_displaylist_mesh_layer_1),
				GEO_SWITCH_CASE(16, geo_switch_anim_state),
				GEO_OPEN_NODE(),
					GEO_NODE_START(),
					GEO_OPEN_NODE(),
						GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, NULL),
					GEO_CLOSE_NODE(),
					GEO_BRANCH(1, star_001_displaylist_opt1),
					GEO_BRANCH(1, star_001_displaylist_opt2),
					GEO_BRANCH(1, star_001_displaylist_opt3),
					GEO_BRANCH(1, star_001_displaylist_opt4),
					GEO_BRANCH(1, star_001_displaylist_opt5),
					GEO_BRANCH(1, star_001_displaylist_opt6),
					GEO_BRANCH(1, star_001_displaylist_opt7),
					GEO_BRANCH(1, star_001_displaylist_opt8),
					GEO_BRANCH(1, star_001_displaylist_opt9),
					GEO_BRANCH(1, star_001_displaylist_opt10),
					GEO_BRANCH(1, star_001_displaylist_opt11),
					GEO_BRANCH(1, star_001_displaylist_opt12),
					GEO_BRANCH(1, star_001_displaylist_opt13),
					GEO_BRANCH(1, star_001_displaylist_opt14),
					GEO_BRANCH(1, star_001_displaylist_opt15),
					GEO_BRANCH(1, star_001_displaylist_opt16),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
