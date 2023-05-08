function captimer()
    djui_hud_set_color(255, 255, 255, 255)
    djui_hud_set_font(FONT_HUD)
    djui_hud_set_resolution(RESOLUTION_N64)
    local metal = get_texture_info("metal")
    local vanish = get_texture_info("vanish")
    local wing = get_texture_info("wing")
	local wmcap = get_texture_info("wmcap")
	local vmcap = get_texture_info("vmcap")
	local wvcap = get_texture_info("wvcap")
    
    local m = gMarioStates[0]
    if (m.flags & (MARIO_WING_CAP | MARIO_METAL_CAP | MARIO_VANISH_CAP)) ~= 0 then
        djui_hud_print_text(".", 37, 204, 1) djui_hud_print_text(tostring(math.ceil(m.capTimer/30)), 53, 204, 1)
    end
	if (m.flags & MARIO_METAL_CAP) ~= 0 and (m.flags & MARIO_WING_CAP) ~= 0 then
		djui_hud_render_texture(wmcap, 21, 204, 1, 1)
	elseif (m.flags & MARIO_METAL_CAP) ~= 0 and (m.flags & MARIO_VANISH_CAP) ~= 0 then
		djui_hud_render_texture(vmcap, 21, 204, 1, 1)
	elseif (m.flags & MARIO_VANISH_CAP) ~= 0 and (m.flags & MARIO_WING_CAP) ~= 0 then
		djui_hud_render_texture(wvcap, 21, 204, 1, 1)
    elseif (m.flags & (MARIO_METAL_CAP)) ~= 0 then
         djui_hud_render_texture(metal, 21, 204, 1, 1)
    elseif(m.flags & (MARIO_VANISH_CAP)) ~= 0 then
        djui_hud_render_texture(vanish, 21, 204, 1, 1)
    elseif (m.flags & (MARIO_WING_CAP)) ~= 0 then
        djui_hud_render_texture(wing, 21, 204, 1, 1)
    end
end

hook_event (HOOK_ON_HUD_RENDER, captimer)