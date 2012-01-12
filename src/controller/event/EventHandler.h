#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

class wxCommandEvent;
class CodeBlocksEvent;

class EventHandler
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
