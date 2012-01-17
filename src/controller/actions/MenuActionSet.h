#ifndef MENUACTIONSET_H
#define MENUACTIONSET_H

#include <vector>

using namespace std;

class MenuAction;

class MenuActionSet
{
    public:
        MenuActionSet();
        void addAction(MenuAction& action);
        const MenuAction& operator[](int index) const;
        int size() const;
        virtual ~MenuActionSet();
    protected:
    private:
        vector<MenuAction*> m_actions;
};

#endif // MENUACTIONSET_H
