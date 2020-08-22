#if !defined(AFX_RETURNDLG_H__7D339948_289D_4C04_9BAE_E2D1C8022D66__INCLUDED_)
#define AFX_RETURNDLG_H__7D339948_289D_4C04_9BAE_E2D1C8022D66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReturnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReturnDlg dialog
#include "MyEdit.h"
class CReturnDlg : public CDialog
{
// Construction
public:
	CDataGrid * m_data_book;
	CReturnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReturnDlg)
	enum { IDD = IDD_RETURN_DLG };
	CMyEdit	m_ebook;
	CString	m_book;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReturnDlg)
	afx_msg void OnChangeEdit1();
	virtual BOOL OnInitDialog();
	afx_msg void OnReturnBook();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNDLG_H__7D339948_289D_4C04_9BAE_E2D1C8022D66__INCLUDED_)
