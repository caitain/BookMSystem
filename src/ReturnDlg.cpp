// ReturnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "MainDlg.h"
#include "ReturnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturnDlg dialog

#include "MyEdit.h"
CReturnDlg::CReturnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReturnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturnDlg)
	m_book = _T("");
	//}}AFX_DATA_INIT
}


void CReturnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturnDlg)
	DDX_Control(pDX, IDC_EDIT1, m_ebook);
	DDX_Text(pDX, IDC_EDIT1, m_book);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturnDlg, CDialog)
	//{{AFX_MSG_MAP(CReturnDlg)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_RETURN_BOOK, OnReturnBook)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturnDlg message handlers

void CReturnDlg::OnChangeEdit1() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	/*UpdateData();
	CString cs;
	cs="select * from ͼ�������Ϣ where ͼ��ID like '%%"+m_book_ID+"%%'";
	CMainDlg *main=(CMainDlg *)this->GetParent();
	_variant_t sql;
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_book->SetRefDataSource(LPUNKNOWN(main->m_pconnection));*/
	UpdateData();
	CMainDlg *main=(CMainDlg *)this->GetParent();
	if(main->m_precordset!=NULL&&main->m_precordset->GetRecordCount()!=0)
		main->m_precordset->Move(0);
	CString cs;
	cs="select * from ͼ�������Ϣ where ͼ��ID like '%%"+m_book+"%%'";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	m_data_book->SetRefDataSource(LPUNKNOWN(main->m_precordset));
	
}

BOOL CReturnDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_data_book=(CDataGrid *)GetDlgItem(IDC_BOOK_DATA);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReturnDlg::OnReturnBook() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	long read_ID;
	if(m_book.IsEmpty())
	{
	   MessageBox("ͼ��ID����Ϊ��");
	   GetDlgItem(IDC_EDIT1)->SetFocus();
	   return ;
	}
	long book_ID=atoi(m_book);
    CString cs;
	cs.Format("select * from ͼ�������Ϣ where ͼ��ID=%ld and �Ƿ�ɽ�='��'",book_ID);
     	CMainDlg *main=(CMainDlg *)this->GetParent();
	_variant_t sql;
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	int icount=main->m_precordset->GetRecordCount();
	if(icount==0)
	{
		MessageBox("�޴�������δ�����,��˶�ͼ��ID�Ƿ���ȷ");
		return;
	}
	else
	{
	   read_ID=main->m_precordset->GetCollect("����֤��").lVal;
	}
	cs.Format("update ͼ�������Ϣ set ����֤��=NULL,�Ƿ�ɽ�='��',�黹����='%s' where ͼ��ID=%ld",main->m_time,book_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
    cs.Format("select * from ͼ�������Ϣ where ͼ��ID=%ld",book_ID);
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
    if(main->m_precordset->GetRecordCount()!=0)
	{
	     _variant_t data=main->m_precordset->GetCollect("�������");
		 CString time;
		 time=data.vt==VT_NULL?"":(_bstr_t)data;
		 long m_day=main->m_precordset->GetCollect("�ɽ�����").lVal;
		 float m_money=main->m_precordset->GetCollect("���ڷ���").fltVal;
         cs.Format("select * from ͼ�������Ϣ where ͼ��ID=%ld and DateDiff('d',�������,Date())>�ɽ�����",book_ID);
		 if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		       return ;
		 if(main->m_precordset->GetRecordCount()!=0)
		 {
			cs.Format("update ������Ϣ�� set �Ƿ�Ƿ��='��',��������=��������+DateDiff('d','%s',Date())-%d,\
				Ƿ�ѽ��=Ƿ�ѽ��+(DateDiff('d','%s',Date())-%d)*%lf where ����֤��=%ld",time,m_day,time,m_day,m_money,read_ID);
	        if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		       return ;
		 }
	}
	cs.Format("update ͼ�������Ϣ set �������=NULL,�黹����=Date() where ͼ��ID=%ld",book_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	MessageBox("����ɹ��黹");
	cs.Format("update ������Ϣ�� set �ѽ�ͼ����=�ѽ�ͼ����-1 where ����֤��=%ld",read_ID);
    if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
	cs="select * from ͼ�������Ϣ where ͼ��ID like '%%"+m_book+"%%'";
	if(!main->OnSQLexcute(main->m_precordset,_variant_t(cs)))
		return ;
}

BOOL CReturnDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
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
    dcMem.SelectObject(pOldBitmap);
   return true;
	return CDialog::OnEraseBkgnd(pDC);
}

HBRUSH CReturnDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CReturnDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == 0x0D || pMsg->wParam == 0x1B))
	 {
      return false;
	 }
	return CDialog::PreTranslateMessage(pMsg);
}
