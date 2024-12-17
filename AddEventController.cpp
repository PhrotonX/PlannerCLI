#include "AddEventController.h"

namespace PlannerCLI {
	AddEventController::AddEventController()
	{
		m_addEventView = new AddEventView();
	}

	AddEventController::~AddEventController() {
		if (m_addEventView != nullptr) delete m_addEventView;
		m_addEventView = nullptr;
	}

	void AddEventController::HandleInput()
	{
	}

	void AddEventController::HandleInput(Event& event, Date date, std::function<void()> saveFunction)
	{
		bool run = true;
		int navigation = 0;

		char choice;

		do {
			m_addEventView->Create(event, date, &navigation);

			switch (_getch()) {
			case KEY_ESC:
				run = false;
				break;
			case KEY_ENTER:
				switch (navigation) {
				case AddEventView::TITLE_FIELD:
					event.SetTitle(m_addEventView->EditTitle(event.GetTitle()));
					break;
				case AddEventView::DESCRIPTION_FIELD:
					event.SetDescription(m_addEventView->EditTitle(event.GetDescription()));
					break;
				case AddEventView::LOCATION_FIELD:
					event.SetLocation(m_addEventView->EditTitle(event.GetLocation()));
					break;
				case AddEventView::START_TIME_FIELD:
					event.SetStartTime(m_addEventView->EditStartTime(event.GetStartTime()));
					break;
				case AddEventView::END_TIME_FIELD:
					event.SetEndTime(m_addEventView->EditEndTime(event.GetEndTime()));
					break;
				case AddEventView::SAVE_BUTTON:
					saveFunction();
				case AddEventView::CANCEL_BUTTON:
					run = false;
					break;
				default:
					break;
				}
				break;
			case KEY_SCAN_CODE_2:
				switch (_getch()) {
				case KEY_DOWN:
					navigation++;
					if (navigation > AddEventView::FIELD_SIZE - 1)
						navigation = AddEventView::FIELD_SIZE - 1;
					break;
				case KEY_UP:
					navigation--;
					if (navigation < 0)
						navigation = 0;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		} while (run);
	}

	void AddEventController::Index()
	{
	}

	void AddEventController::Load()
	{
	}

	void AddEventController::Store()
	{
	}

}