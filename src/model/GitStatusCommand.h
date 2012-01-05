#ifndef GITSTATUSCOMMAND_H
#define GITSTATUSCOMMAND_H

#include <string>
#include <vector>
#include <memory>
#include "GitCommand.h"
#include "GitFileStatus.h"

using namespace std;

class FileStatuses;

class GitStatusCommand : public GitCommand
{
    public:
        GitStatusCommand(const string& workDir);
        GitStatusCommand(const string& workDir, const string& fileName);
        void getFileStatuses(FileStatuses& statuses);
        bool isGitRepository();
        virtual ~GitStatusCommand();
    protected:
    private:

        GitFileStatus* parseLine(const string& line) const;
        GitFileStatus::FileStatus convert(char statusChar) const;
};

#endif // GITSTATUSCOMMAND_H
