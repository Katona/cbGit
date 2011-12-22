#ifndef REVERTFILEACTION_H
#define REVERTFILEACTION_H

#include <cbproject.h>
#include "FileAction.h"

class GitFileStatus;

class RevertFileAction : public FileAction
{
    public:
        RevertFileAction(ProjectFile& file);
        bool enabledFor(const GitFileStatus& status) const;
        virtual ~RevertFileAction();
    protected:
    private:
        static MenuActionHandler* HANDLER;
};

#endif // REVERTFILEACTION_H
