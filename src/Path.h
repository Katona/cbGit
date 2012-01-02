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
        bool endReached() const;
        string getCurrentPath() const;
        const string& getFullPath() const;
        virtual ~Path();
    protected:
    private:
        string m_fullPath;
        int m_currentSeparatorIndex;

        string getPathWithoutTrailingSeparator(const string& relativeFileName);
};

#endif // PATH_H
