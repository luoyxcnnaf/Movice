// TabLogs.cpp : 实现文件
//

#include "stdafx.h"
#include "Movice.h"
#include "TabLogs.h"
#include "afxdialogex.h"


// CTabLogs 对话框

IMPLEMENT_DYNAMIC(CTabLogs, CDialog)

CTabLogs::CTabLogs(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TABLOGS, pParent)
{

}

CTabLogs::~CTabLogs()
{
}

void CTabLogs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_LogsList);
}


BEGIN_MESSAGE_MAP(CTabLogs, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CTabLogs::OnBnClickedButton1)

END_MESSAGE_MAP()


// CTabLogs 消息处理程序


BOOL CTabLogs::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


int CTabLogs::AddLogToList(CString str)
{
	m_LogsList.AddString(str);
	return 0;
}


void CTabLogs::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	AddLogToList("aaaaaaaaaaaaaaaa");
}

