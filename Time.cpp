#include "Time.h"

namespace PlannerCLI {
	Time::Time(const int& hours, const int& minutes) {
		m_nHours = hours;
		m_nMinutes = minutes;
	}

	std::string Time::GetString() const {
		std::string timeMinutes = std::to_string(m_nMinutes);
		std::string timeHours = std::to_string(m_nHours);

		if (m_nHours < 10) {
			timeHours = "0" + timeHours;
		}
		if (m_nMinutes < 10) {
			timeMinutes = "0" + timeMinutes;
		}

		return timeHours + ":" + timeMinutes;
	}
}