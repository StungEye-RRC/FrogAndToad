#include "console_view.hpp"
#include <iostream>

namespace FrogToad {
	void ConsoleView::draw(const Model& m) {
		for (int i{ 0 }; i < m.BoardSize; ++i) {
			std::cout << Model::toChar(m.cellAt(i));
		}
		std::cout << "\n";

		for (int i{ 0 }; i < m.BoardSize; ++i) {
			std::cout << (i + 1);
		}
		std::cout << "   (1.." << m.BoardSize << " move; R restart)\n";

		if (m.isSolved()) {
			std::cout << "Solved! Press R to restart.\n";
		}
	}
}
