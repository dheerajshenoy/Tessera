#pragma once

#include "pch.hpp"

struct Server;

struct Keyboard {
    wl_list link;
    Server *server;
    struct wlr_keyboard *wlr_keyboard;
    wl_listener modifiers;
    wl_listener key;
    wl_listener destroy;
};
