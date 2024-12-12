#ifndef NULLEVENT_H
#define NULLEVENT_H

#include "Event.h"

namespace PlannerCLI {
	class NullEvent : public Event
	{
	public:
		NullEvent();
		~NullEvent() override;
	};
}

#endif //NULLEVENT_H

