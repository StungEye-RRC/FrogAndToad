#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    struct RaylibController : IController {
        void nextMove(BoardModel& m) override;
    };
}
