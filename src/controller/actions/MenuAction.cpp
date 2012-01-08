#include "MenuAction.h"
#include "AddFileActionHandler.h"
#include "../../model/GitFileStatus.h"
#include "CommitFileActionHandler.h"

MenuAction::MenuAction(const string& actionText, MenuActionHandler* handler) :
        m_actionText(actionText), m_handler(handler), m_wxEventID(wxNewId()) {

}

MenuActionHandler& MenuAction::getHandler() const {
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
