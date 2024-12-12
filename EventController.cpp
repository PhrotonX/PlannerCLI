#include "EventController.h"

namespace PlannerCLI {
	EventController::EventController() {
		m_eventView = new EventView();
		m_eventManager = new EventManager();
	}

	EventController::~EventController() {
		if (m_eventView != nullptr) delete m_eventView;
		if (m_eventManager != nullptr) delete m_eventManager;
		m_eventView = nullptr;
		m_eventManager = nullptr;
	}

	void EventController::HandleInput(){
		
	}

	void EventController::Create(Date date){
		Event event;
		AddEventView addEventView;

		bool run = true;
		int navigation = 0;

		char choice;

		do {
			addEventView.Create(event, date, &navigation);

			choice = _getch();
			switch (choice) {
			case KEY_ESC:
				run = false;
				break;
			case 'E':
			case 'e':
				switch (navigation) {
				case AddEventView::TITLE_FIELD:
					event.SetTitle(addEventView.EditTitle(event.GetTitle()));
					break;
				case AddEventView::DESCRIPTION_FIELD:
					event.SetDescription(addEventView.EditTitle(event.GetDescription()));
					break;
				case AddEventView::LOCATION_FIELD:
					event.SetLocation(addEventView.EditTitle(event.GetLocation()));
					break;
				case AddEventView::START_TIME_FIELD:
					event.SetStartTime(addEventView.EditStartTime(event.GetStartTime()));
					break;
				case AddEventView::END_TIME_FIELD:
					event.SetEndTime(addEventView.EditEndTime(event.GetEndTime()));
					break;
				case AddEventView::SAVE_BUTTON:
					m_eventManager->AddEvent(event, date);
				case AddEventView::CANCEL_BUTTON:
					run = false;
					break;
				default:
					break;
				}
				break;
			default:
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
				}
				break;
			}
		} while (run);
	}

	void EventController::Index()
	{

	}

	void EventController::Index(Date date)
	{
		
	}

	void EventController::Store()
	{
	}

	void EventController::Update()
	{
	}

	void EventController::Delete()
	{
	}
}
