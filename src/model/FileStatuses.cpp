#include "FileStatuses.h"
#include "GitFileStatus.h"
#include "../utils/Path.h"
#include "../utils/Utils.h"

FileStatuses::FileStatuses()
{
    //ctor
}

void FileStatuses::add(auto_ptr<const GitFileStatus> status) {
    map<string, const GitFileStatus*>* statusMap = &m_fileStatuses;
    Path path(status->getFileName());

    if (path.isDirectory()) {
        statusMap = &m_folderStatuses;
    }
    const GitFileStatus* statusPtr = status.release();
    (*statusMap)[statusPtr->getFileName()] = statusPtr;
}

GitFileStatus FileStatuses::getStatus(const string& fileName) const {

    /* For files which are has not status information from Git */
    GitFileStatus result(fileName, GitFileStatus::none,
                         GitFileStatus::none);

    const GitFileStatus* status = getFileStatus(fileName);
    if (status != NULL) {
        result = (*status);
    } else if (isInUntrackedFolder(fileName)) {
        /* We consider a file untracked if it is an untracked folder. Might not
           be completely true, some files may be ignored by Git (.gitignore)
        */
        result = GitFileStatus(fileName, GitFileStatus::untracked,
                         GitFileStatus::untracked);
    }
    return result;

}

bool FileStatuses::isInUntrackedFolder(const string& fileName) const {
    map<string, const GitFileStatus*>::const_iterator it;
    for (it = m_folderStatuses.begin(); it != m_folderStatuses.end(); it++) {
        string folderName = (*it).first;
        const GitFileStatus* status = (*it).second;
        if ((startsWith(fileName, folderName)) &&
                (status->getStatus() == GitFileStatus::untracked)) {
            return true;
        }
    }
    return false;
}

void FileStatuses::deleteMapValues(map<string, const GitFileStatus*> m) {
    map<string, const GitFileStatus*>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        delete (*it).second;
    }
}

const GitFileStatus* FileStatuses::getFileStatus(const string& fileName) const {
    map<string, const GitFileStatus*>::const_iterator it =
        m_fileStatuses.find(fileName);
    if (it != m_fileStatuses.end()) {
        return (*it).second;
    } else {
        return NULL;
    }
}

bool FileStatuses::isEmpty() const {
    return m_fileStatuses.empty() && m_folderStatuses.empty();
}

FileStatuses::~FileStatuses()
{
    deleteMapValues(m_fileStatuses);
    deleteMapValues(m_folderStatuses);
}
