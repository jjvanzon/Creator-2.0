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

		class cccCStructure {

			// Constructor & Destructor
				
				public :

					cccCStructure ( ) ;
					~cccCStructure ( ) ;

			// Public
				
				public :
				
					// Properties

						private : cccCClasses* scccClasses ; public :
						cccCClasses* cccClasses ( ) ;

						private : cccCRelations* scccRelations ; public :
						cccCRelations* cccRelations ( ) ;

		};

		// Classes
			
			class cccCClasses : public HoleListInMemory {

				// Constructor & Destructor
					
					public :
					
						cccCClasses ( ) ;
						~cccCClasses ( ) ;

				// Public
					
					public :
						
						// Properties

							cccCClass* Item ( long aIndex ) ;
							cccCClass* Item ( CString aName ) ;

						// Methods
							
							cccCClass* Add ( ) ;

				// Event Procedures

					private :

						class BaseEvents : public HoleListInMemory :: Events {
							public:
								// void CountChanged ( long aPreviousCount ) ;
								void InitializeItem ( long aIndex ) ;
								void TerminateItem ( long aIndex ) ;
								cccCClasses* Parent ;
						} * BaseEventsObject ;
						friend class cccCClasses ;
							
			} ;

            // Class

				class cccCClass {

					// Constructor & Destructor
						
						public :
							
							cccCClass ( ) ;
							~cccCClass ( ) ;

					// Public
						
						public :

							// Variables
								
								CString cccClassName ;

							// Properties
								
								cccCClass* This ( ) { return this ; } ; 

								private : cccCClassAttributes* scccClassAttributes; public :
								cccCClassAttributes* cccClassAttributes ( ) ;

								private : cccCRelatedClasses* scccRelatedClasses; public :
								cccCRelatedClasses* cccRelatedClasses ( ) ;

				} ;
					
				// Class Attributes

					class cccCClassAttributes : public HoleListInMemory {

						// Constructor & Destructor
							
							public :

								cccCClassAttributes ( ) ;
								~cccCClassAttributes ( ) ;

						// Public
							
							public :

								// Properties

									cccCClassAttribute* Item ( long aIndex );
									cccCClassAttribute* Item ( CString aName ) ;
									
								// Methods
									
									cccCClassAttribute* Add ( ) ;

						// Event Procedures

							private:

								class BaseEvents : public HoleListInMemory :: Events {
									public :
										// void CountChanged ( long aPreviousCount ) ;
										void InitializeItem ( long aIndex ) ;
										void TerminateItem ( long aIndex ) ;
										cccCClassAttributes* Parent ;
								} * BaseEventsObject ;
								friend class cccCClassAttributes ;

					} ;

                    // Class Attribute
						
						class cccCClassAttribute {
															
							// Public
								
								public:

									// Variables
										
										CString cccName ;
										CString cccType ;

						} ;

				// Related Classes
					
					class cccCRelatedClasses : public HoleListInMemory {

						// Public
							
							public :
								
								// Properties
									
									cccCRelationClass* Item ( long aIndex ) ;
							
					} ;


        // Relations

			class cccCRelations : public HoleListInMemory {

				// Constructor & Destructor
					
					public :

						cccCRelations ( ) ;
						~cccCRelations ( ) ;

				// Public
					
					public :
						
						// Properties

							cccCRelation* Item ( long aIndex ) ;

						// Methods
							
							cccCRelation* Add ( ) ;

				// Event Procedures
					
					private:

						class BaseEvents : public HoleListInMemory :: Events {
							public:
								// void CountChanged ( long aPreviousCount ) ;
								void InitializeItem ( long aIndex ) ;
								void TerminateItem ( long aIndex ) ;
								cccCRelations *Parent ;
						} * BaseEventsObject ;
						friend class cccCRelations ;

				} ;

            // Relation
				
				class cccCRelation {

					// Constructor & Destructor	

						public :

							cccCRelation ( ) ;
							~cccCRelation ( ) ;

					// Public
						
						public :
							
							// Properties

								cccCRelation* This ( ) { return this ; } ;

								private : cccCRelationClass* scccRelationClassA; public :
								cccCRelationClass* cccRelationClassA ( ) ;

								private: cccCRelationClass* scccRelationClassB; public :
								cccCRelationClass* cccRelationClassB ( ) ;
									
					// Friend
						
						public : 
							
							void DeregisterRelationInClasses ( ) ; // !!! Should become friend
								
				} ;

                // Relation Class
					
					class cccCRelationClass {

					// Constructor & Destructor	

						public :

							cccCRelationClass ( ) ;
															
						// Public
							
							public :

								// Variables
									
									BOOL cccPlural ;
									CString cccName ;
									// !!! Should be read public , write private .
										long cccIdInRelation ;  
										long cccIdInClassRelatedClasses ;
										cccCRelation* cccRelation ; 
										
								// Properties

									private : cccCClass* scccClass ; public :
									cccCClass* cccClass ( ) ;
									void cccClass ( cccCClass* aValue ) ;

						// Friend
							
							public: // !!! Should become private, with friend declarations, but I forgot the friend declaration syntax.
								
								// Methods
									
									void DeregisterRelationInClass ( ) ;
									void RegisterRelationInClass ( ) ;

					} ;



    // Item

        class cccCItem {
			
			// Construction & Destruction
		
				public :

					cccCItem ( ) ;
					~cccCItem ( ) ;

			// Public
				
				public :
						
					// Properties
						
						private : cccCClass* scccClass ; public :
						cccCClass* cccClass ( ) ;
						void cccClass ( cccCClass* aValue ) ;
						
						private : cccCItem* scccGenericClass ; public :
						cccCItem* cccGenericClass ( ) ;
						void cccGenericClass ( cccCItem* aValue ) ;
						
						private : cccCItemAttributes* scccItemAttributes ; public :
						cccCItemAttributes* cccItemAttributes ( ) ;

						private : cccCRelatedItems* scccRelatedItems ; public :
						cccCRelatedItems* cccRelatedItems ( ) ;

						private : cccCRelatedLists* scccRelatedLists ; public :
						cccCRelatedLists* cccRelatedLists ( ) ;
							
						CString* cccClassName ( ) ;

        };

        // Item Atributes

            class cccCItemAttributes : public HoleListInMemory {

				// Constructor & Destructor
					
					public :
					
						cccCItemAttributes ( ) ;
						~cccCItemAttributes ( ) ;

				// Public
					
					public :
						
						// Variables
							
							cccCItem* cccParent ; // !!! Should be public read, friend write

						// Properties

							cccCItemAttribute* Item ( long aIndex ) ;
							cccCItemAttribute* Item ( CString aName )  ;
								
							CString* cccParentName ( ) ;

						// Methods
							
							cccCItemAttribute* Add ( ) ;

				// Event Procedures

					private :

						class BaseEvents : public HoleListInMemory :: Events {
							public:
								// void CountChanged ( long aPreviousCount ) ;
								void InitializeItem ( long aIndex ) ;
								void TerminateItem ( long aIndex ) ;
								cccCItemAttributes* Parent ;
						} * BaseEventsObject ;
						friend class cccCItemAttributes ;

            } ;

            // Item Attribute

                class cccCItemAttribute {

					// Constructor & Destructor
						
						public :

							cccCItemAttribute ( ) ;

					// Public

						public :
							
							// Variables
								
								cccCClassAttribute* cccClassAttribute ;
								cccCItem* cccGenericClassAttribute ;
								CString cccValue ;
								CString cccName ; // Should be public read, friend write

                } ;

        // Related Items

            class cccCRelatedItems : public HoleListInMemory {

				// Constructor & Destructor
					
					public :
					
						cccCRelatedItems ( ) ;
						~cccCRelatedItems ( ) ;

				// Public
					
					public :
						
						// Variables
							
							cccCItem* cccParent ; // !!! Should be public read, friend write
						
						// Properties

							cccCRelatedItem* Item ( long aIndex ) ;
							cccCRelatedItem* Item ( CString aName )  ;
								
							CString* cccParentName ( ) ;
								
						// Methods
							
							cccCRelatedItem* Add ( ) ;

				// Event Procedures

					private :

						class BaseEvents : public HoleListInMemory :: Events {
							public:
								// void CountChanged ( long aPreviousCount ) ;
								void InitializeItem ( long aIndex ) ;
								void TerminateItem ( long aIndex ) ;
								cccCRelatedItems* Parent ;
						} * BaseEventsObject ;
						friend class cccCRelatedItems ;

            } ;

            // Related Item

                class cccCRelatedItem {
					
					// Constructor & Destructor
						
						public:
							
							cccCRelatedItem ( ) ;

					// Public
						
						public:
							
							// Variables

								cccCRelationClass* cccRelationClass ;
								cccCItem* cccGenericRelationClass ;
								CString cccName ; // Should be public read, friend write
																	
							// Properties
								
								private : cccCItem* scccItem ; public :
								cccCItem* cccItem ( ) ;
								void cccItem ( cccCItem* aValue ) ;

                } ;

        // Related Lists

            class cccCRelatedLists : public HoleListInMemory {

				// Constructor & Destructor
					
					public :
					
						cccCRelatedLists ( ) ;
						~cccCRelatedLists ( ) ;

				// Public
					
					public :

						// Variables

							cccCItem* cccParent ; // !!! Should be public read, friend write
						
						// Properties

							cccCRelatedList* Item ( long aIndex ) ;
							cccCRelatedList* Item ( CString aName )  ;
								
							CString* cccParentName ( ) ;

						// Methods
							
							cccCRelatedList* Add ( ) ;

				// Event Procedures

					private :

						class BaseEvents : public HoleListInMemory :: Events {
							public:
								// void CountChanged ( long aPreviousCount ) ;
								void InitializeItem ( long aIndex ) ;
								void TerminateItem ( long aIndex ) ;
								cccCRelatedLists* Parent ;
						} * BaseEventsObject ;
						friend class cccCRelatedLists ;

            } ;

            // Related List

                class cccCRelatedList : public HoleListInMemory {

					// Constructor & Destructor
						
						public :
						
							cccCRelatedList ( ) ;
							~cccCRelatedList ( ) ;

					// Public
						
						public :

		                    // Variables

								cccCRelationClass* cccRelationClass ;
								cccCItem* cccGenericRelationClass ;
								CString cccName ; // Should be public read, friend write

							// Properties

								cccCItem* cccItem ( long aIndex ) ;
								void cccItem ( long aIndex , cccCItem* aValue ) ;

							// Methods
								
								cccCItem* Add ( ) ;

					// Event Procedures

						private :

							class BaseEvents : public HoleListInMemory :: Events {
								public:
									// void CountChanged ( long aPreviousCount ) ;
									void InitializeItem ( long aIndex ) ;
									void TerminateItem ( long aIndex ) ;
									cccCRelatedList* Parent ;
							} * BaseEventsObject ;
							friend class cccCRelatedList ;

                } ;
