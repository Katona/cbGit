#ifndef CBGITPROJECT_H
#define CBGITPROJECT_H

#include <vector>
#include <cbproject.h>

using namespace std;

class cbGitFile;

class cbGitProject
{
    public:
        cbGitProject(cbProject& cbProject);
        const string& getTopLevelPath() const;
        cbGitFile* getFile(const string& relativeFileName);
        vector<cbGitFile*> getFiles() const;
        const string& getRelativeFileName() const;
        virtual ~cbGitProject();
    protected:
    private:
        cbProject& m_cbProject;
        string m_topLevelPath;
        string m_relativeProjectFileName;
        map<string, cbGitFile*> m_files;
        void addGitFile(const string& relativeFileName);
        void addAllGitFiles();
};

#endif // CBGITPROJECT_H
