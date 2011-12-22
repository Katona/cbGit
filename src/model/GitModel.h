#ifndef GITMODEL_H
#define GITMODEL_H

#include <vector>
#include <string>

using namespace std;

class GitFileStatus;

class GitModel
{
    public:
        GitModel(const string& workDir);
        void getStatus(vector<GitFileStatus>& result,
                       const string& fileName = "");
        void add(const vector<string>& filesToAdd);
        void commitAll(const string& message);
        void checkoutFile(const string& fileName);
        void resetFile(const string& fileName);
        virtual ~GitModel();
    protected:
    private:
        string m_workDir;
};

#endif // GITMODEL_H
