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

			cccCStructure :: cccCStructure ( ) {
				scccClasses = new cccCClasses ;
				scccRelations = new cccCRelations ;
			} ;

			cccCStructure :: ~cccCStructure ( ) {
				// The order matters here, because the classes have to exist in destroying Relations . Item [ ] . Relation Class A and B
				delete scccRelations ;
				delete scccClasses ;
			} ;
				
		// Public
			
			// Properties

				cccCClasses* cccCStructure :: cccClasses ( ) {
					return scccClasses ;
				} ;

				cccCRelations* cccCStructure :: cccRelations ( ) {
					return scccRelations ;
				} ;

				
		// Classes

			// Constructor & Destructor
				
				cccCClasses :: cccCClasses ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				cccCClasses :: ~cccCClasses ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					cccCClass* cccCClasses :: Item ( long aIndex ) {
						return ( cccCClass* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					cccCClass* cccCClasses :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> cccClassName == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

						
				// Methods
					
					cccCClass* cccCClasses :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void cccCClasses :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new cccCClass ) ;
				} ;

				void cccCClasses :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Class
				
				// Constructor & Destructor
					
					cccCClass :: cccCClass ( ) {
						scccClassAttributes = new cccCClassAttributes ;
						scccRelatedClasses = new cccCRelatedClasses ;
					} ;
						
					cccCClass :: ~cccCClass ( ) {
						delete scccClassAttributes ;
						delete scccRelatedClasses ;
					} ;


				// Public

					// Properties

						cccCClassAttributes* cccCClass :: cccClassAttributes ( ) {
							return scccClassAttributes ;
						} ;

						cccCRelatedClasses* cccCClass :: cccRelatedClasses ( ) {
							return scccRelatedClasses ;
						} ;



                // Class Atributes
		
					// Constructor & Destructor

						cccCClassAttributes :: cccCClassAttributes ( ) {
							// Setup Event Sinks
								// Base
									BaseEventsObject = new BaseEvents ;
									BaseEventsObject -> Parent = this ;
									HoleListInMemory :: EventSink ( BaseEventsObject ) ;
						} ;

						cccCClassAttributes :: ~cccCClassAttributes ( ) {
							Clear ( ) ;
							delete BaseEventsObject ;
							HoleListInMemory :: EventSink ( 0 ) ;
						} ;

					// Public

						// Properties

							cccCClassAttribute* cccCClassAttributes :: Item ( long aIndex ) {
								return ( cccCClassAttribute* ) HoleListInMemory :: Item ( aIndex ) ;
							} ;

							cccCClassAttribute* cccCClassAttributes :: Item ( CString aName ) {
								long i ;
								for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
									if ( PositionUsed ( i ) == TRUE ) {
										if ( Item ( i ) != 0 ) { 
											if ( Item ( i ) -> cccName == aName ) {
												return Item ( i ) ;
											}
										}
									}
								}
								return 0;
							} ;
							
						// Methods
							
							cccCClassAttribute* cccCClassAttributes :: Add ( ) {
								return Item ( HoleListInMemory :: Add ( ) ) ;
							} ;

					// Event Procedures

						void cccCClassAttributes :: BaseEvents :: InitializeItem ( long aIndex ) {
							Parent -> HoleListInMemory :: Item ( aIndex , new cccCClassAttribute ) ;
						} ;

						void cccCClassAttributes :: BaseEvents :: TerminateItem ( long aIndex ) {
							delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
						} ;

					// Class Atribute
						
						// No Definitions



				// Related Classes
					
					cccCRelationClass* cccCRelatedClasses :: Item ( long aIndex ) {
						return ( cccCRelationClass* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;



		// Relations

			// Constructor & Destructor
				
				cccCRelations :: cccCRelations ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				cccCRelations :: ~cccCRelations ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					cccCRelation* cccCRelations :: Item ( long aIndex ) {
						return ( cccCRelation* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;
						
				// Methods
					
					cccCRelation* cccCRelations :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Private
				
				// Event Procedures

					void cccCRelations :: BaseEvents :: InitializeItem ( long aIndex ) {
						Parent -> HoleListInMemory :: Item ( aIndex , new cccCRelation ) ;
					} ;

					void cccCRelations :: BaseEvents :: TerminateItem ( long aIndex ) {
						Parent -> Item ( aIndex ) -> DeregisterRelationInClasses ( ) ;
						delete Parent -> HoleListInMemory :: Item ( aIndex ) ;
					} ;



            // Relation

				// Constructor & Destructor

					cccCRelation :: cccCRelation ( ) {
						// Create Objects
							scccRelationClassA = new cccCRelationClass ;
							scccRelationClassB = new cccCRelationClass ;
						// Initialize Object Members
							// cccRelation Class A
								cccRelationClassA ( ) -> cccIdInRelation = 0 ;
								cccRelationClassA ( ) -> cccRelation = this ;
							// Relation Class B
								cccRelationClassB ( ) -> cccIdInRelation = 1 ;
								cccRelationClassB ( ) -> cccRelation = this ;
					} ;

					cccCRelation :: ~cccCRelation ( ) {
						DeregisterRelationInClasses ( ) ;
						delete scccRelationClassA ;
						delete scccRelationClassB ;
					} ;

				// Public
					
					// Properties
							
						cccCRelationClass* cccCRelation :: cccRelationClassA ( ) {
							return scccRelationClassA ;
						} ;

						cccCRelationClass* cccCRelation :: cccRelationClassB ( ) {
							return scccRelationClassB ;
						} ;
							
				// Friend
					
					// Public
						
						void cccCRelation :: DeregisterRelationInClasses ( ) {
							cccRelationClassA ( ) -> DeregisterRelationInClass ( ) ;
							cccRelationClassB ( ) -> DeregisterRelationInClass ( ) ;
						}



                // Relation Class

					// Constructor & Destructor

						cccCRelationClass :: cccCRelationClass ( ) {
							cccPlural = FALSE ;
							cccIdInRelation = -1 ;
							cccIdInClassRelatedClasses = -1 ;
							scccClass = 0 ;
						} ;

					// Public
						
						// Properties

							cccCClass* cccCRelationClass :: cccClass ( ) {
								return scccClass ;
							} ;

							void cccCRelationClass :: cccClass ( cccCClass* aValue ) {
								// Reflect Relations in Class.RelatedClasses
									DeregisterRelationInClass ( ) ;
								// Assign
									scccClass = aValue ;
								// Reflect Relations in Class.RelatedClasses
									RegisterRelationInClass ( ) ;
							} ;

					// Friend
						
						// Methods
									
							void cccCRelationClass :: DeregisterRelationInClass ( ) {
								if ( ! cccClass ( ) == 0 ) {
									cccClass ( ) -> cccRelatedClasses ( ) -> Remove ( cccIdInClassRelatedClasses ) ;
								}
							} ;
							void cccCRelationClass :: RegisterRelationInClass ( ) {
								if ( ! cccClass ( ) == 0 ) {
									switch ( cccIdInRelation ) {
										case 0 :
											cccIdInClassRelatedClasses = cccClass ( ) -> cccRelatedClasses ( ) -> Add ( cccRelation -> cccRelationClassB ( ) ) ;
											break ;
										case 1 :
											cccIdInClassRelatedClasses = cccClass ( ) -> cccRelatedClasses ( ) -> Add ( cccRelation -> cccRelationClassA ( ) ) ;
											break ;
									}
								}
							} ;



	// Item

		// Constructor & Destructor
			
			cccCItem :: cccCItem ( ) {
				// Create Objects
					scccItemAttributes = new cccCItemAttributes ;
					scccRelatedItems = new cccCRelatedItems ;
					scccRelatedLists = new cccCRelatedLists ;
				// Initialize Pointers
					scccClass = 0 ;
					scccGenericClass = 0 ;
				// Assign Parents
					cccItemAttributes ( ) -> cccParent = this ;
					cccRelatedItems ( ) -> cccParent = this ;
					cccRelatedLists ( ) -> cccParent = this ;
			} ;
			
			cccCItem :: ~cccCItem ( ) {
				delete scccItemAttributes ;
				delete scccRelatedItems ;
				delete scccRelatedLists ;
			} ;

		// Public
			
			// Properties

				cccCClass* cccCItem :: cccClass ( ) {
					return scccClass ;
				} ;
				void cccCItem :: cccClass ( cccCClass* aValue ) {
					// Declarations
						long i ;
						cccCClassAttribute* tClassAttribute ;
						cccCRelationClass* tRelationClass ;
						cccCItemAttribute* tItemAttribute ;
						cccCRelatedList* tRelatedList ;
						cccCRelatedItem* tRelatedItem ;
					// Functionality
						// Assign 
							scccClass = aValue ;
						// Clear
							cccItemAttributes ( ) -> Clear ( ) ;
							cccRelatedItems ( ) -> Clear ( ) ;
							cccRelatedLists ( ) -> Clear ( ) ;
						// Traverse Class Attributes
							for ( i = 0 ; i <= cccClass ( ) -> cccClassAttributes ( ) -> StorageCount ( ) - 1 ; i ++ ) {
								if ( cccClass ( ) -> cccClassAttributes ( ) -> PositionUsed ( i ) == TRUE ) {
									tClassAttribute = cccClass ( ) -> cccClassAttributes ( ) -> Item ( i ) ;
									tItemAttribute = cccItemAttributes ( ) -> Add ( ) ;
									tItemAttribute -> cccClassAttribute = tClassAttribute ;
									tItemAttribute -> cccName = tClassAttribute -> cccName ;
								}
							}
						// Traverse Class Related Items
							for ( i = 0 ; i <= cccClass ( ) -> cccRelatedClasses ( ) -> StorageCount ( ) - 1 ; i ++ ) {
								if ( cccClass ( ) -> cccRelatedClasses ( ) -> PositionUsed ( i ) == TRUE ) {
									tRelationClass = cccClass ( ) -> cccRelatedClasses ( ) -> Item ( i ) ;
									switch ( tRelationClass -> cccPlural ) {
										case TRUE :
											tRelatedList = cccRelatedLists ( ) -> Add ( ) ;
											tRelatedList -> cccRelationClass = tRelationClass ;
											tRelatedList -> cccName = tRelationClass -> cccName ;
											break ;
										case FALSE :
											tRelatedItem = cccRelatedItems ( ) -> Add ( ) ;
											tRelatedItem -> cccRelationClass = tRelationClass ;
											tRelatedItem -> cccName = tRelationClass -> cccName ;
											break ;
									}
								}
							}
				} ;

				cccCItem* cccCItem :: cccGenericClass ( ) {
					return scccGenericClass ;
				} ;
				void cccCItem :: cccGenericClass ( cccCItem* aValue ) {
					// Declarations
						long i ;
						cccCRelatedList* tGenericClassAttributes = 0 ;
						cccCItem* tGenericClassAttribute = 0 ;
						cccCRelatedList* tGenericRelationClasses = 0 ;
						cccCItem* tGenericRelationClass = 0 ;
						cccCItemAttribute* tPluralAttribute = 0 ;
						CString tPlural ;
						// New
							cccCItemAttribute* tItemAttribute = 0 ;
							cccCItemAttribute* tNameAttribute = 0 ;
							CString tName ;
							cccCRelatedList* tRelatedList = 0 ;
							cccCRelatedItem* tRelatedItem = 0 ;
					// Functionality
						// Assign 
							scccGenericClass = aValue ;
						// Clear
							cccItemAttributes ( ) -> Clear ( ) ;
							cccRelatedItems ( ) -> Clear ( ) ;
							cccRelatedLists ( ) -> Clear ( ) ;
						// Get Generic Class Attributes Reference
							tGenericClassAttributes = ( cccCRelatedList* ) cccGenericClass ( ) -> cccRelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
							if ( tGenericClassAttributes == 0 ) {
								tGenericClassAttributes = ( cccCRelatedList* ) cccGenericClass ( ) -> cccRelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
							}
							if ( tGenericClassAttributes == 0 ) {
								tGenericClassAttributes = ( cccCRelatedList* ) cccGenericClass ( ) -> cccRelatedLists ( ) -> Item ( "Class Attributes" ) ;
							}
						// Traverse Class Attributes
							for ( i = 0 ; i <= tGenericClassAttributes -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tGenericClassAttributes -> PositionUsed ( i ) == TRUE ) {
									tGenericClassAttribute = ( cccCItem* ) tGenericClassAttributes -> Item ( i ) ;
									// Get Name Attribute Reference
										tNameAttribute = ( cccCItemAttribute* ) tGenericClassAttribute -> cccItemAttributes ( ) -> Item ( "gcc Name" ) ;
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( cccCItemAttribute* ) tGenericClassAttribute -> cccItemAttributes ( ) -> Item ( "ggc Name" ) ;
										}
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( cccCItemAttribute* ) tGenericClassAttribute -> cccItemAttributes ( ) -> Item ( "Name" ) ;
										}
									tName = tNameAttribute -> cccValue ;
									tItemAttribute = cccItemAttributes ( ) -> Add ( ) ;
									tItemAttribute -> cccGenericClassAttribute = tGenericClassAttribute ;
									tItemAttribute -> cccName = tName ;
								}
							}
						// Get Generic Relation Classes Reference
							tGenericRelationClasses = ( cccCRelatedList* ) cccGenericClass ( ) -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
							if ( tGenericRelationClasses == 0 ) {
								tGenericRelationClasses = ( cccCRelatedList* ) cccGenericClass ( ) -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
							}
							if ( tGenericRelationClasses == 0 ) {
								tGenericRelationClasses = ( cccCRelatedList* ) cccGenericClass ( ) -> cccRelatedLists ( ) -> Item ( "Related Classes" ) ;
							}
						// Traverse Class Related Items
							for ( i = 0 ; i <= tGenericRelationClasses -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tGenericRelationClasses -> PositionUsed ( i ) == TRUE ) {
									tGenericRelationClass = ( cccCItem* ) tGenericRelationClasses -> Item ( i ) ;
									// Get Plural Attribute Reference
										tPluralAttribute = ( cccCItemAttribute* ) tGenericRelationClass -> cccItemAttributes ( ) -> Item ( "gcc Plural" ) ;
										if ( tPluralAttribute == 0 ) {
											tPluralAttribute = ( cccCItemAttribute* ) tGenericRelationClass -> cccItemAttributes ( ) -> Item ( "ggc Plural" ) ;
										}
										if ( tPluralAttribute == 0 ) {
											tPluralAttribute = ( cccCItemAttribute* ) tGenericRelationClass -> cccItemAttributes ( ) -> Item ( "Plural" ) ;
										}
									tPlural = tPluralAttribute -> cccValue ;
									// Get Name Attribute Reference
										tNameAttribute = ( cccCItemAttribute* ) tGenericRelationClass -> cccItemAttributes ( ) -> Item ( "gcc Name" ) ;
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( cccCItemAttribute* ) tGenericRelationClass -> cccItemAttributes ( ) -> Item ( "ggc Name" ) ;
										}
										if ( tNameAttribute == 0 ) {
											tNameAttribute = ( cccCItemAttribute* ) tGenericRelationClass -> cccItemAttributes ( ) -> Item ( "Name" ) ;
										}
									tName = tNameAttribute -> cccValue ;
									if ( tPlural == "True" ) {
										tRelatedList = cccRelatedLists ( ) -> Add ( ) ;
										tRelatedList -> cccGenericRelationClass = tGenericRelationClass ;	
										tRelatedList -> cccName = tName ;
									}
									// if ( tPlural == "False" ) { // Generic Creator does not define default values yet, so tPlural will be "" in many cases.
									else {
										tRelatedItem = cccRelatedItems ( ) -> Add ( ) ;
										tRelatedItem -> cccGenericRelationClass = tGenericRelationClass ;
										tRelatedItem -> cccName = tName ;
									}
								}
							}
				} ;

				cccCItemAttributes* cccCItem :: cccItemAttributes ( ) {
					return scccItemAttributes ;
				} ;

				cccCRelatedItems* cccCItem :: cccRelatedItems ( ) {
					return scccRelatedItems ;
				} ;

				cccCRelatedLists* cccCItem :: cccRelatedLists ( ) {
					return scccRelatedLists ;
				} ;
					
				CString* cccCItem :: cccClassName ( ) {
					if ( cccClass ( ) != 0 ) {
						return & (cccClass ( ) -> cccClassName ) ;
					}
					if ( cccGenericClass ( ) != 0 ) {
						cccCItemAttribute* tItemAttribute ;
						tItemAttribute = cccGenericClass ( ) -> cccItemAttributes ( ) -> Item ( "gcc Class Name" ) ;
						if ( tItemAttribute == 0 ) {
							tItemAttribute = cccGenericClass ( ) -> cccItemAttributes ( )-> Item ( "ggc Class Name" ) ;
						}
						if ( tItemAttribute == 0 ) {
							tItemAttribute = cccGenericClass ( ) -> cccItemAttributes ( ) -> Item ( "Class Name" ) ;
						}
						if ( tItemAttribute == 0 ) {
							return 0 ;
						}
						else {
							return & ( tItemAttribute -> cccValue ) ;
						}
					}
					return 0 ;
				} ;



        // Item Atributes

			// Constructor & Destructor

				cccCItemAttributes :: cccCItemAttributes ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				cccCItemAttributes :: ~cccCItemAttributes ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					cccCItemAttribute* cccCItemAttributes :: Item ( long aIndex ) {
						return ( cccCItemAttribute* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					cccCItemAttribute* cccCItemAttributes :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> cccName == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;
						
					CString* cccCItemAttributes :: cccParentName ( ) {
						return cccParent -> cccClassName ( ) ;
					} ;

				// Methods
					
					cccCItemAttribute* cccCItemAttributes :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void cccCItemAttributes :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new cccCItemAttribute ) ;
				} ;

				void cccCItemAttributes :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Item Attribute
				
				// Constructor & Destructor
					
					cccCItemAttribute :: cccCItemAttribute ( ) {
						// Initialize Pointers
							cccClassAttribute = 0 ;
							cccGenericClassAttribute = 0 ;
					} ;



        // Related Items

			// Constructor & Destructor
				
				cccCRelatedItems :: cccCRelatedItems ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				cccCRelatedItems :: ~cccCRelatedItems ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties

					cccCRelatedItem* cccCRelatedItems :: Item ( long aIndex ) {
						return ( cccCRelatedItem* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					cccCRelatedItem* cccCRelatedItems :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) { 
									if ( Item ( i ) -> cccName == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

					CString* cccCRelatedItems :: cccParentName ( ) {
						return cccParent -> cccClassName ( ) ;
					} ;

				// Methods

					cccCRelatedItem* cccCRelatedItems :: Add ( ) {
						long tIndex = HoleListInMemory :: Add ( ) ;
						return Item ( tIndex ) ;
					} ;

			// Event Procedures

				void cccCRelatedItems :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new cccCRelatedItem ) ;
				} ;

				void cccCRelatedItems :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;						



            // Related Item

				// Constructor & Destructor
					
					cccCRelatedItem :: cccCRelatedItem ( ) {
						// Initialize Pointers
							cccRelationClass = 0 ;
							cccGenericRelationClass = 0 ;
							scccItem = 0 ;
					} ;
				
				// Public

					// Properties

						cccCItem* cccCRelatedItem :: cccItem ( ) {
							return scccItem ;
						} ;
						void cccCRelatedItem :: cccItem ( cccCItem* aValue ) {
							scccItem = aValue ;
							// Assign Hand Written Class
								if ( cccRelationClass != 0 ) {
									if ( scccItem -> cccClass ( ) == 0 ) {
										scccItem -> cccClass ( cccRelationClass -> cccClass ( ) ) ;
									}
								}
							// Assign Generic Class
								if ( cccGenericRelationClass != 0 ) {
									if ( scccItem -> cccGenericClass ( ) == 0 ) {
									// Look up the Class of the Relation Class
										cccCRelatedItem* tRelatedItem ;
										// In g Layer
											tRelatedItem = cccGenericRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) ;
										// Or else in ggc Layer
											if ( tRelatedItem == 0 ) {
												tRelatedItem = cccGenericRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) ;
											}
										// Or else in ggg Layer
											if ( tRelatedItem == 0 ) {
												tRelatedItem = cccGenericRelationClass -> cccRelatedItems ( ) -> Item ( "Class" ) ;
											}
										cccCItem* tGenericClass ;
										tGenericClass = tRelatedItem -> cccItem ( ) ;
										scccItem -> cccGenericClass ( tGenericClass ) ;
									}
								}
						} ;



        // Related Lists

			// Constructor & Destructor
				
				cccCRelatedLists :: cccCRelatedLists ( ) {
					// Setup Event Sinks
						// Base
							BaseEventsObject = new BaseEvents ;
							BaseEventsObject -> Parent = this ;
							HoleListInMemory :: EventSink ( BaseEventsObject ) ;
				} ;

				cccCRelatedLists :: ~cccCRelatedLists ( ) {
					Clear ( ) ;
					delete BaseEventsObject ;
					HoleListInMemory :: EventSink ( 0 ) ;
				} ;

			// Public

				// Properties
					
					cccCRelatedList* cccCRelatedLists :: Item ( long aIndex ) {
						return ( cccCRelatedList* ) HoleListInMemory :: Item ( aIndex ) ;
					} ;

					cccCRelatedList* cccCRelatedLists :: Item ( CString aName ) {
						long i ;
						for ( i = 0 ; i <= StorageCount ( ) - 1 ; i ++ ) {
							if ( PositionUsed ( i ) == TRUE ) {
								if ( Item ( i ) != 0 ) {
									if ( Item ( i ) -> cccName == aName ) {
										return Item ( i ) ;
									}
								}
							}
						}
						return 0 ;
					} ;

					CString* cccCRelatedLists :: cccParentName ( ) {
						return cccParent -> cccClassName ( ) ;
					} ;

				// Methods
					
					cccCRelatedList* cccCRelatedLists :: Add ( ) {
						return Item ( HoleListInMemory :: Add ( ) ) ;
					} ;

			// Event Procedures

				void cccCRelatedLists :: BaseEvents :: InitializeItem ( long aIndex ) {
					Parent -> HoleListInMemory :: Item ( aIndex , new cccCRelatedList ) ;
				} ;

				void cccCRelatedLists :: BaseEvents :: TerminateItem ( long aIndex ) {
					delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
				} ;



            // Related List

				// Constructor & Destructor
					
					cccCRelatedList :: cccCRelatedList ( ) {
						// Initialize Pointers
							cccRelationClass = 0 ;
							cccGenericRelationClass = 0 ;
						// Setup Event Sinks
							// Base
								BaseEventsObject = new BaseEvents ;
								BaseEventsObject -> Parent = this ;
								HoleListInMemory :: EventSink ( BaseEventsObject ) ;
					} ;

					cccCRelatedList :: ~cccCRelatedList ( ) {
						Clear ( ) ;
						delete BaseEventsObject ;
						HoleListInMemory :: EventSink ( 0 ) ;
					} ;

				// Public

					// Properties
						
						cccCItem* cccCRelatedList :: cccItem ( long aIndex ) {
							return ( cccCItem* ) HoleListInMemory :: Item ( aIndex ) ;
						} ;
						void cccCRelatedList :: cccItem ( long aIndex , cccCItem* aValue ) {
							HoleListInMemory :: Item ( aIndex , ( void* ) aValue ) ;
							// Assign Hand Written Class
								if ( cccRelationClass != 0 ) {
									if ( aValue -> cccClass ( ) == 0 ) {
										aValue -> cccClass ( cccRelationClass -> cccClass ( ) ) ;
									}
								}
							// Assign Generic Class
								if ( cccGenericRelationClass != 0 ) { // This Related List has a Generic Relation Class assigned to it.
									if ( aValue -> cccGenericClass ( ) == 0 ) { // No class assigned to Item yet.
										// Look up the Class of the Relation Class
											cccCRelatedItem* tRelatedItem ;
											// In g Layer
												tRelatedItem = cccGenericRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) ;
											// Or else in ggc Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = cccGenericRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) ;
												}
											// Or else in ggg Layer
												if ( tRelatedItem == 0 ) {
													tRelatedItem = cccGenericRelationClass -> cccRelatedItems ( ) -> Item ( "Class" ) ;
												}
											cccCItem* tGenericClass ;
											tGenericClass = tRelatedItem -> cccItem ( ) ;
										// Assign the class to the item
										aValue -> cccGenericClass ( tGenericClass ) ;
									}
								}
						} ;

					// Methods
						
						cccCItem* cccCRelatedList :: Add ( ) {
							return ( cccCItem* ) Item ( HoleListInMemory :: Add ( ) ) ;
						} ;

				// Event Procedures

					void cccCRelatedList :: BaseEvents :: InitializeItem ( long aIndex ) {
						Parent -> cccItem ( aIndex , ( cccCItem*) new cccCItem ) ;
					} ;

					void cccCRelatedList :: BaseEvents :: TerminateItem ( long aIndex ) {
						delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
					} ;
