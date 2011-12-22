#ifndef COMMITPROJECTACTIONHANDLER_H
#define COMMITPROJECTACTIONHANDLER_H

#include <string>
#include "MenuActionHandler.h"

using namespace std;


class CommitProjectActionHandler : public MenuActionHandler
{
    public:
        CommitProjectActionHandler();
        virtual void onActionFired(wxCommandEvent& event);
        virtual ~CommitProjectActionHandler();
    protected:
    private:
        void stageNecessaryFiles(const string& workDir);
};

#endif // COMMITPROJECTACTIONHANDLER_H
