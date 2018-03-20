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
				GENERIC_WRITE ,
				FILE_SHARE_READ ,
				0 ,
				OPEN_ALWAYS ,
				FILE_ATTRIBUTE_NORMAL ,
				0 ) ;
		// Insane Quick & Dirty solution to DeleteFile leaving the file in use for a while.
			/*
			if ( tFileHandle = INVALID_HANDLE_VALUE ) {
				Sleep ( 1000 ) ;
				tFileHandle = CreateFile (
					( LPCTSTR ) aFilePath ,  
					GENERIC_WRITE ,
					FILE_SHARE_READ ,
					0 ,
					OPEN_ALWAYS ,
					FILE_ATTRIBUTE_NORMAL ,
					0 ) ;
			}
			*/
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
				// Flush
					FlushFileBuffers ( tFileHandle ) ;
				// Close File
					CloseHandle ( tFileHandle ) ;
			}
			/*
			else {
				DWORD tLastError = GetLastError ( ) ;
				CString tLastErrorDescription = GetLastErrorDescription ( tLastError ) ;
				return ;
			}
			*/
	} ;

	void Shell ( CString aCommand , BOOL aWait , BOOL aCloseByUser , BOOL aShowCommandWindow ) {
		// Comment :
			// I need to execute something as a command line,
			// but I can only execute a character constant. and I need a string,
			// So I save the command in a bat file with a fixed filename and execute that,
			// So the command I actually execute is a character constant.
		// Save Bat File
			SaveString ( & aCommand , "Shell.bat" ) ;
		// Execute Bat File
			STARTUPINFO tProcessStartupInfo ;
			PROCESS_INFORMATION tProcessInfo ;
			ZeroMemory ( & tProcessStartupInfo , sizeof ( tProcessStartupInfo ) ) ;
			tProcessStartupInfo . cb = sizeof ( tProcessStartupInfo ) ;
			// More Startup Info
				// 2007-09-16 Commenting out things I changed before I got horrible errors
					if ( ! aShowCommandWindow ) {
						tProcessStartupInfo . dwFlags = tProcessStartupInfo . dwFlags || STARTF_USESHOWWINDOW ;
						tProcessStartupInfo . wShowWindow = SW_HIDE ;
					}
			ZeroMemory ( & tProcessInfo , sizeof ( tProcessInfo ) ) ;
			// aCloseByUser = TRUE ; // Quick & Dirty
			if ( aCloseByUser ) {
				CreateProcess ( 0 , "C:\\windows\\system32\\cmd.exe /q /k \"Shell.bat\"" , 0 , 0 , FALSE , 0 , 0 , 0 , & tProcessStartupInfo , & tProcessInfo ) ;
			}
			else {
				CreateProcess ( 0 , "C:\\windows\\system32\\cmd.exe /q /c \"Shell.bat\"" , 0 , 0 , FALSE , 0 , 0 , 0 , & tProcessStartupInfo , & tProcessInfo ) ;
			}
			if ( aWait ) {
				WaitForSingleObject ( tProcessInfo . hProcess, INFINITE ) ;
			}
	} ;

	int FileSize ( CString aFilePath ) {
		int tReturnValue = 0;
		if ( FileExists ( aFilePath ) ) {
			// Declare File Handle
				HANDLE tFileHandle ;
			// Open File
				tFileHandle = CreateFile ( 
					( LPCTSTR ) aFilePath ,
					GENERIC_READ ,             
					FILE_SHARE_READ || FILE_SHARE_WRITE ,
					0 ,								  
					OPEN_EXISTING ,   
					FILE_ATTRIBUTE_NORMAL ,  
					0 ) ;						 	 
			// If Opened Successfully
				if ( tFileHandle != INVALID_HANDLE_VALUE ) {
					// Get File Size
						tReturnValue = GetFileSize ( tFileHandle , NULL ) ;
					// Close File
						CloseHandle ( tFileHandle ) ;
				}
		}
		return tReturnValue ;
	} ;
