#ifndef ARRAYYEAR_H
#include "../Year.h"
#include "ArrayMonth.h"
namespace PlannerCLI::typeB {
    class ArrayYear : public Year
    {
    public:
        ArrayYear();
        ArrayYear(int year);
        ~ArrayYear() override;

        ArrayMonth& GetMonth(int position);

        void SetMonth(ArrayMonth month, int position);

    private:
        ArrayMonth m_month[12];
    };


}

#endif
