#if !defined(AFX_DATADLG_H__67A5DCC3_5792_4B6C_8F56_7649EA2CBB4C__INCLUDED_)
#define AFX_DATADLG_H__67A5DCC3_5792_4B6C_8F56_7649EA2CBB4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog
#include "datagrid.h"
class CDataDlg : public CDialog
{
// Construction
public:
	CString m_sql;
	CDataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDataDlg)
	enum { IDD = IDD_DATA };
	long	m_ID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:

	// Generated message map functions
	//{{AFX_MSG(CDataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBook();
	afx_msg void OnRead();
	afx_msg void OnUse();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnSave();
	afx_msg void OnDelete();
	afx_msg void OnSerch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDataGrid * m_data_grid;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATADLG_H__67A5DCC3_5792_4B6C_8F56_7649EA2CBB4C__INCLUDED_)
