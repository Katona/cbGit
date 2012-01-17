#ifndef COMMITPROJECTACTIONHANDLER_H
#define COMMITPROJECTACTIONHANDLER_H

#include <string>
#include "ProjectEventHandler.h"

using namespace std;


class CommitProjectHandler : public ProjectEventHandler
{
    public:
        CommitProjectHandler();
        virtual ~CommitProjectHandler();
    protected:
        virtual void handleEvent(cbGitProject& project, GitModel& model);
    private:
        void stageNecessaryFiles(const string& workDir);
};

#endif // COMMITPROJECTACTIONHANDLER_H
