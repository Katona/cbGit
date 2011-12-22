#ifndef PATH_H
#define PATH_H

#include <string>
#include <vector>

using namespace std;

class Path
{
    public:
        Path(const string& relativeFileName);
        void reset();
        void step();
        bool endReached();
        string getCurrentPath();
        virtual ~Path();
    protected:
    private:
        string m_fullPath;
        int m_currentSeparatorIndex;

        string getPathWithTrailingSeparator(const string& relativeFileName);
};

#endif // PATH_H
