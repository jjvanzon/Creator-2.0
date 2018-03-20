// ChildFrame.cpp : implementation of the ChildFrame class
//

#include "stdafx.h"
#include "CreatorApp.h"

#include "ChildFrame.h"

#include "Windows.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ChildFrame

IMPLEMENT_DYNCREATE(ChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(ChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(ChildFrame)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ChildFrame construction/destruction

ChildFrame::ChildFrame()
{
	// TODO: add member initialization code here
	
}

ChildFrame::~ChildFrame()
{
}

BOOL ChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// ChildFrame diagnostics

#ifdef _DEBUG
void ChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void ChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// ChildFrame message handlers
