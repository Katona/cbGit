#ifndef FILESTATUSES_H
#define FILESTATUSES_H

#include <string>
#include <map>
#include <memory>
#include "GitFileStatus.h"

using namespace std;


class FileStatuses
{
    public:
        FileStatuses();
        GitFileStatus& createAndAdd(const string& fileName,
                    GitFileStatus::FileStatus stagingStatus,
                    GitFileStatus::FileStatus workTreeStatus);
        const GitFileStatus& getStatus(const string& fileName) const;
        bool isEmpty() const;

        virtual ~FileStatuses();
    protected:
    private:
        map<string, const GitFileStatus*> m_fileStatuses;
        /** Used to store 'none' statuses for files to which no status has
            been found in m_fileStatuses. This is needed to be able return
            references to GitFileStatus for such files as well without causing
            memory leak.
            */
        mutable map<string, const GitFileStatus*> m_virtualStatuses;

        void deleteMapValues(map<string, const GitFileStatus*> m);
        const GitFileStatus* getFileStatus(const string& fileName) const;
};

#endif // FILESTATUSES_H
