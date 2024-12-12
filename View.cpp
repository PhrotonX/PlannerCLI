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

        std::cout << "�";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "�";
        }
        std::cout << "�" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawBottomBorder()
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        std::cout << "�";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "�";
        }
        std::cout << "�" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawConnectingBorder()
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        std::cout << "�";
        for (int i = 0; i < (APP_WIDTH - PADDING); i++) {
            std::cout << "�";
        }
        std::cout << "�" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawHeading(const std::string& heading)
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;

        int margin = ((APP_WIDTH - PADDING) - heading.size()) - 1;

        std::cout << "� " << heading;
        for (int i = 0; i < margin; i++) {
            std::cout << " ";
        }
        std::cout << "�" << ANSI_COLOR_RESET << std::endl;
    }

    void View::DrawText(const std::string& text)
    {
        DrawHeading(text);
    }

    void View::DrawDoubleLine() {
        for (int i = 0; i < APP_WIDTH; i++) {
            std::cout << "�";
        }
        std::cout << std::endl;
    }

    
}

