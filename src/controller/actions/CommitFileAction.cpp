#include "CommitFileAction.h"
#include "../../model/GitFileStatus.h"
#include "CommitFileActionHandler.h"

MenuActionHandler* CommitFileAction::HANDLER = new CommitFileActionHandler();

CommitFileAction::CommitFileAction(ProjectFile& file)
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
