//
//	Creator . Lists & Trees . Stack On Disk
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Thursday, July 19, 2007 - Saturday, July 21, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Constructor and Destructor

	CStackOnDisk :: CStackOnDisk ( )
	{
		// Initialize Pointers
			sEventSink = 0 ;
		// Create Objects
			List = new CFlatListOnDisk ;
		// Setup Event Sinks
			ListEventsObject = new ListEvents ;
			ListEventsObject -> Parent = this ;
			List -> EventSink ( ListEventsObject ) ;
	} ;

	CStackOnDisk :: ~CStackOnDisk ( )
	{
		delete List ;
		delete ListEventsObject ;
		List -> EventSink ( 0 ) ; 
	} ;

// File
						
	CString CStackOnDisk :: FilePath ( )
	{
		return List -> FilePath ( ) ;
	} ;
	void CStackOnDisk :: FilePath ( CString aValue )
	{
		List -> FilePath ( aValue ) ;
	} ;

	void CStackOnDisk :: Open ( )
	{
		List -> Open ( ) ;
	} ;

	void CStackOnDisk :: Close ( )
	{
		List -> Close ( ) ;
	} ;
						
	BOOL CStackOnDisk :: IsOpen ( )
	{
		return List -> IsOpen ( ) ;
	} ;

// Data

	long CStackOnDisk :: FieldSizeInBytes ( )
	{
		return List -> FieldSizeInBytes ( ) ;
	} ;
	void CStackOnDisk :: FieldSizeInBytes ( long aValue )
	{
		List -> FieldSizeInBytes ( aValue ) ;
	} ;

	long CStackOnDisk :: Count ( ) 
	{
		return List -> Count ( ) ;
	} ;
	void CStackOnDisk :: Count ( long aValue )
	{
		List -> Count ( aValue ) ;
	} ;

	void* CStackOnDisk :: Item ( long aIndex )
	{
		return List -> Item ( aIndex ) ;
	} ;
	void CStackOnDisk :: Item ( long aIndex , void* aValue )
	{
		List -> Item ( aIndex , aValue ) ;
	} ;

	void CStackOnDisk :: Push ( void* aValue )
	{
		Count ( Count ( ) + 1 ) ;
		Item ( Count ( ) - 1 , aValue ) ;
	} ;
	void* CStackOnDisk :: Pop ( )
	{
		void* tPop ;
		tPop = Item ( Count ( ) - 1 ) ;
		Count ( Count ( ) - 1 ) ;
		return tPop ;
	} ;

// Events

	CStackOnDisk :: Events* CStackOnDisk :: EventSink ( ) {
		return sEventSink ;
	} ;
	void CStackOnDisk :: EventSink ( CStackOnDisk :: Events* aValue ) {
		sEventSink = aValue ;
	} ;

// Event Procedures

	void CStackOnDisk :: ListEvents :: CountChanged  ( long aPreviousCount )
	{
		if ( Parent -> EventSink ( ) != 0 ) {
			Parent -> EventSink ( ) -> CountChanged ( aPreviousCount ) ;
		}
	} ;

	void CStackOnDisk :: ListEvents :: InitializeItem ( long aIndex )
	{
		if ( Parent -> EventSink ( ) != 0 ) {
			Parent -> EventSink ( ) -> InitializeItem ( aIndex ) ;
		}
	} ;

	void CStackOnDisk :: ListEvents :: TerminateItem ( long aIndex )
	{
		if ( Parent -> EventSink ( ) != 0 ) {
			Parent -> EventSink ( ) -> TerminateItem ( aIndex ) ;
		}
	} ;
