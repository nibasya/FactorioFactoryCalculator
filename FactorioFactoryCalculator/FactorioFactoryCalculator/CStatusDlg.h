#pragma once


// CStatusDlg ダイアログ

const int ID_UPDATE_STATUS = 40000;

class CStatusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStatusDlg)

public:
	CStatusDlg(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CStatusDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STATUS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()

public:
	CString m_Status;
	afx_msg void UpdateStatus();
private:
	CEdit m_CtrlEditStatus;
};
