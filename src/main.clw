; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDataDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "main.h"

ClassCount=12
Class1=CMainApp
Class2=CMainDlg
Class3=CAboutDlg

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CMyButton
Resource3=IDD_MAIN_DIALOG
Class5=CLogoDlg
Class6=CLogoButton
Class7=CMyEdit
Resource4=IDD_REGISTER_DLG
Class8=CRegisterDlg
Resource5=IDD_LOGO_DIALOG
Class9=CBorrowDlg
Resource6=IDD_DATA
Class10=CReturnDlg
Resource7=IDD_BORROW_DLG
Class11=CDataDlg
Resource8=IDD_RETURN_DLG
Class12=CSetDlg
Resource9=IDD_SET_DLG

[CLS:CMainApp]
Type=0
HeaderFile=main.h
ImplementationFile=main.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMainDlg]
Type=0
HeaderFile=mainDlg.h
ImplementationFile=mainDlg.cpp
Filter=W
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_COMBO1

[CLS:CAboutDlg]
Type=0
HeaderFile=mainDlg.h
ImplementationFile=mainDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MAIN_DIALOG]
Type=1
Class=CMainDlg
ControlCount=33
Control1=IDC_TEXTPLACE,static,1342308352
Control2=IDC_TEXTUSER,static,1342308352
Control3=IDC_CANCEL,button,1342242816
Control4=IDC_INDEX,button,1342242816
Control5=IDC_SORT,button,1342242816
Control6=IDC_USE,button,1342242816
Control7=IDC_NEWSADD,button,1342242816
Control8=IDC_BORROW_BOOK,button,1342242816
Control9=IDC_RETURNBOOK,button,1342242816
Control10=IDC_READ,button,1342242816
Control11=IDC_STATIC,static,1342308352
Control12=IDC_QUERY_TEXT,edit,1350631552
Control13=IDC_QUERY_OK,button,1342242816
Control14=IDC_STATIC,static,1342308352
Control15=IDC_TIME,edit,1350631552
Control16=IDC_SELECT_COMB,combobox,1344339971
Control17=IDC_DATA,button,1342242816
Control18=IDC_MENEY,button,1342242816
Control19=IDC_LOOK_HAVE,button,1342242816
Control20=IDC_CHNIA,button,1342242816
Control21=IDC_CLASS,combobox,1344339971
Control22=IDC_STATIC,static,1342308352
Control23=IDC_BOOK_CLASS2,combobox,1344339971
Control24=IDC_STATIC,static,1342308352
Control25=IDC_SET,button,1342242816
Control26=IDC_MINIBOX,button,1342242816
Control27=IDC_CANCELBOX,button,1342242816
Control28=IDC_LOOK_HAVE2,button,1342242816
Control29=IDC_STATIC,static,1342308352
Control30=IDC_COMBO1,combobox,1344339971
Control31=IDC_RADIO1,button,1342177289
Control32=IDC_RADIO2,button,1342177289
Control33=IDC_CHNIA2,button,1342242816

[CLS:CMyButton]
Type=0
HeaderFile=MyButton.h
ImplementationFile=MyButton.cpp
BaseClass=CButton
Filter=W
LastObject=CMyButton
VirtualFilter=BWC

[DLG:IDD_LOGO_DIALOG]
Type=1
Class=CLogoDlg
ControlCount=10
Control1=IDC_LOGO,button,1342242816
Control2=IDC_RESET,button,1342242816
Control3=IDC_USENAME,edit,1350631552
Control4=IDC_PASSWORD,edit,1350631584
Control5=IDC_CHECK,edit,1350631552
Control6=IDC_RADIO1,button,1342177289
Control7=IDC_RADIO2,button,1342177289
Control8=IDC_LCANCEL,button,1342242816
Control9=IDC_MIN,button,1342242816
Control10=IDC_REGISTER,button,1342242816

[CLS:CLogoDlg]
Type=0
HeaderFile=LogoDlg.h
ImplementationFile=LogoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_REGISTER
VirtualFilter=dWC

[CLS:CLogoButton]
Type=0
HeaderFile=LogoButton.h
ImplementationFile=LogoButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

[CLS:CMyEdit]
Type=0
HeaderFile=MyEdit.h
ImplementationFile=MyEdit.cpp
BaseClass=CEdit
Filter=W
VirtualFilter=WC

[DLG:IDD_REGISTER_DLG]
Type=1
Class=CRegisterDlg
ControlCount=15
Control1=IDC_MYNAME,edit,1350631552
Control2=IDC_PASSWORD,edit,1350631584
Control3=IDC_PASSTWO,edit,1350631584
Control4=IDC_REGISTER,button,1342242817
Control5=IDC_RESET,button,1342242816
Control6=IDCANCEL,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_USENAME,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_COMBO1,combobox,1344339971

[CLS:CRegisterDlg]
Type=0
HeaderFile=RegisterDlg.h
ImplementationFile=RegisterDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRegisterDlg

[DLG:IDD_BORROW_DLG]
Type=1
Class=CBorrowDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_DATA_READ,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control7=IDC_DATA_BOOK,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT3,edit,1350633600
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT4,edit,1350633600
Control12=IDC_PAYOFF,button,1342242816
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[CLS:CBorrowDlg]
Type=0
HeaderFile=BorrowDlg.h
ImplementationFile=BorrowDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=CBorrowDlg
VirtualFilter=dWC

[DLG:IDD_RETURN_DLG]
Type=1
Class=CReturnDlg
ControlCount=5
Control1=IDC_RETURN_BOOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BOOK_DATA,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT1,edit,1350631552

[CLS:CReturnDlg]
Type=0
HeaderFile=ReturnDlg.h
ImplementationFile=ReturnDlg.cpp
BaseClass=CDialog
Filter=W
LastObject=CReturnDlg
VirtualFilter=dWC

[CLS:CDataDlg]
Type=0
HeaderFile=DataDlg.h
ImplementationFile=DataDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_USEID
VirtualFilter=dWC

[DLG:IDD_DATA]
Type=1
Class=CDataDlg
ControlCount=9
Control1=IDC_SAVE,button,1342242817
Control2=IDC_BOOK,button,1342242816
Control3=IDC_READ,button,1342242816
Control4=IDC_USE,button,1342242816
Control5=IDC_DATA_GRID,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control6=IDC_DELETE,button,1342242816
Control7=IDC_STATIC,static,1342308352
Control8=IDC_USEID,edit,1350631552
Control9=IDC_SERCH,button,1342242816

[DLG:IDD_SET_DLG]
Type=1
Class=CSetDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_COMBO1,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_COMBO2,combobox,1344339971
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_COMBO3,combobox,1344339971
Control11=IDC_STATIC,static,1342308352
Control12=IDC_DAY,button,1342242816
Control13=IDC_MONEY,button,1342242816
Control14=IDC_BUTTON3,button,1342242816

[CLS:CSetDlg]
Type=0
HeaderFile=SetDlg.h
ImplementationFile=SetDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_COMBO3
VirtualFilter=dWC

