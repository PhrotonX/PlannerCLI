#ifndef EVENTVIEW_H
#define EVENTVIEW_H

#include "Button.h"
#include "View.h"
#include "Event.h"
#include "Date.h"
#include "Time.h"

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

	protected:
		virtual void OnDisplayTitle();
		virtual void OnDisplayButtons();
		virtual void OnDisplayDateAndTime(Date date, Time startTime, Time endTime, Time previousTime);
		virtual void OnDisplayEvent(const Event& event, size_t position);
	
		int m_nNoOfEvents;
		int* m_pnNavigation;
		int* m_pnEventNavigation;
		Button* m_button[BUTTON_COUNT - 1];
	private:
		
		Date m_date;

		std::vector<Event> m_event;
		
	};
}

#endif //EVENTVIEW_H
