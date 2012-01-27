#include <iostream>
#include <sys/stat.h>
#include <wx/dir.h>
#include <wx/arrstr.h>
#include <wx/string.h>
#include "GitStatusCommand.h"
#include "FileStatuses.h"
#include "../utils/Path.h"
#include "../utils/Utils.h"

using namespace std;

GitStatusCommand::GitStatusCommand(const string& workDir) :
    GitCommand(workDir)
{
    addArgument("status");
    addArgument("-u");
    addArgument("--porcelain");
}

GitStatusCommand::GitStatusCommand(const string& workDir, const string& fileName) :
    GitCommand(workDir)
{
    addArgument("status");
    addArgument(fileName);
    addArgument("--porcelain");
}

void GitStatusCommand::getFileStatuses(FileStatuses& fileStatuses) {
    int cmdRes = execute();
    if (cmdRes == ShellCommand::RESULT_FAILURE) {
        // TODO:log
        return;
    }
    vector<string> outputLines;
    getOutputLines(outputLines);
    for (vector<string>::size_type i = 0; i < outputLines.size(); i++) {
        processLine(fileStatuses, outputLines[i]);
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

GitFileStatus* GitStatusCommand::processLine(FileStatuses& statuses,
                                             const string& line) {
//    cout << "Parsing line: " << line << endl;
    GitFileStatus::FileStatus stagingStatus = convert(line[0]);
    GitFileStatus::FileStatus workTreeStatus = convert(line[1]);
    string fileName = line.substr(3);
//    cout << "Staging stat: " << stagingStatusChar << " Work Tree: " << workTreeStatusChar <<
//        "FIle Name:" << fileName << endl;
    statuses.createAndAdd(fileName, stagingStatus, workTreeStatus);
}

GitStatusCommand::~GitStatusCommand()
{
    //dtor
}

bool GitStatusCommand::isGitRepository() {

    struct stat sb;

    return (stat((getWorkDir() + ".git").c_str(), &sb) == 0 && S_ISDIR(sb.st_mode));
}
