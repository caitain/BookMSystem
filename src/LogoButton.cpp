// LogoButton.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "LogoButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogoButton

CLogoButton::CLogoButton()
{
	m_mouse_flag=false;
	m_sound_flag=true;
}

CLogoButton::~CLogoButton()
{
}


BEGIN_MESSAGE_MAP(CLogoButton, CButton)
	//{{AFX_MSG_MAP(CLogoButton)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE,OnMouseLeave)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogoButton message handlers

void CLogoButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your code to draw the specified item
		if(!m_mouse_flag)
	{
		 this->SetBackGroud(this->GetBitmapID()+1);
	}
}

UINT CLogoButton::GetBitmapID()
{
     switch(GetDlgCtrlID())
	 {
	       case IDC_LOGO:return IDB_LOGO;break;
		   case IDC_RESET:return IDB_RESET;break;
		   case IDC_MIN:return IDB_LMIN;break;
		   case IDC_LCANCEL:return IDB_LCANCEL;break;
           case IDC_REGISTER:return IDB_REGIT;break;
	 }
	 return 0;
}

void CLogoButton::OnMouseMove(UINT nFlags, CPoint point) 
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
		    case IDC_LOGO:this->SetBackGroud(this->GetBitmapID());break;
			case IDC_RESET:this->SetBackGroud(this->GetBitmapID());break;
			case IDC_MIN:this->SetBackGroud(this->GetBitmapID());break;
			case IDC_LCANCEL:this->SetBackGroud(this->GetBitmapID());break;
			case IDC_REGISTER:this->SetBackGroud(this->GetBitmapID());break;
		 }
	
	}
	if(m_sound_flag)
	{
	    PlaySound(MAKEINTRESOURCE(IDR_NORMAL1),AfxGetResourceHandle(),SND_ASYNC|SND_RESOURCE);
	    m_sound_flag=false;
	}
	CButton::OnMouseMove(nFlags, point);
}
LRESULT CLogoButton::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
    if(!m_mouse_flag)
	{
	     switch(GetDlgCtrlID())
		 {
		     case IDC_LOGO:this->SetBackGroud(this->GetBitmapID()+1);break;
			 case IDC_RESET:this->SetBackGroud(this->GetBitmapID()+1);break;
			case IDC_MIN:this->SetBackGroud(this->GetBitmapID()+1);break;
			case IDC_LCANCEL:this->SetBackGroud(this->GetBitmapID()+1);break;
			case IDC_REGISTER:this->SetBackGroud(this->GetBitmapID()+1);break;
		 }
	}
	m_sound_flag=true;	
	m_mouse_flag=false;
	return 0;
}

void CLogoButton::SetBackGroud(UINT nID)
{
	   CDC *dc;
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
	   this->SetWindowRgn(rgn,true);
	   m_mouse_flag=false;
}

void CLogoButton::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	CButton::PreSubclassWindow();
	ModifyStyle(0,BS_OWNERDRAW);
	/*CRect rect;
	this->GetWindowRect(rect);
	CBitmap bitmap;
	bitmap.LoadBitmap(this->GetBitmapID());
	BITMAP bt;
	bitmap.GetBitmap(&bt);
	this->SetWindowPos(NULL,rect.left,rect.top,bt.bmWidth,bt.bmHeight,SWP_FRAMECHANGED);
	*///CButton::PreSubclassWindow();
}

BOOL CLogoButton::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(AfxGetApp()->LoadCursor(IDC_HAND));
	return true;
	return CButton::OnSetCursor(pWnd, nHitTest, message);
}
