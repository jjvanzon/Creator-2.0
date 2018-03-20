//
// Creator . ggg Creator
//
//		Generically usable, in Creator items, with a Creator item as a structure
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
	
	class gggCCreator {

		// Constructor & Destructor
			
			public :
				
				gggCCreator ( ) ;
				~gggCCreator ( ) ;

		// Public

			public :

				// Variables
					
					ggcCCreator* ggcCreator ;
					cccCItem* ggcStructure ; // Might become 'MyStructure'

					// Variables for gggClasses
								
						cccCItem* gggStructure ;
						cccCItem* gggClass ;
						cccCItem* gggClassAttribute ;
						cccCItem* gggRelation ;
						cccCItem* gggRelationClass ;
						cccCItem* gggItem ;
						cccCItem* gggItemAttribute ;
						cccCItem* gggRelatedItem ;
						cccCItem* gggRelatedList ;

				// Methods

					void Load ( CString aFilePath ) ;
					void QuickAndDirtyReplaceCreator ( cccCItem* aStructureClass ) ;

		// Private
			
			private:

				// Variables

					// Variables for gggRelations

						cccCItem* gggStructureClasses ;
						cccCItem* gggStructureRelations ;
						cccCItem* gggClassClassAttributes ;
						cccCItem* gggRelationRelationClassA ;
						cccCItem* gggRelationRelationClassB ;
						cccCItem* gggRelationClassClass ;
						cccCItem* gggItemClass ;
						cccCItem* gggItemItemAttributes ;
						cccCItem* gggItemRelatedItems ;
						cccCItem* gggItemRelatedLists ;
						cccCItem* gggItemAttributeClassAttribute ;
						cccCItem* gggRelatedItemRelationClass ;
						cccCItem* gggRelatedItemItem ;
						cccCItem* gggRelatedListRelationClass ;
						cccCItem* gggRelatedListItems ;
						cccCItem* gggRelatedClasses ;

				// Methods
					
					void Build ( ) ;
					void AddQuickAndDirtyRelatedClasses ( ) ;
					void Unbuild ( ) ;

	} ;