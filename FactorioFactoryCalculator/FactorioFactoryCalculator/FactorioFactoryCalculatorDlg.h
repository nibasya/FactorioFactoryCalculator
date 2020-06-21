
// FactorioFactoryCalculatorDlg.h : ヘッダー ファイル
//

#pragma once

#include <vector>
#include <map>

class CStatusDlgThread;

struct SItem {
	SItem() :num(0), time(0.0), facSel(0), validSpeed(true), loop(false){};
	CString name;
	double num;
	double time;
	std::vector <CString> facName;
	int facSel;
	std::vector <CString> matName;
	std::vector <int> matNum;
	double reqItemPerSec;
	double reqNumPerTarget;
	double reqFacNum;
	bool validSpeed;
	bool loop;
};

struct SFactory {
	SFactory() :gain(0.0), validGain(true) {};
	CString name;
	double gain;
	bool validGain;
};

// CFactorioFactoryCalculatorDlg ダイアログ
class CFactorioFactoryCalculatorDlg : public CDialogEx
{
// コンストラクション
public:
	CFactorioFactoryCalculatorDlg(CWnd* pParent = nullptr);	// 標準コンストラクター

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FACTORIOFACTORYCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート


// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonFolder();
	CEdit m_CtrlEditFolder;
	CEdit m_CtrlEditTargetSpeed;
	CEdit m_CtrlEditItemName;
	CEdit m_CtrlEditItemTime;
	CEdit m_CtrlEditItemNum;
	CEdit m_CtrlEditReqItemNum;
	CEdit m_CtrlEditItemPerSec;
	CEdit m_CtrlEditFacGain;
	CEdit m_CtrlEditFacReqNum;
	CComboBox m_CtrlComboTargetItem;
	CComboBox m_CtrlComboFactory;
	CTreeCtrl m_CtrlTree;
	afx_msg void OnBnClickedButtonLoad();
	void ClearData();
	void ClearTree();
	void ClearTreeSub(HTREEITEM hCurrent);
	bool LoadItemData(CString file);
	bool LoadFactoryData(CString file);
	void ShowReadError(CString txt, CString file, int lineNum, CString line);
	void UpdateTargetCombo();
	static UINT AddNodeThread(LPVOID pData);
	UINT AddNodeThreadMain();
	void AddNode(SItem* pItem, HTREEITEM parent, CStatusDlgThread* pStatus);
	bool CheckLoop(HTREEITEM hTree, CString name);
	std::map < CString, SItem > m_Item;
	std::map < CString, SFactory > m_Factory;
	afx_msg void OnCbnSelchangeComboTarget();
	afx_msg void OnDestroy();
	afx_msg void OnTvnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	double m_TargetSpeed;
	afx_msg void OnBnClickedButtonSet();
	void UpdateValues();
	void UpdateValuesSub(HTREEITEM hCurrent, double reqNum, bool validSpeed);
	afx_msg void OnCbnSelchangeComboFactory();
	CRect m_DefParentRect;
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	CEdit m_CtrlEditTargetTime;
	afx_msg void OnBnClickedButtonTime();
	afx_msg void OnBnClickedButtonJump();
	virtual void OnOK();
};
