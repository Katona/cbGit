#ifndef PROJECTUPDATER_H
#define PROJECTUPDATER_H

#include <set>
#include <vector>
#include <cbproject.h>
#include <globals.h>

#include "../model/GitFileStatus.h"


using namespace std;

class FileStatuses;

class ProjectUpdater
{
    public:
        ProjectUpdater();
        void updateProjects(vector<cbProject*>& projects);
        void updateProject(cbProject& project);
        virtual ~ProjectUpdater();
    protected:
    private:
        void updateProjectFiles(cbProject& cbProject,
                                const FileStatuses& statuses);
        void init(cbProject& project);
        void traceProjectFiles(cbProject& proj);
};

#endif // PROJECTUPDATER_H
