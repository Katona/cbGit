#ifndef PATH_H
#define PATH_H

#include <string>

using namespace std;

class Path
{
    public:
        Path(const string& path);

        /**
         Returns the specified absolutePath as a relative to path to the path
         represented by this instance.
         The result can be an empty string.
         */
        string getRelative(const string& absolutePath) const;
        const string& getPathStr();
        bool isDirectory() const;
        virtual ~Path();
    protected:
    private:
        string m_path;
};

#endif // PATH_H
