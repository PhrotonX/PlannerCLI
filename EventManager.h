#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Model.h"
#include "Event.h"
#include "Date.h"
#include "List.h"
#include <map>

namespace PlannerCLI {
	class EventManager : public Model
	{
	public:
		EventManager(){}
		~EventManager() override{}

		void AddEvent(Event event, Date date);
		Event GetEvent(Date date, size_t position);
		std::map<std::string, List<Event>> GetAllEvents() {
			return m_event;
		}
		void RemoveEvent(size_t position, Date date);
		void UpdateEvent(Event event, Date date, size_t position);

		void Save() override {}

	private:
		std::map<std::string, List<Event>> m_event;
	};

}

#endif //EVENTMANAGER_H
