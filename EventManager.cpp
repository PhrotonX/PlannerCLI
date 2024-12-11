#include "EventManager.h"

namespace PlannerCLI {

	void EventManager::AddEvent(Event event, Date date)
	{
		std::string id = date.GetString();

		m_event[id].Add(event);
	}

	Event EventManager::GetEvent(Date date, size_t position)
	{
		std::string id = date.GetString();

		return m_event[id][position];
	}

	void EventManager::RemoveEvent(size_t position, Date date)
	{
		std::string id = date.GetString();

		m_event[id].Remove(position);
	}

	void EventManager::UpdateEvent(Event event, Date date, size_t position)
	{
		std::string id = date.GetString();

		m_event[id][position] = event;
	}
}