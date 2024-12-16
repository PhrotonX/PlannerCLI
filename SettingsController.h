#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <conio.h>
#include "Controller.h"
#include "SettingsView.h"

namespace PlannerCLI {
	class SettingsController : public Controller
	{
	public:
		SettingsController();
		~SettingsController() override;

		void Index() override;
		void HandleInput() override;

		void Load() override;
		void Store() override;

	private:
		SettingsView* m_pSettingsView;
	};
}


#endif //SETTINGSCONTROLLER_H

