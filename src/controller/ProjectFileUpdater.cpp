#include "ProjectFileUpdater.h"
#include "../utils/Utils.h"

ProjectFileUpdater::ProjectFileUpdater()
{
    //ctor
}

void ProjectFileUpdater::updateFile(ProjectFile& projFile, const GitFileStatus& gitStatus) {
    updateFile(projFile, gitStatus.getStatus());
}

void ProjectFileUpdater::updateFile(ProjectFile& projFile, GitFileStatus::FileStatus fileStatus) {
    projFile.SetFileState(convert(fileStatus));
}

FileVisualState ProjectFileUpdater::convert(GitFileStatus::FileStatus fileStatus) {
    if (fileStatus == GitFileStatus::added) {
        return fvsVcAdded;
    } else if (fileStatus == GitFileStatus::modified) {
        return fvsVcModified;
    } else if (fileStatus == GitFileStatus::untracked) {
        return fvsVcNonControlled;
    } else if (fileStatus == GitFileStatus::none) {
        return fvsVcUpToDate;
    }
    return fvsNormal;

}

ProjectFileUpdater::~ProjectFileUpdater()
{
    //dtor
}
