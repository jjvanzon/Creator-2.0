//
//	Creator . Parser
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

// Layer 1 : Constructor & Destructor

	CParser :: CParser ( ) {
		// Initialize variables
			ShowMessages = FALSE ;
			StructureDefinitionLanguageOn = TRUE ;
			// DataManipulationLanguageOn = TRUE ;
		// Initialize pointers
			Structure = 0 ;
			gggCreator = 0 ;
			Creator = 0 ;
	} ;

	CParser :: ~CParser ( ) {
		// DeleteRelationClassesAAndB ( ) ; // !!! Was here trying to reduce memory leaks, by destroying the Relation Class A's and Relation Class B's created here.
		if ( Structure != 0 ) { delete Structure ; }
	} ;

// Layer 2 : Parse Text

	void CParser :: Parse ( ) {
		// Declarations
			int i ;
			CArray<CString , CString>* tLines ;
		// Clear Structure
			if ( Structure != 0 ) { delete Structure ; }
			Structure = new CItem ;
			if ( Creator != 0 ) {
				Structure -> GenericClass ( Creator -> YourStructure ) ;
			}
			else {
				if ( gggCreator != 0 ) {
					Structure -> GenericClass ( gggCreator -> gggYourStructure ) ;
				}
			}
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
		
// Layer 3 : Parse Line

	void CParser :: ParseLine ( CString aText ) {
		if ( StructureDefinitionLanguageOn == TRUE ) {
			ParseLineForStructureDefinition ( aText ) ;
		}
		// if ( DataManipulationLanguageOn ) {
		// 	ParseLineForDataManipulation ( aText ) ;
		// }
	} ;

// Layer 4 : Parse Line for different language sections

	void CParser :: ParseLineForStructureDefinition ( CString aText ) {
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

	/*
	void CParser :: ParseLineForDataManipulation  ( CString aText ) {
		// Declarations
			int i ;
			CArray<CString , CString>* tTokens ;
			CString tToken ;
			int tFilledTokenIndex ;
			tTokens = Split ( aText, LargeSpace ( ) ) ;
		// Traverse Tokens
			tFilledTokenIndex = -1 ;
			for ( i = 0 ; i <= tTokens -> GetSize ( ) - 1 ; i ++ ) {
				tToken = tTokens -> GetAt ( i ) ;
				tToken.TrimLeft ( ) ;
				tToken.TrimRight ( ) ;
				if ( tToken != "" ) {
					tFilledTokenIndex += 1 ;
					// Detect Assignment
						if ( tToken == "=" ) {
							ParseAssignment ( aText ) ;
							goto Exit ;
						}
				}
			}
	Exit:
		delete tTokens ;
	} ;
	*/

// Layer 4 : Parse Individual Statements

	// Structure Definition

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
						// default :
							// Error : maximum filled tokens is 2
							// return ; // Quick &  Dirty: Ignore that, in order to place comment after the relation declaration
					}
				}
			}
			// Show Messages
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ; }
			// Add Class To Structure
				Structure  -> RelatedLists ( ) -> Item( "Classes" ) -> Add ( ) -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value = tToken ;
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
						// default :
							// Error : maximum filled tokens is 6
							// return ; // Quick &  Dirty: Ignore that, in order to place comment after the relation declaration
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
				CItem* tClass = 0 ;
				tClass = FindClass ( tClassName ) ;
				/*
				// Find Class (I can't search by Name yet in the generic structure) !!!
					CRelatedList* tClasses ;
					CItem* tClass = 0 ;
					tClasses = Structure -> RelatedLists ( ) -> Item("Classes") ;
					for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
						if ( tClasses -> PositionUsed ( i ) == TRUE ) {
							tClass = tClasses -> Item ( i ) ;
							if ( tClass -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value == tClassName ) {
								break ;
							}
							else {
								tClass = 0 ;
							}
						}
					}
				*/
				// Add Attribute
					if ( tClass != 0 ) {
						CItem* tAttribute = 0 ;
						tAttribute = tClass -> RelatedLists ( ) -> Item ( "Class Attributes" ) -> Add ( ) ;
						tAttribute -> ItemAttributes ( ) -> Item ( "Name" ) -> Value = tAttributeName ;
						tAttribute -> ItemAttributes ( ) -> Item ( "Type" ) -> Value = tAttributeType ;
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
				CRelatedList* tRelatedClasses ;
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
				CItem* tRelation ;
				CItem* tRelationClassA ;
				CItem* tRelationClassB ;
				tRelation = Structure -> RelatedLists ( ) -> Item( "Relations" ) -> Add ( ) ;
				// Create  Relation . Relation Class A  and  Relation . Relation Class B
					tRelation -> RelatedItems ( ) -> Item ( "Relation Class A" ) -> Item ( new CItem ) ;
					tRelation -> RelatedItems ( ) -> Item ( "Relation Class B" ) -> Item ( new CItem ) ;
				tRelationClassA = tRelation -> RelatedItems ( ) -> Item ( "Relation Class A" ) -> Item ( ) ;
				tRelationClassB = tRelation -> RelatedItems ( ) -> Item ( "Relation Class B" ) -> Item ( ) ;
				// Assign Name Attributes
					tRelationClassA -> ItemAttributes ( ) -> Item ( "Name" ) -> Value = tRelationClassAName ;
					tRelationClassB -> ItemAttributes ( ) -> Item ( "Name" ) -> Value = tRelationClassBName ;
				// Assign Plural Attributes
					if ( tRelationClassAPlural == "1" ) {
						tRelationClassA -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value = "False" ;
					}
					if ( tRelationClassAPlural == "n" ) {
						tRelationClassA -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value = "True" ;
					}
					if ( tRelationClassBPlural == "1" ) {
						tRelationClassB -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value = "False" ;
					}
					if ( tRelationClassBPlural == "n" ) {
						tRelationClassB -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value = "True" ;
					}
				// Assign Direction Attributes
					tRelationClassA -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value = "1" ;
					tRelationClassB -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value = "0" ;
				// Assign Classes
					// CRelatedList* tClasses ;
					CItem* tClassA = 0 ;
					CItem* tClassB = 0 ;
					// Assign Class A
						tClassA = FindClass ( tRelationClassAClassName ) ;
						/*
						// Find  (I can't search by Name yet in the generic structure) !!!
							tClasses = Structure -> RelatedLists ( ) -> Item ( "Classes" ) ;
							for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
								if ( tClasses -> PositionUsed ( i ) == TRUE ) {
									tClassA = tClasses -> Item ( i ) ;
									if ( tClassA -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value == tRelationClassAClassName ) {
										break ;
									}
									else {
										tClassA = 0 ;
									}
								}
							}
						*/
						// Assign
							if ( tClassA != 0 ) {
								tRelationClassA -> RelatedItems ( ) -> Item ( "Class" ) -> Item ( tClassA ) ;
							}
					// Assign Class B
						tClassB = FindClass ( tRelationClassBClassName ) ;
						/*
							// Find  (I can't search by Name yet in the generic structure) !!!
								tClasses = Structure -> RelatedLists ( ) -> Item("Classes") ;
								for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
									if ( tClasses -> PositionUsed ( i ) == TRUE ) {
										tClassB = tClasses -> Item ( i ) ;
										if ( tClassB -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value == tRelationClassBClassName ) {
											break ;
										}
										else {
											tClassB = 0 ;
										}
									}
								}
						*/
						// Assign
							if ( tClassB != 0 ) {
								tRelationClassB -> RelatedItems ( ) -> Item ( "Class" ) -> Item ( tClassB ) ;
							}
				// Add Quick & Dirty Class . Related Classes
					// Comment : Related List always creates its own items, so I use the base's Add.
					// tClassA . Related Classes . Add ( tRelationClassB )
						if ( tClassA != 0 && tRelationClassB != 0 ) {
							tRelatedClasses = tClassA -> RelatedLists ( ) -> Item ( "Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , tRelationClassB ) ;
						}
					// tClassB . Related Classes . Add ( tRelationClassA )
						if ( tClassB != 0 && tRelationClassA != 0 ) {
							tRelatedClasses = tClassB -> RelatedLists ( ) -> Item ( "Related Classes" ) ;
							tIndex = tRelatedClasses -> HoleListInMemory :: Add ( ) ;
							tRelatedClasses -> Item ( tIndex , tRelationClassA ) ;
						}
		} ;

	// Data Manipulation

		/*
			I think I should first detect the exact type of statement.
			So ParseAssignment is about looking what type of assignment it is.
			I can easily detect an Object Nothing Assignment and an Object New Assignment and an Attribute Literal Assignment
			The AttributeAttributeAssignment and the ObjectObjectAssignments are different to detect.
			They require you to actually parse the specifyers that are the assignment operands and then see if it resolves in two
			object references or in two attributes references.
			Anyway, what all types of assignment have in common, is that the operands have to be parsed if they are specifiers.
			So what I COULD first do is parse the two operands as specifiers.
			Then, next to having parsed the specifiers already, I have all the information to detec the exact assignment type.
			I can then also check if the assignment is valid or not.
			I can divert to other functions to actually execute the rest of what involves the assignment, but probably no further
			real parsing is required, just functions executing the rest of the effect of the assignment.
		*/

		/*
		void CParser :: ParseAssignment ( CString aLine ) {
			// Comment:
				// Object assignments will cause memory leaks for now.
			if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Assignment detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
			// Declarations
				CArray<CString , CString>* tOperands ;
				CArray<CString , CString>* tSplit ;
			// Split by =
				tOperands = Split ( aLine , "=" ) ;
			// Condition : exactly two operands required
				if ( tOperands -> GetSize ( ) != 2 ) {
					// Error : not exactly two operands
					return ;
				}
			// Declarations
				CString tOperandA ;
				CString tOperandB ;
				CItemAttribute* tOperandAAttribute = 0 ;
				CItemAttribute* tOperandBAttribute = 0 ;
				CItem** tOperandAItem = 0 ;
				CItem** tOperandBItem = 0 ;
			// Parse Operands As Specifyer
				// Operand A
					tOperandA = tOperands -> GetAt ( 0 ) ;
					tOperandA . TrimLeft ( ) ;
					tOperandA . TrimRight ( ) ;
					ParseSpecifier ( tOperandA , & tOperandAAttribute , & tOperandAItem ) ;
				// Operand B
					tOperandB = tOperands -> GetAt ( 1 ) ;
					tOperandB . TrimLeft ( ) ;
					tOperandB . TrimRight ( ) ;
					ParseSpecifier ( tOperandB , & tOperandBAttribute , & tOperandBItem ) ;
			// Detect Assignment Types
				// Detect Attribute Assignment
					if ( tOperandAAttribute != 0 ) {
						// Detect Attribute Attribute Assignment
							if ( tOperandBAttribute != 0 ) {
								// Execute effect of assignment
									tOperandAAttribute -> Value = tOperandBAttribute -> Value ;
								goto Exit ;
							}
						// Detect Attribute Literal Assignment
							if ( tOperandBAttribute == 0 ) {
								tOperandAAttribute -> Value = tOperandB . Replace ( "\"" , "" ) ;
								goto Exit ;
							}
					}
				// Detect Object Assignment
					if ( tOperandAItem != 0 ) {
						// Detect Object Object Assignment
							if ( tOperandBItem != 0 ) {
								// Execute effect of assignment
									// I need a reference to a reference of an item as operand A
									// and just a reference to an item as operand B
									*tOperandAItem = *tOperandBItem ;
								goto Exit ;
							}
						// Detect Object New Or Nothing Assignment
							if ( tOperandBItem == 0 ) {
								// Detect Object Nothing Assignment
									if ( StartsWith ( tOperandB , "Nothing" ) ) {
										// Execute effect of assignment
											* tOperandAItem = 0 ;
										goto Exit ;
									 }
								// Detect Object New Assignment
									if ( StartsWith ( tOperandB , "New" ) ) {
										// Execute effect of assignment
											// Get Class Name
												CString tClassName ;
												tSplit = Split ( tOperandB , "New" ) ;
												if ( tSplit -> GetSize ( ) >= 2 ) {
													tClassName = tSplit -> GetAt ( 1 ) ;
													tClassName . TrimLeft ( ) ;
													tClassName . TrimRight ( ) ;
												}
												else {
													return ; // Error : class name not specified
												}
											// Find Class
												CItem* tClass = FindClass ( tOperandB ) ;
												if ( tClass != 0 ) {
													// Create Item
														* tOperandAItem = new CItem ;
													// Assign Class
														( * tOperandAItem ) -> GenericClass ( tClass ) ;
												}
												else {
													goto Exit ; // Error : class not found
												}
										goto Exit ;
									 }
							}
					}
		Exit:
			delete tOperands ;
		} ;

		void CParser :: ParseSpecifier ( CString aText , CItemAttribute** aAttribute , CItem*** aItem ) {
		} ;

		*/

// Layer 5 :  Helpers

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
	
	BOOL CParser :: StartsWith ( CString aText , CString aStart ) {
		// ...
		return FALSE ;
	} ;
		
	CItem* CParser :: FindClass ( CString aName ) {
		long i ;
		CRelatedList* tClasses ;
		CItem* tClass = 0 ;
		tClasses = Structure -> RelatedLists ( ) -> Item( "Classes" ) ;
		for ( i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
			if ( tClasses -> PositionUsed ( i ) == TRUE ) {
				tClass = tClasses -> Item ( i ) ;
				if ( tClass -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value == aName ) {
					return tClass ;
				}
			}
		};
		return 0 ;
	};

	void CParser :: DeleteRelationClassesAAndB ( ) {	
		long i ;
		CRelatedList* tRelations ;
		tRelations = Structure -> RelatedLists ( ) -> Item( "Relations" ) ;
		for ( i = 0 ; i <= tRelations -> StorageCount ( ) - 1 ; i ++ ) {
			if ( tRelations -> PositionUsed ( i ) ) {
				delete tRelations -> Item ( i ) -> RelatedItems ( ) -> Item ( "Relation Class B" ) -> Item ( ) ;
			}
		} ;
	} ;
