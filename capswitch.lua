function dialog_update(dialogid)
    djui_chat_message_create(gNetworkPlayers[0].currAreaIndex .. " " .. gNetworkPlayers[0].currLevelNum .. " " .. gNetworkPlayers[0].currCourseNum)
    if (gNetworkPlayers[0].currAreaIndex == 4 and gNetworkPlayers[0].currLevelNum == 26) then
        save_file_set_flags(1 << 29)
    end
end

hook_event(HOOK_ON_DIALOG, dialog_update)