//
//	Creator . Friend Global
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

// Properties

	int LargeSpaceSize ( ) {
		return 2 ;
	} ;

	CString LargeSpace ( ) {
		return "  " ;
	} ;
		
	CString ApplicationName ( ) {
		return "Creator" ; 
	} ;

	CString Version ( ) {
		return "2007-09-18 00  2.03a" ;
	} ;

	CString RegistryLocation ( ) {
		return "SOFTWARE\\Jan-Joost van Zon\\Creator\\" + Version ( ) ;
	} ;

	CString CreatorProductionSourceCodeFilePath ( ) {
		return GetRegistryValue ( "CreatorProductionSourceCodeFilePath" ) ;
	} ;

	CString CreatorDevelopmentSourceCodeFilePath ( ) {
		return GetRegistryValue ( "CreatorDevelopmentSourceCodeFilePath" ) ;
	} ;

	CString TreeControlProductionCreatorCodeFilePath ( ) {
		return GetRegistryValue ( "TreeControlProductionCreatorCodeFilePath" ) ;
	} ;

	CString GetRegistryValue ( CString aValueName ) {
		HKEY tRegistryKey ;
		CString tReturnValue ;
		DWORD tBufferSize = 1024 ;
		TCHAR tBuffer [ 1024 ] ;
		LONG tSuccess ;
		tSuccess = RegOpenKeyEx (
			HKEY_LOCAL_MACHINE ,   // handle to open key
			RegistryLocation ( ) ,  // subkey name
			0 ,   // reserved
			KEY_READ , // security access mask
			&tRegistryKey);  // handle to open key
		if ( tSuccess == ERROR_SUCCESS ) {
			tSuccess = RegQueryValueEx ( tRegistryKey , aValueName, NULL , NULL , ( LPBYTE ) tBuffer , &tBufferSize) ;
			if ( tSuccess == ERROR_SUCCESS ) {
				tReturnValue = tBuffer ;
				RegCloseKey ( tRegistryKey ) ;
			}
		}
		return tReturnValue ;
	} ;

// Methods

	BOOL IndexValid( long aIndex , long aDimension ) {
		if ( aIndex < 0 ) return FALSE ;
		if ( aIndex > aDimension - 1 ) return FALSE ;
		return TRUE ;
	} ;

// Miscellaneous

	CString GetLastErrorDescription ( DWORD aLastErrorDoubleWord ) {
		LPSTR MessageBuffer;
		DWORD dwBufferLength;
		if (
			dwBufferLength = FormatMessageA (
				FORMAT_MESSAGE_ALLOCATE_BUFFER |
				FORMAT_MESSAGE_IGNORE_INSERTS |
				FORMAT_MESSAGE_FROM_SYSTEM |
				0 ,
				0 ,
				aLastErrorDoubleWord ,
				MAKELANGID ( LANG_NEUTRAL , SUBLANG_DEFAULT ) , // default language
				( LPSTR ) &MessageBuffer ,
				0 ,
				NULL
			)
		)
		{
			CString tMessage = MessageBuffer;
			return tMessage ;
		}
		return "" ;
	} ;
