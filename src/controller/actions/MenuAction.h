#ifndef GITACTION_H
#define GITACTION_H

#include <string>
#include <vector>
#include <cbproject.h>

#include "MenuActionHandler.h"


using namespace std;

class MenuActionHandler;
class GitFileStatus;

class MenuAction
{
    public:
        MenuAction(const string& actionText, MenuActionHandler* handler);
        MenuActionHandler& getHandler() const;
        int getWxEventID() const;
        const string& getText() const;
        virtual bool isEnabled() const;
        virtual ~MenuAction();
    protected:
    private:

        const string m_actionText;
        MenuActionHandler* m_handler;
        const int m_wxEventID;
};

#endif // GITACTION_H
