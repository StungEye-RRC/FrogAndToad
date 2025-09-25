#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	struct ConsoleController : IController {
		void nextMove(BoardModel& m) override; 
	};
}
