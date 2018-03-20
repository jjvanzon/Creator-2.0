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
				// Initialize Variables
					// Expanded = FALSE ;
				// Create Objects
					sItemAttributes = new CItemAttributes ;
					sRelatedItems = new CRelatedItems ;
					sRelatedLists = new CRelatedLists ;
				// Initialize Pointers
					sClass = 0 ;
					sGenericClass = 0 ;
				// Assign Parents
					ItemAttributes ( ) -> Parent ( this ) ;
					RelatedItems ( ) -> Parent ( this ) ;
					RelatedLists ( ) -> Parent ( this ) ;
			} ;
			
			CItem :: ~CItem ( ) {
				delete sItemAttributes ;
				delete sRelatedItems ;
				delete sRelatedLists ;
			} ;

		// Public
			
			// Properties

				CClass* CItem :: Class ( ) {
					return sClass ;
				} ;
				void CItem :: Class ( CClass* aValue ) {
					// Declarations
						long i ;
						CClassAttribute* tClassAttribute ;
						CRelationClass* tRelationClass ;
						CItemAttribute* tItemAttribute ;
						CRelatedList* tRelatedList ;
						CRelatedItem* tRelatedItem ;
					// Functionality
						// Assign 
							sClass = aValue ;
						// Clear
							ItemAttributes ( ) -> Clear ( ) ;
							RelatedItems ( ) -> Clear ( ) ;
							RelatedLists ( ) -> Clear ( ) ;
						// Traverse Class Attributes
							for ( i = 0 ; i <= Class ( ) -> ClassAttributes ( ) -> StorageCount ( ) - 1 ; i ++ ) {
								if ( Class ( ) -> ClassAttributes ( ) -> PositionUsed ( i ) == TRUE ) {
									tClassAttribute = Class ( ) -> ClassAttributes ( ) -> Item ( i ) ;
									tItemAttribute = ItemAttributes ( ) -> Add ( ) ;
									tItemAttribute -> ClassAttribute = tClassAttribute ;
									tItemAttribute -> Name ( tClassAttribute -> Name ) ;
								}
							}
						// Traverse Class Related Items
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
						CRelatedList* tGenericClassAttributes = 0 ;
						CItem* tGenericClassAttribute = 0 ;
						CRelatedList* tGenericRelationClasses = 0 ;
						CItem* tGenericRelationClass = 0 ;
						CItemAttribute* tPluralAttribute = 0 ;
						CString tPlural ;
						// New
							CItemAttribute* tItemAttribute = 0 ;
							CItemAttribute* tNameAttribute = 0 ;
							CString tName ;
							CRelatedList* tRelatedList = 0 ;
							CRelatedItem* tRelatedItem = 0 ;
					// Functionality
						// Assign 
							sGenericClass = aValue ;
						// Clear
							ItemAttributes ( ) -> Clear ( ) ;
							RelatedItems ( ) -> Clear ( ) ;
							RelatedLists ( ) -> Clear ( ) ;
						// Get Generic Class Attributes Reference
							tGenericClassAttributes = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
							if ( tGenericClassAttributes == 0 ) {
								tGenericClassAttributes = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
							}
							if ( tGenericClassAttributes == 0 ) {
								tGenericClassAttributes = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "Class Attributes" ) ;
							}
						// Traverse Class Attributes
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
									tName = tNameAttribute -> Value ;
									tItemAttribute = ItemAttributes ( ) -> Add ( ) ;
									tItemAttribute -> GenericClassAttribute = tGenericClassAttribute ;
									tItemAttribute -> Name ( tName ) ;
								}
							}
						// Get Generic Relation Classes Reference
							tGenericRelationClasses = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
							if ( tGenericRelationClasses == 0 ) {
								tGenericRelationClasses = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
							}
							if ( tGenericRelationClasses == 0 ) {
								tGenericRelationClasses = ( CRelatedList* ) GenericClass ( ) -> RelatedLists ( ) -> Item ( "Related Classes" ) ;
							}
						// Traverse Class Related Items
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
									tPlural = tPluralAttribute -> Value ;
									// Get Name Attribute Reference
										tNameAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "gcc Name" ) ;
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "ggc Name" ) ;
										}
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( CItemAttribute* ) tGenericRelationClass -> ItemAttributes ( ) -> Item ( "Name" ) ;
										}
									tName = tNameAttribute -> Value ;
									if ( tPlural == "True" ) {
										tRelatedList = RelatedLists ( ) -> Add ( ) ;
										tRelatedList -> GenericRelationClass = tGenericRelationClass ;	
										tRelatedList -> Name ( tName ) ;
									}
									// if ( tPlural == "False" ) { // Generic Creator does not define default values yet, so tPlural will be "" in many cases.
									else {
										tRelatedItem = RelatedItems ( ) -> Add ( ) ;
										tRelatedItem -> GenericRelationClass = tGenericRelationClass ;
										tRelatedItem -> Name ( tName ) ;
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
									return tItemAttribute -> Value ;
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

					CItem* CItemAttributes :: Parent ( ) {
						return sParent ;
					} ;
					void CItemAttributes :: Parent ( CItem* aValue ) { // Private, accessed by friend CItem
						sParent = aValue ;
					} ;
											
					CString CItemAttributes :: ParentName ( ) {
						return Parent ( ) -> ClassName ( ) ;
					} ;

				// Methods
					
					CItemAttribute* CItemAttributes :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void CItemAttributes :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CItemAttribute ) ;
				} ;

				void CItemAttributes :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Item Attribute
				
				// Constructor & Destructor
					
					CItemAttribute :: CItemAttribute ( ) {
						// Initialize Pointers
							ClassAttribute = 0 ;
							GenericClassAttribute = 0 ;
					} ;

				// Public
					
					// Properties

						CString CItemAttribute :: Type ( ) {
							if ( GenericClassAttribute != 0 ) {
								CItemAttribute* tAttribute ;
								tAttribute = GenericClassAttribute -> ItemAttributes ( ) -> Item ( "Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ;
								}
								tAttribute = GenericClassAttribute -> ItemAttributes ( ) -> Item ( "ggg Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ;
								}
								tAttribute = GenericClassAttribute -> ItemAttributes ( ) -> Item ( "ggc Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ;
								}
								tAttribute = GenericClassAttribute -> ItemAttributes ( ) -> Item ( "gcc Type" ) ;
								if ( tAttribute != 0 ) {
									return tAttribute  -> Value ;
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

					CItem* CRelatedItems :: Parent ( ) {
						return sParent ;
					} ;
					void CRelatedItems :: Parent ( CItem* aValue ) { // Private, accessed by friend CItem
						sParent = aValue ;
					} ;

					CString CRelatedItems :: ParentName ( ) {
						return Parent ( ) -> ClassName ( ) ;
					} ;

				// Methods

					CRelatedItem* CRelatedItems :: Add ( ) {
						long tIndex = HoleListInMemory :: Add ( ) ;
						return Item ( tIndex ) ;
					} ;

			// Event Procedures

				void CRelatedItems :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CRelatedItem ) ;
				} ;

				void CRelatedItems :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;						



            // Related Item

				// Constructor & Destructor
					
					CRelatedItem :: CRelatedItem ( ) {
						// Initialize Pointers
							RelationClass = 0 ;
							GenericRelationClass = 0 ;
							sItem = 0 ;
					} ;
				
				// Public

					// Properties

						CItem* CRelatedItem :: Item ( ) {
							return sItem ;
						} ;
						void CRelatedItem :: Item ( CItem* aValue ) {
							sItem = aValue ;
							if ( aValue != 0 ) { // New 2007-07-12 : you have to be able to safely assign Nothing
								// Assign Hand Written Class
									if ( RelationClass != 0 ) {
										if ( sItem -> Class ( ) == 0 ) {
											sItem -> Class ( RelationClass -> Class ( ) ) ;
										}
									}
								// Assign Generic Class
									if ( GenericRelationClass != 0 ) {
										if ( sItem -> GenericClass ( ) == 0 ) {
										// Look up the Class of the Relation Class
											CRelatedItem* tRelatedItem ;
											// In g Layer
												tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) ;
											// Or else in ggc Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) ;
												}
											// Or else in ggg Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "Class" ) ;
												}
											CItem* tGenericClass ;
											tGenericClass = tRelatedItem -> Item ( ) ;
											sItem -> GenericClass ( tGenericClass ) ;
										}
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
								if ( GenericRelationClass != 0 ) {
									if ( GenericRelationClass -> GenericClass ( ) != 0 ) {
										// Look up the Class of the Relation Class
											CRelatedItem* tRelatedItem ;
											// In gcc Layer
												tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) ;
												if ( tRelatedItem != 0 ) {
													return tRelatedItem -> Item ( ) -> ItemAttributes ( ) -> Item ( "gcc Class Name" ) -> Value ;
												}
											// Or else in ggc Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) ;
													if ( tRelatedItem != 0 ) {
														return tRelatedItem -> Item ( ) -> ItemAttributes ( ) -> Item ( "ggc Class Name" ) -> Value ;
													}
												}
											// Or else in ggg Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "Class" ) ;
													if ( tRelatedItem != 0 ) {
														return tRelatedItem -> Item ( ) -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value ;
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

					CItem* CRelatedLists :: Parent ( ) {
						return sParent ;
					} ;
					void CRelatedLists :: Parent ( CItem* aValue ) { // Private, accessed by friend CItem 
						sParent = aValue ;
					} ;

					CString CRelatedLists :: ParentName ( ) {
						return Parent ( ) -> ClassName ( ) ;
					} ;

				// Methods
					
					CRelatedList* CRelatedLists :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void CRelatedLists :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new CRelatedList ) ;
				} ;

				void CRelatedLists :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Related List

				// Constructor & Destructor
					
					CRelatedList :: CRelatedList ( ) {
						// Initialize Variables
							// Expanded = FALSE ;
						// Initialize Pointers
							RelationClass = 0 ;
							GenericRelationClass = 0 ;
						// Setup Event Sinks
							// Base
								BaseEventsObject = new BaseEvents ;
								BaseEventsObject -> Parent = this ;
								HoleListInMemory :: EventSink ( BaseEventsObject ) ;
					} ;

					CRelatedList :: ~CRelatedList ( ) {
						Clear ( ) ;
						delete BaseEventsObject ;
						HoleListInMemory :: EventSink ( 0 ) ;
					} ;

				// Public

					// Properties
						
						CItem* CRelatedList :: Item ( long aIndex ) {
							return ( CItem* ) HoleListInMemory :: Item ( aIndex ) ;
						} ;
						void CRelatedList :: Item ( long aIndex , CItem* aValue ) {
							HoleListInMemory :: Item ( aIndex , ( void* ) aValue ) ;
							if ( aValue != 0 ) { // New 2007-07-12 : you have to be able to safely assign Nothing
								// Assign Hand Written Class
									if ( RelationClass != 0 ) {
										if ( aValue -> Class ( ) == 0 ) {
											aValue -> Class ( RelationClass -> Class ( ) ) ;
										}
									}
								// Assign Generic Class
									if ( GenericRelationClass != 0 ) { // This Related List has a Generic Relation Class assigned to it.
										if ( aValue -> GenericClass ( ) == 0 ) { // No class assigned to Item yet.
											// Look up the Class of the Relation Class
												CRelatedItem* tRelatedItem ;
												// In g Layer
													tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) ;
												// Or else in ggc Layer
													if ( tRelatedItem == 0 ) {
														tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) ;
													}
												// Or else in ggg Layer
													if ( tRelatedItem == 0 ) {
														tRelatedItem = GenericRelationClass -> RelatedItems ( ) -> Item ( "Class" ) ;
													}
												CItem* tGenericClass ;
												tGenericClass = tRelatedItem -> Item ( ) ;
											// Assign the class to the item
											aValue -> GenericClass ( tGenericClass ) ;
										}
									}
							}
						} ;

						CString CRelatedList :: Name ( ) {
							return sName ;
						} ;
						void CRelatedList :: Name ( CString aValue ) { // Private, accessed by friend CItem
							sName = aValue ;
						} ;

					// Methods
						
						CItem* CRelatedList :: Add ( ) {
							return ( CItem* ) Item ( HoleListInMemory :: Add ( ) ) ;
						} ;

				// Event Procedures

					void CRelatedList :: BaseEvents :: InitializeItem ( long aIndex ) {
						Parent -> Item ( aIndex , ( CItem*) new CItem ) ;
					} ;

					void CRelatedList :: BaseEvents :: TerminateItem ( long aIndex ) {
						delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
					} ;
