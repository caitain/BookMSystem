#if !defined(AFX_LOGOBUTTON_H__CACD3F81_EA4A_40DB_8B9C_BC5DB9638EE9__INCLUDED_)
#define AFX_LOGOBUTTON_H__CACD3F81_EA4A_40DB_8B9C_BC5DB9638EE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogoButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogoButton window

class CLogoButton : public CButton
{
// Construction
public:
	CLogoButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogoButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetBackGroud(UINT nID);
	UINT GetBitmapID();
	virtual ~CLogoButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLogoButton)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	BOOL m_sound_flag;
	BOOL m_mouse_flag;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGOBUTTON_H__CACD3F81_EA4A_40DB_8B9C_BC5DB9638EE9__INCLUDED_)
