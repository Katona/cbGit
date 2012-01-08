#ifndef REVERTFILEACTION_H
#define REVERTFILEACTION_H

#include "FileAction.h"

class GitFileStatus;
class cbGitFile;

class RevertFileAction : public FileAction
{
    public:
        RevertFileAction(cbGitFile& file);
        bool enabledFor(const GitFileStatus& status) const;
        virtual ~RevertFileAction();
    protected:
    private:
        static MenuActionHandler* HANDLER;
};

#endif // REVERTFILEACTION_H
