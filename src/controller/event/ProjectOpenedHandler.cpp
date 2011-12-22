#include <iostream>
#include "ProjectOpenedHandler.h"
#include "../ProjectUpdater.h"

using namespace std;

ProjectOpenedHandler::ProjectOpenedHandler() :
    AbstractEventHandler(cbEVT_PROJECT_OPEN)
{
    //ctor
}

void ProjectOpenedHandler::handleEvent(CodeBlocksEvent& event) {
    cout << "ProjectOPened" << endl;
    cbProject* project = event.GetProject();
    ProjectUpdater projUpdater;
    vector<cbProject*> projects;
    projects.push_back(project);
    projUpdater.updateProjects(projects);
}

ProjectOpenedHandler::~ProjectOpenedHandler()
{
    //dtor
}
