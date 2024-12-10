#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include "Model.h"

namespace PlannerCLI {
	class EventManager : public Model
	{
	public:
		EventManager(){}
		~EventManager() override{}

		void Save() override;

	private:
		
	};

}

#endif //EVENTMANAGER_H
