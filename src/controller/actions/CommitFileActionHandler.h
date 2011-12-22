#ifndef COMMITACTIONHANDLER_H
#define COMMITACTIONHANDLER_H

#include "MenuActionHandler.h"

class ProjectFile;
class cbProject;

class CommitFileActionHandler : public MenuActionHandler
{
    public:
        CommitFileActionHandler();
        virtual void onActionFired(wxCommandEvent& event);
        virtual ~CommitFileActionHandler();
    protected:
    private:
        void commitSelectedFile(ProjectFile* projectFile);
        void commitAllFiles(const cbProject* project);
};

#endif // COMMITACTIONHANDLER_H
