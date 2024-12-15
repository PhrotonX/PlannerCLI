#include "NullEvent.h"

namespace PlannerCLI {
	NullEvent::NullEvent() : Event::Event()
	{
		m_bIsNull = true;

		SetTitle("Null");
		SetDescription("Null");
		SetLocation("Null");
	}

	NullEvent::~NullEvent()
	{
	}
}