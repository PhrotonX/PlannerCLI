#include <iostream>
#include "App.h"

using namespace std;

int main()
{
    PlannerCLI::App* app = new PlannerCLI::App();
    app->Run();

    delete app;
    app = nullptr;

    return 0;
}
