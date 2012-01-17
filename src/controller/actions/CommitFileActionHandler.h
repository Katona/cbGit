#ifndef COMMITACTIONHANDLER_H
#define COMMITACTIONHANDLER_H

#include "../event/FileEventHandler.h"

class cbGitFile;
class GitModel;

class CommitFileActionHandler : public FileEventHandler
{
    public:
        static CommitFileActionHandler INSTANCE;

        CommitFileActionHandler();

        virtual ~CommitFileActionHandler();
    protected:
        virtual void handleEvent(cbGitFile& file, GitModel& gitModel);
    private:
        void commitFile(cbGitFile& file, GitModel& gitModel);
};

#endif // COMMITACTIONHANDLER_H
