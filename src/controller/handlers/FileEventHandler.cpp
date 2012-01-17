#include "FileEventHandler.h"
#include <projectfile.h>
#include <cbeditor.h>
#include "../../model/GitModel.h"
#include "../../model/FileStatuses.h"
#include "../../utils/cbGitFile.h"
#include "../../utils/Utils.h"

FileEventHandler::FileEventHandler()
{
    //ctor
}

void FileEventHandler::handleEvent(wxCommandEvent& wxEvent) {
    ProjectFile* cbFile = getSelectedProjectFile();
    doHandle(cbFile);
}


void FileEventHandler::handleEvent(CodeBlocksEvent& cbEvent) {
    cbEditor* editor = dynamic_cast<cbEditor*> (cbEvent.GetEditor());
    if (editor == NULL) {
        return;
    }
    ProjectFile* cbFile = editor->GetProjectFile();
    doHandle(cbFile);
}

void FileEventHandler::doHandle(ProjectFile* cbFile) {
    if (cbFile == NULL) {
        return;
    }
    cbGitFile file(*cbFile);
    GitModel model(file.getProjectPath());
    handleEvent(file, model);
}

void FileEventHandler::updateStatus(cbGitFile& file) {
    GitModel gitModel(file.getProjectPath());
    FileStatuses statuses;
    gitModel.getStatus(statuses);
    file.setState(statuses.getStatus(file.getRelativeFileName()).getStatus());
}

FileEventHandler::~FileEventHandler()
{
    //dtor
}
