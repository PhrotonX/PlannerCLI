#include "CalendarView.h"

namespace PlannerCLI{
    CalendarView::CalendarView()
    {
        //ctor
    }

    CalendarView::~CalendarView()
    {
        //dtor
    }

    void CalendarView::Display(){
        std::cout << "���������������������������ͻ" << std::endl;
        std::cout << "�                           �" << std::endl;
        std::cout << "�         PlannerCLI        �" << std::endl;
        std::cout << "�                           �" << std::endl;
        std::cout << "�   Choose an option:       �" << std::endl;
        std::cout << "�   ======================  �" << std::endl;
        std::cout << "�   1. Show Calendar        �" << std::endl;
        std::cout << "�   2. Save Information     �" << std::endl;
        std::cout << "�   3. Settings             �" << std::endl;
        std::cout << "�   4. Help                 �" << std::endl;
        std::cout << "�   5. Exit                 �" << std::endl;
        std::cout << "�                           �" << std::endl;
        std::cout << "���������������������������ͼ" << std::endl;

    }

}
