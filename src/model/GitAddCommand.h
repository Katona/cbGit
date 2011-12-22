#ifndef GITADDCOMMAND_H
#define GITADDCOMMAND_H

#include <vector>
#include "GitCommand.h"

using namespace std;

class GitAddCommand : public GitCommand
{
    public:
        GitAddCommand(const string& workDir, const string& fileName);
        GitAddCommand(const string& workDir, const vector<string>& files);
        virtual ~GitAddCommand();
    protected:
    private:
};

#endif // GITADDCOMMAND_H
