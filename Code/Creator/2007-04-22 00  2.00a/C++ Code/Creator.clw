; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=MainFrame
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Creator.h"
LastPage=0

ClassCount=10
Class1=CreatorApp
Class2=CreatorDoc
Class3=CreatorView
Class4=MainFrame

ResourceCount=5
Resource1=IDR_CREATOTYPE
Resource2=IDD_ABOUTBOX
Class5=ChildFrame
Class6=CAboutDlg
Class7=CMainForm
Resource3=IDR_MAINFRAME
Class8=CCreatorSourceFile
Resource4=IDR_CREATORSOURCEFILE_TMPL
Class9=CCreatorSourceFileDoc
Class10=NavigateData
Resource5=IDD_CREATORSOURCEFILE_FORM

[CLS:CreatorApp]
Type=0
HeaderFile=Creator.h
ImplementationFile=Creator.cpp
Filter=N

[CLS:CreatorDoc]
Type=0
HeaderFile=CreatorDoc.h
ImplementationFile=CreatorDoc.cpp
Filter=N

[CLS:CreatorView]
Type=0
HeaderFile=CreatorView.h
ImplementationFile=CreatorView.cpp
Filter=C


[CLS:MainFrame]
Type=0
HeaderFile=MainFrame.h
ImplementationFile=MainFrame.cpp
Filter=T
LastObject=ID_EDIT_COPY


[CLS:ChildFrame]
Type=0
HeaderFile=ChildFrame.h
ImplementationFile=ChildFrame.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=Creator.cpp
ImplementationFile=Creator.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=MainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_MRU_FILE1
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_HELP_FINDER
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=MainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[MNU:IDR_CREATOTYPE]
Type=1
Class=CreatorView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_MRU_FILE1
Command7=ID_APP_EXIT
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=ID_WINDOW_NEW
Command15=ID_WINDOW_CASCADE
Command16=ID_WINDOW_TILE_HORZ
Command17=ID_WINDOW_ARRANGE
Command18=ID_HELP_FINDER
Command19=ID_APP_ABOUT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=MainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
Command14=ID_CONTEXT_HELP
Command15=ID_HELP
CommandCount=15

[CLS:CMainForm]
Type=0
HeaderFile=MainForm.h
ImplementationFile=MainForm.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDOK

[DLG:IDD_CREATORSOURCEFILE_FORM]
Type=1
Class=CCreatorSourceFile
ControlCount=5
Control1=IDC_TEXTBOX,edit,1353781444
Control2=IDC_PARSEBUTTON,button,1342242816
Control3=IDC_REPLACECREATORBUTTON,button,1342242816
Control4=IDC_SHOWMESSAGESBUTTON,button,1342242816
Control5=IDC_NOMESSAGESBUTTON,button,1342242816

[CLS:CCreatorSourceFile]
Type=0
HeaderFile=CreatorSourceFile.h
ImplementationFile=CreatorSourceFile.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=IDC_EDIT1

[MNU:IDR_CREATORSOURCEFILE_TMPL]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
CommandCount=21

[CLS:CCreatorSourceFileDoc]
Type=0
HeaderFile=CreatorSourceFile.h
ImplementationFile=CreatorSourceFile.cpp
BaseClass=CDocument
Filter=N
VirtualFilter=DC

[CLS:NavigateData]
Type=0
HeaderFile=NavigateData.h
ImplementationFile=NavigateData.cpp
BaseClass=CFormView
Filter=D

