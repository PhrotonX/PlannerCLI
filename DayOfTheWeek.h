#ifndef DAYOFTHEWEEK_H
#define DAYOFTHEWEEK_H
#include <string>

namespace PlannerCLI{
	class DayOfTheWeek
	{
    public:
        enum eDayOfTheWeek {
            Sunday,
            Monday,
            Tuesday,
            Wednesday,
            Thursday,
            Friday,
            Saturday
        };

        /**
                \details Calculates the day of the week through Zeller's Congruence.
                \param year 1-based year value.
                \param year 1-based month value.
                \param year 1-based day value.
                \return The day of the week (0 = Saturday, 6 = Friday).
            */
        static int CalculateDayOfTheWeek(int year, int month, int day);

        void SetValue(eDayOfTheWeek dayOfTheWeek) {
            m_dayOfTheWeek = dayOfTheWeek;
        }

        /**
            \brief Set the day of the week.
            \param dayOfTheWeek Set 0 for Sunday and 6 for Saturday.
        */
        void SetValue(int dayOfTheWeek);

        /**
            \brief Sets the day of the week based on Zeller's Congruence Algorithm
            from Date::CalculateDayOfTheWeek().
            \param dayOfTheWeek Set 0 for Saturday and 6 for Friday.
        */
        void SetValueZC(int dayOfTheWeek);

        eDayOfTheWeek GetValue() {
            return m_dayOfTheWeek;
        }

        /**
            \return Returns 0 for Sunday, 6 for Saturday, and -1 if not available.
        */
        int GetValueN();

        std::string GetName();

    private:
        eDayOfTheWeek m_dayOfTheWeek;
	};

    
}

#endif // DAYOFTHEWEEK_H




