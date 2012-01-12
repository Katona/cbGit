#ifndef PROJECTOPENEDHANDLER_H
#define PROJECTOPENEDHANDLER_H

#include <vector>

#include "ProjectEventHandler.h"



class ProjectOpenedHandler : public ProjectEventHandler
{
    public:
        ProjectOpenedHandler();
        void handleEvent(cbGitProject& project, GitModel& model);
        virtual ~ProjectOpenedHandler();
    protected:
    private:

};

#endif // PROJECTOPENEDHANDLER_H
