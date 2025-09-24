#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    struct ConsoleView : FrogToad::IView {
        void draw(const FrogToad::Model& m) override;
    };
}
