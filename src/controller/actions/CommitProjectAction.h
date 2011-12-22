#ifndef COMMITPROJECTACTION_H
#define COMMITPROJECTACTION_H

#include <cbproject.h>
#include "ProjectAction.h"

class cbProject;

class CommitProjectAction : public ProjectAction
{
    public:
        CommitProjectAction(cbProject& project);
        virtual ~CommitProjectAction();
    protected:
    private:
        static MenuActionHandler* HANDLER;
        bool enabledFor(cbProject& project) const;
};

#endif // COMMITPROJECTACTION_H
