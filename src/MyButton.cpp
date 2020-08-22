// MyButton.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "MyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyButton

CMyButton::CMyButton()
{
	m_mouse_flag=false;
    m_hcursor=AfxGetApp()->LoadCursor(IDC_HAND);
	m_sound_flg=true;
}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	//{{AFX_MSG_MAP(CMyButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyButton message handlers

void CMyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
	if(!m_mouse_flag)
	{
		 this->SetBackGroud(this->GetBitmapID()+1);
	}
}

void CMyButton::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
	CRect rect;
	this->GetWindowRect(rect);
	CBitmap bitmap;
	bitmap.LoadBitmap(this->GetBitmapID());
	BITMAP bt;
	bitmap.GetBitmap(&bt);
	this->SetWindowPos(NULL,rect.left,rect.top,bt.bmWidth,bt.bmHeight,SWP_FRAMECHANGED);
}

UINT CMyButton::GetBitmapID()
{
   switch(GetDlgCtrlID())
	 {
	       case IDC_CANCEL:return IDB_CANCEL;break;
	       case IDC_INDEX:return IDB_INDEX;break;
		   case IDC_SORT:return IDB_SORT;break;
		   case IDC_USE:return IDB_USE;break;
		   case IDC_LOGO:return IDB_LOGO;break;
		   case IDC_NEWSADD:return IDB_ADDNEW;break;
		   case IDC_RETURNBOOK:return IDB_RETURN;break;
		   case IDC_BORROW_BOOK:return IDB_BORROW;break;
           case IDC_READ:return IDB_READ;break;
		   case IDC_QUERY_OK:return IDB_QUERY;break;
		   case IDC_CANCELBOX:return IDB_MCACEL;break;
			case IDC_MINIBOX:return IDB_MMIN;break;

	 }
	 return 0;
}

void CMyButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (!m_mouse_flag)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_mouse_flag = _TrackMouseEvent(&tme);
		switch(GetDlgCtrlID())
		 {
		     case IDC_CANCEL:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_INDEX:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_SORT:this->SetBackGroud(this->GetBitmapID());break;
             case IDC_USE:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_LOGO:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_NEWSADD:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_READ:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_RETURNBOOK:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_BORROW_BOOK:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_QUERY_OK:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_CANCELBOX:this->SetBackGroud(this->GetBitmapID());break;
			 case IDC_MINIBOX:this->SetBackGroud(this->GetBitmapID());break;
		 }
	}
    if(m_sound_flg)
	{
	  PlaySound(MAKEINTRESOURCE(IDR_NORMAL1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE);
	  m_sound_flg=false;
	}
	CButton::OnMouseMove(nFlags, point);
}
LRESULT CMyButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
    if(!m_mouse_flag)
	{
	     switch(GetDlgCtrlID())
		 {
		     case IDC_CANCEL:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_INDEX:this->SetBackGroud(this->GetBitmapID()+1);break;
		     case IDC_SORT:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_USE:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_LOGO:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_NEWSADD:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_READ:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_RETURNBOOK:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_BORROW_BOOK:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_QUERY_OK:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_CANCELBOX:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_MINIBOX:this->SetBackGroud(this->GetBitmapID()+1);break;
		 }
	}
	m_sound_flg=true;
	m_mouse_flag=false;
	return 0;
}

void CMyButton::SetBackGroud(UINT nID)
{
       CDC *dc;
	   dc=GetDC();
	   CRect rect;
	   GetWindowRect(rect);
	   ScreenToClient(rect);
	   CBitmap bitmap;
	   BITMAP bm;
	   bitmap.LoadBitmap(nID);
	   bitmap.GetBitmap(&bm);
	   CPen pen(PS_SOLID,1,RGB(255,255,0));
	   dc->SelectObject(&pen);
	   CBrush brush;
	   brush.CreatePatternBrush(&bitmap);
	   dc->SelectObject(&brush);
	   POINT point;
	   point.x=5;
	   point.y=5;
	   dc->RoundRect(rect,point);
	  /* CDC *dc;
	   dc=GetDC();
	   CRect rect;
	   GetClientRect(rect);
	   CDC pDC;
	   CBitmap bitmap;
	   BITMAP bm;
	   bitmap.LoadBitmap(nID);
	   bitmap.GetBitmap(&bm);
	   pDC.CreateCompatibleDC(dc);
	   pDC.SelectObject(&bitmap);
	   dc->SetStretchBltMode(COLORONCOLOR);//这个模式不设置的话会导致图片严重失真
       dc->StretchBlt(0,0,rect.Width() ,rect.Height(),
       &pDC,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
       //dcMem.SelectObject(pOldBitmap);
	   CRgn rgn;
	   rgn.CreateRoundRectRgn(rect.left,rect.top,rect.right,rect.bottom,10,10);
	   this->SetWindowRgn(rgn,true);*/
	   m_mouse_flag=false;
}

BOOL CMyButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(m_hcursor);
	return true;
	return CButton::OnSetCursor(pWnd, nHitTest, message);
}
