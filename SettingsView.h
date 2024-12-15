#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include "View.h"
#include "Button.h"
#include "Settings.h"

namespace PlannerCLI {
	class SettingsView : public View
	{
	public:
		inline static const int DEBUG_MODE = 0;
		inline static const int ARRAY_CALENDAR = 1;
		inline static const int SETTINGS_BUTTON_COUNT = 2;

		inline static const int BACK_BUTTON = 0;
		inline static const int EDIT_BUTTON = 1;
		inline static const int BUTTON_COUNT = 2;

		SettingsView();
		~SettingsView() override;

		void Display(int* navigation, int* settingNavigation);

		void DisplayHelpInfo() override;

	private:
		Button* m_button[BUTTON_COUNT];
		Button* m_settingsButton[SETTINGS_BUTTON_COUNT];
	};
}


#endif //SETTINGSVIEW_H

