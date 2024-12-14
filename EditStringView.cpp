#include "EditStringView.h"

namespace PlannerCLI {
	EditStringView::EditStringView(const std::string& title, const std::string& data)
	{
		m_strData = data;
		m_strTitle = title;
	}
	std::string EditStringView::Show()
	{
		CLEAR_SCREEN;

		DrawTopBorder();
		DrawHeading("Edit " + m_strTitle);
		DrawBottomBorder();

		std::cout << "Old: " << m_strData << std::endl;
		DrawDoubleLine();
		std::cout << "New: ";

		std::string newString;
		std::getline(std::cin, newString);
		std::cin.ignore();

		return newString;
	}
}