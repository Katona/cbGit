#ifndef COMMITPROJECTDLG_H
#define COMMITPROJECTDLG_H

//(*Headers(CommitProjectDlg)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/checklst.h>
//*)
#include <string>
#include <vector>

using namespace std;

class cbGitProject;
class FileStatuses;
class GitFileStatus;

class CommitProjectDlg: public wxDialog
{
	public:

		CommitProjectDlg(cbGitProject& project, FileStatuses& statuses,
                   wxWindow* parent = 0,wxWindowID id=wxID_ANY);
        string getCommitMessage() const;
        void getSelectedFiles(vector<GitFileStatus*>& files) const;
		virtual ~CommitProjectDlg();

		//(*Declarations(CommitProjectDlg)
		wxButton* m_btnCommit;
		wxTextCtrl* m_txtCommitMessage;
		wxButton* m_btnDeselectAll;
		wxButton* m_btnSelectAll;
		wxCheckListBox* m_listFilesToCommit;
		wxButton* m_btnCancel;
		//*)

	protected:

		//(*Identifiers(CommitProjectDlg)
		static const long ID_TXT_COMMIT_MESSAGE;
		static const long ID_LIST_FILES_TO_COMMIT;
		static const long ID_BTN_SELECT_ALL;
		static const long ID_BTN_DESELECT_ALL;
		static const long ID_BTN_COMMIT;
		static const long ID_BTN_CANCEL;
		//*)

	private:

        void fillCheckListBox(cbGitProject& project, FileStatuses& statuses);
		//(*Handlers(CommitProjectDlg)
		void onListElementChecked(wxCommandEvent& event);
		void onCommitClicked(wxCommandEvent& event);
		void onCancelClicked(wxCommandEvent& event);
		void onSelectAllClicked(wxCommandEvent& event);
		void onDeselectAllClicked(wxCommandEvent& event);
		//*)

        void addFile(const string& fileName, const cbGitProject& project,
                     const FileStatuses& statuses);
		DECLARE_EVENT_TABLE()
};

#endif
