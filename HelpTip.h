#ifndef HELPTIP_H
#define HELPTIP_H

#include <string>

namespace PlannerCLI {

    class HelpTip {
    private:
        int m_nId;                      
        std::string m_strMessage;        

    public:
 
        HelpTip();
        HelpTip(int id, const std::string& message) ;
        ~HelpTip() {}

        int GetId() const ;
        std::string GetMessage() const ;

        void SetId(int newid);
        void SetMessage(const std::string& newmessage);


    }; 
}
#endif // HELPTIP_H
