#ifndef FILESTATUSES_H
#define FILESTATUSES_H

#include <string>
#include <map>
#include <memory>

using namespace std;

class GitFileStatus;

class FileStatuses
{
    public:
        FileStatuses();
        void add(auto_ptr<const GitFileStatus> status);
        GitFileStatus getStatus(const string& fileName) const;
        bool isEmpty() const;

        virtual ~FileStatuses();
    protected:
    private:
        map<string, const GitFileStatus*> m_fileStatuses;
        map<string, const GitFileStatus*> m_folderStatuses;

        bool isInUntrackedFolder(const string& fileName) const;
        void deleteMapValues(map<string, const GitFileStatus*> m);
        const GitFileStatus* getFileStatus(const string& fileName) const;
};

#endif // FILESTATUSES_H
