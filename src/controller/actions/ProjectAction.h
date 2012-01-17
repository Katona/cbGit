#ifndef PROJECTACTION_H
#define PROJECTACTION_H

#include "MenuAction.h"

class cbGitProject;
class MenuActionHandler;

class ProjectAction : public MenuAction
{
    public:
        ProjectAction(const string& actionText, EventHandler* handler,
                      cbGitProject& project);
        bool isEnabled() const;
        virtual ~ProjectAction();
    protected:
        virtual bool enabledFor(cbGitProject& project) const = 0;
    private:
        cbGitProject& m_project;
};

#endif // PROJECTACTION_H
