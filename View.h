#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "FORMAT.h"
#include "Color.h"

namespace PlannerCLI{
    /**
        \brief Handles the command-line line logic.
    */
    class View
    {
        public:
            View();
            virtual ~View();

            void Display() {}

        protected:
            inline static const int APP_WIDTH = 50;
            inline static const int BORDER_HORIZONTAL_SPACE = 2;
            inline static const int INDENT_WIDTH = 2;
            inline static const int PADDING_RIGHT = 1;
            inline static const int PADDING = 2;

            inline static const int CONTENT_WIDTH = APP_WIDTH - (PADDING - BORDER_HORIZONTAL_SPACE);


            inline static const std::string TAB = "\t";
            inline static const std::string BULLET = "ù";

                
            void DrawDoubleLine();
            void DrawBottomBorder();
            void DrawConnectingBorder();
            void DrawTopBorder();
            void DrawHeading(const std::string& heading);
            void DrawSingleLine();
            void DrawText(const std::string& text);

            void SetColor(const Color& color) {
                m_color = color;
            }

            void SetColor(const std::string& background, const std::string& foreground);

            void SetColorDefaults();

        private:
            Color m_color;
    };
}


#endif // VIEW_H
