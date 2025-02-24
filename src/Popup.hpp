#pragma once

#include "pch.hpp"

struct Popup {
    wlr_xdg_popup *xdg_popup;
    wl_listener commit;
    wl_listener destroy;
};
