#include "AddEventView.h"

namespace PlannerCLI {
	void AddEventView::Create(Event& newEvent, Date date, int* navigation) {
		CLEAR_SCREEN;

		for (int i = 0; i < FIELD_SIZE; i++) {
			m_button[i] = new Button(navigation, i);
		}

		m_button[TITLE_FIELD]->SetText("Title: \t\t" + newEvent.GetTitle());
		m_button[LOCATION_FIELD]->SetText("Location: \t" + newEvent.GetLocation());
		m_button[START_TIME_FIELD]->SetText("Start Time: \t" + newEvent.GetStartTime().GetString());
		m_button[END_TIME_FIELD]->SetText("End Time: \t" + newEvent.GetEndTime().GetString());
		m_button[DESCRIPTION_FIELD]->SetText("Description: \t" + newEvent.GetDescription());
		m_button[COLOR_FIELD]->SetText("Color:");
		m_button[SAVE_BUTTON]->SetText("[ Save ]");
		m_button[CANCEL_BUTTON]->SetText("[Cancel]");

		for (int i = 0; i < FIELD_SIZE; i++) {
			if (i == COLOR_FIELD) {
				m_button[i]->Display(false);
				std::cout << newEvent.GetColor().GetBackgroundColor()
					<< newEvent.GetColor().GetForegroundColor() << "\tTest";
				std::cout << ANSI_BACKGROUND_BRIGHT_COLOR_WHITE << ANSI_TEXT_COLOR_BLACK << std::endl;
			}
			else {
				m_button[i]->Display(true);
			}
		}

		DisplayHelpInfo();
	}


	std::string AddEventView::EditTitle(const std::string& title)
	{
		EditStringView dialog = EditStringView("Title", title);
		return dialog.Show();
	}
	std::string AddEventView::EditDescription(const std::string& description)
	{
		EditStringView dialog = EditStringView("Description", description);
		return dialog.Show();
	}
	std::string AddEventView::EditLocation(const std::string& location)
	{
		EditStringView dialog = EditStringView("Location", location);
		return dialog.Show();
	}
	void AddEventView::EditColor()
	{
		DrawTopBorder();
		DrawHeading("Edit Color");
		DrawBottomBorder();
	}
	Time AddEventView::EditStartTime(const Time& time)
	{
		EditTimeView editTimeView = EditTimeView("Start Time", time);
		return editTimeView.Show();
	}

	Time AddEventView::EditEndTime(const Time& time)
	{
		EditTimeView editTimeView = EditTimeView("End Time", time);
		return editTimeView.Show();
	}

	void AddEventView::DisplayHelpInfo()
	{
		DrawSingleLine();
		std::cout << "^v - Navigation\t\tEnter - OK/Edit" << std::endl;
		std::cout << "Esc - Back" << std::endl;
	}
}
