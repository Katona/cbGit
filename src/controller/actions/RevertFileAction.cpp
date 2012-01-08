#include "RevertFileAction.h"
#include "RevertFileActionHandler.h"
#include "../../model/GitFileStatus.h"

MenuActionHandler* RevertFileAction::HANDLER = new RevertFileActionHandler();

RevertFileAction::RevertFileAction(cbGitFile& file) :
    FileAction("Revert", HANDLER, file)
{
    //ctor
}

bool RevertFileAction::enabledFor(const GitFileStatus& status) const{
    return ((status.getStatus() == GitFileStatus::modified) ||
            (status.getStatus() == GitFileStatus::added));
}

RevertFileAction::~RevertFileAction()
{
    //dtor
}
