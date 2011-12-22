#include "ProjectAction.h"

ProjectAction::ProjectAction(const string& actionText, MenuActionHandler* handler,
                             cbProject& project) :
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
