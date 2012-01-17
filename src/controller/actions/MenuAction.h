#ifndef GITACTION_H
#define GITACTION_H

#include <string>
#include <vector>
#include <cbproject.h>

#include "../event/EventHandler.h"


using namespace std;

class GitFileStatus;

class MenuAction
{
    public:
        MenuAction(const string& actionText, EventHandler* handler);
        EventHandler& getHandler() const;
        int getWxEventID() const;
        const string& getText() const;
        virtual bool isEnabled() const = 0;
        virtual ~MenuAction();
    protected:
    private:

        const string m_actionText;
        EventHandler* m_handler;
        const int m_wxEventID;
};

#endif // GITACTION_H
