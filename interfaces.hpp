#pragma once
#include "board_model.hpp"

namespace FrogToad {
    // ########## View "Interface" ##########
    // Abstract class for our game views.
    // Views must inherit from this class and implement the draw method.
    struct IView {
        virtual ~IView() = default;
        virtual void draw(const BoardModel&) = 0;
    };

    // ########## Controller "Interface" + Helper ##########
    // Abstract class for our game controllers.
    // Controllers must inherit from this class and implement the setup method.
    // The step method should in term call out to the applyCommand helper method
    // to communicate with the model.
    struct IController {
        virtual ~IController() = default;
        virtual void step(BoardModel&) = 0;

        static bool applyCommand(BoardModel& m, char key) {
            if (key == 'r' || key == 'R') { m.reset(); return true; }
            // Subtracting '1' from the key to convert from the ASCII char 
            // value to an integer. For example:
            // '1' - '1' = 0
            // '2' - '1' = 1
            // '3' - '1' = 2 
            // Etc...
            return m.tryMove(key - '1');
        }
    };
}
