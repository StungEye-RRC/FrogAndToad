#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    class RaylibController : IController {
    public:
        void nextMove(BoardModel& m) override;
    };
}
