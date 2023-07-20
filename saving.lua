function file_key()
    return get_current_save_file_num() .. "_"
end

function save_hack_data(key,value)
    mod_storage_save(file_key() .. key,value)
end

function load_hack_data(key)
    return mod_storage_load(file_key() .. key)
end

if save_file_get_flags() == 0 then
    save_hack_data("YELLOW_SWITCH","INVALID")
end