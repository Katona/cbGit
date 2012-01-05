#include <sdk.h>
#include <manager.h>
#include <projectmanager.h>
#include <cbproject.h>

#include "AddFileActionHandler.h"
#include "../../model/GitAddCommand.h"
#include "../../model/GitStatusCommand.h"
#include "../../model/FileStatuses.h"
#include "../ProjectFileUpdater.h"
#include "../../utils/Utils.h"

AddFileActionHandler::AddFileActionHandler()
{
    //ctor
}

void AddFileActionHandler::onActionFired(wxCommandEvent& event) {
    ProjectFile* f = getSelectedProjectFile();
    if (f)
    {
        string workDir = toString(f->GetParentProject()->GetCommonTopLevelPath());
        string fileName = toString(f->relativeFilename);

        GitAddCommand addCommand(workDir, fileName);
        addCommand.execute();
        GitStatusCommand statusCmd(workDir, fileName);
        FileStatuses fileStatuses;
        statusCmd.getFileStatuses(fileStatuses);
        ProjectFileUpdater fileUpdater;
        fileUpdater.updateFile((*f), fileStatuses.getStatus(fileName));
    }


}

AddFileActionHandler::~AddFileActionHandler()
{
    //dtor
}
