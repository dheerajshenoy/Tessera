#pragma once

#include "pch.hpp"

struct Toplevel;

enum class CursorMode;

struct Server {

    Server();
    ~Server();

    wl_display *display;
    wlr_backend *backend;
    wlr_renderer *renderer;
    wlr_allocator *allocator;
    wlr_scene *scene;
    wlr_scene_output_layout *scene_layout;

    wlr_xdg_shell *xdg_shell;
    wl_listener new_xdg_toplevel;
    wl_listener new_xdg_popup;
    wl_list toplevels;

    wlr_cursor *cursor;
    wlr_xcursor_manager *cursor_mgr;
    wl_listener cursor_motion;
    wl_listener cursor_motion_absolute;
    wl_listener cursor_button;
    wl_listener cursor_axis;
    wl_listener cursor_frame;

    wlr_seat *seat;
    wl_listener new_input;
    wl_listener request_cursor;
    wl_listener request_set_selection;
    wl_list keyboards;
    CursorMode cursor_mode;
    Toplevel* grabbed_toplevel;
    double grab_x, grab_y;
    wlr_box grab_geobox;
    uint32_t resize_edges;

    wlr_output_layout *output_layout;
    wl_list outputs;
    wl_listener new_output;


};
