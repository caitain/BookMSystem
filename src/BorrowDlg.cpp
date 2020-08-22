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
	   //MessageBox("����֤�Ų���Ϊ��");
	   GetDlgItem(IDC_EDIT1)->SetFocus();
	   return ;
	}
	if(m_book.IsEmpty())
	{
	   //MessageBox("ͼ��ID����Ϊ��");
		GetDlgItem(IDC_EDIT2)->SetFocus();
	   return ;
	}
	long read_ID=atoi(m_read);
	long book_ID=atoi(m_book);
    CString cs;
	//��ѯ���ߡ�ͼ���Ƿ���ڻ������Ƿ���ȷ
	cs.Format("select * from ������Ϣ��,ͼ�������Ϣ where ������Ϣ��.����֤��=%ld and \
		ͼ�������Ϣ.ͼ��ID=%ld",read_ID,book_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	if(main->m_precordset->GetRecordCount()==0)
	{
	   MessageBox("�����ڴ˶��߻����,���֤�����Ƿ���ȷ");
	   return ;
	}
	//��ѯ�����Ƿ�Ƿ��
	cs.Format("select * from ������Ϣ�� where ����֤��=%ld and ��������<>0",read_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	else 
	{
	    if(main->m_precordset->GetRecordCount()!=0)
		{
			m_overday=main->m_precordset->GetCollect("��������").lVal;
            _variant_t money=main->m_precordset->GetCollect("Ƿ�ѽ��");
			m_money=money.vt==VT_NULL?"":(_bstr_t)money;
			
			(CButton *)GetDlgItem(IDC_PAYOFF)->ShowWindow(true);
			MessageBox("�˶�����δ����Ƿ�ѣ�");
			//UpdateWindow();
			UpdateData(false);
			return ;
		}
	}
	cs.Format("select * from ������Ϣ�� where ����֤��=%ld",read_ID);
	_variant_t sql;
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	int i=main->m_precordset->GetCollect("�ѽ�ͼ����").lVal;
	int j=main->m_precordset->GetCollect("�ɽ�ͼ����").lVal;
	if(i>=j)
	{
		cs.Format("���Ѿ�����%ld�����ˣ������ٽ�",i);
		MessageBox(cs);
		return;
	}
	cs.Format("select * from ͼ�������Ϣ where ͼ��ID=%ld and �Ƿ�ɽ�='��'",book_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
    if(main->m_precordset->GetRecordCount()!=0)
	{
	    MessageBox("�����ѱ����");
		return ;
	}
	cs.Format("update ͼ�������Ϣ set ����֤��=%ld,�Ƿ�ɽ�='��',���Ĵ���=���Ĵ���+1,�������='%s',�黹����=NULL where ͼ��ID=%ld",read_ID,main->m_time,book_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("�ɹ����");
	cs.Format("update ������Ϣ�� set �ѽ�ͼ����=�ѽ�ͼ����+1 where ����֤��=%d",read_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	cs="select * from ͼ�������Ϣ where ͼ��ID like '%%"+m_book+"%%'";
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
	cs="select * from ������Ϣ�� where ����֤�� like '%%"+m_read+"%%'";
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
	cs="select * from ͼ�������Ϣ where ͼ��ID like '%%"+m_book+"%%'";
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
	   MessageBox("����֤�Ų���Ϊ��");
	   return ;
	}
	CMainDlg *main=(CMainDlg *)this->GetParent();
	CString cs;
	long read_ID=atoi(m_read);
	cs.Format("update ������Ϣ�� set �Ƿ�Ƿ��='��',��������=0,Ƿ�ѽ��=0 where ����֤��=%ld",read_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_book->SetRefDataSource(LPUNKNOWN(main->m_precordset));
    MessageBox("�ѽ���Ƿ��");
	cs="select * from ������Ϣ�� where ����֤�� like '%%"+m_read+"%%'";
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
    m_bitmap.GetBitmap(&bm);//�õ�λͼ�ߴ�
    dcMem.CreateCompatibleDC(pDC);
    CBitmap* pOldBitmap = dcMem.SelectObject(&m_bitmap);
    pDC->SetStretchBltMode(COLORONCOLOR);//���ģʽ�����õĻ��ᵼ��ͼƬ����ʧ��
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
		    pDC-> SetBkMode(TRANSPARENT);   //��̬�ؼ����ñ���͸�� 
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
