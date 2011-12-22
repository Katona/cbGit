#ifndef ABSTRACTEVENTHANDLER_H
#define ABSTRACTEVENTHANDLER_H

#include <sdk.h>
#include <manager.h>

class AbstractEventHandler
{
    public:
        AbstractEventHandler(wxEventType eventType);
        void registerHandler(Manager& manager);
        void unregisterHandler(Manager& manager);
        virtual void handleEvent(CodeBlocksEvent& event) = 0;
        virtual ~AbstractEventHandler();
    protected:
    private:
        wxEventType m_eventType;
};

#endif // ABSTRACTEVENTHANDLER_H
