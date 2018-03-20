//
//	Creator . Disk Storage , Related Items
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

    class CDiskStorageRelatedItems : public HoleListInMemory {

		// Constructor & Destructor
			
			public : CDiskStorageRelatedItems ( ) ;
			public : ~CDiskStorageRelatedItems ( ) ;

		// Item Property		
		
			CDiskStorageRelatedItem* Item ( long aIndex ) ;

		// Event Procedures

			private : class BaseEvents : public HoleListInMemory :: Events {
				public : CDiskStorageRelatedItems* Parent ;
				// public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * BaseEventsObject ;
			friend class BaseEvents ;
		
	} ;