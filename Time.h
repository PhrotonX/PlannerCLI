#ifndef TIME_H
#define TIME_H
#include <string>

namespace PlannerCLI {
	class Time
	{
	public:
		Time();
		Time(const int& hours, const int& minutes);

		int GetHours() const {
			return m_nHours;
		}

		int GetMinutes() const {
			return m_nMinutes;
		}

		std::string GetString() const;

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


