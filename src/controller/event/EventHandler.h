#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <wx/wx.h>

class wxCommandEvent;
class CodeBlocksEvent;

class EventHandler : public wxEvtHandler
{
    public:
        EventHandler();
        virtual void handleEvent(wxCommandEvent& wxEvent) = 0;
        virtual void handleEvent(CodeBlocksEvent& codeBlocksEvent) = 0;
        virtual ~EventHandler();
    protected:
    private:
};

#endif // EVENTHANDLER_H
