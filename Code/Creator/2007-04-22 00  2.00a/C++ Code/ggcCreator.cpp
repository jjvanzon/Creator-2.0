//
// Creator . ggc Creator
//
//		Generically usable, in Creator items, with a C++ hCClass object as a structure.
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Saturday, March 24, 2007 - Thursday, April 12, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Classes

	// ggc C Creator
		
		// Constructor & Destructor

			ggcCCreator :: ggcCCreator ( ) {
				gccCreator = new gccCCreator ;
				gccStructure = new cccCItem ;
				gccStructure -> cccClass ( gccCreator -> gccStructure ) ;
				Build ( ) ;
			} ;

			ggcCCreator :: ~ggcCCreator ( ) {
				Unbuild ( ) ;
				delete gccStructure ;
				delete gccCreator ;
				} ;

		// Private
			
			// Methods
				
				void ggcCCreator :: Build ( ) {

					// Temporary variables for building classes
					
						cccCRelatedLists* gccStructureRelatedLists ;
						cccCRelatedList* gccClasses ;
						cccCItem* gccClassAttribute ;
						cccCItemAttributes* gccClassProperties ;
						cccCItemAttribute* gccClassName ;
						cccCRelatedList* gccClassAttributes ;
						cccCItemAttributes* gccClassAttributeProperties ;
						cccCItemAttribute* gccClassAttributeProperty ;

					// Temporary variables for building relations
					
						cccCRelatedList* gccRelations ;
						cccCItem* gccRelation ;
						cccCItem* gccRelationClass ;
						cccCItemAttributes* gccRelationClassProperties ;
						cccCItemAttribute* gccRelationClassProperty ;
					
					gccStructureRelatedLists = gccStructure -> cccRelatedLists ( ) ;

						// Classes

							gccClasses = gccStructureRelatedLists -> Item ( "gcc Classes" ) ;

								// Structure

									ggcStructure = gccClasses -> Add ( ) ;
										gccClassProperties = ggcStructure -> cccItemAttributes ( ) ;
											gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
												gccClassName -> cccValue = "ggc Structure" ;

									// Class

										ggcClass = gccClasses -> Add ( ) ;
											gccClassProperties = ggcClass -> cccItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> cccValue = "ggc Class" ;
											gccClassAttributes = ggcClass -> cccRelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
												// Class Name
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  cccItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> cccValue = "ggc Class Name" ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> cccValue = "String" ;

									// Class Attribute

										ggcClassAttribute = gccClasses -> Add ( ) ;
											gccClassProperties = ggcClassAttribute -> cccItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> cccValue = "ggc Class Attribute" ;
											gccClassAttributes = ggcClassAttribute -> cccRelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
												// Name
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  cccItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> cccValue = "ggc Name" ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> cccValue = "String" ;
												// Type
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  cccItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> cccValue = "ggc Type" ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> cccValue = "String" ;

									// Relation
										
										ggcRelation = gccClasses -> Add ( ) ;
											gccClassProperties = ggcRelation -> cccItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> cccValue = "ggc Relation" ;

										// Relation Class

											ggcRelationClass = gccClasses -> Add ( ) ;
												gccClassProperties = ggcRelationClass -> cccItemAttributes ( ) ;
													gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
														gccClassName -> cccValue = "ggc Relation Class" ;
												gccClassAttributes = ggcRelationClass -> cccRelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
													// Name
														gccClassAttribute = gccClassAttributes -> Add ( ) ;
															gccClassAttributeProperties = gccClassAttribute ->  cccItemAttributes ( ) ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																	gccClassAttributeProperty -> cccValue = "ggc Plural" ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																	gccClassAttributeProperty -> cccValue = "Boolean" ;
													// Name
														gccClassAttribute = gccClassAttributes -> Add ( ) ;
															gccClassAttributeProperties = gccClassAttribute ->  cccItemAttributes ( ) ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																	gccClassAttributeProperty -> cccValue = "ggc Name" ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																	gccClassAttributeProperty -> cccValue = "String" ;
								
								// Item

									ggcItem = gccClasses -> Add ( ) ;
										gccClassProperties = ggcItem -> cccItemAttributes ( ) ;
											gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
												gccClassName -> cccValue = "ggc Item" ;
								
									// Item Attribute

										ggcItemAttribute = gccClasses -> Add ( ) ;
											gccClassProperties = ggcItemAttribute -> cccItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> cccValue = "ggc Item Attribute" ;
											gccClassAttributes = ggcItemAttribute -> cccRelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
												// Value
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  cccItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> cccValue = "ggc Value" ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> cccValue = "String" ;
								
									// Related Item

										ggcRelatedItem = gccClasses -> Add ( ) ;
											gccClassProperties = ggcRelatedItem -> cccItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> cccValue = "ggc Related Item" ;
								
									// Related List

										ggcRelatedList = gccClasses -> Add ( ) ;
											gccClassProperties = ggcRelatedList -> cccItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> cccValue = "ggc Related List" ;

						// Relations

							gccRelations = gccStructureRelatedLists -> Item ( "gcc Relations") ;
								
							// Structure To
								
								// To Classes
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcStructure ) ;
											// Relation Class B
												ggcStructureClasses = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcStructureClasses -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcStructureClasses -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Classes" ;
								
								// To Relations

									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcStructure ) ;
											// Relation Class B
												ggcStructureRelations = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcStructureRelations -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelation ) ;
													// Plural  & Name
														gccRelationClassProperties = ggcStructureRelations -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Relations" ;
									
							// Class To
								
								// To Class Attributes
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClass ) ;
											// Relation Class B
												ggcClassClassAttributes = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcClassClassAttributes -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClassAttribute ) ;
													// Plural & Name
														gccRelationClassProperties = ggcClassClassAttributes -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Class Attributes" ;

							// Relation To
								
								// To Relation Class A
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelation ) ;
											// Relation Class B
												ggcRelationRelationClassA = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelationRelationClassA -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelationRelationClassA -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Relation Class A" ;

								// To Relation Class B
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelation ) ;
											// Relation Class B
												ggcRelationRelationClassB = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelationRelationClassB -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelationRelationClassB -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Relation Class B" ;

							// Relation Class To
								
								// To Class

									// Relation						
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelationClass ) ;
											// Relation Class B
												ggcRelationClassClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelationClassClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelationClassClass -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Class" ;

							// Item To
								
								// To Class
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItem ) ;
											// Relation Class B
												ggcItemClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcItemClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemClass -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Class" ;

								// To Item Attributes
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItem ) ;
											// Relation Class B
												ggcItemItemAttributes = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcItemItemAttributes -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItemAttribute ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemItemAttributes -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Item Attributes" ;

								// To Related Items
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItem ) ;
											// Relation Class B
												ggcItemRelatedItems = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcItemRelatedItems -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelatedItem ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemRelatedItems -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Related Items" ;

								// To Related Lists
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItem ) ;
											// Relation Class B
												ggcItemRelatedLists = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcItemRelatedLists -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelatedList ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemRelatedLists -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Related Lists" ;

							// Item Attribute To

								// To Class Attribute
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItemAttribute ) ;
											// Relation Class B
												ggcItemAttributeClassAttribute = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcItemAttributeClassAttribute -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClassAttribute ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemAttributeClassAttribute -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Class Attribute" ;

							// Related Item To

								// To Relation Class
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelatedItem ) ;
											// Relation Class B
												ggcRelatedItemRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelatedItemRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedItemRelationClass -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Relation Class" ;

								// To Item
									
									// Relation 
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelatedItem ) ;
											// Relation Class B
												ggcRelatedItemItem = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelatedItemItem -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItem ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedItemItem -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Item" ;

							// Related List To

								// To Relation Class
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelatedList ) ;
											// Relation Class B
												ggcRelatedListRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelatedListRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedListRelationClass -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Relation Class" ;

								// To Items
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
													// Class
														gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelatedList ) ;
											// Relation Class B
												ggcRelatedListItems = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
													// Class
														ggcRelatedListItems -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcItem ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedListItems -> cccItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> cccValue = "True" ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> cccValue = "ggc Items" ;

						// Construct Related Classes 'Manually'
							
							// Add Relation Between Class and Relation Class
								
								gccRelation = gccRelations -> Add ( ) ;
									gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( new cccCItem ) ;
									gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( new cccCItem ) ;
										// Relation Class A
											gccRelationClass = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
												// Class
													gccRelationClass -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcClass ) ;
										// Relation Class B
											ggcRelatedClasses = gccRelation -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
												// Class
													ggcRelatedClasses -> cccRelatedItems ( ) -> Item ( "gcc Class" ) -> cccItem ( ggcRelationClass ) ;
												// Plural & Name
													gccRelationClassProperties = ggcRelatedClasses -> cccItemAttributes ( ) ;
														gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
															gccRelationClassProperty -> cccValue = "True" ;
														gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
															gccRelationClassProperty -> cccValue = "ggc Related Classes" ;

							// Add Related Classes as Data
								
								AddQuickAndDirtyRelatedClasses ( ) ;

				} ;

				// Quick & Dirty
				void ggcCCreator :: AddQuickAndDirtyRelatedClasses ( ) {
					// Comment:
						// Related List always creates its own items, so I use the base's Add.
					// Declarations
						cccCRelatedList* tRelatedClasses ;
						long tIndex ;
					// Structure . Related Classes
						tRelatedClasses = ggcStructure -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Structure . Classes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ; 
							tRelatedClasses -> cccItem ( tIndex , ggcStructureClasses ) ;
						// Structure . Relations
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcStructureRelations ) ;
					// Class . Related Classes
						tRelatedClasses = ggcClass -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Class . Class Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcClassClassAttributes ) ;
					// Relation . Related Classes
						tRelatedClasses = ggcRelation -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Relation . Relation Class A
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelationRelationClassA ) ;
						// Relation . Relation Class B
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelationRelationClassB ) ;
					// Relation Class . Related Classes
						tRelatedClasses = ggcRelationClass -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Relation Class . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelationClassClass ) ;
					// Item . Related Classes
						tRelatedClasses = ggcItem -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Item . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcItemClass ) ;
						// Item . Item Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcItemItemAttributes ) ;
						// Item . Related Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcItemRelatedItems ) ;
						// Item . Related Lists
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcItemRelatedLists ) ;
					// Item Attribute . Related Classes
						tRelatedClasses = ggcItemAttribute -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Item Attribute . Class Attribute
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcItemAttributeClassAttribute ) ;
					// Related Item . Related Classes
						tRelatedClasses = ggcRelatedItem -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Related Item . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelatedItemRelationClass ) ;
						// Related Item . Item
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelatedItemItem ) ;
					// Related List . Related Classes
						tRelatedClasses = ggcRelatedList -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Related List . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelatedListRelationClass ) ;
						// Related List . Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelatedListItems ) ;
					// Add Relation Between Class and Relation Class
						tRelatedClasses = ggcClass -> cccRelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , ggcRelatedClasses ) ;
				} ;

				void ggcCCreator :: Unbuild ( ) {
					/* delete ggcStructureClasses ;
					delete ggcStructureRelations ;
					delete ggcClassClassAttributes ;
					delete ggcRelationRelationClassA ;
					delete ggcRelationRelationClassB ;
					delete ggcRelationClassClass ;
					delete ggcItemClass ;
					delete ggcItemItemAttributes ;
					delete ggcItemRelatedItems ;
					delete ggcItemRelatedLists ;
					delete ggcItemAttributeClassAttribute ;
					delete ggcRelatedItemRelationClass ;
					delete ggcRelatedItemItem ;
					delete ggcRelatedListRelationClass ;
					delete ggcRelatedListItems ;
					delete ggcRelatedClasses ; */
					long i ;
					cccCRelatedList* tRelations ;
					cccCItem* tRelationClassAItem;
					cccCItem* tRelationClassBItem;
					tRelations = gccStructure -> cccRelatedLists ( ) -> Item ( "gcc Relations") ;
					for ( i = 0 ; i <= tRelations -> StorageCount ( ) - 1 ; i ++ ) {
						if ( tRelations -> PositionUsed ( i ) ) {
							tRelationClassAItem = tRelations -> cccItem ( i ) -> cccRelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> cccItem ( ) ;
							tRelationClassBItem = tRelations -> cccItem ( i ) -> cccRelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> cccItem ( ) ;
							delete tRelationClassAItem ;
							delete tRelationClassBItem ;
						}
					}
				} ;
