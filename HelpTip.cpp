#include "HelpTip.h"

namespace PlannerCLI {
    HelpTip::HelpTip() {
       m_nId = 0;
       m_strMessage = "";
    }


    HelpTip::HelpTip(int inputid, const std::string& inputmessage){
         m_nId=inputid;
        m_strMessage=inputmessage;
    }

    int HelpTip::GetId() const {
        return m_nId;
    }

    std::string HelpTip::GetMessage() const {
        return m_strMessage;
    }

    void HelpTip::SetId(int newid) {
        m_nId = newid;
    }


    void HelpTip::SetMessage(const std::string& newmessage) {
       m_strMessage = newmessage;
    }
} 

