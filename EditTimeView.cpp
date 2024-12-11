#include "EditTimeView.h"

namespace PlannerCLI {
	EditTimeView::EditTimeView(const std::string& title, const Time& time)
	{
		m_strTitle = title;
		m_data = time;
	}

	Time EditTimeView::Show()
	{
		bool running = true;

		int navigation = 0;

		for (int i = 0; i < FIELD_COUNT; i++) {
			m_button[i] = new Button(&navigation, i);
		}

		int hours = m_data.GetHours();
		int minutes = m_data.GetMinutes();
			
		do {
			CLEAR_SCREEN;

			DrawTopBorder();
			DrawHeading("Edit " + m_strTitle);
			DrawBottomBorder();

			std::cout << "Old: " << m_data.GetString() << std::endl;
			DrawDoubleLine();

			//m_button[HOURS_FIELD]->SetText(Time::AddLeadingZero(hours));
			m_button[HOURS_FIELD]->SetText(std::to_string(hours));
			//m_button[MINUTES_FIELD]->SetText(Time::AddLeadingZero(minutes));
			m_button[MINUTES_FIELD]->SetText(std::to_string(minutes));

			m_button[OK_BUTTON]->SetText("[  OK  ]");
			m_button[CANCEL_BUTTON]->SetText("[Cancel]");

			std::cout << "New: ";
			m_button[HOURS_FIELD]->Display(false);
			std::cout << ":";
			m_button[MINUTES_FIELD]->Display(false);
			std::cout << "\n" << std::endl;

			m_button[OK_BUTTON]->Display(false);
			std::cout << "\t";
			m_button[CANCEL_BUTTON]->Display(false);

			std::cout << "\n";

			DrawDoubleLine();

			std::cout << "<> Navigate\t\t^v Edit Values" << std::endl;
			std::cout << "E  Enter\t\t" << std::endl;

			DrawDoubleLine();

			switch (_getch()) {
			case 'E':
			case 'e':
				switch (navigation) {
				case OK_BUTTON:
					m_data.SetHours(hours);
					m_data.SetMinutes(minutes);
					return m_data;
					break;
				case CANCEL_BUTTON:
					running = false;
					break;
				default:
					break;
				}
				break;
			default:
				switch (_getch()) {
				case _KEY_UP:
					switch (navigation) {
					case HOURS_FIELD:
						hours--;
						if (hours < 0) hours = 23;
						break;
					case MINUTES_FIELD:
						minutes--;
						if (minutes < 0) minutes = 59;
						break;
					}
					break;
				case _KEY_DOWN:
					switch (navigation) {
					case HOURS_FIELD:
						hours++;
						if (hours > 23) hours = 0;
						break;
					case MINUTES_FIELD:
						minutes++;
						if (minutes > 59) minutes = 0;
						break;
					}
					break;
				case _KEY_LEFT:
					navigation--;
					if (navigation < 0) navigation = 0;
					break;
				case _KEY_RIGHT:
					navigation++;
					if (navigation > FIELD_COUNT) navigation = FIELD_COUNT;
				}
				break;
			}
		} while (running);

		//Unchanged data.
		return m_data;
	}
}

