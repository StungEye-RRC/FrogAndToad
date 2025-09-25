#pragma once
#include "interfaces.hpp"

namespace FrogToad {
    struct AnsiView : IView {
	AnsiView();
	~AnsiView();

	void draw(const Model& m) override;

    private:
        // Simple ANSI helpers
        static const char* reset() { return "\x1b[0m"; }
        static const char* bold() { return "\x1b[1m"; }
        static const char* dim() { return "\x1b[37m"; }
        static const char* red() { return "\x1b[38;5;196m"; }  // bright red
        static const char* blue() { return "\x1b[38;5;33m"; }   // deep blue
        static const char* green() { return "\x1b[38;5;34m"; }   // status
    };
}

