//
// Creator . ggc Creator
//
//		Generically usable, in Creator items, with a C++ CClass object as a structure.
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
				gccMyCreator = new gccCCreator ;
				gccMyData = new CItem ;
				gccMyData -> Class ( gccMyCreator -> gccYourStructure ) ;
				Build ( ) ;
			} ;

			ggcCCreator :: ~ggcCCreator ( ) {
				Unbuild ( ) ;
				delete gccMyData ;
				delete gccMyCreator ;
			} ;

		// Private
			
			// Methods
				
				void ggcCCreator :: Build ( ) {

					// Temporary variables for building classes
					
						CRelatedLists* gccStructureRelatedLists ;
						CRelatedList* gccClasses ;
						CItem* gccClassAttribute ;
						CItemAttributes* gccClassProperties ;
						CItemAttribute* gccClassName ;
						CRelatedList* gccClassAttributes ;
						CItemAttributes* gccClassAttributeProperties ;
						CItemAttribute* gccClassAttributeProperty ;

					// Temporary variables for building relations
					
						CRelatedList* gccRelations ;
						CItem* gccRelation ;
						CItem* gccRelationClass ;
						CItemAttributes* gccRelationClassProperties ;
						CItemAttribute* gccRelationClassProperty ;
					
					gccStructureRelatedLists = gccMyData -> RelatedLists ( ) ;

						// Classes

							gccClasses = gccStructureRelatedLists -> Item ( "gcc Classes" ) ;

								// Structure

									ggcYourStructure = gccClasses -> Add ( ) ;
										gccClassProperties = ggcYourStructure -> ItemAttributes ( ) ;
											gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
												gccClassName -> Value ( "ggc Structure" ) ;

									// Class

										ggcClass = gccClasses -> Add ( ) ;
											gccClassProperties = ggcClass -> ItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> Value ( "ggc Class" ) ;
											gccClassAttributes = ggcClass -> RelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
												// Class Name
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  ItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> Value ( "ggc Class Name" ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> Value ( "String" ) ;

									// Class Attribute

										ggcClassAttribute = gccClasses -> Add ( ) ;
											gccClassProperties = ggcClassAttribute -> ItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> Value ( "ggc Class Attribute" ) ;
											gccClassAttributes = ggcClassAttribute -> RelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
												// Name
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  ItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> Value ( "ggc Name" ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> Value ( "String" ) ;
												// Type
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  ItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> Value ( "ggc Type" ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> Value ( "String" ) ;

									// Relation
										
										ggcRelation = gccClasses -> Add ( ) ;
											gccClassProperties = ggcRelation -> ItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> Value ( "ggc Relation" ) ;

										// Relation Class

											ggcRelationClass = gccClasses -> Add ( ) ;
												gccClassProperties = ggcRelationClass -> ItemAttributes ( ) ;
													gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
														gccClassName -> Value ( "ggc Relation Class" ) ;
												gccClassAttributes = ggcRelationClass -> RelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
													// Name
														gccClassAttribute = gccClassAttributes -> Add ( ) ;
															gccClassAttributeProperties = gccClassAttribute ->  ItemAttributes ( ) ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																	gccClassAttributeProperty -> Value ( "ggc Plural" ) ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																	gccClassAttributeProperty -> Value ( "Boolean" ) ;
													// Name
														gccClassAttribute = gccClassAttributes -> Add ( ) ;
															gccClassAttributeProperties = gccClassAttribute ->  ItemAttributes ( ) ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																	gccClassAttributeProperty -> Value ( "ggc Name" ) ;
																gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																	gccClassAttributeProperty -> Value ( "String" ) ;
								
								// Item

									ggcItem = gccClasses -> Add ( ) ;
										gccClassProperties = ggcItem -> ItemAttributes ( ) ;
											gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
												gccClassName -> Value ( "ggc Item" ) ;
								
									// Item Attribute

										ggcItemAttribute = gccClasses -> Add ( ) ;
											gccClassProperties = ggcItemAttribute -> ItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> Value ( "ggc Item Attribute" ) ;
											gccClassAttributes = ggcItemAttribute -> RelatedLists ( ) -> Item ( "gcc Class Attributes" ) ;
												// Value
													gccClassAttribute = gccClassAttributes -> Add ( ) ;
														gccClassAttributeProperties = gccClassAttribute ->  ItemAttributes ( ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Name" ) ;
																gccClassAttributeProperty -> Value ( "ggc Value" ) ;
															gccClassAttributeProperty = gccClassAttributeProperties -> Item ( "gcc Type" ) ;
																gccClassAttributeProperty -> Value ( "String" ) ;
								
									// Related Item

										ggcRelatedItem = gccClasses -> Add ( ) ;
											gccClassProperties = ggcRelatedItem -> ItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> Value ( "ggc Related Item" ) ;
								
									// Related List

										ggcRelatedList = gccClasses -> Add ( ) ;
											gccClassProperties = ggcRelatedList -> ItemAttributes ( ) ;
												gccClassName = gccClassProperties -> Item ( "gcc Class Name" ) ;
													gccClassName -> Value ( "ggc Related List" ) ;

						// Relations

							gccRelations = gccStructureRelatedLists -> Item ( "gcc Relations") ;
								
							// Structure To
								
								// To Classes
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcYourStructure ) ;
											// Relation Class B
												ggcStructureClasses = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcStructureClasses -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcStructureClasses -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Classes" ) ;
								
								// To Relations

									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcYourStructure ) ;
											// Relation Class B
												ggcStructureRelations = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcStructureRelations -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelation ) ;
													// Plural  & Name
														gccRelationClassProperties = ggcStructureRelations -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Relations" ) ;
									
							// Class To
								
								// To Class Attributes
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClass ) ;
											// Relation Class B
												ggcClassClassAttributes = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcClassClassAttributes -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClassAttribute ) ;
													// Plural & Name
														gccRelationClassProperties = ggcClassClassAttributes -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Class Attributes" ) ;

							// Relation To
								
								// To Relation Class A
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelation ) ;
											// Relation Class B
												ggcRelationRelationClassA = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelationRelationClassA -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelationRelationClassA -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Relation Class A" ) ;

								// To Relation Class B
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelation ) ;
											// Relation Class B
												ggcRelationRelationClassB = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelationRelationClassB -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelationRelationClassB -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Relation Class B" ) ;

							// Relation Class To
								
								// To Class

									// Relation						
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelationClass ) ;
											// Relation Class B
												ggcRelationClassClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelationClassClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelationClassClass -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Class" ) ;

							// Item To
								
								// To Class
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItem ) ;
											// Relation Class B
												ggcItemClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcItemClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemClass -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Class" ) ;

								// To Item Attributes
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItem ) ;
											// Relation Class B
												ggcItemItemAttributes = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcItemItemAttributes -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItemAttribute ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemItemAttributes -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Item Attributes" ) ;

								// To Related Items
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItem ) ;
											// Relation Class B
												ggcItemRelatedItems = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcItemRelatedItems -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelatedItem ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemRelatedItems -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Related Items" ) ;

								// To Related Lists
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItem ) ;
											// Relation Class B
												ggcItemRelatedLists = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcItemRelatedLists -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelatedList ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemRelatedLists -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Related Lists" ) ;

							// Item Attribute To

								// To Class Attribute
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItemAttribute ) ;
											// Relation Class B
												ggcItemAttributeClassAttribute = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcItemAttributeClassAttribute -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClassAttribute ) ;
													// Plural & Name
														gccRelationClassProperties = ggcItemAttributeClassAttribute -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Class Attribute" ) ;

							// Related Item To

								// To Relation Class
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelatedItem ) ;
											// Relation Class B
												ggcRelatedItemRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelatedItemRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedItemRelationClass -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Relation Class" ) ;

								// To Item
									
									// Relation 
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelatedItem ) ;
											// Relation Class B
												ggcRelatedItemItem = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelatedItemItem -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItem ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedItemItem -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Item" ) ;

							// Related List To

								// To Relation Class
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelatedList ) ;
											// Relation Class B
												ggcRelatedListRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelatedListRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelationClass ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedListRelationClass -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Relation Class" ) ;

								// To Items
									
									// Relation
										gccRelation = gccRelations -> Add ( ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
										gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
											// Relation Class A
												gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
													// Class
														gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelatedList ) ;
											// Relation Class B
												ggcRelatedListItems = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
													// Class
														ggcRelatedListItems -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcItem ) ;
													// Plural & Name
														gccRelationClassProperties = ggcRelatedListItems -> ItemAttributes ( ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
																gccRelationClassProperty -> Value ( "True" ) ;
															gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
																gccRelationClassProperty -> Value ( "ggc Items" ) ;

						// Construct Related Classes 'Manually'
							
							// Add Relation Between Class and Relation Class
								
								gccRelation = gccRelations -> Add ( ) ;
									gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( new CItem ) ;
									gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( new CItem ) ;
										// Relation Class A
											gccRelationClass = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
												// Class
													gccRelationClass -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcClass ) ;
										// Relation Class B
											ggcRelatedClasses = gccRelation -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
												// Class
													ggcRelatedClasses -> RelatedItems ( ) -> Item ( "gcc Class" ) -> Item ( ggcRelationClass ) ;
												// Plural & Name
													gccRelationClassProperties = ggcRelatedClasses -> ItemAttributes ( ) ;
														gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Plural" ) ;
															gccRelationClassProperty -> Value ( "True" ) ;
														gccRelationClassProperty = gccRelationClassProperties -> Item ( "gcc Name" ) ;
															gccRelationClassProperty -> Value ( "ggc Related Classes" ) ;

							// Add Related Classes as Data
								
								AddQuickAndDirtyRelatedClasses ( ) ;

				} ;

				// Quick & Dirty
				void ggcCCreator :: AddQuickAndDirtyRelatedClasses ( ) {
					// Comment:
						// Related List always creates its own items, so I use the base's Add.
					// Declarations
						CRelatedList* tRelatedClasses ;
						long tIndex ;
					// Structure . Related Classes
						tRelatedClasses = ggcYourStructure -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Structure . Classes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ; 
							tRelatedClasses -> Item ( tIndex , ggcStructureClasses ) ;
						// Structure . Relations
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcStructureRelations ) ;
					// Class . Related Classes
						tRelatedClasses = ggcClass -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Class . Class Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcClassClassAttributes ) ;
					// Relation . Related Classes
						tRelatedClasses = ggcRelation -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Relation . Relation Class A
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelationRelationClassA ) ;
						// Relation . Relation Class B
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelationRelationClassB ) ;
					// Relation Class . Related Classes
						tRelatedClasses = ggcRelationClass -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Relation Class . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelationClassClass ) ;
					// Item . Related Classes
						tRelatedClasses = ggcItem -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Item . Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcItemClass ) ;
						// Item . Item Attributes
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcItemItemAttributes ) ;
						// Item . Related Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcItemRelatedItems ) ;
						// Item . Related Lists
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcItemRelatedLists ) ;
					// Item Attribute . Related Classes
						tRelatedClasses = ggcItemAttribute -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Item Attribute . Class Attribute
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcItemAttributeClassAttribute ) ;
					// Related Item . Related Classes
						tRelatedClasses = ggcRelatedItem -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Related Item . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelatedItemRelationClass ) ;
						// Related Item . Item
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelatedItemItem ) ;
					// Related List . Related Classes
						tRelatedClasses = ggcRelatedList -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
						// Related List . Relation Class
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelatedListRelationClass ) ;
						// Related List . Items
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelatedListItems ) ;
					// Add Relation Between Class and Relation Class
						tRelatedClasses = ggcClass -> RelatedLists ( ) -> Item ( "gcc Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , ggcRelatedClasses ) ;
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
					CRelatedList* tRelations ;
					CItem* tRelationClassAItem;
					CItem* tRelationClassBItem;
					tRelations = gccMyData -> RelatedLists ( ) -> Item ( "gcc Relations") ;
					for ( i = 0 ; i <= tRelations -> StorageCount ( ) - 1 ; i ++ ) {
						if ( tRelations -> PositionUsed ( i ) ) {
							tRelationClassAItem = tRelations -> Item ( i ) -> RelatedItems ( ) -> Item ( "gcc Relation Class A" ) -> Item ( ) ;
							tRelationClassBItem = tRelations -> Item ( i ) -> RelatedItems ( ) -> Item ( "gcc Relation Class B" ) -> Item ( ) ;
							delete tRelationClassAItem ;
							delete tRelationClassBItem ;
						}
					}
				} ;
