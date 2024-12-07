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

        private:
    };
}


#endif // VIEW_H
