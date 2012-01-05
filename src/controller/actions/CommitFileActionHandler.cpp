#include "CommitFileActionHandler.h"

#include <vector>
#include "../../model/GitFileStatus.h"
#include "../../utils/Utils.h"
#include "../../model/GitCommitCommand.h"
#include "../../model/GitStatusCommand.h"
#include "../../view/CommitDlgMain.h"

using namespace std;

CommitFileActionHandler::CommitFileActionHandler()
{
    //ctor
}

void CommitFileActionHandler::onActionFired(wxCommandEvent& commandEvent) {
    ProjectFile* selectedFile = getSelectedProjectFile();
    if (selectedFile) {
        commitSelectedFile(selectedFile);
    }
}

void CommitFileActionHandler::commitSelectedFile(ProjectFile* projectFile) {

    CommitDlgDialog commitDlg(0);
    if (commitDlg.ShowModal() == wxID_OK) {
        string commitMsg = toString(commitDlg.getCommitMessage());
        string workDir =
            toString(projectFile->GetParentProject()->GetCommonTopLevelPath());
        string fileName = toString(projectFile->relativeFilename);
        GitCommitCommand commitFileCmd = GitCommitCommand::file(
                workDir, fileName, commitMsg);
        commitFileCmd.execute();
        projectFile->SetFileState(fvsVcUpToDate);
    }
}

CommitFileActionHandler::~CommitFileActionHandler()
{
    //dtor
}
