
--[[
function purple_pressed()
    return load_hack_data("PURPLE_SWITCH") == "PRESSED"
end


function on_purple_pressed(o)
    save_hack_data("PURPLE_SWITCH","PRESSED")
end
]]

--use this function to determine if a switch was pressed
function yellow_pressed()
    return load_hack_data("YELLOW_SWITCH") == "PRESSED"
end

--use this function to save that the switch was pressed
function on_yellow_pressed(o)
    save_hack_data("YELLOW_SWITCH","PRESSED")
end

--[[
each element in this table should be formatted as
[bhvParam2Byte] = {on_switch_pressed,is_switch_enabled}
please note that any functions must be placed before this table 
or else it doesnt work
]]
switch_functionality = {
    [3] = {on_yellow_pressed,yellow_pressed},
--    [4] = {on_purple_pressed,purple_pressed},
}


--- @param o Object
function init(o)
    ourTable = switch_functionality[o.oBehParams2ndByte]
    if ourTable and ourTable[2]() then
        o.oAction = 3
        obj_scale_xyz(o,0.5,0.1,0.5)
    end
end

--- @param o Object
function pressed_check(o)
    --only run this function when the switch is pressed
    if o.oAction ~= 2 then return end
    ourTable = switch_functionality[o.oBehParams2ndByte]
    if ourTable and not ourTable[2]() then
        ourTable[1](o)
    end
end



hook_behavior(id_bhvCapSwitch,OBJ_LIST_SURFACE,false,init,pressed_check,"bhvCustomCapSwitch")