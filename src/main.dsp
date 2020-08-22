# Microsoft Developer Studio Project File - Name="main" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=main - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "main.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "main.mak" CFG="main - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "main - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "main - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "main - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "main - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../bin"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "main - Win32 Release"
# Name "main - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BorrowDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\column.cpp
# End Source File
# Begin Source File

SOURCE=.\columns.cpp
# End Source File
# Begin Source File

SOURCE=.\DataDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\datagrid.cpp
# End Source File
# Begin Source File

SOURCE=.\LogoButton.cpp
# End Source File
# Begin Source File

SOURCE=.\LogoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\main.rc
# End Source File
# Begin Source File

SOURCE=.\mainDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MyButton.cpp
# End Source File
# Begin Source File

SOURCE=.\MyEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\NewButton.cpp
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ReturnDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SetDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BorrowDlg.h
# End Source File
# Begin Source File

SOURCE=.\column.h
# End Source File
# Begin Source File

SOURCE=.\columns.h
# End Source File
# Begin Source File

SOURCE=.\DataDlg.h
# End Source File
# Begin Source File

SOURCE=.\datagrid.h
# End Source File
# Begin Source File

SOURCE=.\LogoButton.h
# End Source File
# Begin Source File

SOURCE=.\LogoDlg.h
# End Source File
# Begin Source File

SOURCE=.\main.h
# End Source File
# Begin Source File

SOURCE=.\mainDlg.h
# End Source File
# Begin Source File

SOURCE=.\MyButton.h
# End Source File
# Begin Source File

SOURCE=.\MyEdit.h
# End Source File
# Begin Source File

SOURCE=.\NewButton.h
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\ReturnDlg.h
# End Source File
# Begin Source File

SOURCE=.\SetDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\addnew.bmp
# End Source File
# Begin Source File

SOURCE=.\res\addnew1.bmp
# End Source File
# Begin Source File

SOURCE=".\res\AquaText Select.cur"
# End Source File
# Begin Source File

SOURCE=.\res\bg123.bmp
# End Source File
# Begin Source File

SOURCE=.\res\borrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\borrow1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\canc.bmp
# End Source File
# Begin Source File

SOURCE=.\res\canc1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\canc2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\canc3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CANCEL.bmp
# End Source File
# Begin Source File

SOURCE=.\res\CANCEL1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\dlg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\eeee.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Index.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Index1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Laugh.ico
# End Source File
# Begin Source File

SOURCE=.\res\logm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\logn.bmp
# End Source File
# Begin Source File

SOURCE=.\res\main.bmp
# End Source File
# Begin Source File

SOURCE=.\res\main.ico
# End Source File
# Begin Source File

SOURCE=.\res\main.rc2
# End Source File
# Begin Source File

SOURCE=.\res\main1111.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mainee.bmp
# End Source File
# Begin Source File

SOURCE=.\res\mm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Q1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\query.bmp
# End Source File
# Begin Source File

SOURCE=.\res\query1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Quit1.bmp
# End Source File
# Begin Source File

SOURCE=".\res\radix phantasma link select.cur"
# End Source File
# Begin Source File

SOURCE=".\res\radix phantasma normal select.cur"
# End Source File
# Begin Source File

SOURCE=.\res\read.bmp
# End Source File
# Begin Source File

SOURCE=.\res\read1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\REGIT.bmp
# End Source File
# Begin Source File

SOURCE=.\res\REGIT1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\return.bmp
# End Source File
# Begin Source File

SOURCE=.\res\return1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\RR.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sort.bmp
# End Source File
# Begin Source File

SOURCE=.\res\sort1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Study.ico
# End Source File
# Begin Source File

SOURCE=.\res\use.bmp
# End Source File
# Begin Source File

SOURCE=.\res\use1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\XX.bmp
# End Source File
# Begin Source File

SOURCE=".\res\关闭1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\最小化一.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\jump.wav
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# Begin Source File

SOURCE=.\res\revup1.wav
# End Source File
# End Target
# End Project
# Section main : {CDE57A50-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CColumns
# 	2:10:HeaderFile:columns.h
# 	2:8:ImplFile:columns.cpp
# End Section
# Section main : {CDE57A43-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:21:DefaultSinkHeaderFile:datagrid.h
# 	2:16:DefaultSinkClass:CDataGrid
# End Section
# Section main : {CDE57A4F-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CColumn
# 	2:10:HeaderFile:column.h
# 	2:8:ImplFile:column.cpp
# End Section
# Section main : {CDE57A41-8B86-11D0-B3C6-00A0C90AEA82}
# 	2:5:Class:CDataGrid
# 	2:10:HeaderFile:datagrid.h
# 	2:8:ImplFile:datagrid.cpp
# End Section
