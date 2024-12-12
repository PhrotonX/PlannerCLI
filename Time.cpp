#include "Time.h"

namespace PlannerCLI {
	Time::Time()
	{
		m_nHours = 0;
		m_nMinutes = 0;
	}

	Time::Time(const int& hours, const int& minutes) {
		m_nHours = hours;
		m_nMinutes = minutes;
	}

	std::string Time::GetString() const {
		return AddLeadingZero(m_nHours) + ":" + AddLeadingZero(m_nMinutes);
	}

	std::string Time::AddLeadingZero(int value)
	{
		std::string strValue = std::to_string(value);

		if (value < 10) {
			strValue = "0" + strValue;
		}

		return strValue;
	}
}