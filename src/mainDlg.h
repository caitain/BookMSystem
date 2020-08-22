// mainDlg.h : header file
//

#if !defined(AFX_MAINDLG_H__B3B66F87_28AD_4A0D_B333_A0501B5386CC__INCLUDED_)
#define AFX_MAINDLG_H__B3B66F87_28AD_4A0D_B333_A0501B5386CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog
#include "MyButton.h"
#include "datagrid.h"	// Added by ClassView
#include "column.h"
#include "columns.h"
#include "LogoDlg.h"
#include "BorrowDlg.h"
#include "ReturnDlg.h"
#include "DataDlg.h"
#include "SetDlg.h"
class CMainDlg : public CDialog
{
// Construction
public:
	void HideDialog();
	void ShowData(_RecordsetPtr &record);
	BOOL OnSQLexcute(_RecordsetPtr &recor,_variant_t &sql);
	CMainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMainDlg)
	enum { IDD = IDD_MAIN_DIALOG };
	CComboBox	m_sort_com;
	CMyButton	m_bmin;
	CMyButton	m_bcancel;
	CComboBox	m_book_class2;
	CComboBox	m_book_class;
	CMyButton	m_btnquery;
	CMyButton	m_btnborrow;
	CMyButton	m_btnread;
	CMyButton	m_btnreturn;
	CComboBox	m_select_comb;
	CMyEdit	m_edit_time;
	CMyEdit	m_text;
	CMyButton	m_addnew;
	CStatic	m_place;
	CMyButton	m_use;
	CMyButton	m_sort;
	CMyButton	m_index;
	CMyButton	m_ctcancel;
	CString	m_textuser;
	CString	m_query_text;
	CString	m_time;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMainDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCancel();
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnUse();
	afx_msg void OnSort();
	afx_msg void OnNewsadd();
	afx_msg void OnReturnbook();
	afx_msg void OnBorrowBook();
	afx_msg void OnRead();
	afx_msg void OnQueryOk();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnChangeQueryText();
	afx_msg void OnIndex();
	afx_msg void OnData();
	afx_msg void OnMeney();
	afx_msg void OnLookHave();
	afx_msg void OnChnia();
	afx_msg void OnSelchangeClass();
	afx_msg void OnSelchangeBookClass2();
	afx_msg void OnSet();
	afx_msg void OnMinibox();
	afx_msg void OnCancelbox();
	afx_msg void OnLookHave2();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnChnia2();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CDataDlg m_data_dlg;
	CToolTipCtrl m_mtipctrl;
	CReturnDlg m_return_dlg;
	CBorrowDlg m_borrow_dlg;
	CString m_sql_text;
	CDataGrid m_datagrid;
	HCURSOR m_hcursor;
public:
	long m_main_useID;
	void UseShow();
	CSetDlg m_set_dlg;
	BOOL m_bool_admin;
	_RecordsetPtr m_precordset;
	_ConnectionPtr m_pconnection;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__B3B66F87_28AD_4A0D_B333_A0501B5386CC__INCLUDED_)
