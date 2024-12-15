#include "ArrayYear.h"

namespace PlannerCLI::typeB {
	ArrayYear::ArrayYear()
	{
	}
	
	ArrayYear::ArrayYear(int year) : Year::Year(year) {

	}

	ArrayYear::~ArrayYear()
	{
	}
	ArrayMonth*& ArrayYear::GetMonth(int position)
	{
		return m_month[position];
	}
	void ArrayYear::SetMonth(ArrayMonth* month, int position)
	{
		m_month[position] = month;
	}
}