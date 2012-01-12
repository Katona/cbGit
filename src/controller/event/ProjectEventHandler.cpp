#include "ProjectEventHandler.h"

#include <vector>
#include <wx/wx.h>
#include "../../model/GitModel.h"
#include "../../model/FileStatuses.h"
#include "../../utils/cbGitProject.h"
#include "../../utils/cbGitFile.h"
#include "../../utils/Utils.h"

using namespace std;

ProjectEventHandler::ProjectEventHandler()
{
    //ctor
}

void ProjectEventHandler::handleEvent(wxCommandEvent& wxEvent) {
    doHandle(getSelectedProject());
}

void ProjectEventHandler::handleEvent(CodeBlocksEvent& cbEvent) {
    doHandle(cbEvent.GetProject());
}

void ProjectEventHandler::doHandle(cbProject* cbProj) {
    if (cbProj == NULL) {
        return;
    }

    cbGitProject project(*cbProj);
    GitModel gitModel(project.getTopLevelPath());
    handleEvent(project, gitModel);
}

void ProjectEventHandler::updateStatus(cbGitProject& project) {

    GitModel gitModel(project.getTopLevelPath());
    FileStatuses gitFileStatuses;
    gitModel.getStatus(gitFileStatuses);

    vector<cbGitFile*> files = project.getFiles();
    for (int i = 0; i < files.size(); i++) {
        const GitFileStatus& status = gitFileStatuses.getStatus(
                (files[i])->getRelativeFileName());
        (files[i])->setState(status.getStatus());
    }
}

ProjectEventHandler::~ProjectEventHandler()
{
    //dtor
}
