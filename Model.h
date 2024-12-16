#ifndef MODEL_H
#define MODEL_H

namespace PlannerCLI{
    /**
        \brief Handles the data logic.
    */
    class Model
    {
        public:
            Model();
            virtual ~Model();

            /**
                \brief Load information from a file.
            */
            virtual void Load() = 0;

            /**
                \details Save information into a file.
            */
            virtual void Save() = 0;
        private:
    };
}


#endif // MODEL_H
