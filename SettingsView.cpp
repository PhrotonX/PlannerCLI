#include "SettingsView.h"

namespace PlannerCLI {
	SettingsView::SettingsView()
	{
	}

	SettingsView::~SettingsView()
	{
	}

	void SettingsView::Display(int* navigation, int* settingNavigation) {
		CLEAR_SCREEN;

		if(Settings::DebugMode)
			std::cout << "SettingsView::Display(): " << *navigation << " " << *settingNavigation << std::endl;

		DrawTopBorder();
		DrawHeading("Settings");
		DrawBottomBorder();

		for (int i = 0; i < BUTTON_COUNT; i++) {
			m_button[i] = new Button(navigation, i);
		}
		for (int i = 0; i < SETTINGS_BUTTON_COUNT; i++) {
			m_settingsButton[i] = new Button(settingNavigation, i);
		}

		std::string strDbgMode = std::to_string(Settings::DebugMode);
		std::string strArrCal = std::to_string(Settings::ArrayCalendar);

		m_settingsButton[DEBUG_MODE]->SetText(" ["+ strDbgMode + "] Debug Mode");
		m_settingsButton[ARRAY_CALENDAR]->SetText(" ["+ strArrCal +"] Use Array Calendar");
		m_button[BACK_BUTTON]->SetText("[ BACK ]");
		m_button[EDIT_BUTTON]->SetText("[ EDIT ]");

		for (int i = 0; i < SETTINGS_BUTTON_COUNT; i++){
			m_settingsButton[i]->Display(true);
		}

		m_button[BACK_BUTTON]->Display();
		std::cout << " ";
		m_button[EDIT_BUTTON]->Display(true);

		DrawDoubleLine();

		for (int i = 0; i < BUTTON_COUNT; i++) {
			if (m_button[i] != nullptr) delete m_button[i];
			m_button[i] = nullptr;
		}
		for (int i = 0; i < SETTINGS_BUTTON_COUNT; i++) {
			if (m_settingsButton[i] != nullptr) delete m_settingsButton[i];
			m_settingsButton[i] = nullptr;
		}

		DisplayHelpInfo();
	}

	void SettingsView::DisplayHelpInfo()
	{
		DrawSingleLine();
		std::cout << "^v Setting Nav.\t\tEnter - OK/Toggle" << std::endl;
		std::cout << "<> Navigation\t\Esc - Back" << std::endl;
	}
}