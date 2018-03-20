# Microsoft Developer Studio Project File - Name="Creator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Creator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Creator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Creator.mak" CFG="Creator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Creator - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Creator - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Creator - Win32 Release"

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
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Creator - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /EHa /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Creator - Win32 Release"
# Name "Creator - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cccCreator.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageClass.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageItemAttribute.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageItemAttributes.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedItem.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedItems.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedList.cpp
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedLists.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CFlatListOnDisk.cpp"
# End Source File
# Begin Source File

SOURCE=.\ChildFrame.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CHoleListOnDisk.cpp"
# End Source File
# Begin Source File

SOURCE=.\CItemAttributeOnDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\CItemAttributesOnDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\CItemOnDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\Creator.cpp
# End Source File
# Begin Source File

SOURCE=.\hlp\Creator.hpj

!IF  "$(CFG)" == "Creator - Win32 Release"

# PROP Ignore_Default_Tool 1
USERDEP__CREAT="hlp\AfxCore.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Release
TargetName=Creator
InputPath=.\hlp\Creator.hpj
InputName=Creator

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Creator - Win32 Debug"

# PROP Ignore_Default_Tool 1
USERDEP__CREAT="hlp\AfxCore.rtf"	"hlp\$(TargetName).hm"	
# Begin Custom Build - Making help file...
OutDir=.\Debug
TargetName=Creator
InputPath=.\hlp\Creator.hpj
InputName=Creator

"$(OutDir)\$(InputName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	start /wait hcw /C /E /M "hlp\$(InputName).hpj" 
	if errorlevel 1 goto :Error 
	if not exist "hlp\$(InputName).hlp" goto :Error 
	copy "hlp\$(InputName).hlp" $(OutDir) 
	goto :done 
	:Error 
	echo hlp\$(InputName).hpj(1) : error: 
	type "hlp\$(InputName).log" 
	:done 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Creator.rc
# End Source File
# Begin Source File

SOURCE=.\CreatorApp.cpp
# End Source File
# Begin Source File

SOURCE=.\CreatorSourceFile.cpp
# End Source File
# Begin Source File

SOURCE=.\CRelatedItemOnDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\CRelatedItemsOnDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\CRelatedListOnDisk.cpp
# End Source File
# Begin Source File

SOURCE=.\CRelatedListsOnDisk.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CStackOnDisk.cpp"
# End Source File
# Begin Source File

SOURCE=.\FileFunctions.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\FlatListInMemory.cpp"
# End Source File
# Begin Source File

SOURCE=.\FriendGlobal.cpp
# End Source File
# Begin Source File

SOURCE=.\gccCreator.cpp
# End Source File
# Begin Source File

SOURCE=.\ggcCreator.cpp
# End Source File
# Begin Source File

SOURCE=.\gggCreator.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\HoleListInMemory.cpp"
# End Source File
# Begin Source File

SOURCE=.\MainFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\Parser.cpp
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\StackInMemory.cpp"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TreeControl.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cccCreator.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageClass.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageItemAttribute.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageItemAttributes.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedItem.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedItems.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedList.h
# End Source File
# Begin Source File

SOURCE=.\CDiskStorageRelatedLists.h
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CFlatListOnDisk.h"
# End Source File
# Begin Source File

SOURCE=.\ChildFrame.h
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CHoleListOnDisk.h"
# End Source File
# Begin Source File

SOURCE=.\CItemAttributeOnDisk.h
# End Source File
# Begin Source File

SOURCE=.\CItemAttributesOnDisk.h
# End Source File
# Begin Source File

SOURCE=.\CItemOnDisk.h
# End Source File
# Begin Source File

SOURCE=.\Creator.h
# End Source File
# Begin Source File

SOURCE=.\CreatorApp.h
# End Source File
# Begin Source File

SOURCE=.\CreatorSourceFile.h
# End Source File
# Begin Source File

SOURCE=.\CRelatedItemOnDisk.h
# End Source File
# Begin Source File

SOURCE=.\CRelatedItemsOnDisk.h
# End Source File
# Begin Source File

SOURCE=.\CRelatedListOnDisk.h
# End Source File
# Begin Source File

SOURCE=.\CRelatedListsOnDisk.h
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CStackOnDisk.h"
# End Source File
# Begin Source File

SOURCE=.\DeclareClasses.h
# End Source File
# Begin Source File

SOURCE=.\FileFunctions.h
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\FlatListInMemory.h"
# End Source File
# Begin Source File

SOURCE=.\FriendGlobal.h
# End Source File
# Begin Source File

SOURCE=.\gccCreator.h
# End Source File
# Begin Source File

SOURCE=.\ggcCreator.h
# End Source File
# Begin Source File

SOURCE=.\gggCreator.h
# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\HoleListInMemory.h"
# End Source File
# Begin Source File

SOURCE=.\MainFrame.h
# End Source File
# Begin Source File

SOURCE=.\Parser.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h

!IF  "$(CFG)" == "Creator - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=Creator
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Creator - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Making help include file...
TargetName=Creator
InputPath=.\Resource.h

"hlp\$(TargetName).hm" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	echo. >"hlp\$(TargetName).hm" 
	echo // Commands (ID_* and IDM_*) >>"hlp\$(TargetName).hm" 
	makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Prompts (IDP_*) >>"hlp\$(TargetName).hm" 
	makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Resources (IDR_*) >>"hlp\$(TargetName).hm" 
	makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Dialogs (IDD_*) >>"hlp\$(TargetName).hm" 
	makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\$(TargetName).hm" 
	echo. >>"hlp\$(TargetName).hm" 
	echo // Frame Controls (IDW_*) >>"hlp\$(TargetName).hm" 
	makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\$(TargetName).hm" 
	
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE="..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\StackInMemory.h"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TreeControl.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Creator.ico
# End Source File
# Begin Source File

SOURCE=.\res\Creator.rc2
# End Source File
# Begin Source File

SOURCE=..\..\Media\CreatorCodename.ico
# End Source File
# Begin Source File

SOURCE=.\res\CreatorDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\idr_navi.ico
# End Source File
# Begin Source File

SOURCE=.\res\idr_tree.ico
# End Source File
# Begin Source File

SOURCE=.\mdi.ico
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Group "Help Files"

# PROP Default_Filter "cnt;rtf"
# Begin Source File

SOURCE=.\hlp\AfxCore.rtf
# End Source File
# Begin Source File

SOURCE=.\hlp\AppExit.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Bullet.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Creator.cnt

!IF  "$(CFG)" == "Creator - Win32 Release"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Release
InputPath=.\hlp\Creator.cnt
InputName=Creator

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ELSEIF  "$(CFG)" == "Creator - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - Copying contents file...
OutDir=.\Debug
InputPath=.\hlp\Creator.cnt
InputName=Creator

"$(OutDir)\$(InputName).cnt" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	copy "hlp\$(InputName).cnt" $(OutDir)

# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw2.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurArw4.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\CurHelp.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCopy.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditCut.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditPast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\EditUndo.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileNew.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileOpen.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FilePrnt.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\FileSave.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpSBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\HlpTBar.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecFirst.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecLast.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecNext.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\RecPrev.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmax.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\ScMenu.bmp
# End Source File
# Begin Source File

SOURCE=.\hlp\Scmin.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
