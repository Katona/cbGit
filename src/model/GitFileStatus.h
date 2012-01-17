#ifndef GITFILESTATUS_H
#define GITFILESTATUS_H

#include <string>

using namespace std;


class GitFileStatus
{
    public:
        enum FileStatus { none = 1, modified = 2, added = 4, untracked = 8};
        GitFileStatus();
        GitFileStatus(const string& fileName, FileStatus stagingStatus,
                      FileStatus workTreeStatus);
        FileStatus getStagingStatus() const;
        FileStatus getWorkTreeStatus() const;
        FileStatus getStatus() const;
        const string& getFileName() const;
        virtual ~GitFileStatus();
    protected:
    private:
        string m_fileName;
        FileStatus m_stagingStatus;
        FileStatus m_workTreeStatus;
};

#endif // GITFILESTATUS_H
