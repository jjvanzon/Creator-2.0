//
// Creator . ggc Creator
//
//		Generically usable, in Creator items, with a C++ CClass object as a structure.
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
					
					CItem* ggcYourStructure ;

		// Private

			private:

				// Variables

					gccCCreator* gccMyCreator;
					CItem* gccMyData ;

					// Variables for ggcClasses

						CItem* ggcClass ;
						CItem* ggcClassAttribute ;
						CItem* ggcRelation ;
						CItem* ggcRelationClass ;
						CItem* ggcItem ;
						CItem* ggcItemAttribute ;
						CItem* ggcRelatedItem ;
						CItem* ggcRelatedList ;

					// Variables for ggcRelations

						CItem* ggcStructureClasses ;
						CItem* ggcStructureRelations ;
						CItem* ggcClassClassAttributes ;
						CItem* ggcRelationRelationClassA ;
						CItem* ggcRelationRelationClassB ;
						CItem* ggcRelationClassClass ;
						CItem* ggcItemClass ;
						CItem* ggcItemItemAttributes ;
						CItem* ggcItemRelatedItems ;
						CItem* ggcItemRelatedLists ;
						CItem* ggcItemAttributeClassAttribute ;
						CItem* ggcRelatedItemRelationClass ;
						CItem* ggcRelatedItemItem ;
						CItem* ggcRelatedListRelationClass ;
						CItem* ggcRelatedListItems ;
						CItem* ggcRelatedClasses ;

				// Methods
					
					void Build ( ) ;
					void AddQuickAndDirtyRelatedClasses ( ) ;
					void Unbuild ( ) ;

	} ;