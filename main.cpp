#include <iostream>
#include "App.h"

using namespace std;

int main()
{
    PlannerCLI::App app;
    app.Run();
    app.Close();

    return 0;
}
