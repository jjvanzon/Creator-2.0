//
//	Creator . ccc Creator
//
//		Usable in C++, in C++ objects, with C++ classes for a structure
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Saturday, March 18, 2007 - Wednesday, April 11, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"


// Typedefs

	// Original
	
		// typedef void ( PASCAL *SetObjectProcedure ) ( void* aObject ) ; // EXAMPLE !!! DON'T DELETE !!! (Unless you have a WORKING other example)
		// typedef CString ( PASCAL *AttributeOverrideGet ) ( CItemAttribute* aThis ) ;
		// typedef void ( PASCAL *AttributeOverrideSet ) ( CItemAttribute* aThis , CString aValue ) ;
	
	// Test Library

		typedef void ( PASCAL *SetObjectProcedure ) ( void* aObject ) ; // EXAMPLE !!! DON'T DELETE !!! (Unless you have a WORKING other example)

	// Method Library

		// extern void PASCAL EXPORT ExecuteMethod ( CItem* aThis )

			typedef void ( PASCAL *ItemExecuteMethod ) ( CItemMethod* aThis ) ;

	// Attribute Method Library

		// extern CString PASCAL EXPORT OverrideGet ( CItemAttribute* aThis )

			typedef CString ( PASCAL *AttributeOverrideGet ) ( CItemAttribute* aThis , BOOL* aOverridden ) ;

		// extern void PASCAL EXPORT OverrideSet ( CItemAttribute* aThis , CString aValue )

			typedef void ( PASCAL *AttributeOverrideSet ) ( CItemAttribute* aThis , BOOL* aOverridden , CString aValue ) ;

	// Related Item Method Library

		// extern CItem* PASCAL EXPORT OverrideItemGet ( CRelatedItem* aThis )

			typedef CItem* ( PASCAL *RelatedItemOverrideItemGet ) ( CRelatedItem* aThis , BOOL* aOverridden ) ;

		// extern void PASCAL EXPORT OverrideItemSet ( CRelatedItem* aThis , CItem* aValue )

			typedef void ( PASCAL *RelatedItemOverrideItemSet ) ( CRelatedItem* aThis , BOOL* aOverridden , CItem* aValue ) ;

	// Related List Method Library

		// extern CItem* PASCAL EXPORT OverrideItemGet ( CRelatedList* aThis , long aIndex )

			typedef CItem* ( PASCAL *RelatedListOverrideItemGet ) ( CRelatedList* aThis , BOOL* aOverridden , long aIndex ) ;

		// extern void PASCAL EXPORT OverrideItemSet ( CRelatedList* aThis , long aIndex , CItem* aValue )

			typedef void ( PASCAL *RelatedListOverrideItemSet ) ( CRelatedList* aThis , BOOL* aOverridden , long aIndex , CItem* aValue ) ;

		// extern void PASCAL EXPORT OverrideInitializeItem ( CRelatedList* aThis , long aIndex )

			typedef void ( PASCAL *RelatedListOverrideInitializeItem ) ( CRelatedList* aThis , BOOL* aOverridden , long aIndex ) ;



// Classes


	// Structure

		// Constructor & Destructor

			CStructure :: CStructure ( ) {
				sClasses = new CClasses ;
				sRelations = new CRelations ;
			} ;

			CStructure :: ~CStructure ( ) {
				// The order matters here, because the classes have to exist in destroying Relations . Item [ ] . Relation Class A and B
				delete sRelations ;
				delete sClasses ;
			} ;
				
		// Public
			
			// Properties

				CClasses* CStructure :: Classes ( ) {
					return sClasses ;
				} ;

				CRelations* CStructure :: Relations ( ) {
					return sRelations ;
				} ;

				
		// Classes

			// Constructor & Destructor
				
				CClasses :: CClasses ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				CClasses :: ~CClasses ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					CClass* CClasses :: Item ( long aIndex ) {
						return ( CClass* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					CClass* CClasses :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> ClassName == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

				// Methods
					
					CClass* CClasses :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void CClasses :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CClass ) ;
				} ;

				void CClasses :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Class
				
				// Constructor & Destructor
					
					CClass :: CClass ( ) {
						sClassAttributes = new CClassAttributes ;
						sRelatedClasses = new CRelatedClasses ;
					} ;
						
					CClass :: ~CClass ( ) {
						delete sClassAttributes ;
						delete sRelatedClasses ;
					} ;

				// Public

					// Properties

						CClassAttributes* CClass :: ClassAttributes ( ) {
							return sClassAttributes ;
						} ;

						CRelatedClasses* CClass :: RelatedClasses ( ) {
							return sRelatedClasses ;
						} ;

                // Class Atributes
		
					// Constructor & Destructor

						CClassAttributes :: CClassAttributes ( ) {
							// Setup Event Sinks
								// Base
									BaseEventsObject = new BaseEvents ;
									BaseEventsObject -> Parent = this ;
									HoleListInMemory :: EventSink ( BaseEventsObject ) ;
						} ;

						CClassAttributes :: ~CClassAttributes ( ) {
							Clear ( ) ;
							delete BaseEventsObject ;
							HoleListInMemory :: EventSink ( 0 ) ;
						} ;

					// Public

						// Properties

							CClassAttribute* CClassAttributes :: Item ( long aIndex ) {
								return ( CClassAttribute* ) HoleListInMemory :: Item ( aIndex ) ;
							} ;

							CClassAttribute* CClassAttributes :: Item ( CString aName ) {
								long i ;
								for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
									if ( PositionUsed ( i ) == TRUE ) {
										if ( Item ( i ) != 0 ) { 
											if ( Item ( i ) -> Name == aName ) {
												return Item ( i ) ;
											}
										}
									}
								}
								return 0;
							} ;
							
						// Methods
							
							CClassAttribute* CClassAttributes :: Add ( ) {
								return Item ( HoleListInMemory :: Add ( ) ) ;
							} ;

					// Event Procedures

						void CClassAttributes :: BaseEvents :: InitializeItem ( long aIndex ) {
							Parent -> HoleListInMemory :: Item ( aIndex , new CClassAttribute ) ;
						} ;

						void CClassAttributes :: BaseEvents :: TerminateItem ( long aIndex ) {
							delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
						} ;

					// Class Atribute
						
						// No Definitions



				// Related Classes
					
					CRelationClass* CRelatedClasses :: Item ( long aIndex ) {
						return ( CRelationClass* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;



		// Relations

			// Constructor & Destructor
				
				CRelations :: CRelations ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				CRelations :: ~CRelations ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					CRelation* CRelations :: Item ( long aIndex ) {
						return ( CRelation* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;
						
				// Methods
					
					CRelation* CRelations :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Private
				
				// Event Procedures

					void CRelations :: BaseEvents :: InitializeItem ( long aIndex ) {
						Parent -> HoleListInMemory :: Item ( aIndex , new CRelation ) ;
					} ;

					void CRelations :: BaseEvents :: TerminateItem ( long aIndex ) {
						Parent -> Item ( aIndex ) -> DeregisterRelationInClasses ( ) ;
						delete Parent -> HoleListInMemory :: Item ( aIndex ) ;
					} ;



            // Relation

				// Constructor & Destructor

					CRelation :: CRelation ( ) {
						// Create Objects
							sRelationClassA = new CRelationClass ;
							sRelationClassB = new CRelationClass ;
						// Initialize Object Members
							// Relation Class A
								RelationClassA ( ) -> IdInRelation ( 0 ) ;
								RelationClassA ( ) -> Relation ( this ) ;
							// Relation Class B
								RelationClassB ( ) -> IdInRelation ( 1 ) ;
								RelationClassB ( ) -> Relation ( this ) ;
					} ;

					CRelation :: ~CRelation ( ) {
						DeregisterRelationInClasses ( ) ;
						delete sRelationClassA ;
						delete sRelationClassB ;
					} ;

				// Public
					
					// Properties
							
						CRelationClass* CRelation :: RelationClassA ( ) {
							return sRelationClassA ;
						} ;

						CRelationClass* CRelation :: RelationClassB ( ) {
							return sRelationClassB ;
						} ;
							
				// Friend
					
					// Methods
						
						void CRelation :: DeregisterRelationInClasses ( ) { // Private, accessed by friend CRelations :: BaseEvents
							RelationClassA ( ) -> DeregisterRelationInClass ( ) ;
							RelationClassB ( ) -> DeregisterRelationInClass ( ) ;
						}



                // Relation Class

					// Constructor & Destructor

						CRelationClass :: CRelationClass ( ) {
							Plural = FALSE ;
							IdInRelation ( -1 ) ;
							IdInClassRelatedClasses ( -1 ) ;
							sClass = 0 ;
						} ;

					// Public
						
						// Properties

							CClass* CRelationClass :: Class ( ) {
								return sClass ;
							} ;

							void CRelationClass :: Class ( CClass* aValue ) {
								// Reflect Relations in Class.RelatedClasses
									DeregisterRelationInClass ( ) ;
								// Assign
									sClass = aValue ;
								// Reflect Relations in Class.RelatedClasses
									RegisterRelationInClass ( ) ;
							} ;

							long CRelationClass :: IdInRelation ( ) {
								return sIdInRelation ;
							} ;
							void CRelationClass :: IdInRelation ( long aValue ) { // Private, accessed by friend Relation
								sIdInRelation = aValue ;
							} ;

							long CRelationClass :: IdInClassRelatedClasses ( ) {
								return sIdInClassRelatedClasses ;
							} ;
							void CRelationClass :: IdInClassRelatedClasses ( long aValue ) { // Private
								sIdInClassRelatedClasses = aValue ;
							} ;

							CRelation* CRelationClass :: Relation ( ) {
								return sRelation ;
							} ;
							void CRelationClass :: Relation ( CRelation* aValue ) { // Private, accessed by friend Relation
								sRelation = aValue ;
							} ;

					// Friend
						
						// Methods
									
							void CRelationClass :: DeregisterRelationInClass ( ) {
								if ( ! Class ( ) == 0 ) {
									Class ( ) -> RelatedClasses ( ) -> Remove ( IdInClassRelatedClasses ( ) ) ;
								}
							} ;
							void CRelationClass :: RegisterRelationInClass ( ) {
								if ( ! Class ( ) == 0 ) {
									switch ( IdInRelation ( ) ) {
										case 0 :
											IdInClassRelatedClasses ( Class ( ) -> RelatedClasses ( ) -> Add ( Relation ( ) -> RelationClassB ( ) ) ) ;
											break ;
										case 1 :
											IdInClassRelatedClasses ( Class ( ) -> RelatedClasses ( ) -> Add ( Relation ( ) -> RelationClassA ( ) ) ) ;
											break ;
									}
								}
							} ;



	// Item

		// Constructor & Destructor
			
			CItem :: CItem ( ) {
				// Create Objects
					sItemAttributes = new CItemAttributes ;
					sRelatedItems = new CRelatedItems ;
					sRelatedLists = new CRelatedLists ;
					sItemMethods = new CItemMethods ;
				// Initialize Pointers
					sClass = 0 ;
					sGenericClass = 0 ;
				// Assign Parents
					ItemAttributes ( ) -> ParentItem ( this ) ;
					RelatedItems ( ) -> ParentItem ( this ) ;
					RelatedLists ( ) -> ParentItem ( this ) ;
					ItemMethods ( ) -> ParentItem ( this ) ;
			} ;
			
			CItem :: ~CItem ( ) {
				delete sItemAttributes ;
				delete sRelatedItems ;
				delete sRelatedLists ;
				delete sItemMethods ;
			} ;

		// Public
			
			// Properties

				CClass* CItem :: Class ( ) {
					return sClass ;
				} ;
				void CItem :: Class ( CClass* aValue ) {
					// Declarations
						long i ;
					// Functionality
						// Assign 
							sClass = aValue ;
						// Clear
							ItemAttributes ( ) -> Clear ( ) ;
							RelatedItems ( ) -> Clear ( ) ;
							RelatedLists ( ) -> Clear ( ) ;
						// Traverse Class Attributes
							CClassAttribute* tClassAttribute ;
							CItemAttribute* tItemAttribute ;
							for ( i = 0 ; i <= Class ( ) -> ClassAttributes ( ) -> StorageCount ( ) - 1 ; i ++ ) {
								if ( Class ( ) -> ClassAttributes ( ) -> PositionUsed ( i ) == TRUE ) {
									tClassAttribute = Class ( ) -> ClassAttributes ( ) -> Item ( i ) ;
									tItemAttribute = ItemAttributes ( ) -> Add ( ) ;
									tItemAttribute -> ClassAttribute = tClassAttribute ;
									tItemAttribute -> Name ( tClassAttribute -> Name ) ;
								}
							}
						// Traverse Class Related Items
							CRelationClass* tRelationClass ;
							CRelatedList* tRelatedList ;
							CRelatedItem* tRelatedItem ;
							for ( i = 0 ; i <= Class ( ) -> RelatedClasses ( ) -> StorageCount ( ) - 1 ; i ++ ) {
								if ( Class ( ) -> RelatedClasses ( ) -> PositionUsed ( i ) == TRUE ) {
									tRelationClass = Class ( ) -> RelatedClasses ( ) -> Item ( i ) ;
									switch ( tRelationClass -> Plural ) {
										case TRUE :
											tRelatedList = RelatedLists ( ) -> Add ( ) ;
											tRelatedList -> RelationClass = tRelationClass ;
											tRelatedList -> Name ( tRelationClass -> Name ) ;
											break ;
										case FALSE :
											tRelatedItem = RelatedItems ( ) -> Add ( ) ;
											tRelatedItem -> RelationClass = tRelationClass ;
											tRelatedItem -> Name ( tRelationClass -> Name ) ;
											break ;
									}
								}
							}
				} ;

				CItem* CItem :: GenericClass ( ) {
					return sGenericClass ;
				} ;
				void CItem :: GenericClass ( CItem* aValue ) {
					// Declarations
						long i ;
						CItemAttribute* tNameAttribute = 0 ;
						CString tName ;
						CItemAttribute* tItemAttribute = 0 ;
					// Functionality
						// Assign 
							sGenericClass = aValue ;
						// Clear
							ItemAttributes ( ) -> Clear ( ) ;
							RelatedItems ( ) -> Clear ( ) ;
							RelatedLists ( ) -> Clear ( ) ;
						// Get Generic Class Attributes Reference
							CRelatedList* tGenericClassAttributes = 0 ;
							tGenericClassAttributes = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
							if ( tGenericClassAttributes == 0 ) {
								tGenericClassAttributes = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
							}
							if ( tGenericClassAttributes == 0 ) {
								tGenericClassAttributes = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "Class Attributes" ) ;
							}
						// Traverse Class Attributes
							CItem* tGenericClassAttribute = 0 ;
							for ( i = 0 ; i <= tGenericClassAttributes -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tGenericClassAttributes -> PositionUsed ( i ) == TRUE ) {
									tGenericClassAttribute = ( CItem* ) tGenericClassAttributes -> Item ( i ) ;
									// Get Name Attribute Reference
										tNameAttribute = ( CItemAttribute* ) tGenericClassAttribute -> ItemAttributes ( ) -> Item ( "gcc Name" ) ;
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( CItemAttribute* ) tGenericClassAttribute -> ItemAttributes ( ) -> Item ( "ggc Name" ) ;
										}
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( CItemAttribute* ) tGenericClassAttribute -> ItemAttributes ( ) -> Item ( "Name" ) ;
										}
									tName = tNameAttribute -> Value ( ) ;
									tItemAttribute = ItemAttributes ( ) -> Add ( ) ;
									tItemAttribute -> GenericClassAttribute ( tGenericClassAttribute ) ;
									tItemAttribute -> Name ( tName ) ;
								}
							}
						// Get Generic Relation Classes Reference
							CRelatedList* tGenericRelationClasses = 0 ;
							tGenericRelationClasses = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
							if ( tGenericRelationClasses == 0 ) {
								tGenericRelationClasses = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
							}
							if ( tGenericRelationClasses == 0 ) {
								tGenericRelationClasses = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "Related Classes" ) ;
							}
						// Traverse Related Classes
							CItem* tGenericRelationClass = 0 ;
							CItemAttribute* tPluralAttribute = 0 ;
							CString tPlural ;
							CRelatedList* tRelatedList = 0 ;
							CRelatedItem* tRelatedItem = 0 ;
							for ( i = 0 ; i <= tGenericRelationClasses -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tGenericRelationClasses -> PositionUsed ( i ) == TRUE ) {
									tGenericRelationClass = ( CItem* ) tGenericRelationClasses -> Item ( i ) ;
									// Get Plural Attribute Reference
										tPluralAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "gcc Plural" ) ;
										if ( tPluralAttribute == 0 ) {
											tPluralAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "ggc Plural" ) ;
										}
										if ( tPluralAttribute == 0 ) {
											tPluralAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "Plural" ) ;
										}
									// Get Plural Value
										tPlural = tPluralAttribute -> Value ( ) ;
									// Get Name Attribute Reference
										tNameAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "gcc Name" ) ;
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "ggc Name" ) ;
										}
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "Name" ) ;
										}
									// Get Name Value
										tName = tNameAttribute -> Value ( ) ;
									// If Plural
										if ( tPlural == "True" ) {
											// Add Related List
												tRelatedList = RelatedLists ( ) -> Add ( ) ;
												tRelatedList -> GenericRelationClass ( tGenericRelationClass ) ;
												tRelatedList -> Name ( tName ) ;
										}
									// If Not Plural
										// if ( tPlural == "False" ) { // Generic Creator does not define default values yet, so tPlural will be "" in many cases.
										else {
											// Add Related Item
												tRelatedItem = RelatedItems ( ) -> Add ( ) ;
												tRelatedItem -> GenericRelationClass ( tGenericRelationClass ) ;
												tRelatedItem -> Name ( tName ) ;
										}
								}
							}
						// Methods (New 2007-09-09) 
							// Kept separated, because it's a different deal here, because methods are only declared in the highest structure layer.
							CRelatedList* tGenericClassMethods = GenericClass ( ) -> RelatedLists ( ) -> Item ( "Class Methods" ) ;
							if ( tGenericClassMethods != 0 ) {
								CItem* tGenericClassMethod = 0 ;
								CItemMethod* tItemMethod = 0 ;
								for ( i = 0 ; i <= tGenericClassMethods -> StorageCount ( ) - 1 ; i ++ ) {
									if ( tGenericClassMethods -> PositionUsed ( i ) == TRUE ) {
										tGenericClassMethod = ( CItem* ) tGenericClassMethods -> Item ( i ) ;
										// Get Name Attribute
											tNameAttribute = tGenericClassMethod -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if ( tNameAttribute == 0 ) { continue ; }
										// Get Name
											tName = tNameAttribute -> Value ( ) ;
										// Add Item Method
											tItemMethod = ItemMethods ( ) -> Add ( ) ;
											tItemMethod -> GenericClassMethod ( tGenericClassMethod ) ;
											tItemMethod -> Name ( tName ) ;
									}
								}
							}
				} ;

				CItemAttributes* CItem :: ItemAttributes ( ) {
					return sItemAttributes ;
				} ;

				CRelatedItems* CItem :: RelatedItems ( ) {
					return sRelatedItems ;
				} ;

				CRelatedLists* CItem :: RelatedLists ( ) {
					return sRelatedLists ;
				} ;

				CItemMethods* CItem :: ItemMethods ( ) {
					return sItemMethods ;
				} ;
					
				CString CItem :: ClassName ( ) {
					// Use C++ Usable Class
						if ( Class ( ) != 0 ) {
							return Class ( ) -> ClassName ;
						}
					// Use Generic Class
						if ( GenericClass ( ) != 0 ) {
							CItemAttribute* tItemAttribute ;
							// Look in gcc layer
								tItemAttribute = GenericClass ( ) -> ItemAttributes ( ) -> Item ( "gcc Class Name" ) ;
							// Or else in ggc layer
								if ( tItemAttribute == 0 ) {
									tItemAttribute = GenericClass ( ) -> ItemAttributes ( )-> Item ( "ggc Class Name" ) ;
								}
							// Or else in ggg layer
								if ( tItemAttribute == 0 ) {
									tItemAttribute = GenericClass ( ) -> ItemAttributes ( ) -> Item ( "Class Name" ) ;
								}
							// Return Attribute Value If Not Nothing
								if ( tItemAttribute != 0 ) {
									return tItemAttribute -> Value ( ) ;
								}
						}
					return "" ;
				} ;

        // Item Atributes

			// Constructor & Destructor

				CItemAttributes :: CItemAttributes ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				CItemAttributes :: ~CItemAttributes ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					CItemAttribute* CItemAttributes :: Item ( long aIndex ) {
						return ( CItemAttribute* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					CItemAttribute* CItemAttributes :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> Name ( ) == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

					CItem* CItemAttributes :: ParentItem ( ) {
						return sParentItem ;
					} ;
					void CItemAttributes :: ParentItem ( CItem* aValue ) { // Private, accessed by friend CItem
						sParentItem = aValue ;
					} ;
											
					CString CItemAttributes :: ParentItemName ( ) {
						return ParentItem ( ) -> ClassName ( ) ;
					} ;

				// Methods
					
					CItemAttribute* CItemAttributes :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void CItemAttributes :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CItemAttribute ) ;
					Parent -> Item ( aIndex ) -> ItemAttributes ( Parent ) ;
				} ;

				void CItemAttributes :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Item Attribute
				
				// Constructor & Destructor
					
					CItemAttribute :: CItemAttribute ( ) {
						// Initialize Pointers
							ClassAttribute = 0 ;
							sGenericClassAttribute = 0 ;
							MethodLibraryHandle = 0 ;
						// Test Loading a Library with Custom Code
							/* 
							HMODULE tModuleHandle ;
							tModuleHandle = LoadLibrary ( "..\\Example Method Library\\Debug\\ExampleMethodLibrary.dll" ) ;
							SetObjectProcedure tProcedureAddress ;
							tProcedureAddress = ( SetObjectProcedure ) GetProcAddress ( tModuleHandle , "SetObject" ) ;
							( tProcedureAddress ) ( this ) ;
							FreeLibrary ( tModuleHandle ) ;
							*/
					} ;

					CItemAttribute :: ~CItemAttribute ( ) {
						GenericClassAttribute ( 0 ) ; // Set to 0, to Unload DLL's
					} ;

				// Public
					
					// Properties

						CString CItemAttribute :: Value ( ) {
							// Override
								if ( MethodLibraryHandle != 0 ) {
									// Declare Return Values
										CString tReturnValue ;
										BOOL tOverridden = FALSE ;
									// Call DLL Function
										try {
											tReturnValue = ( OverrideGetProcedureAddress ) ( this , &tOverridden ) ;
										}
										catch ( ... ) {
										}
									// If Overridden Then Return
										if ( tOverridden == TRUE ) {
											return tReturnValue ;
										}
								}
							// Not Overridden
								return ValueBase ( ) ;
						} ;
						CString CItemAttribute :: ValueBase ( ) {
							return sValue ;
						} ;
						void CItemAttribute :: Value ( CString aValue ) {	
							// Override
								if ( MethodLibraryHandle != 0 ) {
									// Declare Return Values
										BOOL tOverridden = FALSE ;
									// Call DLL Function
										try {
											( OverrideSetProcedureAddress ) ( this , &tOverridden , aValue ) ;
										}
										catch ( ... ) {
										}
									// If Overridden Then Return
										if ( tOverridden == TRUE ) {
											return ;
										}
								}
							// Not Overridden
								ValueBase ( aValue ) ;
						} ;
						void CItemAttribute :: ValueBase ( CString aValue ) {
							sValue = aValue ;
						} ;

						CItem* CItemAttribute :: GenericClassAttribute ( ) {
							return sGenericClassAttribute ;
						} ;
						void CItemAttribute :: GenericClassAttribute ( CItem* aValue ) {	
							// Free Method Library
								if ( sGenericClassAttribute != 0 ) {
									if ( MethodLibraryHandle != 0 ) {
										FreeLibrary ( MethodLibraryHandle ) ;
										MethodLibraryHandle = 0 ;
									}
								}
							// Assign Value
								sGenericClassAttribute = aValue ;
							// Load Method Library
								if ( sGenericClassAttribute != 0 ) {
									// Compose path from module path, module name, class name and attribute name
										// Get Attribute Name
											CItemAttribute* tAttributeNameAttribute = sGenericClassAttribute -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if ( tAttributeNameAttribute == 0 ) { return ; }
											CString tAttributeName = tAttributeNameAttribute -> Value ( ) ;
										// Get Class Item
											CRelatedItem* tClassRelatedItem = sGenericClassAttribute -> RelatedItems ( ) -> Item ( "Class" ) ;
											if  ( tClassRelatedItem == 0 ) { return ; }
											CItem* tClassItem = tClassRelatedItem -> Item ( ) ;
											if  ( tClassItem == 0 ) { return ; }
										// Get Class Name
											CItemAttribute* tClassNameAttribute = tClassItem -> ItemAttributes ( ) -> Item ( "Class Name" ) ;
											if  ( tClassNameAttribute == 0 ) { return ; }
											CString tClassName = tClassNameAttribute -> Value ( ) ;
										// Get Structure Item
											CRelatedItem* tStructureRelatedItem = tClassItem -> RelatedItems ( ) -> Item ( "Structure" ) ;
											if  ( tStructureRelatedItem == 0 ) { return ; }
											CItem* tStructureItem = tStructureRelatedItem -> Item ( ) ;
											if  ( tStructureItem == 0 ) { return ; }
										// Get Module Name
											CItemAttribute* tStructureNameAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if  ( tStructureNameAttribute == 0 ) { return ; }
											CString tModuleName = tStructureNameAttribute -> Value ( ) ;
										// Get Module Path
											CItemAttribute* tStructureFolderAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Folder" ) ;
											if  ( tStructureFolderAttribute == 0 ) { return ; }
											CString tModuleFolder = tStructureFolderAttribute -> Value ( ) ;
										// Compose DLL path
											CString tLibraryPath = tModuleFolder + "\\" + tModuleName + "  .  " + tClassName + "  .  " + tAttributeName + ".dll" ;
									// If DLL File Exists, load the module
										if ( FileExists ( tLibraryPath ) == TRUE ) {
											MethodLibraryHandle = LoadLibrary ( tLibraryPath ) ;	
											OverrideGetProcedureAddress = ( AttributeOverrideGet ) GetProcAddress ( MethodLibraryHandle , "OverrideGet" ) ;
											OverrideSetProcedureAddress = ( AttributeOverrideSet ) GetProcAddress ( MethodLibraryHandle , "OverrideSet" ) ;
										}
								}
						} ;

						CString CItemAttribute :: Type ( ) {
							if ( GenericClassAttribute ( ) != 0 ) {
								CItemAttribute* tAttribute ;
								tAttribute = GenericClassAttribute ( ) -> ItemAttributes ( ) -> Item ( "Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ( ) ;
								}
								tAttribute = GenericClassAttribute ( ) -> ItemAttributes ( ) -> Item ( "ggg Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ( ) ;
								}
								tAttribute = GenericClassAttribute ( ) -> ItemAttributes ( ) -> Item ( "ggc Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ( ) ;
								}
								tAttribute = GenericClassAttribute ( ) -> ItemAttributes ( ) -> Item ( "gcc Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ( ) ;
								}
							}
							if ( ClassAttribute != 0 ) {
								return ClassAttribute -> Type ;
							}
							return "" ;
						} ;

						CString CItemAttribute :: Name ( ) {
							return sName ;
						} ;
						void CItemAttribute :: Name ( CString aValue ) { // Private, accessed by friend CItem
							sName = aValue ;
						} ;

						CItemAttributes* CItemAttribute :: ItemAttributes ( ) {
							return sItemAttributes ;
						} ;
						void CItemAttribute :: ItemAttributes ( CItemAttributes* aValue ) { // Private, accessed by friend CItemAttributes :: BaseEvents
							sItemAttributes = aValue ;
						} ;



        // Related Items

			// Constructor & Destructor
				
				CRelatedItems :: CRelatedItems ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				CRelatedItems :: ~CRelatedItems ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties

					CRelatedItem* CRelatedItems :: Item ( long aIndex ) {
						return ( CRelatedItem* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					CRelatedItem* CRelatedItems :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> Name ( ) == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

					CItem* CRelatedItems :: ParentItem ( ) {
						return sParentItem ;
					} ;
					void CRelatedItems :: ParentItem ( CItem* aValue ) { // Private, accessed by friend CItem
						sParentItem = aValue ;
					} ;

					CString CRelatedItems :: ParentItemName ( ) {
						return ParentItem ( ) -> ClassName ( ) ;
					} ;

				// Methods

					CRelatedItem* CRelatedItems :: Add ( ) {
						long tIndex = HoleListInMemory :: Add ( ) ;
						return Item ( tIndex ) ;
					} ;

			// Event Procedures

				void CRelatedItems :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CRelatedItem ) ;
					Parent -> Item ( aIndex ) -> RelatedItems ( Parent ) ;
				} ;

				void CRelatedItems :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;						



            // Related Item

				// Constructor & Destructor
					
					CRelatedItem :: CRelatedItem ( ) {
						// Initialize Pointers
							RelationClass = 0 ;
							sGenericRelationClass = 0 ;
							sItem = 0 ;
							MethodLibraryHandle = 0 ;
					} ;

					CRelatedItem :: ~CRelatedItem ( ) {
						GenericRelationClass ( 0 ) ; // Set to 0, to Unload DLL's
					} ;
				
				// Public

					// Properties

						CItem* CRelatedItem :: Item ( ) {
							// Override
								if ( MethodLibraryHandle != 0 ) {
									// Declare Return Values
										CItem* tReturnValue ;
										BOOL tOverridden = FALSE ;
									// Call DLL Function
										try {
											tReturnValue = ( OverrideItemGetProcedureAddress ) ( this , &tOverridden ) ;
										}
										catch ( ... ) {
										}
									// If Overridden Then Return
										if ( tOverridden == TRUE ) {
											return tReturnValue ;
										}
								}
							// Not Overridden
								return ItemBase ( ) ;
						} ;
						CItem* CRelatedItem :: ItemBase ( ) {
							return sItem ;
						} ;
						void CRelatedItem :: Item ( CItem* aValue ) {
							// Override
								if ( MethodLibraryHandle != 0 ) {
									// Declare Return Values
										BOOL tOverridden = FALSE ;
									// Call DLL Function
										try {
											( OverrideItemSetProcedureAddress ) ( this , &tOverridden , aValue ) ;
										}
										catch ( ... ) {
										}
									// If Overridden Then Return
										if ( tOverridden == TRUE ) {
											return ;
										}
								}
							// Not Overridden
								ItemBase ( aValue ) ; 
						} ;
						void CRelatedItem :: ItemBase ( CItem* aValue ) {
							sItem = aValue ;
							if ( aValue != 0 ) { // You have to be able to safely assign Nothing
								// Assign Hand Written Class
									if ( RelationClass != 0 ) {
										if ( sItem -> Class ( ) == 0 ) {
											sItem -> Class ( RelationClass -> Class ( ) ) ;
										}
									}
								// Assign Generic Class
									if ( GenericRelationClass ( ) != 0 ) {
										if ( sItem -> GenericClass ( ) == 0 ) {
										// Look up the Class of the Relation Class
											CRelatedItem* tRelatedItem ;
											// In gcc Layer
												tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "gcc Class" ) ;
											// Or else in ggc Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "ggc Class" ) ;
												}
											// Or else in ggg Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "Class" ) ;
												}
											CItem* tGenericClass ;
											tGenericClass = tRelatedItem -> Item ( ) ;
											sItem -> GenericClass ( tGenericClass ) ;
										}
									}
							}
						}

						CItem* CRelatedItem :: GenericRelationClass ( ) {
							return sGenericRelationClass ;
						} ;
						void CRelatedItem :: GenericRelationClass ( CItem* aValue ) {	
							// Free Method Library
								if ( sGenericRelationClass != 0 ) {
									if ( MethodLibraryHandle != 0 ) {
										FreeLibrary ( MethodLibraryHandle ) ;
										MethodLibraryHandle = 0 ;
									}
								}
							// Assign Value
								sGenericRelationClass = aValue ;
							// Load Method Library
								if ( sGenericRelationClass != 0 ) {
									// Compose path from module path, module name, other relation class's class name and relation class name
										// Get Relation Class Name
											CItemAttribute* tRelationClassNameAttribute = sGenericRelationClass -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if ( tRelationClassNameAttribute == 0 ) { return ; }
											CString tRelationClassName = tRelationClassNameAttribute -> Value ( ) ;
										// Get Other Relation Class Item
											CRelatedItem* tOtherRelationClassRelatedItem = sGenericRelationClass -> RelatedItems ( ) -> Item ( "Other Relation Class" ) ;
											if ( tOtherRelationClassRelatedItem == 0 ) { return ; }
											CItem* tOtherRelationClassItem = tOtherRelationClassRelatedItem -> Item ( ) ;
											if ( tOtherRelationClassItem == 0 ) { return ; }
										// Get Other Relation Class's Class
											CRelatedItem* tOtherRelationClassClassRelatedItem = tOtherRelationClassItem -> RelatedItems ( ) -> Item ( "Class" ) ;
											if ( tOtherRelationClassClassRelatedItem == 0 ) { return ; }
											CItem* tOtherRelationClassClassItem = tOtherRelationClassClassRelatedItem -> Item ( ) ;
											if ( tOtherRelationClassClassItem == 0 ) { return ; }
										// Get Other Relation Class's Class Name
											CItemAttribute* tClassOtherRelationClassClassNameAttribute = tOtherRelationClassClassItem -> ItemAttributes ( ) -> Item ( "Class Name" ) ;
											if  ( tClassOtherRelationClassClassNameAttribute == 0 ) { return ; }
											CString tOtherRelationClassClassName = tClassOtherRelationClassClassNameAttribute -> Value ( ) ;
										// Get Structure Item
											CRelatedItem* tStructureRelatedItem = tOtherRelationClassClassItem -> RelatedItems ( ) -> Item ( "Structure" ) ;
											if  ( tStructureRelatedItem == 0 ) { return ; }
											CItem* tStructureItem = tStructureRelatedItem -> Item ( ) ;
											if  ( tStructureItem == 0 ) { return ; }
										// Get Module Name
											CItemAttribute* tStructureNameAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if  ( tStructureNameAttribute == 0 ) { return ; }
											CString tModuleName = tStructureNameAttribute -> Value ( ) ;
										// Get Module Path
											CItemAttribute* tStructureFolderAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Folder" ) ;
											if  ( tStructureFolderAttribute == 0 ) { return ; }
											CString tModuleFolder = tStructureFolderAttribute -> Value ( ) ;
										// Compose DLL path
											CString tLibraryPath = tModuleFolder + "\\" + tModuleName + "  .  " + tOtherRelationClassClassName + "  .  " + tRelationClassName + ".dll" ;
									// If DLL File Exists, load the module
										if ( FileExists ( tLibraryPath ) == TRUE ) {
											MethodLibraryHandle = LoadLibrary ( tLibraryPath ) ;	
											OverrideItemGetProcedureAddress = ( RelatedItemOverrideItemGet ) GetProcAddress ( MethodLibraryHandle , "OverrideItemGet" ) ;
											OverrideItemSetProcedureAddress = ( RelatedItemOverrideItemSet ) GetProcAddress ( MethodLibraryHandle , "OverrideItemSet" ) ;
										}
								}
						} ;

						CString CRelatedItem :: ClassName ( ) {
							// Use C++ Usable Class
								if ( RelationClass != 0 ) {
									if ( RelationClass -> Class ( ) != 0 ) {
										return RelationClass -> Class ( ) -> ClassName ;
									}
								}
							// Use Generic Class
								if ( GenericRelationClass ( ) != 0 ) {
									if ( GenericRelationClass ( ) -> GenericClass ( ) != 0 ) {
										// Look up the Class of the Relation Class
											CRelatedItem* tRelatedItem ;
											// In gcc Layer
												tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "gcc Class" ) ;
												if ( tRelatedItem != 0 ) {
													return tRelatedItem -> Item ( ) -> ItemAttributes ( ) -> Item ( "gcc Class Name" ) -> Value ( ) ;
												}
											// Or else in ggc Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "ggc Class" ) ;
													if ( tRelatedItem != 0 ) {
														return tRelatedItem -> Item ( ) -> ItemAttributes ( ) -> Item ( "ggc Class Name" ) -> Value ( ) ;
													}
												}
											// Or else in ggg Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "Class" ) ;
													if ( tRelatedItem != 0 ) {
														return tRelatedItem -> Item ( ) -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value ( ) ;
													}
												}
									}
								}
							return "" ;
						} ;

						CString CRelatedItem :: Name ( ) {
							return sName ;
						} ;
						void CRelatedItem :: Name ( CString aValue ) { // Private, accessed by friend CItem
							sName = aValue ;
						} ;

						CRelatedItems* CRelatedItem :: RelatedItems ( ) {
							return sRelatedItems ;
						} ;
						void CRelatedItem :: RelatedItems ( CRelatedItems* aValue ) { // Private, accessed by friend CRelatedItems :: BaseEvents
							sRelatedItems = aValue ;
						} ;

        // Related Lists

			// Constructor & Destructor
				
				CRelatedLists :: CRelatedLists ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				CRelatedLists :: ~CRelatedLists ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					CRelatedList* CRelatedLists :: Item ( long aIndex ) {
						return ( CRelatedList* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					CRelatedList* CRelatedLists :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) {
									if ( Item ( i ) -> Name ( ) == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

					CItem* CRelatedLists :: ParentItem ( ) {
						return sParentItem ;
					} ;
					void CRelatedLists :: ParentItem ( CItem* aValue ) { // Private, accessed by friend CItem 
						sParentItem = aValue ;
					} ;

					CString CRelatedLists :: ParentName ( ) {
						return ParentItem ( ) -> ClassName ( ) ;
					} ;

				// Methods
					
					CRelatedList* CRelatedLists :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void CRelatedLists :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CRelatedList ) ;
					Parent -> Item ( aIndex ) -> RelatedLists ( Parent ) ;
				} ;

				void CRelatedLists :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Related List

				// Constructor & Destructor
					
					CRelatedList :: CRelatedList ( ) {
						// Initialize Pointers
							RelationClass = 0 ;
							sGenericRelationClass = 0 ;
							MethodLibraryHandle = 0 ;
						// Setup Event Sinks
							// Base
								BaseEventsObject = new BaseEvents ;
								BaseEventsObject -> Parent = this ;
								HoleListInMemory :: EventSink ( BaseEventsObject ) ;
					} ;

					CRelatedList :: ~CRelatedList ( ) {
						Clear ( ) ;
						GenericRelationClass ( 0 ) ; // Set to 0, to Unload DLL's
						delete BaseEventsObject ;
						HoleListInMemory :: EventSink ( 0 ) ;
					} ;

				// Public

					// Properties
						
						CItem* CRelatedList :: Item ( long aIndex ) {
							// Override
								if ( MethodLibraryHandle != 0 ) {
									// Declare Return Values
										CItem* tReturnValue ;
										BOOL tOverridden = FALSE ;
									// Call DLL Function
										try {
											tReturnValue = ( OverrideItemGetProcedureAddress ) ( this , &tOverridden , aIndex ) ;
										}
										catch ( ... ) {
										}
									// If Overridden Then Return
										if ( tOverridden == TRUE ) {
											return tReturnValue ;
										}
								}								
							// Not Overridden
								return ItemBase ( aIndex ) ;
						} ;
						CItem* CRelatedList :: ItemBase ( long aIndex ) {
							return ( CItem* ) HoleListInMemory :: Item ( aIndex ) ;
						} ;
						void CRelatedList :: Item ( long aIndex , CItem* aValue ) {
							// Override
								if ( MethodLibraryHandle != 0 ) {
									// Declare Return Values
										BOOL tOverridden = FALSE ;
									// Call DLL Function
										try {
											( OverrideItemSetProcedureAddress ) ( this , &tOverridden , aIndex , aValue ) ;
										}
										catch ( ... ) {
										}
									// If Overridden Then Return
										if ( tOverridden == TRUE ) {
											return ;
										}
								}								
							// Not Overridden
								ItemBase ( aIndex , aValue ) ;
						} ;
						void CRelatedList :: ItemBase ( long aIndex , CItem* aValue ) {
							HoleListInMemory :: Item ( aIndex , ( void* ) aValue ) ;
							if ( aValue != 0 ) { // You have to be able to safely assign Nothing
								// Assign Hand Written Class
									if ( RelationClass != 0 ) {
										if ( aValue -> Class ( ) == 0 ) {
											aValue -> Class ( RelationClass -> Class ( ) ) ;
										}
									}
								// Assign Generic Class
									if ( GenericRelationClass ( ) != 0 ) { // This Related List has a Generic Relation Class assigned to it.
										if ( aValue -> GenericClass ( ) == 0 ) { // No class assigned to Item yet.
											// Look up the Class of the Relation Class
												CRelatedItem* tRelatedItem ;
												// In gcc Layer
													tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "gcc Class" ) ;
												// Or else in ggc Layer
													if ( tRelatedItem == 0 ) {
														tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "ggc Class" ) ;
													}
												// Or else in ggg Layer
													if ( tRelatedItem == 0 ) {
														tRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "Class" ) ;
													}
												CItem* tGenericClass ;
												tGenericClass = tRelatedItem -> Item ( ) ;
											// Assign the class to the item
											aValue -> GenericClass ( tGenericClass ) ;
										}
									}
							}
							// Quick & Dirty Synchronization 1 -> n for the Procedures Project
								// Synchronization 1 To N : Synchronize In
									// Creator 0.9 VB Generator example
										// With TargetClass
										// 		If .RelationType = OneToN Or .RelationType = OneToX Then
										// 			With .OtherRelationClass
										// 				l "'Synchronization 1 To N/X: Synchronize In": t
										// 					l "Set Item(aIndex)." + .ItemObjectName + " = " + .ItemObjectName: o
										// 			End With
										// 		End If
										// 	End With
									// Creator 0.9 VB Generator output example:
										// In ScreenControls.Item.Set :
										//		Set Item(aIndex).Screen = Screen
									// Rather complicated looking translation
										if ( GenericRelationClass ( ) != 0 ) {
											CItemAttribute* tTargetClassPluralAttribute = GenericRelationClass ( ) -> ItemAttributes ( ) -> Item ( "Plural" ) ;
											if ( tTargetClassPluralAttribute != 0 ) {
												CString tTargetClassPlural = tTargetClassPluralAttribute -> Value ( ) ;
												CRelatedItem* tOtherRelationClassRelatedItem = GenericRelationClass ( ) -> RelatedItems ( ) -> Item ( "Other Relation Class" ) ;
												if ( tOtherRelationClassRelatedItem != 0 ) {
													CItem* tOtherRelationClassItem = tOtherRelationClassRelatedItem -> Item ( ) ;
													if ( tOtherRelationClassItem != 0 ) {
														CItemAttribute* tOtherRelationClassPluralAttribute = tOtherRelationClassItem -> ItemAttributes ( ) -> Item ( "Plural" ) ;
														if ( tOtherRelationClassPluralAttribute != 0 ) {
															CString tOtherRelationClassPlural = tOtherRelationClassPluralAttribute -> Value ( ) ;
															if ( tOtherRelationClassPlural == "False" && tTargetClassPlural == "True" ) {
																CItemAttribute* tRelationClassNameAttribute = tOtherRelationClassItem -> ItemAttributes ( ) -> Item ( "Name" ) ;
																if ( tRelationClassNameAttribute != 0 ) {
																	CString tRelationClassName = tRelationClassNameAttribute -> Value ( ) ;
																	if ( Item ( aIndex ) != 0 ) {
																		Item ( aIndex ) -> RelatedItems ( ) -> Item ( tRelationClassName ) -> Item ( RelatedLists ( ) -> ParentItem ( ) ) ;
																	}
																}
															}
														}
													}
												}
											}
									}
						} ;

						CItem* CRelatedList :: GenericRelationClass ( ) {
							return sGenericRelationClass ;
						} ;
						void CRelatedList :: GenericRelationClass ( CItem* aValue ) {	
							// Free Method Library
								if ( sGenericRelationClass != 0 ) {
									if ( MethodLibraryHandle != 0 ) {
										FreeLibrary ( MethodLibraryHandle ) ;
										MethodLibraryHandle = 0 ;
									}
								}
							// Assign Value
								sGenericRelationClass = aValue ;
							// Load Method Library
								if ( sGenericRelationClass != 0 ) {
									// Compose path from module path, module name, other relation class's class name and relation class name
										// Get Relation Class Name
											CItemAttribute* tRelationClassNameAttribute = sGenericRelationClass -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if ( tRelationClassNameAttribute == 0 ) { return ; }
											CString tRelationClassName = tRelationClassNameAttribute -> Value ( ) ;
										// Get Other Relation Class Item
											CRelatedItem* tOtherRelationClassRelatedItem = sGenericRelationClass -> RelatedItems ( ) -> Item ( "Other Relation Class" ) ;
											if ( tOtherRelationClassRelatedItem == 0 ) { return ; }
											CItem* tOtherRelationClassItem = tOtherRelationClassRelatedItem -> Item ( ) ;
											if ( tOtherRelationClassItem == 0 ) { return ; }
										// Get Other Relation Class's Class
											CRelatedItem* tOtherRelationClassClassRelatedItem = tOtherRelationClassItem -> RelatedItems ( ) -> Item ( "Class" ) ;
											if ( tOtherRelationClassClassRelatedItem == 0 ) { return ; }
											CItem* tOtherRelationClassClassItem = tOtherRelationClassClassRelatedItem -> Item ( ) ;
											if ( tOtherRelationClassClassItem == 0 ) { return ; }
										// Get Other Relation Class's Class Name
											CItemAttribute* tClassOtherRelationClassClassNameAttribute = tOtherRelationClassClassItem -> ItemAttributes ( ) -> Item ( "Class Name" ) ;
											if  ( tClassOtherRelationClassClassNameAttribute == 0 ) { return ; }
											CString tOtherRelationClassClassName = tClassOtherRelationClassClassNameAttribute -> Value ( ) ;
										// Get Structure Item
											CRelatedItem* tStructureRelatedItem = tOtherRelationClassClassItem -> RelatedItems ( ) -> Item ( "Structure" ) ;
											if  ( tStructureRelatedItem == 0 ) { return ; }
											CItem* tStructureItem = tStructureRelatedItem -> Item ( ) ;
											if  ( tStructureItem == 0 ) { return ; }
										// Get Module Name
											CItemAttribute* tStructureNameAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if  ( tStructureNameAttribute == 0 ) { return ; }
											CString tModuleName = tStructureNameAttribute -> Value ( ) ;
										// Get Module Path
											CItemAttribute* tStructureFolderAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Folder" ) ;
											if  ( tStructureFolderAttribute == 0 ) { return ; }
											CString tModuleFolder = tStructureFolderAttribute -> Value ( ) ;
										// Compose DLL path
											CString tLibraryPath = tModuleFolder + "\\" + tModuleName + "  .  " + tOtherRelationClassClassName + "  .  " + tRelationClassName + ".dll" ;
									// If DLL File Exists, load the module
										if ( FileExists ( tLibraryPath ) == TRUE ) {
											MethodLibraryHandle = LoadLibrary ( tLibraryPath ) ;	
											OverrideItemGetProcedureAddress = ( RelatedListOverrideItemGet ) GetProcAddress ( MethodLibraryHandle , "OverrideItemGet" ) ;
											OverrideItemSetProcedureAddress = ( RelatedListOverrideItemSet ) GetProcAddress ( MethodLibraryHandle , "OverrideItemSet" ) ;
											OverrideInitializeItemProcedureAddress = ( RelatedListOverrideInitializeItem ) GetProcAddress ( MethodLibraryHandle , "OverrideInitializeItem" ) ;
										}
								}
						} ;

						CString CRelatedList :: Name ( ) {
							return sName ;
						} ;
						void CRelatedList :: Name ( CString aValue ) { // Private, accessed by friend CItem
							sName = aValue ;
						} ;

						CRelatedLists* CRelatedList :: RelatedLists ( ) {
							return sRelatedLists ;
						} ;
						void CRelatedList :: RelatedLists ( CRelatedLists* aValue ) { // Private, accessed by friend CItem 
							sRelatedLists = aValue ;
						} ;

					// Methods
						
						CItem* CRelatedList :: Add ( ) {
							return ( CItem* ) Item ( HoleListInMemory :: Add ( ) ) ;
						} ;

				// Event Procedures

					void CRelatedList :: BaseEvents :: InitializeItem ( long aIndex ) {
						// Override
							if ( Parent -> MethodLibraryHandle != 0 ) {
								// Declare Return Values
									CString tReturnValue ;
									BOOL tOverridden = FALSE ;
								// Call DLL Function
									( Parent -> OverrideInitializeItemProcedureAddress ) ( Parent , &tOverridden , aIndex ) ;
								// If Overridden Then Return
									if ( tOverridden == TRUE ) {
										return ;
									}
							}
						// Not Overridden
							Parent -> InitializeItemBase ( aIndex ) ;
					} ;

					void CRelatedList :: InitializeItemBase ( long aIndex ) {
						Item ( aIndex , ( CItem*) new CItem ) ;
					};

					void CRelatedList :: BaseEvents :: TerminateItem ( long aIndex ) {
						delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
					} ;



        // Item Methods

			// Constructor & Destructor

				CItemMethods :: CItemMethods ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				CItemMethods :: ~CItemMethods ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					CItemMethod* CItemMethods :: Item ( long aIndex ) {
						return ( CItemMethod* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					CItemMethod* CItemMethods :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> Name ( ) == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

					CItem* CItemMethods :: ParentItem ( ) {
						return sParentItem ;
					} ;
					void CItemMethods :: ParentItem ( CItem* aValue ) { // Private, accessed by friend CItem
						sParentItem = aValue ;
					} ;
											
					CString CItemMethods :: ParentName ( ) {
						return ParentItem ( ) -> ClassName ( ) ;
					} ;

				// Methods
					
					CItemMethod* CItemMethods :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void CItemMethods :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CItemMethod ) ;
					Parent -> Item ( aIndex ) -> ItemMethods ( Parent ) ;
				} ;

				void CItemMethods :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Item Method
				
				// Constructor & Destructor
					
					CItemMethod :: CItemMethod ( ) {
						// Initialize Pointers
							sGenericClassMethod = 0 ;
							MethodLibraryHandle = 0 ;
					} ;

					CItemMethod :: ~CItemMethod ( ) {
						GenericClassMethod ( 0 ) ; // Set to 0, to Unload DLL's
					} ;

				// Public
					
					// Properties

						void CItemMethod :: Execute ( ) {
							if ( MethodLibraryHandle != 0 ) {
								try {
									( ExecuteMethodProcedureAddress ) ( this ) ;
								}
								catch ( ... ) {
								}
							}
						} ;

						CItem* CItemMethod :: GenericClassMethod ( ) {
							return sGenericClassMethod ;
						} ;
						void CItemMethod :: GenericClassMethod ( CItem* aValue ) {	
							// Free Method Library
								if ( sGenericClassMethod != 0 ) {
									if ( MethodLibraryHandle != 0 ) {
										FreeLibrary ( MethodLibraryHandle ) ;
										MethodLibraryHandle = 0 ;
									}
								}
							// Assign Value
								sGenericClassMethod = aValue ;
							// Load Method Library
								if ( sGenericClassMethod != 0 ) {
									// Compose path from module path, module name, class name and method name
										// Get Method Name
											CItemAttribute* tMethodNameAttribute = sGenericClassMethod -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if ( tMethodNameAttribute == 0 ) { return ; }
											CString tMethodName = tMethodNameAttribute -> Value ( ) ;
										// Get Class Item
											CRelatedItem* tClassRelatedItem = sGenericClassMethod -> RelatedItems ( ) -> Item ( "Class" ) ;
											if  ( tClassRelatedItem == 0 ) { return ; }
											CItem* tClassItem = tClassRelatedItem -> Item ( ) ;
											if  ( tClassItem == 0 ) { return ; }
										// Get Class Name
											CItemAttribute* tClassNameAttribute = tClassItem -> ItemAttributes ( ) -> Item ( "Class Name" ) ;
											if  ( tClassNameAttribute == 0 ) { return ; }
											CString tClassName = tClassNameAttribute -> Value ( ) ;
										// Get Structure Item
											CRelatedItem* tStructureRelatedItem = tClassItem -> RelatedItems ( ) -> Item ( "Structure" ) ;
											if  ( tStructureRelatedItem == 0 ) { return ; }
											CItem* tStructureItem = tStructureRelatedItem -> Item ( ) ;
											if  ( tStructureItem == 0 ) { return ; }
										// Get Module Name
											CItemAttribute* tStructureNameAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Name" ) ;
											if  ( tStructureNameAttribute == 0 ) { return ; }
											CString tModuleName = tStructureNameAttribute -> Value ( ) ;
										// Get Module Path
											CItemAttribute* tStructureFolderAttribute = tStructureItem -> ItemAttributes ( ) -> Item ( "Folder" ) ;
											if  ( tStructureFolderAttribute == 0 ) { return ; }
											CString tModuleFolder = tStructureFolderAttribute -> Value ( ) ;
										// Compose DLL path
											CString tLibraryPath = tModuleFolder + "\\" + tModuleName + "  .  " + tClassName + "  .  " + tMethodName + ".dll" ;
									// If DLL File Exists, load the module
										if ( FileExists ( tLibraryPath ) == TRUE ) {
											MethodLibraryHandle = LoadLibrary ( tLibraryPath ) ;	
											ExecuteMethodProcedureAddress = ( ItemExecuteMethod ) GetProcAddress ( MethodLibraryHandle , "ExecuteMethod" ) ;
										}
								}
						} ;

						CString CItemMethod :: Name ( ) {
							return sName ;
						} ;
						void CItemMethod :: Name ( CString aValue ) { // Private, accessed by friend CItem
							sName = aValue ;
						} ;

						CItemMethods* CItemMethod :: ItemMethods ( ) {
							return sItemMethods ;
						} ;
						void CItemMethod :: ItemMethods ( CItemMethods* aValue ) { // Private, accessed by friend CItemMethods :: BaseEvents
							sItemMethods = aValue ;
						} ;

