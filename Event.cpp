#include "Event.h"

namespace PlannerCLI {
	Event::Event() {
		EVENT_COUNT++;
		m_nId = EVENT_COUNT;

		m_timeBegin = Time(0, 0);
		m_timeEnd = Time(23, 59);
	}
}