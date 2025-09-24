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

	void AnsiView::draw(const FrogToad::Model& m) {
		// Move cursor to top-left; redraw the whole panel in-place
		std::cout << "\x1b[H";

		// Title / instructions
		std::cout << bold() << "Toads & Frogs (7-square)\n" << reset();
		std::cout << dim() << "1..7 = move index   R = restart\n\n" << reset();

		// Board row (colored pieces)
		for (int i = 0; i < 7; ++i) {
			const auto c = m.cellAt(i);
			const auto piece{ FrogToad::Model::toChar(c) };
			if (c == FrogToad::Model::Cell::L) {
				std::cout << blue();
			}
			else if (c == FrogToad::Model::Cell::R) {
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
		for (int i = 1; i <= 7; ++i) {
			std::cout << i << (i < 7 ? ' ' : '\n');
		}
		std::cout << reset() << '\n';

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
