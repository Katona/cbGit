#ifndef CBGITFILE_H
#define CBGITFILE_H

#include <cbproject.h>
#include "../model/GitFileStatus.h"

class cbGitFile
{
    public:
        cbGitFile(ProjectFile& projectFile);
        const string& getRelativeFileName();
        void setState(GitFileStatus::FileStatus status);
        virtual ~cbGitFile();
    protected:
    private:
        ProjectFile& m_projectFile;
        string m_relativeFileName;
        FileVisualState convert(GitFileStatus::FileStatus fileStatus);
};

#endif // CBGITFILE_H
