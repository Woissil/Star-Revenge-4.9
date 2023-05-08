#include "src/game/envfx_snow.h"

const GeoLayout staryellow_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, staryellow_star_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, staryellow_star_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, staryellow_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, staryellow_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
