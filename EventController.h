#ifndef EVENTcONTROLLER_H
#define EVENTcONTROLLER_H
#include "Controller.h"
#include "Event.h"

namespace PlannerCLI {
    class EventController : public Controller
    {
        // Inherited via Controller
        void HandleInput() override;
        void Create() override;
        void Index() override;
        void Store() override;
        void Update() override;
        void Delete() override;
    };


}

#endif //EVENTcONTROLLER_H