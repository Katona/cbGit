#include "GitAddCommand.h"

GitAddCommand::GitAddCommand(const string& workDir, const string& fileName) :
        GitCommand(workDir) {
    addArgument("add");
    addArgument(fileName);
}
GitAddCommand::GitAddCommand(const string& workDir,
                             const vector<string>& files) :
        GitCommand(workDir) {
    addArgument("add");
    addArguments(files);
}

GitAddCommand::~GitAddCommand() {
}
