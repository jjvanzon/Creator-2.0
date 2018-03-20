//
//	Software System . Storage . Basic Data Structures . Friend Global
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Tuesday, August 2, 2005
//
// -----

// Includes

	#include "stdafx.h"

// Methods

	BOOL IndexValid(long aIndex, long aDimension);
	CString GetLastErrorDescription ( DWORD aLastErrorDoubleWord ) ;

	CString DoubleToString ( double aValue ) ;
	double StringToDouble ( CString aValue ) ;

	CString BooleanToString ( bool aValue ) ;
	bool StringToBoolean ( CString aValue ) ;

	CString ShortToString ( short aValue ) ;
	short StringToShort ( CString aValue ) ;

	CString IntegerToString ( int aValue ) ;
	int StringToInteger ( CString aValue ) ;