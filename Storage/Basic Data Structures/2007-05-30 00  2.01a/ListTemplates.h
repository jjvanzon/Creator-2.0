// -----
//
//	Creator . Lists and Trees . List Templates
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Includes

	#include "stdafx.h"




// -----
//
//	Creator . Lists and Trees . Flat List . In Memory . Template
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Class

	template<class ClassPlaceHolder>
	class FlatListInMemoryTemplate {

		// Public

			public:

				// Events

					class Events {
						public:
							virtual void CountChanged ( long aPreviousCount ) { };
							virtual void InitializeItem ( long aIndex ) { };
							virtual void TerminateItem ( long aIndex ) { };
					};

				// Properties

					long Count ( );
					void Count ( long aValue );

					ClassPlaceHolder Item ( long aIndex );
					Item ( long aIndex, ClassPlaceHolder aValue );

					Events *EventSink ( );
					void EventSink ( Events *aValue );

				// Constructor and Destructor

					FlatListInMemoryTemplate ( );
					~FlatListInMemoryTemplate ( );

		// Private

			private:

				// Variables

					// Property Storage

						long sCount;
						CArray<ClassPlaceHolder, ClassPlaceHolder> sItem;
						Events *sEventSink;

	};




// -----
//
//	Creator . Lists and Trees . Flat List . In Memory . Template
//
//		Source Code File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Public

	// Properties

		template<class ClassPlaceHolder>
		long FlatListInMemoryTemplate<ClassPlaceHolder>::Count ( ) {
			return sCount;
		};
		template<class ClassPlaceHolder>
		void FlatListInMemoryTemplate<ClassPlaceHolder>::Count ( long aValue ) {
			if ( aValue < 0 ) aValue = 0;
			if (sCount != aValue) {
				long tPreviousCount;
				tPreviousCount = sCount;
				sCount = aValue;
				if (sCount = 0) {
					sItem.RemoveAll ( );
				}
				else {
					sItem.SetSize ( sCount );
				}
				long i;
				for ( i = tPreviousCount ; i <= sCount - 1 ; i++ ) {
					EventSink( )->InitializeItem ( i );
				}
				for ( i = tPreviousCount - 1 ; i <= sCount ; i-- ) {
					EventSink( )->TerminateItem ( i );
				}
				EventSink( )->CountChanged ( tPreviousCount );
			}
		};

		template<class ClassPlaceHolder>
		ClassPlaceHolder FlatListInMemoryTemplate<ClassPlaceHolder>::Item ( long aIndex ) {
			if ( IndexValid ( aIndex, Count ( ) ) ) return sItem.GetAt ( aIndex ); else return NULL;
		};
		template<class ClassPlaceHolder>
		FlatListInMemoryTemplate<ClassPlaceHolder>::Item ( long aIndex, ClassPlaceHolder aValue ) {
			if ( IndexValid ( aIndex, Count ( ) ) ) sItem.SetAt ( aIndex, aValue );
		};

		template<class ClassPlaceHolder>
		FlatListInMemoryTemplate<ClassPlaceHolder>::Events *FlatListInMemoryTemplate<ClassPlaceHolder>::EventSink ( ) {
			if ( sEventSink == 0 ) sEventSink = new Events;
			return sEventSink;
		};
		template<class ClassPlaceHolder>
		void FlatListInMemoryTemplate<ClassPlaceHolder>::EventSink ( FlatListInMemoryTemplate<ClassPlaceHolder>::Events *aValue ) {
			sEventSink = aValue;
		};

	// Constructor and Destructor

		template<class ClassPlaceHolder>
		FlatListInMemoryTemplate<ClassPlaceHolder>::FlatListInMemoryTemplate ( ) {
			sItem.SetSize ( 0 );
		};

		template<class ClassPlaceHolder>
		FlatListInMemoryTemplate<ClassPlaceHolder>::~FlatListInMemoryTemplate ( ) {
			sItem.RemoveAll ( );
			if (sEventSink != 0 ) delete sEventSink;
		};




// -----
//
//	Creator . Lists and Trees . Stack . In Memory . Template
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Class

	template<class ClassPlaceHolder>
	class StackInMemoryTemplate {

		// Public

			public:

				// Events

					class Events {
						public:
							virtual void CountChanged ( long aPreviousCount ) { };
							virtual void InitializeItem ( long aIndex ) { };
							virtual void TerminateItem ( long aIndex ) { };
					};

				// Properties

					long Count ( );
					void Count ( long aValue );

					ClassPlaceHolder Item ( long aIndex );
					void Item ( long aIndex, ClassPlaceHolder aValue );

					Events *EventSink ( );
					void EventSink ( Events *aValue );

				// Methods

					void Push ( ClassPlaceHolder aValue );
					ClassPlaceHolder Pop ( );

				// Constructor and Destructor

					StackInMemoryTemplate ( );
					~StackInMemoryTemplate ( );

		// Private

			private:
			
				// Variables

					// Property Storage

						Events *sEventSink;

					// Objects

						FlatListInMemoryTemplate<ClassPlaceHolder> *List;

				// Event Procedures

					class ListEvents : public FlatListInMemoryTemplate<ClassPlaceHolder>::Events {
						public:
							void CountChanged ( long aPreviousCount );
							void InitializeItem ( long aIndex );
							void TerminateItem ( long aIndex );
							StackInMemoryTemplate *Parent;
					} *ListEvents1;

	};




// -----
//
//	Creator . Lists and Trees . Stack . In Memory . Template
//
//		Source Code File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Public

	// Properties

		template<class ClassPlaceHolder>
		long StackInMemoryTemplate<ClassPlaceHolder>::Count ( ) {
			return List->Count ( );
		};
		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::Count ( long aValue ) {
			List->Count ( aValue );
		};

		template<class ClassPlaceHolder>
		ClassPlaceHolder StackInMemoryTemplate<ClassPlaceHolder>::Item ( long aIndex ) {
			return List->Item ( aIndex );
		};
		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::Item ( long aIndex, ClassPlaceHolder aValue ) {
			List->Item ( aIndex, aValue );
		};

		template<class ClassPlaceHolder>
		StackInMemoryTemplate<ClassPlaceHolder>::Events *StackInMemoryTemplate<ClassPlaceHolder>::EventSink ( ) {
			if ( sEventSink == 0 ) sEventSink = new Events;
			return sEventSink;
		};
		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::EventSink ( StackInMemoryTemplate<ClassPlaceHolder>::Events *aValue ) {
			sEventSink = aValue;
		};

	// Methods

		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::Push ( ClassPlaceHolder aValue ) {
			Count ( Count ( ) + 1 );
		};
		template<class ClassPlaceHolder>
		ClassPlaceHolder StackInMemoryTemplate<ClassPlaceHolder>::Pop ( ) {
			ClassPlaceHolder tPop;
			tPop = Item ( Count ( ) - 1 );
			Count ( Count ( ) - 1 );
			return tPop;
		};

	// Constructor and Destructor

		template<class ClassPlaceHolder>
		StackInMemoryTemplate<ClassPlaceHolder>::StackInMemoryTemplate ( ) {
			// Create Objects
				List = new FlatListInMemoryTemplate<ClassPlaceHolder>;
			// Setup Event Sinks
				ListEvents1 = new ListEvents;
				ListEvents1->Parent = this;
				List->EventSink ( ListEvents1 );
		};

		template<class ClassPlaceHolder>
		StackInMemoryTemplate<ClassPlaceHolder>::~StackInMemoryTemplate ( ) {
			if (sEventSink != 0 ) delete sEventSink;
			delete List;
			delete ListEvents1;
		};

// Private

	// Event Procedures

		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::ListEvents::CountChanged  ( long aPreviousCount ) {
			Parent->EventSink ( )->CountChanged ( aPreviousCount );
		};

		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::ListEvents::InitializeItem ( long aIndex ) {
			Parent->EventSink ( )->InitializeItem ( aIndex );
		};

		template<class ClassPlaceHolder>
		void StackInMemoryTemplate<ClassPlaceHolder>::ListEvents::TerminateItem ( long aIndex ) {
			Parent->EventSink ( )->TerminateItem ( aIndex );
		};




// -----
//
//	Creator . Lists and Trees . Hole List . In Memory . Template
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Class

	template<class ClassPlaceHolder>
	class HoleListInMemoryTemplate {

		// Public

			public:

				// Events

					class Events {
						public:
							virtual void StorageCountChanged ( long aPreviousCount ) { };
							virtual void InitializeItem ( long aIndex ) { };
							virtual void TerminateItem ( long aIndex ) { };
					};
				
				// Variables

					BOOL AllowRemoveAccessory;
					BOOL NoReuse;

				// Properties

					long StorageCount ( );
					void StorageCount ( long aValue );

					long ListCount ( );
					private: void ListCount ( long aValue ); public:

					ClassPlaceHolder Item ( long aIndex );
					void Item ( long  aIndex, ClassPlaceHolder aValue );

					BOOL PositionUsed ( long aIndex );
					private: void PositionUsed ( long aIndex, BOOL aValue ); public:

					long FreeItems ();
						
					long FreeItem ( long aIndex );

					// Access to Base

						FlatListInMemoryTemplate<ClassPlaceHolder> *BaseList ();
						StackInMemoryTemplate<long> *BaseFreeItemStack ();
						FlatListInMemoryTemplate<BOOL> *BasePositionUsedList ();

					// Event Sink

						Events *EventSink ( );
						void EventSink ( Events *aValue );

				// Methods

					long Add ();
					BOOL Remove ( long aIndex );
					void Clear ();
					BOOL Unremove ( long aIndex);
					void RemoveAccessory ();

				// Constructor and Destructor

					HoleListInMemoryTemplate ( );
					~HoleListInMemoryTemplate ( );

		// Private

			private:

				// Constants

					virtual const long ListCountPosition() { return 0; };
					virtual const long FreeItemStackSystemRecords() { return 1; };

				// Variables

					// Property Storage

						Events *sEventSink;

					// Objects
                
						FlatListInMemoryTemplate<ClassPlaceHolder> *List;
						StackInMemoryTemplate<long> *FreeItemStack;
						FlatListInMemoryTemplate<BOOL> *PositionUsedList;

				// Methods

					void PushFreeItem ( long aValue );
					long PopFreeItem ();

				// Event Procedures

					class ListEvents : public FlatListInMemoryTemplate<ClassPlaceHolder>::Events {
						public:
							void CountChanged ( long aPreviousCount );
							void InitializeItem ( long aIndex );
							void TerminateItem ( long aIndex );
							HoleListInMemoryTemplate *Parent;
					} *ListEvents1;
					friend class FlatListInMemoryTemplate;

					class PositionUsedListEvents : public FlatListInMemoryTemplate<BOOL>::Events {
						public:
							void CountChanged ( long aPreviousCount );
							void InitializeItem ( long aIndex );
							void TerminateItem ( long aIndex );
							HoleListInMemoryTemplate *Parent;
					} *PositionUsedListEvents1;
					friend class PositionUsedListEvents;

					class FreeItemStackEvents : public StackInMemoryTemplate<long>::Events {
						public:
							void CountChanged ( long aPreviousCount );
							void InitializeItem ( long aIndex );
							void TerminateItem ( long aIndex );
							HoleListInMemoryTemplate *Parent;
					} *FreeItemStackEvents1;
					friend class FreeItemStackEvents;

	};




// -----
//
//	Creator . Lists and Trees . Hole List . In Memory . Template
//
//		Source Code File
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, March 22, 2007
//
// -----

// Public

	// Properties

		template<class ClassPlaceHolder>
		long HoleListInMemoryTemplate<ClassPlaceHolder>::StorageCount ( ) {
			return List->Count ( );
		};
		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::StorageCount ( long aValue ) {
			List->Count ( aValue );
			PositionUsedList->Count ( aValue );
		};

		template<class ClassPlaceHolder>
		long HoleListInMemoryTemplate<ClassPlaceHolder>::ListCount ( ) {
			return *(long *)FreeItemStack->Item ( ListCountPosition ( ) );
		};
		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::ListCount ( long aValue ) { // private
			FreeItemStack->Item ( ListCountPosition ( ), (long)&aValue );
		};

		template<class ClassPlaceHolder>
		ClassPlaceHolder HoleListInMemoryTemplate<ClassPlaceHolder>::Item ( long aIndex ) {
			return List->Item ( aIndex );
		};
		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::Item ( long  aIndex, ClassPlaceHolder aValue ) {
			List->Item ( aIndex, aValue );
		};

		template<class ClassPlaceHolder>
		BOOL HoleListInMemoryTemplate<ClassPlaceHolder>::PositionUsed ( long aIndex ) {
			return *(BOOL *)PositionUsedList->Item( aIndex );
		};
		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::PositionUsed ( long aIndex, BOOL aValue ) { // private
			PositionUsedList->Item (aIndex, (BOOL )&aValue);
		};

		template<class ClassPlaceHolder>
		long HoleListInMemoryTemplate<ClassPlaceHolder>::FreeItems () {
			return FreeItemStack->Count ( );
		};
			
		template<class ClassPlaceHolder>
		long HoleListInMemoryTemplate<ClassPlaceHolder>::FreeItem ( long aIndex ) {
			return *(long *)FreeItemStack->Item ( aIndex + 1 );
		};

		// Access to Base

			template<class ClassPlaceHolder>
			FlatListInMemoryTemplate<ClassPlaceHolder> *HoleListInMemoryTemplate<ClassPlaceHolder>::BaseList () {
				return List;
			};

			template<class ClassPlaceHolder>
			StackInMemoryTemplate<long> *HoleListInMemoryTemplate<ClassPlaceHolder>::BaseFreeItemStack () {
				return FreeItemStack;
			};

			template<class ClassPlaceHolder>
			FlatListInMemoryTemplate<BOOL> *HoleListInMemoryTemplate<ClassPlaceHolder>::BasePositionUsedList () {
				return PositionUsedList;
			};

		// Event Sink

			template<class ClassPlaceHolder>
			HoleListInMemoryTemplate<ClassPlaceHolder>::Events *HoleListInMemoryTemplate<ClassPlaceHolder>::EventSink ( ) {
				if ( sEventSink == 0 ) sEventSink = new Events;
				return sEventSink;
			};
			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::EventSink ( HoleListInMemoryTemplate<ClassPlaceHolder>::Events *aValue ) {
				sEventSink = aValue;
			};

	// Methods

		template<class ClassPlaceHolder>
		long HoleListInMemoryTemplate<ClassPlaceHolder>::Add () {
			long tAdd;
            tAdd = PopFreeItem ( );
            PositionUsed ( tAdd , TRUE );
            ListCount ( ListCount ( ) + 1 );
			EventSink ( )->InitializeItem ( tAdd );
			return tAdd;
		};

		template<class ClassPlaceHolder>
		BOOL HoleListInMemoryTemplate<ClassPlaceHolder>::Remove ( long aIndex ) {
            if ( !IndexValid ( aIndex, StorageCount ( ) ) ) return FALSE;
            if ( !PositionUsed ( aIndex ) ) return FALSE;
            EventSink ( )->TerminateItem ( aIndex );
            PushFreeItem ( aIndex );
            PositionUsed ( aIndex, FALSE );
            ListCount ( ListCount ( ) - 1 );
			return TRUE;
		};

		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::Clear () {
            long i;
            for ( i = StorageCount - 1 ; i >=0 ; i-- ) {
				if ( PositionUsed ( i ) == TRUE ) {
	                Remove ( i ) ;
				}
            }
		};

		template<class ClassPlaceHolder>
		BOOL HoleListInMemoryTemplate<ClassPlaceHolder>::Unremove ( long aIndex) {
            if ( !PositionUsed ( aIndex ) ) {
                PositionUsed ( aIndex , TRUE );
                ListCount ( ListCount ( ) + 1 );
                EventSink ( )->InitializeItem ( aIndex );
				return TRUE;
            }
			return FALSE;
			return 0;
		};

		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::RemoveAccessory () {
            if ( AllowRemoveAccessory ) {
                while ( PositionUsed ( StorageCount ( ) - 1 ) == FALSE ) && StorageCount ( ) > 0 ) {
                    StorageCount ( StorageCount ( ) - 1 );
                }
            }
		};

	// Constructor and Destructor

		template<class ClassPlaceHolder>
		HoleListInMemoryTemplate<ClassPlaceHolder>::HoleListInMemoryTemplate ( ) {
			// Create Objects
				List = new FlatListInMemoryTemplate<ClassPlaceHolder>;
				FreeItemStack = new StackInMemoryTemplate<long>;
				PositionUsedList = new FlatListInMemoryTemplate<BOOL>;
				FreeItemStack->Count ( FreeItemStackSystemRecords ( ) );
			// Setup Event Sinks
				// List
					ListEvents1 = new ListEvents;
					ListEvents1->Parent = this;
					List->EventSink ( ListEvents1 );
				// PositionUsedList
					PositionUsedListEvents1 = new PositionUsedListEvents;
					PositionUsedListEvents1->Parent = this;
					PositionUsedList->EventSink ( PositionUsedListEvents1 );
				// FreeItemStack
					FreeItemStackEvents1 = new FreeItemStackEvents;
					FreeItemStackEvents1->Parent = this;
					FreeItemStack->EventSink ( FreeItemStackEvents1 );
		};

		template<class ClassPlaceHolder>
		HoleListInMemoryTemplate<ClassPlaceHolder>::~HoleListInMemoryTemplate ( ) {
			if (sEventSink != 0 ) delete sEventSink;
			delete List;
			delete FreeItemStack;
			delete PositionUsedList;
			delete ListEvents1;
			delete PositionUsedListEvents1;
			delete FreeItemStackEvents1;
		};

// Private

	// Methods

		template<class ClassPlaceHolder>
		void HoleListInMemoryTemplate<ClassPlaceHolder>::PushFreeItem ( long aValue ) {
			FreeItemStack->Push ( (long) aValue );
		};

		template<class ClassPlaceHolder>
		long HoleListInMemoryTemplate<ClassPlaceHolder>::PopFreeItem () {
            if ( NoReuse || FreeItemStack->Count ( ) - FreeItemStackSystemRecords ( ) == 0 ) {
                StorageCount ( StorageCount ( ) + 1 );
                return StorageCount ( ) - 1;
			}
            else {
                return *(long *)FreeItemStack->Pop ( );
            }
		};

	// Event Procedures

		// List

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::ListEvents::CountChanged  ( long aPreviousCount ) {
				Parent->EventSink ( ) -> StorageCountChanged ( aPreviousCount );
			};

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::ListEvents::InitializeItem ( long aIndex ) {
				if ( Parent->PositionUsed ( aIndex ) ) Parent->EventSink ( )->InitializeItem ( aIndex );
			};

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::ListEvents::TerminateItem ( long aIndex ) {
				Parent->EventSink ( )->TerminateItem ( aIndex );
			};

		// Position Used List

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::PositionUsedListEvents::CountChanged  ( long aPreviousCount ) {
			};

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::PositionUsedListEvents::InitializeItem ( long aIndex ) {
				Parent->PositionUsedList->Item ( aIndex, new BOOL );
			};

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::PositionUsedListEvents::TerminateItem ( long aIndex ) {
				delete Parent->PositionUsedList->Item ( aIndex );
			};

		// Free Position Stack

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::FreeItemStackEvents::CountChanged  ( long aPreviousCount ) {
			};

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::FreeItemStackEvents::InitializeItem ( long aIndex ) {
				Parent->PositionUsedList->Item ( aIndex, new long );
			};

			template<class ClassPlaceHolder>
			void HoleListInMemoryTemplate<ClassPlaceHolder>::FreeItemStackEvents::TerminateItem ( long aIndex ) {
				delete Parent->PositionUsedList->Item ( aIndex );
			};
