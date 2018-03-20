//
//	Creator . Disk Storage RelatedItems
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Thursday, July 19, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

	// Constructor & Destructor
		
		CDiskStorageRelatedItems :: CDiskStorageRelatedItems ( ) {
			// Setup Event Sinks
				// Base
					BaseEventsObject = new BaseEvents ;
					BaseEventsObject -> Parent = this ;
					HoleListInMemory :: EventSink ( BaseEventsObject ) ;
		} ;

		CDiskStorageRelatedItems :: ~CDiskStorageRelatedItems ( ) {
			Clear ( ) ;
			delete BaseEventsObject ;
			HoleListInMemory :: EventSink ( 0 ) ;
		} ;

	// Item Property
						
		CDiskStorageRelatedItem* CDiskStorageRelatedItems :: Item ( long aIndex ) {
			return ( CDiskStorageRelatedItem* ) HoleListInMemory :: Item ( aIndex ) ;
		} ;

	// Event Procedures

		void CDiskStorageRelatedItems :: BaseEvents :: InitializeItem ( long aIndex ) {
			Parent -> HoleListInMemory :: Item ( aIndex , new CDiskStorageRelatedItem ) ;
		} ;

		void CDiskStorageRelatedItems :: BaseEvents :: TerminateItem ( long aIndex ) {
			delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
		} ;

