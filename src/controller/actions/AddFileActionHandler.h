#ifndef ADDACTIONHANDLER_H
#define ADDACTIONHANDLER_H

#include "FileActionHandler.h"

class AddFileActionHandler : public FileActionHandler
{
    public:
        static AddFileActionHandler INSTANCE;

        AddFileActionHandler();
        virtual void handleAction(cbGitFile& file, GitModel& gitModel);
        virtual ~AddFileActionHandler();
    protected:
    private:


};

#endif // ADDACTIONHANDLER_H
