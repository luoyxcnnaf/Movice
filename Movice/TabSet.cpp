// TabSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Movice.h"
#include "TabSet.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// CTabSet ��Ϣ�������
