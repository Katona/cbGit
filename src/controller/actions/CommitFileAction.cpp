#include "CommitFileAction.h"
#include "../../model/GitFileStatus.h"
#include "CommitFileActionHandler.h"

EventHandler* CommitFileAction::HANDLER = new CommitFileActionHandler();

CommitFileAction::CommitFileAction(cbGitFile& file)
    : FileAction("Commit", HANDLER, file)
{
    addValidStatus(GitFileStatus::added);
    addValidStatus(GitFileStatus::modified);
}

CommitFileAction::~CommitFileAction()
{
    //dtor
}
