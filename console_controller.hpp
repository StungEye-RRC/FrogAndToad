#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	class ConsoleController : IController {
	public:
		void nextMove(BoardModel& m) override; 
	};
}
