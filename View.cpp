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
        //m_color.Display();
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

    void View::DrawSingleLine()
    {
        //m_color.Display();

        for (int i = 0; i < APP_WIDTH; i++) {
            std::cout << "Ä";
        }
        std::cout << std::endl;
    }

    void View::DrawText(const std::string& text)
    {
        std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;
        

        int margin = ((APP_WIDTH - PADDING) - text.size()) - 1;

        std::cout << "º " << m_color.GetBackgroundColor() << m_color.GetForegroundColor() << text
                  << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK;
        for (int i = 0; i < margin; i++) {
            std::cout << " ";
        }
        std::cout << "º" << ANSI_COLOR_RESET << std::endl;
    }

    void View::SetColor(const std::string& background, const std::string& foreground)
    {
        m_color.SetBackgroundColor(background);
        m_color.SetForegroundColor(foreground);
    }

    void View::SetColorDefaults()
    {
        m_color.SetBackgroundColor(ANSI_BACKGROUND_BRIGHT_COLOR_WHITE);
        m_color.SetForegroundColor(ANSI_TEXT_COLOR_BLACK);
    }

    void View::DrawDoubleLine() {
        for (int i = 0; i < APP_WIDTH; i++) {
            std::cout << "Í";
        }
        std::cout << std::endl;
    }

    
}

