#ifndef EDITTIMEVIEW_H
#define EDITTIMEVIEW_H

#include "View.h"
#include "IDialog.h"
#include "Time.h"
#include "Button.h"

namespace PlannerCLI {
    class EditTimeView : public View, public IDialog<Time>
    {
    public:
        inline static const int HOURS_FIELD =     0;
        inline static const int MINUTES_FIELD =   1;
        inline static const int OK_BUTTON =       2;
        inline static const int CANCEL_BUTTON =   3;
        inline static const int FIELD_COUNT =     4;
        EditTimeView(const std::string& title, const Time& time);
        ~EditTimeView() override;

        Time Show() override;

    private:
        Time m_data;
        Button* m_button[FIELD_COUNT];
    };
}



#endif //EDITTIMEVIEW_H

