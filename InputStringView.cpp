#include "InputStringView.h"

namespace PlannerCLI {
	InputStringView::InputStringView(const std::string& title, const std::string& hint)
	{
		m_strTitle = title;
		m_strHint = hint;
	}

	std::string InputStringView::Show()
	{
		CLEAR_SCREEN;

		DrawTopBorder();
		DrawHeading(m_strTitle);
		DrawBottomBorder();

		std::cout << "\n" << m_strHint;

		std::string query;
		std::getline(std::cin, query);
		std::cin.ignore();

		return query;
	}

}
