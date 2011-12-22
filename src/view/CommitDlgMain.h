/***************************************************************
 * Name:      CommitDlgMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2011-12-05
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef COMMITDLGMAIN_H
#define COMMITDLGMAIN_H

//(*Headers(CommitDlgDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
//*)

class CommitDlgDialog: public wxDialog
{
    enum DialogAction { cancel, commit } ;
    public:

        CommitDlgDialog(wxWindow* parent,wxWindowID id = -1);
        wxString getCommitMessage() const;
        DialogAction getUserAction() const;

        virtual ~CommitDlgDialog();

    private:

        //(*Handlers(CommitDlgDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnCommit(wxCommandEvent& event);
        void OnCancel(wxCommandEvent& event);
        //*)

        //(*Identifiers(CommitDlgDialog)
        static const long ID_TXT_COMMIT_MSG;
        static const long ID_BTN_COMMIT;
        static const long ID_BTN_CANCEL;
        //*)

        //(*Declarations(CommitDlgDialog)
        wxButton* m_btnCommit;
        wxTextCtrl* m_txtCommit;
        wxButton* m_btnCancel;
        //*)
        DialogAction m_userAction;

        DECLARE_EVENT_TABLE()
};

#endif // COMMITDLGMAIN_H
