// CreatorMethodDll.h : main header file for the CREATORMETHODDLL DLL
//

#if !defined(AFX_CREATORMETHODDLL_H__C52ABCCB_68EB_4789_B822_ED9603EDD603__INCLUDED_)
#define AFX_CREATORMETHODDLL_H__C52ABCCB_68EB_4789_B822_ED9603EDD603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include "..\DeclareClasses.h"

/////////////////////////////////////////////////////////////////////////////
// CCreatorMethodDllApp
// See CreatorMethodDll.cpp for the implementation of this class
//

class CCreatorMethodDllApp : public CWinApp
{
public:
	CCreatorMethodDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreatorMethodDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CCreatorMethodDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATORMETHODDLL_H__C52ABCCB_68EB_4789_B822_ED9603EDD603__INCLUDED_)
