//
//	Creator . Parser
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Friday, March 30, 2007 - Saturday, March 31, 2007
//
// -----

// Includes

	#include "stdafx.h"

// Classes
	
	class CParser {

		// Layer 1 : Constructor & Destructor
			
			public : CParser ( ) ;
			public : ~CParser ( ) ;

		// Layer 2 : Parse Text
		
			// Input
				
				// Text

					public : CString Text ;
					
				// Structure for the structure to build  ( two Creator layers are supported )

					public : gggCCreator* gggCreator ;
					public : CCreator* Creator ;
				
				// Data item considered the globality
					
					public : CItem* Global ;

				// Options

					public : BOOL StructureDefinitionLanguageOn ;
					// public : BOOL DataManipulationLanguageOn ;
					public : BOOL ShowMessages ;

			// Operation
			
				public : void Parse ( ) ;

			// Output
			
				public : CItem* Structure ;

		// Layer 3 : Parse Line

			private : void ParseLine ( CString aText ) ;

		// Layer 4 : Parse Line for different language sections
			
			private : void ParseLineForStructureDefinition ( CString aText ) ;
			// private : void ParseLineForDataManipulation ( CString aText ) ;

		// Layer 4 : Parse Individual Statements

			// Structure Definition

				private : void ParseRelationDeclaration ( CArray<CString , CString>* aTokens ) ;
				private : void ParseAttributeDeclaration ( CArray<CString , CString>* aTokens ) ;
				private : void ParseClassDeclaration ( CArray<CString , CString>* aTokens ) ;

			// Data Manipulation

				// private : void ParseAssignment ( CString aLine ) ;
				// private : void ParseSpecifier ( CString aText , CItemAttribute** aItemAttribute , CItem*** aItem ) ; // ParseSpecifier returns a reference to a reference to an item by reference

		// Layer 5 :  Helpers

			private : CArray<CString , CString>* Split ( CString aText , CString aDelimiter ) ;
			private : BOOL StartsWith ( CString aText , CString aStart ) ;
			private : CItem* FindClass ( CString aName ) ;
			private : void DeleteRelationClassesAAndB ( ) ;
	
	} ;
