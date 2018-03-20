// Creator.h : main header file for the CREATOR application
//

#if !defined(AFX_CREATOR_H__3452907D_523B_4D10_ADA0_1CD26547910D__INCLUDED_)
#define AFX_CREATOR_H__3452907D_523B_4D10_ADA0_1CD26547910D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#include "stdafx.h"



/////////////////////////////////////////////////////////////////////////////
// CreatorApp:
// See Creator.cpp for the implementation of this class
//

class CreatorApp : public CWinApp
{


public:
	CreatorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CreatorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL



// Implementation
	//{{AFX_MSG(CreatorApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATOR_H__3452907D_523B_4D10_ADA0_1CD26547910D__INCLUDED_)
