#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	struct ConsoleController : IController {
		void step(BoardModel& m) override; 
	};
}
