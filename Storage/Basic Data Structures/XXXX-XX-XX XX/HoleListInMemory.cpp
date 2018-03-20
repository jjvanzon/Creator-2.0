//
//	Creator . Lists and Trees . Hole List . In Memory
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

// Constructor and Destructor

	HoleListInMemory :: HoleListInMemory ( ) {
		// Initialize Variables  (required in C++)
			AllowRemoveAccessory = FALSE ;
			NoReuse = FALSE ;
		// Initialize Pointers
			sEventSink = 0 ;
		// Create Objects
			List = new FlatListInMemory ;
			FreePositionStack = new StackInMemory ;
			PositionUsedList = new FlatListInMemory ;
		// Setup Event Sinks
			// List
				ListEventsObject = new ListEvents ;
				ListEventsObject -> Parent = this ;
				List -> EventSink ( ListEventsObject ) ;
			// Position Used List
				PositionUsedListEventsObject = new PositionUsedListEvents ;
				PositionUsedListEventsObject -> Parent = this ;
				PositionUsedList -> EventSink ( PositionUsedListEventsObject ) ;
			// Free Position Stack
				FreePositionStackEventsObject = new FreePositionStackEvents ;
				FreePositionStackEventsObject -> Parent = this ;
				FreePositionStack -> EventSink ( FreePositionStackEventsObject ) ;
		// Initialize Values
			FreePositionStack -> Count ( FreePositionStackSystemRecords ( ) ) ;
			long* tLong = new long ;
			* tLong = 0 ;
			FreePositionStack -> Item ( ListCountPosition ( ) , tLong ) ;
	} ;

	HoleListInMemory :: ~HoleListInMemory ( ) {
		delete FreePositionStack -> Item ( ListCountPosition ( ) ) ;
		delete FreePositionStack ;
		delete PositionUsedList ;
		delete List ;
		delete FreePositionStackEventsObject ;
		delete PositionUsedListEventsObject ;
		delete ListEventsObject ;
		FreePositionStack -> EventSink ( 0 ) ; // Why the hell would this be ok, after the object called upon is destroyed?
		PositionUsedList -> EventSink ( 0 ) ; // Why the hell would this be ok, after the object called upon is destroyed?
		List -> EventSink ( 0 ) ;  // Why the hell would this be ok, after the object called upon is destroyed?
	} ;

// Public

	// Properties

		long HoleListInMemory :: StorageCount ( ) {
			return List -> Count ( ) ;
		} ;
		void HoleListInMemory :: StorageCount ( long aValue ) {
			PositionUsedList -> Count ( aValue ) ;
			List -> Count ( aValue ) ;
		} ;

		long HoleListInMemory :: ListCount ( ) {
			return * ( long* ) FreePositionStack -> Item ( ListCountPosition ( ) ) ;
		} ;
		void HoleListInMemory :: ListCount ( long aValue ) { // Private
			long* tLong ;
			tLong = ( long* ) FreePositionStack -> Item ( ListCountPosition ( ) ) ;
			*tLong = aValue ;
		};

		void* HoleListInMemory :: Item ( long aIndex ) {
			return List -> Item ( aIndex ) ;
		};
		void HoleListInMemory :: Item ( long  aIndex , void* aValue ) {
			List -> Item ( aIndex , aValue ) ;
		};

		BOOL HoleListInMemory :: PositionUsed ( long aIndex ) {
			if ( IndexValid ( aIndex , StorageCount ( ) ) ) {
				return * ( BOOL* ) PositionUsedList -> Item ( aIndex ) ;
			}
			else {
				return FALSE ;
			}
		};
		void HoleListInMemory :: PositionUsed ( long aIndex , BOOL aValue ) { // Private
			BOOL* tBoolean ;
			tBoolean = ( BOOL* ) PositionUsedList -> Item ( aIndex ) ;
			*tBoolean = aValue ;
		};

		long HoleListInMemory :: FreePositions ( ) {
			return FreePositionStack -> Count ( ) ;
		};
			
		long HoleListInMemory :: FreePosition ( long aIndex ) {
			return * ( long* ) FreePositionStack -> Item ( aIndex + 1 ) ;
		} ;

		// Access to Base

			FlatListInMemory* HoleListInMemory :: BaseList ( ) {
				return List ;
			} ;

			StackInMemory* HoleListInMemory :: BaseFreePositionStack ( ) {
				return FreePositionStack ;
			} ;

			FlatListInMemory* HoleListInMemory :: BasePositionUsedList ( ) {
				return PositionUsedList ;
			} ;

		// Event Sink

			HoleListInMemory :: Events* HoleListInMemory :: EventSink ( ) {
				return sEventSink ;
			} ;
			void HoleListInMemory :: EventSink ( HoleListInMemory :: Events* aValue ) {
				sEventSink = aValue ;
			} ;

	// Methods

		long HoleListInMemory :: Add ( ) {
			long tAdd ;
            tAdd = PopFreePosition ( ) ;
            PositionUsed ( tAdd , TRUE ) ;
            ListCount ( ListCount ( ) + 1 ) ;
			if ( EventSink ( ) != 0 ) { EventSink ( ) -> InitializeItem ( tAdd ) ; }
			return tAdd;
		} ;
			
		long HoleListInMemory :: Add ( void* aItem ) {
			long tIndex = Add ( ) ;
			HoleListInMemory :: Item ( tIndex , aItem ) ;
			return tIndex ;
		} ;

		BOOL HoleListInMemory :: Remove ( long aIndex ) {
            if ( IndexValid ( aIndex , StorageCount ( ) ) == FALSE ) return FALSE ;
            if ( PositionUsed ( aIndex ) == FALSE ) return FALSE ;
            if ( EventSink ( ) != 0 ) { EventSink ( ) -> TerminateItem ( aIndex ) ; }
			Item ( aIndex , 0 ) ;
            PushFreePosition ( aIndex ) ;
            PositionUsed ( aIndex , FALSE ) ;
            ListCount ( ListCount ( ) - 1 ) ;
			return TRUE ;
		} ;

		void HoleListInMemory :: Clear () {
            long i ;
            for ( i = StorageCount ( ) - 1 ; i >= 0 ; i -- ) {
				if ( PositionUsed ( i ) ) {
					Remove ( i ) ;
				}
            }
		} ;

		BOOL HoleListInMemory :: Unremove ( long aIndex) {
            if ( !PositionUsed ( aIndex ) ) {
                PositionUsed ( aIndex , TRUE ) ;
                ListCount ( ListCount ( ) + 1 ) ;
                if ( EventSink ( ) != 0 ) { EventSink ( )->InitializeItem ( aIndex ) ; }
				return TRUE ;
            }
			return FALSE ;
		} ;

		void HoleListInMemory :: RemoveAccessory ( ) {
            if ( AllowRemoveAccessory ) {
                while ( !PositionUsed ( StorageCount ( ) - 1 ) && StorageCount ( ) > 0 ) {
                    StorageCount ( StorageCount ( ) - 1 ) ;
                }
            }
		} ;

// Private

	// Methods

		void HoleListInMemory :: PushFreePosition ( long aValue ) {
			// Old version (before 2007-05-06), which converted long directly to void*
				// FreePositionStack -> Push ( ( void* ) aValue ) ;
			long* tValue = new long ;
			* tValue = aValue ;
			FreePositionStack -> Push ( ( void* ) tValue ) ;
		} ;

		long HoleListInMemory :: PopFreePosition ( ) {
            if ( NoReuse || FreePositionStack -> Count ( ) - FreePositionStackSystemRecords ( ) == 0 ) {
                StorageCount ( StorageCount ( ) + 1 ) ;
                return StorageCount ( ) - 1 ;
			}
            else {
				// Old version (before 2007-05-06), before I correctly actively created and destroyed long objects.
					// return * ( long* ) FreePositionStack -> Pop ( ) ;
				long* tValuePointer = ( long* ) FreePositionStack -> Pop ( ) ;
				long tValueCopy = * tValuePointer ;
				delete tValuePointer ;
				return tValueCopy ;
            }
		} ;

	// Event Procedures

		// List

			void HoleListInMemory :: ListEvents :: CountChanged  ( long aPreviousCount ) {
				if ( Parent -> EventSink ( ) != 0 ) {
					Parent -> EventSink ( ) -> StorageCountChanged ( aPreviousCount ) ;
				}
			} ;

			void HoleListInMemory :: ListEvents :: InitializeItem ( long aIndex ) {
				if ( Parent -> EventSink ( ) != 0 ) {
					if ( Parent -> PositionUsed ( aIndex ) ) Parent -> EventSink ( ) -> InitializeItem ( aIndex ) ;
				}
			} ;

			void HoleListInMemory :: ListEvents :: TerminateItem ( long aIndex ) {
				if ( Parent -> EventSink ( ) != 0 ) {
					Parent -> EventSink ( ) -> TerminateItem ( aIndex ) ;
				}
			} ;

		// Position Used List

			void HoleListInMemory :: PositionUsedListEvents :: CountChanged  ( long aPreviousCount ) {
			} ;

			void HoleListInMemory :: PositionUsedListEvents :: InitializeItem ( long aIndex ) {
				BOOL* tBoolean ;
				tBoolean = new BOOL ;
				*tBoolean = FALSE ;
				Parent -> PositionUsedList -> Item ( aIndex , tBoolean ) ;
			} ;

			void HoleListInMemory :: PositionUsedListEvents :: TerminateItem ( long aIndex ) {
				delete Parent -> PositionUsedList -> Item ( aIndex ) ;
			};

		// Free Position Stack

			// Don't initialize or terminate objects on the Free Position Stack.
            // Don't initialize one, because in Push Free Position I will replace the object by another one anyway,
			// which will make the originally initialized object unneccessary, yet it will leak to memory.
			// Don't terminate an item, because in Pop Free Position I need to still have the object after I pop it.
			// if I terminate it, it will be destroyed.
			// So Push Free Position and Pop Free Position will have control over the creation and destruction of these objects.

			void HoleListInMemory :: FreePositionStackEvents :: CountChanged  ( long aPreviousCount ) {
			} ;

			void HoleListInMemory :: FreePositionStackEvents :: InitializeItem ( long aIndex ) {
				// long* tLong ;
				// tLong = new long ;
				// *tLong = 0 ;
				// Parent -> FreePositionStack -> Item ( aIndex , tLong ) ;
			} ;

			void HoleListInMemory :: FreePositionStackEvents :: TerminateItem ( long aIndex ) {
				// delete Parent -> FreePositionStack -> Item ( aIndex ) ;
			} ;
