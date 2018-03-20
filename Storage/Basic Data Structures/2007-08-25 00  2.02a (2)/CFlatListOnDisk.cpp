//
//	Creator . Lists & Trees . Flat List On Disk
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Saturday, July 21, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Constructor and Destructor

	CFlatListOnDisk :: CFlatListOnDisk ( )
	{
		// Initialize Variables  (required in C++)
			sCount = 0 ;
			FileHandle = 0 ;
			sFieldSizeInBytes = 4 ;
		// Initialize Pointers
			sEventSink = 0 ;
	} ;

	CFlatListOnDisk :: ~CFlatListOnDisk ( )
	{
	} ;

// File
						
	CString CFlatListOnDisk :: FilePath ( )
	{
		return sFilePath ;
	} ;
	void CFlatListOnDisk :: FilePath ( CString aValue )
	{
		if ( IsOpen ( ) == FALSE ) {
			sFilePath = aValue ;
		}
	} ;

	void CFlatListOnDisk :: Open ( ) // Buffer the Count after this
	{
		if ( IsOpen ( ) == FALSE ) {
			FileHandle = CreateFile (
				FilePath ( ) ,
				GENERIC_READ || GENERIC_WRITE ,
				FILE_SHARE_READ ,
				0 ,
				OPEN_ALWAYS ,
				FILE_ATTRIBUTE_NORMAL ,
				NULL
			) ;
			if ( FileHandle != INVALID_HANDLE_VALUE ) {
				Count ( DeriveCountFromFileSize ( ) ) ;
				LastFilePosition = 0 ;
				IsOpen ( TRUE ) ;
			}
			else {
				FileHandle = 0 ;
			}
		}
	} ;

	void CFlatListOnDisk :: Close ( )
	{
		if ( IsOpen ( ) == TRUE ) {
			if ( CloseHandle ( FileHandle ) == TRUE ) {
				IsOpen ( FALSE ) ;
			}
		}
	} ;
						
	BOOL CFlatListOnDisk :: IsOpen ( )
	{
		return sIsOpen ;
	} ;
	void CFlatListOnDisk :: IsOpen ( BOOL aValue ) // Private
	{
		sIsOpen = aValue ;
	} ;

// Data

	long CFlatListOnDisk :: FieldSizeInBytes ( )
	{
		return sFieldSizeInBytes ;
	} ;
	void CFlatListOnDisk :: FieldSizeInBytes ( long aValue )
	{
		if ( IsOpen ( ) == FALSE ) {
			// Conditions
				if ( aValue > 0 ) {
					// Error : Field size must be at least 1 byte
						return ;
				}
			if ( sFieldSizeInBytes != aValue ) {
				sFieldSizeInBytes = aValue ;
			}
		}
	} ;

	long CFlatListOnDisk :: Count ( ) 
	{
		return sCount ;
	} ;
	void CFlatListOnDisk :: Count ( long aValue ) // Will Change Size Of File
	{
		if ( sCount != aValue ) {
			sCount = aValue ;
			MoveToPosition ( aValue * FieldSizeInBytes ( ) ) ;
			SetEndOfFile ( FileHandle ) ;
		}
	} ;

	long CFlatListOnDisk :: DeriveCountFromFileSize ( )
	{
		if ( FileHandle != 0 ) {
			DWORD tLowWord ;
			DWORD tHighWord ;
			tLowWord = GetFileSize ( FileHandle , &tHighWord ) ;
			if ( tLowWord = -1 ) {
				// Function failed
					return 0 ;
			}
			if ( tHighWord != 0 ) {
				// Error : file too large ( above 2GB )
					return 0 ;
			}
			return tLowWord / FieldSizeInBytes ( ) ;
		}
		return 0 ;
	} ;

	void* CFlatListOnDisk :: Item ( long aIndex ) // Will Read
	{
		if ( IsOpen ( ) == FALSE ) { return 0 ; }
		if ( IndexValid ( aIndex , Count ( ) ) == FALSE ) { return 0 ; }
		MoveToPosition ( aIndex * FieldSizeInBytes ( ) ) ;
		void* tBuffer = malloc ( FieldSizeInBytes ( ) ) ;
		if ( ReadFile ( FileHandle , tBuffer , FieldSizeInBytes ( ) , 0 , 0 ) != 0 ) {
			return tBuffer ;
		}
		else {
			// Error 
				return 0 ;
		}
	} ;
	void CFlatListOnDisk :: Item ( long aIndex , void* aValue ) // Will Write
	{
		if ( IsOpen ( ) == FALSE ) { return ; }
		if ( IndexValid ( aIndex , Count ( ) ) == FALSE ) { return ; }
		MoveToPosition ( aIndex * FieldSizeInBytes ( ) ) ;
		if ( WriteFile ( FileHandle , aValue , FieldSizeInBytes ( ) , 0 , 0 ) != 0 ) {
			// Success
		}
		else {
			// Failure
		}
	} ;
		
	void CFlatListOnDisk :: MoveToPosition ( long aPosition ) {
		long tDistance ;
		tDistance = aPosition - LastFilePosition ;
		SetFilePointer ( FileHandle , tDistance , NULL , FILE_CURRENT ) ;
	} ;

// Events

	CFlatListOnDisk :: Events* CFlatListOnDisk :: EventSink ( )
	{
		return sEventSink ;
	} ;
	void CFlatListOnDisk :: EventSink ( Events* aValue )
	{
		sEventSink = aValue ;
	} ;
