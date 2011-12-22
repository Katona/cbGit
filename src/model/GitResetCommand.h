#ifndef GITRESETCOMMAND_H
#define GITRESETCOMMAND_H

#include "GitCommand.h"


class GitResetCommand : public GitCommand
{
    public:
        GitResetCommand(const string& workDir);
        GitResetCommand& file(const string& fileName);
        virtual ~GitResetCommand();
    protected:
    private:
};

#endif // GITRESETCOMMAND_H
