#include "board_model.hpp"

namespace FrogToad {

    // --- Public API ---

    void BoardModel::reset() {
        board = StartingBoard;
        isGameSolved = false;
    }

    bool BoardModel::isSolved() const { 
        return isGameSolved; 
    }

    BoardModel::Cell BoardModel::cellAt(int i) const {
        return isIndexValid(i) ? board[i] : Cell::Empty;
    }

    char BoardModel::toChar(Cell c) {
        // Converts Cell enums to Text using nested ternary
        // Empty => '.', Frog => 'F', Toad => 'T'
        return c == Cell::Empty ? '.' : (c == Cell::Frog ? 'F' : 'T');
    }

    bool BoardModel::tryMove(int i) {
        if (!isIndexValid(i) || isCellEmpty(i)) return false;

        Cell c{ board[i] };
        int slideMove{ i + moveDirection(c) };
        int jumpMove{ i + 2 * moveDirection(c) };

        if (isIndexValid(slideMove) && !isCellEmpty(slideMove) && isIndexValid(jumpMove) && isCellEmpty(jumpMove)) {
            board[jumpMove] = c;
        }
        else if (isIndexValid(slideMove) && isCellEmpty(slideMove)) {
            board[slideMove] = c;
        }
        else {
            return false;
        }

        board[i] = Cell::Empty;
        evaluateBoard();
        return true;
    }

    // --- Private Static Constexpr Helpers ---

    constexpr bool BoardModel::isIndexValid(int k) { 
        return k >= 0 && k < BoardSize; 
    }
    
    constexpr int BoardModel::moveDirection(Cell c) { 
        return (c == Cell::Frog) ? +1 : -1; 
    }

    // --- Private Instance Helpers ---

    bool BoardModel::isCellEmpty(int k) const { 
        return board[k] == Cell::Empty;
    }

    void BoardModel::evaluateBoard() {
        isGameSolved = (board == GoalBoard);
    }

} // namespace FrogToad
