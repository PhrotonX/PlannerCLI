#ifndef ADDEVENTCONTROLLER_H
#define ADDEVENTCONTROLLER_H

#include <functional>
#include "Controller.h"
#include "AddEventView.h"
#include "Date.h"
#include "Event.h"

namespace PlannerCLI {
	class AddEventController : public Controller
	{
	public:
		AddEventController();
		~AddEventController() override;

		void HandleInput() override;
		void HandleInput(Event& event, Date date, std::function<void()> saveFunction);
		void Index() override;

		void Load() override;
		void Store() override;
	private:

		AddEventView* m_addEventView;
	};
}

#endif //ADDEVENTCONTROLLER_H
