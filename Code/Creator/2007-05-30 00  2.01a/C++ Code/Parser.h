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

		// Constructor & Destructor
			
			public:

				CParser ( ) ;
				~CParser ( ) ;

		// Public
			
			public:
			
				// Variables
				
					CString Text ;
					gggCCreator* gggCreator ;
					CCreator* Creator ;
					CItem* Structure ;
					BOOL ShowMessages ;

				// Methods	
				
					void Parse ( ) ;
						
		// Private

			private:
								
				// Methods

					CArray<CString , CString>* Split ( CString aText , CString aDelimiter ) ;
					void ParseLine ( CString aText ) ;
					void ParseRelationDeclaration ( CArray<CString , CString>* aTokens ) ;
					void ParseAttributeDeclaration ( CArray<CString , CString>* aTokens ) ;
					void ParseClassDeclaration ( CArray<CString , CString>* aTokens ) ;
					void DeleteRelationClassesAAndB ( ) ;

	} ;
