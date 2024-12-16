#ifndef MODEL_H
#define MODEL_H

#include <fstream>
#include <string>

namespace PlannerCLI{
    /**
        \brief Handles the data logic.
    */
    class Model
    {
        public:
            inline static const std::string FILE_BREAK_LINE = "\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00";
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
