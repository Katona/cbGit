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
        GitStatusCommand(const string& workDir,
                         bool traverseUntrackedFolder = true);
        GitStatusCommand(const string& workDir, const string& fileName);
        void getFileStatuses(FileStatuses& statuses);
        bool isGitRepository();
        virtual ~GitStatusCommand();
    protected:
    private:

        bool m_traverseUntrackedFolder;
        GitFileStatus* processLine(FileStatuses& statuses,
                                   const string& line);
        GitFileStatus::FileStatus convert(char statusChar) const;
        void traverseUntrackedFolder(
                FileStatuses& statuses, const string& folder);
};

#endif // GITSTATUSCOMMAND_H
