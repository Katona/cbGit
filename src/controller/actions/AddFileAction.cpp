#include <memory>
#include <cbproject.h>
#include "AddFileAction.h"
#include "AddFileActionHandler.h"

FileEventHandler* AddFileAction::HANDLER = new AddFileActionHandler();

AddFileAction::AddFileAction(cbGitFile& file) :
    FileAction("Add", HANDLER, file)
{
   addValidStatus(GitFileStatus::untracked);
}

AddFileAction::~AddFileAction()
{
    //dtor
}
