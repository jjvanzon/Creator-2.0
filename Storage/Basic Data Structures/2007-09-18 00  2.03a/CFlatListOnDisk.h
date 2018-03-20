//
//	Creator . Lists & Trees . Flat List On Disk
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

    class CFlatListOnDisk {

		// Constructor and Destructor

			public : CFlatListOnDisk ( ) ;
			public : ~CFlatListOnDisk ( ) ;

		// File
			
			public : CString FilePath ( ) ;
			public : void FilePath ( CString aValue ) ;
			private : CString sFilePath ;

			public : void Open ( ) ; // Buffer the Count after this
			public : void Close ( ) ;

			public : BOOL IsOpen ( ) ;
			private : void IsOpen ( BOOL aValue ) ;
			private : BOOL sIsOpen ;
				
			private : HANDLE FileHandle ;

		// Data

			public : long FieldSizeInBytes ( ) ;
			public : void FieldSizeInBytes ( long aValue ) ;
			private : long sFieldSizeInBytes ;

			public : long Count ( ) ; 
			public : void Count ( long aValue ) ; // Will Change Size Of File
			private : long sCount ;
			private : long DeriveCountFromFileSize ( ) ;

			public : void* Item ( long aIndex ) ; // Will Read
			public : void Item ( long aIndex , void* aValue ) ; // Will Write
			private : long LastFilePosition ;
			private : void MoveToPosition ( long aPosition ) ;

		// Events

			public : class Events {
				public : virtual void CountChanged ( long aPreviousCount ) { } ;
				public : virtual void InitializeItem ( long aIndex ) { } ;
				public : virtual void TerminateItem ( long aIndex ) { } ;
			};
			public : Events* EventSink ( ) ;
			public : void EventSink ( Events* aValue ) ;
			private : Events* sEventSink ;
					
	} ;