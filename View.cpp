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
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        std::cout << "É";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "Í";
        }
        std::cout << "»" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawBottomBorder()
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        std::cout << "È";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "Í";
        }
        std::cout << "¼" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawConnectingBorder()
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        std::cout << "Ì";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "Í";
        }
        std::cout << "¹" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawHeading(const std::string& heading)
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        int margin = ((APP_WIDTH - PADDING) - heading.size()) - 1;

        std::cout << "º " << heading;
        for (int i = 0; i < margin; i++) {
            std::cout << " ";
        }
        std::cout << "º" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawText(const std::string& text)
    {
        DrawHeading(text);
    }

    void View::DrawDoubleLine() {
        for (int i = 0; i < APP_WIDTH; i++) {
            std::cout << "Í";
        }
        std::cout << std::endl;
    }

    
}

