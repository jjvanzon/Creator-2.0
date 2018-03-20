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
				cccStructure = new cccCStructure ;
				Build ( ) ;
			} ;

			gccCCreator :: ~gccCCreator ( ) {
				delete cccStructure ;
			} ;

		// Public

			// Methods

				void gccCCreator :: Build ( ) {
					
					cccCClasses* tClasses ;
					cccCClassAttributes* tClassAttributes ;
					cccCClassAttribute* tClassAttribute ;
					cccCRelations* tRelations ;
					cccCRelation* tRelation ;
					cccCRelationClass* tRelationClass ;

					// Classes
						
						tClasses = cccStructure -> cccClasses ( ) ;

						// Structure

							gccStructure = tClasses -> Add ( ) ;
								gccStructure -> cccClassName = "gcc Structure" ;

							// Class
								
								gccClass = tClasses -> Add ( ) ;
									gccClass -> cccClassName = "gcc Class" ;
										tClassAttributes = gccClass -> cccClassAttributes ( ) ;
											tClassAttribute = tClassAttributes -> Add ( ) ;
												tClassAttribute -> cccName = "gcc Class Name" ;
												tClassAttribute -> cccType = "String" ;

								// Class Attribute
									
									gccClassAttribute = tClasses -> Add ( ) ;
										gccClassAttribute -> cccClassName = "gcc Class Attribute" ;
											tClassAttributes = gccClassAttribute -> cccClassAttributes ( ) ;
												tClassAttribute = tClassAttributes -> Add ( ) ;
													tClassAttribute -> cccName = "gcc Name" ;
													tClassAttribute -> cccType = "String" ;
												tClassAttribute = tClassAttributes -> Add ( ) ;
													tClassAttribute -> cccName = "gcc Type" ;
													tClassAttribute -> cccType = "String" ;
							// Relation
								
								gccRelation = tClasses -> Add ( ) ;
									gccRelation -> cccClassName = "gcc Relation" ;

									// Relation Class

										gccRelationClass = tClasses -> Add ( ) ;
											gccRelationClass -> cccClassName = "gcc Relation Class" ;
												tClassAttributes = gccRelationClass -> cccClassAttributes ( ) ;
													tClassAttribute = tClassAttributes -> Add ( ) ;
														tClassAttribute -> cccName = "gcc Plural" ;
														tClassAttribute -> cccType = "Boolean" ;
													tClassAttribute = tClassAttributes -> Add ( ) ;
														tClassAttribute -> cccName = "gcc Name" ;
														tClassAttribute -> cccType = "String" ;

						// Item
							
							gccItem = tClasses -> Add ( ) ;
								gccItem -> cccClassName = "gcc Item" ;

							// Item Attribute

								gccItemAttribute = tClasses -> Add ( ) ;
									gccItemAttribute -> cccClassName = "gcc Item Attribute" ;
										tClassAttributes = gccItemAttribute -> cccClassAttributes ( ) ;
											tClassAttribute = tClassAttributes -> Add ( ) ;
												tClassAttribute -> cccName = "gcc Value" ;
												tClassAttribute -> cccType = "String" ;

							// Related Item
								
								gccRelatedItem = tClasses -> Add ( ) ;
									gccRelatedItem -> cccClassName = "gcc Related Item" ;
					
							// Related List
								
								gccRelatedList = tClasses -> Add ( ) ;
									gccRelatedList -> cccClassName = "gcc Related List" ;

					// Relations
						
						tRelations = cccStructure -> cccRelations ( ) ;
							
						// Structure To
							
							// To Classes
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccStructure ) ;
										tRelationClass -> cccName = "gcc Structure" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccClass ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Classes" ;
											
							// To Relations
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccStructure ) ;
										tRelationClass -> cccName = "gcc Structure" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelation ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Relations" ;

						// Class To
							
							// To Class Attributes
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccClass ) ;
										tRelationClass -> cccName = "gcc Class" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccClassAttribute ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Class Attributes" ;

						// Relation To
							
							// To Relation Class A
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelation ) ;
										tRelationClass -> cccName = "gcc Relation ( as relation class a )" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelationClass ) ;
										tRelationClass -> cccName = "gcc Relation Class A" ;
							
							// To Relation Class B
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelation ) ;
										tRelationClass -> cccName = "gcc Relation ( as relation class b )" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelationClass ) ;
										tRelationClass -> cccName = "gcc Relation Class B" ;

						// Relation Class To

							// To Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelationClass ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Relation Class" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccClass ) ;
										tRelationClass -> cccName = "gcc Class" ;
									
						// Item To

							// To Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccItem ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Item" ; // !!! Ridiculous to maintain a list of all items of the class.
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccClass ) ;
										tRelationClass -> cccName = "gcc Class" ;

							// To Item Attributes
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccItem ) ;
										tRelationClass -> cccName = "gcc Item" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccItemAttribute ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Item Attributes" ;

							// To Related Items
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccItem ) ;
										tRelationClass -> cccName = "gcc Parent Item" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelatedItem ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Related Items" ;

							// To Related Lists
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccItem ) ;
										tRelationClass -> cccName = "gcc Item" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelatedList ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Related List" ;

						// Item Attribute To
							
							// To Class Attribute
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccItemAttribute ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Item Attribute" ; // !!! Ridiculous to maintain a list of all item attributes in every item of this class.
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccClassAttribute ) ;
										tRelationClass -> cccName = "gcc Class Attribute" ;

						// Related Item To
							
							// To Relation Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelatedItem ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Related Item" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelationClass ) ;
										tRelationClass -> cccName = "gcc Relation Class" ;

							// To Item
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelatedItem ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Related Item" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccItem ) ;
										tRelationClass -> cccName = "gcc Item" ;

						// Related List To
							
							// To Relation Class
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelatedList ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Related List" ;
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelationClass ) ;
										tRelationClass -> cccName = "gcc Relation Class" ;
							
							// To Items
								
								tRelation = tRelations -> Add ( ) ;
									tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccRelatedList ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc As Related List Item" ; // !!! Also ridiculous to maintain.
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccItem ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Items" ;

					// Construct Related Classes 'Manually'

						// Add Relation Between Class and Relation Class
							
							tRelation = tRelations -> Add ( ) ;
								tRelationClass = tRelation -> cccRelationClassA ( ) ;
										tRelationClass -> cccClass ( gccClass ) ;
										tRelationClass -> cccPlural = FALSE ;
										tRelationClass -> cccName = "-" ; // !!! No name for now
									tRelationClass = tRelation -> cccRelationClassB ( ) ;
										tRelationClass -> cccClass ( gccRelationClass ) ;
										tRelationClass -> cccPlural = TRUE ;
										tRelationClass -> cccName = "gcc Related Classes" ;

				} ;
