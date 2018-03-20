//
//	File Functions
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Friday, April 20, 2007 - Friday, April 20, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Methods

	BOOL FileExists ( CString aFilePath ) ;
	CString* LoadString ( CString aFilePath ) ;
	void SaveString ( CString* aText , CString aFilePath ) ;
	void Shell ( CString aCommand , BOOL aWait = TRUE , BOOL aClosedByUser = FALSE , BOOL aShowCommandWindow = FALSE ) ;
    int FileSize ( CString aFilePath ) ;
	CString ResolveInvalidFileNameCharacters ( CString aValue ) ;