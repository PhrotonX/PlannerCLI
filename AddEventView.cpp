#include "AddEventView.h"

namespace PlannerCLI {
	void AddEventView::Create(Event& newEvent, Date date, int* navigation) {
		CLEAR_SCREEN;

		for (int i = 0; i < FIELD_SIZE; i++) {
			m_button[i] = new Button(navigation, i);
		}

		m_button[TITLE_FIELD]->SetText("Title: " + newEvent.GetTitle());
		m_button[LOCATION_FIELD]->SetText("Location: " + newEvent.GetLocation());
		m_button[START_TIME_FIELD]->SetText("Start Time: " + newEvent.GetStartTime().GetString());
		m_button[END_TIME_FIELD]->SetText("End Time: " + newEvent.GetEndTime().GetString());
		m_button[DESCRIPTION_FIELD]->SetText("Description: " + newEvent.GetDescription());
		m_button[COLOR_FIELD]->SetText("Color: ");
		m_button[SAVE_BUTTON]->SetText("[ Save ]");
		m_button[CANCEL_BUTTON]->SetText("[Cancel]");

		for (int i = 0; i < FIELD_SIZE; i++) {
			m_button[i]->Display(true);
			if (i == COLOR_FIELD) {
				m_button[i]->Display(false);
				std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK << std::endl;
			}
		}
	}
}
