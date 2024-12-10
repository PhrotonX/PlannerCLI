#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <conio.h>

#define KEY_SCAN_CODE 0
#define KEY_SCAN_CODE_2 224
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

namespace PlannerCLI{
    /**
        \brief Mediator between View and Model. Takes input from View,
        modifies it with Model, and sends back data to View.

        For instance, a user enters his name on a View control. The data
        shall be sent from View into the Model through the Controller.
        The resulting data shall be sent back into the View (e.g. error
        messages like "Invalid username! (username here)."
    */
    class Controller
    {
        public:
            Controller();
            virtual ~Controller();

            /**
                \brief Handle code for user input.
            */
            virtual void HandleInput() = 0;

            virtual void Create() = 0;

            /**
                \brief Handle the homescreen which consists of options.
            */
            virtual void Index() = 0;

            /**
                \brief Store general information from the View into the Model.

            */
            virtual void Store() = 0;
            virtual void Update() = 0;
            virtual void Delete() = 0;
    };
}


#endif // CONTROLLER_H
