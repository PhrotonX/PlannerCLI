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
		
	}

	void EventController::Create(Date date, std::function<void()> saveFunction){

	}

	void EventController::Index(){}

	void EventController::Index(Date date)
	{
		std::vector<Event> events =  m_eventManager->GetEventList(date);
		m_eventView->Display(events, date);
	}

	void EventController::Store()
	{

	}

	void EventController::Update(const Event& event, Date date)
	{
		
	}

	void EventController::Delete()
	{
	}
}
