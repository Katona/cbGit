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
#include "../../utils/cbGitFile.h"


AddFileActionHandler AddFileActionHandler::INSTANCE;

AddFileActionHandler::AddFileActionHandler()
{
    //ctor
}

void AddFileActionHandler::handleEvent(cbGitFile& file, GitModel& gitModel) {
        string workDir = file.getProjectPath();
        string fileName = file.getRelativeFileName();

        GitAddCommand addCommand(workDir, fileName);
        addCommand.execute();
        updateStatus(file);
}

AddFileActionHandler::~AddFileActionHandler()
{
    //dtor
}
