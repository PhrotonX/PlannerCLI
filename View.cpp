#include "View.h"

namespace PlannerCLI{
    View::View()
    {
        //ctor
    }

    View::~View()
    {
        //dtor
    }

    void View::DrawTopBorder() {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE;
        std::cout << ANSI_TEXT_COLOR_BLACK;

        std::cout << "É";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "Í";
        }
        std::cout << "»" << ANSI_COLOR_RESET << std::endl;
    }
}

