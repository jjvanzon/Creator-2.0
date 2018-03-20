//
//	Creator . Lists and Trees . Flat List . In Memory
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

		long FlatListInMemory :: Count ( ) {
			return sCount ;
		} ;
		void FlatListInMemory :: Count ( long aValue ) {
			// There is separation between increase size and decrease size,
			// and the point at which the Count is stored,
			// because when initialize item and terminate item
			// are called, all positions it is called for, have to be available
			// and Count ( ) has to be large enough.
			if ( aValue < 0 ) aValue = 0 ;
			if ( sCount != aValue ) {
				long tPreviousCount ;
				long i ;
				tPreviousCount = sCount ;
				// Size Gets Larger
					if ( aValue > tPreviousCount ) {
						// Increase Array Size 
							sItem . SetSize ( aValue ) ;
						// Store Count
							sCount = aValue ;
						// Raise Initialize Item
							if ( EventSink ( ) != 0 ) {
								for ( i = tPreviousCount ; i <= aValue - 1 ; i++ ) {
									EventSink ( ) -> InitializeItem ( i ) ;
								}
							}
					}
				// Size Gets Smaller
					if ( aValue < tPreviousCount ) {
						// Raise Terminate Item
							if ( EventSink ( ) != 0 ) {
								for ( i = tPreviousCount - 1 ; i >= aValue ; i-- ) {
									EventSink ( ) -> TerminateItem ( i ) ;
								}
							}
						// Store Count
							sCount = aValue ;
						// Decrease Array Size
							if ( aValue == 0 ) {
								sItem . RemoveAll ( ) ;
							}
							else {
								sItem . SetSize ( aValue ) ;
							}
					}
				// Raise Count Changes
					if ( EventSink ( ) != 0 ) {
						EventSink ( ) -> CountChanged ( tPreviousCount ) ;
					}
			}
		} ;

		void* FlatListInMemory :: Item ( long aIndex ) {
			if ( IndexValid ( aIndex, Count ( ) ) ) return sItem . GetAt ( aIndex ) ; else return 0 ;
		} ;
		FlatListInMemory :: Item ( long aIndex , void *aValue ) {
			if ( IndexValid ( aIndex, Count ( ) ) ) sItem . SetAt ( aIndex, aValue ) ;
		} ;

		FlatListInMemory :: Events* FlatListInMemory :: EventSink ( ) {
			return sEventSink ;
		};
		void FlatListInMemory :: EventSink ( FlatListInMemory :: Events *aValue ) {
			sEventSink = aValue ;
		};

	// Constructor and Destructor

		FlatListInMemory :: FlatListInMemory ( ) {
			// Initialize Variables  (required in C++)
				sCount = 0 ;
			// Initialize Pointers
				sEventSink = 0 ;
			// Initialize Arrays
				sItem . SetSize ( 0 ) ;
		};

		FlatListInMemory :: ~FlatListInMemory ( ) {
			Count ( 0 ) ; 
		};
