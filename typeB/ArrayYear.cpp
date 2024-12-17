#include "ArrayYear.h"

namespace PlannerCLI::typeB {
	ArrayYear::ArrayYear()
	{
	}
	
	ArrayYear::ArrayYear(int year) : Year::Year(year) {

	}

	ArrayYear::~ArrayYear()
	{
		for (int month = 0; month < ArrayMonth::MONTHS; month++) {
			if (m_month[month] != nullptr) {
				delete m_month[month];
				m_month[month] = nullptr;
			}
		}
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