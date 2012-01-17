#include "ProjectAction.h"
#include "../../utils/cbGitProject.h"

ProjectAction::ProjectAction(const string& actionText, EventHandler* handler,
                             cbGitProject& project) :
    MenuAction(actionText, handler), m_project(project)
{
    //ctor
}

bool ProjectAction::isEnabled() const {
    return enabledFor(m_project);
}

ProjectAction::~ProjectAction()
{
    //dtor
}
