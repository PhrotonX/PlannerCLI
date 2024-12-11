#ifndef EVENTVIEW_H
#define EVENTVIEW_H
#include "View.h"

namespace PlannerCLI {
	class EventView : public View
	{
	public:
		EventView(){}
		~EventView() {}

		/**
			\details Display all events from a specific date.
		*/
		void Index();
	};
}

#endif //EVENTVIEW_H
