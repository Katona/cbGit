#include "GitCommand.h"

GitCommand::GitCommand(const string& workDir) :
    ShellCommand("git"), m_workDir(workDir)
{
    addArgument("--git-dir=" + workDir + ".git");
    addArgument("--work-tree=" + workDir);
}

const string& GitCommand::getWorkDir() {
    return m_workDir;
}

GitCommand::~GitCommand()
{
    //dtor
}
