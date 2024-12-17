#include "EventGlanceView.h"

namespace PlannerCLI {
	void EventGlanceView::Display(const std::vector<Event>& event, Date date, int* navigation, int* eventNavigation){
        m_event = event;
        m_date = date;
        if (m_pnEventNavigation != nullptr) *m_pnEventNavigation = -1;
        if (m_pnNavigation != nullptr) *m_pnNavigation = -1;

        OnDisplayTitle();

        Time prevTime;

        m_nNoOfEvents = m_event.size();

        int i = 0;
        for (auto& eventItem : m_event) {
            if (i == 3) {
                DrawText("Press ENTER to show more events");
                break;
            }
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

    void EventGlanceView::OnDisplayTitle()
    {
        DrawConnectingBorder();
        DrawText(m_date.GetFormattedString());
        DrawConnectingBorder();
    }

    void EventGlanceView::OnDisplayDateAndTime(Date date, Time startTime, Time endTime, Time previousTime)
    {
        EventView::OnDisplayDateAndTime(date, startTime, endTime, previousTime);
    }

    void EventGlanceView::OnDisplayEvent(const Event& event, size_t position)
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

    void EventGlanceView::OnHandleEmptyEvents()
    {
        EventView::OnHandleEmptyEvents();
    }

}
