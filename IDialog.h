#ifndef IDIALOG_H
#define IDIALOG_H

#include <conio.h>
#include <string>

namespace PlannerCLI {
	/**
		\remarks Classes that inherit this class shall no longer follow MVC Architecture.
	*/
	template<typename T>
	class IDialog
	{
	public:
		virtual T Show() = 0;

	protected:

		inline static const int _KEY_UP = 72;
		inline static const int _KEY_DOWN = 80;
		inline static const int _KEY_LEFT = 75;
		inline static const int _KEY_RIGHT = 77;
		std::string m_strTitle;
	};

	template<typename T>
	T IDialog<T>::Show() {

	}

}

#endif //IDIALOG_H

