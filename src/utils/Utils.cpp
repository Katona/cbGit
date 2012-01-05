#include "Utils.h"

#include <projectmanager.h>

const FileTreeData* getSelectedTreeData() {
    ProjectManager* manager = Manager::Get()->GetProjectManager();
    wxTreeCtrl *tree = manager->GetTree();

    if (!tree)
        return NULL;

    wxTreeItemId treeItem =  manager->GetTreeSelection();

    if (!treeItem.IsOk())
        return NULL;

    const FileTreeData *data = static_cast<FileTreeData*>(tree->GetItemData( treeItem ));
    return data;
}

string toString(const wxString& wxStr) {

    return string(wxStr.mb_str());
}

wxString toWxStr(const string& stdStr) {
    return wxString::FromUTF8(stdStr.c_str());
}

ProjectFile* getSelectedProjectFile(const FileTreeData* fileTreeData) {
    const FileTreeData *data = fileTreeData != 0 ? fileTreeData :
        getSelectedTreeData();

    return data == NULL ? NULL : data->GetProjectFile();
}

cbProject* getSelectedProject(const FileTreeData* fileTreeData) {
    const FileTreeData *data = fileTreeData != 0 ? fileTreeData :
        getSelectedTreeData();
    return data == NULL ? NULL : data->GetProject();
}

bool startsWith(const string& comparedString, const string& prefix) {
    return comparedString.compare(0, prefix.size(), prefix) == 0;
}
