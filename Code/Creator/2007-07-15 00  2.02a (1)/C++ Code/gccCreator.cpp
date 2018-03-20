//
// Creator . gcc Creator
//
//		Generically usable, in C++ objects, with C++ objects for a structure.
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, March 22, 2007 - Wednesday, April 11, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Classes
	
	// gcc C Creator

		// Constructor & Destructor

			gccCCreator :: gccCCreator ( ) {
				cccMyData = new CStructure ;
				Build ( ) ;
			} ;

			gccCCreator :: ~gccCCreator ( ) {
				delete cccMyData ;
			} ;

		// Public

			// Methods

				void gccCCreator :: Build ( ) {
					
					CClasses* tClasses ;
					CClassAttributes* tClassAttributes ;
					CClassAttribute* tClassAttribute ;
					CRelations* tRelations ;
					CRelation* tRelation ;
					CRelationClass* tRelationClass ;

					// Classes
						
						tClasses = cccMyData -> Classes ( ) ;

						// Structure

							gccYourStructure = tClasses -> Add ( ) ;
								gccYourStructure -> ClassName = "gcc Structure" ;

							// Class
								
								gccClass = tClasses -> Add ( ) ;
									gccClass -> ClassName = "gcc Class" ;
										tClassAttributes = gccClass -> ClassAttributes ( ) ;
											tClassAttribute = tClassAttributes -> Add ( ) ;
												tClassAttribute -> Name = "gcc Class Name" ;
												tClassAttribute -> Type = "String" ;

								// Class Attribute
									
									gccClassAttribute = tClasses -> Add ( ) ;
										gccClassAttribute -> ClassName = "gcc Class Attribute" ;
											tClassAttributes = gccClassAttribute -> ClassAttributes ( ) ;
												tClassAttribute = tClassAttributes -> Add ( ) ;
													tClassAttribute -> Name = "gcc Name" ;
													tClassAttribute -> Type = "String" ;
												tClassAttribute = tClassAttributes -> Add ( ) ;
													tClassAttribute -> Name = "gcc Type" ;
													tClassAttribute -> Type = "String" ;
							// Relation
								
								gccRelation = tClasses -> Add ( ) ;
									gccRelation -> ClassName = "gcc Relation" ;

									// Relation Class

										gccRelationClass = tClasses -> Add ( ) ;
											gccRelationClass -> ClassName = "gcc Relation Class" ;
												tClassAttributes = gccRelationClass -> ClassAttributes ( ) ;
													tClassAttribute = tClassAttributes -> Add ( ) ;
														tClassAttribute -> Name = "gcc Plural" ;
														tClassAttribute -> Type = "Boolean" ;
													tClassAttribute = tClassAttributes -> Add ( ) ;
														tClassAttribute -> Name = "gcc Name" ;
														tClassAttribute -> Type = "String" ;

						// Item
							
							gccItem = tClasses -> Add ( ) ;
								gccItem -> ClassName = "gcc Item" ;

							// Item Attribute

								gccItemAttribute = tClasses -> Add ( ) ;
									gccItemAttribute -> ClassName = "gcc Item Attribute" ;
										tClassAttributes = gccItemAttribute -> ClassAttributes ( ) ;
											tClassAttribute = tClassAttributes -> Add ( ) ;
												tClassAttribute -> Name = "gcc Value" ;
												tClassAttribute -> Type = "String" ;

							// Related Item
								
								gccRelatedItem = tClasses -> Add ( ) ;
									gccRelatedItem -> ClassName = "gcc Related Item" ;
					
							// Related List
								
								gccRelatedList = tClasses -> Add ( ) ;
									gccRelatedList -> ClassName = "gcc Related List" ;

					// Relations
						
						tRelations = cccMyData -> Relations ( ) ;
							
						// Structure To
							
							// To Classes
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccYourStructure ) ;
										tRelationClass -> Name = "gcc Structure" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccClass ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Classes" ;
											
							// To Relations
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccYourStructure ) ;
										tRelationClass -> Name = "gcc Structure" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelation ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Relations" ;

						// Class To
							
							// To Class Attributes
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccClass ) ;
										tRelationClass -> Name = "gcc Class" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccClassAttribute ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Class Attributes" ;

						// Relation To
							
							// To Relation Class A
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelation ) ;
										tRelationClass -> Name = "gcc Relation ( as relation class a )" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelationClass ) ;
										tRelationClass -> Name = "gcc Relation Class A" ;
							
							// To Relation Class B
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelation ) ;
										tRelationClass -> Name = "gcc Relation ( as relation class b )" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelationClass ) ;
										tRelationClass -> Name = "gcc Relation Class B" ;

						// Relation Class To

							// To Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelationClass ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Relation Class" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccClass ) ;
										tRelationClass -> Name = "gcc Class" ;
									
						// Item To

							// To Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccItem ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Item" ; // !!! Ridiculous to maintain a list of all items of the class.
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccClass ) ;
										tRelationClass -> Name = "gcc Class" ;

							// To Item Attributes
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccItem ) ;
										tRelationClass -> Name = "gcc Item" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccItemAttribute ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Item Attributes" ;

							// To Related Items
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccItem ) ;
										tRelationClass -> Name = "gcc Parent Item" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelatedItem ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Related Items" ;

							// To Related Lists
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccItem ) ;
										tRelationClass -> Name = "gcc Item" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelatedList ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Related List" ;

						// Item Attribute To
							
							// To Class Attribute
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccItemAttribute ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Item Attribute" ; // !!! Ridiculous to maintain a list of all item attributes in every item of this class.
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccClassAttribute ) ;
										tRelationClass -> Name = "gcc Class Attribute" ;

						// Related Item To
							
							// To Relation Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelatedItem ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Related Item" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelationClass ) ;
										tRelationClass -> Name = "gcc Relation Class" ;

							// To Item
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelatedItem ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Related Item" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccItem ) ;
										tRelationClass -> Name = "gcc Item" ;

						// Related List To
							
							// To Relation Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelatedList ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Related List" ;
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelationClass ) ;
										tRelationClass -> Name = "gcc Relation Class" ;
							
							// To Items
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccRelatedList ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc As Related List Item" ; // !!! Also ridiculous to maintain.
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccItem ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Items" ;

					// Construct Related Classes 'Manually'

						// Add Relation Between Class and Relation Class
							
							tRelation = tRelations -> Add ( ) ;
								tRelationClass = tRelation -> RelationClassA ( ) ;
										tRelationClass -> Class ( gccClass ) ;
										tRelationClass -> Plural = FALSE ;
										tRelationClass -> Name = "-" ; // !!! No name for now
									tRelationClass = tRelation -> RelationClassB ( ) ;
										tRelationClass -> Class ( gccRelationClass ) ;
										tRelationClass -> Plural = TRUE ;
										tRelationClass -> Name = "gcc Related Classes" ;

				} ;
