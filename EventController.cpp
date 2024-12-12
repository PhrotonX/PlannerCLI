#include "EventController.h"

namespace PlannerCLI {
	EventController::EventController() {
		m_eventView = new EventView();
		m_eventManager = new EventManager();
		m_addEventController = new AddEventController();
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

		int navigation = 0;
		int eventNavigation = 0;
	
		do {
			m_eventView->Display(m_event, m_date, &navigation, &eventNavigation);

			switch (_getch()) {
			default:
				switch (_getch()) {
				case 'D':
				case 'd':
					Delete(eventNavigation);
					eventNavigation--;

					if (eventNavigation < 0)
						eventNavigation = 0;
					break;
				case KEY_RIGHT:
					navigation++;

					if (navigation > EventView::BUTTON_COUNT - 1)
						navigation = EventView::BUTTON_COUNT - 1;
					break;
				case KEY_LEFT:
					navigation--;
					
					if (navigation < 0)
						navigation = 0;
					break;	
				case KEY_UP:
					if (navigation == EventView::EVENT_LIST) {
						eventNavigation--;

						if (eventNavigation < 0)
							eventNavigation = 0;
					}
					break;
				case KEY_DOWN:
					if (navigation == EventView::EVENT_LIST) {
						eventNavigation++;

						if (eventNavigation > m_eventView->GetNoOfEvents() - 1)
							eventNavigation = m_eventView->GetNoOfEvents() - 1;
					}
					break;
				default:
					switch (navigation) {
					case EventView::ADD_BUTTON:
						Create(m_date);
						break;
					case EventView::EVENT_LIST:
						Update(eventNavigation);
						break;
					case EventView::BACK_BUTTON:
						run = false;
					default:
						break;
					}
					break;
				}

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
		
		HandleInput();
	}

	void EventController::Store()
	{

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
