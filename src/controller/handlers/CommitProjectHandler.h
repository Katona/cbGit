#ifndef COMMITPROJECTACTIONHANDLER_H
#define COMMITPROJECTACTIONHANDLER_H

#include <string>
#include <vector>
#include "ProjectEventHandler.h"

using namespace std;

class GitFileStatus;

class CommitProjectHandler : public ProjectEventHandler
{
    public:
        CommitProjectHandler();
        virtual ~CommitProjectHandler();
    protected:
        virtual void handleEvent(cbGitProject& project, GitModel& model);
    private:
        void stageNecessaryFiles(GitModel& model,
                                 const vector<GitFileStatus*>& fileStatuses);
        void getFileNames(vector<string>& fileNames,
                          const vector<GitFileStatus*>& fileStatuses);
};

#endif // COMMITPROJECTACTIONHANDLER_H
