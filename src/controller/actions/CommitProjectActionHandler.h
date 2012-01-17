#ifndef COMMITPROJECTACTIONHANDLER_H
#define COMMITPROJECTACTIONHANDLER_H

#include <string>
#include "../event/ProjectEventHandler.h"

using namespace std;


class CommitProjectActionHandler : public ProjectEventHandler
{
    public:
        CommitProjectActionHandler();
        virtual ~CommitProjectActionHandler();
    protected:
        virtual void handleEvent(cbGitProject& project, GitModel& model);
    private:
        void stageNecessaryFiles(const string& workDir);
};

#endif // COMMITPROJECTACTIONHANDLER_H
