#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	struct ConsoleController : IController {
		void step(Model& m) override; 
	};
}
