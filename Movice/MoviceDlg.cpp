
// MoviceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Movice.h"
#include "MoviceDlg.h"
#include "afxdialogex.h"
#include "Cdmsoft.h"
#include "../Movice/logs/netIOlog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Cdmsoft dm;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMoviceDlg 对话框



CMoviceDlg::CMoviceDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MOVICE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMoviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(CMoviceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMoviceDlg::OnBnClickedOk)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMoviceDlg::OnSelchangeTab1)
END_MESSAGE_MAP()


// CMoviceDlg 消息处理程序

BOOL CMoviceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	//向标签控件中添加选项卡
	m_Tab.InsertItem(0, "日志", 0);
	m_Tab.InsertItem(1, "设置", 1);

	//创建子窗口
	m_TabLogs.Create(IDD_TABLOGS, &m_Tab);
	m_TabSet.Create(IDD_TABSET, &m_Tab);
	

	CRect clientRC;
	m_Tab.GetClientRect(clientRC);			//获取标签客户区域
	clientRC.DeflateRect(2, 30, 2, 2);		//减少客户区域大小

	m_TabLogs.MoveWindow(clientRC);		//移动子窗口
	m_TabSet.MoveWindow(clientRC);		//移动子窗口
	

	m_TabLogs.ShowWindow(SW_SHOW);			//显示子窗口
	m_Tab.SetCurSel(0);						//设置默认选中的标签页

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMoviceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMoviceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMoviceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMoviceDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	sprintf(_dbgtemp, "初始化大漠插件"); writeLog(_dbgtemp, true);
	CString strFilePath;
	char strBuff[256];
	Cdmsoft dm;
	::CoInitialize(NULL);//初始化线程COM库
	dm.CreateDispatch(_T("dm.dmsoft"));
	strFilePath.Format("%s", dm.Ver());
	MessageBox(NULL, strFilePath, MB_OK);
}


void CMoviceDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int nCurSel = m_Tab.GetCurSel();
	if (nCurSel == 0)
	{
		
		m_TabLogs.ShowWindow(SW_SHOW);
		m_TabSet.ShowWindow(SW_HIDE);

	}
	else if (nCurSel == 1)
	{
		m_TabSet.ShowWindow(SW_SHOW);
		m_TabLogs.ShowWindow(SW_HIDE);
	}
	*pResult = 0;
}
