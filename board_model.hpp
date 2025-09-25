#pragma once
#include <array>

namespace FrogToad {
    struct BoardModel {
        static constexpr int BoardSize = 7;

        enum class Cell { Empty, Frog, Toad }; // Empty, Frog moves right, Toad moves left

        // --- Public API ---
        void reset();                      // Resets the board to the starting state
        bool isSolved() const;             // Has the board been solved?
        Cell cellAt(int i) const;          // returns Empty on out-of-range 
        static char toChar(Cell c);        // 'T' for Frog (Toad), 'F' for Toad (Frog)
        bool tryMove(int i);               // apply slide-or-jump, returns true if moved

    private:
        static constexpr std::array<Cell, BoardSize> StartingBoard{ Cell::Frog, Cell::Frog, Cell::Frog, Cell::Empty, Cell::Toad, Cell::Toad, Cell::Toad };
        static constexpr std::array<Cell, BoardSize> GoalBoard{ Cell::Toad, Cell::Toad, Cell::Toad, Cell::Empty, Cell::Frog, Cell::Frog, Cell::Frog };

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
