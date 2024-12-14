#include "SearchEventView.h"

namespace PlannerCLI {
	void SearchEventView::Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation)
	{
		EventView::Display(event, date, navigation, eventNavigation);
	}

	std::string SearchEventView::EditQuery()
	{
		InputStringView m_editDialog = InputStringView("Search", "Query: ");
		std::string query = m_editDialog.Show();

		SetQuery(query);
		return query;
	}

	void SearchEventView::DisplayHelpInfo() {
		EventView::DisplayHelpInfo();
	}

	void SearchEventView::OnDisplayTitle()
	{
		DrawTopBorder();
		DrawText("Search results for " + m_strQuery);
		DrawConnectingBorder();
	}

	void SearchEventView::OnDisplayButtons()
	{
		for (int i = 0; i < BUTTON_COUNT; i++) {
			m_button[i] = new Button(m_pnNavigation, i);
		}

		m_button[BACK_BUTTON]->SetText("[ BACK ]");
		m_button[ADD_BUTTON]->SetText("[ ADD  ]");
		m_button[EVENT_LIST]->SetText("[ EDIT ]");
		m_button[ADD_BUTTON]->SetActiveColor(ANSI_BACKGROUND_BRIGHT_COLOR_GRAY, ANSI_TEXT_COLOR_BRIGHT_YELLOW);
		m_button[ADD_BUTTON]->SetInactiveColor(ANSI_BACKGROUND_COLOR_WHITE, ANSI_TEXT_COLOR_GRAY);

		for (int i = 0; i < BUTTON_COUNT; i++) {
			m_button[i]->Display(false);
			std::cout << " ";
		}
		std::cout << std::endl;
	}

	void SearchEventView::OnDisplayDateAndTime(Date date, Time startTime, Time endTime, Time previousTime)
	{
		std::string time;
		if (startTime.GetHours() > previousTime.GetHours() ||
			startTime.GetHours() == 0) {
			DrawText(date.GetFormattedString() + " " + startTime.GetString() + "-" + endTime.GetString());
		}
	}

	void SearchEventView::OnDisplayEvent(const Event& event, size_t position)
	{
		EventView::OnDisplayEvent(event, position);
	}

	void SearchEventView::OnHandleEmptyEvents()
	{
		EventView::OnHandleEmptyEvents();
	}





}

