//
//	Creator . Disk Storage Item Attribute
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

	CDiskStorageItemAttribute :: CDiskStorageItemAttribute ( )
	{
		List = new CFlatListOnDisk ;
	} ;

	CDiskStorageItemAttribute :: ~CDiskStorageItemAttribute ( )
	{
		delete List ; 
	} ;

// File
	
	CString CDiskStorageItemAttribute :: FolderPath ( )
	{
		return sFolderPath ;
	} ;
	void CDiskStorageItemAttribute :: FolderPath ( CString aValue )
	{
		sFolderPath = aValue ;
	} ;

	CString CDiskStorageItemAttribute :: ClassName ( )
	{
		return sClassName ;
	} ;
	void CDiskStorageItemAttribute :: ClassName ( CString aValue )
	{
		sClassName = aValue ;
	} ;

	CString CDiskStorageItemAttribute :: AttributeName ( )
	{
		if ( ClassAttribute ( ) != 0 ) {
			return ClassAttribute ( ) -> Name ;
		}
		if ( GenericClassAttribute ( ) != 0 ) {
			GenericClassAttribute ( ) -> ItemAttributes ( ) -> Item ( "Name" ) -> Value ( ) ;
		}
		return "" ;
	} ;

	void CDiskStorageItemAttribute :: ApplyToFilePath ( )
	{
		List -> FilePath ( FolderPath ( ) + "\\" + ClassName ( ) + " . " + AttributeName ( ) + " Flat List.crd" ) ;
	} ;

// Class Attribute

	CClassAttribute* CDiskStorageItemAttribute :: ClassAttribute ( )
	{
		return sClassAttribute ;
	} ;
	void CDiskStorageItemAttribute :: ClassAttribute ( CClassAttribute* aValue )
	{
		if ( sClassAttribute != aValue ) {
			sClassAttribute = aValue ;
			ApplyToFilePath ( ) ;
			// Apply to stuff
		}
	} ;

	CItem* CDiskStorageItemAttribute :: GenericClassAttribute ( )
	{
		return sGenericClassAttribute ;
	} ;
	void CDiskStorageItemAttribute :: GenericClassAttribute ( CItem* aValue )
	{
		if ( sGenericClassAttribute != aValue ) {
			sGenericClassAttribute = aValue ;
			ApplyToFilePath ( ) ;
			// Apply to stuff
		}
	} ;

// Data
	
	void* CDiskStorageItemAttribute :: Item ( long aIndex )
	{
		return List -> Item ( aIndex ) ;
	} ;

	void CDiskStorageItemAttribute :: Item ( long aIndex , void* aValue )
	{
		List -> Item ( aIndex , aValue ) ;
	} ;

// Other

	void CDiskStorageItemAttribute :: ApplyToFieldSizeInBytes ( )
	{
		if ( ClassAttribute ( ) != 0 ) {
			if ( ClassAttribute ( ) -> Type == "Boolean" ) {
				// ...
			}
			// List -> FieldSizeInBytes ( ClassAttribute ( ) -> Size ( ) ) ;
		}
		// if ( GenericClassAttribute
	} ;
