#include "FileActionHandler.h"
#include "../../model/GitModel.h"
#include "../../model/FileStatuses.h"
#include "../../utils/cbGitFile.h"
#include "../../utils/Utils.h"

FileActionHandler::FileActionHandler()
{
    //ctor
}

void FileActionHandler::onActionFired(wxCommandEvent& event) {
    ProjectFile* selectedFile = getSelectedProjectFile();
    if (selectedFile == NULL) {
        return;
    }
    cbGitFile file(*selectedFile);
    GitModel model(file.getProjectPath());
    handleAction(file, model);
}

void FileActionHandler::updateStatus(cbGitFile& file) {
    GitModel gitModel(file.getProjectPath());
    FileStatuses statuses;
    gitModel.getStatus(statuses);
    file.setState(statuses.getStatus(file.getRelativeFileName()).getStatus());
}

FileActionHandler::~FileActionHandler()
{
    //dtor
}
