local function for_each_object_with_behavior(behavior, func_f)
    local obj = obj_get_first_with_behavior_id(behavior)
    while obj ~= nil do
        func_f(obj)
        obj = obj_get_next_with_same_behavior_id(obj)
    end
end

function warp_loop(o)
    djui_chat_message_create(tostring(o.oBehParams >> 16))
    if ((o.oBehParams >> 8) & 0xff) == 145 then
        if save_file_get_total_star_count(get_current_save_file_num() - 1, 1 - 1, 25 - 1) >= 145 then
            o.oBehParams = o.oBehParams | (2 << 16)
        else
            o.oBehParams = o.oBehParams | (10 << 16)
        end
    end
end

function pss_warp_cooker()
    if gNetworkPlayers[0].currLevelNum == LEVEL_PSS then
        for_each_object_with_behavior(id_bhvWarp, warp_loop)
    end
end

hook_event(HOOK_UPDATE, pss_warp_cooker)
