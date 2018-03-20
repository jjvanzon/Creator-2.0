# Microsoft Developer Studio Generated NMAKE File, Based on CreatorAttributeMethodDll.dsp
!IF "$(CFG)" == ""
CFG=CreatorAttributeMethodDll - Win32 Debug
!MESSAGE No configuration specified. Defaulting to CreatorAttributeMethodDll - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "CreatorAttributeMethodDll - Win32 Release" && "$(CFG)" != "CreatorAttributeMethodDll - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CreatorAttributeMethodDll.mak" CFG="CreatorAttributeMethodDll - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CreatorAttributeMethodDll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CreatorAttributeMethodDll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\CreatorAttributeMethodDll.dll"


CLEAN :
	-@erase "$(INTDIR)\cccCreator.obj"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.obj"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.pch"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.res"
	-@erase "$(INTDIR)\FileFunctions.obj"
	-@erase "$(INTDIR)\FlatListInMemory.obj"
	-@erase "$(INTDIR)\FriendGlobal.obj"
	-@erase "$(INTDIR)\HoleListInMemory.obj"
	-@erase "$(INTDIR)\StackInMemory.obj"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.dll"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.exp"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.lib"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CreatorAttributeMethodDll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CreatorAttributeMethodDll.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CreatorAttributeMethodDll.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:no /pdb:"$(OUTDIR)\CreatorAttributeMethodDll.pdb" /machine:I386 /def:".\CreatorAttributeMethodDll.def" /out:"$(OUTDIR)\CreatorAttributeMethodDll.dll" /implib:"$(OUTDIR)\CreatorAttributeMethodDll.lib" 
DEF_FILE= \
	".\CreatorAttributeMethodDll.def"
LINK32_OBJS= \
	"$(INTDIR)\cccCreator.obj" \
	"$(INTDIR)\CreatorAttributeMethodDll.obj" \
	"$(INTDIR)\FileFunctions.obj" \
	"$(INTDIR)\FlatListInMemory.obj" \
	"$(INTDIR)\FriendGlobal.obj" \
	"$(INTDIR)\HoleListInMemory.obj" \
	"$(INTDIR)\StackInMemory.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CreatorAttributeMethodDll.res"

"$(OUTDIR)\CreatorAttributeMethodDll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\CreatorAttributeMethodDll.dll" "$(OUTDIR)\CreatorAttributeMethodDll.bsc"


CLEAN :
	-@erase "$(INTDIR)\cccCreator.obj"
	-@erase "$(INTDIR)\cccCreator.sbr"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.obj"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.pch"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.res"
	-@erase "$(INTDIR)\CreatorAttributeMethodDll.sbr"
	-@erase "$(INTDIR)\FileFunctions.obj"
	-@erase "$(INTDIR)\FileFunctions.sbr"
	-@erase "$(INTDIR)\FlatListInMemory.obj"
	-@erase "$(INTDIR)\FlatListInMemory.sbr"
	-@erase "$(INTDIR)\FriendGlobal.obj"
	-@erase "$(INTDIR)\FriendGlobal.sbr"
	-@erase "$(INTDIR)\HoleListInMemory.obj"
	-@erase "$(INTDIR)\HoleListInMemory.sbr"
	-@erase "$(INTDIR)\StackInMemory.obj"
	-@erase "$(INTDIR)\StackInMemory.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.bsc"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.dll"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.exp"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.ilk"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.lib"
	-@erase "$(OUTDIR)\CreatorAttributeMethodDll.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CreatorAttributeMethodDll.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\CreatorAttributeMethodDll.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\CreatorAttributeMethodDll.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\cccCreator.sbr" \
	"$(INTDIR)\CreatorAttributeMethodDll.sbr" \
	"$(INTDIR)\FileFunctions.sbr" \
	"$(INTDIR)\FlatListInMemory.sbr" \
	"$(INTDIR)\FriendGlobal.sbr" \
	"$(INTDIR)\HoleListInMemory.sbr" \
	"$(INTDIR)\StackInMemory.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\CreatorAttributeMethodDll.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /dll /incremental:yes /pdb:"$(OUTDIR)\CreatorAttributeMethodDll.pdb" /debug /machine:I386 /def:".\CreatorAttributeMethodDll.def" /out:"$(OUTDIR)\CreatorAttributeMethodDll.dll" /implib:"$(OUTDIR)\CreatorAttributeMethodDll.lib" /pdbtype:sept 
DEF_FILE= \
	".\CreatorAttributeMethodDll.def"
LINK32_OBJS= \
	"$(INTDIR)\cccCreator.obj" \
	"$(INTDIR)\CreatorAttributeMethodDll.obj" \
	"$(INTDIR)\FileFunctions.obj" \
	"$(INTDIR)\FlatListInMemory.obj" \
	"$(INTDIR)\FriendGlobal.obj" \
	"$(INTDIR)\HoleListInMemory.obj" \
	"$(INTDIR)\StackInMemory.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\CreatorAttributeMethodDll.res"

"$(OUTDIR)\CreatorAttributeMethodDll.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("CreatorAttributeMethodDll.dep")
!INCLUDE "CreatorAttributeMethodDll.dep"
!ELSE 
!MESSAGE Warning: cannot find "CreatorAttributeMethodDll.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release" || "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"
SOURCE=..\..\Creator\cccCreator.cpp

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\cccCreator.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\cccCreator.obj"	"$(INTDIR)\cccCreator.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\CreatorAttributeMethodDll.cpp

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\CreatorAttributeMethodDll.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\CreatorAttributeMethodDll.obj"	"$(INTDIR)\CreatorAttributeMethodDll.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"


!ENDIF 

SOURCE=.\CreatorAttributeMethodDll.rc

"$(INTDIR)\CreatorAttributeMethodDll.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=..\..\Creator\FileFunctions.cpp

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\FileFunctions.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\FileFunctions.obj"	"$(INTDIR)\FileFunctions.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE="..\..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\FlatListInMemory.cpp"

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\FlatListInMemory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\FlatListInMemory.obj"	"$(INTDIR)\FlatListInMemory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=..\FriendGlobal.cpp

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\FriendGlobal.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\FriendGlobal.obj"	"$(INTDIR)\FriendGlobal.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE="..\..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\HoleListInMemory.cpp"

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\HoleListInMemory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\HoleListInMemory.obj"	"$(INTDIR)\HoleListInMemory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE="..\..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\StackInMemory.cpp"

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"


"$(INTDIR)\StackInMemory.obj" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"


"$(INTDIR)\StackInMemory.obj"	"$(INTDIR)\StackInMemory.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\CreatorAttributeMethodDll.pch"
	$(CPP) $(CPP_PROJ) $(SOURCE)


!ENDIF 

SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Fp"$(INTDIR)\CreatorAttributeMethodDll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\CreatorAttributeMethodDll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "CreatorAttributeMethodDll - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\CreatorAttributeMethodDll.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\CreatorAttributeMethodDll.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

