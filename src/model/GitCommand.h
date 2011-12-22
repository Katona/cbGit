#ifndef GITCOMMAND_H
#define GITCOMMAND_H

#include <string>
#include "ShellCommand.h"

using namespace std;

class GitCommand : public ShellCommand
{
    public:
        GitCommand(const string& workDir);
        virtual ~GitCommand();
    protected:
        const string& getWorkDir();
    private:
        const string m_workDir;
};

#endif // GITCOMMAND_H
