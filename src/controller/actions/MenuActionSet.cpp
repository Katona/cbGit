#include "MenuActionSet.h"
#include "MenuAction.h"

MenuActionSet::MenuActionSet()
{
    //ctor
}

void MenuActionSet::addAction(MenuAction* action) {
    m_actions.push_back(action);
}

const MenuAction& MenuActionSet::operator[](int index) const {
    return (*m_actions[index]);
}

int MenuActionSet::size() const {
    return m_actions.size();
}

MenuActionSet::~MenuActionSet()
{
    for (vector<MenuAction*>::size_type i = 0; i < m_actions.size(); i++) {
        delete m_actions[i];
    }
}
