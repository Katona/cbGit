#ifndef GITCHECKOUTCOMMAND_H
#define GITCHECKOUTCOMMAND_H

#include <vector>
#include <string>
#include "GitCommand.h"

using namespace std;

class GitCheckoutCommand : public GitCommand
{
    public:
        GitCheckoutCommand(const string& workDir);
        GitCheckoutCommand& file(const string& fileName);
        GitCheckoutCommand& revertToStagingIndex();
        int execute();
        virtual ~GitCheckoutCommand();
    protected:
    private:
        vector<string> m_fileNames;
        bool m_toStage;
};

#endif // GITCHECKOUTCOMMAND_H
