//
//	Creator . Creator Parser
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Friday, March 30, 2007 - Saturday, March 31, 2007
//
// -----

// Includes

	#include "stdafx.h" 
	#include "DeclareClasses.h"

// Constructor & Destructor

	CParser :: CParser ( ) {
		// Initialize variables
			ShowMessages = FALSE ;
		// Initialize pointers
			Structure = 0 ;
	} ;

	CParser :: ~CParser ( ) {
		// DeleteRelationClassesAAndB ( ) ; // !!! Was here trying to reduce memory leaks, by destroying the Relation Class A's and Relation Class B's created here.
		if ( Structure != 0 ) { delete Structure ; }
	} ;

// Public

	// Methods

		void CParser :: Parse ( ) {
			// Declarations
				int i ;
				CArray<CString , CString>* tLines ;
			// Clear Structure
				if ( Structure != 0 ) { delete Structure ; }
				Structure = new cccCItem ;
				Structure -> cccGenericClass ( Creator -> gggStructure ) ;
			// Split Into Lines
				tLines = Split ( Text, "\n" ) ;
			// Traverse Lines
				for ( i = 0 ; i <= tLines -> GetSize ( ) - 1 ; i ++ ) {
					if ( ShowMessages == TRUE ) { MessageBox ( 0 , tLines -> GetAt ( i ) , ApplicationName ( ) + " - Parse" , 0 ) ; }
					ParseLine ( tLines -> GetAt ( i ) ) ;
				}
			// Clean Up
				delete tLines ;
		}
		
// Private

	// Methods

		CArray<CString , CString>* CParser :: Split ( CString aText , CString aDelimiter ) {
			// Declarations
				int i ;
				CString tDelimiterCandidate ;
				CString tCharacter ;
				CString tString = "";
				CArray<CString , CString>* tArray ;
				tArray = new CArray<CString , CString> ;
			// Functionality
				// Traverse Characters
					for ( i = 0 ; i <= aText . GetLength ( ) ; i ++ ) {
						// Get Delimiter Candidate
							if ( i <= aText . GetLength ( ) - aDelimiter . GetLength ( ) ) {
								tDelimiterCandidate = aText . Mid ( i, aDelimiter . GetLength ( ) ) ;
							}
							else {
								tDelimiterCandidate = "" ;
							}
						// If Delimiter Found 
							if ( tDelimiterCandidate == aDelimiter ) {
								// Add to array
									tArray -> Add ( tString ) ;
									tString = "" ;
									i += aDelimiter . GetLength ( ) - 1 ;
							}
							else {
								// Add character to temporary string
									tCharacter = aText . Mid ( i , 1 ) ;
									tString += tCharacter ;
							}
					}
				// Add Last Element
					if ( tString != "" ) {
						tArray -> Add ( tString ) ;
					}
				return tArray ;
		} ;

		void CParser :: ParseLine ( CString aText ) {
			// Declarations
				int i ;
				CArray<CString , CString>* tTokens ;
				CString tToken ;
				int tFilledTokenIndex ;
				tTokens = Split ( aText, LargeSpace ( ) ) ;
			// Traverse Tokens, looking for keywords with priority 1
				tFilledTokenIndex = -1 ;
				for ( i = 0 ; i <= tTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = tTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						// Detect Attribute Declaration
							if ( tFilledTokenIndex == 1 && tToken == "-->" ) {
								ParseAttributeDeclaration ( tTokens ) ;
								goto Exit ;
							}
						// Detect Relation Declaration
							if ( tFilledTokenIndex == 5 && tToken == "-->" ) {
								ParseRelationDeclaration ( tTokens ) ;
								goto Exit ;
							}
					}
				}
			// Traverse Tokens, looking for keywords with priority 2
				tFilledTokenIndex = -1 ;
				for ( i = 0 ; i <= tTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = tTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						// Detect Class Declaration
							if ( tFilledTokenIndex == 0 && tToken == "Class" ) {
								ParseClassDeclaration ( tTokens ) ;
								goto Exit ;
							}
					}
				}
		Exit:
			delete tTokens ;
		} ;

		void CParser :: ParseClassDeclaration ( CArray<CString , CString>* aTokens ) {
			if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Class Declaration detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
			int i ;
			CString tToken ;
			int tFilledTokenIndex = -1 ;
			CString tClassName ;
			for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
				tToken = aTokens -> GetAt ( i ) ;
				tToken.TrimLeft ( ) ;
				tToken.TrimRight ( ) ;
				if ( tToken != "" ) {
					tFilledTokenIndex += 1 ;
					switch ( tFilledTokenIndex ) {
						case 0 :
							// "Class"
								if ( tToken != "Class" ) {
									// Error : 1st filled token must be "Class"
									return ;
								}
							break ;
						case 1 :
							// Class Name
								tClassName = tToken ;
								// Add Class to structure	
							break ;
						default :
							// Error : maximum filled tokens is 2
							return ;
					}
				}
			}
			// Show Messages
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ; }
			// Add Class To Structure
				Structure  -> cccRelatedLists ( ) -> Item( "Classes" ) -> Add ( ) -> cccItemAttributes ( ) -> Item ( "Class Name" ) -> cccValue = tToken ;
		} ;

		void CParser :: ParseAttributeDeclaration ( CArray<CString , CString>* aTokens ) {
			if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Attribute Declaration detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
			int i ;
			CString tToken ;
			int tFilledTokenIndex = -1 ;
			CString tClassName ;
			CString tAttributeName ;
			CString tAttributeType ;
			for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
				tToken = aTokens -> GetAt ( i ) ;
				tToken.TrimLeft ( ) ;
				tToken.TrimRight ( ) ;
				if ( tToken != "" ) {
					tFilledTokenIndex += 1 ;
					switch ( tFilledTokenIndex ) {
						case 0 :
							// Class Name
								tClassName = tToken ;
							break ;
						case 1 :
							// "-->"
								if ( tToken != "-->" ) {
									// Error : 2nd filled token must be "-->"
									return ;
								}
							break ;
						case 2 :
							// Attribute Name
								tAttributeName = tToken ;
							break ;
						case 3 :
							// "("
								if ( tToken != "(" ) {
									// Error : 4th filled token must be "("
									return ;
								}
							break ;
						case 4 :
							// Attribute Type
								tAttributeType = tToken ;
							break ;
						case 5 :
							// ")"
								if ( tToken != ")" ) {
									// Error : 6th filled token must be ")"
									return ;
								}
							break ;
						default :
							// Error : maximum filled tokens is 6
							return ;
					}
				}
			}
			// Show Messages
				if ( ShowMessages == TRUE ) { 
					MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ;
					MessageBox ( 0 , "Attribute Name = " + tAttributeName , ApplicationName ( ) + " - Parse" , 0 ) ;
					MessageBox ( 0 , "Attribute Type = " + tAttributeType , ApplicationName ( ) + " - Parse" , 0 ) ;
				}
			// Add Attribute To Class
				// Find Class (I can't search by Name yet in the generic structure) !!!
					cccCRelatedList* tClasses ;
					cccCItem* tClass = 0 ;
					tClasses = Structure -> cccRelatedLists ( ) -> Item("Classes") ;
					for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
						if ( tClasses -> PositionUsed ( i ) == TRUE ) {
							tClass = tClasses -> cccItem ( i ) ;
							if ( tClass -> cccItemAttributes ( ) -> Item ( "Class Name" ) -> cccValue == tClassName ) {
								break ;
							}
							else {
								tClass = 0 ;
							}
						}
					}
				// Add Attribute
					if ( tClass != 0 ) {
						cccCItem* tAttribute = 0 ;
						tAttribute = tClass -> cccRelatedLists ( ) -> Item ( "Class Attributes" ) -> Add ( ) ;
						tAttribute -> cccItemAttributes ( ) -> Item ( "Name" ) -> cccValue = tAttributeName ;
						tAttribute -> cccItemAttributes ( ) -> Item ( "Type" ) -> cccValue = tAttributeType ;
					}
		} ;

		void CParser :: ParseRelationDeclaration ( CArray<CString , CString>* aTokens ) {
			if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Relation Declaration detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
			int i ;
			CString tToken ;
			int tFilledTokenIndex = -1 ;
			CString tRelationClassAClassName ;
			CString tRelationClassAName ;
			CString tRelationClassAPlural ;
			CString tRelationClassBPlural ;
			CString tRelationClassBClassName ;
			CString tRelationClassBName ;
			// Used in Quick & Dirty Related Classes
				int tIndex ; 
				cccCRelatedList* tRelatedClasses ;
			for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
				tToken = aTokens -> GetAt ( i ) ;
				tToken.TrimLeft ( ) ;
				tToken.TrimRight ( ) ;
				if ( tToken != "" ) {
					tFilledTokenIndex += 1 ;
					switch ( tFilledTokenIndex ) {
						case 0 :
							// Relation Class A . Class
								tRelationClassAClassName = tToken ;
							break ;
						case 1 :
							// "("
								if ( tToken != "(" ) {
									// Error : 2nd filled token must be "(""
									return ;
								}
							break ;
						case 2 :
							// Relation Class A . Name
								tRelationClassAName = tToken ;
							break ;
						case 3 :
							// ")"
								if ( tToken != ")" ) {
									// Error : 4th filled token must be ")"
									return ;
								}
							break ;
						case 4 :
							// Relation Class A . Plural
								tRelationClassAPlural = tToken ;
							break ;
						case 5 :
							// "-->"
								if ( tToken != "-->" ) {
									// Error : 7th filled token must be "("
									return ;
								}
						case 6 :
							// Relation Class B . Plural
								tRelationClassBPlural = tToken ;
							break ;
						case 7 :
							// Relation Class B . Class
								tRelationClassBClassName = tToken ;
							break ;
						case 8 :
							// "("
								if ( tToken != "(" ) {
									// Error : 7th filled token must be "("
									return ;
								}
							break ;
						case 9 :
							// Relation Class B . Name
								tRelationClassBName = tToken ;
							break ;
						case 10 :
							// ")"
								if ( tToken != ")" ) {
									// Error : 9th filled token must be ")"
									return ;
								}
							break ;
						// default :
							// Error : maximum filled tokens is 9
							// return ; // Quick &  Dirty: Ignore that, in order to place comment after the relation declaration
					}
				}
			}
			// Show Messages
				if ( ShowMessages == TRUE ) {
					MessageBox ( 0 , "Relation Class A Class = " + tRelationClassAClassName , ApplicationName ( ) + " - Parse", 0 ) ;
					MessageBox ( 0 , "Relation Class A Name = " + tRelationClassAName , ApplicationName ( ) + " - Parse" , 0 ) ;
					MessageBox ( 0 , "Relation Class A Plural = " + tRelationClassAPlural , ApplicationName ( ) + " - Parse" , 0 ) ;
					MessageBox ( 0 , "Relation Class B Plural = " + tRelationClassBPlural , ApplicationName ( ) + " - Parse" , 0 ) ;
					MessageBox ( 0 , "Relation Class B Class = " + tRelationClassBClassName , ApplicationName ( ) + " - Parse" , 0 ) ;
					MessageBox ( 0 , "Relation Class B Name = " + tRelationClassBName , ApplicationName ( ) + " - Parse" , 0 ) ;
				}
			// Add Relation To Structure
				cccCItem* tRelation ;
				cccCItem* tRelationClassA ;
				cccCItem* tRelationClassB ;
				tRelation = Structure -> cccRelatedLists ( ) -> Item( "Relations" ) -> Add ( ) ;
				// Create  Relation . Relation Class A  and  Relation . Relation Class B
					tRelation -> cccRelatedItems ( ) -> Item ( "Relation Class A" ) -> cccItem ( new cccCItem ) ;
					tRelation -> cccRelatedItems ( ) -> Item ( "Relation Class B" ) -> cccItem ( new cccCItem ) ;
				tRelationClassA = tRelation -> cccRelatedItems ( ) -> Item ( "Relation Class A" ) -> cccItem ( ) ;
				tRelationClassB = tRelation -> cccRelatedItems ( ) -> Item ( "Relation Class B" ) -> cccItem ( ) ;
				// Assign Name Attributes
					tRelationClassA -> cccItemAttributes ( ) -> Item ( "Name" ) -> cccValue = tRelationClassAName ;
					tRelationClassB -> cccItemAttributes ( ) -> Item ( "Name" ) -> cccValue = tRelationClassBName ;
				// Assign Plural Attributes
					if ( tRelationClassAPlural == "1" ) {
						tRelationClassA -> cccItemAttributes ( ) -> Item ( "Plural" ) -> cccValue = "False" ;
					}
					if ( tRelationClassAPlural == "n" ) {
						tRelationClassA -> cccItemAttributes ( ) -> Item ( "Plural" ) -> cccValue = "True" ;
					}
					if ( tRelationClassBPlural == "1" ) {
						tRelationClassB -> cccItemAttributes ( ) -> Item ( "Plural" ) -> cccValue = "False" ;
					}
					if ( tRelationClassBPlural == "n" ) {
						tRelationClassB -> cccItemAttributes ( ) -> Item ( "Plural" ) -> cccValue = "True" ;
					}
				// Assign Classes
					cccCRelatedList* tClasses ;
					cccCItem* tClassA = 0 ;
					cccCItem* tClassB = 0 ;
					// Assign Class A
						// Find  (I can't search by Name yet in the generic structure) !!!
							tClasses = Structure -> cccRelatedLists ( ) -> Item ( "Classes" ) ;
							for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tClasses -> PositionUsed ( i ) == TRUE ) {
									tClassA = tClasses -> cccItem ( i ) ;
									if ( tClassA -> cccItemAttributes ( ) -> Item ( "Class Name" ) -> cccValue == tRelationClassAClassName ) {
										break ;
									}
									else {
										tClassA = 0 ;
									}
								}
							}
						// Assign
							if ( tClassA != 0 ) {
								tRelationClassA -> cccRelatedItems ( ) -> Item ( "Class" ) -> cccItem ( tClassA ) ;
							}
					// Assign Class B
						// Find  (I can't search by Name yet in the generic structure) !!!
							tClasses = Structure -> cccRelatedLists ( ) -> Item("Classes") ;
							for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tClasses -> PositionUsed ( i ) == TRUE ) {
									tClassB = tClasses -> cccItem ( i ) ;
									if ( tClassB -> cccItemAttributes ( ) -> Item ( "Class Name" ) -> cccValue == tRelationClassBClassName ) {
										break ;
									}
									else {
										tClassB = 0 ;
									}
								}
							}
						// Assign
							if ( tClassB != 0 ) {
								tRelationClassB -> cccRelatedItems ( ) -> Item ( "Class" ) -> cccItem ( tClassB ) ;
							}
				// Add Quick & Dirty Class . Related Classes
					// Comment : Related List always creates its own items, so I use the base's Add.
					// tClassA . Related Classes . Add ( tRelationClassB )
						if ( tClassA != 0 && tRelationClassB != 0 ) {
							tRelatedClasses = tClassA -> cccRelatedLists ( ) -> Item ( "Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , tRelationClassB ) ;
						}
					// tClassB . Related Classes . Add ( tRelationClassA )
						if ( tClassB != 0 && tRelationClassA != 0 ) {
							tRelatedClasses = tClassB -> cccRelatedLists ( ) -> Item ( "Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> cccItem ( tIndex , tRelationClassA ) ;
						}
		} ;

		void CParser :: DeleteRelationClassesAAndB ( ) {	
			long i ;
			cccCRelatedList* tRelations ;
			tRelations = Structure -> cccRelatedLists ( ) -> Item( "Relations" ) ;
			for ( i = 0 ; i <= tRelations -> StorageCount ( ) - 1 ; i ++ ) {
				if ( tRelations -> PositionUsed ( i ) ) {
					delete tRelations -> cccItem ( i ) -> cccRelatedItems ( ) -> Item ( "Relation Class B" ) -> cccItem ( ) ;
				}
			} ;
		} ;

