#ifndef SEARCHEVENTVIEW_H
#define SEARCHEVENTVIEW_H

#include "EventView.h"
#include "InputStringView.h"

namespace PlannerCLI {
	class SearchEventView : public EventView
	{
	public:
		SearchEventView(){}
		~SearchEventView() override{}

		void Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation);
		void DisplayHelpInfo() override;
		void SetQuery(const std::string& query) {
			m_strQuery = query;
		}

		std::string EditQuery();

	protected:
		void OnDisplayTitle() override;
		void OnDisplayButtons() override;
		void OnDisplayDateAndTime(Date date, Time startTime, Time endTime, Time previousTime) override;
		void OnDisplayEvent(const Event& event, size_t position) override;
		void OnHandleEmptyEvents();
	private:
		std::string m_strQuery;
	};
}

#endif //SEARCHEVENTVIEW_H


