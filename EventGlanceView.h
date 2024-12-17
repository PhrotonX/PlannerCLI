#ifndef EVENTGLANCEVIEW_H
#define EVENTGLANCEVIEW_H
#include "EventView.h"

namespace PlannerCLI {
	class EventGlanceView : public EventView
	{
	public:
		EventGlanceView() {}
		~EventGlanceView() {}

		/**
			\param navigation Always set to nullptr.
			\param eventNavigation Always set to nullptr.
		*/
		void Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation) override;

		int GetNoOfEvents() const {
			return m_nNoOfEvents;
		}

		void DisplayHelpInfo() override{}

	protected:
		void OnDisplayTitle() override;
		void OnDisplayButtons() override {}
		void OnDisplayDateAndTime(Date date, Time startTime, Time endTime, Time previousTime) override;
		void OnDisplayEvent(const Event& event, size_t position) override;
		void OnHandleEmptyEvents() override;
	};
}

#endif //EVENTGLANCEVIEW_H


