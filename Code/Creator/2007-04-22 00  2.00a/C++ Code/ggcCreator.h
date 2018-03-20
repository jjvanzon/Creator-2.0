//
// Creator . ggc Creator
//
//		Generically usable, in Creator items, with a C++ hCClass object as a structure.
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, March 22, 2007 - Thursday, April 12, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Classes
	
	class ggcCCreator {
			
		// Constructor & Destructor
			
			public :
				
				ggcCCreator ( ) ;
				~ggcCCreator ( ) ;

		// Public

			public :

				// Variables
					
					cccCItem* gccStructure ; // Might become 'MyStructure'
					
					// Variables for ggcClasses

						cccCItem* ggcStructure ;
						cccCItem* ggcClass ;
						cccCItem* ggcClassAttribute ;
						cccCItem* ggcRelation ;
						cccCItem* ggcRelationClass ;
						cccCItem* ggcItem ;
						cccCItem* ggcItemAttribute ;
						cccCItem* ggcRelatedItem ;
						cccCItem* ggcRelatedList ;

		// Private

			private:

				// Variables

					gccCCreator* gccCreator;

					// Variables for ggcRelations

						cccCItem* ggcStructureClasses ;
						cccCItem* ggcStructureRelations ;
						cccCItem* ggcClassClassAttributes ;
						cccCItem* ggcRelationRelationClassA ;
						cccCItem* ggcRelationRelationClassB ;
						cccCItem* ggcRelationClassClass ;
						cccCItem* ggcItemClass ;
						cccCItem* ggcItemItemAttributes ;
						cccCItem* ggcItemRelatedItems ;
						cccCItem* ggcItemRelatedLists ;
						cccCItem* ggcItemAttributeClassAttribute ;
						cccCItem* ggcRelatedItemRelationClass ;
						cccCItem* ggcRelatedItemItem ;
						cccCItem* ggcRelatedListRelationClass ;
						cccCItem* ggcRelatedListItems ;
						cccCItem* ggcRelatedClasses ;

				// Methods
					
					void Build ( ) ;
					void AddQuickAndDirtyRelatedClasses ( ) ;
					void Unbuild ( ) ;

	} ;