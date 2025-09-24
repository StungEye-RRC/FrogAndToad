#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    struct RaylibController : FrogToad::IController {
        void step(FrogToad::Model& m) override;
    };
}
