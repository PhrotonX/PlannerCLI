#ifndef EVENTVIEW_H
#define EVENTVIEW_H
#include "View.h"
#include "Event.h"
#include "Date.h"

namespace PlannerCLI {
	class EventView : public View
	{
	public:
		EventView(){}
		~EventView() {}

		void Display() override{}

		/**
			\details Display all events from a specific date.
		*/
		void Display(const Event& event, const Date& date);
	};
}

#endif //EVENTVIEW_H
