//
//	Creator . ccc Creator
//
//		Usable in C++, in C++ objects, with C++ classes for a structure
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Saturday, March 18, 2007 - Sunday, April 22, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Classes

	// Structure

		class CStructure {

			// Constructor & Destructor
				
				public :

					CStructure ( ) ;
					~CStructure ( ) ;

			// Public
				
				public :
				
					// Properties

						private : CClasses* sClasses ; public :
						CClasses* Classes ( ) ;

						private : CRelations* sRelations ; public :
						CRelations* Relations ( ) ;

		};

		// Classes
			
			class CClasses : public HoleListInMemory {

				// Constructor & Destructor
					
					public :
					
						CClasses ( ) ;
						~CClasses ( ) ;

				// Public
					
					public :
						
						// Properties

							CClass* Item ( long aIndex ) ;
							CClass* Item ( CString aName ) ;

						// Methods
							
							CClass* Add ( ) ;

				// Event Procedures

					private : class BaseEvents : public HoleListInMemory :: Events {
						public : CClasses* Parent ;
						// public : void CountChanged ( long aPreviousCount ) ;
						public : void InitializeItem ( long aIndex ) ;
						public : void TerminateItem ( long aIndex ) ;
					} * BaseEventsObject ;
					friend class BaseEvents ;
							
			} ;

            // Class

				class CClass {

					// Constructor & Destructor
						
						public :
							
							CClass ( ) ;
							~CClass ( ) ;

					// Public
						
						public :

							// Variables
								
								CString ClassName ;

							// Properties
								
								CClass* This ( ) { return this ; } ; 

								private : CClassAttributes* sClassAttributes; public :
								CClassAttributes* ClassAttributes ( ) ;

								private : CRelatedClasses* sRelatedClasses; public :
								CRelatedClasses* RelatedClasses ( ) ;

				} ;
					
				// Class Attributes

					class CClassAttributes : public HoleListInMemory {

						// Constructor & Destructor
							
							public :

								CClassAttributes ( ) ;
								~CClassAttributes ( ) ;

						// Public
							
							public :

								// Properties

									CClassAttribute* Item ( long aIndex );
									CClassAttribute* Item ( CString aName ) ;
									
								// Methods
									
									CClassAttribute* Add ( ) ;

						// Event Procedures

							private : class BaseEvents : public HoleListInMemory :: Events {
								public : CClassAttributes* Parent ;
								// public : void CountChanged ( long aPreviousCount ) ;
								public : void InitializeItem ( long aIndex ) ;
								public : void TerminateItem ( long aIndex ) ;
							} * BaseEventsObject ;
							friend class BaseEvents ;

					} ;

                    // Class Attribute
						
						class CClassAttribute {
															
							// Public
								
								public:

									// Variables
										
										CString Name ;
										CString Type ;

						} ;

				// Related Classes
					
					class CRelatedClasses : public HoleListInMemory {

						// Public
							
							public :
								
								// Properties
									
									CRelationClass* Item ( long aIndex ) ;
							
					} ;


        // Relations

			class CRelations : public HoleListInMemory {

				// Constructor & Destructor
					
					public :

						CRelations ( ) ;
						~CRelations ( ) ;

				// Public
					
					public :
						
						// Properties

							CRelation* Item ( long aIndex ) ;

						// Methods
							
							CRelation* Add ( ) ;

				// Event Procedures
				
					private : class BaseEvents : public HoleListInMemory :: Events {
						public : CRelations* Parent ;
						// public : void CountChanged ( long aPreviousCount ) ;
						public : void InitializeItem ( long aIndex ) ;
						public : void TerminateItem ( long aIndex ) ;
					} * BaseEventsObject ;
					friend class BaseEvents ;

				} ;

            // Relation
				
				class CRelation {
					
					// Friends
						
						friend class CRelations :: BaseEvents ;

					// Constructor & Destructor	

						public :

							CRelation ( ) ;
							~CRelation ( ) ;

					// Public
						
						public :
							
							// Properties

								CRelation* This ( ) { return this ; } ;

								private : CRelationClass* sRelationClassA; public :
								CRelationClass* RelationClassA ( ) ;

								private: CRelationClass* sRelationClassB; public :
								CRelationClass* RelationClassB ( ) ;
									
					// Friend
						
						private : void DeregisterRelationInClasses ( ) ; // Accessed by friend CRelations :: BaseEvents
								
				} ;

                // Relation Class
					
					class CRelationClass {

						// Friends	
							
							friend class CRelation ;

						// Constructor & Destructor	

							public :

								CRelationClass ( ) ;
															
						// Public
							
							// Variables
								
								BOOL Plural ;
								CString Name ;
									
							// Properties

								public : CClass* Class ( ) ;
								public : void Class ( CClass* aValue ) ;
								private : CClass* sClass ;

								public : long IdInClassRelatedClasses ( ) ;
								private : void IdInClassRelatedClasses ( long aValue ) ;
								private : long sIdInClassRelatedClasses ;

								public : long IdInRelation ( ) ;
								private : void IdInRelation ( long aValue ) ;
								private : long sIdInRelation ; // Accessed by friend CRelation 

								public : CRelation* Relation ( ) ;
								private : void Relation ( CRelation* aValue ) ;
								private : CRelation* sRelation ; // Accessed by friend CRelation

						// Friend
							
							private : void DeregisterRelationInClass ( ) ; // Accessed by friend CRelation
							private : void RegisterRelationInClass ( ) ; // Accessed by friend CRelation

					} ;



    // Item

        class CItem {
			
			// Construction & Destruction
		
				public :

					CItem ( ) ;
					~CItem ( ) ;

			// Public
				
				public :
					
					// Variables
						
						// BOOL Expanded ; // Quick & Dirty for View Data project 2007-05-03
						
					// Properties
						
						private : CClass* sClass ; public :
						CClass* Class ( ) ;
						void Class ( CClass* aValue ) ;
						
						private : CItem* sGenericClass ; public :
						CItem* GenericClass ( ) ;
						void GenericClass ( CItem* aValue ) ;
						
						private : CItemAttributes* sItemAttributes ; public :
						CItemAttributes* ItemAttributes ( ) ;

						private : CRelatedItems* sRelatedItems ; public :
						CRelatedItems* RelatedItems ( ) ;

						private : CRelatedLists* sRelatedLists ; public :
						CRelatedLists* RelatedLists ( ) ;
							
						CString ClassName ( ) ;

        };

        // Item Atributes

            class CItemAttributes : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
					
					public :
					
						CItemAttributes ( ) ;
						~CItemAttributes ( ) ;

				// Public
					
					public :

						// Properties

							CItemAttribute* Item ( long aIndex ) ;
							CItemAttribute* Item ( CString aName )  ;

							public : CItem* Parent ( ) ;
							private : void Parent ( CItem* aValue ) ; // Accessed by friend CItem
							private : CItem* sParent ;
															
							CString ParentName ( ) ;

						// Methods
							
							CItemAttribute* Add ( ) ;

				// Event Procedures

					private : class BaseEvents : public HoleListInMemory :: Events {
						public : CItemAttributes* Parent ;
						// public : void CountChanged ( long aPreviousCount ) ;
						public : void InitializeItem ( long aIndex ) ;
						public : void TerminateItem ( long aIndex ) ;
					} * BaseEventsObject ;
					friend class BaseEvents ;

            } ;

            // Item Attribute

                class CItemAttribute {
					
					// Friends
						
						friend class CItem ;

					// Constructor & Destructor
						
						public :

							CItemAttribute ( ) ;

					// Public

						public :
							
							// Variables
								
								CClassAttribute* ClassAttribute ;
								CItem* GenericClassAttribute ;
								CString Value ;

									
							// Properties
								
								public : CString Type ( ) ;

								private : CString sName ;
								public : CString Name ( ) ;
								private : void  Name ( CString aValue ) ; // Accessed by friend CItem

                } ;

        // Related Items

            class CRelatedItems : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
					
					public :
					
						CRelatedItems ( ) ;
						~CRelatedItems ( ) ;

				// Public
					
					public :
						
						// Properties

							CRelatedItem* Item ( long aIndex ) ;
							CRelatedItem* Item ( CString aName )  ;

							public : CItem* Parent ( ) ;
							private : void Parent ( CItem* aValue ) ; // Accessed by friend CItem
							private : CItem* sParent ;
															
							CString ParentName ( ) ;
								
						// Methods
							
							CRelatedItem* Add ( ) ;

				// Event Procedures

					private : class BaseEvents : public HoleListInMemory :: Events {
						public : CRelatedItems* Parent ;
						// public : void CountChanged ( long aPreviousCount ) ;
						public : void InitializeItem ( long aIndex ) ;
						public : void TerminateItem ( long aIndex ) ;
					} * BaseEventsObject ;
					friend class BaseEvents ;

            } ;

            // Related Item

                class CRelatedItem {
					
					// Friends
						
						friend class CItem ;

					// Constructor & Destructor
						
						public:
							
							CRelatedItem ( ) ;

					// Public
						
						public:
							
							// Variables

								CRelationClass* RelationClass ;
								CItem* GenericRelationClass ;
																	
							// Properties
								
								private : CItem* sItem ;
								public : CItem* Item ( ) ;
								public : void Item ( CItem* aValue ) ;

								CString ClassName ( ) ;

								private : CString sName ;
								public : CString Name ( ) ;
								private : void  Name ( CString aValue ) ; // Accessed by friend CItem

                } ;

        // Related Lists

            class CRelatedLists : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
					
					public :
					
						CRelatedLists ( ) ;
						~CRelatedLists ( ) ;

				// Public
					
					public :
						
						// Properties

							CRelatedList* Item ( long aIndex ) ;
							CRelatedList* Item ( CString aName )  ;

							public : CItem* Parent ( ) ;
							private : void Parent ( CItem* aValue ) ; // Accessed by friend CItem
							private : CItem* sParent ;
								
							CString ParentName ( ) ;

						// Methods
							
							CRelatedList* Add ( ) ;

				// Event Procedures

					private : class BaseEvents : public HoleListInMemory :: Events {
						public : CRelatedLists* Parent ;
						// public : void CountChanged ( long aPreviousCount ) ;
						public : void InitializeItem ( long aIndex ) ;
						public : void TerminateItem ( long aIndex ) ;
					} * BaseEventsObject ;
					friend class BaseEvents ;

            } ;

            // Related List

                class CRelatedList : public HoleListInMemory {
					
					// Friends
						
						friend class CItem ;

					// Constructor & Destructor
						
						public :
						
							CRelatedList ( ) ;
							~CRelatedList ( ) ;

					// Public
						
						public :

		                    // Variables

								CRelationClass* RelationClass ;
								CItem* GenericRelationClass ;

							// Properties

								CItem* Item ( long aIndex ) ;
								void Item ( long aIndex , CItem* aValue ) ;

								private : CString sName ;
								public : CString Name ( ) ;
								private : void  Name ( CString aValue ) ; // Accessed by friend CItem

							// Methods
								
								public : CItem* Add ( ) ;

					// Event Procedures

						private :

							class BaseEvents : public HoleListInMemory :: Events {
								public : CRelatedList* Parent ;
								// public : void CountChanged ( long aPreviousCount ) ;
								public : void InitializeItem ( long aIndex ) ;
								public : void TerminateItem ( long aIndex ) ;
							} * BaseEventsObject ;
							friend class BaseEvents ;

                } ;
