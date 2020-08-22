#if !defined(AFX_LOGODLG_H__2D71B2D3_F760_4F46_9D08_DEA7CEDED4E1__INCLUDED_)
#define AFX_LOGODLG_H__2D71B2D3_F760_4F46_9D08_DEA7CEDED4E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogoDlg dialog
#include "LogoButton.h"
#include "MyEdit.h"
#include "RegisterDlg.h"
class CLogoDlg : public CDialog
{
// Construction
public:
	long m_useID;
	_RecordsetPtr m_recordset;
	_ConnectionPtr m_connection;
	BOOL OnSQLexcute(_RecordsetPtr &recor,_variant_t &sql);
	BOOL m_logo_succeed;
	CLogoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogoDlg)
	enum { IDD = IDD_LOGO_DIALOG };
	CLogoButton	m_register;
	CLogoButton	m_quit;
	CLogoButton	m_min;
	CMyEdit	m_Echeck;
	CMyEdit	m_Epass;
	CMyEdit	m_Euse;
	CLogoButton	m_reset;
	CLogoButton	m_logo;
	CString	m_check;
	CString	m_password;
	CString	m_usename;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogoDlg)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnLogo();
	afx_msg void OnReset();
	afx_msg void OnMin();
	afx_msg void OnLcancel();
	afx_msg void OnRegister();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CToolTipCtrl m_tipctrl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGODLG_H__2D71B2D3_F760_4F46_9D08_DEA7CEDED4E1__INCLUDED_)
