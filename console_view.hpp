#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    /**
     * @brief Plain-text console implementation of FrogToad::IView.
     */
    struct ConsoleView : IView {
        /**
         * @brief Render the current board to stdout.
         * @param m Immutable board model to display.
         */
        void draw(const BoardModel& m) override;
    };
}
