#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    struct ConsoleView : IView {
        void draw(const Model& m) override;
    };
}
