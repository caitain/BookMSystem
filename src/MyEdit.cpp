// MyEdit.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "MyEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyEdit

CMyEdit::CMyEdit()
{
}

CMyEdit::~CMyEdit()
{
}


BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	//{{AFX_MSG_MAP(CMyEdit)
	ON_WM_ERASEBKGND()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyEdit message handlers

BOOL CMyEdit::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default

	CRect rect;
	GetWindowRect(rect);
	ScreenToClient(rect);
	CBrush brush(RGB(134,249,235));
	pDC->FillRect(rect,&brush);
	return true;
	return CEdit::OnEraseBkgnd(pDC);
}

BOOL CMyEdit::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(AfxGetApp()->LoadCursor(IDC_EDIT));
	return true;
	return CEdit::OnSetCursor(pWnd, nHitTest, message);
}
