#pragma once
#include "interfaces.hpp"
#include "raylib.h"

namespace FrogToad {
    struct RaylibView : FrogToad::IView {
        void draw(const FrogToad::Model& m) override;

        int windowW() const;
        int windowH() const;
    };
}
