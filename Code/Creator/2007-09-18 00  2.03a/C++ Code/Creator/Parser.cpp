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
			DebugOrRelease = "Debug" ;
			// DebugOrRelease = "Release" ;
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
			// int i ;
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
			// Lines = Split ( Text, "\n" ) ;
			Lines = Split ( Text, "\r\n" ) ;
		// Traverse Lines
			for ( LineIndex = 0 ; LineIndex <= Lines -> GetSize ( ) - 1 ; LineIndex ++ ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , Lines -> GetAt ( LineIndex ) , ApplicationName ( ) + " - Parse" , 0 ) ; }
				ParseLine ( Lines -> GetAt ( LineIndex ) ) ;
			}
		// Clean Up
			delete Lines ;
		// Compile Methods
			// CompileMethods ( ) ;
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
					// Detect Name Declaration
						if ( tFilledTokenIndex == 0 && tToken == "Name" ) {
							ParseNameDeclaration ( tTokens ) ;
							goto Exit ;
						}
					// Detect Method Declaration
						/*
						if ( tFilledTokenIndex == 0 && tToken == "Method" ) {
							ParseMethodDeclaration ( tTokens ) ;
							goto Exit ;
						}
						*/
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
					// Detect Debug Declaration
						if ( tFilledTokenIndex == 0 && tToken == "Debug" ) {
							ParseDebugMemberDeclaration ( tTokens ) ;
							goto Exit ;
						}
					// Detect Method Definition
						if ( tFilledTokenIndex == 0 && tToken == "Method" ) {
							ParseMethodDefinition ( tTokens ) ;
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

	// Parse Structure Definition

		// Parse Class Declaration

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
					Structure  -> RelatedLists ( ) -> Item( "Classes" ) -> Add ( ) -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value ( tToken ) ;
			} ;

		// Parse Attribute Declaration

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
					// Add Attribute
						if ( tClass != 0 ) {
							CItem* tAttribute = 0 ;
							tAttribute = tClass -> RelatedLists ( ) -> Item ( "Class Attributes" ) -> Add ( ) ;
							tAttribute -> ItemAttributes ( ) -> Item ( "Name" ) -> Value ( tAttributeName ) ;
							tAttribute -> ItemAttributes ( ) -> Item ( "Type" ) -> Value ( tAttributeType ) ;
						}
			} ;

		// Parse Relation Declaration

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
						tRelationClassA -> ItemAttributes ( ) -> Item ( "Name" ) -> Value ( tRelationClassAName ) ;
						tRelationClassB -> ItemAttributes ( ) -> Item ( "Name" ) -> Value ( tRelationClassBName ) ;
					// Assign Plural Attributes
						if ( tRelationClassAPlural == "1" ) {
							tRelationClassA -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value ( "False" ) ;
						}
						if ( tRelationClassAPlural == "n" ) {
							tRelationClassA -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value ( "True" ) ;
						}
						if ( tRelationClassBPlural == "1" ) {
							tRelationClassB -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value ( "False" ) ;
						}
						if ( tRelationClassBPlural == "n" ) {
							tRelationClassB -> ItemAttributes ( ) -> Item ( "Plural" ) -> Value ( "True" ) ;
						}
					// Assign Direction Attributes
						tRelationClassA -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value ( "1" ) ;
						tRelationClassB -> ItemAttributes ( ) -> Item ( "Direction" ) -> Value ( "0" ) ;
					// Assign Classes
						CItem* tClassA = 0 ;
						CItem* tClassB = 0 ;
						// Assign Class A
							tClassA = FindClass ( tRelationClassAClassName ) ;
							// Assign
								if ( tClassA != 0 ) {
									tRelationClassA -> RelatedItems ( ) -> Item ( "Class" ) -> Item ( tClassA ) ;
								}
						// Assign Class B
							tClassB = FindClass ( tRelationClassBClassName ) ;
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
					// Quick & Dirty Other Relation Class for Quick & Dirty Synchronization 1 -> n for the Procedures Project
						// Assign Other Relation Classes
							CRelatedItem* tOtherRelationClassRelatedItem ;
							tOtherRelationClassRelatedItem = tRelationClassA -> RelatedItems ( ) -> Item ( "Other Relation Class" ) ;
							if ( tOtherRelationClassRelatedItem != 0 ) {
								tOtherRelationClassRelatedItem -> Item ( tRelationClassB ) ;
							}
							tOtherRelationClassRelatedItem = tRelationClassB -> RelatedItems ( ) -> Item ( "Other Relation Class" ) ;
							if ( tOtherRelationClassRelatedItem != 0 ) {
								tOtherRelationClassRelatedItem -> Item ( tRelationClassA ) ;
							}
			} ;

		// Parse Name Declaration

			void CParser :: ParseNameDeclaration ( CArray<CString , CString>* aTokens ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Name Declaration detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
				int i ;
				CString tToken ;
				int tFilledTokenIndex = -1 ;
				CString tName ;
				for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = aTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						switch ( tFilledTokenIndex ) {
							case 0 :
								// "Name"
									if ( tToken != "Name" ) {
										// Error : 1st filled token must be "Name"
										return ;
									}
								break ;
							case 1 :
								// Name
									tName = tToken ;
								break ;
							// default :
								// Error : maximum filled tokens is 2
								// return ; // Quick &  Dirty: Ignore that, in order to place comment after the name declaration
						}
					}
				}
				// Show Messages
					if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Name = " + tName , ApplicationName ( ) + " - Parse" , 0 ) ; }
				// Assign Name to Structure Add Class To Structure
					CItemAttribute* tNameAttribute = Structure -> ItemAttributes ( ) -> Item ( "Name" ) ;
					if ( tNameAttribute != 0 ) {
						tNameAttribute -> Value ( tName ) ;
					}
			} ;

		// Parse Method Declaration

			void CParser :: ParseMethodDeclaration ( CArray<CString , CString>* aTokens ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Method Declaration detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
				int i ;
				CString tToken ;
				int tFilledTokenIndex = -1 ;
				CString tClassName ;
				CString tMethodName ;
				for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = aTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						switch ( tFilledTokenIndex ) {
							case 0 :
								// "Method"
									if ( tToken != "Method" ) {
										// Error : 1st filled token must be "Method"
										return ;
									}
								break ;
							case 1 :
								// Class Name
									tClassName = tToken ;
								break ;
							case 2 :
								// .
									if ( tToken != "." ) {
										// Error : 3rd filled token must be "."
										return ;
									}
								break ;
							case 3 :
								// Method Name
									tMethodName = tToken ;
								break ;
							// default :
								// Error : maximum filled tokens is 4
								// return ; // Quick &  Dirty: Ignore that, in order to place comment after the method declaration
						}
					}
				}
				// Show Messages
					if ( ShowMessages == TRUE ) {
						MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ;
						MessageBox ( 0 , "Method Name = " + tMethodName , ApplicationName ( ) + " - Parse" , 0 ) ;
					}
				// Add Method To Class
					CItem* tClass = 0 ;
					tClass = FindClass ( tClassName ) ;
					// Add Method
						if ( tClass != 0 ) {
							CItem* tMethod ;
							tMethod = tClass -> RelatedLists ( ) -> Item ( "Class Methods" ) -> Add ( ) ;
							tMethod -> ItemAttributes ( ) -> Item ( "Name" ) -> Value ( tMethodName ) ;
						}
			} ;

		// Parse Debug Member Declaration

			void CParser :: ParseDebugMemberDeclaration ( CArray<CString , CString>* aTokens ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Debug Member Declaration detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
				int i ;
				CString tToken ;
				int tFilledTokenIndex = -1 ;
				CString tClassName ;
				CString tMemberName ;
				for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = aTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						switch ( tFilledTokenIndex ) {
							case 0 :
								// "Name"
									if ( tToken != "Debug" ) {
										// Error : 1st filled token must be "Method"
										return ;
									}
								break ;
							case 1 :
								// Class Name
									tClassName = tToken ;
								break ;
							case 2 :
								// .
									if ( tToken != "." ) {
										// Error : 3rd filled token must be "."
										return ;
									}
								break ;
							case 3 :
								// Method Name
									tMemberName = tToken ;
								break ;
							// default :
								// Error : maximum filled tokens is 4
								// return ; // Quick &  Dirty: Ignore that, in order to place comment after the method declaration
						}
					}
				}
				// Show Messages
					if ( ShowMessages == TRUE ) {
						MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ;
						MessageBox ( 0 , "Member Name = " + tMemberName , ApplicationName ( ) + " - Parse" , 0 ) ;
					}
				// Add Method To Class
					CItemAttribute* tDebugMemberAttribute = Structure -> ItemAttributes ( ) -> Item ( "Debug Member" ) ;
					if ( tDebugMemberAttribute != 0 ) {
						tDebugMemberAttribute -> Value ( tClassName + "  .  "  + tMemberName ) ;
					}
			} ;

		// Parse Method Definition

			void CParser :: ParseMethodDefinition ( CArray<CString , CString>* aTokens ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Method Definition detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
				// Determine whether it's overriding a method, or a custom method
					int i ;
					CString tToken ;
					int tFilledTokenIndex = -1 ;
					CString tSecondToken ;
					CString tClassName ;
					CString tMethodName ;
					for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
						tToken = aTokens -> GetAt ( i ) ;
						tToken.TrimLeft ( ) ;
						tToken.TrimRight ( ) ;
						if ( tToken != "" ) {
							tFilledTokenIndex += 1 ;
							// Detect Overridden Method Definition
								if ( tFilledTokenIndex == 1 && tToken == "Override" ) {
									ParseOverriddenMethodDefinition ( aTokens ) ;
									return ;
								}
							// Detect Custom Method Definition
								if ( tFilledTokenIndex == 1 && tToken != "Override" ) {
									ParseCustomMethodDefinition ( aTokens ) ;
									return ;
								}
						}
					}
			} ;

			// Get the info from the first line.
			// If it's a custom method, add it to the structure.
			// Record the current line position.
			// Look for end tag 'End Method'.
			// While at it, increment Line Index.
			// When End Tag is found, store its line position.
			// Combine the lines between start and end line to one string.
			// Retrieve the Structure Name and Folder.
				// Do I have the folder already?
			// Store the text in a file in the appropriate location.

			void CParser :: ParseOverriddenMethodDefinition ( CArray<CString , CString>* aTokens ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Overridden Method Definition detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
				// Get the info from the first line
					CString tClassName ;
					CString tMemberName ;
					CString tSystemMemberName1 ;
					CString tSystemMemberName2 ;
					ParseOverriddenMethodDefinitionGetInfoFromFirstLine (
						aTokens ,
						& tClassName ,
						& tMemberName ,
						& tSystemMemberName1 ,
						& tSystemMemberName2 ) ;
					// Show Messages
						if ( ShowMessages == TRUE ) {
							MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ;
							MessageBox ( 0 , "Member Name = " + tMemberName , ApplicationName ( ) + " - Parse" , 0 ) ;
							MessageBox ( 0 , "System Member Name 1 = " + tSystemMemberName1 , ApplicationName ( ) + " - Parse" , 0 ) ;
							MessageBox ( 0 , "System Member Name 2 = " + tSystemMemberName2 , ApplicationName ( ) + " - Parse" , 0 ) ;
						}
				// Record the current line position.
					int tFirstLine = LineIndex ;
				// Look for end tag 'End  Method'.
				// While at it, increment Line Index.
				// When End Tag is found, store its line position.
					int tLastLine = ParseMethodDefinitionLookForEndTag ( ) ;
					if ( tLastLine == -1 ) {
						// Error :  End  Method  not found.
					}
				// Combine the lines between start and end line to one string.
					CString tMethodContents = Join ( Lines , "\r\n" , tFirstLine + 1 , tLastLine - 1 ) ;
				// Retrieve the Structure Name and Folder.
					// Do I have the folder already?
					// Get Structure Name
						CString tStructureName ;
						CItemAttribute* tStructureNameAttribute = Structure -> ItemAttributes ( ) -> Item ( "Name" ) ;
						if ( tStructureNameAttribute != 0 ) {
							tStructureName = tStructureNameAttribute -> Value ( ) ;
						}
					// Get Structure Folder
						CString tStructureFolder ;
						// Not present in the structure yet.
							// CItemAttribute* tStructureFolderAttribute = Structure -> ItemAttributes ( ) -> Item ( "Folder" ) ; 
							// if ( tStructureFolderAttribute != 0 ) {
							// 	tStructureFolder = tStructureFolderAttribute -> Value ( ) ;
							// }
						tStructureFolder = Folder ;
				// Store the text in a file in the appropriate location.
					if ( FileExists ( tStructureFolder ) ) {
						CString tFilePath = tStructureFolder + "\\" + tStructureName + "  .  " + tClassName + "  .  " + tMemberName ;
						if ( tSystemMemberName1 != "" ) { tFilePath += "  .  " + tSystemMemberName1 ; }
						if ( tSystemMemberName2 != "" ) { tFilePath += "  .  " + tSystemMemberName2 ; }
						tFilePath += ".crm" ;
						SaveString ( & tMethodContents , tFilePath ) ;
					}
			} ;

			void CParser :: ParseOverriddenMethodDefinitionGetInfoFromFirstLine (
				CArray<CString , CString>* aTokens ,
				CString* aClassName ,
				CString* aMemberName ,
				CString* aSystemMemberName1 ,
				CString* aSystemMemberName2
			) {
				int i ;
				CString tToken ;
				int tFilledTokenIndex = -1 ;
				for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = aTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						switch ( tFilledTokenIndex ) {
							case 0 :
								// "Method"
									if ( tToken != "Method" ) {
										// Error : 1st filled token must be "Method"
										return ;
									}
								break ;
							case 1 :
								// "Overrides"
									if ( tToken != "Override" ) {
										// Error : 1st filled token must be "Method"
										return ;
									}
								break ;
							case 2 :
								// Class Name
									*aClassName = tToken ;
								break ;
							case 3 :
								// .
									if ( tToken != "." ) {
										// Error : 3rd filled token must be "."
										return ;
									}
								break ;
							case 4 : 
								// Member Name
									*aMemberName = tToken ;
								break ;
							case 5 :
								// .
									if ( tToken != "." ) {
										// Error : 3rd filled token must be "."
										return ;
									}
								break ;
							case 6 : 
								// System Member Name 1
									*aSystemMemberName1 = tToken ;
								break ;
							case 7 :
								// '.'  or second token of Member Name 1 ( 'Item'  in  'Initialize  Item' )
									if ( tToken == "." ) {
										// Ok
									}
									else {
										*aSystemMemberName1 += "  " + tToken ;
									}
								break ;
							case 8 : 
								// System Member Name 2
									*aSystemMemberName2 = tToken ;
								break ;
							// default :
								// Error : maximum filled tokens is 10
								// return ; // Quick &  Dirty : Ignore that, in order to place comment after the method declaration
						}
					}
				}
			} ;

			void CParser :: ParseCustomMethodDefinition ( CArray<CString , CString>* aTokens ) {
				if ( ShowMessages == TRUE ) { MessageBox ( 0 , "Custom Method Definition detected." , ApplicationName ( ) + " - Parse" , 0 ) ; }
				// Get the info from the first line
					CString tClassName ;
					CString tMethodName ;
					ParseCustomMethodDefinitionGetInfoFromFirstLine (
						aTokens ,
						& tClassName ,
						& tMethodName ) ;
					// Show Messages
						if ( ShowMessages == TRUE ) {
							MessageBox ( 0 , "Class Name = " + tClassName , ApplicationName ( ) + " - Parse" , 0 ) ;
							MessageBox ( 0 , "Method Name = " + tMethodName , ApplicationName ( ) + " - Parse" , 0 ) ;
						}
				// Record the current line position.
					int tFirstLine = LineIndex ;
				// Look for end tag 'End  Method'.
				// While at it, increment Line Index.
				// When End Tag is found, store its line position.
					int tLastLine = ParseMethodDefinitionLookForEndTag ( ) ;
					if ( tLastLine == -1 ) {
						// Error :  End  Method  not found.
					}
				// Combine the lines between start and end line to one string.
					CString tMethodContents = Join ( Lines , "\r\n" , tFirstLine + 1 , tLastLine - 1 ) ;
				// Retrieve the Structure Name and Folder.
					// Do I have the folder already?
					// Get Structure Name
						CString tStructureName ;
						CItemAttribute* tStructureNameAttribute = Structure -> ItemAttributes ( ) -> Item ( "Name" ) ;
						if ( tStructureNameAttribute != 0 ) {
							tStructureName = tStructureNameAttribute -> Value ( ) ;
						}
					// Get Structure Folder
						CString tStructureFolder ;
						// Not present in the structure yet.
							// CItemAttribute* tStructureFolderAttribute = Structure -> ItemAttributes ( ) -> Item ( "Folder" ) ; 
							// if ( tStructureFolderAttribute != 0 ) {
							// 	tStructureFolder = tStructureFolderAttribute -> Value ( ) ;
							// }
						tStructureFolder = Folder ;
				// Store the text in a file in the appropriate location.
					if ( FileExists ( tStructureFolder ) ) {
						CString tFilePath = tStructureFolder + "\\" + tStructureName + "  .  " + tClassName + "  .  " + tMethodName + ".crm" ;
						SaveString ( & tMethodContents , tFilePath ) ;
					}
				// Add Method To Class
					CItem* tClass = 0 ;
					tClass = FindClass ( tClassName ) ;
					// Add Method
						if ( tClass != 0 ) {
							CItem* tMethod ;
							tMethod = tClass -> RelatedLists ( ) -> Item ( "Class Methods" ) -> Add ( ) ;
							tMethod -> ItemAttributes ( ) -> Item ( "Name" ) -> Value ( tMethodName ) ;
						}
			} ;

			void CParser :: ParseCustomMethodDefinitionGetInfoFromFirstLine (
				CArray<CString , CString>* aTokens ,
				CString* aClassName ,
				CString* aMethodName
			) {
				int i ;
				CString tToken ;
				int tFilledTokenIndex = -1 ;
				for ( i = 0 ; i <= aTokens -> GetSize ( ) - 1 ; i ++ ) {
					tToken = aTokens -> GetAt ( i ) ;
					tToken.TrimLeft ( ) ;
					tToken.TrimRight ( ) ;
					if ( tToken != "" ) {
						tFilledTokenIndex += 1 ;
						switch ( tFilledTokenIndex ) {
							case 0 :
								// "Method"
									if ( tToken != "Method" ) {
										// Error : 1st filled token must be "Method"
										return ;
									}
								break ;
							case 1 :
								// Class Name
									*aClassName = tToken ;
								break ;
							case 2 :
								// .
									if ( tToken != "." ) {
										// Error : 3rd filled token must be "."
										return ;
									}
								break ;
							case 3 : 
								// Method Name
									*aMethodName = tToken ;
								break ;
							// default :
								// Error : maximum filled tokens is 4
								// return ; // Quick &  Dirty : Ignore that, in order to place comment after the method declaration
						}
					}
				}
			} ;

			int CParser :: ParseMethodDefinitionLookForEndTag ( ) {
				CString tLine ;
				for ( LineIndex = LineIndex + 1 ; LineIndex <= Lines -> GetSize ( ) - 1 ; LineIndex ++ ) {
					tLine = Lines -> GetAt ( LineIndex ) ;
					tLine . TrimLeft ( ) ;
					tLine . TrimRight ( ) ;
					if ( tLine == "End  Method" ) {
						return LineIndex ;
					}
				}
				return -1 ;
			} ;

	// Parse Data Manipulation

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
									tOperandAAttribute -> Value = tOperandBAttribute -> Value ( ) ;
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

// Layer : Compile Methods

	void CParser :: CompileMethods ( ) {
		// Get Structure Attributes
			CItemAttribute* tStructureNameAttribute = Structure -> ItemAttributes ( ) -> Item ( "Name" ) ;
			if ( tStructureNameAttribute == 0 ) { return ; }
			CString tStructureName = tStructureNameAttribute -> Value ( ) ;
			CItemAttribute* tStructureFolderAttribute = Structure -> ItemAttributes ( ) -> Item ( "Folder" ) ;
			if ( tStructureFolderAttribute == 0 ) { return ; }
			CString tStructureFolder = tStructureFolderAttribute -> Value ( ) ;
			if ( tStructureFolder == "" ) { return ; }
			CItemAttribute* tDebugMemberAttribute = Structure -> ItemAttributes ( ) -> Item ( "Debug Member" ) ;
			if ( tDebugMemberAttribute == 0 ) { return ; }
			CString tDebugMember = tDebugMemberAttribute -> Value ( ) ;
		// Delete compiler errors file
			CString tCompilerErrorsFilePath = tStructureFolder + "\\" + "Compiler Errors.txt" ;
			if ( FileExists ( tCompilerErrorsFilePath ) ) { DeleteFile ( tCompilerErrorsFilePath ) ; }
		// Declare Variables for Debug Member
			CItem* tDebugAttribute = 0 ;
			CItem* tDebugMethod = 0 ;
			CItem* tDebugRelatedItem = 0 ;
			CItem* tDebugRelatedList = 0 ;
			CString tDebugClassName ;
			CString tDebugMemberName ;
		// Traverse Classes
			CRelatedList* tClasses = Structure -> RelatedLists ( ) -> Item ( "Classes" ) ;
			for ( int i = 0 ; i <= tClasses -> StorageCount ( ) - 1 ; i ++ ) {
				if ( tClasses -> PositionUsed ( i ) == TRUE ) {
					CItem* tClass = tClasses -> Item ( i ) ;
					CItemAttribute* tClassNameAttribute = tClass -> ItemAttributes ( ) -> Item ( "Class Name" ) ;
					CString tClassName = tClassNameAttribute -> Value ( ) ;
					int j ;
					// Traverse Attributes
						CRelatedList* tClassAttributes = tClass -> RelatedLists ( ) -> Item ( "Class Attributes" ) ;
						for ( j = 0 ; j <= tClassAttributes -> StorageCount ( ) - 1 ; j ++ ) {
							if ( tClassAttributes -> PositionUsed ( j ) == TRUE ) {
								CItem* tClassAttribute = tClassAttributes -> Item ( j ) ;
								CItemAttribute* tClassAttributeNameAttribute = tClassAttribute -> ItemAttributes ( ) -> Item ( "Name" ) ;
								CString tAttributeName = tClassAttributeNameAttribute -> Value ( ) ;
								CompileAttributeMethodDll ( tStructureFolder , tStructureName , tClassName , tAttributeName ) ;
								if ( tClassName + "  .  " + tAttributeName == tDebugMember ) {
									tDebugAttribute = tClassAttribute ;
									tDebugClassName = tClassName ;
									tDebugMemberName = tAttributeName ;
								}
							}
						}
					// Traverse Methods
						CRelatedList* tClassMethods = tClass -> RelatedLists ( ) -> Item ( "Class Methods" ) ;
						for ( j = 0 ; j <= tClassMethods -> StorageCount ( ) - 1 ; j ++ ) {
							if ( tClassMethods -> PositionUsed ( j ) == TRUE ) {
								CItem* tClassMethod = tClassMethods -> Item ( j ) ;
								CItemAttribute* tClassMethodNameAttribute = tClassMethod -> ItemAttributes ( ) -> Item ( "Name" ) ;
								CString tMethodName = tClassMethodNameAttribute -> Value ( ) ;
								CompileMethodDll ( tStructureFolder , tStructureName , tClassName , tMethodName ) ;
								if ( tClassName + "  .  " + tMethodName == tDebugMember ) {
									tDebugMethod = tClassMethod ;
									tDebugClassName = tClassName ;
									tDebugMemberName = tMethodName ;
								}
							}
						}
					// Traverse Related Classes
						CRelatedList* tRelatedClasses = tClass -> RelatedLists ( ) -> Item ( "Related Classes" ) ;
						for ( j = 0 ; j <= tRelatedClasses -> StorageCount ( ) - 1 ; j ++ ) {
							if ( tRelatedClasses -> PositionUsed ( j ) == TRUE ) {
								CItem* tRelatedClass = tRelatedClasses -> Item ( j ) ;
								CItemAttribute* tRelatedClassNameAttribute = tRelatedClass -> ItemAttributes ( ) -> Item ( "Name" ) ;
								CString tRelatedClassName = tRelatedClassNameAttribute -> Value ( ) ;
								CItemAttribute* tRelatedClassPluralAttribute = tRelatedClass -> ItemAttributes ( ) -> Item ( "Plural" ) ;
								CString tRelatedClassPlural = tRelatedClassPluralAttribute -> Value ( ) ;
								if ( tRelatedClassPlural == "True" ) {
									CompileRelatedListMethodDll ( tStructureFolder , tStructureName , tClassName , tRelatedClassName ) ;
									if ( tClassName + "  .  " + tRelatedClassName == tDebugMember ) {
										tDebugRelatedList = tRelatedClass ;
										tDebugClassName = tClassName ;
										tDebugMemberName = tRelatedClassName ;
									}
								}
								else {
									CompileRelatedItemMethodDll ( tStructureFolder , tStructureName , tClassName , tRelatedClassName ) ;
									if ( tClassName + "  .  " + tRelatedClassName == tDebugMember ) {
										tDebugRelatedItem = tRelatedClass ;
										tDebugClassName = tClassName ;
										tDebugMemberName = tRelatedClassName ;
									}
								}
							}
						}
				}
			}
		// Recompile Member to Debug
			if ( tDebugAttribute != 0 ) {
				CompileAttributeMethodDll ( tStructureFolder , tStructureName , tDebugClassName , tDebugMemberName ) ;
			}
			if ( tDebugMethod != 0 ) {
				CompileMethodDll ( tStructureFolder , tStructureName , tDebugClassName , tDebugMemberName ) ;
			}
			if ( tDebugRelatedItem != 0 ) {
				CompileRelatedItemMethodDll ( tStructureFolder , tStructureName , tDebugClassName , tDebugMemberName ) ;
			}
			if ( tDebugRelatedList != 0 ) {
				CompileRelatedListMethodDll ( tStructureFolder , tStructureName , tDebugClassName , tDebugMemberName ) ;
			}
		// Show compiler errors
			if ( FileExists ( tCompilerErrorsFilePath ) ) {
				if ( FileSize ( tCompilerErrorsFilePath ) == 0 ) {
					DeleteFile ( tCompilerErrorsFilePath ) ;
				}
				else {
					CString tCommand ;
					tCommand = ( CString ) "Echo Off" + "\r\n" ;
					tCommand += ( CString ) "Notepad " + "\"" + tCompilerErrorsFilePath + "\"" + "\r\n" ;
					Shell ( tCommand , FALSE ) ;
				}
			}
	} ;

	void CParser :: CompileAttributeMethodDll (
		CString aStructureFolder ,
		CString aStructureName ,
		CString aClassName ,
		CString aAttributeName
	) {
		CString tGetSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aAttributeName + "  .  Get" + ".crm" ;
		CString tSetSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aAttributeName + "  .  Set" + ".crm" ;
		if ( FileExists ( tGetSourcePath ) || FileExists ( tSetSourcePath ) ) {
			CString tAttributeMethodDllCppSourceCodeFolderPath = GetRegistryValue ( "AttributeMethodDllCppSourceCodeFolderPath" ) ;
			CString tEmptyString = "" ;
			// Copy Get
				CString tGetTargetPath = tAttributeMethodDllCppSourceCodeFolderPath + "\\OverrideGet.h" ;
				if ( FileExists ( tGetSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tGetCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tGetSourcePath ) ) ;
							SaveString ( & tGetCode ,  tGetTargetPath ) ;
						// AlterFileWriteTime ( tGetTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tGetTargetPath ) ;
						SaveString ( & tEmptyString , tGetTargetPath ) ;
						// AlterFileWriteTime ( tGetTargetPath ) ;
				}
			// Copy Set
				CString tSetTargetPath = tAttributeMethodDllCppSourceCodeFolderPath + "\\OverrideSet.h" ;
				if ( FileExists ( tSetSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tSetCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tSetSourcePath ) ) ;
							SaveString ( & tSetCode ,  tSetTargetPath ) ;
						// AlterFileWriteTime ( tSetTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tSetTargetPath ) ;
						SaveString ( &tEmptyString , tSetTargetPath ) ;
						// AlterFileWriteTime ( tSetTargetPath ) ;
				}
			// Delete obj file and output DLL
				DeleteFile ( tAttributeMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorAttributeMethodDll.obj" ) ;
				DeleteFile ( tAttributeMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorAttributeMethodDll.dll" ) ;
			// Prepare Compiler Error Files
				CString tTempCompilerErrorsFilePath = aStructureFolder + "\\" + "Temp Compiler Errors.txt" ;
				CString tCompilerErrorsFilePath = aStructureFolder + "\\" + "Compiler Errors.txt" ;
				if ( ! FileExists ( tCompilerErrorsFilePath ) ) { SaveString ( &tEmptyString , tCompilerErrorsFilePath ) ; }
			// Build DLL
				CString tBuildCommand = "";
				tBuildCommand += ( CString ) "Echo " + aStructureName + "  .  " + aClassName + "  .  " + aAttributeName + "\r\n" ;
				tBuildCommand += ( CString ) "Echo -----" + "\r\n" ;
				tBuildCommand += ( CString ) tAttributeMethodDllCppSourceCodeFolderPath . Left ( 1 ) + ":" + "\r\n" ;
				tBuildCommand += ( CString ) "chdir " + "\"" + tAttributeMethodDllCppSourceCodeFolderPath + "\"" + "\r\n" ;
				tBuildCommand += ( CString ) "nmake " + "\"" + "CreatorAttributeMethodDll.mak" + "\"" 
					+ " /x " + "\"" + tTempCompilerErrorsFilePath + "\""
					+ " CFG=\"CreatorAttributeMethodDll - Win32 "+ DebugOrRelease +"\"" + "\r\n" ;
				Shell ( tBuildCommand , TRUE ) ;
			// Accumulate compiler errors
				if ( FileSize ( tTempCompilerErrorsFilePath ) > 131 ) {
					// If the file is large enough
						CString tAccumulateErrorsCommand ;
						tAccumulateErrorsCommand = ( CString ) "copy " + "\"" + tCompilerErrorsFilePath + "\" + \"" + tTempCompilerErrorsFilePath + "\" \"" + tCompilerErrorsFilePath + "\"" + "\r\n" ;
						tAccumulateErrorsCommand += ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n";
						Shell ( tAccumulateErrorsCommand , TRUE ) ;
						// Build again, now leaving the window open.
							tBuildCommand = ( CString )
								"Echo ERRORS!" + "\r\n" 
								+ "Echo -----" + "\r\n" 
								+ tBuildCommand ;
							Shell ( tBuildCommand , TRUE , TRUE , TRUE ) ; 
				}
				Shell ( ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n" ) ;
			// Copy Output DLL
				CString tSourceDllFilePath = tAttributeMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\" + "CreatorAttributeMethodDll.dll" ;
				if ( FileExists ( tSourceDllFilePath ) ) {
					CopyFile (
						tSourceDllFilePath  ,
						aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aAttributeName + ".dll" , FALSE ) ;
				}
		}
	};

	void CParser :: CompileMethodDll (
		CString aStructureFolder ,
		CString aStructureName ,
		CString aClassName ,
		CString aMethodName
	) {
		CString tMethodCodeSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aMethodName + ".crm" ;
		if ( FileExists ( tMethodCodeSourcePath ) ) {
			CString tMethodDllCppSourceCodeFolderPath = GetRegistryValue ( "MethodDllCppSourceCodeFolderPath" ) ;
			CString tEmptyString = "" ;
			// Copy Method Code
				CString tMethodCodeTargetPath = tMethodDllCppSourceCodeFolderPath + "\\ExecuteMethod.h" ;
				CopyFile ( tMethodCodeSourcePath , tMethodCodeTargetPath , FALSE ) ;
				// AlterFileWriteTime ( tMethodCodeTargetPath ) ;
			// Delete obj file and output DLL
				DeleteFile ( tMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorMethodDll.obj" ) ;
				DeleteFile ( tMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorMethodDll.dll" ) ;
			// Prepare Compiler Error Files
				CString tTempCompilerErrorsFilePath = aStructureFolder + "\\" + "Temp Compiler Errors.txt" ;
				CString tCompilerErrorsFilePath = aStructureFolder + "\\" + "Compiler Errors.txt" ;
				if ( ! FileExists ( tCompilerErrorsFilePath ) ) { SaveString ( &tEmptyString , tCompilerErrorsFilePath ) ; }
			// Build DLL
				CString tBuildCommand = "";
				tBuildCommand += ( CString ) "Echo " + aStructureName + "  .  " + aClassName + "  .  " + aMethodName + "\r\n" ;
				tBuildCommand += ( CString ) "Echo -----" + "\r\n" ;
				tBuildCommand += ( CString ) tMethodDllCppSourceCodeFolderPath . Left ( 1 ) + ":" + "\r\n" ;
				tBuildCommand += ( CString ) "chdir " + "\"" + tMethodDllCppSourceCodeFolderPath + "\"" + "\r\n" ;
				tBuildCommand += ( CString ) "nmake " + "\"" + "CreatorMethodDll.mak" + "\"" 
					+ " /x " + "\"" + tTempCompilerErrorsFilePath + "\""
					+ " CFG=\"CreatorMethodDll - Win32 "+ DebugOrRelease +"\""+ "\r\n" ;
				Shell ( tBuildCommand , TRUE ) ;
			// Accumulate compiler errors 
				if ( FileSize ( tTempCompilerErrorsFilePath ) > 131 ) {
					// If the file is large enough
						CString tAccumulateErrorsCommand ;
						tAccumulateErrorsCommand = ( CString ) "copy " + "\"" + tCompilerErrorsFilePath + "\" + \"" + tTempCompilerErrorsFilePath + "\" \"" + tCompilerErrorsFilePath + "\"" + "\r\n" ;
						tAccumulateErrorsCommand += ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n";
						Shell ( tAccumulateErrorsCommand , TRUE ) ;
						// Build again, now leaving the window open.
							tBuildCommand = ( CString )
								"Echo ERRORS!" + "\r\n" 
								+ "Echo -----" + "\r\n" 
								+ tBuildCommand ;
							Shell ( tBuildCommand , TRUE , TRUE , TRUE ) ; 
				}
				Shell ( ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n" ) ;
			// Copy Output DLL
				CString tSourceDllFilePath = tMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\" + "CreatorMethodDll.dll" ;
				if ( FileExists ( tSourceDllFilePath ) ) {
					CopyFile (
						tSourceDllFilePath  ,
						aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aMethodName + ".dll" , FALSE ) ;
				}
		}
	};

	void CParser :: CompileRelatedItemMethodDll (
		CString aStructureFolder ,
		CString aStructureName ,
		CString aClassName ,
		CString aRelatedClassName
	) {
		CString tGetSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "  .  Get" + ".crm" ;
		CString tSetSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "  .  Set" + ".crm" ;
		if ( FileExists ( tGetSourcePath ) || FileExists ( tSetSourcePath ) ) {
			CString tRelatedItemMethodDllCppSourceCodeFolderPath = GetRegistryValue ( "RelatedItemMethodDllCppSourceCodeFolderPath" ) ;
			CString tEmptyString = "" ;
			// Copy Get
				CString tGetTargetPath = tRelatedItemMethodDllCppSourceCodeFolderPath + "\\OverrideItemGet.h" ;
				if ( FileExists ( tGetSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tOverrideGetCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tGetSourcePath ) ) ;
							SaveString ( & tOverrideGetCode ,  tGetTargetPath ) ;
						// AlterFileWriteTime ( tGetTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tGetTargetPath ) ;
						SaveString ( & tEmptyString , tGetTargetPath ) ;
						// AlterFileWriteTime ( tGetTargetPath ) ;
				}
			// Copy Set
				CString tSetTargetPath = tRelatedItemMethodDllCppSourceCodeFolderPath + "\\OverrideItemSet.h" ;
				if ( FileExists ( tSetSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tOverrideSetCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tSetSourcePath ) ) ;
							SaveString ( & tOverrideSetCode ,  tSetTargetPath ) ;
						// AlterFileWriteTime ( tSetTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tSetTargetPath ) ;
						SaveString ( &tEmptyString , tSetTargetPath ) ;
						// AlterFileWriteTime ( tSetTargetPath ) ;
				}
			// Delete obj file and output DLL
				DeleteFile ( tRelatedItemMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorRelatedItemMethodDll.obj" ) ;
				DeleteFile ( tRelatedItemMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorRelatedItemMethodDll.dll" ) ;
			// Prepare Compiler Error Files
				CString tTempCompilerErrorsFilePath = aStructureFolder + "\\" + "Temp Compiler Errors.txt" ;
				CString tCompilerErrorsFilePath = aStructureFolder + "\\" + "Compiler Errors.txt" ;
				if ( ! FileExists ( tCompilerErrorsFilePath ) ) { SaveString ( &tEmptyString , tCompilerErrorsFilePath ) ; }
			// Build DLL
				CString tBuildCommand = "";
				tBuildCommand += ( CString ) "Echo " + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "\r\n" ;
				tBuildCommand += ( CString ) "Echo -----" + "\r\n" ;
				tBuildCommand += ( CString ) tRelatedItemMethodDllCppSourceCodeFolderPath . Left ( 1 ) + ":" + "\r\n" ;
				tBuildCommand += ( CString ) "chdir " + "\"" + tRelatedItemMethodDllCppSourceCodeFolderPath + "\"" + "\r\n" ;
				tBuildCommand += ( CString ) "nmake " + "\"" + "CreatorRelatedItemMethodDll.mak" + "\""
					+ " /x " + "\"" + tTempCompilerErrorsFilePath + "\""
					+ " CFG=\"CreatorRelatedItemMethodDll - Win32 "+ DebugOrRelease +"\""+ "\r\n" ;
				Shell ( tBuildCommand , TRUE ) ;
			// Accumulate compiler errors
				if ( FileSize ( tTempCompilerErrorsFilePath ) > 131 ) {
					// If the file is large enough
						CString tAccumulateErrorsCommand ;
						tAccumulateErrorsCommand = ( CString ) "copy " + "\"" + tCompilerErrorsFilePath + "\" + \"" + tTempCompilerErrorsFilePath + "\" \"" + tCompilerErrorsFilePath + "\"" + "\r\n" ;
						tAccumulateErrorsCommand += ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n";
						Shell ( tAccumulateErrorsCommand , TRUE ) ;
						// Build again, now leaving the window open.
							tBuildCommand = ( CString )
								"Echo ERRORS!" + "\r\n" 
								+ "Echo -----" + "\r\n" 
								+ tBuildCommand ;
							Shell ( tBuildCommand , TRUE , TRUE , TRUE ) ; 
				}
				Shell ( ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n" ) ;
			// Copy Output DLL
				CString tSourceDllFilePath = tRelatedItemMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\" + "CreatorRelatedItemMethodDll.dll" ;
				if ( FileExists ( tSourceDllFilePath ) ) {
					CopyFile (
						tSourceDllFilePath  ,
						aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + ".dll" , FALSE ) ;
				}
		}
	};

	void CParser :: CompileRelatedListMethodDll (
		CString aStructureFolder ,
		CString aStructureName ,
		CString aClassName ,
		CString aRelatedClassName
	) {
		CString tItemGetSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "  .  Item  .  Get" + ".crm" ;
		CString tItemSetSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "  .  Item  .  Set" + ".crm" ;
		CString tInitializeItemSourcePath = aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "  .  Initialize  Item" + ".crm" ;
		if ( FileExists ( tItemGetSourcePath ) || FileExists ( tItemSetSourcePath ) || FileExists ( tInitializeItemSourcePath ) ) {
			CString tRelatedListMethodDllCppSourceCodeFolderPath = GetRegistryValue ( "RelatedListMethodDllCppSourceCodeFolderPath" ) ;
			CString tEmptyString = "" ;
			// Copy Item Get
				CString tItemGetTargetPath = tRelatedListMethodDllCppSourceCodeFolderPath + "\\OverrideItemGet.h" ;
				if ( FileExists ( tItemGetSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tItemGetCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tItemGetSourcePath ) ) ;
							SaveString ( & tItemGetCode ,  tItemGetTargetPath ) ;
						// AlterFileWriteTime ( tItemGetTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tItemGetTargetPath ) ;
						SaveString ( & tEmptyString , tItemGetTargetPath ) ;
						// AlterFileWriteTime ( tItemGetTargetPath ) ;
				}
			// Copy Item Set
				CString tItemSetTargetPath = tRelatedListMethodDllCppSourceCodeFolderPath + "\\OverrideItemSet.h" ;
				if ( FileExists ( tItemSetSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tItemSetCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tItemSetSourcePath ) ) ;
							SaveString ( & tItemSetCode ,  tItemSetTargetPath ) ;
						// AlterFileWriteTime ( tItemSetTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tItemSetTargetPath ) ;
						SaveString ( &tEmptyString , tItemSetTargetPath ) ;
						// AlterFileWriteTime ( tItemSetTargetPath ) ;
				}
			// Copy Initialize Item
				CString tInitializeItemTargetPath = tRelatedListMethodDllCppSourceCodeFolderPath + "\\OverrideInitializeItem.h" ;
				if ( FileExists ( tInitializeItemSourcePath ) ) {
					// Copy it to the DLL C++ code path
						// Use LoadString and SaveString to add an extra line of code to it : *aOverridden = TRUE ;
							CString tInitializeItemCode = ( CString ) "*aOverridden = TRUE ;" + "\r\n" + * ( LoadString ( tInitializeItemSourcePath ) ) ;
							SaveString ( & tInitializeItemCode ,  tInitializeItemTargetPath ) ;
						// AlterFileWriteTime ( tInitializeItemTargetPath ) ;
				}
				else {
					// Create an empty file to the C++ code path
						DeleteFile ( tInitializeItemTargetPath ) ;
						SaveString ( &tEmptyString , tInitializeItemTargetPath ) ;
						// AlterFileWriteTime ( tInitializeItemTargetPath ) ;
				}
			// Delete obj file and output DLL
				DeleteFile ( tRelatedListMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorRelatedListMethodDll.obj" ) ;
				DeleteFile ( tRelatedListMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\CreatorRelatedListMethodDll.dll" ) ;
			// Prepare Compiler Error Files
				CString tTempCompilerErrorsFilePath = aStructureFolder + "\\" + "Temp Compiler Errors.txt" ;
				CString tCompilerErrorsFilePath = aStructureFolder + "\\" + "Compiler Errors.txt" ;
				if ( ! FileExists ( tCompilerErrorsFilePath ) ) { SaveString ( &tEmptyString , tCompilerErrorsFilePath ) ; }
			// Build DLL
				CString tBuildCommand = "";
				tBuildCommand += ( CString ) "Echo " + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + "\r\n" ;
				tBuildCommand += ( CString ) "Echo -----" + "\r\n" ;
				tBuildCommand += ( CString ) tRelatedListMethodDllCppSourceCodeFolderPath . Left ( 1 ) + ":" + "\r\n" ;
				tBuildCommand += ( CString ) "chdir " + "\"" + tRelatedListMethodDllCppSourceCodeFolderPath + "\"" + "\r\n" ;
				tBuildCommand += ( CString ) "nmake " + "\"" + "CreatorRelatedListMethodDll.mak" + "\"" 
					+ " /x " + "\"" + tTempCompilerErrorsFilePath + "\""
					+ " CFG=\"CreatorRelatedListMethodDll - Win32 "+ DebugOrRelease +"\""+ "\r\n" ;
				Shell ( tBuildCommand , TRUE ) ;
			// Accumulate compiler errors
				if ( FileSize ( tTempCompilerErrorsFilePath ) > 131 ) {
					// If the file is large enough
						CString tAccumulateErrorsCommand ;
						tAccumulateErrorsCommand = ( CString ) "copy " + "\"" + tCompilerErrorsFilePath + "\" + \"" + tTempCompilerErrorsFilePath + "\" \"" + tCompilerErrorsFilePath + "\"" + "\r\n" ;
						tAccumulateErrorsCommand += ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n";
						Shell ( tAccumulateErrorsCommand , TRUE ) ;
						// Build again, now leaving the window open.
							tBuildCommand = ( CString )
								"Echo ERRORS!" + "\r\n" 
								+ "Echo -----" + "\r\n" 
								+ tBuildCommand ;
							Shell ( tBuildCommand , TRUE , TRUE , TRUE ) ; 
				}
				Shell ( ( CString ) "del " + "\"" + tTempCompilerErrorsFilePath + "\"" + "\r\n" ) ;
			// Copy Output DLL
				CString tSourceDllFilePath = tRelatedListMethodDllCppSourceCodeFolderPath + "\\" + DebugOrRelease + "\\" + "CreatorRelatedListMethodDll.dll" ;
				if ( FileExists ( tSourceDllFilePath ) ) {
					CopyFile (
						tSourceDllFilePath  ,
						aStructureFolder + "\\" + aStructureName + "  .  " + aClassName + "  .  " + aRelatedClassName + ".dll" , FALSE ) ;
				}
		}
	};

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

	CString CParser :: Join ( CArray<CString , CString>* aElements , CString aDelimiter , int aFirstIndex , int aLastIndex ) {
		// Resolve Optional Parameters
			if ( aFirstIndex == -1 ) { aFirstIndex = 0 ; }
			if ( aLastIndex == -1 ) { aLastIndex = aElements -> GetSize ( ) - 1 ; }
		// Correct Parameters
			if ( aFirstIndex < 0 ) { aFirstIndex = 0 ; }
			if ( aLastIndex > aElements -> GetSize ( ) - 1 ) { aLastIndex = aElements -> GetSize ( ) - 1 ; }
		// Conditions
			if ( aLastIndex < aFirstIndex ) { return "" ; }
		// Functionality
			CString tReturnValue ;
			for ( int i = aFirstIndex ; i <= aLastIndex - 1 ; i ++ ) {
				tReturnValue += aElements -> GetAt ( i ) ;
				tReturnValue += aDelimiter ;
			}
			tReturnValue += aElements -> GetAt ( i ) ;
			return tReturnValue ;
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
				if ( tClass -> ItemAttributes ( ) -> Item ( "Class Name" ) -> Value ( ) == aName ) {
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

	/*
	void CParser :: AlterFileWriteTime ( CString aFilePath ) {
		HANDLE tFileHandle = CreateFile (
			( LPCTSTR ) aFilePath , 
			GENERIC_READ | GENERIC_WRITE ,
			FILE_SHARE_READ ,
			0 ,
			OPEN_EXISTING ,
			FILE_ATTRIBUTE_NORMAL ,
			0 ) ;
		FILETIME tFileTime ;
		if ( GetFileTime ( tFileHandle , 0 , 0 , & tFileTime ) == 0 ) { return ; }
		SYSTEMTIME tFileTimeFormatted ; 
		if ( FileTimeToSystemTime ( & tFileTime , & tFileTimeFormatted ) != TRUE ) { return ; }
		// This trick I do with the minute will make sure it's always a minute later than the file it was last built with
		      // Instead ... if the build was done in the previous Creator module compilatation that started on the same second
			  // So that should happen averagely once every 60 Creator modules you build.
		WORD tMinuteTest = 65535 ;
		WORD tHourTest = 65535 ;
		WORD tDayTest = 65535 ;
		WORD tMonthTest = 65535 ;
		WORD tYearTest = 65535 ;
		tMinuteTest = tFileTimeFormatted . wMinute ;
		tHourTest = tFileTimeFormatted . wHour ;
		tDayTest = tFileTimeFormatted . wDay ;
		tMonthTest = tFileTimeFormatted . wMonth ;
		tYearTest = tFileTimeFormatted . wYear ;
		static WORD tMinute = 65535 ;
		static WORD tHour = 65535 ;
		static WORD tDay = 65535 ;
		static WORD tMonth = 65535 ;
		static WORD tYear = 65535 ;
		if ( tMinute == 65535 ) { tMinute = tFileTimeFormatted . wMinute ; }
		if ( tHour == 65535 ) { tHour = tFileTimeFormatted . wHour ; }
		if ( tDay == 65535 ) { tDay = tFileTimeFormatted . wDay ; }
		if ( tMonth == 65535 ) { tMonth = tFileTimeFormatted . wMonth ; }
		if ( tYear == 65535 ) { tYear = tFileTimeFormatted . wYear ; }
		tMinute += 1 ;
		if ( tMinute == 60 ) {
			tMinute = 0 ;
			tHour += 1 ;
			if ( tHour == 24 ) {
				tHour = 0 ;
				tDay += 1 ;
				if ( tDay > 28 ) {
					tDay = 1 ;
					tMonth += 1 ;
					if ( tMonth == 13 ) {
						tMonth = 1 ;
						tYear += 1 ;
					}
				}
			}
		}
		tFileTimeFormatted.wMinute = tMinute ;
		tFileTimeFormatted.wHour = tHour ;
		tFileTimeFormatted.wDay = tDay ;
		tFileTimeFormatted.wMonth = tMonth ;
		tFileTimeFormatted.wYear = tYear ;
		if ( SystemTimeToFileTime ( & tFileTimeFormatted , & tFileTime ) != TRUE ) { return ; }
		SetFileTime ( tFileHandle , 0 , 0 , &tFileTime ) ;
		FlushFileBuffers ( tFileHandle ) ;
		CloseHandle ( tFileHandle ) ;
		// Sleep ( 2000 ) ; // !!! The only thing that seems to work is this.
	} ;
	*/
