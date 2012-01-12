#ifndef FILEEVENTHANDLER_H
#define FILEEVENTHANDLER_H

#include "EventHandler.h"

class cbGitFile;
class GitModel;
class wxCommandEvent;
class CodeBlocksEvent;
class ProjectFile;

class FileEventHandler : public EventHandler
{
    public:
        FileEventHandler();
        void handleEvent(wxCommandEvent& wxEvent);
        void handleEvent(CodeBlocksEvent& cbEvent);
        virtual ~FileEventHandler();
    protected:
        virtual void handleEvent(cbGitFile& file, GitModel& model) = 0;
        void updateStatus(cbGitFile& file);
    private:
        void doHandle(ProjectFile* cbFile);
};

#endif // FILEEVENTHANDLER_H
