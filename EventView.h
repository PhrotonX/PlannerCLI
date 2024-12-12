#ifndef EVENTVIEW_H
#define EVENTVIEW_H
#include "Button.h"
#include "View.h"
#include "Event.h"
#include "Date.h"
#include <vector>

namespace PlannerCLI {
	class EventView : public View
	{
	public:
		inline static const int BACK_BUTTON = 0;
		inline static const int ADD_BUTTON = 1;
		inline static const int EVENT_LIST = 2;
		inline static const int BUTTON_COUNT = 3;

		EventView(){}
		~EventView() {}
		
		/**
			\details Display all events from a specific date.
		*/
		void Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation);

		int GetNoOfEvents() const {
			return m_nNoOfEvents;
		}

		void HelpInfo();

	private:
		int m_nNoOfEvents;

		Button* m_button[BUTTON_COUNT];
	};
}

#endif //EVENTVIEW_H
