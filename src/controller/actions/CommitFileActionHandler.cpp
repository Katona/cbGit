#include "CommitFileActionHandler.h"

#include <vector>
#include "../../model/GitFileStatus.h"
#include "../../model/GitCommitCommand.h"
#include "../../model/GitModel.h"
#include "../../view/CommitDlgMain.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitFile.h"

using namespace std;

CommitFileActionHandler CommitFileActionHandler::INSTANCE;

CommitFileActionHandler::CommitFileActionHandler()
{
    //ctor
}

void CommitFileActionHandler::handleEvent(cbGitFile& file, GitModel& gitModel) {
    CommitDlgDialog commitDlg(0);
    if (commitDlg.ShowModal() == wxID_OK) {
        commitFile(file, gitModel);
    }
}

void CommitFileActionHandler::commitFile(cbGitFile& file, GitModel& gitModel) {

    CommitDlgDialog commitDlg(0);
    if (commitDlg.ShowModal() == wxID_OK) {
        string commitMsg = toString(commitDlg.getCommitMessage());
        string workDir = file.getProjectPath();
        string fileName = file.getRelativeFileName();
        GitCommitCommand commitFileCmd = GitCommitCommand::file(
                workDir, fileName, commitMsg);
        commitFileCmd.execute();
        updateStatus(file);
    }
}

CommitFileActionHandler::~CommitFileActionHandler()
{
    //dtor
}
