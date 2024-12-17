#include "EventManager.h"

namespace PlannerCLI {
	EventManager::EventManager()
	{
		m_nullEvents.push_back(m_nullEvent);
	}

	void EventManager::AddEvent(Event event, Date date)
	{
		std::string id = date.GetString();

		event.SetDate(date);

		//Find event by id.
		if (m_event.count(id) == 0) {
			m_event[id] = std::vector<Event>();
		}

		//Set the event position using the size of the event vector which is 1 less than the
		//actual size before adding the event item, in which the value is equivalent to the
		//zero-based index position of the event item within the vector.
		event.SetPosition(m_event[id].size());
		
		m_event[id].push_back(event);
	}

	Event& EventManager::GetEvent(Date date, size_t position)
	{
		std::string id = date.GetString();

		if (m_event.count(id) != 0) { //Checks if a key in the map exists.
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
		
		if (m_event[id].size() > 1) {
			size_t ctr = 0;
			for (auto& event : m_event[id]) {
				if (event.GetPosition() == position) {
					ctr = event.GetPosition();
				}
			}
			m_event[id].erase(m_event[id].begin() + ctr);
		}
		else {
			//Avoid a crash when there is only 1 remaining element in a vector.
			m_event[id].clear();
		}
	}

	std::vector<Event> EventManager::SearchEvent(const std::string& query)
	{
		std::vector<Event> results;

		int count = 0;

		for (auto& mapItem : m_event) {
			for (auto& eventItem : mapItem.second) {
				if (eventItem.GetTitle().find(query) != std::string::npos) {
					results.push_back(eventItem);

					count++;
				}
			}
		}

		if (count <= 0) {
			results.push_back(m_nullEvent);
		}
		
		return results;
	}

	void EventManager::UpdateEvent(Event event)
	{
		Date date = event.GetDate();
		size_t position = event.GetPosition();

		std::string id = date.GetString();

		//m_event[id].at(position) = event;
		for (auto& eventItem : m_event[id]) {
			if (eventItem.GetPosition() == position)
				eventItem = event;
		}
	}
	void EventManager::Load()
	{
		
	}
	void EventManager::Save()
	{
	}
	Event EventManager::OnLoadEvent(std::ifstream& file)
	{
		Event event;

		std::string eventDate, title, description, location, startTime, endTime;
		std::string position; //size_t
		std::string id; //long
		std::string line;
		std::getline(file, eventDate);

		//Return a NullEvent if end of file has been reached. The end of file for saved events is
		//always a null Date string.
		if (eventDate == "") return NullEvent();

		std::getline(file, position);
		std::getline(file, id);
		std::getline(file, title);
		std::getline(file, description);
		std::getline(file, location);
		std::getline(file, startTime);
		std::getline(file, endTime);
		std::getline(file, line);

		Date date = Date(eventDate);
		event.SetDate(date);

		std::stringstream positionStream(position);
		size_t nPosition;
		positionStream >> nPosition;
		event.SetPosition(nPosition);

		event.SetID(std::stol(id));

		event.SetTitle(title);
		event.SetDescription(description);
		event.SetLocation(location);
		event.SetStartTime(Time(startTime));
		event.SetEndTime(Time(endTime));

		return event;
	}
	void EventManager::OnSaveEvent(std::ofstream& file, Event event)
	{
		file << event.GetDate().GetString() << std::endl;
		file << event.GetPosition() << std::endl;
		file << event.GetID() << std::endl;
		file << event.GetTitle() << std::endl;
		file << event.GetDescription() << std::endl;
		file << event.GetLocation() << std::endl;
		file << event.GetStartTime().GetString() << std::endl;
		file << event.GetEndTime().GetString() << std::endl;
		file << FILE_BREAK_LINE << std::endl;
	}

	void EventManager::Sort(Date date)
	{
		std::string id = date.GetString();

		if (m_event[id].size() > 1) {
			for (size_t i = 0; i < m_event[id].size() - 1; i++) {
				for (size_t j = i; j < m_event[id].size() - 1; j++){
					Time lowerTime = m_event[id].at(j).GetStartTime();
					Time upperTime = m_event[id].at(j + 1).GetStartTime();
					if (lowerTime.GetHours() > upperTime.GetHours()) {
						 std::swap(m_event[id].at(j), m_event[id].at(j + 1));
					}
				}
			}
		}

		for (int i = 0; i < m_event[id].size(); i++) {
			m_event[id].at(i).SetPosition(i);
		}
		
	}
}