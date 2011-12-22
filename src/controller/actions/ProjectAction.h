#ifndef PROJECTACTION_H
#define PROJECTACTION_H

#include "MenuAction.h"

class cbProject;
class MenuActionHandler;

class ProjectAction : public MenuAction
{
    public:
        ProjectAction(const string& actionText, MenuActionHandler* handler,
                      cbProject& project);
        bool isEnabled() const;
        virtual ~ProjectAction();
    protected:
        virtual bool enabledFor(cbProject& project) const = 0;
    private:
        cbProject& m_project;
};

#endif // PROJECTACTION_H
