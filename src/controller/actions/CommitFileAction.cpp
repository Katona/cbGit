#include "CommitFileAction.h"
#include "../../model/GitFileStatus.h"
#include "CommitFileActionHandler.h"

EventHandler* CommitFileAction::HANDLER = new CommitFileActionHandler();

CommitFileAction::CommitFileAction(cbGitFile& file)
    : FileAction("Commit", HANDLER, file)
{
    //ctor
}

bool CommitFileAction::enabledFor(const GitFileStatus& status) const {
    return ((status.getStatus() == GitFileStatus::modified) ||
            (status.getStatus() == GitFileStatus::added));
}

CommitFileAction::~CommitFileAction()
{
    //dtor
}
