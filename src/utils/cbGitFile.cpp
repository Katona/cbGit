#include "cbGitFile.h"
#include "Utils.h"

cbGitFile::cbGitFile(ProjectFile& projectFile) :
    m_projectFile(projectFile),
    m_projectPath(toString(projectFile.GetParentProject()->GetCommonTopLevelPath())),
    m_relativeFileName(toString(projectFile.relativeFilename))
{
    //ctor
}

const string& cbGitFile::getRelativeFileName() const {
    return m_relativeFileName;
}

const string& cbGitFile::getProjectPath() const {
    return m_projectPath;
}

void cbGitFile::setState(GitFileStatus::FileStatus status) {
    m_projectFile.SetFileState(convert(status));
}

FileVisualState cbGitFile::convert(GitFileStatus::FileStatus fileStatus) {
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

cbGitFile::~cbGitFile()
{
    //dtor
}
