
// FactorioFactoryCalculatorDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "framework.h"
#include "FactorioFactoryCalculator.h"
#include "FactorioFactoryCalculatorDlg.h"
#include "afxdialogex.h"
#include "CStatusDlg.h"
#include "CStatusDlgThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFactorioFactoryCalculatorDlg ダイアログ



CFactorioFactoryCalculatorDlg::CFactorioFactoryCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FACTORIOFACTORYCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFactorioFactoryCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_FOLDER, m_CtrlEditFolder);
	DDX_Control(pDX, IDC_EDIT_TARGET_SPEED, m_CtrlEditTargetSpeed);
	DDX_Control(pDX, IDC_EDIT_NAME, m_CtrlEditItemName);
	DDX_Control(pDX, IDC_EDIT_ITEM_TIME, m_CtrlEditItemTime);
	DDX_Control(pDX, IDC_EDIT_ITEM_NUM, m_CtrlEditItemNum);
	DDX_Control(pDX, IDC_EDIT_REQUIRED_ITEM_NUM, m_CtrlEditReqItemNum);
	DDX_Control(pDX, IDC_EDIT_ITEM_PER_SEC, m_CtrlEditItemPerSec);
	DDX_Control(pDX, IDC_EDIT_GAIN, m_CtrlEditFacGain);
	DDX_Control(pDX, IDC_EDIT_REQUIRED_FACTORY_NUM, m_CtrlEditFacReqNum);
	DDX_Control(pDX, IDC_COMBO_TARGET, m_CtrlComboTargetItem);
	DDX_Control(pDX, IDC_COMBO_FACTORY, m_CtrlComboFactory);
	DDX_Control(pDX, IDC_TREE, m_CtrlTree);
	DDX_Control(pDX, IDC_EDIT_TARGET_TIME, m_CtrlEditTargetTime);
}

BEGIN_MESSAGE_MAP(CFactorioFactoryCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_FOLDER, &CFactorioFactoryCalculatorDlg::OnBnClickedButtonFolder)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CFactorioFactoryCalculatorDlg::OnBnClickedButtonLoad)
	ON_CBN_SELCHANGE(IDC_COMBO_TARGET, &CFactorioFactoryCalculatorDlg::OnCbnSelchangeComboTarget)
	ON_WM_DESTROY()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, &CFactorioFactoryCalculatorDlg::OnTvnSelchangedTree)
	ON_BN_CLICKED(IDC_BUTTON_SET, &CFactorioFactoryCalculatorDlg::OnBnClickedButtonSet)
	ON_CBN_SELCHANGE(IDC_COMBO_FACTORY, &CFactorioFactoryCalculatorDlg::OnCbnSelchangeComboFactory)
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDC_BUTTON_TIME, &CFactorioFactoryCalculatorDlg::OnBnClickedButtonTime)
	ON_BN_CLICKED(IDC_BUTTON_JUMP, &CFactorioFactoryCalculatorDlg::OnBnClickedButtonJump)
END_MESSAGE_MAP()


// CFactorioFactoryCalculatorDlg メッセージ ハンドラー

BOOL CFactorioFactoryCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定

	// TODO: 初期化をここに追加します。
	m_CtrlEditTargetSpeed.SetWindowText(_T("1"));
	m_CtrlEditTargetTime.SetWindowText(_T("1"));
	CString buff;
	m_CtrlEditTargetSpeed.GetWindowText(buff);
	m_TargetSpeed = _ttof(buff);

	GetWindowRect(&m_DefParentRect);

	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CFactorioFactoryCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CFactorioFactoryCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CFactorioFactoryCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFactorioFactoryCalculatorDlg::OnBnClickedButtonFolder()
{
	IFileDialog* pDialog = NULL;
	HRESULT hr;
	DWORD options;
	CString path;

// インスタンス生成
hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pDialog));
if (FAILED(hr)) {
	MessageBox(_T("Failed to create dialog"));
	return;
}

// 設定の初期化
pDialog->GetOptions(&options);
pDialog->SetOptions(options | FOS_PICKFOLDERS);
COMDLG_FILTERSPEC rgSpec[] =
{
	// not valid setting
/*		{ _T("Images"), _T("*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ppm;*.tga") },
		{ _T("BMP"), _T("*.bmp") },
		{ _T("GIF"), _T("*.gif") },
		{ _T("JPEG"), _T("*.jpg;*.jpeg") },
		{ _T("PNG"), _T("*.png") },
		{ _T("PPM"), _T("*.ppm") },
		{ _T("TARGA"), _T("*.tga") },
*/
		{ _T("all"), _T("*.*") },
};
pDialog->SetFileTypes(sizeof(rgSpec) / sizeof(COMDLG_FILTERSPEC), rgSpec);

// フォルダ選択ダイアログを表示
hr = pDialog->Show(NULL);

// 結果取得
if (!SUCCEEDED(hr)) {
	pDialog->Release();
	return;
}
IShellItem* pItem = NULL;
PWSTR pPath = NULL;
try {
	hr = pDialog->GetResult(&pItem);
	if (!SUCCEEDED(hr))
		throw hr;
	hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pPath);
	if (!SUCCEEDED(hr))
		throw hr;
	path = pPath;
	CoTaskMemFree(pPath);
	pItem->Release();
}
catch (HRESULT e) {
	if (e == S_OK) {
		OutputDebugString(_T("exception thrown with S_OK\n"));
	}
	if (pItem != NULL)
		pItem->Release();
	pDialog->Release();
	return;
}
pDialog->Release();

m_CtrlEditFolder.SetWindowText(path);
}


void CFactorioFactoryCalculatorDlg::OnBnClickedButtonLoad()
{
	CString folder;
	m_CtrlEditFolder.GetWindowText(folder);
	if (folder.GetLength() < 1) {
		MessageBox(_T("Please set folder name"));
		return;
	}
	if (!PathIsDirectory(folder)) {
		MessageBox(_T("Please set valid folder name"));
		return;
	}

	if (folder.Right(1) == _T("\\")) {
		folder = folder.Left(folder.GetLength() - 1);
	}
	CString itemFile = folder + _T("\\item.csv");
	CString facFile = folder + _T("\\factory.csv");

	ClearData();

	if (!LoadItemData(itemFile))
		return;
	if (!LoadFactoryData(facFile))
		return;
	UpdateTargetCombo();
}

void CFactorioFactoryCalculatorDlg::ClearData()
{
	m_Item.clear();
	m_Factory.clear();
	ClearTree();
	m_CtrlComboTargetItem.ResetContent();
	m_CtrlComboFactory.ResetContent();
}

void CFactorioFactoryCalculatorDlg::ClearTree()
{
	HTREEITEM root = m_CtrlTree.GetRootItem();
	if (root == NULL) {
		return;
	}
	
	ClearTreeSub(root);
	m_CtrlTree.DeleteAllItems();
}

void CFactorioFactoryCalculatorDlg::ClearTreeSub(HTREEITEM hCurrent)
{
	HTREEITEM child = m_CtrlTree.GetChildItem(hCurrent);
	while (child != NULL) {
		ClearTreeSub(child);
		child = m_CtrlTree.GetNextSiblingItem(child);
	}
	delete reinterpret_cast<SItem*>(m_CtrlTree.GetItemData(hCurrent));
}

bool CFactorioFactoryCalculatorDlg::LoadItemData(CString file)
{
	CStdioFile f;
	if (f.Open(file, CFile::modeRead | CFile::typeUnicode) == FALSE) {
		MessageBox(_T("Failed to open item\nfile: ") + file);
		return false;
	}
	CString line;
	int lineNum = 0;
	CString buff;
	int facNum;


	f.ReadString(line);	//	Skip first line which might contain BOM
	lineNum++;

	while (f.ReadString(line) != NULL) {
		lineNum++;
		SItem item;
		// Item name, Generated num, Time, Fac. num, Fac1, Fac2, ..., Facnum, Material 1 name, Material 1 num, Material 2 name, ...
		if (line.GetLength() < 2) {
			if ((line.GetLength() == 0) || (line[0] ==_T('\r'))) {
				// empty line
				continue;
			}
			ShowReadError(_T("Invalid line."), file, lineNum, line);
			return false;
		}
		if (line.Trim().Left(2)==_T("//")) {
			// this is a comment
			continue;
		}
		int tokCount = 0;
		CString tok;
		// name
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() == 0) {
			ShowReadError(_T("Item name not set."), file, lineNum, line);
			return false;
		}
		if (m_Item.find(tok) != m_Item.end()) {
			ShowReadError(_T("Item already registered."), file, lineNum, line);
			return false;
		}
		item.name = tok;
		// num
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() == 0) {
			ShowReadError(_T("Item number not set."), file, lineNum, line);
			return false;
		}
		if (_ttof(tok) == 0) {
			ShowReadError(_T("Item number was not a number or was 0."), file, lineNum, line);
			return false;
		}
		item.num = _ttof(tok);
		// time
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() == 0) {
			ShowReadError(_T("Time not set."), file, lineNum, line);
			return false;
		}
		if (_ttof(tok) == 0.0) {
			ShowReadError(_T("Time was not a number or was 0."), file, lineNum, line);
			return false;
		}
		item.time = _ttof(tok);
		// number of factories
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() == 0) {
			ShowReadError(_T("Number of factories is not set."), file, lineNum, line);
			return false;
		}
		if (_ttoi(tok) == 0) {
			ShowReadError(_T("Number of factories was not a number or was 0."), file, lineNum, line);
			return false;
		}
		facNum = _ttoi(tok);
		// Factory name
		for (int i = 0; i < facNum; i++) {
			tok = line.Tokenize(_T(","), tokCount).Trim();
			if (tok.GetLength() == 0) {
				ShowReadError(_T("Factory name not set."), file, lineNum, line);
				return false;
			}
			item.facName.push_back(tok);
		}
		// materials
		while(1){
			// name
			tok = line.Tokenize(_T(","), tokCount).Trim();
			if (tok.GetLength() == 0) {
				// no materials
				break;
			}
			item.matName.push_back(tok);
			// num
			tok = line.Tokenize(_T(","), tokCount).Trim();
			if (tok.GetLength() == 0) {
				ShowReadError(_T("Material number not set."), file, lineNum, line);
				return false;
			}
			if (_ttoi(tok) == 0) {
				ShowReadError(_T("Material number was not a number or was 0."), file, lineNum, line);
				return false;
			}
			item.matNum.push_back(_ttoi(tok));
		}
		m_Item[item.name] = item;
	}
	return true;
}

bool CFactorioFactoryCalculatorDlg::LoadFactoryData(CString file)
{
	CStdioFile f;
	if (f.Open(file, CFile::modeRead | CFile::typeUnicode) == FALSE) {
		MessageBox(_T("Failed to open factory.\nFile: ") + file);
		return false;
	}
	CString line;
	int lineNum = 0;
	CString buff;

	f.ReadString(line);	//	Skip first line which might contain BOM
	lineNum++;

	while (f.ReadString(line) != NULL) {
		lineNum++;
		SFactory factory;
		// Factory name, Speed gain
		if (line.GetLength() < 2) {
			if ((line.GetLength() == 0) || (line[0] == _T('\r'))) {
				// empty line
				continue;
			}
			ShowReadError(_T("Invalid line."), file, lineNum, line);
			return false;
		}
		if ((line[0] == _T('/')) && (line[1] == _T('/'))) {
			// this is a comment
			continue;
		}
		int tokCount = 0;
		CString tok;
		// name
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() == 0) {
			ShowReadError(_T("Factory name not set."), file, lineNum, line);
			return false;
		}
		if (m_Factory.find(tok) != m_Factory.end()) {
			(_T("Factory name already registered."), file, lineNum, line);
			return false;
		}
		factory.name = tok;
		// num
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() == 0) {
			ShowReadError(_T("Speed gain is not set."), file, lineNum, line);
			return false;
		}
		if (_ttof(tok) == 0.0) {
			ShowReadError(_T("Speed gain was not a number or was 0."), file, lineNum, line);
			return false;
		}
		factory.gain = _ttof(tok);
		// Check abnormal data
		tok = line.Tokenize(_T(","), tokCount).Trim();
		if (tok.GetLength() != 0) {
			ShowReadError(_T("Unknown data is set at tail of the line."), file, lineNum, line);
			return false;
		}
		m_Factory[factory.name] = factory;
	}
	return true;
}

void CFactorioFactoryCalculatorDlg::ShowReadError(CString txt, CString file, int lineNum, CString line)
{
	CString buff;
	buff.Format(_T("%s\nFile: %s\nLine: %d\nText: %s"), txt, file, lineNum, line);
	MessageBox(buff);
}

void CFactorioFactoryCalculatorDlg::UpdateTargetCombo()
{
	for each (auto item in m_Item)
	{
		m_CtrlComboTargetItem.AddString(item.first);
	}
}


void CFactorioFactoryCalculatorDlg::OnCbnSelchangeComboTarget()
{
	ClearTree();
	
	int sel = m_CtrlComboTargetItem.GetCurSel();
	if (sel == CB_ERR) {
		return;
	}

	CString itemName;
	m_CtrlComboTargetItem.GetLBText(sel, itemName);
	SItem item = m_Item[itemName];
	
	CStatusDlgThread* pThread = DYNAMIC_DOWNCAST(CStatusDlgThread, AfxBeginThread(RUNTIME_CLASS(CStatusDlgThread) , 0, 0, CREATE_SUSPENDED));
	// Add initialization if needed before ResumeThread()
	pThread->ResumeThread();
	while (pThread->m_Dlg.m_hWnd == 0) {
		Sleep(0);
	}

	pThread->UpdateStatus(_T("Start adding item to the tree"));
	AddNode(&item, NULL, pThread);
	
	pThread->UpdateStatus(_T("Updating values in the tree"));
	UpdateValues();

	if (!pThread->m_Valid) {
		ClearTree();
	}
	else {
		NMTREEVIEW trv;
		HTREEITEM hTree = m_CtrlTree.GetRootItem();
		trv.itemOld.hItem = hTree;
		trv.itemNew.hItem = hTree;
		LRESULT result;
		OnTvnSelchangedTree(reinterpret_cast<NMHDR*>(&trv), &result);

		pThread->m_Dlg.PostMessage(WM_COMMAND, IDOK);
	}

	WaitForSingleObject(pThread->m_hThread, 30000);	// Wait for the thread to be ended
	delete pThread;
}

void CFactorioFactoryCalculatorDlg::AddNode(SItem* pItem, HTREEITEM parent, CStatusDlgThread* pStatus)
{
	if (!pStatus->m_Valid) {
		return;
	}
	HTREEITEM hTree = m_CtrlTree.InsertItem(pItem->name, parent, TVI_LAST);
	SItem* p = new SItem;
	*p = *pItem;
	m_CtrlTree.SetItemData(hTree, DWORD_PTR(p));
	if (!CheckLoop(parent, pItem->name)) {	// As this makes a loop, do not add an child
		p->loop = true;
	}
	else {
		for each (auto child in pItem->matName)
		{
			if (m_Item.find(child) == m_Item.end()) {
				SItem emptyItem;
				emptyItem.name = child;
				emptyItem.validSpeed = false;
				m_Item[child] = emptyItem;
			}
			AddNode(&m_Item[child], hTree, pStatus);
		}
		
		CString buff;
		buff.Format(_T("Adding item to tree: %d"), m_CtrlTree.GetCount());
		pStatus->UpdateStatus(buff);
	}
}

// If there is a loop, then return false. If no loop, return true
bool CFactorioFactoryCalculatorDlg::CheckLoop(HTREEITEM hTree, CString name)
{
	if (hTree == NULL) {
		return true;
	}

	if (m_CtrlTree.GetItemText(hTree) == name) {
		return false;
	}
	HTREEITEM parent = m_CtrlTree.GetParentItem(hTree);
	if (parent == NULL) {
		return true;
	}
	return CheckLoop(parent, name);
}


void CFactorioFactoryCalculatorDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	ClearTree();
}


void CFactorioFactoryCalculatorDlg::OnTvnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CString buff;
	HTREEITEM hNew = pNMTreeView->itemNew.hItem;
	SItem* pItem = reinterpret_cast<SItem*>(m_CtrlTree.GetItemData(hNew));

	m_CtrlEditItemName.SetWindowText(pItem->name);
	buff.Format(_T("%.2f"), pItem->reqNumPerTarget);
	m_CtrlEditReqItemNum.SetWindowText(buff);
	buff.Format(_T("%.2f"), pItem->reqItemPerSec);
	m_CtrlEditItemPerSec.SetWindowText(buff);
	buff.Format(_T("%.2f"), pItem->time);
	m_CtrlEditItemTime.SetWindowText(buff);
	buff.Format(_T("%.2f"), pItem->num);
	m_CtrlEditItemNum.SetWindowText(buff);

	if (!pItem->validSpeed) {
		m_CtrlEditItemTime.SetWindowText(_T("No Data"));
		m_CtrlEditItemNum.SetWindowText(_T("No Data"));
	}
	if (pItem->loop) {
		m_CtrlEditItemTime.SetWindowText(_T("Looped"));
		m_CtrlEditItemNum.SetWindowText(_T("Looped"));
	}

	m_CtrlComboFactory.ResetContent();
	m_CtrlEditFacGain.SetWindowText(_T("No Data"));
	m_CtrlEditFacReqNum.SetWindowText(_T("N/A"));

	if (pItem->facName.size() != 0) {
		for each (auto fac in pItem->facName)
		{
			m_CtrlComboFactory.AddString(fac);
		}

		m_CtrlComboFactory.SetCurSel(pItem->facSel);
		m_CtrlComboFactory.GetLBText(pItem->facSel, buff);
		if (m_Factory.find(buff) == m_Factory.end()) {
			SFactory empty;
			empty.name = buff;
			empty.gain = 1;
			empty.validGain = false;
			m_Factory[buff] = empty;
		}
		SFactory fact = m_Factory[buff];
		if (fact.validGain) {
			buff.Format(_T("%.2f"), fact.gain);
			m_CtrlEditFacGain.SetWindowText(buff);
			buff.Format(_T("%.2f"), pItem->reqFacNum);
			m_CtrlEditFacReqNum.SetWindowText(buff);
		}
	}
	*pResult = 0;
}


void CFactorioFactoryCalculatorDlg::OnBnClickedButtonTime()
{
	CString buff;
	m_CtrlEditTargetTime.GetWindowText(buff);
	if (buff.GetLength() < 1) {
		MessageBox(_T("Please set a number"));
		return;
	}
	double tmp = _ttof(buff);
	if (tmp <= 0.0) {
		MessageBox(_T("Please set a positive number"));
		return;
	}
	buff.Format(_T("%.5f"), 1 / tmp);
	m_CtrlEditTargetSpeed.SetWindowText(buff);

	OnBnClickedButtonSet();
}


void CFactorioFactoryCalculatorDlg::OnBnClickedButtonSet()
{
	CString buff;
	m_CtrlEditTargetSpeed.GetWindowText(buff);
	if (buff.GetLength() < 1) {
		MessageBox(_T("Please set a number"));
		return;
	}
	double tmp = _ttof(buff);
	if (tmp <= 0.0) {
		MessageBox(_T("Please set a positive number"));
		return;
	}
	m_TargetSpeed = tmp;
	buff.Format(_T("%.5f"), 1 / tmp);
	m_CtrlEditTargetTime.SetWindowText(buff);

	UpdateValues();
}


void CFactorioFactoryCalculatorDlg::UpdateValues()
{
	HTREEITEM root = m_CtrlTree.GetRootItem();
	if (root == NULL) {
		return;
	}

	UpdateValuesSub(root, 1, true);

	HTREEITEM hTree = m_CtrlTree.GetSelectedItem();
	if (hTree == NULL) {
		hTree = m_CtrlTree.GetRootItem();
	}
	NMTREEVIEW trv;
	trv.itemOld.hItem = hTree;
	trv.itemNew.hItem = hTree;
	LRESULT result;
	OnTvnSelchangedTree(reinterpret_cast<NMHDR*>(&trv), &result);
}

void CFactorioFactoryCalculatorDlg::UpdateValuesSub(HTREEITEM hCurrent, double reqNum, bool validSpeed)
{
	SItem* pItem = reinterpret_cast<SItem*>(m_CtrlTree.GetItemData(hCurrent));

	bool valid = pItem->validSpeed;
	if (pItem->validSpeed) {
		if (m_Factory.find(pItem->facName[pItem->facSel]) == m_Factory.end()) {
			SFactory empty;
			empty.name = pItem->facName[pItem->facSel];
			empty.gain = 1;
			empty.validGain = false;
			m_Factory[empty.name] = empty;
			valid = false;
		}
	}

	pItem->reqNumPerTarget = reqNum;
	pItem->reqItemPerSec = pItem->reqNumPerTarget * m_TargetSpeed;

	if (valid) {
		pItem->reqFacNum = pItem->reqNumPerTarget * pItem->time *m_TargetSpeed / pItem->num / m_Factory[pItem->facName[pItem->facSel]].gain;
	}

	HTREEITEM child = m_CtrlTree.GetChildItem(hCurrent);
	int i = 0;
	while (child != NULL) {
		UpdateValuesSub(child, reqNum * pItem->matNum[i] / pItem->num, valid);
		child = m_CtrlTree.GetNextSiblingItem(child);
		i++;
	}
}


void CFactorioFactoryCalculatorDlg::OnCbnSelchangeComboFactory()
{
	int sel = m_CtrlComboFactory.GetCurSel();
	if (sel == CB_ERR) {
		return;
	}

	HTREEITEM hTree = m_CtrlTree.GetSelectedItem();
	ASSERT(hTree != NULL);

	SItem* pItem = reinterpret_cast<SItem*>(m_CtrlTree.GetItemData(hTree));
	ASSERT(pItem != NULL);
	pItem->facSel = sel;
	UpdateValues();
}


void CFactorioFactoryCalculatorDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	lpMMI->ptMinTrackSize = CPoint(m_DefParentRect.Width(), m_DefParentRect.Height());

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


void CFactorioFactoryCalculatorDlg::OnBnClickedButtonJump()
{
	CString target;
	m_CtrlEditItemName.GetWindowText(target);
	if (target.GetLength() < 1) {
		return;
	}
	int index = m_CtrlComboTargetItem.FindStringExact(-1, target);
	if (index == CB_ERR) {
		return;
	}
	m_CtrlComboTargetItem.SetCurSel(index);
	OnCbnSelchangeComboTarget();
}


void CFactorioFactoryCalculatorDlg::OnOK()
{
	// Ignore enter key
	// CDialogEx::OnOK();
}
