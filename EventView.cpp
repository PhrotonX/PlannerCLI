#include "EventView.h"

namespace PlannerCLI {
	void EventView::Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation) {
        m_event = event;
        m_date = date;
        m_pnNavigation = navigation;
        m_pnEventNavigation = eventNavigation;

        CLEAR_SCREEN;

        OnDisplayTitle();

        Time prevTime;

        m_nNoOfEvents = m_event.size();

        int i = 0;
        for (auto& eventItem : m_event) {
            if (!eventItem.IsNull()) {
                OnDisplayDateAndTime(eventItem.GetDate(), eventItem.GetStartTime(), eventItem.GetEndTime(), prevTime);

                OnDisplayEvent(eventItem, i);
                
                prevTime = eventItem.GetStartTime();
            }
            else {
                DrawText("No events to display");
            }
            
            i++;
        }

        OnHandleEmptyEvents();

        DrawBottomBorder();

        OnDisplayButtons();

        DisplayHelpInfo();
	}

    void EventView::DisplayWidget(const std::vector<Event>& event, Date date)
    {
        m_event = event;
        m_date = date;
        if (m_pnEventNavigation != nullptr) *m_pnEventNavigation = -1;
        if (m_pnNavigation != nullptr) *m_pnNavigation = -1;

        OnDisplayTitle();

        Time prevTime;

        m_nNoOfEvents = m_event.size();

        int i = 0;
        for (auto& eventItem : m_event) {
            if (i == 3) break;
            if (!eventItem.IsNull()) {
                OnDisplayDateAndTime(eventItem.GetDate(), eventItem.GetStartTime(), eventItem.GetEndTime(), prevTime);

                OnDisplayEvent(eventItem, i);

                prevTime = eventItem.GetStartTime();
            }
            else {
                DrawText("No events to display");
            }

            i++;
        }

        OnHandleEmptyEvents();

        DrawBottomBorder();
    }

    void EventView::DisplayHelpInfo() {
        SetColorDefaults();
        DrawSingleLine();

        std::cout << "<> Button Navigation\t^v Event Navigation" << std::endl;
        std::cout << "D - Delete\t\tEnter - OK/Edit" << std::endl;
        std::cout << "Esc - Back" << std::endl;
    }

    void EventView::OnDisplayTitle()
    {
        DrawTopBorder();
        DrawHeading(m_date.GetFormattedString(true));
        DrawConnectingBorder();
    }

    void EventView::OnDisplayButtons()
    {
        for (int i = 0; i < BUTTON_COUNT; i++) {
            m_button[i] = new Button(m_pnNavigation, i);
        }

        m_button[BACK_BUTTON]->SetText("[ BACK ]");
        m_button[ADD_BUTTON]->SetText("[ ADD  ]");
        m_button[EVENT_LIST]->SetText("[ EDIT ]");

        for (int i = 0; i < BUTTON_COUNT; i++) {
            m_button[i]->Display(false);
            std::cout << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < BUTTON_COUNT; i++) {
            if (m_button[i] != nullptr) delete m_button[i];
            m_button[i] = nullptr;
        }
    }

    void EventView::OnDisplayDateAndTime(Date date, Time startTime, Time endTime, Time previousTime)
    {
        std::string time;
        //if (startTime.GetHours() > previousTime.GetHours() ||
            //startTime.GetHours() == 0) {
            //time = std::to_string(startTime.GetHours()) + ":00";
            DrawText(startTime.GetString() + "-" + endTime.GetString());
        //}
    }

    void EventView::OnDisplayEvent(const Event& event, size_t position)
    {
        std::string title = event.GetTitle();
        if (title.length() > (CONTENT_WIDTH - INDENT_WIDTH) - 2) {
            title = title.substr(0, (CONTENT_WIDTH - INDENT_WIDTH) - 7) + "...";
        }

        if (m_pnEventNavigation != nullptr && m_pnNavigation != nullptr) {
            if (*m_pnEventNavigation == position && *m_pnNavigation == EVENT_LIST) {
                SetColor(ANSI_BACKGROUND_COLOR_BLUE, ANSI_TEXT_COLOR_BRIGHT_WHITE);
                DrawText(BULLET + " " + title);
                SetColorDefaults();
            }
        }
        
        else {
            DrawText(BULLET + " " + title);
        }

        DrawText(" ");
    }

    void EventView::OnHandleEmptyEvents()
    {
        if (m_event.empty()) {
            DrawText("No events to display");
        }
    }
    
}