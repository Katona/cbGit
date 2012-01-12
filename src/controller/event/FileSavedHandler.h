#ifndef FILESAVEDHANDLER_H
#define FILESAVEDHANDLER_H

#include "FileEventHandler.h"


class FileSavedHandler : public FileEventHandler
{
    public:
        FileSavedHandler();
        void handleEvent(cbGitFile& file, GitModel& gitModel);
        virtual ~FileSavedHandler();
    protected:
    private:
};

#endif // FILESAVEDHANDLER_H
