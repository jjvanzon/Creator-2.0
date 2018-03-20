# Microsoft Developer Studio Generated NMAKE File, Based on CreatorRelatedItemMethodDll.dsp
!IF "$(CFG)" == ""
CFG=CreatorRelatedItemMethodDll - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CreatorRelatedItemMethodDll - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CreatorRelatedItemMethodDll - Win32 Release" && "$(CFG)" != "CreatorRelatedItemMethodDll - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CreatorRelatedItemMethodDll.mak" CFG="CreatorRelatedItemMethodDll - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CreatorRelatedItemMethodDll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CreatorRelatedItemMethodDll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "CreatorRelatedItemMethodDll - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CreatorRelatedItemMethodDll.dll"


CLEAN :
	-@erase "$(INTDIR)\cccCreator.obj"
	-@erase "$(INTDIR)\CreatorRelatedItemMethodDll.obj"
	-@erase "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	-@erase "$(INTDIR)\CreatorRelatedItemMethodDll.res"
	-@erase "$(INTDIR)\FileFunctions.obj"
	-@erase "$(INTDIR)\FlatListInMemory.obj"
	-@erase "$(INTDIR)\FriendGlobal.obj"
	-@erase "$(INTDIR)\HoleListInMemory.obj"
	-@erase "$(INTDIR)\StackInMemory.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.dll"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.exp"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CreatorRelatedItemMethodDll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CreatorRelatedItemMethodDll.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CreatorRelatedItemMethodDll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\CreatorRelatedItemMethodDll.pdb" /machine:I386 /def:".\CreatorRelatedItemMethodDll.def" /out:"$(OUTDIR)\CreatorRelatedItemMethodDll.dll" /implib:"$(OUTDIR)\CreatorRelatedItemMethodDll.lib" 
DEF_FILE= \
	".\CreatorRelatedItemMethodDll.def"
LINK32_OBJS= \
	"$(INTDIR)\cccCreator.obj" \
	"$(INTDIR)\CreatorRelatedItemMethodDll.obj" \
	"$(INTDIR)\FileFunctions.obj" \
	"$(INTDIR)\FlatListInMemory.obj" \
	"$(INTDIR)\FriendGlobal.obj" \
	"$(INTDIR)\HoleListInMemory.obj" \
	"$(INTDIR)\StackInMemory.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CreatorRelatedItemMethodDll.res"

"$(OUTDIR)\CreatorRelatedItemMethodDll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CreatorRelatedItemMethodDll - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CreatorRelatedItemMethodDll.dll"


CLEAN :
	-@erase "$(INTDIR)\cccCreator.obj"
	-@erase "$(INTDIR)\CreatorRelatedItemMethodDll.obj"
	-@erase "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	-@erase "$(INTDIR)\CreatorRelatedItemMethodDll.res"
	-@erase "$(INTDIR)\FileFunctions.obj"
	-@erase "$(INTDIR)\FlatListInMemory.obj"
	-@erase "$(INTDIR)\FriendGlobal.obj"
	-@erase "$(INTDIR)\HoleListInMemory.obj"
	-@erase "$(INTDIR)\StackInMemory.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.dll"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.exp"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.ilk"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.lib"
	-@erase "$(OUTDIR)\CreatorRelatedItemMethodDll.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CreatorRelatedItemMethodDll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CreatorRelatedItemMethodDll.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CreatorRelatedItemMethodDll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\CreatorRelatedItemMethodDll.pdb" /debug /machine:I386 /def:".\CreatorRelatedItemMethodDll.def" /out:"$(OUTDIR)\CreatorRelatedItemMethodDll.dll" /implib:"$(OUTDIR)\CreatorRelatedItemMethodDll.lib" /pdbtype:sept 
DEF_FILE= \
	".\CreatorRelatedItemMethodDll.def"
LINK32_OBJS= \
	"$(INTDIR)\cccCreator.obj" \
	"$(INTDIR)\CreatorRelatedItemMethodDll.obj" \
	"$(INTDIR)\FileFunctions.obj" \
	"$(INTDIR)\FlatListInMemory.obj" \
	"$(INTDIR)\FriendGlobal.obj" \
	"$(INTDIR)\HoleListInMemory.obj" \
	"$(INTDIR)\StackInMemory.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CreatorRelatedItemMethodDll.res"

"$(OUTDIR)\CreatorRelatedItemMethodDll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CreatorRelatedItemMethodDll.dep")
!INCLUDE "CreatorRelatedItemMethodDll.dep"
!ELSE 
!MESSAGE Warning: cannot find "CreatorRelatedItemMethodDll.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CreatorRelatedItemMethodDll - Win32 Release" || "$(CFG)" == "CreatorRelatedItemMethodDll - Win32 Debug"
SOURCE=..\..\Creator\cccCreator.cpp

"$(INTDIR)\cccCreator.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\CreatorRelatedItemMethodDll.cpp

"$(INTDIR)\CreatorRelatedItemMethodDll.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"


SOURCE=.\CreatorRelatedItemMethodDll.rc

"$(INTDIR)\CreatorRelatedItemMethodDll.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=..\..\Creator\FileFunctions.cpp

"$(INTDIR)\FileFunctions.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\..\..\Storage\Basic Data Structures\XXXX-XX-XX XX\FlatListInMemory.cpp"

"$(INTDIR)\FlatListInMemory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=..\FriendGlobal.cpp

"$(INTDIR)\FriendGlobal.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\..\..\Storage\Basic Data Structures\XXXX-XX-XX XX\HoleListInMemory.cpp"

"$(INTDIR)\HoleListInMemory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE="..\..\..\..\..\..\Storage\Basic Data Structures\XXXX-XX-XX XX\StackInMemory.cpp"

"$(INTDIR)\StackInMemory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorRelatedItemMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CreatorRelatedItemMethodDll - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CreatorRelatedItemMethodDll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CreatorRelatedItemMethodDll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CreatorRelatedItemMethodDll - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CreatorRelatedItemMethodDll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CreatorRelatedItemMethodDll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

