#include "MenuAction.h"
#include "../handlers/AddFileHandler.h"
#include "../../model/GitFileStatus.h"
#include "../handlers/CommitFileHandler.h"

MenuAction::MenuAction(const string& actionText, EventHandler* handler) :
        m_actionText(actionText), m_handler(handler), m_wxEventID(wxNewId()) {

}

EventHandler& MenuAction::getHandler() const {
    return (*m_handler);
}

int MenuAction::getWxEventID() const {
    return m_wxEventID;
}

const string& MenuAction::getText() const {
    return m_actionText;
}

MenuAction::~MenuAction() {
//    if (m_handler != 0) {
//        delete m_handler;
//    }
}
