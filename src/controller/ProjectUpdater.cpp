#include <map>
#include <projectfile.h>
#include "ProjectUpdater.h"
#include "../model/GitStatusCommand.h"
#include "../model/GitFileStatus.h"
#include "ProjectFileUpdater.h"
#include "../Utils.h"

using namespace std;

ProjectUpdater::ProjectUpdater()
{
    //ctor
}

void ProjectUpdater::init(cbProject& project) {
    for (int i = 0; i < project.GetFilesCount(); i++) {
        ProjectFile* projectFile = project.GetFile(i);
        projectFile->SetFileState(fvsVcUpToDate);
        m_filesByFolder.addFile(projectFile);
    }
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
                                vector<GitFileStatus>& gitFileStatuses) {

    ProjectFileUpdater fileUpdater;

    for (vector<GitFileStatus>::size_type i = 0; i < gitFileStatuses.size(); i++) {
        string fileName = gitFileStatuses[i].getFileName();
        wxString wxFileName = toWxStr(fileName);
        ProjectFile* projectFile = cbProject.GetFileByFilename(wxFileName);
        if (projectFile != NULL) {
            fileUpdater.updateFile((*projectFile), gitFileStatuses[i]);
        } else if (gitFileStatuses[i].getStatus() == GitFileStatus::untracked) {
            markFolderAsUntracked(fileName, fileUpdater);
        }
    }
}

void ProjectUpdater::markFolderAsUntracked(const string& folder, ProjectFileUpdater& fileUpdater) {
    const vector<ProjectFile*>& filesInFolder =
        m_filesByFolder.getFilesRecursively(folder);
    for (vector<ProjectFile*>::size_type i = 0; i < filesInFolder.size(); i++) {
        fileUpdater.updateFile(*(filesInFolder[i]), GitFileStatus::untracked);
    }
}

void ProjectUpdater::updateProject(cbProject& project) {
        GitStatusCommand statusCmd(toString(project.GetCommonTopLevelPath()));
        if (!statusCmd.isGitRepository()) {
            return;
        }
        init(project);
        traceProjectFiles(project);
        vector<GitFileStatus> gitFileStatuses;
        statusCmd.getFileStatuses(gitFileStatuses);
        updateProjectFiles(project, gitFileStatuses);
}

ProjectUpdater::~ProjectUpdater()
{
    //dtor
}
