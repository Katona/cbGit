#include "Path.h"
#include "Utils.h"

Path::Path(const string& path) :
    m_path(path)
{

}

string Path::getRelative(const string& absolutePath) const {
    string result;
    if (startsWith(absolutePath, m_path)) {
        result = absolutePath.substr(m_path.size());
    }
    return result;
}

const string& Path::getPathStr() {
    return m_path;
}

bool Path::isDirectory() const {
    if (m_path.empty()) {
        return false;
     }
    /* Might not be too reliable, but faster than check it */
    return m_path[m_path.size() - 1] == '/';
}


Path::~Path()
{
    //dtor
}
