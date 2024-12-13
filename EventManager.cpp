#include "EventManager.h"

namespace PlannerCLI {
	EventManager::EventManager()
	{
		m_nullEvents.push_back(m_nullEvent);
	}

	void EventManager::AddEvent(Event event, Date date)
	{
		std::string id = date.GetString();

		//Find event by id.
		if (m_event.count(id) == 0) {
			m_event[id] = std::vector<Event>();
		}
		
		m_event[id].push_back(event);
	}

	Event& EventManager::GetEvent(Date date, size_t position)
	{
		std::string id = date.GetString();

		if (m_event.count(id) != 0) {
			return m_event[id].at(position);
		}
		else {
			return m_nullEvent;
		}
	}

	std::vector<Event>& EventManager::GetEventList(Date date)
	{
		std::string id = date.GetString();

		if (m_event.count(id) != 0) {
			return m_event[id];
		}
		else {
			return m_nullEvents;
		}
	}

	void EventManager::RemoveEvent(Date date, size_t position)
	{
		std::string id = date.GetString();

		m_event[id].erase(m_event[id].begin() + position);
	}

	std::vector<Event> EventManager::SearchEvent(const std::string& query)
	{
		std::vector<Event> results;

		int count = 0;

		for (auto& mapItem : m_event) {
			for (auto& eventItem : mapItem.second) {
				if (eventItem.GetTitle().find(query) != std::string::npos) {
					Date date = Date(mapItem.first);
					eventItem.SetDate(date);
					results.push_back(eventItem);
				}
			}

			count++;
		}

		if (count <= 0) {
			results.push_back(m_nullEvent);
		}
		
		return results;
	}

	void EventManager::UpdateEvent(Event event, Date date, size_t position)
	{
		std::string id = date.GetString();

		m_event[id].at(position) = event;
	}
	void EventManager::Sort(Date date)
	{
		std::string id = date.GetString();

		bool swapped = false;

		if (!m_event[id].size() <= 1) {
			for (size_t i = 0; i < m_event.size() - 1; i++) {
				for (size_t j = i; j < m_event.size() - 1; j++){
					Time lowerTime = m_event[id].at(j).GetStartTime();
					Time upperTime = m_event[id].at(j + 1).GetStartTime();
					if (lowerTime.GetHours() > upperTime.GetHours()) {
						 std::swap(m_event[id].at(j), m_event[id].at(j + 1));
						 swapped = true;
					}
				}

				if (!swapped)
					break;
			}
		}
		
	}
}