// SetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "SetDlg.h"
#include "MainDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDlg dialog


CSetDlg::CSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDlg)
	//}}AFX_DATA_INIT
}


void CSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDlg)
	DDX_Control(pDX, IDC_COMBO3, m_max_book);
	DDX_Control(pDX, IDC_COMBO2, m_min_money);
	DDX_Control(pDX, IDC_COMBO1, m_max_day);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDlg)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_DAY, OnDay)
	ON_BN_CLICKED(IDC_MONEY, OnMoney)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDlg message handlers

BOOL CSetDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
    CRect rect;
    GetClientRect(&rect);
    CBitmap m_bitmap;
    BITMAP bm;
    CDC dcMem;
    m_bitmap.LoadBitmap(IDB_DLGBACK);
    m_bitmap.GetBitmap(&bm);//得到位图尺寸
    dcMem.CreateCompatibleDC(pDC);
    CBitmap* pOldBitmap = dcMem.SelectObject(&m_bitmap);
    pDC->SetStretchBltMode(COLORONCOLOR);//这个模式不设置的话会导致图片严重失真
    pDC->StretchBlt(0,0,rect.Width() ,rect.Height(),
    &dcMem,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
    dcMem.SelectObject(pOldBitmap);
   return true;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor   ==   CTLCOLOR_STATIC)
       { 
		    pDC-> SetBkMode(TRANSPARENT);   //静态控件设置背景透明 
            pDC->SetTextColor(RGB(0,255,255));
			return   HBRUSH(GetStockObject(HOLLOW_BRUSH)); 
       }   
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CSetDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_max_day.SetCurSel(0);
	m_min_money.SetCurSel(0);
	m_max_book.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetDlg::OnOK() 
{
	// TODO: Add extra validation here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	UpdateData();
    CString day;
	m_max_day.GetLBText(m_max_day.GetCurSel(),day);
	day.TrimLeft();
	day.TrimRight();
	CString money;
	m_min_money.GetLBText(m_min_money.GetCurSel(),money);
	money.TrimLeft();
	money.TrimRight();
    long m_day;
	double m_money;
	m_day=atoi(day);
	m_money=atof(money);
    CString cs;
	cs.Format("update 图书基本信息 set 可借天数=%ld,超期罚款=%lf",m_day,m_money);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	CString book_i;
	m_max_book.GetLBText(m_max_book.GetCurSel(),book_i);
	cs.Format("update 读者信息表 set 可借图书数=%d",atoi(book_i));
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("设置成功");
	cs="select * from 图书基本信息";
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
	return ;
	//CDialog::OnOK();
}

void CSetDlg::OnDay() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	UpdateData();
    CString day;
	m_max_day.GetLBText(m_max_day.GetCurSel(),day);
	day.TrimLeft();
	day.TrimRight();
    long m_day;
	m_day=atoi(day);
    CString cs;
	cs.Format("update 图书基本信息 set 可借天数=%ld",m_day);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("设置成功");
	cs="select * from 图书基本信息";
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
	return ;
}

void CSetDlg::OnMoney() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	UpdateData();
	CString money;
	m_min_money.GetLBText(m_min_money.GetCurSel(),money);
	money.TrimLeft();
	money.TrimRight();
	double m_money;
	m_money=atof(money);
    CString cs;
	cs.Format("update 图书基本信息 set 超期罚款=%lf",m_money);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("设置成功");
	cs="select * from 图书基本信息";
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
	return ;
}

void CSetDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	UpdateData();
	CString book_i,cs;
	m_max_book.GetLBText(m_max_book.GetCurSel(),book_i);
	cs.Format("update 读者信息表 set 可借图书数=%d",atoi(book_i));
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("设置成功");
	cs="select * from 图书基本信息";
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
	return ;
}
