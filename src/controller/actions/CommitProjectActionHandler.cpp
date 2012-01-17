#include "CommitProjectActionHandler.h"

#include <iostream>

#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitProject.h"
#include "../../view/CommitDlgMain.h"

CommitProjectActionHandler::CommitProjectActionHandler()
{
    //ctor
}

void CommitProjectActionHandler::handleEvent(cbGitProject& project, GitModel& model) {
    cout << "Commiting project" << endl;
    CommitDlgDialog commitDialog(0);
    if (commitDialog.ShowModal() == wxID_OK) {
        string commitMsg = toString(commitDialog.getCommitMessage());
        GitModel gitModel(project.getTopLevelPath());
        gitModel.commitAll(commitMsg);
        updateStatus(project);
    }
}

CommitProjectActionHandler::~CommitProjectActionHandler()
{
    //dtor
}
