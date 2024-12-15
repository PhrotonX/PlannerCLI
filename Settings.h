#ifndef SETTINGS_H
#define SETTINGS_H

#include "Model.h"

namespace PlannerCLI {
	class Settings : public Model
	{
	public:
		Settings() {}
		~Settings() override {}

		void Save() override {}

		static void ToggleDebugMode();

		static void ToggleArrayCalendar();

		inline static bool DebugMode = false;
		inline static bool ArrayCalendar = false;
	};
}

#endif //SETTINGS_H