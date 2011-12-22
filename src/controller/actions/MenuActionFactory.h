#ifndef MENUACTIONFACTORY_H
#define MENUACTIONFACTORY_H

#include <memory>
#include <vector>
#include <cbproject.h>

using namespace std;

class MenuAction;
class FileAction;
class ProjectAction;
class MenuActionSet;

class MenuActionFactory
{
    public:
        static MenuActionFactory& getInstance();
        auto_ptr<MenuActionSet> getActions(cbProject& project);
        auto_ptr<MenuActionSet> getActions(ProjectFile& file);
        virtual ~MenuActionFactory();
    protected:
    private:
        static MenuActionFactory INSTANCE;

        vector<FileAction*> m_fileActions;
        vector<ProjectAction*> m_projectActions;
        vector<MenuAction*> m_folderActions;


        MenuActionFactory();
        MenuActionFactory(MenuActionFactory const&);
        void operator=(MenuActionFactory const&);
};

#endif // MENUACTIONFACTORY_H
