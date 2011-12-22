#include "FileSavedHandler.h"
#include <iostream>
#include <cbeditor.h>
#include "../ProjectFileUpdater.h"
#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../Utils.h"

using namespace std;

FileSavedHandler::FileSavedHandler() :
    AbstractEventHandler(cbEVT_EDITOR_SAVE)
{
    //ctor
}

void FileSavedHandler::handleEvent(CodeBlocksEvent& event) {
    cout << "Handle file save event " << endl;
    cbEditor* editor = dynamic_cast<cbEditor*> (event.GetEditor());
    if (editor == NULL) {
        return;
    }
    ProjectFile* file = editor->GetProjectFile();
    if (file == NULL) {
        return;
    }
    string fileName = toString(file->relativeFilename);
    string workDir = toString(file->GetParentProject()->GetCommonTopLevelPath());
    vector<GitFileStatus> statuses;
    GitModel model(workDir);
    model.getStatus(statuses, fileName);
    if (statuses.empty()) {
        file->SetFileState(fvsVcUpToDate);
    } else {
        ProjectFileUpdater updater;
        updater.updateFile(*file, statuses[0]);
    }


}

FileSavedHandler::~FileSavedHandler()
{
    //dtor
}
