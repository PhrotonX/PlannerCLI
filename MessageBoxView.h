#ifndef MESSAGEBOXVIEW_H
#define MESSAGEBOXVIEW_H
#include "View.h"
#include "IDialog.h"
#include "Button.h"
#include <string>

namespace PlannerCLI {
    /**
        \remarks Does not need to strictly follow MVC architecture.
    */
    class MessageBoxView : public View, public IDialog<bool>
    {
    public:
        MessageBoxView(const std::string& title, const std::string& description);
        ~MessageBoxView() override {}

        bool Show();

    protected:
        void DisplayHelpInfo() override{}

    private:
        void Display() {}
        std::string m_strDescription;

    };

}

#endif //MESSAGEBOXVIEW_H

