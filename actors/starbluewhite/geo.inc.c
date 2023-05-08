#include "src/game/envfx_snow.h"

const GeoLayout starbluewhite_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, starbluewhite_star_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, starbluewhite_star_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, starbluewhite_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, starbluewhite_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
