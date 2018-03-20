//
//	Creator . Disk Storage Class
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

	CDiskStorageClass :: CDiskStorageClass ( )
	{
		List = new CHoleListOnDisk ;
		ReferenceCountList = new CFlatListOnDisk ;
		sItemAttributes = new CDiskStorageItemAttributes ;
		sRelatedItems = new CDiskStorageRelatedItems ;
		sRelatedLists = new CDiskStorageRelatedLists ;
	} ;

	CDiskStorageClass :: ~CDiskStorageClass ( )
	{
		delete List ; 
		delete ReferenceCountList ; 
		delete sItemAttributes ;
		delete sRelatedItems ;
		delete sRelatedLists ;
	} ;

// Related Items

	CClass* CDiskStorageClass :: Class ( )
	{
		return sClass ;
	} ;
	void CDiskStorageClass :: Class ( CClass* aValue )
	{
		sClass = aValue ;
	} ;

	CItem* CDiskStorageClass :: GenericClass ( )
	{
		return sGenericClass ;
	} ;
	void CDiskStorageClass :: GenericClass ( CItem* aValue )
	{
		sGenericClass = aValue ;
	};

	CDiskStorageItemAttributes* CDiskStorageClass :: ItemAttributes ( )
	{
		return sItemAttributes ;
	} ;

	CDiskStorageRelatedItems* CDiskStorageClass :: RelatedItems ( )
	{
		return sRelatedItems ;
	} ;

	CDiskStorageRelatedLists* CDiskStorageClass :: RelatedLists ( )
	{
		return sRelatedLists ;
	} ;

// File
	
	CString CDiskStorageClass :: FolderPath ( )
	{
		return sFolderPath ;
	} ;
	void CDiskStorageClass :: FolderPath ( CString aValue )
	{
		sFolderPath = aValue ;
	} ;

	CString CDiskStorageClass :: ClassName ( )
	{
		return sClassName ;
	} ;
	void CDiskStorageClass :: ClassName ( CString aValue )
	{
		sClassName = aValue ;
	} ;

	CString CDiskStorageClass :: HoleListFilePath ( )
	{
		return FolderPath ( ) + "\\" + ClassName ( ) + " Hole List.crd" ;
	} ;
	CString CDiskStorageClass :: ReferenceCountListFilePath ( )
	{
		return FolderPath ( ) + "\\" + ClassName ( ) + " Reference Count List.crd" ;
	} ;
