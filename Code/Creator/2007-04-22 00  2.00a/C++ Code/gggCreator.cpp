//
// Creator . ggg Creator
//
//		Generically usable, in Creator items, with a Creator item as a structure
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
	
	// ggg C Creator

		// Constructor & Destructor
			
			gggCCreator :: gggCCreator ( ) {
				ggcCreator = new ggcCCreator ;
				ggcStructure = new cccCItem ;
 				ggcStructure -> cccGenericClass ( ggcCreator -> ggcStructure ) ;
				Build ( ) ;
			} ;

			gggCCreator :: ~gggCCreator ( ) {
				Unbuild ( ) ;
				delete ggcStructure ;
				delete ggcCreator ;
			} ;

		// Private

			// Methods
				
				void gggCCreator :: Build ( ) {

					// Temporary variables for building classes
					
						cccCRelatedLists* ggcStructureRelatedLists ;
						cccCRelatedList* ggcClasses ;
						cccCItem* ggcClassAttribute ;
						cccCItemAttributes* ggcClassProperties ;
						cccCItemAttribute* ggcClassName ;
						cccCRelatedList* ggcClassAttributes ;
						cccCItemAttributes* ggcClassAttributeProperties ;
						cccCItemAttribute* ggcClassAttributeProperty ;

					// Temporary variables for building relations
					
						cccCRelatedList* ggcRelations ;
						cccCItem* ggcRelation ;
						cccCItem* ggcRelationClass ;
						cccCItemAttributes* ggcRelationClassProperties ;
						cccCItemAttribute* ggcRelationClassProperty ;
					
					ggcStructureRelatedLists = ggcStructure -> cccRelatedLists ( ) ;

						// Classes			

							ggcClasses = ggcStructureRelatedLists -> Item ( "ggc Classes" ) ;

								// Structure

									gggStructure = ggcClasses -> Add ( ) ;
										ggcClassProperties = gggStructure -> cccItemAttributes ( ) ;
											ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
												ggcClassName -> cccValue = "Structure" ;

									// Class

										gggClass = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggClass -> cccItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> cccValue = "Class" ;
											ggcClassAttributes = gggClass -> cccRelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
												// Class Name
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  cccItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> cccValue = "Class Name" ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> cccValue = "String" ;

									// Class Attribute

										gggClassAttribute = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggClassAttribute -> cccItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> cccValue = "Class Attribute" ;
											ggcClassAttributes = gggClassAttribute -> cccRelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
												// Name
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  cccItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> cccValue = "Name" ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> cccValue = "String" ;
												// Type
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  cccItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> cccValue = "Type" ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> cccValue = "String" ;

									// Relation
										
										gggRelation = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggRelation -> cccItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> cccValue = "Relation" ;

										// Relation Class

											gggRelationClass = ggcClasses -> Add ( ) ;
												ggcClassProperties = gggRelationClass -> cccItemAttributes ( ) ;
													ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
														ggcClassName -> cccValue = "Relation Class" ;
												ggcClassAttributes = gggRelationClass -> cccRelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
													// Plural
														ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
															ggcClassAttributeProperties = ggcClassAttribute ->  cccItemAttributes ( ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																	ggcClassAttributeProperty -> cccValue = "Plural" ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																	ggcClassAttributeProperty -> cccValue = "Boolean" ;
													// Name
														ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
															ggcClassAttributeProperties = ggcClassAttribute ->  cccItemAttributes ( ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																	ggcClassAttributeProperty -> cccValue = "Name" ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																	ggcClassAttributeProperty -> cccValue = "String" ;
								
								// Item

									gggItem = ggcClasses -> Add ( ) ;
										ggcClassProperties = gggItem -> cccItemAttributes ( ) ;
											ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
												ggcClassName -> cccValue = "Item" ;
								
									// Item Attribute

										gggItemAttribute = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggItemAttribute -> cccItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> cccValue = "Item Attribute" ;
											ggcClassAttributes = gggItemAttribute -> cccRelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
												// Value
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  cccItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> cccValue = "Value" ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> cccValue = "String" ;
								
									// Related Item

										gggRelatedItem = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggRelatedItem -> cccItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> cccValue = "Related Item" ;
								
									// Related List

										gggRelatedList = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggRelatedList -> cccItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> cccValue = "RelatedList" ;

						// Relations

							ggcRelations = ggcStructureRelatedLists -> Item ( "ggc Relations") ;
								
							// Structure To
								
								// To Classes
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggStructure ) ;
											// Relation Class B
												gggStructureClasses = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggStructureClasses -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggStructureClasses -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Classes" ;
								
								// To Relations

									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggStructure ) ;
											// Relation Class B
												gggStructureRelations = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggStructureRelations -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelation ) ;
													// Plural  & Name
														ggcRelationClassProperties = gggStructureRelations -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Relations" ;
									
							// Class To
								
								// To Class Attributes
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClass ) ;
											// Relation Class B
												gggClassClassAttributes = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggClassClassAttributes -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClassAttribute ) ;
													// Plural & Name
														ggcRelationClassProperties = gggClassClassAttributes -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Class Attributes" ;

							// Relation To
								
								// To Relation Class A
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelation ) ;
											// Relation Class B
												gggRelationRelationClassA = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelationRelationClassA -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelationRelationClassA -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Relation Class A" ;

								// To Relation Class B
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelation ) ;
											// Relation Class B
												gggRelationRelationClassB = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelationRelationClassB -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelationRelationClassB -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Relation Class B" ;

							// Relation Class To
								
								// To Class

									// Relation						
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelationClass ) ;
											// Relation Class B
												gggRelationClassClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelationClassClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelationClassClass -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Class" ;

							// Item To
								
								// To Class
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItem ) ;
											// Relation Class B
												gggItemClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggItemClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemClass -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Class" ;

								// To Item Attributes
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItem ) ;
											// Relation Class B
												gggItemItemAttributes = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggItemItemAttributes -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItemAttribute ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemItemAttributes -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Item Attributes" ;

								// To Related Items
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItem ) ;
											// Relation Class B
												gggItemRelatedItems = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggItemRelatedItems -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelatedItem ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemRelatedItems -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Related Items" ;

								// To Related Lists
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItem ) ;
											// Relation Class B
												gggItemRelatedLists = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggItemRelatedLists -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelatedList ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemRelatedLists -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Related Lists" ;

							// Item Attribute To

								// To Class Attribute
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItemAttribute ) ;
											// Relation Class B
												gggItemAttributeClassAttribute = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggItemAttributeClassAttribute -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClassAttribute ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemAttributeClassAttribute -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Class Attribute" ;

							// Related Item To

								// To Relation Class
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelatedItem ) ;
											// Relation Class B
												gggRelatedItemRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelatedItemRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedItemRelationClass -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Relation Class" ;

								// To Item
									
									// Relation 
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelatedItem ) ;
											// Relation Class B
												gggRelatedItemItem = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelatedItemItem -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItem ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedItemItem -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Item" ;

							// Related List To

								// To Relation Class
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelatedList ) ;
											// Relation Class B
												gggRelatedListRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelatedListRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedListRelationClass -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Relation Class" ;

								// To Items
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
										ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
													// Class
														ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelatedList ) ;
											// Relation Class B
												gggRelatedListItems = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
													// Class
														gggRelatedListItems -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggItem ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedListItems -> cccItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> cccValue = "True" ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> cccValue = "Items" ;

						// Construct Related Classes 'Manually'
							
							// Add Relation Between Class and Relation Class
								
								ggcRelation = ggcRelations -> Add ( ) ;
									ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( new cccCItem ) ;
									ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( new cccCItem ) ;
										// Relation Class A
											ggcRelationClass = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
												// Class
													ggcRelationClass -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggClass ) ;
										// Relation Class B
											gggRelatedClasses = ggcRelation -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
												// Class
													gggRelatedClasses -> cccRelatedItems ( ) -> Item ( "ggc Class" ) -> cccItem ( gggRelationClass ) ;
												// Plural & Name
													ggcRelationClassProperties = gggRelatedClasses -> cccItemAttributes ( ) ;
														ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
															ggcRelationClassProperty -> cccValue = "True" ;
														ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
															ggcRelationClassProperty -> cccValue = "Related Classes" ;

							// Add Related Classes As Data
								
								AddQuickAndDirtyRelatedClasses ( ) ;

				} ;

				// Quick & Dirty
				void gggCCreator :: AddQuickAndDirtyRelatedClasses ( ) {
					// Comment:
						// Related List always creates its own items, so I use the base's Add.
					// Declarations
						cccCRelatedList* tRelatedClasses ;
						long tIndex ;
					// Structure . Related Classes
						tRelatedClasses = gggStructure -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ; // Ik zie geen gName waar hij in kan zoeken, alleen maar een gPlural.
						// Structure . Classes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ; 
							tRelatedClasses -> cccItem( tIndex , gggStructureClasses ) ;
						// Structure . Relations
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggStructureRelations ) ;
					// Class . Related Classes
						tRelatedClasses = gggClass -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Class . Class Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggClassClassAttributes ) ;
					// Relation . Related Classes
						tRelatedClasses = gggRelation -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Relation . Relation Class A
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelationRelationClassA ) ;
						// Relation . Relation Class B
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelationRelationClassB ) ;
					// Relation Class . Related Classes
						tRelatedClasses = gggRelationClass -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Relation Class . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelationClassClass ) ;
					// Item . Related Classes
						tRelatedClasses = gggItem -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Item . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggItemClass ) ;
						// Item . Item Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggItemItemAttributes ) ;
						// Item . Related Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggItemRelatedItems ) ;
						// Item . Related Lists
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggItemRelatedLists ) ;
					// Item Attribute . Related Classes
						tRelatedClasses = gggItemAttribute -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Item Attribute . Class Attribute
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggItemAttributeClassAttribute ) ;
					// Related Item . Related Classes
						tRelatedClasses = gggRelatedItem -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Related Item . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelatedItemRelationClass ) ;
						// Related Item . Item
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelatedItemItem ) ;
					// Related List . Related Classes
						tRelatedClasses = gggRelatedList -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Related List . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelatedListRelationClass ) ;
						// Related List . Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem( tIndex , gggRelatedListItems ) ;
					// Add Relation Between Class and Relation Class
						tRelatedClasses = gggClass -> cccRelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , gggRelatedClasses ) ;
				} ;

				void gggCCreator :: QuickAndDirtyReplaceCreator ( cccCItem* aStructureClass ) {
					delete gggStructure ;
					gggStructure = aStructureClass ;
				} ;

				void gggCCreator :: Load ( CString aFilePath ) {
					// Actually adds an extra Creator layer! It's a quick and dirty replacement.
					CParser* tParser ;
					tParser = new CParser ;
					CString* tString ;
					tString = LoadString ( aFilePath ) ;
					tParser -> Creator = this ;
					tParser -> Text = *tString ;
					delete tString ; // Shame I need to copy the string
					tParser -> Parse ( ) ;
					QuickAndDirtyReplaceCreator ( tParser -> Structure -> cccRelatedLists ( ) -> Item ( "Classes" ) -> cccItem ( 0 ) ) ;
					tParser -> Structure = 0 ;
					delete tParser ;
				} ;

				void gggCCreator :: Unbuild ( ) {
					// Also destroy the ones that do not yet have an object reference ...
					/* delete gggStructureClasses ;
					delete gggStructureRelations ;
					delete gggClassClassAttributes ;
					delete gggRelationRelationClassA ;
					delete gggRelationRelationClassB ;
					delete gggRelationClassClass ;
					delete gggItemClass ;
					delete gggItemItemAttributes ;
					delete gggItemRelatedItems ;
					delete gggItemRelatedLists ;
					delete gggItemAttributeClassAttribute ;
					delete gggRelatedItemRelationClass ;
					delete gggRelatedItemItem ;
					delete gggRelatedListRelationClass ;
					delete gggRelatedListItems ;
					delete gggRelatedClasses ; */
					long i ;
					cccCRelatedList* tRelations ;
					cccCItem* tRelationClassAItem;
					cccCItem* tRelationClassBItem;
					tRelations = ggcStructure -> cccRelatedLists ( ) -> Item ( "ggc Relations") ;
					for ( i = 0 ; i <= tRelations -> StorageCount ( ) - 1 ; i ++ ) {
						if ( tRelations -> PositionUsed ( i ) ) {
							tRelationClassAItem = tRelations -> cccItem ( i ) -> cccRelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> cccItem ( ) ;
							tRelationClassBItem = tRelations -> cccItem ( i ) -> cccRelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> cccItem ( ) ;
							delete tRelationClassAItem ;
							delete tRelationClassBItem ;
						}
					}
				} ;