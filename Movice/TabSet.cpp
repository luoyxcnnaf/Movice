// TabSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Movice.h"
#include "TabSet.h"
#include "afxdialogex.h"
#include "MoviceDlg.h"




// CTabSet �Ի���

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


// CTabSet ��Ϣ�������


void CTabSet::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CMoviceDlg *pDlg = (CMoviceDlg *)GetParent()->GetParent();
	pDlg->AddMsgToLogs("dddd");


}

