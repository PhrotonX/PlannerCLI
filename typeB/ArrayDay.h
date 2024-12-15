#ifndef ARRAYDAY_H
#define ARRAYDAY_H

#include "../Day.h"
#include "../Event.h"
#include "../NullEvent.h"

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

        void UpdateEvent(Event event);

        void DeleteEvent(Event event);
       

    protected:
        Event m_event[10];
        int m_nEventSize = 0;
    };


}


#endif //ARRAYDAY_H