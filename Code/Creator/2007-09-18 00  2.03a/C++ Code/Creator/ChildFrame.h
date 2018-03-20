// ChildFrame.h : interface of the ChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRAME_H__5CFD200F_ABB4_47DE_8DE0_8B1352C9E8A1__INCLUDED_)
#define AFX_CHILDFRAME_H__5CFD200F_ABB4_47DE_8DE0_8B1352C9E8A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class ChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(ChildFrame)
public:
	ChildFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ChildFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~ChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(ChildFrame)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRAME_H__5CFD200F_ABB4_47DE_8DE0_8B1352C9E8A1__INCLUDED_)
