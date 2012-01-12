#include "EventHandlerRegistrar.h"
#include <iostream>
#include <manager.h>
#include <cbfunctor.h>
#include "ProjectOpenedHandler.h"
#include "FileSavedHandler.h"
#include "EventHandler.h"


using namespace std;

EventHandlerRegistrar::EventHandlerRegistrar()
{
}

void EventHandlerRegistrar::registerHandlers(Manager& manager) {
    cout << "Registering handlers" << endl;

    registerHandler(manager, cbEVT_EDITOR_SAVE, new FileSavedHandler());
    registerHandler(manager, cbEVT_PROJECT_OPEN, new ProjectOpenedHandler());
}

void EventHandlerRegistrar::unregisterHandlers(Manager& manager) {
    cout << "Unregistering handlers" << endl;
    for (vector<EventHandler*>::size_type i = 0; i < m_registeredHandlers.size(); i++) {
        manager.RemoveAllEventSinksFor(m_registeredHandlers[i]);
    }
}

void EventHandlerRegistrar::registerHandler(Manager& manager, wxEventType eventType,
                                            EventHandler* handler) {

    cbEventFunctor<EventHandler, CodeBlocksEvent>* evFunctor =
        new cbEventFunctor<EventHandler, CodeBlocksEvent>(
            handler, &EventHandler::handleEvent);
    manager.RegisterEventSink(eventType, evFunctor);
    m_registeredHandlers.push_back(handler);
}

EventHandlerRegistrar::~EventHandlerRegistrar()
{
    for (vector<EventHandler*>::size_type i = 0; i < m_registeredHandlers.size(); i++) {
        delete m_registeredHandlers[i];
    }
}
