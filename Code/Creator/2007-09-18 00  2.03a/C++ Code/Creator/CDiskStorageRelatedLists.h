//
//	Creator . Disk Storage , Related Lists
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

    class CDiskStorageRelatedLists : public HoleListInMemory {

		// Constructor & Destructor
			
			public : CDiskStorageRelatedLists ( ) ;
			public : ~CDiskStorageRelatedLists ( ) ;

		// Item Property		
		
			CDiskStorageRelatedList* Item ( long aIndex ) ;

		// Event Procedures

			private : class BaseEvents : public HoleListInMemory :: Events {
				public : CDiskStorageRelatedLists* Parent ;
				// public : void CountChanged ( long aPreviousCount ) ;
				public : void InitializeItem ( long aIndex ) ;
				public : void TerminateItem ( long aIndex ) ;
			} * BaseEventsObject ;
			friend class BaseEvents ;
		
	} ;