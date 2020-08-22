// DataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "DataDlg.h"
#include "Maindlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataDlg dialog


CDataDlg::CDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDataDlg)
	m_ID = 0;
	//}}AFX_DATA_INIT
}


void CDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDataDlg)
	DDX_Text(pDX, IDC_USEID, m_ID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDataDlg, CDialog)
	//{{AFX_MSG_MAP(CDataDlg)
	ON_BN_CLICKED(IDC_BOOK, OnBook)
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_USE, OnUse)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_SERCH, OnSerch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataDlg message handlers

BOOL CDataDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_data_grid=(CDataGrid *)GetDlgItem(IDC_DATA_GRID);
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(!main->m_bool_admin)
	{
	   (CButton *)GetDlgItem(IDC_BOOK)->ShowWindow(false);
	   (CButton *)GetDlgItem(IDC_READ)->ShowWindow(false);
	    m_data_grid->SetAllowAddNew(false);
	}
	m_data_grid->SetCaption("图书基本信息表");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDataDlg::OnBook() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	CString cs;
	cs="select * from 图书基本信息";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_grid->SetRefDataSource(LPUNKNOWN(main->m_precordset));
	m_data_grid->SetCaption("图书基本信息表");
	m_data_grid->SetAllowAddNew(true);
}

void CDataDlg::OnRead() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	CString cs;
    cs="select * from 读者信息表";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_grid->SetRefDataSource(LPUNKNOWN(main->m_precordset));
	m_data_grid->SetCaption("读者信息表");
	m_data_grid->SetAllowAddNew(true);
}

void CDataDlg::OnUse() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	CString cs;
	if(main->m_bool_admin)
	cs="select * from 用户信息";
	else
		cs.Format("select 用户名,密码 from 用户信息 where 借书证号=%ld",main->m_main_useID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_grid->SetRefDataSource(LPUNKNOWN(main->m_precordset));
    m_data_grid->SetCaption("用户信息表");
	if(!main->m_bool_admin)
	m_data_grid->SetAllowAddNew(false);
}

BOOL CDataDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
    GetClientRect(&rect);
    CBitmap m_bitmap;
    BITMAP bm;
    CDC dcMem;
    m_bitmap.LoadBitmap(IDB_DLGBACK);
    m_bitmap.GetBitmap(&bm);
    dcMem.CreateCompatibleDC(pDC);
    CBitmap* pOldBitmap = dcMem.SelectObject(&m_bitmap);
    pDC->SetStretchBltMode(COLORONCOLOR);
    pDC->StretchBlt(0,0,rect.Width() ,rect.Height(),
    &dcMem,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
    dcMem.SelectObject(pOldBitmap);
   return true;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CDataDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor   ==   CTLCOLOR_STATIC)
       { 
		    pDC-> SetBkMode(TRANSPARENT);   //静态控件设置背景透明 
            pDC->SetTextColor(RGB(0,0,255));
			return   HBRUSH(GetStockObject(HOLLOW_BRUSH)); 
       }   
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CDataDlg::OnSave() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
}

BOOL CDataDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == 0x0D || pMsg->wParam == 0x1B))
	 {
      return false;
	 }
	return CDialog::PreTranslateMessage(pMsg);
}

void CDataDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
    if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
	{
        if(MessageBox("是否删除?","提示",MB_OKCANCEL)==IDOK)
		main->m_precordset->Delete(adAffectCurrent);
	}
}


void CDataDlg::OnSerch() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	UpdateData();
	if(this->m_ID==0)
		GetDlgItem(IDC_USEID)->SetFocus();
	CString cs;
    if(m_data_grid->GetCaption()=="图书基本信息表")
		     cs.Format("select * from 图书基本信息 where 图书ID=%ld",this->m_ID);
		else if (m_data_grid->GetCaption()=="读者信息表")
            cs.Format("select * from 读者信息表 where 借书证号=%ld",this->m_ID);
	    else if(main->m_bool_admin)
            cs.Format("select * from 用户信息 where 借书证号=%ld",this->m_ID);
			else cs.Format("select 用户名,密码 from 用户信息 where 借书证号=%ld",this->m_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_grid->SetRefDataSource(LPUNKNOWN(main->m_precordset));

}
