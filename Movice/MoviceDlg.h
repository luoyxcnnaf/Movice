
// MoviceDlg.h : 头文件
//

#pragma once

#include "TabSet.h"
#include "TabLogs.h"
#include "afxcmn.h"

// CMoviceDlg 对话框
class CMoviceDlg : public CDialogEx
{
// 构造
public:
	CMoviceDlg(CWnd* pParent = NULL);	// 标准构造函数
	CTabLogs m_TabLogs;
	CTabSet m_TabSet;
	

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOVICE_DIALOG };

#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CTabCtrl m_Tab;
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	int AddMsgToLogs(CString str);
};
