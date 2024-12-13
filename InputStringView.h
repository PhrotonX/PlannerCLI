#ifndef INPUTSTRINGVIEW_H
#define INPUTSTRINGVIEW_H

#include "IDialog.h"
#include "View.h"

namespace PlannerCLI {
	class InputStringView : public View, public IDialog<std::string>
	{
	public:
		InputStringView(const std::string& title, const std::string& hint);
		~InputStringView() override {}

		std::string Show() override;

	private:
		std::string m_strHint;
	};


}

#endif //INPUTSTRINGVIEW_H
