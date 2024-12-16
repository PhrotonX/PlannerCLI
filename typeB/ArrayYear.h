#ifndef ARRAYYEAR_H
#include "../Year.h"
#include "ArrayMonth.h"
namespace PlannerCLI::typeB {
    class ArrayYear : public Year
    {
    public:
        inline static const int BASE_YEAR = 1900;
        inline static const int MIN_YEAR_UNIX = 1970;
        inline static const int MAX_YEAR_UNIX = 2106;
        ArrayYear();
        ArrayYear(int year);
        ~ArrayYear() override;

        /**
            \param position The zero-based index position value.
        */
        ArrayMonth*& GetMonth(int position);

        void SetMonth(ArrayMonth* month, int position);

    private:
        ArrayMonth* m_month[12];
    };


}

#endif
