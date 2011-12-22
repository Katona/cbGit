#include <iostream>
#include <sys/stat.h>
#include "GitStatusCommand.h"

using namespace std;

GitStatusCommand::GitStatusCommand(const string& workDir) :
    GitCommand(workDir)
{
    addArgument("status");
    addArgument("--porcelain");
}

GitStatusCommand::GitStatusCommand(const string& workDir, const string& fileName) :
    GitCommand(workDir)
{
    addArgument("status");
    addArgument(fileName);
    addArgument("--porcelain");
}

void GitStatusCommand::getFileStatuses(vector<GitFileStatus>& fileStatuses) {
    int result = execute();
    if (result == ShellCommand::RESULT_FAILURE) {
        // TODO:log
        return;
    }
    vector<string> outputLines;
    getOutputLines(outputLines);
//    cout << "Parsing output lines" << endl;
    GitFileStatus status;
    for (vector<string>::size_type i = 0; i < outputLines.size(); i++) {
        GitFileStatus status = parseLine(outputLines[i]);
//        cout << "Putting to the vector" << endl;
        fileStatuses.push_back(status);
    }


}

GitFileStatus::FileStatus GitStatusCommand::convert(char statusChar) const {
//    cout << "conversion" << endl;
    if (statusChar == 'A') {
        return GitFileStatus::added;
    } else if (statusChar == 'M') {
        return GitFileStatus::modified;
    } else if (statusChar == '?') {
        return GitFileStatus::untracked;
    } else {
        return GitFileStatus::none;
    }
}

GitFileStatus GitStatusCommand::parseLine(const string& line) const {
//    cout << "Parsing line: " << line << endl;
    char stagingStatusChar = line[0];
    char workTreeStatusChar = line[1];
    string fileName = line.substr(3);
//    cout << "Staging stat: " << stagingStatusChar << " Work Tree: " << workTreeStatusChar <<
//        "FIle Name:" << fileName << endl;
    GitFileStatus status(fileName,
                         convert(stagingStatusChar),
                         convert(workTreeStatusChar));
    return status;
}

GitStatusCommand::~GitStatusCommand()
{
    //dtor
}

bool GitStatusCommand::isGitRepository() {

    struct stat sb;

    return (stat((getWorkDir() + ".git").c_str(), &sb) == 0 && S_ISDIR(sb.st_mode));
}
