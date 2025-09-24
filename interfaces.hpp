#pragma once
#include "model.hpp"

namespace FrogToad {
    // ===================== View interface =====================
    struct IView {
        virtual ~IView() = default;
        virtual void draw(const FrogToad::Model&) = 0;
    };

    // ===================== Controller interface + helper =====================
    struct IController {
        virtual ~IController() = default;
        virtual void step(FrogToad::Model&) = 0;

        static bool applyCommand(FrogToad::Model& m, char key) {
            if (key == 'r' || key == 'R') { m.reset(); return true; }
            // Subtracting '1' from the key to convert from 
            // the ASCII char value to the integer equivalent.
            return m.tryMove(key - '1');
        }
    };
}
