#include "EventController.h"

namespace PlannerCLI {
	EventController::EventController() {
		m_eventView = nullptr;
		m_eventManager = new EventManager();
		m_addEventController = new AddEventController();
		m_bIsSearching = false;
	}

	EventController::~EventController() {
		if (m_eventView != nullptr) delete m_eventView;
		if (m_eventManager != nullptr) delete m_eventManager;
		if (m_addEventController != nullptr) delete m_addEventController;
		m_eventView = nullptr;
		m_eventManager = nullptr;
		m_addEventController = nullptr;
	}

	void EventController::HandleInput(){
		bool run = true;

		m_nNavigation = 0;
		m_nEventNavigation = 0;

		if (m_eventView == nullptr) m_eventView = new EventView();

		do {
			m_eventView->Display(m_event, m_date, &m_nNavigation, &m_nEventNavigation);

			switch (_getch()) {
			case 'D':
			case 'd':
				Delete(m_nEventNavigation);
				m_nEventNavigation--;

				if (m_nEventNavigation < 0)
					m_nEventNavigation = 0;
				break;
			case KEY_ENTER:
				switch (m_nNavigation) {
				case EventView::ADD_BUTTON:
					Create(m_date);
					break;
				case EventView::EVENT_LIST:
					Update(m_nEventNavigation);
					break;
				case EventView::BACK_BUTTON:
					run = false;
					break;
				default:
					break;
				}
				break;
			case KEY_ESC:
				run = false;
				break;
			case KEY_SCAN_CODE_2:
				switch (_getch()) {
				case KEY_RIGHT:
					m_nNavigation++;

					if (m_nNavigation > EventView::BUTTON_COUNT - 1)
						m_nNavigation = EventView::BUTTON_COUNT - 1;
					break;
				case KEY_LEFT:
					m_nNavigation--;
					
					if (m_nNavigation < 0)
						m_nNavigation = 0;
					break;	
				case KEY_UP:
					if (m_nNavigation == EventView::EVENT_LIST) {
						m_nEventNavigation--;

						if (m_nEventNavigation < 0)
							m_nEventNavigation = 0;
					}
					break;
				case KEY_DOWN:
					if (m_nNavigation == EventView::EVENT_LIST) {
						m_nEventNavigation++;

						if (m_nEventNavigation > m_eventView->GetNoOfEvents() - 1)
							m_nEventNavigation = m_eventView->GetNoOfEvents() - 1;
					}
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

	void EventController::Create(Date date){
		Event newEvent;
		m_addEventController->HandleInput(newEvent, date, [&]() {
			m_eventManager->AddEvent(newEvent, date);
			//Crashes here...
			m_eventManager->Sort(date);
			m_event = m_eventManager->GetEventList(date);
		});
		
	}

	void EventController::Index(){}

	void EventController::Index(Date date)
	{
		m_event = m_eventManager->GetEventList(date);
		m_date = date;
		
		m_eventView = new EventView();

		HandleInput();

		delete m_eventView;
		m_eventView = nullptr;
	}

	void EventController::Search() {
		m_bIsSearching = true;

		m_eventView = new SearchEventView();
		SearchEventView* m_searchView = dynamic_cast<SearchEventView*>(m_eventView);

		m_event = m_eventManager->SearchEvent(m_searchView->EditQuery());

		HandleInput();

		delete m_eventView;
		m_eventView = nullptr;

		m_bIsSearching = false;
	}

	void EventController::Update(size_t position)
	{
		m_addEventController->HandleInput(m_event.at(position), m_date, [&]() {
			m_eventManager->UpdateEvent(m_event.at(position), m_date, position);
			m_eventManager->Sort(m_date);
			m_event = m_eventManager->GetEventList(m_date);
		});
	}

	void EventController::Delete(size_t position)
	{
		m_eventManager->RemoveEvent(m_date, position);
		m_eventManager->Sort(m_date);
		m_event = m_eventManager->GetEventList(m_date);
	}
}
