// TabSet.cpp : 实现文件
//

#include "stdafx.h"
#include "Movice.h"
#include "TabSet.h"
#include "afxdialogex.h"
#include "MoviceDlg.h"




// CTabSet 对话框

IMPLEMENT_DYNAMIC(CTabSet, CDialog)

CTabSet::CTabSet(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_TABSET, pParent)
{

}

CTabSet::~CTabSet()
{
}

void CTabSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTabSet, CDialog)
	ON_BN_CLICKED(IDOK, &CTabSet::OnBnClickedOk)
END_MESSAGE_MAP()


// CTabSet 消息处理程序


void CTabSet::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CMoviceDlg *pDlg = (CMoviceDlg *)GetParent()->GetParent();
	pDlg->AddMsgToLogs("dddd");


}

