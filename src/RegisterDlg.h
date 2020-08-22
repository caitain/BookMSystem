#if !defined(AFX_REGISTERDLG_H__AEAD3AC5_8BB5_495B_AA3A_C5731692262F__INCLUDED_)
#define AFX_REGISTERDLG_H__AEAD3AC5_8BB5_495B_AA3A_C5731692262F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog
#include "MyEdit.h"
class CRegisterDlg : public CDialog
{
// Construction
public:
	BOOL DoSQLexcute(_RecordsetPtr &record,_variant_t sql);
	_RecordsetPtr m_recordset;
	_ConnectionPtr m_connection;
	CRegisterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisterDlg)
	enum { IDD = IDD_REGISTER_DLG };
	CMyEdit	m_edpass2;
	CMyEdit	m_edpass;
	CMyEdit	m_edname;
	CComboBox	m_borrow_ID;
	CString	m_usename;
	CString	m_pass1;
	CString	m_pass2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegisterDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnRegister();
	virtual void OnCancel();
	afx_msg void OnReset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	long bookID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERDLG_H__AEAD3AC5_8BB5_495B_AA3A_C5731692262F__INCLUDED_)
