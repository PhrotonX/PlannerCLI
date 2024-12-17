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

	void Settings::Load()
	{
	}

	void Settings::Save()
	{
	}

}