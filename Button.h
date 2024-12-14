#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <string>
#include "FORMAT.h"

namespace PlannerCLI {
	class Button
	{
	public:
		Button(int* navigationValue, int value);
		virtual ~Button(){}

		void Display(bool endline = false);

		void SetActiveColor(const std::string& background, const std::string& foreground) {
			m_strActiveColorBg = background;
			m_strActiveColorFg = foreground;
		}

		void SetInactiveColor(const std::string& background, const std::string& foreground) {
			m_strInactiveColorBg = background;
			m_strInactiveColorFg = foreground;
		}

		void SetText(const std::string& value) {
			m_strText = value;
		}
		
	private:
		int* m_nNavigationValue;
		int m_nValue;
		std::string m_strText;
		std::string m_strActiveColorBg;
		std::string m_strActiveColorFg;
		std::string m_strInactiveColorBg;
		std::string m_strInactiveColorFg;
	};
}

#endif //BUTTON_H

