#ifndef CONTEXTMENUCONTRIBUTION_H
#define CONTEXTMENUCONTRIBUTION_H

#include <vector>
#include <cbeditor.h>
#include <cbproject.h>

using namespace std;

class MenuAction;
class MenuActionSet;

class ContextMenuContribution
{
    public:
        ContextMenuContribution();
        void expandMenu(const ModuleType type, wxMenu* menu,
                        const FileTreeData* data);
        virtual ~ContextMenuContribution();
    protected:
    private:
        void expandProjectManagerMenu(const ModuleType type, wxMenu* menu,
                                      const FileTreeData* data);
        void addActionsToMenu(wxMenu* menu,
                       const MenuActionSet& actions);
};

#endif // CONTEXTMENUCONTRIBUTION_H
