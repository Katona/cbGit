#ifndef REVERTFILEACTIONHANDLER_H
#define REVERTFILEACTIONHANDLER_H

#include "../event/FileEventHandler.h"

class GitModel;

class RevertFileActionHandler : public FileEventHandler
{
    public:
        static RevertFileActionHandler INSTANCE;
        RevertFileActionHandler();
        virtual ~RevertFileActionHandler();
    protected:
        void handleEvent(cbGitFile& file, GitModel& gitModel);
    private:
};

#endif // REVERTFILEACTIONHANDLER_H
