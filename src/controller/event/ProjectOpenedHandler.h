#ifndef PROJECTOPENEDHANDLER_H
#define PROJECTOPENEDHANDLER_H

#include <vector>
#include <sdk.h>

#include "AbstractEventHandler.h"



class ProjectOpenedHandler : public AbstractEventHandler
{
    public:
        ProjectOpenedHandler();
        virtual void handleEvent(CodeBlocksEvent& event);
        virtual ~ProjectOpenedHandler();
    protected:
    private:

};

#endif // PROJECTOPENEDHANDLER_H
