-- don't ask me why there is nothing here idk too
---@param o Object
function bhv_custom_exclamation_box_init(o)
    if o.oBehParams2ndByte == 3 then
        if yellow_pressed() then
            o.oAction = 2
        else
            o.oAction = 1
        end
    end
end

---@param o Object
function bhv_custom_exclamation_box_loop(o)
    if o.oBehParams2ndByte == 3 and o.oAction == 1 then
        if yellow_pressed() then
            o.oAction = 2
            obj_set_model_extended(o,E_MODEL_EXCLAMATION_BOX)
        end
    end
end

id_bhvExclamationBox = hook_behavior(id_bhvExclamationBox, OBJ_LIST_SURFACE, false, bhv_custom_exclamation_box_init, bhv_custom_exclamation_box_loop, "bhvExclamationBox")