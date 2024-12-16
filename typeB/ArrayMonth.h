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
		ArrayMonth(int month);
		~ArrayMonth() override;

		/**
			\brief Returns a reference to a day object.
			\param day The zero-based index value.
		*/
		ArrayDay& GetDay(int day) {
			return m_day[day];
		}

		void UpdateDay(ArrayDay day);

	private:
		ArrayDay m_day[31];
	};
}

#endif //ARRAYMONTH_H


