#pragma once
#include "afxwin.h"


// CTabLogs �Ի���

class CTabLogs : public CDialog
{
	DECLARE_DYNAMIC(CTabLogs)

public:
	CTabLogs(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabLogs();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABLOGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox m_LogsList;
	int AddLogToList(CString s);
	afx_msg void OnBnClickedButton1();
protected:
	
};
