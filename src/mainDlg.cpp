// mainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "mainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg dialog

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainDlg)
	m_textuser = _T("");
	m_query_text = _T("");
	m_time = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_MAIN);
	m_hcursor=AfxGetApp()->LoadCursor(IDC_NORMAL);
	m_sql_text="select * from ͼ�������Ϣ  where ���� like";
	m_bool_admin=false;
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainDlg)
	DDX_Control(pDX, IDC_COMBO1, m_sort_com);
	DDX_Control(pDX, IDC_MINIBOX, m_bmin);
	DDX_Control(pDX, IDC_CANCELBOX, m_bcancel);
	DDX_Control(pDX, IDC_BOOK_CLASS2, m_book_class2);
	DDX_Control(pDX, IDC_CLASS, m_book_class);
	DDX_Control(pDX, IDC_QUERY_OK, m_btnquery);
	DDX_Control(pDX, IDC_BORROW_BOOK, m_btnborrow);
	DDX_Control(pDX, IDC_READ, m_btnread);
	DDX_Control(pDX, IDC_RETURNBOOK, m_btnreturn);
	DDX_Control(pDX, IDC_SELECT_COMB, m_select_comb);
	DDX_Control(pDX, IDC_TIME, m_edit_time);
	DDX_Control(pDX, IDC_QUERY_TEXT, m_text);
	DDX_Control(pDX, IDC_NEWSADD, m_addnew);
	DDX_Control(pDX, IDC_TEXTPLACE, m_place);
	DDX_Control(pDX, IDC_USE, m_use);
	DDX_Control(pDX, IDC_SORT, m_sort);
	DDX_Control(pDX, IDC_INDEX, m_index);
	DDX_Control(pDX, IDC_CANCEL, m_ctcancel);
	DDX_Text(pDX, IDC_TEXTUSER, m_textuser);
	DDX_Text(pDX, IDC_QUERY_TEXT, m_query_text);
	DDX_Text(pDX, IDC_TIME, m_time);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMainDlg, CDialog)
	//{{AFX_MSG_MAP(CMainDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_BN_CLICKED(IDC_USE, OnUse)
	ON_BN_CLICKED(IDC_SORT, OnSort)
	ON_BN_CLICKED(IDC_NEWSADD, OnNewsadd)
	ON_BN_CLICKED(IDC_RETURNBOOK, OnReturnbook)
	ON_BN_CLICKED(IDC_BORROW_BOOK, OnBorrowBook)
	ON_BN_CLICKED(IDC_READ, OnRead)
	ON_BN_CLICKED(IDC_QUERY_OK, OnQueryOk)
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_EN_CHANGE(IDC_QUERY_TEXT, OnChangeQueryText)
	ON_BN_CLICKED(IDC_INDEX, OnIndex)
	ON_BN_CLICKED(IDC_DATA, OnData)
	ON_BN_CLICKED(IDC_MENEY, OnMeney)
	ON_BN_CLICKED(IDC_LOOK_HAVE, OnLookHave)
	ON_BN_CLICKED(IDC_CHNIA, OnChnia)
	ON_CBN_SELCHANGE(IDC_CLASS, OnSelchangeClass)
	ON_CBN_SELCHANGE(IDC_BOOK_CLASS2, OnSelchangeBookClass2)
	ON_BN_CLICKED(IDC_SET, OnSet)
	ON_BN_CLICKED(IDC_MINIBOX, OnMinibox)
	ON_BN_CLICKED(IDC_CANCELBOX, OnCancelbox)
	ON_BN_CLICKED(IDC_LOOK_HAVE2, OnLookHave2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_CHNIA2, OnChnia2)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDlg message handlers

BOOL CMainDlg::OnInitDialog()
{
	
	
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.
     CMainApp *main=(CMainApp *)AfxGetApp();
	if(main->m_flag)
		CDialog::EndDialog(IDCANCEL);
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//�����趨���ڵĴ�С��λ��,������
	this->SetWindowPos(NULL,200,100,1002,688,SWP_FRAMECHANGED);
	CRect rect;
	GetWindowRect(rect);
	ScreenToClient(rect);
	CRgn rgn;
	rgn.CreateRoundRectRgn(rect.left,rect.top,rect.right,rect.bottom,10,10);
	this->SetWindowRgn(rgn,true);
	//�趨ϵͳ�˵�
	ModifyStyle(0, WS_SYSMENU|WS_MINIMIZEBOX);
    SetWindowText("ͼ��ݹ���ϵͳ1.0");
	//������������ʾ�ı���������
	m_mtipctrl.Create(this);
    m_mtipctrl.AddTool(GetDlgItem(IDC_INDEX),"ͼ�����ҳ");
	m_mtipctrl.AddTool(GetDlgItem(IDC_SORT),"���߽������а�");
	m_mtipctrl.AddTool(GetDlgItem(IDC_NEWSADD),"������ӵ�ͼ��");
	m_mtipctrl.AddTool(GetDlgItem(IDC_RETURNBOOK),"����");
	m_mtipctrl.AddTool(GetDlgItem(IDC_BORROW_BOOK),"����");
	m_mtipctrl.AddTool(GetDlgItem(IDC_READ),"��ʾ������Ϣ");
	m_mtipctrl.AddTool(GetDlgItem(IDC_USE),"��ʾ�û���Ϣ");
	m_mtipctrl.AddTool(GetDlgItem(IDC_SELECT_COMB),"��ѡ���ѯ��ģʽ(Ĭ��Ϊģ������)");
	m_mtipctrl.AddTool(GetDlgItem(IDC_QUERY_TEXT),"�����ѯ�ַ�");
	m_mtipctrl.AddTool(GetDlgItem(IDC_QUERY_OK),"��ѯ��ǰ��");
    m_mtipctrl.AddTool(GetDlgItem(IDC_TIME),"��ǰ����");
	m_mtipctrl.AddTool(GetDlgItem(IDC_CANCEL),"�˳�ϵͳ");
	m_mtipctrl.SetDelayTime(500);
    m_mtipctrl.SetTipTextColor(RGB(0,0,255));
    m_mtipctrl.Activate(true);
    //�趨CDataGrid�ؼ�λ��

	POINT point;
	point.x=209;
	point.y=120;
	rect.left=point.x;
	rect.top=point.y+20;
	rect.right=rect.right-20;
	rect.bottom=rect.bottom-20;
	//�ؼ��Ķ�̬����,145������һ�����־��ǿؼ�����ʽ,��ʽ��Ψһ
	m_datagrid.Create("ͼ�������Ϣ",1451294720,rect,this,WM_USER+1);
    m_datagrid.SetBorderStyle(1);
	m_datagrid.SetAllowAddNew(false);
	m_datagrid.SetAllowDelete(false);
	m_datagrid.SetAllowUpdate(false);
	m_datagrid.SetBackColor(RGB(215,255,215));
	m_datagrid.SetRowHeight(20);
	m_datagrid.SetForeColor(RGB(0,0,255));
	//�������ݿ�
	try
	{
	    m_pconnection.CreateInstance(__uuidof(Connection));
		m_pconnection->Open("Driver={Microsoft Access Driver (*.mdb)};DBQ=ͼ��������ݿ�.mdb","","",adConnectUnspecified);
	
	}
	catch(_com_error &e)
	{
	     MessageBox(e.Description());
         CDialog::EndDialog(IDCANCEL);
		 return false;
	}
	catch(...)
	{
	    MessageBox("���ݿ����Ӵ���");
		CDialog::EndDialog(IDCANCEL);
	}
	try
	{
	   m_precordset.CreateInstance(__uuidof(Recordset));
	   m_precordset->Open(_variant_t("select * from ͼ�������Ϣ"),
		                m_pconnection.GetInterfacePtr(),
						adOpenStatic,adLockOptimistic,adCmdUnknown);
	}
	catch(_com_error &e)
	{
		MessageBox(e.Description());
		return false;
	}
	this->ShowData(m_precordset);
    //ȷ����ǰ�û���ݣ�
	if(!main->m_flag)
    {
	      m_textuser=main->m_oweruse;
		  if(main->m_oweruse=="��������Ա")
		  {
			  this->m_bool_admin=true;
		  }
		  else
		  {
		     this->UseShow();
			 this->m_main_useID=main->useID;
			 m_textuser.Format("%s ID:%ld",main->m_oweruse,main->useID);
		  }
	}
	//���õ�ǰϵͳ����
	CTime time;
	time=CTime::GetCurrentTime();
	m_time=time.Format("%Y-%m-%d");
	UpdateData(false);
	//��ʼ��������ѯ�б��
	m_select_comb.AddString("��ȷ��ѯ");
	m_select_comb.AddString("ģ����ѯ");
	m_select_comb.SetCurSel(2);
	//��ʼ������б��
	m_book_class.AddString("ȫ��");
	m_book_class.SetCurSel(0);
	m_book_class2.AddString("ȫ��");
	m_book_class2.SetCurSel(0);
	this->m_sort_com.SetCurSel(0);
	CheckDlgButton(IDC_RADIO1,BST_CHECKED);
	int icount=this->m_precordset->GetRecordCount();
	this->m_precordset->MoveFirst();
	CString cs;
	//��������
	for(int i=0;i<icount;i++)
	{
	    _variant_t str=m_precordset->GetCollect("�����");
		cs=str.vt==VT_NULL?"":(_bstr_t)str;
		if(m_book_class.FindStringExact(-1,cs)==CB_ERR)
			m_book_class.AddString(cs);
		str=m_precordset->GetCollect("�����");
		cs=str.vt==VT_NULL?"":(_bstr_t)str;
		if(m_book_class2.FindStringExact(-1,cs)==CB_ERR)
			m_book_class2.AddString(cs);
		this->m_precordset->MoveNext();
	}
	this->m_precordset->MoveFirst();
	//����λͼ��ť
    //�����ӶԻ���
	m_return_dlg.Create(IDD_RETURN_DLG,this);
	m_return_dlg.MoveWindow(rect,true);
	m_borrow_dlg.Create(IDD_BORROW_DLG,this);
	m_borrow_dlg.MoveWindow(rect,true);
	m_data_dlg.Create(IDD_DATA,this);
	m_data_dlg.MoveWindow(rect,true);
	m_set_dlg.Create(IDD_SET_DLG,this);
	m_set_dlg.MoveWindow(rect,true);
	//���ڻ���չ��,��������
	if(!main->m_flag)
	{
		ShowWindow(SW_HIDE);
		CRect m_rect;
		GetClientRect(&m_rect);
		CPoint Point;
		Point.x=m_rect.Width()/2;
		Point.y=m_rect.Height()/2;
		CRgn m_rgn;
		this->ShowWindow(SW_HIDE);  
		int m=GetSystemMetrics(SM_CYSIZEFRAME);
		for (i=10;i<m_rect.Width()/2+m;i+=1)
		{   
			m_rgn.CreateRoundRectRgn(Point.x-i,Point.y-i,Point.x+i,Point.y+i,10,10);
			SetWindowRgn((HRGN) m_rgn,TRUE);
			ShowWindow(SW_SHOW);
			CenterWindow();
			m_rgn.DeleteObject();
		}
		//�ٴε������ڣ�ʹ���ڱ�ΪԲ�Ǿ���
		CRect rrect;
		GetWindowRect(rrect);
		ScreenToClient(rrect);
		CRgn rrgn;
		rrgn.CreateRoundRectRgn(rrect.left,rrect.top,rrect.right,rrect.bottom,10,10);
		this->SetWindowRgn(rrgn,true);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMainDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMainDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMainDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	PostMessage(WM_NCLBUTTONDOWN,HTCAPTION,MAKELPARAM(point.x,point.y));
	CDialog::OnLButtonDown(nFlags, point);
}

BOOL CMainDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
    GetClientRect(&rect);
    CBitmap m_bitmap;
    BITMAP bm;
    CDC dcMem;
    m_bitmap.LoadBitmap(IDB_BACKGROUND);
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

HBRUSH CMainDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	 if(nCtlColor   ==   CTLCOLOR_STATIC)
       { 
		    pDC-> SetBkMode(TRANSPARENT);   //��̬�ؼ����ñ���͸�� 
            pDC->SetTextColor(RGB(0,0,255));
			return   HBRUSH(GetStockObject(HOLLOW_BRUSH)); 
       }   
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMainDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	 if(m_precordset->State==adStateOpen)
		 m_precordset->Close();
	m_precordset.Release();
	if(m_pconnection->State==adStateOpen)
		m_pconnection->Close();
	  m_pconnection.Release();
	CDialog::EndDialog(IDCANCEL);
}

BOOL CMainDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if((pMsg->message == WM_KEYDOWN) && (pMsg->wParam == 0x0D || pMsg->wParam == 0x1B))
	 {
      return false;
	 }
	 if(pMsg->message==WM_MOUSEMOVE)
    m_mtipctrl.RelayEvent(pMsg);
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CMainDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	::SetCursor(m_hcursor);
	return true;
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CMainDlg::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CDialog::PreSubclassWindow();
}

BOOL CMainDlg::OnSQLexcute(_RecordsetPtr &recor, _variant_t &sql)
{
       if(recor->State==adStateOpen)
		   recor->Close();
	   try
	   {
	       recor->Open(sql,
			           m_pconnection.GetInterfacePtr(),
					   adOpenStatic,adLockOptimistic,adCmdUnknown);
		   return true;
	   }
	   catch (_com_error &e)
	   {
	       MessageBox(e.Description());
		   return false;
	   }
}

void CMainDlg::OnUse() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
	m_datagrid.SetCaption("�û���Ϣ��");
	CString strsql;
	if(this->m_bool_admin)
	strsql="select * from �û���Ϣ";
	else
		strsql.Format("select * from �û���Ϣ where ����֤��=%ld",this->m_main_useID);
	if(!this->OnSQLexcute(m_precordset,(_variant_t)strsql))
		return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(m_precordset));
	m_datagrid.SetCaption("�û���Ϣ��");
	this->ShowData(m_precordset);
	m_datagrid.Refresh();
	UpdateData(false);
	UpdateData(true);
	this->m_sql_text="select * from �û���Ϣ where �û��� like ";
}

void CMainDlg::OnSort() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
		_variant_t strsql;
	strsql="select * from ͼ�������Ϣ  order by ���Ĵ��� desc";
	
	if(!this->OnSQLexcute(m_precordset,strsql))
		return ;
	m_datagrid.SetCaption("ͼ�������Ϣ");
	this->ShowData(m_precordset);
	m_datagrid.Refresh();
	UpdateData(false);
	UpdateData(true);
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::ShowData(_RecordsetPtr &record)
{
    //m_datagrid.UpdateData();
	m_datagrid.SetRefDataSource(LPUNKNOWN(record));
}

void CMainDlg::OnNewsadd() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
    m_datagrid.ShowWindow(SW_SHOW);
	m_datagrid.SetCaption("ͼ�������Ϣ");
	_variant_t sql;
	sql="select * from ͼ�������Ϣ";
	if(!this->OnSQLexcute(m_precordset,sql))
	{
	   return ;
	}
	int iCunt=m_precordset->GetRecordCount();
	if(iCunt>10)
	{
	   sql="select top 10 * from ͼ�������Ϣ order by ���ʱ�� desc";
	}
	else
	{
	    CString cs;
		cs.Format("select top %d * from ͼ�������Ϣ order by ���ʱ�� desc",iCunt);
		sql=(_variant_t)cs;
	}
	if(!this->OnSQLexcute(m_precordset,sql))
	{
	    return ;
	}
	this->ShowData(m_precordset);
		UpdateData(true);
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::OnReturnbook() 
{
	// TODO: Add your control notification handler code here
	m_datagrid.ShowWindow(false);
	this->HideDialog();
	m_return_dlg.ShowWindow(SW_SHOW);
}

void CMainDlg::OnBorrowBook() 
{
	// TODO: Add your control notification handler code here
	m_datagrid.ShowWindow(false);
	this->HideDialog();
	m_borrow_dlg.ShowWindow(SW_SHOW);
} 

void CMainDlg::OnRead() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
	m_datagrid.SetCaption("������Ϣ��");
	CString sql;
	if(this->m_bool_admin)
	   sql="select * from ������Ϣ��";
	else
		sql.Format("select * from ������Ϣ�� where ����֤��=%ld",this->m_main_useID);
	if(!this->OnSQLexcute(m_precordset,(_variant_t)sql))
	{
	   return ;
	}
	this->ShowData(m_precordset);
	UpdateData(true);
	this->m_sql_text="select * from ������Ϣ�� where ���� like ";
}
void CMainDlg::OnQueryOk() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
    UpdateData(true);
	if(m_query_text.IsEmpty())
	{
	    GetDlgItem(IDC_QUERY_TEXT)->SetFocus();
	   return ;
	}
	if(!this->m_bool_admin)
		if(m_datagrid.GetCaption()=="������Ϣ��"||m_datagrid.GetCaption()=="�û���Ϣ��")
			return ;
	CString temp;
	temp=m_datagrid.GetCaption();
	CString cs;
	cs=m_sql_text+"'%%"+m_query_text+"%%'";
	CString tempstr;
	m_select_comb.GetLBText(m_select_comb.GetCurSel(),tempstr);
	if(tempstr=="��ȷ��ѯ")
	{
	    if(m_datagrid.GetCaption()=="ͼ�������Ϣ")
		     cs.Format("select * from ͼ�������Ϣ where ͼ��ID=%ld",atoi(m_query_text));
		else if (m_datagrid.GetCaption()=="������Ϣ��"&&this->m_bool_admin)
             	cs.Format("select * from ������Ϣ�� where ����֤��=%ld",atoi(m_query_text));
	    else if(this->m_bool_admin)
				cs.Format("select * from �û���Ϣ where ����֤��=%ld",atoi(m_query_text));
	}
    if(!this->OnSQLexcute(m_precordset,(_variant_t)cs))
		return ;
	if(m_precordset->RecordCount!=0)
	{
	    this->ShowData(m_precordset);
	}
	else
    {
	    MessageBox("û�д˼�¼");
		return ;
	}
}

void CMainDlg::HideDialog()
{
    m_return_dlg.ShowWindow(SW_HIDE);
	m_borrow_dlg.ShowWindow(SW_HIDE);
	m_data_dlg.ShowWindow(SW_HIDE);
	m_set_dlg.ShowWindow(SW_HIDE);
}

void CMainDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	/*CTime time;
	time=CTime::GetCurrentTime();
	m_time=time.Format("%Y-%M-%d %H:%m:%S");
	UpdateData(false);*/
	CDialog::OnTimer(nIDEvent);
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	//SetTimer(1,100,NULL);
	return 0;
}

void CMainDlg::OnChangeQueryText() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	if(!this->m_bool_admin)
		if(m_datagrid.GetCaption()=="������Ϣ��"||m_datagrid.GetCaption()=="�û���Ϣ��")
			return ;
	CString cs;
	if(m_datagrid.GetCaption()=="ͼ�������Ϣ")
		    cs="select * from ͼ�������Ϣ where ���� like '%%"+m_query_text+"%%'";
		else if (m_datagrid.GetCaption()=="������Ϣ��")
            cs="select * from ������Ϣ�� where ���� like '%%"+m_query_text+"%%'";
	    else 
			cs="select * from �û���Ϣ where �û��� like '%%"+m_query_text+"%%'"; 
	CString tempstr;
	m_select_comb.GetLBText(m_select_comb.GetCurSel(),tempstr);
	if(tempstr=="��ȷ��ѯ")
	{
	    if(m_datagrid.GetCaption()=="ͼ�������Ϣ")
		    cs="select * from ͼ�������Ϣ where ͼ��ID like '%%"+m_query_text+"%%'";
		else if (m_datagrid.GetCaption()=="������Ϣ��")
            cs="select * from ������Ϣ�� where ����֤�� like '%%"+m_query_text+"%%'";
	    else 
			cs="select * from �û���Ϣ where ����֤�� like '%%"+m_query_text+"%%'"; 
		
	}
	if(!OnSQLexcute(m_precordset,_variant_t(cs)))
		return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(m_precordset));
}

void CMainDlg::OnIndex() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	CString cs;
	this->HideDialog();
	m_datagrid.SetCaption("ͼ�������Ϣ");
	m_datagrid.ShowWindow(true);
	cs="select * from ͼ�������Ϣ";
	if(!this->OnSQLexcute(m_precordset,_variant_t(cs)))
	return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(m_precordset));
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::OnData() 
{
	// TODO: Add your control notification handler code here
	this->HideDialog();
	m_datagrid.ShowWindow(false);
	m_data_dlg.ShowWindow(SW_SHOW);
	if(this->m_bool_admin)
	m_data_dlg.OnBook();
	else
		m_data_dlg.OnUse();
}

void CMainDlg::OnMeney() 
{
	// TODO: Add your control notification handler code here
	CString cs;
	cs="select * from ������Ϣ�� where �Ƿ�Ƿ��='��'";
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
	if(!this->OnSQLexcute(m_precordset,_variant_t(cs)))
		return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(this->m_precordset));
}

void CMainDlg::OnLookHave() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	CString cs;
	this->HideDialog();
	m_datagrid.SetCaption("ͼ�������Ϣ");
	m_datagrid.ShowWindow(true);
	cs="select * from ͼ�������Ϣ where �Ƿ�ɽ�='��'";
	if(!this->OnSQLexcute(m_precordset,_variant_t(cs)))
	return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(m_precordset));
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::OnChnia() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL, "open", "http://www.cnki.net",NULL, NULL, SW_MAXIMIZE );
}

void CMainDlg::OnSelchangeClass() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	CString cs,sql;
    m_book_class.GetLBText(m_book_class.GetCurSel(),cs);
    if(cs=="ȫ��")
	{
	   sql="select * from ͼ�������Ϣ";
	}
	else
		sql.Format("select * from ͼ�������Ϣ where �����='%s'",cs);
	if(!this->OnSQLexcute(this->m_precordset,_variant_t(sql)))
		return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(this->m_precordset));

}

void CMainDlg::OnSelchangeBookClass2() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	CString cs,sql;
    m_book_class2.GetLBText(m_book_class2.GetCurSel(),cs);
    if(cs=="ȫ��")
	{
	   sql="select * from ͼ�������Ϣ";
	}
	else
		sql.Format("select * from ͼ�������Ϣ where �����='%s'",cs);
	if(!this->OnSQLexcute(this->m_precordset,_variant_t(sql)))
		return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(this->m_precordset));
}

void CMainDlg::OnSet() 
{
	// TODO: Add your control notification handler code here
	this->HideDialog();
	m_datagrid.ShowWindow(SW_HIDE);
	m_set_dlg.ShowWindow(SW_SHOW);
}

void CMainDlg::UseShow()
{
      (CButton *)GetDlgItem(IDC_RETURNBOOK)->ShowWindow(false);
	  (CButton *)GetDlgItem(IDC_BORROW_BOOK)->ShowWindow(false);
	  (CButton *)GetDlgItem(IDC_MENEY)->ShowWindow(false);
	  (CButton *)GetDlgItem(IDC_SET)->ShowWindow(false);
}

void CMainDlg::OnMinibox() 
{
	// TODO: Add your control notification handler code here
		this->ShowWindow(SW_MINIMIZE);
}

void CMainDlg::OnCancelbox() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	 if(m_precordset->State==adStateOpen)
		 m_precordset->Close();
	m_precordset.Release();
	if(m_pconnection->State==adStateOpen)
		m_pconnection->Close();
	  m_pconnection.Release();
	CDialog::EndDialog(IDCANCEL);
}

void CMainDlg::OnLookHave2() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	CString cs;
	this->HideDialog();
	if(this->m_bool_admin)
	{
	   MessageBox("���Ƕ�����?");
	   return ;
	}
	m_datagrid.SetCaption("ͼ�������Ϣ");
	m_datagrid.ShowWindow(true);
	cs.Format("select * from ͼ�������Ϣ where ����֤��=%ld",this->m_main_useID);
	if(!this->OnSQLexcute(m_precordset,_variant_t(cs)))
	return ;
	m_datagrid.SetRefDataSource(LPUNKNOWN(m_precordset));
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
	CString strsql,cs;
    this->m_sort_com.GetLBText(this->m_sort_com.GetCurSel(),cs);
	if(cs=="������")
	strsql="select * from ͼ�������Ϣ  order by ���Ĵ���";
	else
    strsql="select * from ͼ�������Ϣ  order by ���ʱ��";
	if(!this->OnSQLexcute(m_precordset,(_variant_t)strsql))
		return ;
	m_datagrid.SetCaption("ͼ�������Ϣ");
	this->ShowData(m_precordset);
	m_datagrid.Refresh();
	UpdateData(false);
	UpdateData(true);
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
	CString strsql,cs;
    this->m_sort_com.GetLBText(this->m_sort_com.GetCurSel(),cs);
	if(cs=="������")
	strsql="select * from ͼ�������Ϣ  order by ���Ĵ��� desc";
	else
    strsql="select * from ͼ�������Ϣ  order by ���ʱ�� desc";
	if(!this->OnSQLexcute(m_precordset,(_variant_t)strsql))
		return ;
	m_datagrid.SetCaption("ͼ�������Ϣ");
	this->ShowData(m_precordset);
	m_datagrid.Refresh();
	UpdateData(false);
	UpdateData(true);
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}

void CMainDlg::OnChnia2() 
{
	// TODO: Add your control notification handler code here
	ShellExecute(NULL, "open", "http://192.168.10.100",NULL, NULL, SW_MAXIMIZE );
}

void CMainDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	if(m_precordset!=NULL&&m_precordset->GetRecordCount()!=0)
		m_precordset->Move(0);
	this->HideDialog();
	m_datagrid.ShowWindow(SW_SHOW);
	CString strsql,cs;
    this->m_sort_com.GetLBText(this->m_sort_com.GetCurSel(),cs);
	if(cs=="������")
	{
		if(this->IsDlgButtonChecked(IDC_RADIO1))
		    strsql="select * from ͼ�������Ϣ  order by ���Ĵ���";
		else 
			strsql="select * from ͼ�������Ϣ order by ���Ĵ��� desc";
	}
	else
	{
        if(this->IsDlgButtonChecked(IDC_RADIO2))
		   strsql="select * from ͼ�������Ϣ  order by ���ʱ�� desc";
         else
		   strsql="select * from ͼ�������Ϣ  order by ���ʱ��";
	}
	if(!this->OnSQLexcute(m_precordset,(_variant_t)strsql))
		return ;
	m_datagrid.SetCaption("ͼ�������Ϣ");
	this->ShowData(m_precordset);
	m_datagrid.Refresh();
	UpdateData(false);
	UpdateData(true);
	this->m_sql_text="select * from ͼ�������Ϣ where ���� like ";
}
