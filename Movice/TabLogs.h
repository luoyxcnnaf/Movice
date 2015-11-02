#pragma once
#include "afxwin.h"


// CTabLogs 对话框

class CTabLogs : public CDialog
{
	DECLARE_DYNAMIC(CTabLogs)

public:
	CTabLogs(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTabLogs();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABLOGS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListBox m_LogsList;
	int AddLogToList(CString s);
	afx_msg void OnBnClickedButton1();
protected:
	
};
