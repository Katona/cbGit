#include "MenuActionFactory.h"
#include <string>
#include "AddFileAction.h"
#include "ProjectAction.h"
#include "CommitFileAction.h"
#include "CommitProjectAction.h"
#include "RevertFileAction.h"
#include "MenuActionSet.h"
#include "../../model/GitStatusCommand.h"
#include "../../Utils.h"


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

auto_ptr<MenuActionSet> MenuActionFactory::getActions(ProjectFile& projectFile) {
    auto_ptr<MenuActionSet> result(new MenuActionSet());
    result->addAction(new AddFileAction(projectFile));
    result->addAction(new CommitFileAction(projectFile));
    result->addAction(new RevertFileAction(projectFile));

    return result;
}

auto_ptr<MenuActionSet> MenuActionFactory::getActions(cbProject& project) {
    auto_ptr<MenuActionSet> result(new MenuActionSet());

    result->addAction(new CommitProjectAction(project));

    return result;
}

MenuActionFactory::~MenuActionFactory()
{
    //dtor
}
