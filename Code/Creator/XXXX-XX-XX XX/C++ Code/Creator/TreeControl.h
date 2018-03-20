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
	class CItemAttribute ;
	class CItemMethod ;

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
					public : void SetValue ( long aPosition , CString aValue ) ;
					public : void Add ( long aPosition ) ;
					public : void Remove ( long aPosition ) ;
					public : void Create ( long aPosition ) ;
					public : void SetToNothing ( long aPosition ) ;
					public : void RememberItem ( long aPosition ) ;
					public : void AssignItem ( long aPosition ) ;
					private : CItem* RememberedItem ;
					public : void Execute ( long aPosition ) ;
					public : void Refresh ( long* aPosition ) ;
					public : CString GetText ( ) ; // Constructs the Text to display on screen using the flat Tree Item Array

				// Properties
				
					public : BOOL Expanded ( long aPosition ) ;
					public : long Level ( long aPosition ) ;
					public : CString ItemType ( long aPosition ) ;
					public : BOOL IsNothing ( long aPosition ) ;
				
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
						private : long ExpandItemMethods ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;

				// Refresh
				
					// ( Rebuilds the Flat Arrays, based on the Data Items, and refreshes Tree Items, and adds and removes extra or accessive tree children )

					// ( Layer 3 . 3 . 1 )

						private : void RefreshRoot ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;

					// ( Layer 3 . 3 . 2 )
					
						private : void RefreshItem ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) ;

					// ( Layer 3 . 3 . 3 )

						private : void RefreshItemClassName ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemAttributes ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemRelatedItems ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemRelatedLists ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) ;
						private : void RefreshItemMethods ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex  ) ;

					// ( Layer 3 . 3 . 4 )

						private : void RefreshRelatedItem ( long* aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) ;
						private : void RefreshRelatedItemWhenNothing ( long* aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) ;
						private : void RefreshRelatedList ( long* aPosition , long aLevel , CRelatedList* aRelatedList , CItem* aTreeItem ) ;
						private : void RefreshRelatedListItem ( long* aPosition , long aLevel , CRelatedList* aRelatedList , long aRelatedListItemPosition , CItem* aTreeItem ) ;

			// Layer 4 : Insert & Delete

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

				private : void Delete ( long aPosition ) ;

			// Layer 5 : Data Items & Tree Items
				
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
					//     - Item Attributes ( not for collapsing and expanding, but for changing attribute values )
					//     - Item Methods
					//
					// So there are 3 things to keep in sync: Data Items, Tree Items and Flat Arrays	
					//
					// Even when items have been removed in between from a List,
					// There will still be a Tree Item for each index, so the Tree Item and Data Item indexes are always in sync.
					//
					// !!! (I just realized the indexes of Tree Control data items and tree items will stay in sync anyway, when you synchronously remove items.)
				
				// Variables

					private : CCreator* Creator ;
					private : CItem* MyStructure ;
					private : CItem* TreeRoot ;
					public : CItem* DataRoot ;
					private : CArray < CItem* , CItem* > TreeItemArray ;
					private : CArray < CRelatedItem* , CRelatedItem* > RelatedItemArray ;
					private : CArray < CRelatedList* , CRelatedList* > RelatedListArray ;
					private : CArray < CRelatedList* , CRelatedList* > RelatedListItemRelatedListArray ;
					private : CArray < long , long > RelatedListItemPositionArray ;
					private : CArray < CItemAttribute* , CItemAttribute* > ItemAttributeArray ;
					private : CArray < CItemMethod* , CItemMethod* > ItemMethodArray ;

					// New 2007-08-25

						public : CCreator* DataStructureCreator ;  // Not sure you need a whole new Creator, though.
						public : CItem* DataStructure ;

			// Layer 6 : Helpers

				// Constants
					
					public : CString RootItemType ( ) { return "0" ; } ;
					public : CString AttributeItemType ( ) { return "1" ; } ;
					public : CString RelatedItemItemType ( ) { return "2" ; } ;
					public : CString RelatedListItemType ( ) { return "3" ; } ;
					public : CString RelatedListItemItemType ( ) { return "4" ; } ;
					public : CString TitleItemType ( ) { return "5" ; } ;
					public : CString ClassNameItemType ( ) { return "6" ; } ;
					public : CString MethodItemType ( ) { return "7" ; } ;
					public : CString ForewardDirection ( ) { return "0" ; } ;
					public : CString BackwardDirection ( ) { return "1" ; } ;
					public : CString UndefinedDirection ( ) { return "2" ; } ;

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
	CButton	ExecuteButton;
						CButton	RememberItemButton;
						CButton	SetValueButton;
						CButton	SetToNothingButton;
						CStatic	ValueTitleLabel;
						CEdit	ValueTextBox;
						CButton	RemoveButton;
						CButton	CreateButton;
						CButton	AssignItemButton;
						CButton	AddButton;
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
				afx_msg void OnAddButtonClicked();
				afx_msg void OnRemoveButtonClicked();
				afx_msg void OnCreateButtonClicked();
				afx_msg void OnAssignItemButtonClicked();
				afx_msg void OnSetToNothingButtonClicked();
				afx_msg void OnSetValueButtonClicked();
				afx_msg void OnRememberItemButtonClicked();
	afx_msg void OnExecuteButtonClicked();
	//}}AFX_MSG
				DECLARE_MESSAGE_MAP()

		} ;

// Microsoft Generated Footer

	//{{AFX_INSERT_LOCATION}}
	// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

	#endif // !defined(AFX_TREECONTROL_H__CC31EC76_2DDE_4C86_8A8C_010C239BD7E9__INCLUDED_)
