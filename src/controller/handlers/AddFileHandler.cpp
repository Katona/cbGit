#include <sdk.h>
#include <manager.h>
#include <projectmanager.h>
#include <cbproject.h>

#include "AddFileHandler.h"
#include "../../model/GitAddCommand.h"
#include "../../model/GitStatusCommand.h"
#include "../../model/FileStatuses.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitFile.h"


AddFileHandler AddFileHandler::INSTANCE;

AddFileHandler::AddFileHandler()
{
    //ctor
}

void AddFileHandler::handleEvent(cbGitFile& file, GitModel& gitModel) {
        string workDir = file.getProjectPath();
        string fileName = file.getRelativeFileName();

        GitAddCommand addCommand(workDir, fileName);
        addCommand.execute();
        updateStatus(file);
}

AddFileHandler::~AddFileHandler()
{
    //dtor
}
