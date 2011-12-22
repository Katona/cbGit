#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <string>
#include <sdk.h>
#include <wx/wx.h>
#include <cbproject.h>

using namespace std;

string toString(const wxString& wxStr);
wxString toWxStr(const string& stdStr);
ProjectFile* getSelectedProjectFile(const FileTreeData* fileTreeData = 0);
cbProject* getSelectedProject(const FileTreeData* fileTreeData = 0);

#endif // UTILS_H_INCLUDED
