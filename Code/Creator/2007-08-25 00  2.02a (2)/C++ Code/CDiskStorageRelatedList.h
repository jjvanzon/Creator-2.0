//
//	Creator . Disk Storage , Related List
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Thursday, July 19, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Class

    class CDiskStorageRelatedList : public CFlatListOnDisk { // List Parallel to Objects

		public : long ClassID ;
		public : long ObjectID ;
			
		public : CHoleListOnDisk* ListItems ;
		
	} ;