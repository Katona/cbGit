#ifndef GITSTATUSCOMMAND_H
#define GITSTATUSCOMMAND_H

#include <string>
#include <vector>
#include "GitCommand.h"
#include "GitFileStatus.h"

using namespace std;

class GitStatusCommand : public GitCommand
{
    public:
        GitStatusCommand(const string& workDir);
        GitStatusCommand(const string& workDir, const string& fileName);
        void getFileStatuses(vector<GitFileStatus>& fileStatuses);
        bool isGitRepository();
        virtual ~GitStatusCommand();
    protected:
    private:

        GitFileStatus parseLine(const string& line) const;
        GitFileStatus::FileStatus convert(char statusChar) const;
};

#endif // GITSTATUSCOMMAND_H
