#include "ArrayMonth.h"

namespace PlannerCLI::typeB {
	ArrayMonth::ArrayMonth()
	{
		for (int i = 0; i < MAX_MONTH_LENGTH, i++) {
			m_day[i] = ArrayDay();
		}
	}
}
