//
//	Creator . Lists & Trees . Hole List On Disk
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Thursday, July 19, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Constructor and Destructor

	CHoleListOnDisk :: CHoleListOnDisk ( )
	{
		// Initialize Variables  (required in C++)
			AllowRemoveAccessory = FALSE ;
			NoReuse = FALSE ;
		// Initialize Pointers
			sEventSink = 0 ;
		// Create Objects
			Data ( new CFlatListOnDisk ) ;
			FreePositionStack ( new CStackOnDisk ) ;
			PositionUsedList ( new CFlatListOnDisk ) ;
		// Setup Event Sinks
			// Data
				DataEventsObject = new DataEvents ;
				DataEventsObject -> Parent = this ;
				Data ( ) -> EventSink ( DataEventsObject ) ;
			// Position Used List
				PositionUsedListEventsObject = new PositionUsedListEvents ;
				PositionUsedListEventsObject -> Parent = this ;
				PositionUsedList ( ) -> EventSink ( PositionUsedListEventsObject ) ;
			// Free Position Stack
				FreePositionStackEventsObject = new FreePositionStackEvents ;
				FreePositionStackEventsObject -> Parent = this ;
				FreePositionStack ( ) -> EventSink ( FreePositionStackEventsObject ) ;
		// Initialize Values
			// Position Used List & Free Position Stack Field Sizes
				PositionUsedList ( ) -> FieldSizeInBytes ( 1 ) ;
				FreePositionStack ( ) -> FieldSizeInBytes ( 4 ) ;
			// List Count on Free Position Stack
				FreePositionStack ( ) -> Count ( FreePositionStackSystemRecords ( ) ) ;
				long* tLong = new long ;
				* tLong = 0 ;
				FreePositionStack ( ) -> Item ( ListCountPosition ( ) , tLong ) ;
	} ;

	CHoleListOnDisk :: ~CHoleListOnDisk ( )
	{
		delete FreePositionStack ( ) -> Item ( ListCountPosition ( ) ) ;
		delete FreePositionStack ( ) ;
		delete PositionUsedList ( ) ;
		delete Data ( ) ;
		delete FreePositionStackEventsObject ;
		delete PositionUsedListEventsObject ;
		delete DataEventsObject ;
		FreePositionStack ( ) -> EventSink ( 0 ) ; // Why the hell would this be ok, after the object called upon is destroyed?
		PositionUsedList ( ) -> EventSink ( 0 ) ; // Why the hell would this be ok, after the object called upon is destroyed?
		Data ( ) -> EventSink ( 0 ) ;  // Why the hell would this be ok, after the object called upon is destroyed?
	} ;

// Base Objects

	CFlatListOnDisk* CHoleListOnDisk :: Data ( )
	{
		return sData ;
	} ;

	void CHoleListOnDisk :: Data ( CFlatListOnDisk* aValue )
	{
		sData = aValue ;
	} ;

	CStackOnDisk* CHoleListOnDisk :: FreePositionStack ( )
	{
		return sFreePositionStack ;
	} ;
	void CHoleListOnDisk :: FreePositionStack ( CStackOnDisk* aValue ) {
		sFreePositionStack = aValue ;
	} ;

	CFlatListOnDisk* CHoleListOnDisk :: PositionUsedList ( )
	{
		return sPositionUsedList ;
	} ;
	void CHoleListOnDisk :: PositionUsedList ( CFlatListOnDisk* aValue )
	{
		sPositionUsedList = aValue ;
	} ;

// File

	CString CHoleListOnDisk :: DataFilePath ( )
	{
		return Data ( ) -> FilePath ( ) ;
	} ;
	void CHoleListOnDisk :: DataFilePath ( CString aValue )
	{
		Data ( ) -> FilePath ( aValue ) ;
	} ;

	CString CHoleListOnDisk :: FreePositionStackFilePath ( )
	{
		return FreePositionStack ( ) -> FilePath ( ) ;
	} ;
	void CHoleListOnDisk :: FreePositionStackFilePath ( CString aValue )
	{
		FreePositionStack ( ) -> FilePath ( aValue ) ;
	} ;

	CString CHoleListOnDisk :: PositionUsedListFilePath ( )
	{
		return PositionUsedList ( ) -> FilePath ( ) ;
	} ;
	void CHoleListOnDisk :: PositionUsedListFilePath ( CString aValue )
	{
		PositionUsedList ( ) -> FilePath ( aValue ) ;
	} ;

	void CHoleListOnDisk :: Open ( )
	{
		Data ( ) -> Open ( ) ;
		PositionUsedList ( ) -> Open ( ) ;
		FreePositionStack ( ) -> Open ( ) ;
	} ; 
	void CHoleListOnDisk :: Close ( )
	{
		Data ( ) -> Close ( ) ;
		PositionUsedList ( ) -> Close ( ) ;
		FreePositionStack ( ) -> Close ( ) ;
	} ;

	BOOL CHoleListOnDisk :: IsOpen ( )
	{
		return Data ( ) -> IsOpen ( ) ;
	} ;

// Data

	// Properties

		long CHoleListOnDisk :: FieldSizeInBytes ( )
		{
			return Data ( ) -> FieldSizeInBytes ( ) ;
		} ;
		void CHoleListOnDisk :: FieldSizeInBytes ( long aValue )
		{
			Data ( ) -> FieldSizeInBytes ( aValue ) ;
		} ;

		long CHoleListOnDisk :: StorageCount ( ) {
			return Data ( ) -> Count ( ) ;
		} ;
		void CHoleListOnDisk :: StorageCount ( long aValue ) {
			PositionUsedList ( ) -> Count ( aValue ) ;
			Data ( ) -> Count ( aValue ) ;
		} ;

		long CHoleListOnDisk :: ListCount ( ) {
			return * ( long* ) FreePositionStack ( ) -> Item ( ListCountPosition ( ) ) ;
		} ;
		void CHoleListOnDisk :: ListCount ( long aValue ) { // Private
			long* tLong ;
			tLong = ( long* ) FreePositionStack ( ) -> Item ( ListCountPosition ( ) ) ;
			*tLong = aValue ;
		};

		void* CHoleListOnDisk :: Item ( long aIndex ) {
			return Data ( ) -> Item ( aIndex ) ;
		};
		void CHoleListOnDisk :: Item ( long  aIndex , void* aValue ) {
			Data ( ) -> Item ( aIndex , aValue ) ;
		};

		BOOL CHoleListOnDisk :: PositionUsed ( long aIndex ) {
			if ( IndexValid ( aIndex , StorageCount ( ) ) ) {
				return * ( BOOL* ) PositionUsedList ( ) -> Item ( aIndex ) ;
			}
			else {
				return FALSE ;
			}
		};
		void CHoleListOnDisk :: PositionUsed ( long aIndex , BOOL aValue ) { // Private
			BOOL* tBoolean ;
			tBoolean = ( BOOL* ) PositionUsedList ( ) -> Item ( aIndex ) ;
			*tBoolean = aValue ;
		};

		long CHoleListOnDisk :: FreePositions ( ) {
			return FreePositionStack ( ) -> Count ( ) ;
		};
			
		long CHoleListOnDisk :: FreePosition ( long aIndex ) {
			return * ( long* ) FreePositionStack ( ) -> Item ( aIndex + 1 ) ;
		} ;

	// Methods

		long CHoleListOnDisk :: Add ( ) {
			long tAdd ;
            tAdd = PopFreePosition ( ) ;
            PositionUsed ( tAdd , TRUE ) ;
            ListCount ( ListCount ( ) + 1 ) ;
			if ( EventSink ( ) != 0 ) { EventSink ( ) -> InitializeItem ( tAdd ) ; }
			return tAdd;
		} ;
			
		long CHoleListOnDisk :: Add ( void* aItem ) {
			long tIndex = Add ( ) ;
			CHoleListOnDisk :: Item ( tIndex , aItem ) ;
			return tIndex ;
		} ;

		BOOL CHoleListOnDisk :: Remove ( long aIndex ) {
            if ( IndexValid ( aIndex , StorageCount ( ) ) == FALSE ) return FALSE ;
            if ( PositionUsed ( aIndex ) == FALSE ) return FALSE ;
            if ( EventSink ( ) != 0 ) { EventSink ( ) -> TerminateItem ( aIndex ) ; }
			Item ( aIndex , 0 ) ;
            PushFreePosition ( aIndex ) ;
            PositionUsed ( aIndex , FALSE ) ;
            ListCount ( ListCount ( ) - 1 ) ;
			return TRUE ;
		} ;

		void CHoleListOnDisk :: Clear () {
            long i ;
            for ( i = StorageCount ( ) - 1 ; i >= 0 ; i -- ) {
				if ( PositionUsed ( i ) ) {
					Remove ( i ) ;
				}
            }
		} ;

		BOOL CHoleListOnDisk :: Unremove ( long aIndex) {
            if ( !PositionUsed ( aIndex ) ) {
                PositionUsed ( aIndex , TRUE ) ;
                ListCount ( ListCount ( ) + 1 ) ;
                if ( EventSink ( ) != 0 ) { EventSink ( )->InitializeItem ( aIndex ) ; }
				return TRUE ;
            }
			return FALSE ;
		} ;

		void CHoleListOnDisk :: RemoveAccessory ( ) {
            if ( AllowRemoveAccessory ) {
                while ( !PositionUsed ( StorageCount ( ) - 1 ) && StorageCount ( ) > 0 ) {
                    StorageCount ( StorageCount ( ) - 1 ) ;
                }
            }
		} ;

// Helpers

	// Methods

		void CHoleListOnDisk :: PushFreePosition ( long aValue ) {
			long* tValue = new long ;
			* tValue = aValue ;
			FreePositionStack ( ) -> Push ( ( void* ) tValue ) ;
		} ;

		long CHoleListOnDisk :: PopFreePosition ( ) {
            if ( NoReuse || FreePositionStack ( ) -> Count ( ) - FreePositionStackSystemRecords ( ) == 0 ) {
                StorageCount ( StorageCount ( ) + 1 ) ;
                return StorageCount ( ) - 1 ;
			}
            else {
				long* tValuePointer = ( long* ) FreePositionStack ( ) -> Pop ( ) ;
				long tValueCopy = * tValuePointer ;
				delete tValuePointer ;
				return tValueCopy ;
            }
		} ;

// Events

	CHoleListOnDisk :: Events* CHoleListOnDisk :: EventSink ( ) {
		return sEventSink ;
	} ;
	void CHoleListOnDisk :: EventSink ( CHoleListOnDisk :: Events* aValue ) {
		sEventSink = aValue ;
	} ;

// Event Procedures

	// List

		void CHoleListOnDisk :: DataEvents :: CountChanged  ( long aPreviousCount ) {
			if ( Parent -> EventSink ( ) != 0 ) {
				Parent -> EventSink ( ) -> StorageCountChanged ( aPreviousCount ) ;
			}
		} ;

		void CHoleListOnDisk :: DataEvents :: InitializeItem ( long aIndex ) {
			if ( Parent -> EventSink ( ) != 0 ) {
				if ( Parent -> PositionUsed ( aIndex ) ) Parent -> EventSink ( ) -> InitializeItem ( aIndex ) ;
			}
		} ;

		void CHoleListOnDisk :: DataEvents :: TerminateItem ( long aIndex ) {
			if ( Parent -> EventSink ( ) != 0 ) {
				Parent -> EventSink ( ) -> TerminateItem ( aIndex ) ;
			}
		} ;

	// Position Used List

		void CHoleListOnDisk :: PositionUsedListEvents :: CountChanged  ( long aPreviousCount ) {
		} ;

		void CHoleListOnDisk :: PositionUsedListEvents :: InitializeItem ( long aIndex ) {
			BOOL* tBoolean ;
			tBoolean = new BOOL ;
			*tBoolean = FALSE ;
			Parent -> PositionUsedList ( ) -> Item ( aIndex , tBoolean ) ;
		} ;

		void CHoleListOnDisk :: PositionUsedListEvents :: TerminateItem ( long aIndex ) {
			delete Parent -> PositionUsedList ( ) -> Item ( aIndex ) ;
		};

	// Free Position Stack

		// Don't initialize or terminate objects on the Free Position Stack.
        // Don't initialize one, because in Push Free Position I will replace the object by another one anyway,
		// which will make the originally initialized object unneccessary, yet it will leak to memory.
		// Don't terminate an item, because in Pop Free Position I need to still have the object after I pop it.
		// if I terminate it, it will be destroyed.
		// So Push Free Position and Pop Free Position will have control over the creation and destruction of these objects.

		void CHoleListOnDisk :: FreePositionStackEvents :: CountChanged  ( long aPreviousCount ) {
		} ;

		void CHoleListOnDisk :: FreePositionStackEvents :: InitializeItem ( long aIndex ) {
		} ;

		void CHoleListOnDisk :: FreePositionStackEvents :: TerminateItem ( long aIndex ) {
		} ;
