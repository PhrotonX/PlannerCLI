#include "Nullable.h"

namespace PlannerCLI {
	Nullable::Nullable() {
		m_bIsNull = false;
	}

	Nullable::~Nullable()
	{

	}

	bool Nullable::IsNull() const
	{
		return m_bIsNull;
	}
}