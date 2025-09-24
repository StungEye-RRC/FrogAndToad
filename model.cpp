#include "model.hpp"

namespace FrogToad {

    // --- Public API ---

    void Model::reset() {
        board = StartingBoard;
        isGameSolved = false;
    }

    bool Model::isSolved() const { 
        return isGameSolved; 
    }

    Model::Cell Model::cellAt(int i) const {
        return isIndexValid(i) ? board[i] : Cell::E;
    }

    char Model::toChar(Cell c) {
        // Converts Cell enums to Text using nested ternary
        // E => '.', L => 'T', R => 'F'
        return c == Cell::E ? '.' : (c == Cell::L ? 'T' : 'F');
    }

    bool Model::tryMove(int i) {
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

        board[i] = Cell::E;
        evaluateBoard();
        return true;
    }

    // --- Private Static Constexpr Helpers ---

    constexpr bool Model::isIndexValid(int k) { 
        return k >= 0 && k < BoardSize; 
    }
    
    constexpr int Model::moveDirection(Cell c) { 
        return (c == Cell::L) ? +1 : -1; 
    }

    // --- Private Instance Helpers ---

    bool Model::isCellEmpty(int k) const { 
        return board[k] == Cell::E;
    }

    void Model::evaluateBoard() {
        isGameSolved = (board == GoalBoard);
    }

} // namespace FrogToad
