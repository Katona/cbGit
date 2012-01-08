#ifndef COMMITACTIONHANDLER_H
#define COMMITACTIONHANDLER_H

#include "FileActionHandler.h"

class cbGitFile;
class GitModel;

class CommitFileActionHandler : public FileActionHandler
{
    public:
        CommitFileActionHandler();
        virtual void handleAction(cbGitFile& file, GitModel& gitModel);
        virtual ~CommitFileActionHandler();
    protected:
    private:
        void commitFile(cbGitFile& file, GitModel& gitModel);
};

#endif // COMMITACTIONHANDLER_H
