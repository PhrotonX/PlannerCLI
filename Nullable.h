#ifndef NULLABLE_H
#define NULLABLE_H

namespace PlannerCLI {
	class Nullable
	{
	public:
		Nullable();
		virtual ~Nullable();

		bool IsNull() const;
	protected:
		bool m_bIsNull;
	};
}

#endif
