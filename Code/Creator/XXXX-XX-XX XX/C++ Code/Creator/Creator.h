//
// Creator . Creator
//
//		Totally generic Creator loaded from code file.
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Friday, May 4, 2007 - Friday, May 4, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Classes
	
	class CCreator {

		// Constructor & Destructor
		
			public :

				CCreator ( ) ;
				~CCreator ( ) ;

		// Public
			
			public :
				
				// Variables

					CItem* YourStructure ;
						
				// Methods
					
					void QuickAndDirtyReplaceCreator ( CItem* aStructureClass ) ;

					CItem* LoadStructure ( CString aFilePath ) ;

		// Private
			
			private :
				
				// Variables
					
					gggCCreator* gggMyCreator ;
					CItem* gggMyData ;
				
				// Methods
					
					void Load ( ) ;
} ;
