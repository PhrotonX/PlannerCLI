#include "ArrayMonth.h"

namespace PlannerCLI::typeB {
	ArrayMonth::ArrayMonth()
	{
		for (int i = 0; i < MAX_MONTH_LENGTH; i++) {
			m_day[i] = ArrayDay();
		}
	}

	ArrayMonth::ArrayMonth(int month) : Month::Month(month)
	{
		
	}
	ArrayMonth::~ArrayMonth()
	{
		
	}
	void ArrayMonth::UpdateDay(ArrayDay day)
	{
		int position = day.GetValue() - 1;
		m_day[position] = day;
	}
}
