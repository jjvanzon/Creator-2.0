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
				ggcMyCreator = new ggcCCreator ;
				ggcMyData = new CItem ;
 				ggcMyData -> GenericClass ( ggcMyCreator -> ggcYourStructure ) ;
				Build ( ) ;
			} ;

			gggCCreator :: ~gggCCreator ( ) {
				Unbuild ( ) ;
				delete ggcMyData ;
				delete ggcMyCreator ;
			} ;

		// Private

			// Methods
				
				void gggCCreator :: Build ( ) {

					// Temporary variables for building classes
					
						CRelatedLists* ggcStructureRelatedLists ;
						CRelatedList* ggcClasses ;
						CItem* ggcClassAttribute ;
						CItemAttributes* ggcClassProperties ;
						CItemAttribute* ggcClassName ;
						CRelatedList* ggcClassAttributes ;
						CItemAttributes* ggcClassAttributeProperties ;
						CItemAttribute* ggcClassAttributeProperty ;

					// Temporary variables for building relations
					
						CRelatedList* ggcRelations ;
						CItem* ggcRelation ;
						CItem* ggcRelationClass ;
						CItemAttributes* ggcRelationClassProperties ;
						CItemAttribute* ggcRelationClassProperty ;
					
					ggcStructureRelatedLists = ggcMyData -> RelatedLists ( ) ;

						// Classes			

							ggcClasses = ggcStructureRelatedLists -> Item ( "ggc Classes" ) ;

								// Structure

									gggYourStructure = ggcClasses -> Add ( ) ;
										ggcClassProperties = gggYourStructure -> ItemAttributes ( ) ;
											ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
												ggcClassName -> Value ( "Structure" ) ;

									// Class

										gggClass = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggClass -> ItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> Value ( "Class" ) ;
											ggcClassAttributes = gggClass -> RelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
												// Class Name
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> Value ( "Class Name" ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> Value ( "String" ) ;

									// Class Attribute

										gggClassAttribute = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggClassAttribute -> ItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> Value ( "Class Attribute" ) ;
											ggcClassAttributes = gggClassAttribute -> RelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
												// Name
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> Value ( "Name" ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> Value ( "String" ) ;
												// Type
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> Value ( "Type" ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> Value ( "String" ) ;

									// Relation
										
										gggRelation = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggRelation -> ItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> Value ( "Relation" ) ;

										// Relation Class

											gggRelationClass = ggcClasses -> Add ( ) ;
												ggcClassProperties = gggRelationClass -> ItemAttributes ( ) ;
													ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
														ggcClassName -> Value ( "Relation Class" ) ;
												ggcClassAttributes = gggRelationClass -> RelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
													// Plural
														ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
															ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																	ggcClassAttributeProperty -> Value ( "Plural" ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																	ggcClassAttributeProperty -> Value ( "Boolean" ) ;
													// Name
														ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
															ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																	ggcClassAttributeProperty -> Value ( "Name" ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																	ggcClassAttributeProperty -> Value ( "String" ) ;
													// Direction  ( Quick & Dirty solution, substituting  Relation Class  ->  Relation ( as relation class a )  =  Something )
														ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
															ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																	ggcClassAttributeProperty -> Value ( "Direction" ) ;
																ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																	ggcClassAttributeProperty -> Value ( "String" ) ;
								
								// Item

									gggItem = ggcClasses -> Add ( ) ;
										ggcClassProperties = gggItem -> ItemAttributes ( ) ;
											ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
												ggcClassName -> Value ( "Item" ) ;
								
									// Item Attribute

										gggItemAttribute = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggItemAttribute -> ItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> Value ( "Item Attribute" ) ;
											ggcClassAttributes = gggItemAttribute -> RelatedLists ( ) -> Item ( "ggc Class Attributes" ) ;
												// Value
													ggcClassAttribute = ggcClassAttributes -> Add ( ) ;
														ggcClassAttributeProperties = ggcClassAttribute ->  ItemAttributes ( ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Name" ) ;
																ggcClassAttributeProperty -> Value ( "Value" ) ;
															ggcClassAttributeProperty = ggcClassAttributeProperties -> Item ( "ggc Type" ) ;
																ggcClassAttributeProperty -> Value ( "String" ) ;
								
									// Related Item

										gggRelatedItem = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggRelatedItem -> ItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> Value ( "Related Item" ) ;
								
									// Related List

										gggRelatedList = ggcClasses -> Add ( ) ;
											ggcClassProperties = gggRelatedList -> ItemAttributes ( ) ;
												ggcClassName = ggcClassProperties -> Item ( "ggc Class Name" ) ;
													ggcClassName -> Value ( "RelatedList" ) ;

						// Relations

							ggcRelations = ggcStructureRelatedLists -> Item ( "ggc Relations") ;
								
							// Structure To
								
								// To Classes
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggYourStructure ) ;
											// Relation Class B
												gggStructureClasses = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggStructureClasses -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggStructureClasses -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Classes" ) ;
								
								// To Relations

									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggYourStructure ) ;
											// Relation Class B
												gggStructureRelations = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggStructureRelations -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelation ) ;
													// Plural  & Name
														ggcRelationClassProperties = gggStructureRelations -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Relations" ) ;
									
							// Class To
								
								// To Class Attributes
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClass ) ;
											// Relation Class B
												gggClassClassAttributes = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggClassClassAttributes -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClassAttribute ) ;
													// Plural & Name
														ggcRelationClassProperties = gggClassClassAttributes -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Class Attributes" ) ;

							// Relation To
								
								// To Relation Class A
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelation ) ;
											// Relation Class B
												gggRelationRelationClassA = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelationRelationClassA -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelationRelationClassA -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Relation Class A" ) ;

								// To Relation Class B
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelation ) ;
											// Relation Class B
												gggRelationRelationClassB = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelationRelationClassB -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelationRelationClassB -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Relation Class B" ) ;

							// Relation Class To
								
								// To Class

									// Relation						
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelationClass ) ;
											// Relation Class B
												gggRelationClassClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelationClassClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelationClassClass -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Class" ) ;

							// Item To
								
								// To Class
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItem ) ;
											// Relation Class B
												gggItemClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggItemClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemClass -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Class" ) ;

								// To Item Attributes
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItem ) ;
											// Relation Class B
												gggItemItemAttributes = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggItemItemAttributes -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItemAttribute ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemItemAttributes -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Item Attributes" ) ;

								// To Related Items
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItem ) ;
											// Relation Class B
												gggItemRelatedItems = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggItemRelatedItems -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelatedItem ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemRelatedItems -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Related Items" ) ;

								// To Related Lists
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItem ) ;
											// Relation Class B
												gggItemRelatedLists = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggItemRelatedLists -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelatedList ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemRelatedLists -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Related Lists" ) ;

							// Item Attribute To

								// To Class Attribute
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItemAttribute ) ;
											// Relation Class B
												gggItemAttributeClassAttribute = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggItemAttributeClassAttribute -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClassAttribute ) ;
													// Plural & Name
														ggcRelationClassProperties = gggItemAttributeClassAttribute -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Class Attribute" ) ;

							// Related Item To

								// To Relation Class
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelatedItem ) ;
											// Relation Class B
												gggRelatedItemRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelatedItemRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedItemRelationClass -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Relation Class" ) ;

								// To Item
									
									// Relation 
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelatedItem ) ;
											// Relation Class B
												gggRelatedItemItem = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelatedItemItem -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItem ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedItemItem -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Item" ) ;

							// Related List To

								// To Relation Class
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelatedList ) ;
											// Relation Class B
												gggRelatedListRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelatedListRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelationClass ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedListRelationClass -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Relation Class" ) ;

								// To Items
									
									// Relation
										ggcRelation = ggcRelations -> Add ( ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
										ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
													// Class
														ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelatedList ) ;
											// Relation Class B
												gggRelatedListItems = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
													// Class
														gggRelatedListItems -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggItem ) ;
													// Plural & Name
														ggcRelationClassProperties = gggRelatedListItems -> ItemAttributes ( ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
																ggcRelationClassProperty -> Value ( "True" ) ;
															ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
																ggcRelationClassProperty -> Value ( "Items" ) ;

						// Construct Related Classes 'Manually'
							
							// Add Relation Between Class and Relation Class
								
								ggcRelation = ggcRelations -> Add ( ) ;
									ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( new CItem ) ;
									ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( new CItem ) ;
										// Relation Class A
											ggcRelationClass = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
												// Class
													ggcRelationClass -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggClass ) ;
										// Relation Class B
											gggRelatedClasses = ggcRelation -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
												// Class
													gggRelatedClasses -> RelatedItems ( ) -> Item ( "ggc Class" ) -> Item ( gggRelationClass ) ;
												// Plural & Name
													ggcRelationClassProperties = gggRelatedClasses -> ItemAttributes ( ) ;
														ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Plural" ) ;
															ggcRelationClassProperty -> Value ( "True" ) ;
														ggcRelationClassProperty = ggcRelationClassProperties -> Item ( "ggc Name" ) ;
															ggcRelationClassProperty -> Value ( "Related Classes" ) ;

							// Add Related Classes As Data
								
								AddQuickAndDirtyRelatedClasses ( ) ;

				} ;

				// Quick & Dirty
				void gggCCreator :: AddQuickAndDirtyRelatedClasses ( ) {
					// Comment:
						// Related List always creates its own items, so I use the base's Add.
					// Declarations
						CRelatedList* tRelatedClasses ;
						long tIndex ;
					// Structure . Related Classes
						tRelatedClasses = gggYourStructure -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ; // Ik zie geen gName waar hij in kan zoeken, alleen maar een gPlural.
						// Structure . Classes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ; 
							tRelatedClasses -> Item( tIndex , gggStructureClasses ) ;
						// Structure . Relations
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggStructureRelations ) ;
					// Class . Related Classes
						tRelatedClasses = gggClass -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Class . Class Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggClassClassAttributes ) ;
					// Relation . Related Classes
						tRelatedClasses = gggRelation -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Relation . Relation Class A
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelationRelationClassA ) ;
						// Relation . Relation Class B
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelationRelationClassB ) ;
					// Relation Class . Related Classes
						tRelatedClasses = gggRelationClass -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Relation Class . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelationClassClass ) ;
					// Item . Related Classes
						tRelatedClasses = gggItem -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Item . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggItemClass ) ;
						// Item . Item Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggItemItemAttributes ) ;
						// Item . Related Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggItemRelatedItems ) ;
						// Item . Related Lists
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggItemRelatedLists ) ;
					// Item Attribute . Related Classes
						tRelatedClasses = gggItemAttribute -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Item Attribute . Class Attribute
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggItemAttributeClassAttribute ) ;
					// Related Item . Related Classes
						tRelatedClasses = gggRelatedItem -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Related Item . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelatedItemRelationClass ) ;
						// Related Item . Item
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelatedItemItem ) ;
					// Related List . Related Classes
						tRelatedClasses = gggRelatedList -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
						// Related List . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelatedListRelationClass ) ;
						// Related List . Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item( tIndex , gggRelatedListItems ) ;
					// Add Relation Between Class and Relation Class
						tRelatedClasses = gggClass -> RelatedLists ( ) -> Item ( "ggc Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , gggRelatedClasses ) ;
				} ;

				/*
				void gggCCreator :: LoadCreator ( CString aFilePath ) {
					// Actually adds an extra Creator layer! It's a quick and dirty replacement.
					CParser* tParser ;
					tParser = new CParser ;
					CString* tString ;
					tString = LoadString ( aFilePath ) ;
					tParser -> gggCreator = this ;
					tParser -> Text = *tString ;
					delete tString ; // Shame I need to copy the string
					tParser -> Parse ( ) ;
					QuickAndDirtyReplaceCreator ( tParser -> Structure -> RelatedLists ( ) -> Item ( "Classes" ) -> Item ( 0 ) ) ;
					tParser -> Structure = 0 ;
					delete tParser ;
				} ;
				*/

				/*
				void gggCCreator :: QuickAndDirtyReplaceCreator ( CItem* aStructureClass ) {
					delete gggYourStructure ; // Should it be deleted? Should even more be deleted?
					gggYourStructure = aStructureClass ;
				} ;
				*/

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
					CRelatedList* tRelations ;
					CItem* tRelationClassAItem;
					CItem* tRelationClassBItem;
					tRelations = ggcMyData -> RelatedLists ( ) -> Item ( "ggc Relations") ;
					for ( i = 0 ; i <= tRelations -> StorageCount ( ) - 1 ; i ++ ) {
						if ( tRelations -> PositionUsed ( i ) ) {
							tRelationClassAItem = tRelations -> Item ( i ) -> RelatedItems ( ) -> Item ( "ggc Relation Class A" ) -> Item ( ) ;
							tRelationClassBItem = tRelations -> Item ( i ) -> RelatedItems ( ) -> Item ( "ggc Relation Class B" ) -> Item ( ) ;
							delete tRelationClassAItem ;
							delete tRelationClassBItem ;
						}
					}
				} ;