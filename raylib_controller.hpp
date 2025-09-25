#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    struct RaylibController : IController {
        void step(BoardModel& m) override;
    };
}
