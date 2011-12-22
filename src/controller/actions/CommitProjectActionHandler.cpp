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

void CommitProjectActionHandler::stageNecessaryFiles(const string& workDir) {
    GitModel gitModel(workDir);
    vector<GitFileStatus> statuses;
    gitModel.getStatus(statuses);
    vector<string> filesToStage;
    for (vector<GitFileStatus>::size_type i = 0; i < statuses.size(); i++) {
        if (statuses[i].getWorkTreeStatus() != GitFileStatus::none) {
            filesToStage.push_back(statuses[i].getFileName());
        }
    }
    gitModel.add(filesToStage);
}

CommitProjectActionHandler::~CommitProjectActionHandler()
{
    //dtor
}
