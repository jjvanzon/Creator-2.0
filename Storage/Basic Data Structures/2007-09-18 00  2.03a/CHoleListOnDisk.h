//
//	Creator . Lists & Trees . Hole List On Disk
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Thursday, July 19, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Class

    class CHoleListOnDisk {

		// Constructor and Destructor
		
			public : CHoleListOnDisk ( ) ;
			public : ~CHoleListOnDisk ( ) ;

		// Base Objects

			public : CFlatListOnDisk* Data ( ) ;
			private : void Data ( CFlatListOnDisk* aValue ) ;
			private : CFlatListOnDisk* sData ;

			public : CStackOnDisk* FreePositionStack ( ) ;
			private : void FreePositionStack ( CStackOnDisk* aValue ) ;
			private : CStackOnDisk* sFreePositionStack ;

			public : CFlatListOnDisk* PositionUsedList ( ) ;
			private : void PositionUsedList ( CFlatListOnDisk* aValue ) ;
			private : CFlatListOnDisk* sPositionUsedList ;

		// File

			public : CString DataFilePath ( ) ;
			public : void DataFilePath ( CString aValue ) ;

			public : CString FreePositionStackFilePath ( ) ;
			public : void FreePositionStackFilePath ( CString aValue ) ;

			public : CString PositionUsedListFilePath ( ) ;
			public : void PositionUsedListFilePath ( CString aValue ) ;

			public : void Open ( ) ; 
			public : void Close ( ) ;

			public : BOOL IsOpen ( ) ;

		// Data
			
			// Variables

				public : BOOL AllowRemoveAccessory ;
				public : BOOL NoReuse ;

			// Properties

				public : long FieldSizeInBytes ( ) ;
				public : void FieldSizeInBytes ( long aValue ) ;

				public : long StorageCount ( ) ;
				public : void StorageCount ( long aValue ) ;

				public : long ListCount ( ) ;
				private : void ListCount ( long aValue ) ;

				public : void* Item ( long aIndex ) ;
				public : void Item ( long  aIndex, void* aValue ) ;

				public : BOOL PositionUsed ( long aIndex ) ;
				private : void PositionUsed ( long aIndex , BOOL aValue ) ;

				public : long FreePositions ( ) ;
					
				public : long FreePosition ( long aIndex ) ;

			// Methods

				public : long Add ( ) ;
				public : long Add ( void* aItem ) ;
				public : BOOL Remove ( long aIndex ) ;
				public : void Clear ( ) ;
				public : BOOL Unremove ( long aIndex) ;
				public : void RemoveAccessory ( ) ;

		// Helpers

			// Methods

				private : void PushFreePosition ( long aValue ) ;
				private : long PopFreePosition ( ) ;

			// Constants

				private : virtual const long ListCountPosition ( ) { return 0 ; } ;
				private : virtual const long FreePositionStackSystemRecords ( ) { return 1 ; } ;

		// Events

			public : class Events {
				public : virtual void StorageCountChanged ( long aPreviousCount ) { } ;
				public : virtual void InitializeItem ( long aIndex ) { } ;
				public : virtual void TerminateItem ( long aIndex ) { } ;
			};
			public : Events* EventSink ( ) ;
			public : void EventSink ( Events* aValue ) ;
			private : Events* sEventSink ;

		// Event Procedures

			private : class DataEvents : public CFlatListOnDisk :: Events {
				public : CHoleListOnDisk* Parent ;
				public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * DataEventsObject ;
			friend class DataEvents ;

			private : class PositionUsedListEvents : public CFlatListOnDisk :: Events {
				public : CHoleListOnDisk* Parent ;
				public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * PositionUsedListEventsObject ;
			friend class PositionUsedListEvents ;

			private : class FreePositionStackEvents : public CStackOnDisk :: Events {
				public : CHoleListOnDisk* Parent ;
				public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * FreePositionStackEventsObject ;
			friend class FreePositionStackEvents ;

	} ;