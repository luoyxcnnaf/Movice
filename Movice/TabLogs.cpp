// TabLogs.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Movice.h"
#include "TabLogs.h"
#include "afxdialogex.h"


// CTabLogs �Ի���

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


// CTabLogs ��Ϣ�������


BOOL CTabLogs::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


int CTabLogs::AddLogToList(CString str)
{
	m_LogsList.AddString(str);
	return 0;
}


void CTabLogs::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AddLogToList("aaaaaaaaaaaaaaaa");
}

