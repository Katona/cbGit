#include "RevertFileActionHandler.h"
#include <iostream>
#include "../../model/GitModel.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitFile.h"

using namespace std;

RevertFileActionHandler::RevertFileActionHandler()
{
    //ctor
}

void RevertFileActionHandler::handleEvent(cbGitFile& file, GitModel& gitModel) {
    cout << "Handling revert action" << endl;

    string workDir = file.getProjectPath();
    string fileName = file.getRelativeFileName();
    cout << "File: " << fileName << endl;
    cout << "WorkDir: " << workDir << endl;
    gitModel.checkoutFile(fileName);
    updateStatus(file);
}

RevertFileActionHandler::~RevertFileActionHandler()
{
    //dtor
}
