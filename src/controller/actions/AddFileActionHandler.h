#ifndef ADDACTIONHANDLER_H
#define ADDACTIONHANDLER_H

#include "MenuActionHandler.h"

class wxCommandEvent;

class AddFileActionHandler : public MenuActionHandler
{
    public:
        static AddFileActionHandler INSTANCE;

        AddFileActionHandler();
        virtual void onActionFired(wxCommandEvent& event);
        virtual ~AddFileActionHandler();
    protected:
    private:


};

#endif // ADDACTIONHANDLER_H
