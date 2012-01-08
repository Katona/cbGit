#ifndef MENUACTIONFACTORY_H
#define MENUACTIONFACTORY_H

#include <memory>
#include <vector>

using namespace std;

class MenuAction;
class FileAction;
class ProjectAction;
class MenuActionSet;
class cbGitFile;
class cbGitProject;

class MenuActionFactory
{
    public:
        static MenuActionFactory& getInstance();
        auto_ptr<MenuActionSet> getActions(cbGitProject& project);
        auto_ptr<MenuActionSet> getActions(cbGitFile& file);
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
