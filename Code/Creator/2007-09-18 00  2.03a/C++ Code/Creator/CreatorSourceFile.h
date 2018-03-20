// Microsoft Generated Header

	#if !defined(AFX_CREATORSOURCEFILE_H__7C8AD4FC_9966_4D7C_8468_24CFA77AA82F__INCLUDED_)
	#define AFX_CREATORSOURCEFILE_H__7C8AD4FC_9966_4D7C_8468_24CFA77AA82F__INCLUDED_

	#if _MSC_VER > 1000
	#pragma once
	#endif // _MSC_VER > 1000


//
//	Creator . Creator Source File
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: ~ Friday, March 30, 2007 - Saturday, April 21, 2007
//
// -----

// Includes

	#ifndef __AFXEXT_H__
	#include <afxext.h>
	#endif

// Class Declarations

	class gggCCreator ;
	class CCreator ;
	class CParser ;

// Classes

	// Document

		class CCreatorSourceFileDoc : public CDocument {

			// Constructor & Destructor

				protected :

					CCreatorSourceFileDoc ( ) ; // Protected constructor used by dynamic creation
					DECLARE_DYNCREATE ( CCreatorSourceFileDoc )

			// Public
				
				public :
					
					// Variables
						
						CCreator* Creator ;
						CParser* Parser ;
						CString Code ;
							
					// Methods
						
						void Load ( CString aFilePath ) ;
						void Save ( CString aFilePath ) ;

			// Event Procedures ( / Overrides )

				// ClassWizard generated virtual function overrides
				//{{AFX_VIRTUAL(CCreatorSourceFileDoc)
					public:
						virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
						virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
					protected:
						virtual BOOL OnNewDocument();
				//}}AFX_VIRTUAL

			// Implementation

				public:
					virtual ~CCreatorSourceFileDoc();
					#ifdef _DEBUG
						virtual void AssertValid() const;
						virtual void Dump(CDumpContext& dc) const;
					#endif

			// Generated message map functions

				protected:
					//{{AFX_MSG(CCreatorSourceFileDoc)
						// NOTE - the ClassWizard will add and remove member functions here.
					//}}AFX_MSG
					DECLARE_MESSAGE_MAP()

		};

	// View

		class CCreatorSourceFile : public CFormView {

			// Constructor & Destructor
			
				protected :

					CCreatorSourceFile ( ) ; // protected constructor used by dynamic creation
					DECLARE_DYNCREATE ( CCreatorSourceFile )

			// Private

				private :

					// Variables

						BOOL Shift ;
						BOOL Ctrl ;
						BOOL Alt ;

					// Properties
						
						CCreatorSourceFileDoc* Document ( ) ;

					// Methods
					
						void InsertText ( CString aText ) ;
						BOOL DeleteLargeSpace ( ) ;

			// Retaining Scroll Position ( Unbelievably Complicated )
					
				void RememberScrollPosition ( ) ;
				void RestoreScrollPosition ( ) ;
				int VisibleLinesInTextBox ;
				int TextBoxBottomLineA ;
				int TextBoxBottomLineB ;

			// Form Data

				public :

					//{{AFX_DATA(CCreatorSourceFile)
	enum { IDD = IDD_CREATORSOURCEFILE_FORM };
	CButton	ShowMessagesButton;
	CButton	ReplaceCreatorButton;
	CButton	ParseButton;
	CButton	NoMessagesButton;
						CEdit	TextBox;
	//}}AFX_DATA

			// Implementation

				protected :
					virtual ~CCreatorSourceFile();
				#ifdef _DEBUG
					virtual void AssertValid() const;
					virtual void Dump(CDumpContext& dc) const;
				#endif

			// Base Class Event Procedures ( / Overrides )

					// ClassWizard generated virtual function overrides
					//{{AFX_VIRTUAL(CCreatorSourceFile)
						public:
							virtual BOOL PreTranslateMessage(MSG* pMsg);
						protected:
							virtual void DoDataExchange(CDataExchange* pDX); // DDX / DDV support
							virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
							virtual void OnInitialUpdate();
					//}}AFX_VIRTUAL

			// Event Procedures ( / Message Mappings )

					// Generated message map functions
					//{{AFX_MSG(CCreatorSourceFile)
						afx_msg void OnTextBoxChanged();
						afx_msg void OnParseButtonClicked();
						afx_msg void OnReplaceCreatorButtonClicked();
						afx_msg void OnShowMessagesButtonClicked();
						afx_msg void OnNoMessagesButtonClicked();
	afx_msg void OnPaint();
	//}}AFX_MSG
					DECLARE_MESSAGE_MAP()

		};


// Microsoft Generated Footer

	//{{AFX_INSERT_LOCATION}}
	// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

	#endif // !defined(AFX_CREATORSOURCEFILE_H__7C8AD4FC_9966_4D7C_8468_24CFA77AA82F__INCLUDED_)
