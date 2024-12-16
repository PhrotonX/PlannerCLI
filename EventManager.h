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

		virtual void AddEvent(Event event, Date date);
		virtual Event& GetEvent(Date date, size_t position);
		virtual std::vector<Event>& GetEventList(Date date);
		std::map<std::string, std::vector<Event>>& GetAllEvents() {
			return m_event;
		}
		virtual void RemoveEvent(Date date, size_t position);
		virtual std::vector<Event> SearchEvent(const std::string& query);
		virtual void UpdateEvent(Event event);

		void Load() override;
		void Save() override;
		virtual void Sort(Date date);

	private:
		//@NOTE: Very problematic!
		std::map<std::string, std::vector<Event>> m_event;
		
	protected:
		NullEvent m_nullEvent;
		std::vector<Event> m_nullEvents;
	};

}

#endif //EVENTMANAGER_H
