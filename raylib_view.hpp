#pragma once
#include "interfaces.hpp"
#include "raylib.h"

namespace FrogToad {
    class RaylibView : IView {
    public:
        void draw(const BoardModel& m) override;

        int windowW() const;
        int windowH() const;
    };
}
