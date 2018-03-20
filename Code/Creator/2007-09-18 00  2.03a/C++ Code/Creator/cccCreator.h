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

		class CStructure {

			// Constructor & Destructor
				
				public : CStructure ( ) ;
				public : ~CStructure ( ) ;

			// Public
				
				// Properties

					private : CClasses* sClasses ;
					public : CClasses* Classes ( ) ;

					private : CRelations* sRelations ;
					public : CRelations* Relations ( ) ;

		};

		// Classes
			
			class CClasses : public HoleListInMemory {

				// Constructor & Destructor
					
					public : CClasses ( ) ;
					public : ~CClasses ( ) ;

				// Public
					
					// Properties

						public : CClass* Item ( long aIndex ) ;
						public : CClass* Item ( CString aName ) ;

					// Methods
						
						public : CClass* Add ( ) ;

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
						
						public : CClass ( ) ;
						public : ~CClass ( ) ;

					// Public
						
						// Variables
							
							public : CString ClassName ;

						// Properties
							
							public : CClass* This ( ) { return this ; } ; 

							private : CClassAttributes* sClassAttributes;
							public : CClassAttributes* ClassAttributes ( ) ;

							private : CRelatedClasses* sRelatedClasses;
							public : CRelatedClasses* RelatedClasses ( ) ;

				} ;
					
				// Class Attributes

					class CClassAttributes : public HoleListInMemory {

						// Constructor & Destructor
							
							public : CClassAttributes ( ) ;
							public : ~CClassAttributes ( ) ;

						// Public
							
							// Properties

								public : CClassAttribute* Item ( long aIndex );
								public : CClassAttribute* Item ( CString aName ) ;
								
							// Methods
								
								public : CClassAttribute* Add ( ) ;

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
								
								// Variables
									
									public : CString Name ;
									public : CString Type ;

						} ;

				// Related Classes
					
					class CRelatedClasses : public HoleListInMemory {

						// Public
							
							// Properties
								
								public : CRelationClass* Item ( long aIndex ) ;
							
					} ;


        // Relations

			class CRelations : public HoleListInMemory {

				// Constructor & Destructor
					
					public : CRelations ( ) ;
					public : ~CRelations ( ) ;

				// Public
					
					// Properties

						public : CRelation* Item ( long aIndex ) ;

					// Methods
						
						public : CRelation* Add ( ) ;

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

						public : CRelation ( ) ;
						public : ~CRelation ( ) ;

					// Public
						
						// Properties

							public : CRelation* This ( ) { return this ; } ;

							private : CRelationClass* sRelationClassA ;
							public : CRelationClass* RelationClassA ( ) ;

							private: CRelationClass* sRelationClassB ;
							public : CRelationClass* RelationClassB ( ) ;
									
					// Friend
						
						private : void DeregisterRelationInClasses ( ) ; // Accessed by friend CRelations :: BaseEvents
								
				} ;

                // Relation Class
					
					class CRelationClass {

						// Friends	
							
							friend class CRelation ;

						// Constructor & Destructor	

							public : CRelationClass ( ) ;
															
						// Public
							
							// Variables
								
								public : BOOL Plural ;
								public : CString Name ;
									
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
		
				public : CItem ( ) ;
				public : ~CItem ( ) ;

			// Public
					
				// Properties
					
					public : CClass* Class ( ) ;
					public : void Class ( CClass* aValue ) ;
					private : CClass* sClass ;
					
					public : CItem* GenericClass ( ) ;
					public : void GenericClass ( CItem* aValue ) ;
					private : CItem* sGenericClass ;
					
					public : CItemAttributes* ItemAttributes ( ) ;
					private : CItemAttributes* sItemAttributes ;

					public : CRelatedItems* RelatedItems ( ) ;
					private : CRelatedItems* sRelatedItems ;

					public : CRelatedLists* RelatedLists ( ) ;
					private : CRelatedLists* sRelatedLists ;
					
					public : CItemMethods* ItemMethods ( ) ;
					private : CItemMethods* sItemMethods ;
						
					public : CString ClassName ( ) ;

				// Private Variables
					
					private : HMODULE MethodLibraryHandle ;
					private : ItemExecuteMethod ExecuteMethodProcedureAddress ;

        };

        // Item Atributes

            class CItemAttributes : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
				
					public : CItemAttributes ( ) ;
					public : ~CItemAttributes ( ) ;

				// Public
					
					// Properties

						public : CItemAttribute* Item ( long aIndex ) ;
						public : CItemAttribute* Item ( CString aName )  ;

						public : CItem* ParentItem ( ) ;
						private : void ParentItem ( CItem* aValue ) ; // Accessed by friend CItem
						private : CItem* sParentItem ;
														
						public : CString ParentItemName ( ) ;

					// Methods
						
						public : CItemAttribute* Add ( ) ;

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
						friend class CItemAttributes :: BaseEvents ;

					// Constructor & Destructor
						
						public : CItemAttribute ( ) ;
						public : ~CItemAttribute ( ) ;

					// Public

						// Variables
							
							public :CClassAttribute* ClassAttribute ;
								
						// Properties
							
							public : CString Value ( ) ;
							public : CString ValueBase ( ) ;
							public : void Value ( CString aValue ) ;
							public : void ValueBase ( CString aValue ) ;
							private : CString sValue ;

							public : CItem* GenericClassAttribute ( ) ;
							public : void GenericClassAttribute ( CItem* aValue ) ;
							private : CItem* sGenericClassAttribute ;

							public : CItemAttributes* ItemAttributes ( ) ;
							private : void ItemAttributes ( CItemAttributes* aValue ) ; // Accessed by friend CItemAttributes :: BaseEvents
							private : CItemAttributes* sItemAttributes ;
							
							public : CString Type ( ) ;

							// Stored in the data, for faster searching by name
							private : CString sName ;
							public : CString Name ( ) ;
							private : void  Name ( CString aValue ) ; // Accessed by friend CItem

					// Private Variables
						
						private : HMODULE MethodLibraryHandle ;
						private : AttributeOverrideGet OverrideGetProcedureAddress ;
						private : AttributeOverrideSet OverrideSetProcedureAddress ;

                } ;

        // Related Items

            class CRelatedItems : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
					
					public : CRelatedItems ( ) ;
					public : ~CRelatedItems ( ) ;

				// Public
					
					// Properties

						public : CRelatedItem* Item ( long aIndex ) ;
						public : CRelatedItem* Item ( CString aName )  ;

						public : CItem* ParentItem ( ) ;
						private : void ParentItem ( CItem* aValue ) ; // Accessed by friend CItem
						private : CItem* sParentItem ;
														
						public : CString ParentItemName ( ) ;
							
					// Methods
						
						public : CRelatedItem* Add ( ) ;

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
						friend class CRelatedItems :: BaseEvents ;

					// Constructor & Destructor
						
						public : CRelatedItem ( ) ;
						public : ~CRelatedItem ( ) ;

					// Public
						
						// Variables

							public : CRelationClass* RelationClass ;
																
						// Properties
							
							public : CItem* Item ( ) ;
							public : CItem* ItemBase ( ) ;
							public : void Item ( CItem* aValue ) ;
							public : void ItemBase ( CItem* aValue ) ;
							private : CItem* sItem ;

							public : CItem* GenericRelationClass ( ) ;
							public : void  GenericRelationClass ( CItem* aValue ) ; // Should be made friend
							private : CItem* sGenericRelationClass ;
							// public : CItem* GenericRelationClass ; // Old variable that was turned into a property

							public : CRelatedItems* RelatedItems ( ) ;
							private : void RelatedItems ( CRelatedItems* aValue ) ; // Accessed by friend CRelatedItems :: BaseEvents
							private : CRelatedItems* sRelatedItems ;

							public : CString ClassName ( ) ;

							// Stored in the data, for faster searching by name
							public : CString Name ( ) ;
							private : void  Name ( CString aValue ) ; // Accessed by friend CItem
							private : CString sName ;

					// Private Variables
						
						private : HMODULE MethodLibraryHandle ;
						private : RelatedItemOverrideItemGet OverrideItemGetProcedureAddress ;
						private : RelatedItemOverrideItemSet OverrideItemSetProcedureAddress ;

                } ;

        // Related Lists

            class CRelatedLists : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
					
					public : CRelatedLists ( ) ;
					public : ~CRelatedLists ( ) ;

				// Public
					
					// Properties

						public : CRelatedList* Item ( long aIndex ) ;
						public : CRelatedList* Item ( CString aName )  ;

						public : CItem* ParentItem ( ) ;
						private : void ParentItem ( CItem* aValue ) ; // Accessed by friend CItem
						private : CItem* sParentItem ;
							
						public : CString ParentName ( ) ;

					// Methods
						
						public : CRelatedList* Add ( ) ;

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
						friend class CRelatedLists :: BaseEvents ;

					// Constructor & Destructor
						
						public : CRelatedList ( ) ;
						public : ~CRelatedList ( ) ;

					// Public
						
		                // Variables

							public : CRelationClass* RelationClass ;

						// Properties

							public : CItem* Item ( long aIndex ) ;
							public : CItem* ItemBase ( long aIndex ) ;
							public : void Item ( long aIndex , CItem* aValue ) ;
							public : void ItemBase ( long aIndex , CItem* aValue ) ;

							public : CItem* GenericRelationClass ( ) ;
							public : void  GenericRelationClass ( CItem* aValue ) ; // Should be made friend
							private : CItem* sGenericRelationClass ;

							// Stored in the data, for faster searching by name
							public : CString Name ( ) ;
							private : void  Name ( CString aValue ) ; // Accessed by friend CItem
							private : CString sName ;

							public : CRelatedLists* RelatedLists ( ) ;
							private : void RelatedLists ( CRelatedLists* aValue ) ; // Accessed by friend CRelatedLists :: BaseEvents
							private : CRelatedLists* sRelatedLists ;

						// Methods
							
							public : CItem* Add ( ) ;

					// Private Variables
						
						private : HMODULE MethodLibraryHandle ;
						private : RelatedListOverrideItemGet OverrideItemGetProcedureAddress ;
						private : RelatedListOverrideItemSet OverrideItemSetProcedureAddress ;
						private : RelatedListOverrideInitializeItem OverrideInitializeItemProcedureAddress ;

					// Event Procedures

						private :

							class BaseEvents : public HoleListInMemory :: Events {
								public : CRelatedList* Parent ;
								// public : void CountChanged ( long aPreviousCount ) ;
								public : void InitializeItem ( long aIndex ) ;
								public : void TerminateItem ( long aIndex ) ;
							} * BaseEventsObject ;
							friend class BaseEvents ;

							public : void InitializeItemBase ( long aIndex ) ;

                } ;



        // Item Methods

            class CItemMethods : public HoleListInMemory {

				// Friends
					
					friend class CItem ;

				// Constructor & Destructor
				
					public : CItemMethods ( ) ;
					public : ~CItemMethods ( ) ;

				// Public
					
					// Properties

						public : CItemMethod* Item ( long aIndex ) ;
						public : CItemMethod* Item ( CString aName )  ;

						public : CItem* ParentItem ( ) ;
						private : void ParentItem ( CItem* aValue ) ; // Accessed by friend CItem
						private : CItem* sParentItem ;
														
						public : CString ParentName ( ) ;

					// Methods
						
						public : CItemMethod* Add ( ) ;

				// Event Procedures

					private : class BaseEvents : public HoleListInMemory :: Events {
						public : CItemMethods* Parent ;
						// public : void CountChanged ( long aPreviousCount ) ;
						public : void InitializeItem ( long aIndex ) ;
						public : void TerminateItem ( long aIndex ) ;
					} * BaseEventsObject ;
					friend class BaseEvents ;

            } ;

            // Item Method

                class CItemMethod {
					
					// Friends
						
						friend class CItem ;
						friend class CItemMethods :: BaseEvents ;

					// Constructor & Destructor
						
						public : CItemMethod ( ) ;
						public : ~CItemMethod ( ) ;

					// Public
								
						// Methods
													
							public : void Execute ( ) ;

						// Properties

							public : CItem* GenericClassMethod ( ) ;
							public : void GenericClassMethod ( CItem* aValue ) ;
							private : CItem* sGenericClassMethod ;

							public : CItemMethods* ItemMethods ( ) ;
							private : void ItemMethods ( CItemMethods* aValue ) ; // Accessed by friend CItemMethods :: BaseEvents
							private : CItemMethods* sItemMethods ;

							// Stored in the data, for faster searching by name
							public : CString Name ( ) ;
							private : void  Name ( CString aValue ) ; // Accessed by friend CItem
							private : CString sName ;

					// Private Variables
						
						private : HMODULE MethodLibraryHandle ;
						private : ItemExecuteMethod ExecuteMethodProcedureAddress ;

                } ;
