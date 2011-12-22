#ifndef PROJECTUPDATER_H
#define PROJECTUPDATER_H

#include <set>
#include <vector>
#include <cbproject.h>
#include <globals.h>

#include "../model/GitFileStatus.h"
#include "../FilesByFolder.h"


using namespace std;

class ProjectFile;
class FilesByFolder;
class ProjectFileUpdater;

class ProjectUpdater
{
    public:
        ProjectUpdater();
        void updateProjects(vector<cbProject*>& projects);
        void updateProject(cbProject& project);
        virtual ~ProjectUpdater();
    protected:
    private:

        FilesByFolder m_filesByFolder;

        void updateProjectFiles(cbProject& cbProject,
                                vector<GitFileStatus>& gitFileStatuses);
        FileVisualState convert(GitFileStatus::FileStatus fileStatus);
        void init(cbProject& project);
        void traceProjectFiles(cbProject& proj);
        void markFolderAsUntracked(const string& folder, ProjectFileUpdater& fileUpdater);
};

#endif // PROJECTUPDATER_H
