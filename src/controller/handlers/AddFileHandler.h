#ifndef ADDACTIONHANDLER_H
#define ADDACTIONHANDLER_H

#include "FileEventHandler.h"

class AddFileHandler : public FileEventHandler
{
    public:
        static AddFileHandler INSTANCE;

        AddFileHandler();
        virtual ~AddFileHandler();
    protected:
        virtual void handleEvent(cbGitFile& file, GitModel& model);
    private:


};

#endif // ADDACTIONHANDLER_H
