#ifndef VIEW_H
#define VIEW_H
#include <iostream>

namespace PlannerCLI{
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
