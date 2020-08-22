#if !defined(AFX_BORROWDLG_H__DED9BE6A_011B_47CC_A6F8_30C61C9BAF60__INCLUDED_)
#define AFX_BORROWDLG_H__DED9BE6A_011B_47CC_A6F8_30C61C9BAF60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowDlg dialog
#include "datagrid.h"
#include "MyEdit.h"
class CBorrowDlg : public CDialog
{
// Construction
public:
	CDataGrid * m_data_book;
	CDataGrid *m_data_read;

	CBorrowDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBorrowDlg)
	enum { IDD = IDD_BORROW_DLG };
	CMyEdit	m_eread;
	CMyEdit	m_edbook;
	CString	m_read;
	CString	m_book;
	int		m_overday;
	CString	m_money;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBorrowDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnPayoff();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWDLG_H__DED9BE6A_011B_47CC_A6F8_30C61C9BAF60__INCLUDED_)
