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

            virtual void Display() = 0;


        protected:
            inline static const int APP_WIDTH = 50;
            inline static const int PADDING_RIGHT = 1;
            inline static const int PADDING = 2;

        private:
    };
}


#endif // VIEW_H
