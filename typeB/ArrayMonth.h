#ifndef ARRAYMONTH_H
#define ARRAYMONTH_H

#include "../Month.h";
#include "ArrayDay.h"

namespace PlannerCLI::typeB {
	class ArrayMonth : public Month
	{
	public:
		inline static const int BASE_YEAR = 1900;
		inline static const int MAX_MONTH_LENGTH = 31;

		ArrayMonth();
		ArrayMonth(int month);
		~ArrayMonth() override {}

		/**
			\brief Returns a reference to a day object.
			\param day The zero-based index value.
		*/
		Day& GetDay(int day) {
			return m_day[day];
		}

		int GetMonthLength() const {
			return m_nMonthLength;
		}

		void SetMonthLength(const int& length) {
			m_nMonthLength = length;
		}

		void UpdateDay(ArrayDay day);

	private:
		ArrayDay m_day[31];
		int m_nMonthLength;
	};
}

#endif //ARRAYMONTH_H


