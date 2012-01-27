#include "CommitProjectDlg.h"

//(*InternalHeaders(CommitProjectDlg)
#include <wx/string.h>
#include <wx/intl.h>
//*)

#include <iostream>

#include "../model/FileStatuses.h"
#include "../model/GitFileStatus.h"
#include "../utils/cbGitProject.h"
#include "../utils/cbGitFile.h"
#include "../utils/Utils.h"

//(*IdInit(CommitProjectDlg)
const long CommitProjectDlg::ID_TXT_COMMIT_MESSAGE = wxNewId();
const long CommitProjectDlg::ID_LIST_FILES_TO_COMMIT = wxNewId();
const long CommitProjectDlg::ID_BTN_SELECT_ALL = wxNewId();
const long CommitProjectDlg::ID_BTN_DESELECT_ALL = wxNewId();
const long CommitProjectDlg::ID_BTN_COMMIT = wxNewId();
const long CommitProjectDlg::ID_BTN_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommitProjectDlg,wxDialog)
	//(*EventTable(CommitProjectDlg)
	//*)
END_EVENT_TABLE()

CommitProjectDlg::CommitProjectDlg(cbGitProject& project, FileStatuses& statuses,
                                   wxWindow* parent,wxWindowID id)
{
	//(*Initialize(CommitProjectDlg)
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	m_txtCommitMessage = new wxTextCtrl(this, ID_TXT_COMMIT_MESSAGE, _("Commit message"), wxDefaultPosition, wxSize(400,100), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TXT_COMMIT_MESSAGE"));
	BoxSizer1->Add(m_txtCommitMessage, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Files to commit"));
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	m_listFilesToCommit = new wxCheckListBox(this, ID_LIST_FILES_TO_COMMIT, wxDefaultPosition, wxSize(400,-1), 0, 0, 0, wxDefaultValidator, _T("ID_LIST_FILES_TO_COMMIT"));
	BoxSizer3->Add(m_listFilesToCommit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxVERTICAL);
	m_btnSelectAll = new wxButton(this, ID_BTN_SELECT_ALL, _("Select All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_SELECT_ALL"));
	BoxSizer4->Add(m_btnSelectAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_btnDeselectAll = new wxButton(this, ID_BTN_DESELECT_ALL, _("Deselect All"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_DESELECT_ALL"));
	BoxSizer4->Add(m_btnDeselectAll, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(StaticBoxSizer1, 2, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	m_btnCommit = new wxButton(this, ID_BTN_COMMIT, _("Commit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_COMMIT"));
	BoxSizer2->Add(m_btnCommit, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	m_btnCancel = new wxButton(this, ID_BTN_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_CANCEL"));
	BoxSizer2->Add(m_btnCancel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_LIST_FILES_TO_COMMIT,wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,(wxObjectEventFunction)&CommitProjectDlg::onListElementChecked);
	Connect(ID_BTN_COMMIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitProjectDlg::onCommitClicked);
	Connect(ID_BTN_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitProjectDlg::onCancelClicked);
	Connect(ID_BTN_SELECT_ALL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitProjectDlg::onSelectAllClicked);
	Connect(ID_BTN_DESELECT_ALL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitProjectDlg::onDeselectAllClicked);

	fillCheckListBox(project, statuses);
	//*)
}

CommitProjectDlg::~CommitProjectDlg()
{
	//(*Destroy(CommitProjectDlg)
	//*)
}

void CommitProjectDlg::fillCheckListBox(cbGitProject& project, FileStatuses& statuses) {

    vector<cbGitFile*> files = project.getFiles();
    cout << "Project filename: " << project.getRelativeFileName() << endl;
    addFile(project.getRelativeFileName(), project, statuses);
    for (int i = 0; i < files.size(); i++) {
        addFile(files[i]->getRelativeFileName(), project, statuses);
    }

}

void CommitProjectDlg::addFile(const string& fileName,
                               const cbGitProject& project,
                               const FileStatuses& statuses) {

    const GitFileStatus& status = statuses.getStatus(fileName);
    if (status.getStatus() == GitFileStatus::none)
    {
        return;
    }
    m_listFilesToCommit->Append(toWxStr(fileName),
                                const_cast<GitFileStatus*> (&status));
    m_listFilesToCommit->Check(m_listFilesToCommit->GetCount() - 1);

}

void CommitProjectDlg::onListElementChecked(wxCommandEvent& event)
{
}

void CommitProjectDlg::onCommitClicked(wxCommandEvent& event)
{
    EndModal(wxID_OK);
    Close();
}

string CommitProjectDlg::getCommitMessage() const {
    return toString(m_txtCommitMessage->GetValue());
}

void CommitProjectDlg::getSelectedFiles(vector<GitFileStatus*>& files) const {
    for (int i = 0; i < m_listFilesToCommit->GetCount(); i++) {
        if (m_listFilesToCommit->IsChecked(i)) {
            files.push_back(static_cast<GitFileStatus*>
                        (m_listFilesToCommit->GetClientData(i)));
        }
        m_listFilesToCommit->Check(i, true);
    }
}

void CommitProjectDlg::onSelectAllClicked(wxCommandEvent& event) {
    for (int i = 0; i < m_listFilesToCommit->GetCount(); i++) {
        m_listFilesToCommit->Check(i, true);
    }
}

void CommitProjectDlg::onDeselectAllClicked(wxCommandEvent& event) {
    for (int i = 0; i < m_listFilesToCommit->GetCount(); i++) {
        m_listFilesToCommit->Check(i, false);
    }
}


void CommitProjectDlg::onCancelClicked(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
    Close();
}
