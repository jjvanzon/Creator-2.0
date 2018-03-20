//
//	Creator . Disk Storage , Item Attributes
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

    class CDiskStorageItemAttributes : public HoleListInMemory {

		// Constructor & Destructor
			
			public : CDiskStorageItemAttributes ( ) ;
			public : ~CDiskStorageItemAttributes ( ) ;

		// Item Property		
		
			CDiskStorageItemAttribute* Item ( long aIndex ) ;

		// Event Procedures

			private : class BaseEvents : public HoleListInMemory :: Events {
				public : CDiskStorageItemAttributes* Parent ;
				// public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * BaseEventsObject ;
			friend class BaseEvents ;
		
	} ;