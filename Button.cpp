#include "Button.h"

namespace PlannerCLI {
	Button::Button(int* navigationValue, int value)
	{
		m_nNavigationValue = navigationValue;
		m_nValue = value;

		SetActiveColor(ANSI_BACKGROUND_COLOR_BLUE, ANSI_TEXT_COLOR_BRIGHT_WHITE);
		SetInactiveColor(ANSI_BACKGROUND_BRIGHT_COLOR_WHITE, ANSI_TEXT_COLOR_BLACK);
	}

	void Button::Display(bool endline)
	{
		if (*m_nNavigationValue == m_nValue) {
			std::cout << m_strActiveColorBg << m_strActiveColorFg;
		}
		else {
			std::cout << m_strInactiveColorBg << m_strInactiveColorFg;
		}

		std::cout << m_strText << ANSI_COLOR_RESET;

		if (endline)
			std::cout << std::endl;
	}

}
