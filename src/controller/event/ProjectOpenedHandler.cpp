#include <iostream>
#include "ProjectOpenedHandler.h"
#include "../ProjectUpdater.h"

using namespace std;

ProjectOpenedHandler::ProjectOpenedHandler()
{
    //ctor
}

void ProjectOpenedHandler::handleEvent(cbGitProject& project, GitModel& model) {
    cout << "ProjectOPened" << endl;
    updateStatus(project);
}

ProjectOpenedHandler::~ProjectOpenedHandler()
{
    //dtor
}
