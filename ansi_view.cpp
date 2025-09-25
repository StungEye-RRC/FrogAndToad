#include "ansi_view.hpp"
#include <iostream>

namespace FrogToad {
	AnsiView::AnsiView() {
		// Clear screen once and hide cursor
		std::cout << clearScreen() << cursorHome() << hideCursor();
	}
	AnsiView::~AnsiView() {
		// Reset attributes and show cursor on exit
		std::cout << resetStyles() << showCursor();
	}

	void AnsiView::draw(const BoardModel& m) {
		// Move cursor to top-left
		std::cout << cursorHome() << resetStyles();

		std::cout << white() << "Toads & Frogs" << eraseAfter() << "\n";
		std::cout << grey() << "1.." << m.BoardSize << " = move index   R = restart\n\n" << resetStyles();

		// Board row 
		for (int i = 0; i < m.BoardSize; ++i) {
			const auto c = m.cellAt(i);
			const auto piece{ BoardModel::toChar(c) };
			if (c == BoardModel::Cell::Frog) {
				std::cout << blue();
			}
			else if (c == BoardModel::Cell::Toad) {
				std::cout << red();
			}
			else {
				std::cout << grey();
			}

			std::cout << piece << ' ' << resetStyles();
		}
		std::cout << '\n';

		// Index row (1..7), dimmed
		std::cout << grey();
		for (int i = 1; i <= m.BoardSize; ++i) {
			std::cout << i << ' ';
		}
		std::cout << resetStyles() << "\n\n";

		// Status line
		if (m.isSolved()) {
			std::cout << bell() << green() << "Solved! R to restart." << resetStyles() << "\x1b[K\n";
		}
		else {
			std::cout << grey() << "Choose a piece to move." << resetStyles() << "\x1b[K\n";
		}

		// If previous frame printed longer lines, clear the rest of the screen area
		std::cout << eraseAfter();
		std::cout.flush();
	}
 }
