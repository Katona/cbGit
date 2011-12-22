#include "Path.h"

Path::Path(const string& relativeFileName)
{
    m_fullPath = getPathWithTrailingSeparator(relativeFileName);
    m_currentSeparatorIndex = -1;
}

string Path::getPathWithTrailingSeparator(const string& relativeFileName) {
    if (relativeFileName.find('/') == relativeFileName.npos) {
        return "";
    }
    size_t lastSeparatorIndex = relativeFileName.find_last_of('/');
    return relativeFileName.substr(0, lastSeparatorIndex + 1);
}

string Path::getCurrentPath() {
    return m_currentSeparatorIndex < 1
            ? ""
            : m_fullPath.substr(0, m_currentSeparatorIndex);
}

void Path::step() {
    if (!endReached()) {
        m_currentSeparatorIndex =
                m_fullPath.find('/', m_currentSeparatorIndex + 1);
    }
}

void Path::reset() {
    m_currentSeparatorIndex = -1;
}

bool Path::endReached() {
    return ((m_fullPath.size() == 0) ||
            (m_currentSeparatorIndex == m_fullPath.size() - 1));
}

Path::~Path()
{
    //dtor
}
