//
//	Sigma . Data . Lists and Trees . Paper
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Tuesday, August 2, 2005 - Tuesday, August 3, 2005
//
// -----

// Includes

	#include "stdafx.h"

// Class

	class Paper {

		// Public

			public:

				// Variables

					long Indents;
					BOOL TabsAreSpaces;
					BOOL UseTabs;
					BOOL UseEnters;

				// Properties

					long Lines ( );
					void Lines ( long aValue );

					CString *Line ( long aIndex );
					void Line ( long aIndex, CString *aValue );

					long LineIndents ( long aIndex );
					void LineIndents ( long aIndex, long aValue );

					CString *LastLine ( );
					void LastLine ( CString *aValue );

					CString *FromattedLine ( long aIndex );
					
					CString *Contents ( );

				// Methods

					void Clear ( );
					void Add ( CString *aString );
					void AddLine ( CString *aString );
					void Indent ( );
					void Outdent ( );
					void Enter ( );
					void Save ( CString *aFilePath );
					void AddPaper ( Paper *aPaper );
					// AddTemplate ( Template *aTemplate );
					long SearchLine ( CString *aLine );
					
					void C ( );
					void A ( CString *aString );
					void L ( CString *aString );
					void I ( );
					void O ( );
					void E ( );

				// Constructor and Destructor

					Paper ( );
					~Paper ( );

		// Private

			private:

				// Variables

					// Property Storage

						long sLines;
						CStringArray sLine;
						CArray<long, long> sLineIndents;
		
	};