#include "Event.h"

namespace PlannerCLI {
	Event::Event() {
		EVENT_COUNT++;
		m_nId = EVENT_COUNT;
	}
}