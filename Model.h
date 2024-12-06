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
                \details Save model data.
            */
            virtual void Save() = 0;
        private:
    };
}


#endif // MODEL_H
