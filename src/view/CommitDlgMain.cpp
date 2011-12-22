/***************************************************************
 * Name:      CommitDlgMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2011-12-05
 * Copyright:  ()
 * License:
 **************************************************************/

#include "CommitDlgMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(CommitDlgDialog)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(CommitDlgDialog)
const long CommitDlgDialog::ID_TXT_COMMIT_MSG = wxNewId();
const long CommitDlgDialog::ID_BTN_COMMIT = wxNewId();
const long CommitDlgDialog::ID_BTN_CANCEL = wxNewId();
//*)

BEGIN_EVENT_TABLE(CommitDlgDialog,wxDialog)
    //(*EventTable(CommitDlgDialog)
    //*)
END_EVENT_TABLE()

CommitDlgDialog::CommitDlgDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(CommitDlgDialog)
    wxBoxSizer* btnSizer;
    wxBoxSizer* dialogSizer;

    Create(parent, id, _("Commit"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("id"));
    dialogSizer = new wxBoxSizer(wxVERTICAL);
    m_txtCommit = new wxTextCtrl(this, ID_TXT_COMMIT_MSG, _("Commit message"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TXT_COMMIT_MSG"));
    m_txtCommit->SetMinSize(wxSize(400,100));
    m_txtCommit->SetFocus();
    dialogSizer->Add(m_txtCommit, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSizer = new wxBoxSizer(wxHORIZONTAL);
    m_btnCommit = new wxButton(this, ID_BTN_COMMIT, _("Commit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_COMMIT"));
    btnSizer->Add(m_btnCommit, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_btnCancel = new wxButton(this, ID_BTN_CANCEL, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTN_CANCEL"));
    btnSizer->Add(m_btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    dialogSizer->Add(btnSizer, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(dialogSizer);
    dialogSizer->Fit(this);
    dialogSizer->SetSizeHints(this);
    Center();

    Connect(ID_BTN_COMMIT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitDlgDialog::OnCommit);
    Connect(ID_BTN_CANCEL,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&CommitDlgDialog::OnCancel);
    //*)
}

CommitDlgDialog::~CommitDlgDialog()
{
    //(*Destroy(CommitDlgDialog)
    //*)
}

void CommitDlgDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void CommitDlgDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void CommitDlgDialog::OnCommit(wxCommandEvent& event)
{
    m_userAction = commit;
    EndModal(wxID_OK);
    Close();
}

void CommitDlgDialog::OnCancel(wxCommandEvent& event)
{
    m_userAction = cancel;
    EndModal(wxID_CANCEL);
    Close();
}

wxString CommitDlgDialog::getCommitMessage() const {
    return m_txtCommit->GetValue();
}
