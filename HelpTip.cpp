#include "HelpTip.h"

namespace PlannerCLI {


HelpTip::HelpTip() : id(0), message("") {}


HelpTip::HelpTip(int id, const std::string& message) 
    : id(id), message(message) {}


int HelpTip::getId() const {
    return id;
}


std::string HelpTip::getMessage() const {
    return message;
}


void HelpTip::setId(int newid) {
    id = newid;
}


void HelpTip::setMessage(const std::string& newmessage) {
   message = newmessage;
}

} 

