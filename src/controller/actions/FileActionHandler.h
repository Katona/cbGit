#ifndef FILEACTIONHANDLER_H
#define FILEACTIONHANDLER_H

#include "MenuActionHandler.h"

class cbGitFile;
class GitModel;

class FileActionHandler : public MenuActionHandler
{
    public:
        FileActionHandler();
        void onActionFired(wxCommandEvent& event);
        virtual void handleAction(cbGitFile& file, GitModel& gitModel) = 0;
        virtual ~FileActionHandler();
    protected:
        void updateStatus(cbGitFile& file);
    private:
};

#endif // FILEACTIONHANDLER_H
