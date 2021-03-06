#include "cbGitProject.h"
#include "cbGitFile.h"
#include "Utils.h"
#include "Path.h"


cbGitProject::cbGitProject(cbProject& cbProject) :
    m_cbProject(cbProject),
    m_topLevelPath(toString(cbProject.GetCommonTopLevelPath()))

{
    Path path(m_topLevelPath);
    m_relativeProjectFileName =
            path.getRelative(toString(cbProject.GetFilename()));
    addAllGitFiles();
}

const string& cbGitProject::getTopLevelPath() const
{
    return m_topLevelPath;
}

cbGitFile* cbGitProject::getFile(const string& relativeFileName) {
    return m_files[relativeFileName];
}

vector<cbGitFile*> cbGitProject::getFiles() const {
    vector<cbGitFile*> result;
    map<string, cbGitFile*>::const_iterator it;
    for (it = m_files.begin(); it != m_files.end(); it++) {
        result.push_back(it->second);
    }
    return result;
}

void cbGitProject::addAllGitFiles() {
    for (int i = 0; i < m_cbProject.GetFilesCount(); i++) {
        cbGitFile* gitFile = new cbGitFile(*m_cbProject.GetFile(i));
        m_files[gitFile->getRelativeFileName()] = gitFile;
    }
}

const string& cbGitProject::getRelativeFileName() const {
    return m_relativeProjectFileName;
}

cbGitProject::~cbGitProject()
{
    map<string, cbGitFile*>::const_iterator it;
    for (it = m_files.begin(); it != m_files.end(); it++) {
        delete it->second;
    }
}
