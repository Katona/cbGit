#ifndef ADDACTIONHANDLER_H
#define ADDACTIONHANDLER_H

#include "../event/FileEventHandler.h"

class AddFileActionHandler : public FileEventHandler
{
    public:
        static AddFileActionHandler INSTANCE;

        AddFileActionHandler();
        virtual ~AddFileActionHandler();
    protected:
        virtual void handleEvent(cbGitFile& file, GitModel& model);
    private:


};

#endif // ADDACTIONHANDLER_H
