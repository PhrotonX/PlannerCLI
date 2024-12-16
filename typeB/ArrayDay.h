#ifndef ARRAYDAY_H
#define ARRAYDAY_H

#include "../Day.h"
#include "../Event.h"
#include "../NullEvent.h"
#include <vector>

namespace PlannerCLI::typeB {
    class ArrayDay : public Day
    {
    public:

        inline static const int MAX_EVENTS = 10;

        ArrayDay();
        ArrayDay(int day);
        ~ArrayDay() override {}

        void AddEvent(Event event);

        Event& GetEvent(int position) {
            return m_event[position];
        }

        std::vector<Event>& GetEventList() {
            return m_event;
        }

        void UpdateEvent(Event event);

        void DeleteEvent(size_t position);
       

    protected:
        std::vector<Event> m_event;
        int m_nEventSize = 0;
    };


}


#endif //ARRAYDAY_H