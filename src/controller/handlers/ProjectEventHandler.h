#ifndef PROJECTEVENTHANDLER_H
#define PROJECTEVENTHANDLER_H

#include "EventHandler.h"

class wxCommandEvent;
class CodeBlocksEvent;
class cbGitProject;
class cbProject;
class GitModel;

class ProjectEventHandler : public EventHandler
{
    public:
        ProjectEventHandler();
        void handleEvent(wxCommandEvent& wxEvent);
        void handleEvent(CodeBlocksEvent& cbEvent);
        virtual ~ProjectEventHandler();
    protected:
        virtual void handleEvent(cbGitProject& project, GitModel& model) = 0;
        void updateStatus(cbGitProject& project);
    private:
        void doHandle(cbProject* cbProj);
};

#endif // PROJECTEVENTHANDLER_H
