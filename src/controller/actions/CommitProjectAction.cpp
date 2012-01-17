#include "CommitProjectAction.h"
#include "CommitFileActionHandler.h"
#include "CommitProjectActionHandler.h"
#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../model/FileStatuses.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitProject.h"

EventHandler* CommitProjectAction::HANDLER = new CommitProjectActionHandler();

CommitProjectAction::CommitProjectAction(cbGitProject& project) :
    ProjectAction("Commit...", HANDLER, project)
{
    //ctor
}

bool CommitProjectAction::enabledFor(cbGitProject& project) const {

    string workDir = project.getTopLevelPath();

    GitModel gitModel(workDir);
    FileStatuses statuses;
    gitModel.getStatus(statuses);
    return !statuses.isEmpty();
}

CommitProjectAction::~CommitProjectAction()
{
    //dtor
}
