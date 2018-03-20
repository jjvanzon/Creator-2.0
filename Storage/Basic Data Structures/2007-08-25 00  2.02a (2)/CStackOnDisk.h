//
//	Creator . Lists & Trees . Stack List On Disk
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Saturday, July 21, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Class

    class CStackOnDisk {

		// Constructor & Destructor

			public : CStackOnDisk ( ) ;
			public : ~CStackOnDisk ( ) ;

		// Base

			private : CFlatListOnDisk* List ;

		// File

			public : CString FilePath ( ) ;
			public : void FilePath ( CString aValue ) ;

			public : void Open ( ) ; 
			public : void Close ( ) ;

			public : BOOL IsOpen ( ) ;

		// Data

			public : long FieldSizeInBytes ( ) ;
			public : void FieldSizeInBytes ( long aValue ) ;

			public : long Count ( ) ;
			public : void Count ( long aValue ) ;

			public : void* Item ( long aIndex ) ;
			public : void Item ( long aIndex , void *aValue ) ;

			public : void Push ( void* aValue ) ;
			public : void* Pop ( ) ;

		// Events

			public : class Events {
				public :
					virtual void CountChanged ( long aPreviousCount ) { } ;
					virtual void InitializeItem ( long aIndex ) { } ;
					virtual void TerminateItem ( long aIndex ) { } ;
			};
			public : Events* EventSink ( ) ;
			public : void EventSink ( Events* aValue ) ;
			private : Events* sEventSink ;

		// Event Procedures

			private : class ListEvents : public CFlatListOnDisk :: Events {
				public : CStackOnDisk* Parent ;
				public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * ListEventsObject ;
			friend class ListEvents ;

	} ;

