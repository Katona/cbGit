#include "RevertFileActionHandler.h"
#include <iostream>
#include "../../model/GitModel.h"
#include "../../Utils.h"

using namespace std;

RevertFileActionHandler::RevertFileActionHandler()
{
    //ctor
}

void RevertFileActionHandler::onActionFired(wxCommandEvent& event) {
    cout << "Handling revert action" << endl;
    ProjectFile* selectedFile = getSelectedProjectFile();
    if (selectedFile == NULL) {
        return;
    }
    cbProject* project = selectedFile->GetParentProject();
    if (project == NULL) {
        return;
    }
    string workDir = toString(project->GetCommonTopLevelPath());
    string fileName = toString(selectedFile->relativeFilename);
    cout << "File: " << fileName << endl;
    cout << "WorkDir: " << workDir << endl;
    GitModel gitModel(workDir);
    gitModel.checkoutFile(fileName);
    selectedFile->SetFileState(fvsVcUpToDate);
}

RevertFileActionHandler::~RevertFileActionHandler()
{
    //dtor
}
