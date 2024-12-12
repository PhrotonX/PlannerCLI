#ifndef EVENTVIEW_H
#define EVENTVIEW_H
#include "View.h"
#include "Event.h"
#include "Date.h"
#include <vector>

namespace PlannerCLI {
	class EventView : public View
	{
	public:
		EventView(){}
		~EventView() {}
		
		/**
			\details Display all events from a specific date.
		*/
		void Display(const std::vector<Event>& event, Date date);
	};
}

#endif //EVENTVIEW_H
