//
//	Creator . Disk Storage , Item Attribute
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

    class CDiskStorageItemAttribute {

		// Constructor & Destructor
			
			public : CDiskStorageItemAttribute ( ) ;
			public : ~CDiskStorageItemAttribute ( ) ;

		// Base Object
			
			private : CFlatListOnDisk* List ;

		// Class Attribute

			public : CClassAttribute* ClassAttribute ( ) ;
			public : void ClassAttribute ( CClassAttribute* aValue ) ;
			private : CClassAttribute* sClassAttribute ;

			public : CItem* GenericClassAttribute ( ) ;
			public : void GenericClassAttribute ( CItem* aValue ) ;
			private : CItem* sGenericClassAttribute ;
									
		// File
			
			public : CString FolderPath ( ) ;
			public : void FolderPath ( CString aValue ) ;
			private : CString sFolderPath ;
				
			public : CString ClassName ( ) ;
			public : void ClassName ( CString aValue ) ;
			private : CString sClassName ;
				
			public : CString AttributeName ( ) ;

			private : void ApplyToFilePath ( ) ;

		// Data
			
			public : void* Item ( long aIndex ) ;
			public : void Item ( long aIndex , void* aValue ) ;

		// Other

			private : void ApplyToFieldSizeInBytes ( ) ;

	} ;