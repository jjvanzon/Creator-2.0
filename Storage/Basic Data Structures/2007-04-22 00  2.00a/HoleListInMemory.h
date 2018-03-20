//
//	Creator . Lists and Trees . Hole List . In Memory
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, April 12, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Class

	class HoleListInMemory {

		// Constructor and Destructor
			
			public :

				HoleListInMemory ( ) ;
				~HoleListInMemory ( ) ;

		// Public

			public :

				// Events

					class Events {
						public :
							virtual void StorageCountChanged ( long aPreviousCount ) { } ;
							virtual void InitializeItem ( long aIndex ) { } ;
							virtual void TerminateItem ( long aIndex ) { } ;
					};
				
				// Variables

					BOOL AllowRemoveAccessory ;
					BOOL NoReuse ;

				// Properties

					long StorageCount ( ) ;
					void StorageCount ( long aValue ) ;

					long ListCount ( ) ;
					private : void ListCount ( long aValue ) ; public :

					void* Item ( long aIndex ) ;
					void Item ( long  aIndex, void* aValue ) ;

					BOOL PositionUsed ( long aIndex ) ;
					private : void PositionUsed ( long aIndex , BOOL aValue ) ; public :

					long FreePositions ( ) ;
						
					long FreePosition ( long aIndex ) ;

					// Access to Base

						FlatListInMemory* BaseList ( ) ;
						StackInMemory* BaseFreePositionStack ( ) ;
						FlatListInMemory* BasePositionUsedList ( ) ;

					// Event Sink

						Events* EventSink ( ) ;
						void EventSink ( Events* aValue ) ;

				// Methods

					long Add ( ) ;
					long Add ( void* aItem ) ;
					BOOL Remove ( long aIndex ) ;
					void Clear ( ) ;
					BOOL Unremove ( long aIndex) ;
					void RemoveAccessory ( ) ;

		// Private

			private :

				// Constants

					virtual const long ListCountPosition ( ) { return 0 ; } ;
					virtual const long FreePositionStackSystemRecords ( ) { return 1 ; } ;

				// Variables

					// Property Storage

						Events* sEventSink ;

					// Objects
                
						FlatListInMemory* List ;
						StackInMemory* FreePositionStack ;
						FlatListInMemory* PositionUsedList ;

				// Methods

					void PushFreePosition ( long aValue ) ;
					long PopFreePosition ( ) ;

				// Event Procedures

					class ListEvents : public FlatListInMemory :: Events {
						public :
							void CountChanged ( long aPreviousCount ) ;
							void InitializeItem ( long aIndex ) ;
							void TerminateItem ( long aIndex ) ;
							HoleListInMemory* Parent ;
					} * ListEventsObject ;
					friend class FlatListInMemory ;

					class PositionUsedListEvents : public FlatListInMemory :: Events {
						public :
							void CountChanged ( long aPreviousCount ) ;
							void InitializeItem ( long aIndex ) ;
							void TerminateItem ( long aIndex ) ;
							HoleListInMemory* Parent ;
					} * PositionUsedListEventsObject ;
					friend class PositionUsedListEvents ;

					class FreePositionStackEvents : public StackInMemory :: Events {
						public :
							void CountChanged ( long aPreviousCount ) ;
							void InitializeItem ( long aIndex ) ;
							void TerminateItem ( long aIndex ) ;
							HoleListInMemory* Parent ;
					} * FreePositionStackEventsObject ;
					friend class FreePositionStackEvents ;

	} ;
