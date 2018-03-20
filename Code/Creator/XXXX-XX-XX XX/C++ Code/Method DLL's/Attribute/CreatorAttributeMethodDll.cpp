// CreatorAttributeMethodDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "CreatorAttributeMethodDll.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CCreatorAttributeMethodDllApp

BEGIN_MESSAGE_MAP(CCreatorAttributeMethodDllApp, CWinApp)
	//{{AFX_MSG_MAP(CCreatorAttributeMethodDllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreatorAttributeMethodDllApp construction

CCreatorAttributeMethodDllApp::CCreatorAttributeMethodDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCreatorAttributeMethodDllApp object

CCreatorAttributeMethodDllApp theApp;

extern CString PASCAL EXPORT OverrideGet ( CItemAttribute* aThis , BOOL* aOverridden )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	#include "OverrideGet.h"
	return "" ;
}

extern void PASCAL EXPORT OverrideSet ( CItemAttribute* aThis , BOOL* aOverridden , CString aValue )
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	#include "OverrideSet.h"
}
