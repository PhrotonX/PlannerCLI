#ifndef TIME_H
#define TIME_H
#include <string>

namespace PlannerCLI {
	class Time
	{
	public:
		Time(const int& hours, const int& minutes) {
			m_nHours = hours;
			m_nMinutes = minutes;
		}

		int GetHours() const {
			return m_nHours;
		}

		int GetMinutes() const {
			return m_nMinutes;
		}

		std::string GetString() const {
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

		void SetHours(const int& hours) {
			m_nHours = hours;
		}

		void SetMinutes(const int& minutes) {
			m_nMinutes = minutes;
		}

	private:
		int m_nHours;
		int m_nMinutes;
	};
}
#endif //TIME_H


