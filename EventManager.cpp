#include "EventManager.h"

namespace PlannerCLI {

	void EventManager::AddEvent(Event event, Date date)
	{
		std::string id = date.GetString();

		m_event[id].push_back(event);
	}

	Event& EventManager::GetEvent(Date date, size_t position)
	{
		std::string id = date.GetString();

		return m_event[id].at(position);
	}

	std::vector<Event>& EventManager::GetEventList(Date date)
	{
		std::string id = date.GetString();

		return m_event[id];
	}

	void EventManager::RemoveEvent(size_t position, Date date)
	{
		std::string id = date.GetString();

		m_event[id].erase(m_event[id].begin() + position);
	}

	void EventManager::UpdateEvent(Event event, Date date, size_t position)
	{
		std::string id = date.GetString();

		m_event[id].at(position) = event;
	}
}