#include <map>
#include <projectfile.h>
#include "ProjectUpdater.h"
#include "../model/GitStatusCommand.h"
#include "../model/GitFileStatus.h"
#include "../model/FileStatuses.h"
#include "ProjectFileUpdater.h"
#include "../utils/Utils.h"

using namespace std;

ProjectUpdater::ProjectUpdater()
{
    //ctor
}

void ProjectUpdater::updateProjects(vector<cbProject*>& projects) {
    for (vector<cbProject*>::size_type i = 0; i < projects.size(); i++) {
        updateProject(*projects[i]);
    }
}

void ProjectUpdater::traceProjectFiles(cbProject& proj) {
    for (int i = 0; i < proj.GetFilesCount(); i++) {
        ProjectFile* file = proj.GetFile(i);
//        cout << string(file->GetBaseName().mb_str()) << endl;
//        cout << string(file->relativeToCommonTopLevelPath.mb_str()) << endl;
        cout << string(file->relativeFilename.mb_str()) << endl;
    }
}

void ProjectUpdater::updateProjectFiles(cbProject& cbProject,
                                const FileStatuses& gitFileStatuses) {

    ProjectFileUpdater fileUpdater;

    for (int i = 0; i < cbProject.GetFilesCount(); i++) {
        ProjectFile* prFile = cbProject.GetFile(i);
        if (prFile == NULL) {
            // Should not happen
            // TODO: log
            continue;
        }
        string fileName = toString(prFile->relativeFilename);
        const GitFileStatus& status = gitFileStatuses.getStatus(fileName);
        fileUpdater.updateFile((*prFile), status);
    }
}

void ProjectUpdater::updateProject(cbProject& project) {
        GitStatusCommand statusCmd(toString(project.GetCommonTopLevelPath()));
        if (!statusCmd.isGitRepository()) {
            return;
        }
        traceProjectFiles(project);
        FileStatuses gitFileStatuses;
        statusCmd.getFileStatuses(gitFileStatuses);
        updateProjectFiles(project, gitFileStatuses);
}

ProjectUpdater::~ProjectUpdater()
{
    //dtor
}
