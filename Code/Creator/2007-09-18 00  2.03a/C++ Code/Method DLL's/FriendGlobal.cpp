//
//	Software System . Storage . Basic Data Structures . Friend Global
//
//		Source Code File
//
//		Author: Jan-Joost van Zon
//		Date: Tuesday, August 2, 2005
//
// -----

// Includes

	#include "stdafx.h"
	#include "FriendGlobal.h"

// Methods

	BOOL IndexValid(long aIndex, long aDimension) {
		if (aIndex < 0) return FALSE;
		if (aIndex > aDimension - 1) return FALSE;
		return TRUE;
	};
	
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
