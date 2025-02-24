#pragma once

#include "pch.hpp"
#include "Server.hpp"
#include "Output.hpp"
#include "Toplevel.hpp"
#include "Popup.hpp"
#include "Keyboard.hpp"

enum class CursorMode {
    PASSTHROUGH = 0,
    MOVE,
    RESIZE,
};


class Tessera {

public:
    Tessera();
    ~Tessera();
    int run() noexcept;

private:
    Server *m_server { nullptr };
};
