#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Model.h"
#include "Event.h"
#include "Date.h"
#include "Time.h"
#include "NullEvent.h"
#include <vector>
#include <map>

namespace PlannerCLI {
	class EventManager : public Model
	{
	public:
		EventManager();
		~EventManager() override{}

		void AddEvent(Event event, Date date);
		Event& GetEvent(Date date, size_t position);
		std::vector<Event>& GetEventList(Date date);
		std::map<std::string, std::vector<Event>>& GetAllEvents() {
			return m_event;
		}
		void RemoveEvent(Date date, size_t position);
		std::vector<Event> SearchEvent(const std::string& query);
		void UpdateEvent(Event event, Date date, size_t position);

		void Save() override {}
		void Sort(Date date);

	private:
		//@NOTE: Very problematic!
		std::map<std::string, std::vector<Event>> m_event;
		
		NullEvent m_nullEvent;
		std::vector<Event> m_nullEvents;
	};

}

#endif //EVENTMANAGER_H
