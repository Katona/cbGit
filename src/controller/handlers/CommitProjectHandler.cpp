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
        vector<GitFileStatus*> selectedFiles;
        commitDialog.getSelectedFiles(selectedFiles);
        stageNecessaryFiles(model, selectedFiles);
        vector<string> fileNames;
        getFileNames(fileNames, selectedFiles);
        gitModel.commitFiles(fileNames, commitMsg);
        updateStatus(project);
    }
}

void CommitProjectHandler::stageNecessaryFiles(
        GitModel& model,
        const vector<GitFileStatus*>& fileStatuses) {
    vector<string> filesToStage;
    for (int i = 0; i < fileStatuses.size(); i++) {
        if ((fileStatuses[i]->getWorkTreeStatus() & GitFileStatus::untracked) > 0) {
            filesToStage.push_back(fileStatuses[i]->getFileName());
        }
    }
    model.add(filesToStage);
}

void CommitProjectHandler::getFileNames(vector<string>& fileNames,
                                        const vector<GitFileStatus*>& fileStatuses) {

    for (int i = 0; i < fileStatuses.size(); i++) {
        fileNames.push_back(fileStatuses[i]->getFileName());
    }
}

CommitProjectHandler::~CommitProjectHandler()
{
    //dtor
}
