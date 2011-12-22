#include "GitResetCommand.h"

GitResetCommand::GitResetCommand(const string& workDir) :
    GitCommand(workDir)
{
    addArgument("reset");
}

GitResetCommand& GitResetCommand::file(const string& fileName) {
    addArgument(fileName);
    return *this;
}

GitResetCommand::~GitResetCommand()
{
    //dtor
}
