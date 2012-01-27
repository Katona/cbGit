#include "CommitProjectHandler.h"

#include <iostream>

#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../model/FileStatuses.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitProject.h"
#include "../../view/CommitProjectDlg.h"

CommitProjectHandler::CommitProjectHandler()
{
    //ctor
}

void CommitProjectHandler::handleEvent(cbGitProject& project, GitModel& model) {
    cout << "Committing project" << endl;
    FileStatuses statuses;
    GitModel gitModel(project.getTopLevelPath());
    gitModel.getStatus(statuses);

    CommitProjectDlg commitDialog(project, statuses);
    if (commitDialog.ShowModal() == wxID_OK) {
        string commitMsg = commitDialog.getCommitMessage();
        gitModel.commitAll(commitMsg);
        updateStatus(project);
    }
}

CommitProjectHandler::~CommitProjectHandler()
{
    //dtor
}
