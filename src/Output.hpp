#pragma once

#include "pch.hpp"

struct Output {
    wl_list link;
    Server *server;
    wlr_output *output;
    wl_listener frame;
    wl_listener request_state;
    wl_listener destroy;
};
