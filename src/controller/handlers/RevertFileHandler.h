#ifndef REVERTFILEACTIONHANDLER_H
#define REVERTFILEACTIONHANDLER_H

#include "FileEventHandler.h"

class GitModel;

class RevertFileHandler : public FileEventHandler
{
    public:
        static RevertFileHandler INSTANCE;
        RevertFileHandler();
        virtual ~RevertFileHandler();
    protected:
        void handleEvent(cbGitFile& file, GitModel& gitModel);
    private:
};

#endif // REVERTFILEACTIONHANDLER_H
