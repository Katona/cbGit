#ifndef REVERTFILEACTIONHANDLER_H
#define REVERTFILEACTIONHANDLER_H

#include "FileActionHandler.h"

class GitModel;

class RevertFileActionHandler : public FileActionHandler
{
    public:
        RevertFileActionHandler();
        void handleAction(cbGitFile& file, GitModel& gitModel);
        virtual ~RevertFileActionHandler();
    protected:
    private:
};

#endif // REVERTFILEACTIONHANDLER_H
