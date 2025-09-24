#pragma once
#include "interfaces.hpp"

namespace FrogToad {
	struct ConsoleController : FrogToad::IController {
		void step(FrogToad::Model& m) override; 
	};
}
