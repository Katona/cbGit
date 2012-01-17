#include "MenuActionFactory.h"
#include <string>
#include "../handlers/AddFileHandler.h"
#include "../handlers/CommitFileHandler.h"
#include "../handlers/RevertFileHandler.h"
#include "ProjectAction.h"
#include "CommitProjectAction.h"
#include "MenuActionSet.h"
#include "FileAction.h"
#include "../../model/GitStatusCommand.h"
#include "../../utils/Utils.h"
#include "../../utils/cbGitFile.h"


using namespace std;

MenuActionFactory MenuActionFactory::INSTANCE = MenuActionFactory();

MenuActionFactory& MenuActionFactory::getInstance() {
    return MenuActionFactory::INSTANCE;
}

MenuActionFactory::MenuActionFactory()
{
}

auto_ptr<MenuActionSet> MenuActionFactory::getActions(cbGitFile& file) {
    auto_ptr<MenuActionSet> result(new MenuActionSet());
    result->addAction(
            createFileAction("Add", AddFileHandler::INSTANCE, file)
                      .addValidStatus(GitFileStatus::untracked));
    result->addAction(
            createFileAction("Commit ...", CommitFileHandler::INSTANCE, file)
                      .addValidStatus(GitFileStatus::modified)
                      .addValidStatus(GitFileStatus::added));
    result->addAction(
            createFileAction("Revert", RevertFileHandler::INSTANCE, file)
                      .addValidStatus(GitFileStatus::modified)
                      .addValidStatus(GitFileStatus::added));

    return result;
}

auto_ptr<MenuActionSet> MenuActionFactory::getActions(cbGitProject& project) {
    auto_ptr<MenuActionSet> result(new MenuActionSet());

    result->addAction(*(new CommitProjectAction(project)));

    return result;
}

FileAction& MenuActionFactory::createFileAction(const string& text,
                                            EventHandler& handler,
                                            cbGitFile& file) {
    FileAction* action = new FileAction(text, &handler, file);
    return *action;
}
MenuActionFactory::~MenuActionFactory()
{
    //dtor
}
