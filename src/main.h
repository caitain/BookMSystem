// main.h : main header file for the MAIN application
//

#if !defined(AFX_MAIN_H__21B18109_7E7A_4CC0_A920_5D8C5944902C__INCLUDED_)
#define AFX_MAIN_H__21B18109_7E7A_4CC0_A920_5D8C5944902C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMainApp:
// See main.cpp for the implementation of this class
//

class CMainApp : public CWinApp
{
public:
	long useID;
	CString m_oweruse;
	BOOL m_flag;
	CMainApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMainApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAIN_H__21B18109_7E7A_4CC0_A920_5D8C5944902C__INCLUDED_)
