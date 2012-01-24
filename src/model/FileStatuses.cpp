#include "FileStatuses.h"
#include "GitFileStatus.h"
#include "../utils/Path.h"
#include "../utils/Utils.h"

FileStatuses::FileStatuses()
{
    //ctor
}

GitFileStatus& FileStatuses::createAndAdd(const string& fileName,
                    GitFileStatus::FileStatus stagingStatus,
                    GitFileStatus::FileStatus workTreeStatus) {

    GitFileStatus* newStatus = new GitFileStatus(fileName,
                                                 stagingStatus,
                                                 workTreeStatus);
    m_fileStatuses[fileName] = newStatus;
}

const GitFileStatus& FileStatuses::getStatus(const string& fileName) const {
    /* For files which are has not status information from Git */
    const GitFileStatus* result = getFileStatus(fileName);;

    if (result == NULL) {
        result = new GitFileStatus(fileName, GitFileStatus::none,
                         GitFileStatus::none);
        m_virtualStatuses[fileName] = result;
    }
    return (*result);
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
    return m_fileStatuses.empty();
}

FileStatuses::~FileStatuses()
{
    deleteMapValues(m_fileStatuses);
    deleteMapValues(m_virtualStatuses);
}
