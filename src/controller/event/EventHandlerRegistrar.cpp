
#include "EventHandlerRegistrar.h"
#include <iostream>
#include <manager.h>
#include "ProjectOpenedHandler.h"
#include "FileSavedHandler.h"


using namespace std;

EventHandlerRegistrar::EventHandlerRegistrar()
{
    m_handlers.push_back(new ProjectOpenedHandler());
    m_handlers.push_back(new FileSavedHandler());
}

void EventHandlerRegistrar::registerHandlers(Manager& manager) {
    cout << "Registering handlers" << endl;
    for (vector<AbstractEventHandler*>::size_type i = 0; i < m_handlers.size(); i++) {
        m_handlers[i]->registerHandler(manager);
    }
}

void EventHandlerRegistrar::unregisterHandlers(Manager& manager) {
    cout << "Unregistering handlers" << endl;
    for (vector<AbstractEventHandler*>::size_type i = 0; i < m_handlers.size(); i++) {
        manager.RemoveAllEventSinksFor(&m_handlers[i]);
    }
}

EventHandlerRegistrar::~EventHandlerRegistrar()
{
    for (vector<AbstractEventHandler*>::size_type i = 0; i < m_handlers.size(); i++) {
        delete m_handlers[i];
    }

}
