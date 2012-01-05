#include "Path.h"

Path::Path(const string& relativeFileName) :
    m_relativeFileName(relativeFileName)
{

}

bool Path::isDirectory() const {
    if (m_relativeFileName.empty()) {
        return false;
    }
    /* Might not be too reliable, but faster than check it */
    return m_relativeFileName[m_relativeFileName.size() - 1] == '/';
}

Path::~Path()
{
    //dtor
}
