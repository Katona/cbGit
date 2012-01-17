#include "RevertFileAction.h"
#include "RevertFileActionHandler.h"
#include "../../model/GitFileStatus.h"

EventHandler* RevertFileAction::HANDLER = new RevertFileActionHandler();

RevertFileAction::RevertFileAction(cbGitFile& file) :
    FileAction("Revert", HANDLER, file)
{
    addValidStatus(GitFileStatus::modified);
    addValidStatus(GitFileStatus::added);
}

RevertFileAction::~RevertFileAction()
{
    //dtor
}
