// CStatusDlgThread.cpp : 実装ファイル
//

#include "pch.h"
#include "FactorioFactoryCalculator.h"
#include "CStatusDlg.h"
#include "CStatusDlgThread.h"


// CStatusDlgThread

IMPLEMENT_DYNCREATE(CStatusDlgThread, CWinThread)

CStatusDlgThread::CStatusDlgThread() : m_Valid(true)
{
	m_bAutoDelete = false;
}

BOOL CStatusDlgThread::InitInstance()
{
	m_pMainWnd = &m_Dlg;
	m_Dlg.DoModal();
	m_Valid = false;
	return TRUE;
}

void CStatusDlgThread::UpdateStatus(CString status)
{
	m_Dlg.m_Status = status;
	if (m_Dlg.m_hWnd) {
		m_Dlg.PostMessage(WM_COMMAND, ID_UPDATE_STATUS);
	}
}

BEGIN_MESSAGE_MAP(CStatusDlgThread, CWinThread)
END_MESSAGE_MAP()
