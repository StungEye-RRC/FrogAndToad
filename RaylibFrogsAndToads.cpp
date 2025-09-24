#include <array>
#include <string>
#include "model.hpp"

#define RAYLIB_BUILD 

#ifdef RAYLIB_BUILD
	#include "raylib.h"
    #include "raylib_controller.hpp"
	#include "raylib_view.hpp"
#else
	#include <iostream>
	#include <conio.h>
	#include "console_controller.hpp"
	#include "console_view.hpp"
	#include "ansi_view.hpp"
#endif

#ifndef RAYLIB_BUILD
int main() {
    FrogToad::Model model;
    FrogToad::ConsoleView view;
    FrogToad::ConsoleController ctrl;

    std::cout << "Toads & Frogs - Console\n\n";

    while (true) {
        view.draw(model);
        ctrl.step(model);
        std::cout << "\n";
    }
    std::cout << "Goodbye!\n";
    return 0;
}
#else
int main() {
    FrogToad::Model model;
    FrogToad::RaylibView view;
    FrogToad::RaylibController ctrl;

    InitWindow(view.windowW(), view.windowH(), "Toads & Frogs - Raylib");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ctrl.step(model);
        BeginDrawing();
        view.draw(model);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
#endif
