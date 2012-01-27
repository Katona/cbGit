#include "GitCommitCommand.h"

string GitCommitCommand::EMPTY_MESSAGE = "Empty commit message";

GitCommitCommand::GitCommitCommand(const string& workDir, const string& message) :
    GitCommand(workDir)
{
    addArgument("commit");
    addArgument("-m \"" + message +"\"");
}

GitCommitCommand GitCommitCommand::all(const string& workDir, const string& message) {
    GitCommitCommand result(workDir, message);
    result.addArgument("-a");
    return result;
}

GitCommitCommand GitCommitCommand::file(const string& workDir,
                                        const string& fileName,
                                        const string& message) {
    GitCommitCommand result(workDir, message);
    result.addArgument(fileName);
    return result;
}

GitCommitCommand GitCommitCommand::files(const string& workDir,
                                        const vector<string>& fileNames,
                                        const string& message) {
    GitCommitCommand result(workDir, message);
    result.addArgument("--");
    result.addArguments(fileNames);
    return result;
}

GitCommitCommand::~GitCommitCommand()
{
    //dtor
}
