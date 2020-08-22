// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "main.h"
#include "RegisterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog


CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegisterDlg)
	m_usename = _T("");
	m_pass1 = _T("");
	m_pass2 = _T("");
	//}}AFX_DATA_INIT
}


void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegisterDlg)
	DDX_Control(pDX, IDC_PASSWORD, m_edpass2);
	DDX_Control(pDX, IDC_PASSTWO, m_edpass);
	DDX_Control(pDX, IDC_MYNAME, m_edname);
	DDX_Control(pDX, IDC_COMBO1, m_borrow_ID);
	DDX_Text(pDX, IDC_MYNAME, m_usename);
	DDX_Text(pDX, IDC_PASSWORD, m_pass1);
	DDX_Text(pDX, IDC_PASSTWO, m_pass2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisterDlg)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_REGISTER, OnRegister)
	ON_BN_CLICKED(IDC_RESET, OnReset)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg message handlers

HBRUSH CRegisterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
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

BOOL CRegisterDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	::CoInitialize(NULL);
	m_borrow_ID.AddString("-ѡ�����֤��-");
	m_borrow_ID.SetCurSel(0);
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
	try
	{
	   m_recordset.CreateInstance(__uuidof(Recordset));
	   //CString cs;
	   //cs="select * from �û���Ϣ where �û���="+m_usename;
	}
	catch(_com_error &e)
	{
		MessageBox(e.Description());
		return false;
	}
	_variant_t sql;
	   sql="select ����֤�� from ������Ϣ�� where �Ƿ�ע��ϵͳ='δע��'";
	   this->DoSQLexcute(m_recordset,sql);
	int iCount=m_recordset->GetRecordCount();
	if(iCount==0)
		return false;
	m_recordset->MoveFirst();
	for(int i=0;i<iCount;i++)
    {
	   bookID=m_recordset->GetCollect("����֤��").lVal;
	   CString cs;
	   cs.Format("%ld",bookID);
	   m_borrow_ID.AddString(cs);
	   m_recordset->MoveNext();
	 }
	//for(int i=0;i<iCount;i++)
	////�ر����ݿ�����
	if(m_recordset->State==adStateOpen)
	{
	 m_recordset->Close();
	 m_recordset.Release();
	}
	if(m_connection->State==adStateOpen)
	{
	  m_connection->Close();
	  m_connection.Release();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CRegisterDlg::OnRegister() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_borrow_ID.GetCurSel()==0)
	{
	    MessageBox("��ѡ��һ������֤��");
		return ;
	}
	this->m_usename.TrimLeft();
	this->m_usename.TrimRight();
	/////////���ݿ����
	if(m_usename.IsEmpty())
	{
	   MessageBox("�û�������Ϊ��");
	   return;
	}
	if(m_pass1!=m_pass2)
	{
	     MessageBox("������������벻һ��");
		 return ;
	}
	try
	{
     m_connection.CreateInstance(__uuidof(Connection));
	 m_connection->Open("Driver={Microsoft Access Driver (*.mdb)};DBQ=ͼ��������ݿ�.mdb","","",adConnectUnspecified);
	}
	catch(_com_error &e)
	{
	     MessageBox(e.Description());
		 return ;
	}
	try
	{
	   m_recordset.CreateInstance(__uuidof(Recordset));
	   //CString cs;
	   //cs="select * from �û���Ϣ where �û���="+m_usename;
	   
	}
	catch(_com_error &e)
	{
		MessageBox(e.Description());
		return ;
	}
	_variant_t SQL;
	 SQL="select * from �û���Ϣ where �û���='"+m_usename+"'";
	   this->DoSQLexcute(m_recordset,SQL);
	if(m_recordset->GetRecordCount()!=0)
	{
	     MessageBox("���û����Ѵ���");
		 return ;
	}
	////�ر����ݿ�����
	CString sql,cs;
	m_borrow_ID.GetLBText(m_borrow_ID.GetCurSel(),cs);
	sql.Format("insert into �û���Ϣ(�û���,����,����֤��) values('%s','%s','%s')",\
		         m_usename,m_pass1,cs);
     if(this->DoSQLexcute(m_recordset,_variant_t(sql)))
	 {
	      MessageBox("ע��ɹ�");
		  long ID=atoi(cs);
		  cs.Format("update ������Ϣ�� set �Ƿ�ע��ϵͳ='��ע��' where ����֤��=%ld",ID);
		  this->DoSQLexcute(m_recordset,_variant_t(cs));
	 }
	if(m_recordset->State==adStateOpen)
	{
	 m_recordset->Close();
	 m_recordset.Release();
	}
	if(m_connection->State==adStateOpen)
	{
	  m_connection->Close();
	  m_connection.Release();
	}
	this->OnCancel();
}

void CRegisterDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CoUninitialize();
	CDialog::OnCancel();
}

BOOL CRegisterDlg::DoSQLexcute(_RecordsetPtr &record, _variant_t sql)
{
    if(record->State==adStateOpen)
		   record->Close();
	   try
	   {
	       record->Open(sql,
			           m_connection.GetInterfacePtr(),
					   adOpenStatic,adLockOptimistic,adCmdUnknown);
		   return true;
	   }
	   catch (_com_error &e)
	   {
	       MessageBox(e.Description());
		   return false;
	   }
     return false;
}

void CRegisterDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	m_borrow_ID.SetCurSel(0);
	m_pass1.Empty();
	m_pass2.Empty();
	UpdateData(false);
}
