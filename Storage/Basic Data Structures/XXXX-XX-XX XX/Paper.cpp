//
//	Sigma . Data . Lists and Trees . Paper
//
//		Source Code File
//
//		Author: Jan-Joost van Zon
//		Date: Tuesday, August 2, 2005 - Wednesday, August 3, 2005
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Public

	// Properties

		long Paper::Lines ( ) {
			return sLines;
		};
		void Paper::Lines ( long aValue ) {
			if ( aValue < 0 ) aValue = 0;
			if ( sLines != aValue ) {
				long i;
				for ( i = sLines - 1 ; i >= aValue ; i-- ) {
					delete &sLine.GetAt ( i );
				}
				sLines = aValue;
				sLine.SetSize ( aValue );
				sLineIndents.SetSize ( aValue );
			}
		};

		CString *Paper::Line ( long aIndex ) {
			if ( IndexValid ( aIndex, Lines() ) ) return &sLine.GetAt ( aIndex ); else return NULL;
		};
		void Paper::Line (long aIndex, CString *aValue) {
			if ( IndexValid ( aIndex, Lines() ) ) sLine.SetAt ( aIndex, *aValue );
		};

		long Paper::LineIndents (long aIndex) {
			if ( IndexValid ( aIndex, Lines() ) ) return sLineIndents.GetAt ( aIndex ); else return 0;
		};
		void Paper::LineIndents (long aIndex, long aValue) {
			if ( IndexValid ( aIndex, Lines() ) ) sLineIndents.SetAt ( aIndex, aValue );
		};

		CString *Paper::LastLine () {
			return Line ( Lines - 1 );
		};
		void Paper::LastLine (CString *aValue) {
			Line ( Lines - 1, aValue );
		};

		CString *Paper::FromattedLine (long aIndex) {
			long i;
			CString *tFormattedLine = new CString;
			if ( IndexValid( aIndex, Lines() ) ) {
				if ( UseTabs ) {
					if ( TabsAreSpaces ) {
						for ( i = 1 ; i <= LineIndents ( aIndex ) ; i++ ) {
							*tFormattedLine = *tFormattedLine + "    ";
						}
					}
					else {
						for ( i = 1 ; i <= LineIndents ( aIndex ) ; i++) {
							*tFormattedLine = *tFormattedLine + "\t";
						}
					}
				}
				*tFormattedLine = *tFormattedLine + (char)Line ( aIndex );
			}
			return tFormattedLine;
		};
		
		CString *Paper::Contents () {
			long i;
			CString *tContents = new CString;
			for ( i = 0 ; i <= Lines - 2 ; i++ ) {
				*tContents = *tContents + (char)FromattedLine ( i );
				if ( UseEnters ) *tContents = *tContents + "\n";
			}
			*tContents = *tContents + (char)FromattedLine ( Lines() - 1 );
			return tContents;
		};

	// Methods

		void Paper::Clear () {
			Lines ( 0 );
			Indents = 0;
		};
		
		void Paper::Add (CString *aString) {
			LastLine ( & ( *LastLine ( ) + (char)aString ) );
		};
		
		void Paper::AddLine (CString *aString) {
			Lines ( Lines ( ) + 1 );
			LineIndents ( Lines ( ) - 1, Indents );
			LastLine ( aString );
		};
		
		void Paper::Indent () {
			Indents = Indents + 1;
		};
		
		void Paper::Outdent () {
			Indents = Indents - 1;
		};
		
		void Paper::Enter () {
			AddLine ( new CString("") );
		};
		
		void Paper::Save (CString *aFilePath) {
			if ( (char)aFilePath == *("") ) goto Exit;
			HANDLE tFileHandle;
			DeleteFile ( (const char *)aFilePath );
			tFileHandle = CreateFile ( (const char*)aFilePath, GENERIC_WRITE, 0, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL );
			WriteFileEx ( tFileHandle, (const void *)(char)aFilePath, 10, NULL, NULL);
			CloseHandle (tFileHandle);
		Exit: ;
		};
		
		void Paper::AddPaper (Paper *aPaper) {
			if (aPaper == 0) goto Exit;
			long i;
			for ( i = 0 ; i <= aPaper->Lines - 1 ; i++ ) {
				Lines ( Lines () + 1);
				LineIndents ( Lines () - 1, Indents + aPaper->LineIndents( i ) );
				Line ( Lines () - 1, (CString*)(char)aPaper->Line( i ) ); // !!! Will it make a copy? (char)aPaper->Line(i) ?
			}
			// Indents = Indents + aPaper->LineIndents ( aPaper->Lines() -1 );
			Indents = Indents + aPaper->Indents;
		Exit: ;
		};
		
		// AddTemplate (Template *aTemplate) {
		// };
		
		long Paper::SearchLine (CString *aLine) {
			long i;
			for ( i = 0 ; i <= Lines () - 1 ; i++ ) {
				if ( (char) Line ( i ) == (char) aLine ) return i;
			}
			return -1;
		};

		/*            
            Public Sub RemoveTrailingEnters()
                'On Error Resume Next
                Do While Trim(LastLine = "") And Lines > 0
                    Lines = Lines - 1
                Loop
            End Sub

            Public Function SearchLineThatContains(aString As String) As Long
                'On Error Resume Next
                Dim i As Long
                SearchLineThatContains = -1
                For i = 0 To Lines - 1
                    If InStr(1, JLine(i), aString) > 0 Then
                        SearchLineThatContains = i
                        Exit Function
                    End If
                Next i
            End Function

		*/

		void Paper::C () {
			Clear ();
		};
		
		void Paper::A (CString *aString) {
			Add (aString);
		};
		
		void Paper::L (CString *aString) {
			AddLine (aString);
		};
		
		void Paper::I () {
			Indent ();
		};
		
		void Paper::O () {
			Outdent ();
		};
		
		void Paper::E () {
			Enter ();
		};

	// Constructor

		Paper::Paper() {
			TabsAreSpaces = TRUE;
			UseTabs = TRUE;
			UseEnters = TRUE;
		};

		Paper::~Paper() {
			Lines ( 0 );
		};