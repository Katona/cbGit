#include "MenuActionFactory.h"
#include <string>
#include "AddFileAction.h"
#include "AddFileActionHandler.h"
#include "CommitFileActionHandler.h"
#include "RevertFileActionHandler.h"
#include "ProjectAction.h"
#include "CommitFileAction.h"
#include "CommitProjectAction.h"
#include "RevertFileAction.h"
#include "MenuActionSet.h"
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
//    m_fileActions.push_back(new AddFileAction());
//    m_fileActions.push_back(new CommitFileAction());
//    m_fileActions.push_back(new RevertFileAction());

//    m_projectActions.push_back(new CommitProjectAction());
}

auto_ptr<MenuActionSet> MenuActionFactory::getActions(cbGitFile& file) {
    auto_ptr<MenuActionSet> result(new MenuActionSet());
    result->addAction(
            createFileAction("Add", AddFileActionHandler::INSTANCE, file)
                      .addValidStatus(GitFileStatus::untracked));
    result->addAction(
            createFileAction("Commit ...", CommitFileActionHandler::INSTANCE, file)
                      .addValidStatus(GitFileStatus::modified)
                      .addValidStatus(GitFileStatus::added));
    result->addAction(
            createFileAction("Revert", RevertFileActionHandler::INSTANCE, file)
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
