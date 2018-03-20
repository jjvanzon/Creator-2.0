//
//	File Functions
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Tuesday, August 2, 2005
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Methods

	BOOL FileExists ( CString aFilePath ) {
		HANDLE tSearchHandle ;
		WIN32_FIND_DATA tFindData ;
		tSearchHandle = FindFirstFile ( ( LPCTSTR ) aFilePath , &tFindData ) ;
		if ( tSearchHandle != INVALID_HANDLE_VALUE ) {
			FindClose ( tSearchHandle ) ;
			return TRUE ;
		}
		else {
			return FALSE ;
		}
	} ;

	CString* LoadString ( CString aFilePath ) {
		CString* tReturnValue ;
		tReturnValue = new CString ;
		*tReturnValue = "" ;
		if ( FileExists ( aFilePath ) ) {
			// Declare File Handle
				HANDLE tFileHandle ;
			// Open File
				tFileHandle = CreateFile ( 
					( LPCTSTR ) aFilePath ,
					GENERIC_READ ,             // open for reading 
					FILE_SHARE_READ ,       // share for reading 
					0 ,								  // no security 
					OPEN_EXISTING ,           // existing file only 
					FILE_ATTRIBUTE_NORMAL ,   // normal file 
					0 ) ;						 	  // no attr. template 
			// If Opened Successfully
				if ( tFileHandle != INVALID_HANDLE_VALUE ) {
					// Read From File
						char tByte ;
						DWORD tBytesRead ;
						while ( ReadFile ( tFileHandle , &tByte , 1 , &tBytesRead , 0 ) ) {
							if ( tBytesRead == 0 ) { break ; } ;
							*tReturnValue = *tReturnValue + tByte ;
						}
					// Close File
						CloseHandle ( tFileHandle ) ;
				}
		}
		return tReturnValue ;
	} ;

	void SaveString ( CString* aText , CString aFilePath ) {
		// Delete existing file
			if ( FileExists ( aFilePath ) ) {
				DeleteFile ( ( LPCTSTR ) aFilePath ) ;
			}
		// Declare File Handle
			HANDLE tFileHandle ;
		// Open File
			tFileHandle = CreateFile (
				( LPCTSTR ) aFilePath ,  
				GENERIC_WRITE ,        // open for writing 
				FILE_SHARE_READ ,	// share read
				0 ,									  // no security 
				OPEN_ALWAYS ,           // open or create 
				FILE_ATTRIBUTE_NORMAL ,     // normal file 
				0 ) ;                                  // no attr. template 
		// If Opened Successfully
			if ( tFileHandle != INVALID_HANDLE_VALUE ) {
				// Write To File
					long i ;
					char tByte ;
					DWORD tBytesWritten ;
					for ( i = 0 ; i <= aText -> GetLength ( ) - 1 ; i ++ ) {
						tByte = aText -> GetAt ( i ) ;
						WriteFile ( tFileHandle , &tByte , 1 , &tBytesWritten , 0 ) ;
					}
				// Close File
					CloseHandle ( tFileHandle ) ;
			}
	} ;