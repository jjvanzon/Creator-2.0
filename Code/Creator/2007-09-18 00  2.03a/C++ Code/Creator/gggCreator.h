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
					
					CItem* gggYourStructure ;

				// Methods

					// void LoadCreator ( CString aFilePath ) ;
					// void QuickAndDirtyReplaceCreator ( CItem* aStructureClass ) ;

		// Private
			
			private :

				// Variables

					ggcCCreator* ggcMyCreator ;
					CItem* ggcMyData ;

					// Variables for gggClasses
								
						CItem* gggClass ;
						CItem* gggClassAttribute ;
						CItem* gggRelation ;
						CItem* gggRelationClass ;
						CItem* gggItem ;
						CItem* gggItemAttribute ;
						CItem* gggRelatedItem ;
						CItem* gggRelatedList ;

					// Variables for gggRelations

						CItem* gggStructureClasses ;
						CItem* gggStructureRelations ;
						CItem* gggClassClassAttributes ;
						CItem* gggRelationRelationClassA ;
						CItem* gggRelationRelationClassB ;
						CItem* gggRelationClassClass ;
						CItem* gggItemClass ;
						CItem* gggItemItemAttributes ;
						CItem* gggItemRelatedItems ;
						CItem* gggItemRelatedLists ;
						CItem* gggItemAttributeClassAttribute ;
						CItem* gggRelatedItemRelationClass ;
						CItem* gggRelatedItemItem ;
						CItem* gggRelatedListRelationClass ;
						CItem* gggRelatedListItems ;
						CItem* gggRelatedClasses ;

				// Methods
					
					void Build ( ) ;
					void AddQuickAndDirtyRelatedClasses ( ) ;
					void Unbuild ( ) ;

	} ;