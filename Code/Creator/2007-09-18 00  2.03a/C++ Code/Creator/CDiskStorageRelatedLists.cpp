//
//	Creator . Disk Storage Related Lists
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
		
		CDiskStorageRelatedLists :: CDiskStorageRelatedLists ( ) {
			// Setup Event Sinks
				// Base
					BaseEventsObject = new BaseEvents ;
					BaseEventsObject -> Parent = this ;
					HoleListInMemory :: EventSink ( BaseEventsObject ) ;
		} ;

		CDiskStorageRelatedLists :: ~CDiskStorageRelatedLists ( ) {
			Clear ( ) ;
			delete BaseEventsObject ;
			HoleListInMemory :: EventSink ( 0 ) ;
		} ;

	// Item Property
						
		CDiskStorageRelatedList* CDiskStorageRelatedLists :: Item ( long aIndex ) {
			return ( CDiskStorageRelatedList* ) HoleListInMemory :: Item ( aIndex ) ;
		} ;

	// Event Procedures

		void CDiskStorageRelatedLists :: BaseEvents :: InitializeItem ( long aIndex ) {
			Parent -> HoleListInMemory :: Item ( aIndex , new CDiskStorageRelatedList ) ;
		} ;

		void CDiskStorageRelatedLists :: BaseEvents :: TerminateItem ( long aIndex ) {
			delete Parent -> HoleListInMemory :: Item ( aIndex ) ;    
		} ;

