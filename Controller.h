#ifndef CONTROLLER_H
#define CONTROLLER_H

namespace PlannerCLI{
    class Controller
    {
        public:
            Controller();
            virtual ~Controller();


            virtual void Create() = 0;

            /**
                \brief Handle the homescreen which consists of options.
            */
            virtual void Index() = 0;

            /**
                \brief Store general information
            */
            virtual void Store() = 0;
            virtual void Update() = 0;
            virtual void Delete() = 0;
    };
}


#endif // CONTROLLER_H
