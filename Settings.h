#ifndef SETTINGS_H
#define SETTINGS_H

#include "Model.h"

namespace PlannerCLI {
	class Settings : public Model
	{
	public:
		inline static bool DebugMode = false;
		inline static bool ArrayCalendar = false;

		Settings() {}
		~Settings() override {}

		static void ToggleDebugMode();

		static void ToggleArrayCalendar();

		void Load() override;

		void Save() override;

		

		
	};
}

#endif //SETTINGS_H