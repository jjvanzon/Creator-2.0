//
//	Creator . Disk Storage Item Attributes
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
		
		CDiskStorageItemAttributes :: CDiskStorageItemAttributes ( ) {
			// Setup Event Sinks
				// Base
					BaseEventsObject = new BaseEvents ;
					BaseEventsObject -> Parent = this ;
					HoleListInMemory :: EventSink ( BaseEventsObject ) ;
		} ;

		CDiskStorageItemAttributes :: ~CDiskStorageItemAttributes ( ) {
			Clear ( ) ;
			delete BaseEventsObject ;
			HoleListInMemory :: EventSink ( 0 ) ;
		} ;

	// Item Property
						
		CDiskStorageItemAttribute* CDiskStorageItemAttributes :: Item ( long aIndex ) {
			return ( CDiskStorageItemAttribute* ) HoleListInMemory :: Item ( aIndex ) ;
		} ;

	// Event Procedures

		void CDiskStorageItemAttributes :: BaseEvents :: InitializeItem ( long aIndex ) {
			Parent -> HoleListInMemory :: Item ( aIndex , new CDiskStorageItemAttribute ) ;
		} ;

		void CDiskStorageItemAttributes :: BaseEvents :: TerminateItem ( long aIndex ) {
			delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
		} ;

