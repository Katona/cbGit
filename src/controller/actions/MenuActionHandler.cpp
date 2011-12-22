#include "MenuActionHandler.h"
#include <iostream>

using namespace std;

MenuActionHandler::MenuActionHandler()
{
    //ctor
}

void MenuActionHandler:: onMenuClosed(wxMenuEvent& menuEvent) {
    cout << "Menu closed" << endl;
}

MenuActionHandler::~MenuActionHandler()
{
    //dtor
}
