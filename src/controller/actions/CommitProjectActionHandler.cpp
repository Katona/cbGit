#include "CommitProjectActionHandler.h"

#include <iostream>

#include "../../model/GitModel.h"
#include "../../model/GitFileStatus.h"
#include "../../Utils.h"
#include "../../view/CommitDlgMain.h"
#include "../../controller/ProjectUpdater.h"

CommitProjectActionHandler::CommitProjectActionHandler()
{
    //ctor
}

void CommitProjectActionHandler::onActionFired(wxCommandEvent& event) {
    cout << "Commiting project" << endl;
    CommitDlgDialog commitDialog(0);
    if (commitDialog.ShowModal() == wxID_OK) {
        cbProject* selectedProj = getSelectedProject();
        string workDir = toString(selectedProj->GetCommonTopLevelPath());
        string commitMsg = toString(commitDialog.getCommitMessage());
        GitModel gitModel(workDir);
        gitModel.commitAll(commitMsg);
        ProjectUpdater projUpdater;
        projUpdater.updateProject(*selectedProj);
    }
}

CommitProjectActionHandler::~CommitProjectActionHandler()
{
    //dtor
}
