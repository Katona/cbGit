#ifndef EVENTHANDLERREGISTRAR_H
#define EVENTHANDLERREGISTRAR_H

#include <vector>
#include <manager.h>

using namespace std;

class Manager;
class EventHandler;

class EventHandlerRegistrar
{
    public:
        EventHandlerRegistrar();
        void registerHandlers(Manager& manager);
        void unregisterHandlers(Manager& manager);
        virtual ~EventHandlerRegistrar();
    protected:
    private:
        vector<EventHandler*> m_registeredHandlers;

        void registerHandler(Manager& manager, wxEventType eventType,
                             EventHandler* handler);
};

#endif // EVENTHANDLERREGISTRAR_H
