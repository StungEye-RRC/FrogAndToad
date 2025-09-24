#include "raylib_view.hpp"
#include <string>

namespace FrogToad {
	void RaylibView::draw(const FrogToad::Model& m) {
		ClearBackground(RAYWHITE);
	}

	int RaylibView::windowW() const { return 600; }
	int RaylibView::windowH() const { return 300; }
}