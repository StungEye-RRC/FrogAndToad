#include "raylib_controller.hpp"
#include "raylib.h"

namespace FrogToad {
	void RaylibController::step(FrogToad::Model& m) {
		if (IsKeyPressed(KEY_R))       applyCommand(m, 'R');
		if (IsKeyPressed(KEY_ONE))     applyCommand(m, '1');
		if (IsKeyPressed(KEY_TWO))     applyCommand(m, '2');
		if (IsKeyPressed(KEY_THREE))   applyCommand(m, '3');
		if (IsKeyPressed(KEY_FOUR))    applyCommand(m, '4');
		if (IsKeyPressed(KEY_FIVE))    applyCommand(m, '5');
		if (IsKeyPressed(KEY_SIX))     applyCommand(m, '6');
		if (IsKeyPressed(KEY_SEVEN))   applyCommand(m, '7');
	}
}