//
// Creator . gcc Creator 
//
//		Generically usable, in C++ objects, with C++ objects for a structure.
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, March 22, 2007 - Wednesday, April 11, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Classes
	
	class gccCCreator {

		// Constructor & Destructor
			
			public :
				
				gccCCreator ( ) ;
				~gccCCreator ( ) ;
				
		// Public
		
			public :

				// Variables

					cccCStructure* cccStructure ; // Might become 'MyStructure'

					cccCClass* gccStructure ;
					cccCClass* gccClass ;
					cccCClass* gccClassAttribute ;
					cccCClass* gccRelation ;
					cccCClass* gccRelationClass ;
					cccCClass* gccItem ;
					cccCClass* gccItemAttribute ;
					cccCClass* gccRelatedItem ;
					cccCClass* gccRelatedList ;

		// Private

			private :

				// Methods

					void Build ( ) ;

	} ;
