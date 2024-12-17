#include "SettingsController.h"

namespace PlannerCLI {
	SettingsController::SettingsController()
	{
		m_pSettingsView = new SettingsView();
	}

	SettingsController::~SettingsController()
	{
		if (m_pSettingsView != nullptr) delete m_pSettingsView;
		m_pSettingsView = nullptr;
	}

	void SettingsController::Index()
	{
		HandleInput();
	}

	void SettingsController::HandleInput() {
		bool run = true;

		int navigation = 0;
		int settingNavigation = 0;
		
		do {

			m_pSettingsView->Display(&navigation, &settingNavigation);

			switch (_getch()) {
			case KEY_ENTER:
				switch (navigation) {
					case SettingsView::BACK_BUTTON:
						run = false;
						break;
					case SettingsView::EDIT_BUTTON:
						switch (settingNavigation) {
							case SettingsView::DEBUG_MODE:
								Settings::ToggleDebugMode();
								break;
							case SettingsView::ARRAY_CALENDAR:
								Settings::ToggleArrayCalendar();
								break;
							default:
								break;
						}
						break;
					default:
						break;
				}
				break;
			case KEY_ESC:
				run = false;
				break;
			case KEY_SCAN_CODE_2:
				switch (_getch()) {
				case KEY_UP:
					if (navigation == SettingsView::EDIT_BUTTON) {
						settingNavigation--;
					
						if (settingNavigation < 0)
							settingNavigation = 0;
					}
					
					break;
				case KEY_DOWN:
					if (navigation == SettingsView::EDIT_BUTTON) {
						settingNavigation++;

						if (settingNavigation > SettingsView::BUTTON_COUNT - 1)
							settingNavigation = SettingsView::BUTTON_COUNT - 1;
					}
					
					break;
				case KEY_LEFT:
					navigation--;

					if (navigation < 0)
						navigation = 0;
					break;
				case KEY_RIGHT:
					navigation++;

					if (navigation > SettingsView::BUTTON_COUNT - 1)
						navigation = SettingsView::BUTTON_COUNT - 1;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		} while (run);
	}
	void SettingsController::Load()
	{
	}
	void SettingsController::Store()
	{
	}
}