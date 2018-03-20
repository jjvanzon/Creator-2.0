//
//	Creator . Lists and Trees . Stack . In Memory
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

	class StackInMemory {

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
					void Item ( long aIndex , void *aValue ) ;

					Events* EventSink ( ) ;
					void EventSink ( Events* aValue ) ;

				// Methods

					void Push ( void* aValue ) ;
					void* Pop ( ) ;

				// Constructor & Destructor

					StackInMemory ( ) ;
					~StackInMemory ( ) ;

		// Private

			private :
			
				// Variables

					// Property Storage

						Events* sEventSink ;

					// Objects

						FlatListInMemory* List ;

				// Event Procedures

					class ListEvents : public FlatListInMemory :: Events {
						public :
							void CountChanged ( long aPreviousCount ) ;
							void InitializeItem ( long aIndex ) ;
							void TerminateItem ( long aIndex ) ;
							StackInMemory* Parent ;
					} * ListEventsObject ;

	} ;