// CStatusDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "FactorioFactoryCalculator.h"
#include "CStatusDlg.h"
#include "afxdialogex.h"


// CStatusDlg ダイアログ

IMPLEMENT_DYNAMIC(CStatusDlg, CDialogEx)

CStatusDlg::CStatusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STATUS, pParent)
{
}

CStatusDlg::~CStatusDlg()
{
}

void CStatusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_STATUS, m_CtrlEditStatus);
}

BEGIN_MESSAGE_MAP(CStatusDlg, CDialogEx)
	ON_COMMAND(ID_UPDATE_STATUS, UpdateStatus)
END_MESSAGE_MAP()


void CStatusDlg::UpdateStatus()
{
	m_CtrlEditStatus.SetWindowText(m_Status);
}
