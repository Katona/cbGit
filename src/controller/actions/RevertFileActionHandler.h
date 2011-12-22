#ifndef REVERTFILEACTIONHANDLER_H
#define REVERTFILEACTIONHANDLER_H

#include "MenuActionHandler.h"


class RevertFileActionHandler : public MenuActionHandler
{
    public:
        RevertFileActionHandler();
        void onActionFired(wxCommandEvent& event);
        virtual ~RevertFileActionHandler();
    protected:
    private:
};

#endif // REVERTFILEACTIONHANDLER_H
