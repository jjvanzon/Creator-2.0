// Microsoft Generated Header

	#if !defined(AFX_TREECONTROL_H__CC31EC76_2DDE_4C86_8A8C_010C239BD7E9__INCLUDED_)
	#define AFX_TREECONTROL_H__CC31EC76_2DDE_4C86_8A8C_010C239BD7E9__INCLUDED_

	#if _MSC_VER > 1000
	#pragma once
	#endif // _MSC_VER > 1000

//
//	Creator . Tree Control
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, April 3, 2007 - Friday, April 4, 2007
//
// -----

// Includes

	#ifndef __AFXEXT_H__
	#include <afxext.h>
	#endif
	#include <afxtempl.h>

// Class Declarations

	class CItem ;
	class CCreator ;
	class CRelatedItem ;
	class CRelatedList ;

// Classes

	// Document

		class TreeControlDoc : public CDocument {
			
			// Layer 1 : Constructor & Destructor

				protected :

					TreeControlDoc ( ) ; // Protected constructor used by dynamic creation
					DECLARE_DYNCREATE ( TreeControlDoc )

			// Layer 2 : Main Operations
				
				// Methods

					public : long Expand ( long aPosition ) ;
					public : void Collapse ( long aPosition ) ;
					public : CString GetText ( ) ; // Constructs the Text to display on screen using the flat Tree Item Array

					public : void Refresh ( long* aPosition ) ;

				// Properties
				
					public : BOOL Expanded ( long aPosition ) ;
					public : long Level ( long aPosition ) ;
				
			// Layer 3 : Branch Offs of Main Operations

				// Expand
					
					// ( Layer 3 . 1 . 1 )

						private : long ExpandRoot ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;
						private : long ExpandRelatedItem ( long aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) ;
						private : long ExpandRelatedList ( long aPosition , long aLevel , CRelatedList* aRelatedList , CItem* aTreeItem ) ;
						private : long ExpandRelatedListItem ( long aPosition , long aLevel , CRelatedList* aRelatedList , long aRelatedListItemPosition , CItem* aTreeItem ) ;

					// ( Layer 3 . 1 . 2 )
					
						private : long ExpandItem ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;
						private : long ExpandRelatedItemWhenNothing ( long aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) ;

					// ( Layer 3 . 1 . 3 )

						private : long ExpandItemClassName ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;
						private : long ExpandItemAttributes ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;
						private : long ExpandItemRelatedItems ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;
						private : long ExpandItemRelatedLists ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;

				// Refresh

					// ( Layer 3 . 3 . 1 )

						private : void RefreshRoot ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;

					// ( Layer 3 . 3 . 2 )
					
						private : void RefreshItem ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;

					// ( Layer 3 . 3 . 3 )

						private : void RefreshItemClassName ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemAttributes ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemRelatedItems ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemRelatedLists ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;

					// ( Layer 3 . 3 . 4 )

						private : void RefreshRelatedItem ( long* aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) ;
						private : void RefreshRelatedItemWhenNothing ( long* aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) ;
						private : void RefreshRelatedList ( long* aPosition , long aLevel , CRelatedList* aRelatedList , CItem* aTreeItem ) ;
						private : void RefreshRelatedListItem ( long* aPosition , long aLevel , CRelatedList* aRelatedList , long aRelatedListItemPosition , CItem* aTreeItem ) ;

			// Layer 5 : Insert & Remove

				private : void Insert (
					long aPosition ,
					long aLevel ,
					CString aDirection ,
					CItem* aTreeItem ,
					CString aText ,
					CString aItemType ,
					void* aDataItem ,
					long aRelatedListItemPosition = 0 ,
					BOOL aForRefresh = FALSE
				) ;

				private : void Remove ( long aPosition ) ;

			// Layer 4 : Data Items & Tree Items
				
				// Comment :

					// There is a separation between Data Items and Tree Items,
					// because the same Data Item can be represented by multiple items in the Tree,
					// while the Expanded property can be completely different.
					//
					// Apart from the Data's and Tree's organization in a tree structure, 
					// There are flat arrays of Tree Items and Data Items,
					// in the same order as the lines on screen the items are positioned at.
					//
					// A flat array is needed for :
					//     - Tree Items
					//     - Related Items
					//     - Related Lists
					//     - Related List Items
				
				// Variables

					private : CCreator* Creator ;
					private : CItem* MyStructure ;
					private : CItem* TreeRoot ;
					private : CItem* DataRoot ;
					private : CArray < CItem* , CItem* > TreeItemArray ;
					private : CArray < CRelatedItem* , CRelatedItem* > RelatedItemArray ;
					private : CArray < CRelatedList* , CRelatedList* > RelatedListArray ;
					private : CArray < CRelatedList* , CRelatedList* > RelatedListItemRelatedListArray ;
					private : CArray < long , long > RelatedListItemPositionArray ;

			// Layer 5 : Helpers

				// Constants
					
					private : CString RootItemType ( ) { return "0" ; } ;
					private : CString AttributeItemType ( ) { return "1" ; } ;
					private : CString RelatedItemItemType ( ) { return "2" ; } ;
					private : CString RelatedListItemType ( ) { return "3" ; } ;
					private : CString RelatedListItemItemType ( ) { return "4" ; } ;
					private : CString TitleItemType ( ) { return "5" ; } ;
					private : CString ClassNameItemType ( ) { return "6" ; } ;
					private : CString ForewardDirection ( ) { return "0" ; } ;
					private : CString BackwardDirection ( ) { return "1" ; } ;
					private : CString UndefinedDirection ( ) { return "2" ; } ;

				// Methods

					private : void InitializeArrays ( ) ;
					private : CString GetAttribute ( long aPosition , CString aAttributeName ) ; // Gets an attribute from a Tree Item out of the flat array
					private : CString TabSpace ( long aLevel ) ;
					private : CString LongToString ( long aValue ) ;
					private : CString ExpansionSymbol ( BOOL aExpanded ) ;

			// Event Procedures ( / Overrides )
			
				// ClassWizard generated virtual function overrides
				//{{AFX_VIRTUAL(TreeControlDoc)
					public:
					protected:
						virtual BOOL OnNewDocument();
				//}}AFX_VIRTUAL

			// Implementation

				public:
					virtual ~TreeControlDoc();
					#ifdef _DEBUG
						virtual void AssertValid() const;
						virtual void Dump(CDumpContext& dc) const;
					#endif

			// Generated message map functions

				protected:
					//{{AFX_MSG(TreeControlDoc)
						// NOTE - the ClassWizard will add and remove member functions here.
					//}}AFX_MSG
					DECLARE_MESSAGE_MAP()

		} ;

	// View

		class TreeControl : public CFormView {
			
			// Constructor & Destructor
			
				protected :

					TreeControl ( ) ; // protected constructor used by dynamic creation
					DECLARE_DYNCREATE ( TreeControl )

			// Private
				
				private :
					
					// Properties
					
						TreeControlDoc* Document ( ) ;
						long CurrentLine ( ) ;
						BOOL Expanded ( ) ;

					// Methods

						void Fill ( ) ;
						void Expand ( ) ;
						void Collapse ( ) ;
						BOOL CollapseSymbolHitTest ( ) ;

			// Form Data

				public :

					//{{AFX_DATA(TreeControl)
	enum { IDD = IDD_TREECONTROL_FORM };
	CButton	RefreshButton;
						CEdit	TextBox;
	//}}AFX_DATA

			// Implementation

				protected:
					virtual ~TreeControl();
					#ifdef _DEBUG
						virtual void AssertValid() const;
						virtual void Dump(CDumpContext& dc) const;
					#endif

			// Base Class Event Procedures ( / Overrides )
				
				// ClassWizard generated virtual function overrides
				//{{AFX_VIRTUAL(TreeControl)
					public:
						virtual void OnInitialUpdate();
						virtual BOOL PreTranslateMessage(MSG* pMsg);
					protected:
						virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
				//}}AFX_VIRTUAL

			// Event Procedures ( / Message Mappings )
				
				// Generated message map functions
				//{{AFX_MSG(TreeControl)
				afx_msg void OnRefreshButton();
	afx_msg void OnPaint();
	//}}AFX_MSG
				DECLARE_MESSAGE_MAP()

		} ;

// Microsoft Generated Footer

	//{{AFX_INSERT_LOCATION}}
	// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

	#endif // !defined(AFX_TREECONTROL_H__CC31EC76_2DDE_4C86_8A8C_010C239BD7E9__INCLUDED_)
