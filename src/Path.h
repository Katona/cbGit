#ifndef PATH_H
#define PATH_H

#include <string>
#include <vector>

using namespace std;

class Path
{
    public:
        Path(const string& relativeFileName);
        bool isDirectory() const;
        virtual ~Path();
    protected:
    private:
        string m_relativeFileName;
};

#endif // PATH_H
