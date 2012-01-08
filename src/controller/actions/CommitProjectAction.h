#ifndef COMMITPROJECTACTION_H
#define COMMITPROJECTACTION_H

#include "ProjectAction.h"

class cbGitProject;

class CommitProjectAction : public ProjectAction
{
    public:
        CommitProjectAction(cbGitProject& project);
        virtual ~CommitProjectAction();
    protected:
    private:
        static MenuActionHandler* HANDLER;
        bool enabledFor(cbGitProject& project) const;
};

#endif // COMMITPROJECTACTION_H
