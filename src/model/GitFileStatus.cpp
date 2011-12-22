#include "GitFileStatus.h"

GitFileStatus::GitFileStatus() {
}

GitFileStatus::GitFileStatus(const string& fileName, FileStatus stagingStatus,
                      FileStatus workTreeStatus) :
    m_fileName(fileName), m_stagingStatus(stagingStatus),
    m_workTreeStatus(workTreeStatus)
{
    //ctor
}

const string& GitFileStatus::getFileName() const {
    return m_fileName;
}

GitFileStatus::FileStatus GitFileStatus::getStagingStatus() const {
    return m_stagingStatus;
}

GitFileStatus::FileStatus GitFileStatus::getWorkTreeStatus() const {
    return m_workTreeStatus;
}

GitFileStatus::FileStatus GitFileStatus::getStatus() const {
    FileStatus result = none;
    if (m_workTreeStatus != 0) {
        result = m_workTreeStatus;
    } else if (m_stagingStatus != 0) {
        result = m_stagingStatus;
    }
    return result;
}

GitFileStatus::~GitFileStatus()
{
    //dtor
}
