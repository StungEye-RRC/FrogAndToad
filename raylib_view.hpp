#pragma once
#include "interfaces.hpp"
#include "raylib.h"

namespace FrogToad {
    struct RaylibView : IView {
        void draw(const BoardModel& m) override;

        int windowW() const;
        int windowH() const;
    };
}
