
// MoviceDlg.cpp : ʵ���ļ�
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMoviceDlg �Ի���



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


// CMoviceDlg ��Ϣ�������

BOOL CMoviceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	//���ǩ�ؼ������ѡ�
	m_Tab.InsertItem(0, "��־", 0);
	m_Tab.InsertItem(1, "����", 1);

	//�����Ӵ���
	m_TabLogs.Create(IDD_TABLOGS, &m_Tab);
	m_TabSet.Create(IDD_TABSET, &m_Tab);
	

	CRect clientRC;
	m_Tab.GetClientRect(clientRC);			//��ȡ��ǩ�ͻ�����
	clientRC.DeflateRect(2, 30, 2, 2);		//���ٿͻ������С

	m_TabLogs.MoveWindow(clientRC);		//�ƶ��Ӵ���
	m_TabSet.MoveWindow(clientRC);		//�ƶ��Ӵ���
	

	m_TabLogs.ShowWindow(SW_SHOW);			//��ʾ�Ӵ���
	m_Tab.SetCurSel(0);						//����Ĭ��ѡ�еı�ǩҳ

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMoviceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMoviceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMoviceDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	sprintf(_dbgtemp, "��ʼ����Į���"); writeLog(_dbgtemp, true);
	CString strFilePath;
	char strBuff[256];
	Cdmsoft dm;
	::CoInitialize(NULL);//��ʼ���߳�COM��
	dm.CreateDispatch(_T("dm.dmsoft"));
	strFilePath.Format("%s", dm.Ver());
	MessageBox(NULL, strFilePath, MB_OK);
}


void CMoviceDlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
