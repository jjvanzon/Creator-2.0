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

					CClass* gccYourStructure ;

		// Private

			private :

				
				// Variables

					CStructure* cccMyData ;
					CClass* gccClass ;
					CClass* gccClassAttribute ;
					CClass* gccRelation ;
					CClass* gccRelationClass ;
					CClass* gccItem ;
					CClass* gccItemAttribute ;
					CClass* gccRelatedItem ;
					CClass* gccRelatedList ;

				// Methods

					void Build ( ) ;

	} ;
