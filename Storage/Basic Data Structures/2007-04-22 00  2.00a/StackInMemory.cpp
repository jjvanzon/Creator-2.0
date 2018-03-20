//
//	Creator . Lists and Trees . Stack . In Memory
//
//		Source Code File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, April 12, 2007
//
// -----

// Includes

	#include "stdafx.h" 
	#include "DeclareClasses.h"

// Public

	// Properties

		long StackInMemory :: Count ( ) {
			return List -> Count ( ) ;
		} ;
		void StackInMemory :: Count ( long aValue ) {
			List -> Count ( aValue ) ;
		} ;

		void* StackInMemory :: Item ( long aIndex ) {
			return List -> Item ( aIndex ) ;
		} ;
		void StackInMemory :: Item ( long aIndex, void *aValue ) {
			List -> Item ( aIndex, aValue ) ;
		} ;

		StackInMemory :: Events* StackInMemory :: EventSink ( ) {
			return sEventSink ;
		} ;
		void StackInMemory :: EventSink ( StackInMemory :: Events* aValue ) {
			sEventSink = aValue ;
		} ;

	// Methods

		void StackInMemory :: Push ( void* aValue ) {
			Count ( Count ( ) + 1 ) ;
		} ;
		void* StackInMemory :: Pop ( ) {
			void* tPop ;
			tPop = Item ( Count ( ) - 1 ) ;
			Count ( Count ( ) - 1 ) ;
			return tPop ;
		} ;

	// Constructor & Destructor

		StackInMemory :: StackInMemory ( ) {
			// Initialize Pointers
				sEventSink = 0 ;
			// Create Objects
				List = new FlatListInMemory ;
			// Setup Event Sinks
				ListEventsObject = new ListEvents ;
				ListEventsObject -> Parent = this ;
				List -> EventSink ( ListEventsObject ) ;
		};

		StackInMemory :: ~StackInMemory ( ) {
			delete List ;
			delete ListEventsObject ;
			List -> EventSink ( 0 ) ; 
		};

// Private

	// Event Procedures

		void StackInMemory :: ListEvents :: CountChanged  ( long aPreviousCount ) {
			if ( Parent -> EventSink ( ) != 0 ) {
				Parent -> EventSink ( ) -> CountChanged ( aPreviousCount ) ;
			}
		};

		void StackInMemory :: ListEvents :: InitializeItem ( long aIndex ) {
			if ( Parent -> EventSink ( ) != 0 ) {
				Parent -> EventSink ( ) -> InitializeItem ( aIndex ) ;
			}
		};

		void StackInMemory :: ListEvents :: TerminateItem ( long aIndex ) {
			if ( Parent -> EventSink ( ) != 0 ) {
				Parent -> EventSink ( ) -> TerminateItem ( aIndex ) ;
			}
		};
