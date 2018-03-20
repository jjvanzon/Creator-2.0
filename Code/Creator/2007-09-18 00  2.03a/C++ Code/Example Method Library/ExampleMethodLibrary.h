// ExampleMethodLibrary.h : main header file for the EXAMPLEMETHODLIBRARY DLL
//

#if !defined(AFX_EXAMPLEMETHODLIBRARY_H__7A7E6F7D_5960_45CD_998B_72CF2F9EC675__INCLUDED_)
#define AFX_EXAMPLEMETHODLIBRARY_H__7A7E6F7D_5960_45CD_998B_72CF2F9EC675__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "DeclareClasses.h"
#include "..\Creator\cccCreator.h"

/////////////////////////////////////////////////////////////////////////////
// CExampleMethodLibraryApp
// See ExampleMethodLibrary.cpp for the implementation of this class
//

class CExampleMethodLibraryApp : public CWinApp
{
public:
	CExampleMethodLibraryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExampleMethodLibraryApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CExampleMethodLibraryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXAMPLEMETHODLIBRARY_H__7A7E6F7D_5960_45CD_998B_72CF2F9EC675__INCLUDED_)
