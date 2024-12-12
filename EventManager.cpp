#include "EventManager.h"

namespace PlannerCLI {

	void EventManager::AddEvent(Event event, Date date)
	{
		std::string id = date.GetString();

		if (m_event[id] == nullptr) {
			m_event[id] = new List<Event>();
		}
		m_event[id]->Add(event);
	}

	Event& EventManager::GetEvent(Date date, size_t position)
	{
		std::string id = date.GetString();

		return m_event[id]->At(position);
	}

	List<Event>*& EventManager::GetEventList(Date date)
	{
		std::string id = date.GetString();

		return m_event[id];
	}

	void EventManager::RemoveEvent(size_t position, Date date)
	{
		std::string id = date.GetString();

		m_event[id]->Remove(position);
	}

	void EventManager::UpdateEvent(Event event, Date date, size_t position)
	{
		std::string id = date.GetString();

		m_event[id]->At(position) = event;
	}
}