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
}


BEGIN_MESSAGE_MAP(CTabLogs, CDialog)
END_MESSAGE_MAP()


// CTabLogs 消息处理程序
