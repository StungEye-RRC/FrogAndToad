#include "console_view.hpp"
#include <iostream>

namespace FrogToad {
	void ConsoleView::draw(const FrogToad::Model& m) {
		for (int i{ 0 }; i < 7; ++i) {
			std::cout << FrogToad::Model::toChar(m.cellAt(i));
		}
		std::cout << "\n";

		for (int i{ 0 }; i < 7; ++i) {
			std::cout << (i + 1);
		}
		std::cout << "   (1..7 move; R restart)\n";

		if (m.isSolved()) {
			std::cout << "Solved! Press R to restart.\n";
		}
	}
}
