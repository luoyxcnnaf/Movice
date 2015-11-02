#pragma once
#include "TabLogs.h"

// CTabSet 对话框

class CTabSet : public CDialog
{
	DECLARE_DYNAMIC(CTabSet)

public:
	CTabSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTabSet();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABSET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:

private:
	CTabLogs* logsDLG ;
};
