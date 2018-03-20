//
//	Creator . Tree Control
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, April 3, 2007 - Friday, April 4, 2007 
//
// -----

// Includes

	#include "stdafx.h"
	#include "CreatorApp.h"
	#include "TreeControl.h"

	#include "DeclareClasses.h"

// Microsoft Generated Code

	#ifdef _DEBUG
	#define new DEBUG_NEW
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
	#endif

	/////////////////////////////////////////////////////////////////////////////
	// TreeControl

	IMPLEMENT_DYNCREATE(TreeControl, CFormView)

	void TreeControl::DoDataExchange(CDataExchange* pDX)
	{
		CFormView::DoDataExchange(pDX);
		//{{AFX_DATA_MAP(TreeControl)
	DDX_Control(pDX, IDC_REFRESHBUTTON, RefreshButton);
			DDX_Control(pDX, IDC_TREECONTROLTEXTBOX, TextBox);
	//}}AFX_DATA_MAP
	}

	BEGIN_MESSAGE_MAP(TreeControl, CFormView)
		//{{AFX_MSG_MAP(TreeControl)
			ON_BN_CLICKED(IDC_REFRESHBUTTON, OnRefreshButton)
	ON_WM_SIZE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	END_MESSAGE_MAP()

	/////////////////////////////////////////////////////////////////////////////
	// TreeControl diagnostics

	#ifdef _DEBUG
	void TreeControl::AssertValid() const
	{
		CFormView::AssertValid();
	}

	void TreeControl::Dump(CDumpContext& dc) const
	{
		CFormView::Dump(dc);
	}
	#endif //_DEBUG

	/////////////////////////////////////////////////////////////////////////////
	// TreeControl message handlers
	/////////////////////////////////////////////////////////////////////////////
	// TreeControlDoc

	IMPLEMENT_DYNCREATE(TreeControlDoc, CDocument)

	BEGIN_MESSAGE_MAP(TreeControlDoc, CDocument)
		//{{AFX_MSG_MAP(TreeControlDoc)
			// NOTE - the ClassWizard will add and remove mapping macros here.
		//}}AFX_MSG_MAP
	END_MESSAGE_MAP()

	/////////////////////////////////////////////////////////////////////////////
	// TreeControlDoc diagnostics

	#ifdef _DEBUG
	void TreeControlDoc::AssertValid() const
	{
		CDocument::AssertValid();
	}

	void TreeControlDoc::Dump(CDumpContext& dc) const
	{
		CDocument::Dump(dc);
	}
	#endif //_DEBUG


// Classes

	// Document

		// Layer 1 : Constructor & Destructor
		
			TreeControlDoc :: TreeControlDoc ( ) {
				// Create Creator
					Creator = new CCreator ;
				// Load Tree Control's Creator Code
					// Get Code File Path
						CString tTreeControlProductionCreatorCodeFilePath = TreeControlProductionCreatorCodeFilePath ( ) ;
						if ( FileExists ( tTreeControlProductionCreatorCodeFilePath ) == FALSE ) {
							MessageBox ( 0 , "Tree Control Creator Code file not found. Adapt registry setting HKEY_LOCAL_MACHINE\\" + RegistryLocation ( ) + "\\TreeControlProductionCreatorCodeFilePath" , ApplicationName ( ) , 0 ) ;
						}
					MyStructure = Creator -> LoadStructure ( tTreeControlProductionCreatorCodeFilePath ) ;
				// Add Root Item
					// Create Tree Root 
						TreeRoot = new CItem ;
						TreeRoot -> GenericClass ( MyStructure -> RelatedLists ( ) -> Item ( "Classes" ) -> Item ( 0 ) ) ;
						TreeRoot -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value = "False" ;
						TreeRoot -> ItemAttributes ( ) -> Item ( "Text" ) -> Value = "Root" ;
						TreeRoot -> ItemAttributes ( ) -> Item ( "Position" ) -> Value = "0" ;
						TreeRoot -> ItemAttributes ( ) -> Item ( "Level" ) -> Value = "0" ;
						TreeRoot -> ItemAttributes ( ) -> Item ( "Item Type" ) -> Value = RootItemType ( ) ;
					// Set Example Data Root
						// DataRoot = Creator -> YourStructure ; // Creator's own structure
						DataRoot = MyStructure ; // Tree Control's structure
						// DataRoot = TreeRoot ; // Tree Control's data (Wicked, display Tree Item data itself)
					// Add Tree Root and Data Root to Arrays
						InitializeArrays ( ) ;
			}

			TreeControlDoc :: ~TreeControlDoc ( ) {
				delete Creator ;
				delete TreeRoot ;
			}
		
		// Layer 2 : Main Operations

			// Methods

				long TreeControlDoc :: Expand ( long aPosition ) {
					// Conditions
						// Index Valid
							if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) ) ) { return aPosition ; }
					// Declarations
						CItem* tTreeItem = TreeItemArray . GetAt ( aPosition ) ;
					// Get Expanded Attribute
						CItemAttribute* tExpanded = tTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) ;
					// Conditions
						// Item not expanded already
							if ( tExpanded -> Value == "True" ) { return aPosition ; } ;
					// Get Other Tree Item Attributes
						CString tLevelString =  tTreeItem -> ItemAttributes ( ) -> Item ( "Level" ) -> Value ;
						long tLevel = atoi ( tLevelString ) ;
						CString tItemType = tTreeItem -> ItemAttributes ( ) -> Item ( "Item Type" ) -> Value ;
					// Set Expanded = True
						tExpanded -> Value = "True" ;
					// Expand Root
						if ( tItemType == RootItemType ( ) ) {
							return ExpandRoot ( 
								aPosition , 
								tLevel , 
								DataRoot , 
								tTreeItem
							) ;
						}
					// Expand Related Item
						if ( tItemType == RelatedItemItemType ( ) ) {
							return ExpandRelatedItem (
								aPosition ,
								tLevel ,
								RelatedItemArray . GetAt ( aPosition ) ,
								tTreeItem
							) ;
						}
					// Expand Related List
						if ( tItemType == RelatedListItemType ( ) ) {
							return ExpandRelatedList ( 
								aPosition ,
								tLevel ,
								RelatedListArray . GetAt ( aPosition ) ,
								tTreeItem
							) ;
						}
					// Expand Related List Item
						if ( tItemType == RelatedListItemItemType ( ) ) {
							return ExpandRelatedListItem (
								aPosition ,
								tLevel ,
								RelatedListItemRelatedListArray . GetAt ( aPosition ) ,
								RelatedListItemPositionArray . GetAt ( aPosition ) ,
								TreeItemArray . GetAt ( aPosition )
							) ;
						}
					return aPosition ;
				} ;

				void TreeControlDoc :: Collapse ( long aPosition ) {
					// Comment :
						// Set the Tree Item to not collapsed
						// Traverse all Tree Item's sub items in reverse order
							// Collapse the item (causes recursion)
							// Remove the item from the flat arrays
							// Remove the child from the tree item
					// Conditions
						// Index Valid
							if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) ) ) { return ; }
					// Get Tree Item
						CItem* tTreeItem = TreeItemArray . GetAt ( aPosition ) ;
					// Get Expanded Attribute
						CItemAttribute* tExpanded = tTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) ;
					// Conditions
						// Item not already collapsed
							 if ( tExpanded -> Value == "False" ) { return ; } ;
					// Set Expanded = False
						tExpanded -> Value = "False" ;
					// Traverse Children
						CRelatedList* tChildren = tTreeItem -> RelatedLists ( ) -> Item ( "Children" ) ;
						long i ;
						for ( i = tChildren -> StorageCount ( ) - 1 ; i >= 0 ; i -- ) {
							if ( tChildren -> PositionUsed ( i ) == TRUE ) {
								CItem* tChild = tChildren -> Item ( i ) ;
								// Get Child's Attributes
									// Expanded
										CItemAttribute* tExpanded = tChild -> ItemAttributes ( ) -> Item ( "Expanded" ) ;
									// Position
										CString tPositionString = tChild -> ItemAttributes ( ) -> Item ( "Position" ) -> Value ;
										long tPosition = atoi ( tPositionString ) ;
								// Collapse Child
									if ( tExpanded -> Value == "True" ) {
										Collapse ( tPosition ) ;
										tExpanded -> Value == "False" ;
									}
								// Remove Child From Flat Arrays
									Remove ( tPosition ) ;
								// Remove Child From Tree Item
									tChildren -> Remove ( i ) ;
							}
						}
					} ;

				CString TreeControlDoc :: GetText ( ) {
					// Declarations
						long i ;
						CString tReturnValue ;
						long tLevel ;
						CString tItemType ;
						BOOL tExpanded ;
						CString tText ;
						CString tDirection ;
					// Traverse Tree Items
						for ( i = 0 ; i <= TreeItemArray . GetSize ( ) - 1 ; i ++ ) {
							// Get Attribute Values
								// Level
									tLevel = atoi ( GetAttribute ( i , "Level" ) ) ;
								// Item, Type
									tItemType = GetAttribute ( i , "Item Type" ) ;
								// Expanded
									tExpanded = GetAttribute ( i , "Expanded" ) == "True" ;
								// Text
									tText = GetAttribute ( i , "Text" ) ;
								// Direction
									tDirection = GetAttribute ( i , "Direction" ) ;
							// Build Line
								// Add Tab Space
									tReturnValue +=  TabSpace ( tLevel ) ;
								// Add Expanded Symbol
									if ( tItemType == AttributeItemType ( ) ) {
										tReturnValue += "    " ;
									}
									if ( tItemType == TitleItemType ( ) ) {
										tReturnValue += "   " ;
									}
									if ( tItemType == ClassNameItemType ( ) ) {
										tReturnValue += "    " ;
									}
									if ( 
										tItemType == RootItemType ( ) ||
										tItemType == RelatedItemItemType ( ) ||
										tItemType == RelatedListItemType ( ) ||
										tItemType == RelatedListItemItemType ( ) 
									) {
										tReturnValue += ExpansionSymbol ( tExpanded ) ;
									}
								// Add Text
									tReturnValue += tText ;
								// Add Direction Symbol
 									if ( tDirection == ForewardDirection ( ) ) {
										tReturnValue += "  -->  " ;
									}
									if ( tDirection == BackwardDirection ( ) ) {
										tReturnValue += "  <--   " ;
									}
								// Add Enter
									tReturnValue += "\r\n" ;
						}
						return tReturnValue ;
				} ;

				void TreeControlDoc :: Refresh ( long* aPosition ) {
					// Manage aPosition Nothing
						BOOL tPositionWasNothing = FALSE ;
						if ( aPosition == 0 ) { tPositionWasNothing = TRUE ; }
						if ( tPositionWasNothing == TRUE ) { aPosition = new long ; *aPosition = 0 ; }
					// Functionality
						RefreshRoot ( aPosition , 0 , DataRoot , TreeRoot ) ;
					// Manage aPosition Nothing
						if ( tPositionWasNothing == TRUE ) { delete aPosition ; }
				} ;
				
			// Properties
			
				BOOL TreeControlDoc :: Expanded ( long aPosition ) {
					// Conditions
						if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) ) ) { return FALSE ; }
					// Return Value
						if ( GetAttribute ( aPosition , "Expanded" ) == "True" ) {
							return TRUE ;
						}
						else {
							return FALSE ;
						}
				} ;

				long TreeControlDoc :: Level ( long aPosition ) {
					// Conditions
						if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) ) ) { return FALSE ; }
					// Return Value
						CString tString ;
						tString = GetAttribute ( aPosition , "Level" ) ;
						if ( tString = "" ) { return -1 ; }
						return atoi ( tString ) ;
				} ;

		// Layer 3 : Branch Offs of Main Operations

			// Expand
				
				// ( Layer 3 . 1 . 1 )

					long TreeControlDoc :: ExpandRoot ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						return ExpandItem ( aPosition , aLevel , aDataItem , aTreeItem ) ;
					} ;

					long TreeControlDoc :: ExpandRelatedItem ( long aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) {
						if ( aRelatedItem -> Item ( ) == 0 ) {
							return ExpandRelatedItemWhenNothing (
								aPosition ,
								aLevel ,
								aRelatedItem ,
								aTreeItem
							) ;
						}
						else {
							return ExpandItem (
								aPosition ,
								aLevel ,
								aRelatedItem -> Item ( ) ,
								aTreeItem
							) ;
						}
					} ;
						
					long TreeControlDoc :: ExpandRelatedList ( long aPosition , long aLevel , CRelatedList* aRelatedList , CItem* aTreeItem ) {
						CString tString ;
						CItem* tChild ;
						// Show Class Name
							tString = "Class : " + aRelatedList -> GenericRelationClass -> ClassName ( ) ;
							tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
							Insert (
								// a Position
									aPosition + 1 ,
								// a Level
									aLevel + 1 ,
								// a Direction
									UndefinedDirection ( ) ,
								// a Tree Item
									tChild ,
								// a Text
									tString ,
								// a Item Type
									ClassNameItemType ( ) ,
								// a DataItem
									0
							) ;
							aPosition += 1 ;
						long i ;
						for ( i = 0 ; i <= aRelatedList -> StorageCount ( ) - 1 ; i ++ ) {
							// Always add a Tree Child for each position
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
							if ( aRelatedList -> PositionUsed ( i ) == TRUE ) {
								tString = "[  " + LongToString ( i ) + "  ]" ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										RelatedListItemItemType ( ) ,
									// a Data Item
										aRelatedList ,
									// a Related List Item Position
										i
								) ;
							}
							aPosition += 1 ;
						}
						return aPosition ;
					} ;

					long TreeControlDoc :: ExpandRelatedListItem ( long aPosition , long aLevel , CRelatedList* aRelatedList , long aRelatedListItemPosition , CItem* aTreeItem ) {
						return ExpandItem (
							aPosition ,
							aLevel ,
							aRelatedList -> Item ( aRelatedListItemPosition ) ,
							aTreeItem
						) ;
					} ;
				
				// ( Layer 3 . 1 . 2 )

					long TreeControlDoc :: ExpandItem ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						// Conditions
							if ( aDataItem == 0 ) { return aPosition ; }
						// Declarations
							CString tString ;
						// Show Class Name
							aPosition = ExpandItemClassName (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem
							) ;
						// Show Attributes
							aPosition = ExpandItemAttributes (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem
							) ;
						// Show Related Items
							aPosition = ExpandItemRelatedItems (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem
							) ;
						// Show Related Lists
							aPosition = ExpandItemRelatedLists (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem
							) ;
						return aPosition ;
					} ;

					long TreeControlDoc :: ExpandRelatedItemWhenNothing ( long aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) {
						CString tString ;
						CItem* tChild ;
						tString = aRelatedItem -> ClassName ( ) ;
						tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
						Insert (
							// a Position
								aPosition + 1 ,
							// a Level
								aLevel + 1 ,
							// a Direction
								UndefinedDirection ( ) ,
							// a Tree Item
								tChild ,
							// a Text
								"( Nothing ) Class : " + tString ,
							// a Item Type
								TitleItemType ( ) ,
							// a DataItem
								0 
						) ;
						aPosition += 1 ;
						return aPosition ;
					} ;

				// ( Layer 3 . 1 . 3 )

					long TreeControlDoc :: ExpandItemClassName ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						CItem* tChild ;
						// Title
							tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
							Insert (
								// a Position
									aPosition + 1 ,
								// a Level
									aLevel + 1 ,
								// a Direction
									UndefinedDirection ( ) ,
								// a Tree Item
									tChild ,
								// a Text
									"Class :" ,
								// a Item Type
									TitleItemType ( ) ,
								// a DataItem
									0 
							) ;
							aPosition += 1 ;
							aLevel += 1 ;
						CString tString ;
						tString = aDataItem -> ClassName ( ) ;
						tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
						Insert (
							// a Position
								aPosition + 1 ,
							// a Level
								aLevel + 1 ,
							// a Direction
								UndefinedDirection ( ) ,
							// a Tree Item
								tChild ,
							// a Text
								tString ,
							// a Item Type
								ClassNameItemType ( ) ,
							// a DataItem
								0 
						) ;
						aPosition += 1 ;
						aLevel -= 1 ;
						return aPosition ;
					} ;
					
					long TreeControlDoc :: ExpandItemAttributes ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						CItem* tChild ;
						CItemAttributes* tItemAttributes ;
						tItemAttributes = aDataItem -> ItemAttributes ( ) ;
						// Title
							if ( tItemAttributes -> ListCount ( ) > 0 ) {
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										"Attributes :" ,
									// a Item Type
										TitleItemType ( ) ,
									// a DataItem
										0 
								) ;
								aPosition += 1 ;
								aLevel += 1 ;
							}
						long i ;
						CString tString ;
						for ( i = 0 ; i <= tItemAttributes -> StorageCount ( ) - 1 ; i ++ ) {
							if ( tItemAttributes -> PositionUsed ( i ) == TRUE ) {
								CItemAttribute* tItemAttribute ;
								tItemAttribute = tItemAttributes -> Item ( i ) ;
								tString = tItemAttribute -> Name ( ) + " : " ;
								// Handle String literals in a different way
									if ( tItemAttribute -> Type ( ) == "String" ) {
										CString tStringLiteral ;
										tStringLiteral = tItemAttribute -> Value ;
										tStringLiteral . Replace ( "\"" , "\"\"" ) ;
										tString += "\"" ;
										tString += tStringLiteral ;
										tString += "\"" ;
									}
								else {
									tString += tItemAttribute -> Value ;
								}
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										AttributeItemType ( ) ,
									// a DataItem
										0 
								) ;
								aPosition += 1 ;
							}
						}
						if ( tItemAttributes -> ListCount ( ) > 0 ) {
							aLevel -= 1 ;
						}
						return aPosition ;
					} ;

					long TreeControlDoc :: ExpandItemRelatedItems ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						CItem* tChild ;
						CRelatedItems* tRelatedItems ;
						tRelatedItems = aDataItem -> RelatedItems ( ) ;
						// Title
							if ( tRelatedItems -> ListCount ( ) > 0 ) {
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										"Related Items :" ,
									// a Item Type
										TitleItemType ( ) ,
									// a DataItem
										0 
								) ;
								aPosition += 1 ;
								aLevel += 1 ;
							}
						long i ;
						CString tString ;
						for ( i = 0 ; i <= tRelatedItems -> StorageCount ( ) -1 ; i ++ ) {
							if ( tRelatedItems -> PositionUsed ( i ) == TRUE ) {
								CRelatedItem* tRelatedItem ;
								tRelatedItem = tRelatedItems -> Item ( i ) ;
								CString tDirection ;
								CItemAttribute* tDirectionAttribute = tRelatedItem -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) ;
								if ( tDirectionAttribute != 0 ) {
									tDirection = tRelatedItem -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value ;
								}
								tString = tRelatedItem -> Name ( ) ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										tDirection ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										RelatedItemItemType ( ) ,
									// a Data Item
										tRelatedItem
								) ;
								aPosition += 1 ;
							}
						}
						if ( tRelatedItems -> ListCount ( ) > 0 ) {
							aLevel -= 1 ;
						}
						return aPosition ;
					} ;

					long TreeControlDoc :: ExpandItemRelatedLists ( long aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						CItem* tChild ;
						CRelatedLists* tRelatedLists ;
						tRelatedLists = aDataItem -> RelatedLists ( ) ;
						// Title
							if ( tRelatedLists -> ListCount ( ) > 0 ) {
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										"Related Lists :" ,
									// a Item Type
										TitleItemType ( ) ,
									// a DataItem
										0 
								) ;
								aPosition += 1 ;
								aLevel += 1 ;
							}
						long i ;
						CString tString ;
						for ( i = 0 ; i <= tRelatedLists -> StorageCount ( ) -1 ; i ++ ) {
							if ( tRelatedLists -> PositionUsed ( i ) == TRUE ) {
								CRelatedList* tRelatedList ;
								tRelatedList = tRelatedLists -> Item ( i ) ;
								CString tDirection ;
								CItemAttribute* tDirectionAttribute = tRelatedList -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) ;
								if ( tDirectionAttribute != 0 ) {
									tDirection = tRelatedList -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value ;
								}
								tString = tRelatedList -> Name ( ) + "  [  " + LongToString ( tRelatedList -> ListCount ( ) ) + "  ]" ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Add ( ) ;
								Insert (
									// a Position
										aPosition + 1 ,
									// a Level
										aLevel + 1 ,
									// a Direction
										tDirection ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										RelatedListItemType ( ) ,
									// a Data Item
										tRelatedList
								) ;
								aPosition += 1 ;
							}
						}
						if ( tRelatedLists -> ListCount ( ) > 0 ) {
							aLevel -= 1 ;
						}
						return aPosition ;
					} ;
					
			// Refresh
				
				// ( Layer 3 . 3 . 1 )

					void TreeControlDoc :: RefreshRoot ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						// Re-Initialize Arrays
							InitializeArrays ( ) ;
						// Call Refresh Item
							RefreshItem ( aPosition , aLevel , aDataItem , aTreeItem ) ;
					} ;

				// ( Layer 3 . 3 . 2 )

					void TreeControlDoc :: RefreshItem ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem ) {
						// Conditions
							if ( aDataItem == 0 ) { return ; }
							if ( aTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value != "True" ) { return ; }
						// Declarations
							CString tString ;
							long* tChildIndex ;
							tChildIndex = new long ;
							*tChildIndex = -1 ;
						// Show Class Name
							RefreshItemClassName (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem ,
								tChildIndex
							) ;
						// Show Attributes
							RefreshItemAttributes (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem ,
								tChildIndex
							) ;
						// Show Related Items
							RefreshItemRelatedItems (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem ,
								tChildIndex
							) ;
						// Show Related Lists
							RefreshItemRelatedLists (
								aPosition ,
								aLevel ,
								aDataItem ,
								aTreeItem ,
								tChildIndex
							) ;
						// Clean Up
							delete tChildIndex ;
					} ;

				// ( Layer 3 . 3 . 3 )

					void TreeControlDoc :: RefreshItemClassName ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) {
						CItem* tChild ;
						// Title
							*aChildIndex += 1 ;
							tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
							*aPosition += 1 ;
							Insert (
								// a Position
									*aPosition ,
								// a Level
									aLevel + 1 ,
								// a Direction
									UndefinedDirection ( ) ,
								// a Tree Item
									tChild ,
								// a Text
									"Class :" ,
								// a Item Type
									TitleItemType ( ) ,
								// a DataItem
									0 ,
								// a For Refresh
									TRUE
							) ;
							aLevel += 1 ;
						CString tString ;
						tString = aDataItem -> ClassName ( ) ;
						*aChildIndex += 1 ;
						tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
						*aPosition += 1 ;
						Insert (
							// a Position
								*aPosition ,
							// a Level
								aLevel + 1 ,
							// a Direction
								UndefinedDirection ( ) ,
							// a Tree Item
								tChild ,
							// a Text
								tString ,
							// a Item Type
								ClassNameItemType ( ) ,
							// a DataItem
								0 ,
							// a For Refresh
								TRUE
						) ;
						aLevel -= 1 ;
					} ;
					
					void TreeControlDoc :: RefreshItemAttributes ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) {
						CItem* tChild ;
						CItemAttributes* tItemAttributes ;
						tItemAttributes = aDataItem -> ItemAttributes ( ) ;
						// Title
							if ( tItemAttributes -> ListCount ( ) > 0 ) {
								*aChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										"Attributes :" ,
									// a Item Type
										TitleItemType ( ) ,
									// a DataItem
										0 ,
									// a Related List Item Position
										0 ,
									// a For Refresh
										TRUE
								) ;
								aLevel += 1 ;
							}
						long i ;
						CString tString ;
						for ( i = 0 ; i <= tItemAttributes -> StorageCount ( ) - 1 ; i ++ ) {
							if ( tItemAttributes -> PositionUsed ( i ) == TRUE ) {
								CItemAttribute* tItemAttribute ;
								tItemAttribute = tItemAttributes -> Item ( i ) ;
								tString = tItemAttribute -> Name ( ) + " : " ;
								// Handle String literals in a different way
									if ( tItemAttribute -> Type ( ) == "String" ) {
										CString tStringLiteral ;
										tStringLiteral = tItemAttribute -> Value ;
										tStringLiteral . Replace ( "\"" , "\"\"" ) ;
										tString += "\"" ;
										tString += tStringLiteral ;
										tString += "\"" ;
									}
								else {
									tString += tItemAttribute -> Value ;
								}
								*aChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										AttributeItemType ( ) ,
									// a DataItem
										0 ,
									// a Related List Item Position
										0 ,
									// a For Refresh
										TRUE
								) ;
							}
						}
						if ( tItemAttributes -> ListCount ( ) > 0 ) {
							aLevel -= 1 ;
						}
					} ;

					void TreeControlDoc :: RefreshItemRelatedItems ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) {
						CItem* tChild ;
						CRelatedItems* tRelatedItems ;
						tRelatedItems = aDataItem -> RelatedItems ( ) ;
						// Title
							if ( tRelatedItems -> ListCount ( ) > 0 ) {
								*aChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										"Related Items :" ,
									// a Item Type
										TitleItemType ( ) ,
									// a DataItem
										0 ,
									// a Related List Item Position
										0 ,
									// a For Refresh
										TRUE
								) ;
								aLevel += 1 ;
							}
						long i ;
						CString tString ;
						for ( i = 0 ; i <= tRelatedItems -> StorageCount ( ) -1 ; i ++ ) {
							if ( tRelatedItems -> PositionUsed ( i ) == TRUE ) {
								CRelatedItem* tRelatedItem ;
								tRelatedItem = tRelatedItems -> Item ( i ) ;
								CString tDirection ;
								CItemAttribute* tDirectionAttribute = tRelatedItem -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) ;
								if ( tDirectionAttribute != 0 ) {
									tDirection = tRelatedItem -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value ;
								}
								tString = tRelatedItem -> Name ( ) ;
								*aChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition ,
									// a Level
										aLevel + 1 ,
									// a Direction
										tDirection ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										RelatedItemItemType ( ) ,
									// a Data Item
										tRelatedItem ,
									// a Related List Item Position
										0 ,
									// a For Refresh
										TRUE
								) ;
								// Recursion
									RefreshRelatedItem ( aPosition , aLevel + 1 , tRelatedItem , tChild ) ;
							}
						}
						if ( tRelatedItems -> ListCount ( ) > 0 ) {
							aLevel -= 1 ;
						}
					} ;

					void TreeControlDoc :: RefreshItemRelatedLists ( long* aPosition , long aLevel , CItem* aDataItem , CItem* aTreeItem , long* aChildIndex ) {
						CItem* tChild ;
						CRelatedLists* tRelatedLists ;
						tRelatedLists = aDataItem -> RelatedLists ( ) ;
						// Title
							if ( tRelatedLists -> ListCount ( ) > 0 ) {
								*aChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										"Related Lists :" ,
									// a Item Type
										TitleItemType ( ) ,
									// a DataItem
										0 ,
									// a Related List Item Position
										0 ,
									// a For Refresh
										TRUE
								) ;
								aLevel += 1 ;
							}
						long i ;
						CString tString ;
						for ( i = 0 ; i <= tRelatedLists -> StorageCount ( ) -1 ; i ++ ) {
							if ( tRelatedLists -> PositionUsed ( i ) == TRUE ) {
								CRelatedList* tRelatedList ;
								tRelatedList = tRelatedLists -> Item ( i ) ;
								CString tDirection ;
								CItemAttribute* tDirectionAttribute = tRelatedList -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) ;
								if ( tDirectionAttribute != 0 ) {
									tDirection = tRelatedList -> GenericRelationClass -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value ;
								}
								tString = tRelatedList -> Name ( ) + "  [  " + LongToString ( tRelatedList -> ListCount ( ) ) + "  ]" ;
								*aChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( *aChildIndex ) ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition,
									// a Level
										aLevel + 1 ,
									// a Direction
										tDirection ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										RelatedListItemType ( ) ,
									// a Data Item
										tRelatedList ,
									// a Related List Item Position
										0 ,
									// a For Refresh
										TRUE
								) ;
								// Recursion
									RefreshRelatedList ( aPosition , aLevel + 1 , tRelatedList , tChild ) ;
							}
						}
						if ( tRelatedLists -> ListCount ( ) > 0 ) {
							aLevel -= 1 ;
						}
					} ;

				// ( Layer 3 . 3 . 4 )

					void TreeControlDoc :: RefreshRelatedItem ( long* aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) {
						if ( aTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value != "True" ) { return ; } // New 2007-05-28 21:40
						if ( aRelatedItem -> Item ( ) == 0 ) {
							RefreshRelatedItemWhenNothing (
								aPosition ,
								aLevel ,
								aRelatedItem ,
								aTreeItem
							) ;
						}
						else {
							RefreshItem (
								aPosition ,
								aLevel ,
								aRelatedItem -> Item ( ) ,
								aTreeItem
							) ;
						}
					} ;

					void TreeControlDoc :: RefreshRelatedItemWhenNothing ( long* aPosition , long aLevel , CRelatedItem* aRelatedItem , CItem* aTreeItem ) {
						if ( aTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value != "True" ) { return ; }
						CString tString ;
						CItem* tChild ;
						long tChildIndex = -1 ;
						tString = aRelatedItem -> ClassName ( ) ;
						tChildIndex += 1 ;
						tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( tChildIndex ) ;
						*aPosition += 1 ;
						Insert (
							// a Position
								*aPosition ,
							// a Level
								aLevel + 1 ,
							// a Direction
								UndefinedDirection ( ) ,
							// a Tree Item
								tChild ,
							// a Text
								"( Nothing ) Class : " + tString ,
							// a Item Type
								TitleItemType ( ) ,
							// a DataItem
								0 ,
							// a Related List Item Position
								0 ,
							// a For Refresh
								TRUE
						) ;
					} ;
						
					void TreeControlDoc :: RefreshRelatedList ( long* aPosition , long aLevel , CRelatedList* aRelatedList , CItem* aTreeItem ) {
						if ( aTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value != "True" ) { return ; }
						CString tString ;
						CItem* tChild ;
						long tChildIndex = -1 ;
						// Show Class Name
							tString = "Class : " + aRelatedList -> GenericRelationClass -> ClassName ( ) ;
							tChildIndex += 1 ;
							tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( tChildIndex ) ;
							*aPosition += 1 ;
							Insert (
								// a Position
									*aPosition ,
								// a Level
									aLevel + 1 ,
								// a Direction
									UndefinedDirection ( ) ,
								// a Tree Item
									tChild ,
								// a Text
									tString ,
								// a Item Type
									ClassNameItemType ( ) ,
								// a DataItem
									0 ,
								// a Related List Item Position
									0 ,
								// a For Refresh
									TRUE
							) ;
						long i ;
						for ( i = 0 ; i <= aRelatedList -> StorageCount ( ) - 1 ; i ++ ) {
							// Always add a Tree Child for each position
								tChildIndex += 1 ;
								tChild = aTreeItem -> RelatedLists ( ) -> Item ( "Children" ) -> Item ( tChildIndex ) ;
							if ( aRelatedList -> PositionUsed ( i ) == TRUE ) {
								tString = "[  " + LongToString ( i ) + "  ]" ;
								*aPosition += 1 ;
								Insert (
									// a Position
										*aPosition ,
									// a Level
										aLevel + 1 ,
									// a Direction
										UndefinedDirection ( ) ,
									// a Tree Item
										tChild ,
									// a Text
										tString ,
									// a Item Type
										RelatedListItemItemType ( ) ,
									// a Data Item
										aRelatedList ,
									// a Related List Item Position
										i ,
									// a For Refresh
										TRUE
								) ;
								// Recursion
									RefreshRelatedListItem ( aPosition , aLevel + 1 , aRelatedList , i , tChild ) ;
							}
						}
					} ;

					void TreeControlDoc :: RefreshRelatedListItem ( long* aPosition , long aLevel , CRelatedList* aRelatedList , long aRelatedListItemPosition , CItem* aTreeItem ) {
						if ( aTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value != "True" ) { return ; }
						RefreshItem (
							aPosition ,
							aLevel ,
							aRelatedList -> Item ( aRelatedListItemPosition ) ,
							aTreeItem
						) ;
					} ;
				
		// Layer 5 : Insert & Remove

			void TreeControlDoc :: Insert (
				long aPosition ,
				long aLevel ,
				CString aDirection ,
				CItem* aTreeItem ,
				CString aText ,
				CString aItemType ,
				void* aDataItem ,
				long aRelatedListItemPosition ,
				BOOL aForRefresh 
			) {
				// Conditions
					// Index Valid
						if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) + 1 ) ) { return ; }
				// Add Position
					TreeItemArray . SetSize ( TreeItemArray . GetSize ( ) + 1 ) ;
					RelatedItemArray . SetSize ( RelatedItemArray . GetSize ( ) + 1 ) ;
					RelatedListArray . SetSize ( RelatedListArray . GetSize ( ) + 1 ) ;
					RelatedListItemRelatedListArray . SetSize ( RelatedListItemRelatedListArray . GetSize ( ) + 1 ) ;
					RelatedListItemPositionArray . SetSize ( RelatedListItemPositionArray . GetSize ( ) + 1 ) ;
				// Shift all down
					long i ;
					for ( i = TreeItemArray . GetSize ( ) - 1 ; i >= aPosition + 1 ; i -- ) {
						TreeItemArray . SetAt ( i , TreeItemArray . GetAt ( i - 1 ) ) ;
						RelatedItemArray . SetAt ( i , RelatedItemArray . GetAt ( i - 1 ) ) ;
						RelatedListArray . SetAt ( i , RelatedListArray . GetAt ( i - 1 ) ) ;
						RelatedListItemRelatedListArray . SetAt ( i , RelatedListItemRelatedListArray . GetAt ( i - 1 ) ) ;
						RelatedListItemPositionArray . SetAt ( i , RelatedListItemPositionArray . GetAt ( i - 1 ) ) ;
						// Adapt position attribute of shifted Tree Item.
							TreeItemArray . GetAt ( i ) -> ItemAttributes ( ) -> Item ( "Position" ) -> Value = LongToString ( i ) ;
					}
				// Fill in item
					TreeItemArray . SetAt ( aPosition , aTreeItem ) ;
					if ( aForRefresh == FALSE ) {
						aTreeItem -> ItemAttributes ( ) -> Item ( "Expanded" ) -> Value = "False" ;
					}
					aTreeItem -> ItemAttributes ( ) -> Item ( "Text" ) -> Value = aText ;
					aTreeItem -> ItemAttributes ( ) -> Item ( "Position" ) -> Value = LongToString ( aPosition ) ;
					aTreeItem -> ItemAttributes ( ) -> Item ( "Level" ) -> Value = LongToString ( aLevel ) ;
					aTreeItem -> ItemAttributes ( ) -> Item ( "Item Type" ) -> Value = aItemType ;
					aTreeItem -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value = aDirection ;
					if ( aItemType == RootItemType ( ) ) {
					}
					if ( aItemType == RelatedItemItemType ( ) ) {
						RelatedItemArray . SetAt ( aPosition , ( CRelatedItem* ) aDataItem ) ;
					}
					if ( aItemType == RelatedListItemType ( ) ) {
						RelatedListArray . SetAt ( aPosition , ( CRelatedList* ) aDataItem ) ;
					}
					if ( aItemType == RelatedListItemItemType ( ) ) {
						RelatedListItemRelatedListArray . SetAt ( aPosition , ( CRelatedList* ) aDataItem ) ;
						RelatedListItemPositionArray . SetAt ( aPosition , aRelatedListItemPosition ) ;
					}
			} ;

			void TreeControlDoc :: Remove ( long aPosition ) {
				// Conditions
					// Index Valid
						if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) ) ) { return ; }
				// Shift all up
					long i ;
					for ( i = aPosition ; i <= TreeItemArray . GetSize ( ) - 2 ; i ++ ) {
						TreeItemArray . SetAt ( i , TreeItemArray . GetAt ( i + 1 ) ) ;
						RelatedItemArray . SetAt ( i , RelatedItemArray . GetAt ( i + 1 ) ) ;
						RelatedListArray . SetAt ( i , RelatedListArray . GetAt ( i + 1 ) ) ;
						RelatedListItemRelatedListArray . SetAt ( i , RelatedListItemRelatedListArray . GetAt ( i + 1 ) ) ;
						RelatedListItemPositionArray . SetAt ( i , RelatedListItemPositionArray . GetAt ( i + 1 ) ) ;
						// Adapt position attribute of shifted Tree Item.
							TreeItemArray . GetAt ( i ) -> ItemAttributes ( ) -> Item ( "Position" ) -> Value = LongToString ( i ) ;
					}
				// Remove position
					TreeItemArray . SetSize ( TreeItemArray . GetSize ( ) - 1 ) ;
					RelatedItemArray . SetSize ( RelatedItemArray . GetSize ( ) - 1 ) ;
					RelatedListArray . SetSize ( RelatedListArray . GetSize ( ) - 1 ) ;
					RelatedListItemRelatedListArray . SetSize ( RelatedListItemRelatedListArray . GetSize ( ) - 1 ) ;
					RelatedListItemPositionArray . SetSize ( RelatedListItemPositionArray . GetSize ( ) - 1 ) ;
			} ;

		// Layer 5 : Helpers

			void TreeControlDoc :: InitializeArrays ( ) {
				// Add Tree Root and Data Root to Arrays
					TreeItemArray . SetSize ( 1 ) ;
					RelatedItemArray . SetSize ( 1 ) ;
					RelatedListArray . SetSize ( 1 ) ;
					RelatedListItemRelatedListArray . SetSize ( 1 ) ;
					RelatedListItemPositionArray . SetSize ( 1 ) ;
					TreeItemArray . SetAt ( 0 , TreeRoot ) ;
			} ;

			CString TreeControlDoc :: GetAttribute ( long aPosition , CString aAttributeName ) {
				// Conditions
					if ( ! IndexValid ( aPosition , TreeItemArray . GetSize ( ) ) ) { return "" ; }
				// Return Value
					return TreeItemArray . GetAt ( aPosition ) -> ItemAttributes ( ) -> Item ( aAttributeName ) -> Value ;
			} ;

			CString TreeControlDoc :: TabSpace ( long aLevel ) {
				long i ;
				CString tReturnValue ; 
				tReturnValue = "" ;
				for ( i = 0 ; i <= aLevel - 1 ; i ++ ) {
					// tReturnValue = tReturnValue + "    " ;
					tReturnValue = tReturnValue + "      " ;
				}
				return tReturnValue ;
			} ;

			CString TreeControlDoc :: LongToString ( long aValue ) {
				CString tString ;
				tString = "" ;
				tString.Format ( "%d" , aValue ) ;
				return tString ;
			} ;

			CString TreeControlDoc :: ExpansionSymbol ( BOOL aExpanded ) {
				if ( aExpanded == TRUE ) {
					return " -  " ;
				}
				else {
					return "+  " ;
				}
			} ;

		// Base Class Event Procedures
		
			BOOL TreeControlDoc :: OnNewDocument ( ) {
				if ( ! CDocument :: OnNewDocument ( ) ) {
					return FALSE ;
				}
				return TRUE;
			}


	// View

		// Constructor & Destructor

			TreeControl :: TreeControl ( ) : CFormView ( TreeControl :: IDD ) {
				//{{AFX_DATA_INIT(TreeControl)
					// NOTE: the ClassWizard will add member initialization here
				//}}AFX_DATA_INIT
			}

			TreeControl :: ~TreeControl ( ) {
			}

		// Private Properties

			TreeControlDoc* TreeControl :: Document ( ) {
				return ( TreeControlDoc* ) this -> GetDocument ( ) ;
			} ;

			long TreeControl :: CurrentLine ( ) {
				int tSelectionStart ;
				int tSelectionEnd ;
				int tLine ;
				TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
				tLine = TextBox . LineFromChar ( tSelectionStart ) ;
				return (long) tLine ;
			} ;

			BOOL TreeControl :: Expanded ( ) {
				return Document ( ) -> Expanded ( CurrentLine ( ) ) ;
			} ;

		// Private Methods

			void TreeControl :: Fill ( ) {
				int tSelectionStart ;
				int tSelectionEnd ;
				int tVerticalScrollPosition ;
				// I can't maintain the horizontal scroll position. Vertical was already tricky.
				tVerticalScrollPosition = TextBox . GetScrollPos ( SB_VERT ) ;
				TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
				TextBox . Clear ( ) ;
				TextBox . SetWindowText ( Document ( ) -> GetText ( ) ) ;
				// You do see a flicker between SetWindowText and LineScroll
				TextBox . LineScroll ( tVerticalScrollPosition ) ;
				TextBox . SetSel ( tSelectionStart , tSelectionEnd ) ;
			} ;	

			void TreeControl :: Expand ( ) {
				long tExpansionBottomLine ;
				tExpansionBottomLine = Document ( ) -> Expand ( CurrentLine ( ) ) ;
				Fill ( ) ;
				// Unbelievably complicated way to make all expanded lines visible
					// Get Caret Position
						int tSelectionStart ;
						int tSelectionEnd ;
						TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
					// Get Text Box Position
						LPRECT tClientRect = new RECT ;
						TextBox . GetClientRect ( tClientRect ) ;
					// Assume Line Height
						int tLineHeight = 13 ;
					// Calculate Visible Lines
						int tVisibleLinesInTextBox = ( tClientRect -> bottom + 1) / tLineHeight ;
					// Get Character Position of Top Left Character
						CPoint tPoint ;
						tPoint . x = 0 ;
						tPoint . y = 0 ;
						int tTopLeftLineAndChar = TextBox . CharFromPos ( tPoint ) ;
					// Get Top Line
						int TextBoxTopLine = HIWORD ( tTopLeftLineAndChar ) ;
					// Calculate Bottom Line
						int tTextBoxBottomLine = TextBoxTopLine + tVisibleLinesInTextBox - 1 ;
					// If Text Box Bottom Line smaller than Expansion Bottom Line
						if ( tTextBoxBottomLine < tExpansionBottomLine ) {
							// Tiny bug :
								// Somehow this 'if' is entered also when the expanded content just 
								// fits with the current scroll position, but then the tPositionsToScroll stays zero.
							// Calculate Positions To Scroll
								int tDesiredScrollPosition = tExpansionBottomLine - tVisibleLinesInTextBox + 1 ;
								int tCurrentScrollPosition = TextBox . GetScrollPos ( SB_VERT) ;
								int tPositionsToScroll = tDesiredScrollPosition - tCurrentScrollPosition ;
							// Scroll
								TextBox . LineScroll ( tPositionsToScroll ) ;
						}
			} ;

			void TreeControl :: Collapse ( ) {
				Document ( ) -> Collapse ( CurrentLine ( ) ) ;
				Fill ( ) ;
			} ;
			
			BOOL TreeControl :: CollapseSymbolHitTest ( ) {
				// Comment :
					// This procedure has a flaw.
					// I can't get the character position within the current line.
					// Otherwise I could test for the exact position the expansion symbol is at.
					// But now I can only look if a + or - is AROUND the selected text.
					// That means that if there's a + or - character used for another purpose than the expansion symbol,
					// the item is expanded or collapsed too if you click on a + or - that doesn't represent an expansion symbol.
				// Declarations
				// Get Text
					CString tText ;
					TextBox . GetWindowText ( tText ) ;
				// Get Selection
					int tSelectionStart ;
					int tSelectionEnd ;
					TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
				// Search For Plus
					// Set Search Start & End
						int tPlusSearchStart ;
						int tPlusSearchEnd ;
						tPlusSearchStart = tSelectionStart - 1 ;
						if ( tPlusSearchStart < 0 ) { tPlusSearchStart = 0 ; }
						tPlusSearchEnd = tSelectionEnd + 0 ;
						if ( tPlusSearchEnd > tText . GetLength ( ) - 1 ) { tPlusSearchEnd = tText . GetLength ( ) - 1 ; }
					// Get Search Text Section 
						CString tPlusSearchTextSection ;
						tPlusSearchTextSection = tText . Mid ( tPlusSearchStart , tPlusSearchEnd - tPlusSearchStart + 1 ) ;
					// Return True if + is present
						if ( tPlusSearchTextSection . Find ( "+" ) != -1 ) {
							return TRUE ;
						}
				// Search For Minus
					// Set Search Start & End
						int tMinusSearchStart ;
						int tMinusSearchEnd ;
						tMinusSearchStart = tSelectionStart - 1 ;
						if ( tMinusSearchStart < 0 ) { tMinusSearchStart = 0 ; }
						tMinusSearchEnd = tSelectionEnd + 1 ;
						if ( tMinusSearchEnd > tText . GetLength ( ) - 1 ) { tMinusSearchEnd = tText . GetLength ( ) - 1 ; }
					// Get Search Text Section 
						CString tMinusSearchTextSection ;
						tMinusSearchTextSection = tText . Mid ( tMinusSearchStart , tMinusSearchEnd - tMinusSearchStart + 1 ) ;
					// Return True if - is present
						if ( tMinusSearchTextSection . Find ( "-" ) != -1 ) {
							return TRUE ;
						}
				// Else Return False
					return FALSE ;
			} ;
				
		// Event Procedures ( / Message Mappings )

			void TreeControl :: OnRefreshButton() {
				Document ( ) -> Refresh ( 0 ) ;
				Fill ( ) ;
			} ;

		// Base Class Event Procedures ( / Overrides )

			void TreeControl :: OnInitialUpdate()  {
				// Call Base
					CFormView :: OnInitialUpdate ( ) ;
				// Quick Fix : To Fill OnLoad I use OnInitialUpdate, because I can't find anything that better represents OnLoad.
					Fill ( ) ;
			} ;

			BOOL TreeControl::PreTranslateMessage(MSG* pMsg) {
				// Control Text Box User Input
					if ( GetFocus ( ) == ( CWnd* ) & TextBox ) { 
						// Keyboard
							if ( pMsg -> message == WM_KEYDOWN ) { 
								switch ( pMsg -> wParam ) {
									case 0x0000000d : // Enter ( lookup constant )
										if ( Expanded ( ) ) { Collapse ( ) ; } else { Expand ( ) ; }
										return FALSE ;
									case 0x00000026 : // Allow arrow up
										return FALSE ;
									case 0x00000028 : // Allow arrow down
										return FALSE ;
									case 0x00000027 : // Allow arrow right
										return FALSE ;
									case 0x00000025 : // Allow arrow left
										return FALSE ;
									default : // Cancel other keyboard events.
										return TRUE ;
								}
							}
						// Mouse
							// Left Button Up
								if ( pMsg -> message == WM_LBUTTONUP ) {
									if ( CollapseSymbolHitTest ( ) == TRUE ) {
										if ( Expanded ( ) ) { Collapse ( ) ; } else { Expand ( ) ; }
									}
								}
							// Double Click
								if ( pMsg -> message == WM_LBUTTONDBLCLK ) {
									if ( CollapseSymbolHitTest ( ) == FALSE ) { // Don't proces double click on expansion symbol
										if ( Expanded ( ) ) { Collapse ( ) ; } else { Expand ( ) ; }
									}
									return TRUE ;
								}
					} 
				return CFormView :: PreTranslateMessage ( pMsg ) ;
			} ;

			void TreeControl :: OnPaint ( ) {
				CPaintDC dc ( this ) ; // device context for painting
				RECT tTreeControlRectange ;
				GetClientRect ( & tTreeControlRectange ) ;
				TextBox . MoveWindow ( 0 , 0 , tTreeControlRectange . right , tTreeControlRectange . bottom - 20 ) ;
				RefreshButton . MoveWindow ( tTreeControlRectange.right - 50 , tTreeControlRectange.bottom - 19 , 50 , 19 ) ;
			} ;
