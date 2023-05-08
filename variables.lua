----------
--models--
----------

E_MODEL_FLIPSWITCH_PANEL = smlua_model_util_get_id("Flipswitch_Panel_MOP")
E_MODEL_FLIPSWAP_PLATFORM = smlua_model_util_get_id("Flipswap_Platform_MOP")
E_MODEL_FLIPSWAP_PLATFORM_BORDER = smlua_model_util_get_id("Flipswap_Platform_Border_MOP")
E_MODEL_FLIPBLOCK = smlua_model_util_get_id("FlipBlock_MOP")
E_MODEL_NOTEBLOCK = smlua_model_util_get_id("Noteblock_MOP")
E_MODEL_SANDBLOCK = smlua_model_util_get_id("SandBlock_MOP")
E_MODEL_SHELL_1 = smlua_model_util_get_id("Shell_1_MOP")
E_MODEL_SHELL_2 = smlua_model_util_get_id("Shell_2_MOP")
E_MODEL_SHRINK_PLATFORM = smlua_model_util_get_id("Shrink_Platform_MOP")
E_MODEL_SHRINK_PLATFORM_BORDER = smlua_model_util_get_id("Shrink_Platform_Border_MOP")
E_MODEL_SWITCHBLOCK = smlua_model_util_get_id("Switchblock_MOP")
E_MODEL_SWITCHBLOCK_SWITCH = smlua_model_util_get_id("Switchblock_Switch_MOP")
E_MODEL_SPRING = smlua_model_util_get_id("Spring_MOP")
E_MODEL_CHECKPOINT = smlua_model_util_get_id("Checkpoint_Flag_MOP")
E_MODEL_GREEN_SWITCHBOARD = smlua_model_util_get_id("Green_Switchboard_MOP")
E_MODEL_GREEN_SWITCHBOARD_GEARS = smlua_model_util_get_id("Green_Switchboard_Gears_MOP")

-------------
--collision--
-------------

COL_FLIPBLOCK_MOP = smlua_collision_util_get("col_FlipBlock_MOP_0x7d1a98")
COL_NOTEBLOCK_MOP = smlua_collision_util_get("col_Noteblock_MOP_0xaa6444")
COL_SANDBLOCK_MOP = smlua_collision_util_get("col_Sandblock_MOP_0xaa6444")
COL_FLIPSWAP_PLATFORM_MOP = smlua_collision_util_get("col_Flipswap_Platform_MOP_0x7d9d88")
COL_FLIPSWITCH_PANEL_MOP = smlua_collision_util_get("col_Flipswitch_Panel_MOP_0x7daf78")
COL_GREEN_SWITCHBOARD_MOP = smlua_collision_util_get("col_Green_Switchboard_MOP_0x7ddc38")
COL_SHRINK_PLATFORM = smlua_collision_util_get("col_Shrink_Platform_MOP_0xad3720")
COL_SWITCHBLOCK_MOP = smlua_collision_util_get("col_Switchblock_MOP_0x7d3058")
COL_SWITCHBLOCK_SWITCH_MOP = smlua_collision_util_get("col_Switchblock_Switch_MOP_0x7d7348")

----------------------
--Variable constants--
----------------------

FLIP_TIMER = 210
SHRINK_TIME = 150
-- This is lua, so no need to specify float or not
-- SHRINK_TIMEF = 150.0

bhvFlipswap_Platform_Border_MOP = id_bhvUnused05A8
bhvShrink_Platform_Border_MOP = id_bhvUnused05A8
bhvGreen_Switchboard_Gear_MOP = id_bhvUnused05A8

--------------------
--Action constants--
--------------------

SPRING_ACT_IDLE = 0
SPRING_ACT_INACTIVE = 1

FLIP_BLOCK_ACT_INACTIVE = 0
FLIP_BLOCK_ACT_IDLE = 1
FLIP_BLOCK_ACT_FLIPPING = 2

NOTEBLOCK_ACT_IDLE = 0
NOTEBLOCK_ACT_BOUNCE = 1

SANDBLOCK_ACT_IDLE = 0
SANDBLOCK_ACT_DISAPPEARING = 1
SANDBLOCK_ACT_DISAPPEARED = 2

FLIPSWAP_PLATFORM_ACT_IDLE = 0
FLIPSWAP_PLATFORM_ACT_FLIPPING = 1

CHECKPOINT_FLAG_ACT_IDLE = 0
CHECKPOINT_FLAG_ACT_ACTIVATED = 1

SHRINK_PLATFORM_ACT_IDLE = 0
SHRINK_PLATFORM_ACT_DISAPPEARING = 1
SHRINK_PLATFORM_ACT_DISAPPEARED = 2

FLIPSWITCH_PANEL_ACT_IDLE = 0
FLIPSWITCH_PANEL_ACT_ACTIVE = 1

SWITCHBLOCK_ACT_ACTIVE = 0
SWITCHBLOCK_ACT_INACTIVE = 1

-------------
--Variables--
-------------

-- This isn't used, but may as well keep it in case someone wants to use it
do_fall_damage = true