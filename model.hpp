#pragma once
#include <array>

namespace FrogToad {
    struct Model {
        static constexpr int BoardSize = 7;

        enum class Cell { E, L, R }; // Empty, L moves right, R moves left

        // --- Public API ---
        void reset();                      // Resets the board to the starting state
        bool isSolved() const;             // Has the board been solved?
        Cell cellAt(int i) const;          // returns E on out-of-range 
        static char toChar(Cell c);        // 'T' for L (Toad), 'F' for R (Frog)
        bool tryMove(int i);               // apply slide-or-jump, returns true if moved

    private:
        static constexpr std::array<Cell, BoardSize> StartingBoard{ Cell::L, Cell::L, Cell::L, Cell::E, Cell::R, Cell::R, Cell::R };
        static constexpr std::array<Cell, BoardSize> GoalBoard{ Cell::R, Cell::R, Cell::R, Cell::E, Cell::L, Cell::L, Cell::L };

        // State
        bool isGameSolved{ false };
        std::array<Cell, BoardSize> board{ StartingBoard };

        // Static Constexpr Helpers
        static constexpr bool isIndexValid(int k);
        static constexpr int moveDirection(Cell c);

        // Instance Helpers
        bool isCellEmpty(int k) const;
        void evaluateBoard();  // Sets "isGameSolved" based on the state of the board.
    };
}
