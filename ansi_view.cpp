#include "ansi_view.hpp"
#include <iostream>

namespace FrogToad {
	AnsiView::AnsiView() {
		// Clear screen once and hide cursor
		std::cout << "\x1b[2J\x1b[H\x1b[?25l";
		std::cout.flush();
	}
	AnsiView::~AnsiView() {
		// Reset attributes and show cursor on exit
		std::cout << "\x1b[0m\x1b[?25h\n";
		std::cout.flush();
	}

	void AnsiView::draw(const BoardModel& m) {
		// Move cursor to top-left
		std::cout << "\x1b[H";

		std::cout << bold() << "Toads & Frogs (7-square)\n" << reset();
		std::cout << dim() << "1.." << m.BoardSize << " = move index   R = restart\n\n" << reset();

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
				std::cout << dim();
			}

			std::cout << piece << ' ' << reset();
		}
		std::cout << '\n';

		// Index row (1..7), dimmed
		std::cout << dim();
		for (int i = 1; i <= m.BoardSize; ++i) {
			std::cout << i << ' ';
		}
		std::cout << reset() << "\n\n";

		// Status line
		if (m.isSolved()) {
			std::cout << green() << "Solved! R to restart." << reset() << "\x1b[K\n";
		}
		else {
			std::cout << dim() << "Choose a piece to move." << reset() << "\x1b[K\n";
		}

		// If previous frame printed longer lines, clear the rest of the screen area
		std::cout << "\x1b[0J";
		std::cout.flush();
	}
 }
