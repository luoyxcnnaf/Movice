
// MoviceDlg.h : ͷ�ļ�
//

#pragma once

#include "TabSet.h"
#include "TabLogs.h"
#include "afxcmn.h"

// CMoviceDlg �Ի���
class CMoviceDlg : public CDialogEx
{
// ����
public:
	CMoviceDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CTabLogs m_TabLogs;
	CTabSet m_TabSet;
	

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MOVICE_DIALOG };

#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
