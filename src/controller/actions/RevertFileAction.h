#ifndef REVERTFILEACTION_H
#define REVERTFILEACTION_H

#include "FileAction.h"

class GitFileStatus;
class cbGitFile;

class RevertFileAction : public FileAction
{
    public:
        RevertFileAction(cbGitFile& file);
        virtual ~RevertFileAction();
    protected:
    private:
        static EventHandler* HANDLER;
};

#endif // REVERTFILEACTION_H
