// BorrowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "BorrowDlg.h"
#include "mainDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowDlg dialog


CBorrowDlg::CBorrowDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBorrowDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBorrowDlg)
	m_read = _T("");
	m_book = _T("");
	m_overday = 0;
	m_money = _T("0");
	//}}AFX_DATA_INIT
	
}


void CBorrowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBorrowDlg)
	DDX_Control(pDX, IDC_EDIT2, m_eread);
	DDX_Control(pDX, IDC_EDIT1, m_edbook);
	DDX_Text(pDX, IDC_EDIT1, m_read);
	DDX_Text(pDX, IDC_EDIT2, m_book);
	DDX_Text(pDX, IDC_EDIT4, m_overday);
	DDX_Text(pDX, IDC_EDIT3, m_money);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBorrowDlg, CDialog)
	//{{AFX_MSG_MAP(CBorrowDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_BN_CLICKED(IDC_PAYOFF, OnPayoff)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBorrowDlg message handlers

BOOL CBorrowDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_data_read=(CDataGrid *)GetDlgItem(IDC_DATA_READ);
    m_data_book=(CDataGrid *)GetDlgItem(IDC_DATA_BOOK);
	GetDlgItem(IDC_PAYOFF)->ShowWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//DEL BOOL CBorrowDlg::PreCreateWindow(CREATESTRUCT& cs) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CDialog::PreCreateWindow(cs);
//DEL }

void CBorrowDlg::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	//CRect rect;
	//this->GetWindowRect(rect);
	//this->SetWindowPos(NULL,rect.left,rect.top,bt.bmWidth,bt.bmHeight,SWP_FRAMECHANGED);
	CDialog::PreSubclassWindow();
}

void CBorrowDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	//CDialog::OnCancel();
	this->ShowWindow(SW_HIDE);
}



void CBorrowDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(m_read.IsEmpty())
	{
	   //MessageBox("借书证号不能为空");
	   GetDlgItem(IDC_EDIT1)->SetFocus();
	   return ;
	}
	if(m_book.IsEmpty())
	{
	   //MessageBox("图书ID不能为空");
		GetDlgItem(IDC_EDIT2)->SetFocus();
	   return ;
	}
	long read_ID=atoi(m_read);
	long book_ID=atoi(m_book);
    CString cs;
	//查询读者、图书是否存在或输入是否正确
	cs.Format("select * from 读者信息表,图书基本信息 where 读者信息表.借书证号=%ld and \
		图书基本信息.图书ID=%ld",read_ID,book_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	if(main->m_precordset->GetRecordCount()==0)
	{
	   MessageBox("不存在此读者或书号,请查证输入是否正确");
	   return ;
	}
	//查询读者是否欠费
	cs.Format("select * from 读者信息表 where 借书证号=%ld and 超期天数<>0",read_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	else 
	{
	    if(main->m_precordset->GetRecordCount()!=0)
		{
			m_overday=main->m_precordset->GetCollect("超期天数").lVal;
            _variant_t money=main->m_precordset->GetCollect("欠费金额");
			m_money=money.vt==VT_NULL?"":(_bstr_t)money;
			
			(CButton *)GetDlgItem(IDC_PAYOFF)->ShowWindow(true);
			MessageBox("此读者尚未交清欠费！");
			//UpdateWindow();
			UpdateData(false);
			return ;
		}
	}
	cs.Format("select * from 读者信息表 where 借书证号=%ld",read_ID);
	_variant_t sql;
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	int i=main->m_precordset->GetCollect("已借图书数").lVal;
	int j=main->m_precordset->GetCollect("可借图书数").lVal;
	if(i>=j)
	{
		cs.Format("你已经借了%ld本书了，不能再借",i);
		MessageBox(cs);
		return;
	}
	cs.Format("select * from 图书基本信息 where 图书ID=%ld and 是否可借='否'",book_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
    if(main->m_precordset->GetRecordCount()!=0)
	{
	    MessageBox("此书已被借出");
		return ;
	}
	cs.Format("update 图书基本信息 set 借书证号=%ld,是否可借='否',借阅次数=借阅次数+1,借出日期='%s',归还日期=NULL where 图书ID=%ld",read_ID,main->m_time,book_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("成功借出");
	cs.Format("update 读者信息表 set 已借图书数=已借图书数+1 where 借书证号=%d",read_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	cs="select * from 图书基本信息 where 图书ID like '%%"+m_book+"%%'";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
		
	//CDialog::OnOK();
}

void CBorrowDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	CString cs;
	cs="select * from 读者信息表 where 借书证号 like '%%"+m_read+"%%'";
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	_variant_t sql;
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	_RecordsetPtr m_record;
	m_record=main->m_precordset;
	m_data_read->SetRefDataSource(LPUNKNOWN(m_record));
	// TODO: Add your control notification handler code here
}

void CBorrowDlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	UpdateData();
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	CString cs;
	cs="select * from 图书基本信息 where 图书ID like '%%"+m_book+"%%'";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_book->SetRefDataSource(LPUNKNOWN(main->m_precordset));
	// TODO: Add your control notification handler code here
	
}

void CBorrowDlg::OnPayoff() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_read.IsEmpty())
	{
	   MessageBox("借书证号不能为空");
	   return ;
	}
	CMainDlg *main=(CMainDlg *)this->GetParent();
	CString cs;
	long read_ID=atoi(m_read);
	cs.Format("update 读者信息表 set 是否欠费='否',超期天数=0,欠费金额=0 where 借书证号=%ld",read_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_book->SetRefDataSource(LPUNKNOWN(main->m_precordset));
    MessageBox("已交清欠款");
	cs="select * from 读者信息表 where 借书证号 like '%%"+m_read+"%%'";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	GetDlgItem(IDC_PAYOFF)->ShowWindow(false);
	m_money="0";
	m_overday=0;
	UpdateData(false);
}

BOOL CBorrowDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	/*CRect rect;
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
    dcMem.SelectObject(pOldBitmap);*/
	   
       //return true;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CBorrowDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CBorrowDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == 0x0D || pMsg->wParam == 0x1B))
	 {
      return false;
	 }
	return CDialog::PreTranslateMessage(pMsg);
}

void CBorrowDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	   //CDC *dc;
	   //dc=GetDC();
	   CRect rect;
	   GetWindowRect(rect);
	   ScreenToClient(rect);
	   CBitmap bitmap;
	   BITMAP bm;
	   bitmap.LoadBitmap(IDB_DLGBACK);
	   bitmap.GetBitmap(&bm);
	   CPen pen(PS_SOLID,1,RGB(0,255,0));
	   dc.SelectObject(&pen);
	   CBrush brush;
	   brush.CreatePatternBrush(&bitmap);
	   dc.SelectObject(&brush);
	   POINT point;
	   point.x=5;
	   point.y=5;
	   dc.RoundRect(rect,point);
	// Do not call CDialog::OnPaint() for painting messages
}
