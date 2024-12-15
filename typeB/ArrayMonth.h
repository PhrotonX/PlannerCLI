#ifndef ARRAYMONTH_H
#define ARRAYMONTH_H

#include "../Month.h";
#include "ArrayDay.h"

namespace PlannerCLI::typeB {
	class ArrayMonth : public Month
	{
	public:

		inline static const int MAX_MONTH_LENGTH = 31;

		ArrayMonth();
		~ArrayMonth() override {}

	private:
		ArrayDay m_day[31];
		int m_nMonthLength;
	};
}

#endif //ARRAYMONTH_H


