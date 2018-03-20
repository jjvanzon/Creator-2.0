//
//	Creator . Disk Storage , Class
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

    class CDiskStorageClass {

		// Constructor & Destructor
			
			public : CDiskStorageClass ( ) ;
			public : ~CDiskStorageClass ( ) ;

		// Related Items

			private : CHoleListOnDisk* List ;
			private : CFlatListOnDisk* ReferenceCountList ;
				
			public : CClass* Class ( ) ;
			public : void Class ( CClass* aValue ) ;
			private : CClass* sClass ;

			public : CItem* GenericClass ( ) ;
			public : void GenericClass ( CItem* aValue ) ;
			private : CItem* sGenericClass ;

			public : CDiskStorageItemAttributes* ItemAttributes ( ) ;
			private : CDiskStorageItemAttributes* sItemAttributes ;

			public : CDiskStorageRelatedItems* RelatedItems ( ) ;
			private : CDiskStorageRelatedItems* sRelatedItems ;

			public : CDiskStorageRelatedLists* RelatedLists ( ) ;	
			private : CDiskStorageRelatedLists* sRelatedLists ;
			
		// File
			
			public : CString FolderPath ( ) ;
			public : void FolderPath ( CString aValue ) ;
			private : CString sFolderPath ;
				
			public : CString ClassName ( ) ;
			public : void ClassName ( CString aValue ) ;
			private : CString sClassName ;

			public : CString HoleListFilePath ( ) ;
			public : CString ReferenceCountListFilePath ( ) ;

	} ;
