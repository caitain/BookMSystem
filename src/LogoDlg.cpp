// LogoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "LogoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogoDlg dialog


CLogoDlg::CLogoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLogoDlg)
	m_check = _T("");
	m_password = _T("");
	m_usename = _T("");
	//}}AFX_DATA_INIT
    m_logo_succeed=false;
}


void CLogoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogoDlg)
	DDX_Control(pDX, IDC_REGISTER, m_register);
	DDX_Control(pDX, IDC_LCANCEL, m_quit);
	DDX_Control(pDX, IDC_MIN, m_min);
	DDX_Control(pDX, IDC_CHECK, m_Echeck);
	DDX_Control(pDX, IDC_PASSWORD, m_Epass);
	DDX_Control(pDX, IDC_USENAME, m_Euse);
	DDX_Control(pDX, IDC_RESET, m_reset);
	DDX_Control(pDX, IDC_LOGO, m_logo);
	DDX_Text(pDX, IDC_CHECK, m_check);
	DDX_Text(pDX, IDC_PASSWORD, m_password);
	DDX_Text(pDX, IDC_USENAME, m_usename);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLogoDlg, CDialog)
	//{{AFX_MSG_MAP(CLogoDlg)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LOGO, OnLogo)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	ON_BN_CLICKED(IDC_MIN, OnMin)
	ON_BN_CLICKED(IDC_LCANCEL, OnLcancel)
	ON_BN_CLICKED(IDC_REGISTER, OnRegister)
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogoDlg message handlers
WNDPROC otherProc;
LRESULT  CALLBACK wndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
    if(msg==WM_CHAR && wParam==0x0d)
	{
		
		SetFocus(::GetNextDlgTabItem(::GetParent(hwnd),hwnd,FALSE));
		return 1;
	}
	if(msg==WM_CHAR && wParam==0x09)
	{
		
		SetFocus(::GetNextDlgTabItem(::GetParent(hwnd),hwnd,FALSE));
		return 1;
	}
	else
	{
		return otherProc(hwnd,msg,wParam,lParam);
	}
}
BOOL CLogoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	this->SetWindowPos(NULL,300,150,480,311,SWP_FRAMECHANGED);
	CRect rect;
	GetWindowRect(rect);
	ScreenToClient(rect);
	CRgn rgn;
	rgn.CreateRoundRectRgn(rect.left,rect.top,rect.right,rect.bottom,10,10);
	this->SetWindowRgn(rgn,true);
	//�趨ϵͳ�˵�
	ModifyStyle(0, WS_SYSMENU|WS_MINIMIZEBOX);
    SetWindowText("ͼ��ݹ���ϵͳ1.0");
	//��������ʾ�ı�
   otherProc=(WNDPROC)SetWindowLong(GetDlgItem(IDC_USENAME)->m_hWnd,GWL_WNDPROC,
		(LONG)wndProc);
   CheckDlgButton(IDC_RADIO1,BST_CHECKED);
   m_tipctrl.Create(this);
   m_tipctrl.AddTool(GetDlgItem(IDC_USENAME),"�����û���");
   m_tipctrl.AddTool(GetDlgItem(IDC_PASSWORD),"��������");
   m_tipctrl.AddTool(GetDlgItem(IDC_LOGO),"����");
   m_tipctrl.AddTool(GetDlgItem(IDC_RESET),"����");
    m_tipctrl.AddTool(GetDlgItem(IDC_CHECK),"�����ִ�Сд");
   //m_tipctrl.AddTool(GetDlgItem(IDC_MIN),"��С��");
   //m_tipctrl.AddTool(GetDlgItem(IDC_CANCEL),"�ر�");
   m_tipctrl.SetDelayTime(1000);
  // m_tipctrl.SetTipBkColor(RGB(0,255,255));
   m_tipctrl.SetTipTextColor(RGB(0,0,255));
   m_tipctrl.Activate(true);
   
   //����COM���ݻ���
   CoInitialize(NULL);
   try
	{
     m_connection.CreateInstance(__uuidof(Connection));
	 m_connection->Open("Driver={Microsoft Access Driver (*.mdb)};DBQ=ͼ��������ݿ�.mdb","","",adConnectUnspecified);
	}
	catch(_com_error &e)
	{
	     MessageBox(e.Description());
		 return false;
	}
	catch(...)
	{
	    MessageBox("���ݿ�����ʧ��");
		 m_logo_succeed=false;
		 CDialog::EndDialog(IDCANCEL);
	}
	try
	{
	   m_recordset.CreateInstance(__uuidof(Recordset));
	   
	}
	catch(_com_error &e)
	{
		MessageBox(e.Description());
		return false;
	}
   return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CLogoDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
    GetClientRect(&rect);
	CBitmap m_bitmap;
    BITMAP bm;
    CDC dcMem;
    m_bitmap.LoadBitmap(IDB_BACKLOGO);
    m_bitmap.GetBitmap(&bm);
    dcMem.CreateCompatibleDC(pDC);
    CBitmap* pOldBitmap = dcMem.SelectObject(&m_bitmap);
    pDC->SetStretchBltMode(COLORONCOLOR);
    pDC->StretchBlt(0,0,rect.Width() ,rect.Height(),
    &dcMem,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
    dcMem.SelectObject(pOldBitmap);

	CRgn rgn;
	 rgn.CreateRoundRectRgn(rect.left,rect.top+2,rect.right+1,rect.bottom,10,10);
	 this->SetWindowRgn(rgn,true);
	return true;
	return CDialog::OnEraseBkgnd(pDC);
}
void CLogoDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	this->PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,point.y));
	CDialog::OnLButtonDown(nFlags, point);
}

void CLogoDlg::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

HBRUSH CLogoDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	 if(nCtlColor   ==   CTLCOLOR_STATIC) 
       { 
            
		    pDC-> SetBkMode(TRANSPARENT);   //���ñ���͸�� 
            pDC->SetTextColor(RGB(0,0,255));
			return   HBRUSH(GetStockObject(HOLLOW_BRUSH)); 
       }   
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CLogoDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == 0x0D || pMsg->wParam == 0x1B))
	 {
      return false;
	 }
	 if(pMsg->message==WM_MOUSEMOVE)
    m_tipctrl.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

void CLogoDlg::OnLogo() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_usename.TrimLeft();
	m_usename.TrimRight();
	m_check.TrimRight();
	m_check.TrimLeft();
	if(m_usename.IsEmpty())
	{
	   MessageBox("�û�������Ϊ��");
	   GetDlgItem(IDC_USENAME)->SetFocus();
	   return ;
	}
	if(m_password.IsEmpty())
	{
	   MessageBox("���벻��Ϊ��");
	   GetDlgItem(IDC_PASSWORD)->SetFocus();
	   return ;
	}
	CString sQL;
	sQL.Format("select * from �û���Ϣ where �û���='%s' and ����='%s'",m_usename,m_password);
	if(!this->OnSQLexcute(m_recordset,_variant_t(sQL)))
	{
	    return ;
	}
	char *str;
	 str=m_check.GetBuffer(5);
	if(!(strcmp("tysi",strlwr(str))==0))
	{ 
		 MessageBox("��֤�����");
		 return ;
	}
	if(m_recordset->GetRecordCount()==0)
	{
		 MessageBox("�������","������ʾ");
		 m_check.Empty();
		 OnReset();
		 return ;
	}
	
    else
	{
	   CString use,pass;
	    _variant_t temp1,temp2;
	   temp1=m_recordset->GetCollect("�û���");
	   use.Empty();
       use=temp1.vt==VT_NULL?"":(_bstr_t)temp1;
	   if(m_usename!=use)
	   {
	       MessageBox("�û�������");
		   GetDlgItem(IDC_USENAME)->SetFocus();
		   m_usename.Empty();
		   this->OnReset();
		   return ;
	   }
       temp2=m_recordset->GetCollect("����");
	   pass.Empty();
       pass=temp2.vt==VT_NULL?"":(_bstr_t)temp2;
	   if(m_password!=pass)
	   {
	       MessageBox("�������");
		   GetDlgItem(IDC_PASSWORD)->SetFocus();
		   this->OnReset();
		   return ;
	   }
	   this->m_logo_succeed=true;
	}
	_variant_t strvar;
	strvar=m_recordset->GetCollect("���");
	m_usename=strvar.vt==VT_NULL?"":(_bstr_t)strvar;
	if(m_usename!="����Ա")
    {
	strvar=m_recordset->GetCollect("����֤��");
    long num=strvar.lVal;
	CString cs;
     cs.Format("select * from ������Ϣ�� where ����֤��=%ld",num);
	if(!this->OnSQLexcute(m_recordset,_variant_t(cs)))
	{
	   return ;      
	}
	if(m_recordset->GetRecordCount==0)
	{
	    MessageBox("�����ڴ˶���");
		return;
	}
	strvar=m_recordset->GetCollect("����");
	m_usename=strvar.vt==VT_NULL?"":(_bstr_t)strvar;
	this->m_useID=m_recordset->GetCollect("����֤��").lVal;
	}
	else 
		m_usename="��������Ա";
	if(m_recordset->State==adStateOpen)
		 m_recordset->Close();
	     m_recordset.Release();
	if(m_connection->State==adStateOpen)
		m_connection->Close();
	    m_connection.Release();
	CDialog::EndDialog(IDCANCEL);
}

void CLogoDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	m_password.Empty();

	UpdateData(false);
    GetDlgItem(IDC_USENAME)->SetFocus();
	UpdateWindow();
	
}

void CLogoDlg::OnMin() 
{
	// TODO: Add your control notification handler code here
	this->ShowWindow(SW_MINIMIZE);
}


void CLogoDlg::OnLcancel() 
{
	// TODO: Add your control notification handler code here
	this->m_logo_succeed=false;
	if(m_recordset->State==adStateOpen)
		 m_recordset->Close();
	m_recordset.Release();
	if(m_connection->State==adStateOpen)
		m_connection->Close();
	  m_connection.Release();
	CDialog::EndDialog(IDCANCEL);
}

void CLogoDlg::OnRegister() 
{
	// TODO: Add your control notification handler code here
	 CRegisterDlg dlg;
	 dlg.DoModal();	 
}

BOOL CLogoDlg::OnSQLexcute(_RecordsetPtr &recor, _variant_t &sql)
{
    if(recor->State==adStateOpen)
		   recor->Close();
	   try
	   {
	       recor->Open(sql,
			           m_connection.GetInterfacePtr(),
					   adOpenStatic,adLockOptimistic,adCmdUnknown);
		   return true;
	   }
	   catch (_com_error &e)
	   {
	       MessageBox(e.Description());
		   return false;
	   }
}

BOOL CLogoDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(AfxGetApp()->LoadCursor(IDC_NORMAL));
	return true;
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}
