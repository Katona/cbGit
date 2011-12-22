#include "CommitProjectAction.h"
#include "CommitFileActionHandler.h"
#include "CommitProjectActionHandler.h"
#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../Utils.h"

MenuActionHandler* CommitProjectAction::HANDLER = new CommitProjectActionHandler();

CommitProjectAction::CommitProjectAction(cbProject& project) :
    ProjectAction("Commit...", HANDLER, project)
{
    //ctor
}

bool CommitProjectAction::enabledFor(cbProject& project) const {

    string workDir = toString(project.GetCommonTopLevelPath());

    GitModel gitModel(workDir);
    vector<GitFileStatus> statuses;
    gitModel.getStatus(statuses);
    return !statuses.empty();
}

CommitProjectAction::~CommitProjectAction()
{
    //dtor
}
