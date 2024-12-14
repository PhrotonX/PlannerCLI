#ifndef EDITSTRINGVIEW_H
#define EDITSTRINGVIEW_H

#include "View.h"
#include "IDialog.h"

namespace PlannerCLI {
	class EditStringView : public View, public IDialog<std::string>
	{
	public:
		EditStringView(const std::string& title, const std::string& data);
		~EditStringView() override{}

		void DisplayHelpInfo() override {}
		std::string Show() override;
	private:
		std::string m_strData;
	};
}

#endif //EDITSTRINGVIEW_H

