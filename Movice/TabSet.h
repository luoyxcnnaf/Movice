#pragma once


// CTabSet �Ի���

class CTabSet : public CDialog
{
	DECLARE_DYNAMIC(CTabSet)

public:
	CTabSet(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTabSet();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABSET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
