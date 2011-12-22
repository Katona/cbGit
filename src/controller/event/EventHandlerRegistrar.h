#ifndef EVENTHANDLERREGISTRAR_H
#define EVENTHANDLERREGISTRAR_H

#include <vector>

#include "AbstractEventHandler.h"

using namespace std;

class Manager;

class EventHandlerRegistrar
{
    public:
        EventHandlerRegistrar();
        void registerHandlers(Manager& manager);
        void unregisterHandlers(Manager& manager);
        virtual ~EventHandlerRegistrar();
    protected:
    private:
        vector<AbstractEventHandler*> m_handlers;
};

#endif // EVENTHANDLERREGISTRAR_H
