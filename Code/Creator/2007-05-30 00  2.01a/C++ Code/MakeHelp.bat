@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by CREATOR.HPJ. >"hlp\Creator.hm"
echo. >>"hlp\Creator.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Creator.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Creator.hm"
echo. >>"hlp\Creator.hm"
echo // Prompts (IDP_*) >>"hlp\Creator.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Creator.hm"
echo. >>"hlp\Creator.hm"
echo // Resources (IDR_*) >>"hlp\Creator.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Creator.hm"
echo. >>"hlp\Creator.hm"
echo // Dialogs (IDD_*) >>"hlp\Creator.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Creator.hm"
echo. >>"hlp\Creator.hm"
echo // Frame Controls (IDW_*) >>"hlp\Creator.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Creator.hm"
REM -- Make help for Project CREATOR


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Creator.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Creator.hlp" goto :Error
if not exist "hlp\Creator.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Creator.hlp" Debug
if exist Debug\nul copy "hlp\Creator.cnt" Debug
if exist Release\nul copy "hlp\Creator.hlp" Release
if exist Release\nul copy "hlp\Creator.cnt" Release
echo.
goto :done

:Error
echo hlp\Creator.hpj(1) : error: Problem encountered creating help file

:done
echo.
