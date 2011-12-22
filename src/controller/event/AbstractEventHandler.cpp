#include <manager.h>
#include <sdk.h>
#include <cbfunctor.h>
#include <iostream>

#include "AbstractEventHandler.h"

using namespace std;

AbstractEventHandler::AbstractEventHandler(wxEventType eventType) :
    m_eventType(eventType)
{
    //ctor
}

void AbstractEventHandler::registerHandler(Manager& manager) {
    cout << "HAndler ergistered" << endl;
    cbEventFunctor<AbstractEventHandler, CodeBlocksEvent>* evFunctor =
        new cbEventFunctor<AbstractEventHandler, CodeBlocksEvent>(
            this, &AbstractEventHandler::handleEvent);
    manager.RegisterEventSink(m_eventType, evFunctor);
}

void AbstractEventHandler::unregisterHandler(Manager& manager) {
}

AbstractEventHandler::~AbstractEventHandler()
{
    //dtor
}
