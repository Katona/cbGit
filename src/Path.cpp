#include "Path.h"

Path::Path(const string& relativeFileName)
{
    m_fullPath = getPathWithoutTrailingSeparator(relativeFileName);
    m_currentSeparatorIndex = -1;
}

string Path::getPathWithoutTrailingSeparator(const string& relativeFileName) {
    if (relativeFileName.find('/') == string::npos) {
        return "";
    }
    size_t lastSeparatorIndex = relativeFileName.find_last_of('/');
    return relativeFileName.substr(0, lastSeparatorIndex);
}

string Path::getCurrentPath() const {
    return m_currentSeparatorIndex < 1
            ? ""
            : m_fullPath.substr(0, m_currentSeparatorIndex);
}

const string& Path::getFullPath() const {
    return m_fullPath;
}

void Path::step() {
    if (!endReached()) {
        m_currentSeparatorIndex =
                m_fullPath.find('/', m_currentSeparatorIndex + 1);
        if (m_currentSeparatorIndex == string::npos) {
            m_currentSeparatorIndex = m_fullPath.size();
        }
    }
}

void Path::reset() {
    m_currentSeparatorIndex = -1;
}

bool Path::endReached() const {
    return ((m_fullPath.size() == 0) ||
            (m_currentSeparatorIndex == m_fullPath.size()));
}

Path::~Path()
{
    //dtor
}
