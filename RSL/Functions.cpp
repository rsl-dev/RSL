#include "Functions.h"

namespace rfg
{
    void HideHud(bool Hide)
    {
        //HudVisible = !HudVisible; //This wasn't working for some odd reason so I just set them manually. Same for HideFog.
        rfg::HudHide(Hide);
        if (Hide)
        {
            Globals::HudVisible = false;
        }
        else
        {
            Globals::HudVisible = true;
        }
    }

    void HideFog(bool Hide)
    {
        GameRenderSetFogEnabled(!Hide);
        //FogVisible = !Hide;
        if (Hide)
        {
            Globals::FogVisible = false;
        }
        else
        {
            Globals::FogVisible = true;
        }
    }

    void ToggleHud()
    {
        if (Globals::HudVisible)
        {
            HideHud(true);
            Globals::HudVisible = false;
        }
        else
        {
            HideHud(false);
            Globals::HudVisible = true;
        }
        //HudVisible = !HudVisible; //This wasn't working for some odd reason so I just set them manually.
    }

    void ToggleFog()
    {
        if (Globals::FogVisible)
        {
            HideFog(true);
            Globals::FogVisible = false;
        }
        else
        {
            HideFog(false);
            Globals::FogVisible = true;
        }
        //FogVisible = !FogVisible; //This wasn't working for some odd reason so I just set them manually.
    }

    F_Camera_Start_Slew_Mode CameraStartSlewMode;
    F_Camera_Stop_Slew_Mode CameraStopSlewMode;
    F_Camera_Start_Third_Person CameraStartThirdPerson;
    F_camera_start_first_person CameraStartFirstPerson;
    F_camera_stop_first_person CameraStopFirstPerson;

    F_Camera_First_Person_Pre_Process CameraFirstPersonPreProcess;
    F_camera_free_system_init CameraFreeSystemInit;
    F_camera_free_mode_init CameraFreeModeInit;

    F_Interface_Debug_Mode_Activate InterfaceDebugModeActivate;
    F_Keen_Debug_WriteToLogFile KeenDebugWriteToLogFile;
    F_Hud_Display_Distance HudDisplayDistance;

    F_console_set_console_mode ConsoleSetConsoleMode;
    F_console_get_console_mode ConsoleGetConsoleMode;
    F_Console_Init ConsoleInit;
    F_Console_Activate ConsoleActivate;
    F_Console_Deactivate ConsoleDeactivate;

    F_InvertDataItem InvertDataItem;
    F_Console_Printf ConsolePrintf;
    F_Console_Display_Help ConsoleDisplayHelp;
    F_Console_Command_Enable ConsoleCommandEnable;
    F_Console_Do_Command ConsoleDoCommand;

    F_Game_Print_Screen GamePrintScreen;

    F_console_chat_printf ConsoleChatPrintf;
    F_unused_dcf_r_show_mem_usage UnusedDcfRShowMemUsage;
    F_rfg_dyn_get_active_destruction_frame RfgDynGetActiveDestructionFrame;
    F_rfg_dyn_reset_destruction_frame RfgDynResetDestructionFrame;
    F_rfg_dyn_system_shutdown RfgDynSystemShutdown;
    F_get_screen_width GetScreenWidth;
    F_console_is_active ConsoleIsActive;
    F_AllocatorStillValid AllocatorStillValid;
    F_debug_spew_projectile DebugSpewProjectile;
    F_debug_spew_game_io DebugSpewGameIo;
    F_rl_render_lib_get_metrics RlRenderLibGetMetrics;
    F_profile_dump_info ProfileDumpInfo;
    F_vint_render_text VintRenderText;
    F_xray_effect_start XrayEffectStart;
    F_xray_effect_stop XrayEffectStop;

    F_key_down KeyDown;
    F_game_render_set_bloom_exposure_factor GameRenderSetBloomExposureFactor;
    F_game_render_set_hdr_state GameRenderSetHdrState;
    F_game_render_2d_text GameRender2dText;
    F_ui_add_debug_text UiAddDebugText;
    F_get_depth_of_field_enabled GetDepthOfFieldEnabled;
    F_set_depth_of_field_enabled SetDepthOfFieldEnabled;
    //F_character_controller_set_pos CharacterControllerSetPos; //IDA shows this as using __thiscall, but using that causes the game to immediately crash
    F_fog_of_war_clear FogOfWarClear;

    F_Hud_Hide HudHide;
    F_game_render_set_fog_enabled GameRenderSetFogEnabled;

    F_explosion_create ExplosionCreate;
    F_keen_graphics_beginframe GraphicsBeginFrame;
    F_MouseGenericAutoCentering MouseGenericAutoCentering;
    F_CameraViewDataSetView CameraViewDataSetView;
    F_PlayerDoFrame PlayerDoFrame;
    F_PlayerConstructor PlayerConstructor;
    F_CharacterControllerSetPos CharacterControllerSetPos;

    F_ObjectUpdatePosAndOrient ObjectUpdatePosAndOrient;

    F_HavokBodySetPosition HavokBodySetPosition;
    F_HavokBodyGetPositionAndOrient HavokBodyGetPositionAndOrient;

    F_HavokBodySetPositionAndOrient HavokBodySetPositionAndOrient;

    F_HumanUpdatePosAndOrient HumanUpdatePosAndOrient;
    F_HumanTeleportUnsafe HumanTeleportUnsafe;
    //F_HumanTeleport HumanTeleport;

    F_HookDoFrame HookDoFrame;

    F_KeenGraphicsResizeRenderSwapchain KeenGraphicsResizeRenderSwapchain;
    F_GameseqGetState GameseqGetState;
    F_GameseqSetState GameseqSetState;
    F_GameseqPushState GameseqPushState;

    F_ObjectEnableOutline ObjectEnableOutline;
    F_ObjectDisableOutline ObjectDisableOutline;
    F_HumanEnableOutline HumanEnableOutline;
    F_HumanDisableOutline HumanDisableOutline;
    F_TargetOutlineAddObject TargetOutlineAddObject;

    F_ui_tool_tips_add_tip UiToolTipsAddTip;

    F_rl_draw_tristrip_2d_begin RlDrawTristrip2dBegin;
    F_rl_draw_string RlDrawString;

    F_is_game_paused IsGamePaused;
    F_world_do_frame WorldDoFrame;
    F_world_get_object_name WorldGetObjectName;

    F_world_get_object_zone_by_index WorldGetObjectZoneByIndex;
    F_world_get_object_zone_by_grid_id WorldGetObjectZoneByGridId;

    F_gsm_get_alert_level GsmGetAlertLevel;
    F_gsm_set_alert_level GsmSetAlertLevel;

    F_gsm_get_alert_value GsmGetAlertValue;
    F_gsm_set_alert_value GsmSetAlertValue;

    F_gsm_get_alert_level_cap GsmGetAlertLevelCap;
    F_gsm_set_alert_level_cap GsmSetAlertLevelCap;

    F_game_render_get_TOD_light GameRenderGetTodLight;
    F_game_render_set_TOD_light GameRenderSetTodLight;

    F_game_render_get_tod_on_off_value GameRenderGetTodOnOffValue;
    F_game_render_set_tod_on_off_value GameRenderSetTodOnOffValue;

    F_game_render_set_TOD_light_color GameRenderSetTodLightColor;

    F_game_clock_get_tod_partitioned GameClockGetTodPartitioned;

    F_game_clock_get_time_of_day GameClockGetTimeOfDay;
    F_game_clock_set_time GameClockSetTime;

    F_game_time_of_day_get_skybox_tod_colors GameTimeOfDayGetSkyboxTodColors;
    F_game_time_of_day_get_weather_settings GameTimeOfDayGetWeatherSettings;
    F_game_time_of_day_get_cloud_scroll_values GameTimeOfDayGetCloudScrollValues;
    F_game_time_of_day_get_num_orbitals GameTimeOfDayGetNumOrbitals;
    F_game_time_of_day_get_cloud_lighting GameTimeOfDayGetCloudLighting;
    F_game_time_of_day_get_orbital_params GameTimeOfDayGetOrbitalParams;

    F_district_from_name DistrictFromName;

    F_get_world_zone_by_index GetWorldZoneByIndex;
    F_get_world_zone_by_grid_id GetWorldZoneByGridId;
    F_get_world_zone_by_name GetWorldZoneByName;
    F_get_world_zone_by_pos GetWorldZoneByPos;
    F_get_world_zone_by_object_handle GetWorldZoneByObjectHandle;

    F_rfg_dyn_apply_point_impulse RfgDynApplyPointImpulse;
    F_rfg_dyn_repair_sphere RfgDynRepairSphere;

    F_IsValidEigenGradient IsValidEigenGradient;

    Human* CastObjectToHuman(Object* ObjectPtr) { return static_cast<Human*>(ObjectPtr); }
    Player* CastObjectToPlayer(Object* ObjectPtr) { return static_cast<Player*>(ObjectPtr); }
    obj_zone* CastObjectToObjZone(Object* ObjectPtr) { return static_cast<obj_zone*>(ObjectPtr); }
    district* CastObjectToDistrict(Object* ObjectPtr) { return static_cast<district*>(ObjectPtr); }

    F_rl_camera_render_begin RlCameraRenderBegin;

    F_game_render_set_far_clip_distance GameRenderSetFarClipDistance;
    F_game_render_get_far_clip_distance GameRenderGetFarClipDistance;
    F_game_render_get_main_scene GameRenderGetMainScene;

    F_hkpWorld_stepDeltaTime hkpWorldStepDeltaTime;
    F_ApplicationUpdateTime ApplicationUpdateTime;

    F_hkpWorldGetGravity hkpWorldGetGravity;
    F_hkpWorldSetGravity hkpWorldSetGravity;

    F_vint_lua_get_state VintGetLuaState;
    F_lua_dobuffer LuaDoBuffer;

    F_havok_body_get_pointer HavokBodyGetPointer;
    F_havok_body_apply_linear_impulse_A HavokBodyApplyLinearImpulseA;
    F_havok_body_apply_linear_impulse_B HavokBodyApplyLinearImpulseB;
    F_havok_body_apply_point_impulse havok_body_apply_point_impulse;

    F_keen_graphics_beginFrame KeenGraphicsBeginFrame;

    F_keen_get_build_version_string KeenGetBuildVersionString;

    F_WorldObjectFromHandle WorldObjectFromHandle;

    F_unused_dcf_ragdoll_player UnusedDcfRagdollPlayer;

    F_StreamGridSetStreamRadius StreamGridSetStreamRadius;
    F_StreamGridGetStreamRadius StreamGridGetStreamRadius;
    F_StreamGridDoFrame StreamGridDoFrame;
    F_CsWrapSlice CsWrapSlice;


    F_cutscene_spawn_vehicle CutsceneSpawnVehicle;
    //F_object_spawn_vehicle ObjectSpawnVehicle;
    F_vehicle_info_get_master_list VehicleInfoGetMasterList;
    F_sp_spawn_vehicle SpSpawnVehicle;
    F_create_new_vehicle create_new_vehicle_raw;

    F_load_level_internal load_level_internal;

    void LoadLevelWrapper(std::string Filename, bool NewGame, bool SingleZone)
    {
        const char* FilenameAsCharPtr = Filename.c_str();

        __asm mov esi, FilenameAsCharPtr;

        load_level_internal(NewGame, SingleZone);
    }

    F_WorldSetPendingTerritoryLoad WorldSetPendingTerritoryLoad;

    F_peg_load_wrapper peg_load_wrapper;

    F_string_hash string_hash;

    F_object_spawn_vehicle object_spawn_vehicle;

    F_human_get_head_pos_orient human_get_head_pos_orient;
    F_human_set_render human_set_render;
    F_human_hide human_hide;
    F_human_set_opacity_plus_child_items human_set_opacity_plus_child_items;

    F_matrix_rotate_around_local_vector matrix_rotate_around_local_vector;

    F_keen_ImmediateRenderer_beginRenderPass keen_ImmediateRenderer_beginRenderPass;

    F_ui_add_secondary_message ui_add_secondary_message;
    F_ui_add_user_message ui_add_user_message;
    F_ui_add_msgbox ui_add_msgbox;
    F_hud_message_change_minor_message hud_message_change_minor_message;
    F_hud_message_change_user hud_message_change_user;
    F_hud_message_remove_user hud_message_remove_user;

    F_rfgl_find_and_delete_object_mover rfgl_find_and_delete_object_mover;
    F_rfgl_find_and_delete_debris_object rfgl_find_and_delete_debris_object;

    F_game_clock_get game_clock_get;

    F_audiolib_cue_get_id audiolib_cue_get_id;
    F_audiolib_cue_is_id_valid audiolib_cue_is_id_valid;
    F_audiolib_cue_play audiolib_cue_play;
    F_audiolib_get_listener_pos audiolib_get_listener_pos;
    F_audiolib_cue_play_3d audiolib_cue_play_3d;

    F_gamestate_gp_process gamestate_gp_process;
    F_game_is_paused game_is_paused;

    F_human_fire_ignite human_fire_ignite;
    F_human_fire_stop human_fire_stop;

    F_rfg_init_stage_2_done rfg_init_stage_2_done;
    F_rfg_init_stage_2_done_2 rfg_init_stage_2_done_2;

    F_verify_gamesave_exit_notify verify_gamesave_exit_notify;

    F_havok_body_force_activate havok_body_force_activate;
    F_havok_body_set_movable havok_body_set_movable;
    F_havok_body_get_mass havok_body_get_mass;

    F_objective_highlight_add objective_highlight_add;
    F_objective_highlight_remove objective_highlight_remove;
    F_objective_highlight_remove_all objective_highlight_remove_all;

    F_world_load_territory world_load_territory;

    F_can_drop_vehicle can_drop_vehicle;

    F_mission_get_name mission_get_name;
    F_mission_get_description mission_get_description;

    F_vehicle_interaction_request_enter vehicle_interaction_request_enter;
    F_vehicle_interaction_request_exit vehicle_interaction_request_exit;
    F_vehicle_engine_start vehicle_engine_start;
    F_vehicle_engine_stop vehicle_engine_stop;
    F_flyer_engine_start flyer_engine_start;
    F_flyer_engine_stop flyer_engine_stop;

    F_havok_body_get_linear_velocity havok_body_get_linear_velocity;
    F_havok_body_get_linear_dampening havok_body_get_linear_dampening;
    F_havok_body_set_linear_velocity havok_body_set_linear_velocity;
    F_havok_body_set_linear_dampening havok_body_set_linear_dampening;
    F_havok_body_set_angular_dampening havok_body_set_angular_dampening;
    F_havok_body_set_angular_velocity havok_body_set_angular_velocity;
    F_havok_body_get_angular_velocity havok_body_get_angular_velocity;
    F_havok_body_get_angular_dampening havok_body_get_angular_dampening;

    F_cf_open cf_open;

    F_effects_template_find effects_template_find;
    F_vfx_effect_create vfx_effect_create;
    F_vfx_effect_enable_emission vfx_effect_enable_emission;
    F_vfx_effect_enable_coronas vfx_effect_enable_coronas;
    F_vfx_effect_update vfx_effect_update;

    F_effects_play effects_play;

    F_squad_definition_from_name squad_definition_from_name;
    F_squad_spawn_parameters_spawn_squad squad_spawn_parameters_spawn_squad;
    F_squad_spawn_parameters_constructor squad_spawn_parameters_constructor;
    F_squad_spawn_parameters_create_squad squad_spawn_parameters_create_squad;

    F_find_local_spawn_region find_local_spawn_region;
    F_find_local_building find_local_building;
    F_object_squad_spawn_members object_squad_spawn_members;

    F_gem_post_event gem_post_event;
    F_world_create_object_general_mover world_create_object_general_mover;
    F_player_create_player_squad player_create_player_squad;
    F_rfg_snap_to_ground rfg_snap_to_ground;
    F_automobile_honk_horn automobile_honk_horn;

    F_chunk_get_base_by_name chunk_get_base_by_name;
    F_object_mover_create_from_chunk object_mover_create_from_chunk;

    F_object_debris_create_havok_body object_debris_create_havok_body;

    F_obj_prop_block_constructor obj_prop_block_constructor;
    F_rfg_prop_block_set_internal rfg_prop_block_set_internal;
    F_world_create_object_internal world_create_object_internal;

    object* CreateObjectFromZoneObjectBinary(std::string path, vector& pos, matrix& orient, const char* name)
    {
        std::ifstream in(path);

        //get length of file
        in.seekg(0, std::ios::end);
        size_t length = in.tellg();
        in.seekg(0, std::ios::beg);

        //Read file into byte array
        char* buffer = new char[length];
        in.read(buffer, length);

        //Create obj_prop_block based on zone object values
        auto zoneObjCast = reinterpret_cast<zone_object_extended*>(buffer);
        obj_prop_block propBlock;
        obj_prop_block_constructor(&propBlock, nullptr, pos, orient, name);
        propBlock.num_props = zoneObjCast->num_props;
        propBlock.buf_pos = zoneObjCast->prop_list_size;
        propBlock.prop_list = &zoneObjCast->prop_list;
        propBlock.buf_size = propBlock.buf_pos;

        //Attempt to create the object.
        object* resultingObject = world_create_object_internal(Globals::RfgWorldPtr, nullptr, zoneObjCast->classname_hash, propBlock, nullptr, 0xFFFFFFFF);
        return resultingObject;
    }

    F_obj_auto_props_constructor obj_auto_props_constructor;
    F_obj_projectile_props_constructor obj_projectile_props_constructor;
    F_str_hash_string str_hash_string;
    F_amb_prop_create amb_prop_create;
    F_weapon_fire weapon_fire;
}
