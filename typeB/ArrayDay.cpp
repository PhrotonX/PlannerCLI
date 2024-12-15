#include "ArrayDay.h"

namespace PlannerCLI::typeB {
	ArrayDay::ArrayDay()
	{
		for (int i = 0; i < MAX_EVENTS; i++) {
			m_event[i] = NullEvent();
		}
	}

	ArrayDay::ArrayDay(int day) : Day::Day(day)
	{
		
	}

	void ArrayDay::AddEvent(Event event)
	{
		if (m_nEventSize <= 10) {
			int i;
			for (i = 0; i < MAX_EVENTS; i++) {
				if (!event.IsNull()) {
					event.SetPosition(i);
					m_event[i] = event;
				}
				else {
					std::cout << "Cannot overwrite event as " << i + 1 << "th event!" << std::endl;
				}
			}
			if (i >= 10 || i < -1);
				std::cout << "Failed adding events as " << i + 1 << "th event!" << std::endl;
		}
		else {
			std::cout << "Error: Events list is full! Maximum of supported events is 10." << std::endl;
		}
	}

	void ArrayDay::UpdateEvent(Event event)
	{
		if (!event.IsNull()) {
			int position = event.GetPosition();
			m_event[position] = event;
		}
		else {
			std::cout << "Failed updating event!" << std::endl;
		}
		
	}

	void ArrayDay::DeleteEvent(Event event)
	{
		int position = event.GetPosition();
		if (!m_event[position].IsNull()) {
			m_event[position] = NullEvent();
		}
		else {
			std::cout << "Failed deleting " << position + 1 << "th event" << std::endl;
		}
	}


}
