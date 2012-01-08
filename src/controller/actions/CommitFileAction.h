#ifndef COMMITFILEACTION_H
#define COMMITFILEACTION_H

#include "FileAction.h"


class CommitFileAction : public FileAction
{
    public:
        CommitFileAction(cbGitFile& file);
        virtual bool enabledFor(const GitFileStatus& status) const;
        virtual ~CommitFileAction();
    protected:
    private:
        static MenuActionHandler* HANDLER;
};

#endif // COMMITFILEACTION_H
