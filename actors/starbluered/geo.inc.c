#include "src/game/envfx_snow.h"

const GeoLayout starbluered_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, starbluered_star_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, starbluered_star_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, starbluered_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, starbluered_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
