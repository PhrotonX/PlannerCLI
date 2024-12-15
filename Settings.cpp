#include "Settings.h"

namespace PlannerCLI {
	void Settings::ToggleDebugMode()
	{
		DebugMode = !DebugMode;
	}

	void Settings::ToggleArrayCalendar()
	{
		ArrayCalendar = !ArrayCalendar;
	}


}