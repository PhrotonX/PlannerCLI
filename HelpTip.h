#ifndef HELPTIP_H
#define HELPTIP_H

#include <string>

namespace PlannerCLI {

class HelpTip {
private:
    int id;                      
    std::string message;        

public:
 
    HelpTip() : id(0), message("") {}
    HelpTip(int id, const std::string& message) : id(id), message(message) {}

    int getId() const { return id; }
    std::string getMessage() const { return message; }

    void setId(int newid) { id = newid; }
    void setMessage(const std::string& newmessage) { message = newmessage; }


}; 
}
#endif // HELPTIP_H
