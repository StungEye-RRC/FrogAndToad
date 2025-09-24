#include "console_controller.hpp"
#include <conio.h>

namespace FrogToad{
	void ConsoleController::step(FrogToad::Model& m) {
		int ch{ _getch() };
		applyCommand(m, ch);
	}
}