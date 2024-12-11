#ifndef VIEW_H
#define VIEW_H
#include <iostream>
#include "FORMAT.h"

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
            inline static const int PADDING_RIGHT = 1;
            inline static const int PADDING = 2;
                
            void DrawDoubleLine();
            void DrawBottomBorder();
            void DrawTopBorder();
            void DrawHeading(const std::string& heading);

        private:
    };
}


#endif // VIEW_H
