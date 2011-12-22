#ifndef FILESAVEDHANDLER_H
#define FILESAVEDHANDLER_H

#include "AbstractEventHandler.h"


class FileSavedHandler : public AbstractEventHandler
{
    public:
        FileSavedHandler();
        void handleEvent(CodeBlocksEvent& event);
        virtual ~FileSavedHandler();
    protected:
    private:
};

#endif // FILESAVEDHANDLER_H
