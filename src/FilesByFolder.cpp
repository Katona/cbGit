#include "FilesByFolder.h"
#include "Utils.h"
#include "Path.h"


const vector<ProjectFile*> FilesByFolder::EMPTY_PRFILE_VECTOR;// = vector<ProjectFile*>();

FilesByFolder::FilesByFolder()
{
    //ctor
}

void FilesByFolder::addFile(ProjectFile* file) {
    string fileName = toString(file->relativeFilename);
    Path filePath(fileName);
    while (!filePath.endReached()) {
        filePath.step();
        addFileToFolder(filePath.getCurrentPath(), file);
    }
}

void FilesByFolder::addFileToFolder(const string& folder, ProjectFile* file) {
    vector<ProjectFile*>* filesInFolder = m_filesByFolder[folder];
    if (filesInFolder == NULL) {
        filesInFolder = new vector<ProjectFile*>();
        m_filesByFolder[folder] = filesInFolder;
    }
    filesInFolder->push_back(file);
}

const vector<ProjectFile*>& FilesByFolder::getFilesRecursively(const string& folder) {
    Path path(folder);
    vector<ProjectFile*>* files = m_filesByFolder[path.getFullPath()];
    return files == NULL
            ? EMPTY_PRFILE_VECTOR
            : *files;
}

FilesByFolder::~FilesByFolder()
{
    for (map<string, vector<ProjectFile*>* >::iterator it = m_filesByFolder.begin(); it != m_filesByFolder.end(); it++) {
        delete it->second;
    }
}
