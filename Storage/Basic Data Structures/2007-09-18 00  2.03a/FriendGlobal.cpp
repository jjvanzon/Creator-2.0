//
//	Sigma . Data . Lists and Trees . Friend Global
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