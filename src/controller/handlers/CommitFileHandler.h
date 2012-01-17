#ifndef COMMITACTIONHANDLER_H
#define COMMITACTIONHANDLER_H

#include "FileEventHandler.h"

class cbGitFile;
class GitModel;

class CommitFileHandler : public FileEventHandler
{
    public:
        static CommitFileHandler INSTANCE;

        CommitFileHandler();

        virtual ~CommitFileHandler();
    protected:
        virtual void handleEvent(cbGitFile& file, GitModel& gitModel);
    private:
        void commitFile(cbGitFile& file, GitModel& gitModel);
};

#endif // COMMITACTIONHANDLER_H
