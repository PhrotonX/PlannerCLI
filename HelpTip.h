#ifndef HELPTIP_H
#define HELPTIP_H

#include <string>

namespace PlannerCLI {

class HelpTip {
private:
    int id;                      
    std::string message;        

public:
 
    HelpTip();
    HelpTip(int id, const std::string& message) ;

    int getId() const ;
    std::string getMessage() const ;

    void setId(int newid);
    void setMessage(const std::string& newmessage);


}; 
}
#endif // HELPTIP_H
