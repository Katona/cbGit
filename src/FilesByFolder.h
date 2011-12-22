#ifndef FILESBYFOLDER_H
#define FILESBYFOLDER_H

#include <vector>
#include <map>
#include <cbproject.h>

using namespace std;

class FilesByFolder
{
    public:
        FilesByFolder();
        void addFile(ProjectFile* file);
        const vector<ProjectFile*>& getFilesRecursively(const string& folder);
        virtual ~FilesByFolder();
    protected:
    private:
        const static vector<ProjectFile*> EMPTY_PRFILE_VECTOR;
        map<string, vector<ProjectFile*>* > m_filesByFolder;

        void addFileToFolder(const string& folder, ProjectFile* file);

};

#endif // FILESBYFOLDER_H
