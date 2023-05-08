#include "src/game/envfx_snow.h"

const GeoLayout stargrey_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, stargrey_star_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stargrey_star_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, stargrey_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, stargrey_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
