#include "MessageBoxView.h"

namespace PlannerCLI {
	MessageBoxView::MessageBoxView(const std::string& title, const std::string& description)
	{
		m_strTitle = title;
		m_strDescription = description;
	}

	bool MessageBoxView::Show()
	{
		bool run = true;

		do {
			CLEAR_SCREEN;

			DrawTopBorder();
			DrawText(m_strTitle);
			DrawConnectingBorder();

			DrawText(m_strDescription);

			DrawConnectingBorder();

			SetColor(ANSI_BACKGROUND_COLOR_BLUE, ANSI_TEXT_COLOR_BRIGHT_WHITE);
			DrawText("[  OK  ]");
			SetColorDefaults();

			DrawBottomBorder();

			switch (_getch()) {
			default:
				run = false;
				return true;
			}
		} while (run);
		
	}
}

