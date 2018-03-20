//
//	Creator . Lists and Trees . Flat List . In Memory
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, April 12, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Class

	class FlatListInMemory {

		// Public

			public :

				// Events

					class Events {
						public :
							virtual void CountChanged ( long aPreviousCount ) { } ;
							virtual void InitializeItem ( long aIndex ) { } ;
							virtual void TerminateItem ( long aIndex ) { } ;
					};

				// Properties

					long Count ( ) ;
					void Count ( long aValue ) ;

					void* Item ( long aIndex ) ;
					Item ( long aIndex, void* aValue ) ;

					Events* EventSink ( ) ;
					void EventSink ( Events* aValue ) ;

				// Constructor and Destructor

					FlatListInMemory ( ) ;
					~FlatListInMemory ( ) ;

		// Private

			private :

				// Variables

					// Property Storage

						long sCount ;
						CArray<void* , void*> sItem ;
						Events* sEventSink ;

	} ;
