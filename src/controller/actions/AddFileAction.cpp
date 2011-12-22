#include <memory>
#include <cbproject.h>
#include "AddFileAction.h"
#include "AddFileActionHandler.h"

MenuActionHandler* AddFileAction::HANDLER = new AddFileActionHandler();

AddFileAction::AddFileAction(ProjectFile& file) :
    FileAction("Add", HANDLER, file)
{
    //ctor
}

bool AddFileAction::enabledFor(const GitFileStatus& gitFileStatus) const
{
    return gitFileStatus.getStatus() == GitFileStatus::untracked;
}

AddFileAction::~AddFileAction()
{
    //dtor
}
