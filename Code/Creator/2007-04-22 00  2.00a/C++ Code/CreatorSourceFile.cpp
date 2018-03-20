//
//	Creator . Creator Source File
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: ~ Friday, March 30, 2007 - Saturday, April 21, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "Creator.h"
	#include "CreatorSourceFile.h"

	#include "DeclareClasses.h"

// Microsoft Generated Code

	#ifdef _DEBUG
	#define new DEBUG_NEW
	#undef THIS_FILE
	static char THIS_FILE[] = __FILE__;
	#endif

	/////////////////////////////////////////////////////////////////////////////
	// CCreatorSourceFile

	IMPLEMENT_DYNCREATE(CCreatorSourceFile, CFormView)


	void CCreatorSourceFile::DoDataExchange(CDataExchange* pDX)
	{
		CFormView::DoDataExchange(pDX);
		//{{AFX_DATA_MAP(CCreatorSourceFile)
		DDX_Control(pDX, IDC_TEXTBOX, TextBox);
		//}}AFX_DATA_MAP
	}

	BEGIN_MESSAGE_MAP(CCreatorSourceFile, CFormView)
		//{{AFX_MSG_MAP(CCreatorSourceFile)
		ON_EN_CHANGE(IDC_TEXTBOX, OnTextBoxChanged)
		ON_BN_CLICKED(IDC_PARSEBUTTON, OnParseButtonClicked)
		ON_BN_CLICKED(IDC_REPLACECREATORBUTTON, OnReplaceCreatorButtonClicked)
		ON_BN_CLICKED(IDC_SHOWMESSAGESBUTTON, OnShowMessagesButtonClicked)
		ON_BN_CLICKED(IDC_NOMESSAGESBUTTON, OnNoMessagesButtonClicked)
		//}}AFX_MSG_MAP
	END_MESSAGE_MAP()

	/////////////////////////////////////////////////////////////////////////////
	// CCreatorSourceFile diagnostics

	#ifdef _DEBUG
	void CCreatorSourceFile::AssertValid() const
	{
		CFormView::AssertValid();
	}

	void CCreatorSourceFile::Dump(CDumpContext& dc) const
	{
		CFormView::Dump(dc);
	}
	#endif //_DEBUG

	/////////////////////////////////////////////////////////////////////////////
	// CCreatorSourceFile message handlers
	/////////////////////////////////////////////////////////////////////////////
	// CCreatorSourceFileDoc

	IMPLEMENT_DYNCREATE(CCreatorSourceFileDoc, CDocument)

	BEGIN_MESSAGE_MAP(CCreatorSourceFileDoc, CDocument)
		//{{AFX_MSG_MAP(CCreatorSourceFileDoc)
			// NOTE - the ClassWizard will add and remove mapping macros here.
		//}}AFX_MSG_MAP
	END_MESSAGE_MAP()

	/////////////////////////////////////////////////////////////////////////////
	// CCreatorSourceFileDoc diagnostics

	#ifdef _DEBUG
	void CCreatorSourceFileDoc::AssertValid() const
	{
		CDocument::AssertValid();
	}

	void CCreatorSourceFileDoc::Dump(CDumpContext& dc) const
	{
		CDocument::Dump(dc);
	}
	#endif //_DEBUG

	/////////////////////////////////////////////////////////////////////////////
	// CCreatorSourceFileDoc serialization


// Classes

	// Document
		
		// Constructor & Destructor

			CCreatorSourceFileDoc :: CCreatorSourceFileDoc ( ) {
				Creator = new gggCCreator ;
				CString tCreatorProductionSourceCodeFilePath ;
				tCreatorProductionSourceCodeFilePath = CreatorProductionSourceCodeFilePath ( ) ;
				if ( FileExists ( tCreatorProductionSourceCodeFilePath ) == FALSE ) {
					MessageBox ( 0 , "Creator Production Source Code File not found. Adapt registry setting HKEY_LOCAL_MACHINE\\SOFTWARE\\Jan-Joost van Zon\\Creator\\2007-02-25 XX  2.0X\\CreatorProductionSourceCodeFilePath" , ApplicationName ( ) , 0 ) ;
				}
				Creator -> Load ( tCreatorProductionSourceCodeFilePath ) ;
				Parser = new CParser ;
				Parser -> Creator = Creator ;
			}

			CCreatorSourceFileDoc :: ~CCreatorSourceFileDoc ( ) {
				delete Parser ;
				delete Creator ;
			}
				
		// Public
			
			// Methods
				
				void CCreatorSourceFileDoc :: Load ( CString aFilePath ) {
					CString* tString ;
					tString = LoadString ( aFilePath ) ;
					Code = *tString ;
					delete tString ; // !!! Shame I need to copy the string and then delete it. That's because Code is not a poinetr.
				} ;

				void CCreatorSourceFileDoc :: Save ( CString aFilePath ) {
					CString* tString ;
					tString = &Code ;
					SaveString ( tString , aFilePath ) ;
				} ;

		// Base Class Event Procedures

			BOOL CCreatorSourceFileDoc :: OnNewDocument ( ) {
				if ( !CDocument :: OnNewDocument ( ) ) {
					return FALSE;
				}
				Load ( CreatorDevelopmentSourceCodeFilePath ( ) ) ;
				return TRUE;
			}

			BOOL CCreatorSourceFileDoc :: OnOpenDocument (LPCTSTR lpszPathName) {
				if ( ! CDocument :: OnOpenDocument ( lpszPathName ) ) {
					return FALSE ;
				}
				Load ( lpszPathName ) ;
				return TRUE ;
			}

			BOOL CCreatorSourceFileDoc :: OnSaveDocument ( LPCTSTR lpszPathName ) {
				Save ( lpszPathName ) ;
				// return CDocument :: OnSaveDocument ( lpszPathName ) ;
				return TRUE ;
			}

	// View

		// Constructor & Destructor

			CCreatorSourceFile :: CCreatorSourceFile ( ) : CFormView ( CCreatorSourceFile :: IDD ) {
				//{{AFX_DATA_INIT(CCreatorSourceFile)
				//}}AFX_DATA_INIT
				Ctrl = FALSE ;
				Shift = FALSE ;
			}

			CCreatorSourceFile :: ~CCreatorSourceFile ( ) {
			}
				
		// Private Properties

			CCreatorSourceFileDoc* CCreatorSourceFile :: Document ( ) {
				return ( CCreatorSourceFileDoc* ) this -> GetDocument ( ) ;
			} ;

		// Private Methods

			void CCreatorSourceFile :: InsertText ( CString aText ) { 
				// Declarations
					CString tString ;
					int tSelectionStart ;
					int tSelectionEnd ;
				// Get Text and Selection Positions
					TextBox . GetWindowText ( tString ) ;
					TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
				// Other Functionality
					if ( tSelectionStart == tSelectionEnd ) {
						CString tBegin ;
						CString tEnd ;
						tBegin = tString . Left ( tSelectionStart ) ;
						tEnd = tString . Right ( tString . GetLength ( ) - tSelectionStart ) ;
						tString = tBegin + aText + tEnd ;
						TextBox . SetWindowText ( tString ) ;
						tSelectionStart += aText . GetLength ( ) ;
						TextBox . SetSel ( tSelectionStart , tSelectionStart ) ;
					}
			}

			BOOL CCreatorSourceFile :: DeleteLargeSpace ( ) {
				// Declarations
					CString tString ;
					int tSelectionStart ;
					int tSelectionEnd ;
					int tCharacterPosition ;
					int tSpacesRemoved = 0 ;
					CString tCharacter ;
					CString tBegin ;
					CString tEnd ;
					BOOL tReturnValue = FALSE ;
				// Get Text and Selection Positions
					TextBox . GetWindowText ( tString ) ;
					TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
				// Other Functionality
					if ( tSelectionStart == tSelectionEnd ) { // There shouldn't be text selected
						// Set character position to just before the cursor
							tCharacterPosition = tSelectionStart - 1 ; 
						// Get this character
							if ( tCharacterPosition >= 0 ) {
								tCharacter = tString . Mid ( tCharacterPosition , 1 ) ;
							}
						// Loop Through Characters Backwards
							while ( tCharacterPosition >= 0 && tCharacter == " " && tSpacesRemoved < LargeSpaceSize ( ) ) {
								// Get part of text before character to remove
									tBegin = tString . Left ( tCharacterPosition ) ; 
								// Get part of text after character to remove
									tEnd = tString . Right ( tString . GetLength ( ) - tCharacterPosition - 1 ) ; 
								// Concatinate text before and after character to remove
									tString = tBegin + tEnd ; 
								// Set Text Box's new text
									TextBox . SetWindowText ( tString ) ; 
								// Increment spaces removed
									tSpacesRemoved += 1 ;
								// Decrement cursor position
									tSelectionStart -= 1 ; 
									if ( tSelectionStart >= 0 ) {
										TextBox . SetSel ( tSelectionStart , tSelectionStart ) ;
									}
								// Set success to True
									tReturnValue = TRUE ; 
								// Set character position to just before the cursor
									tCharacterPosition -= 1 ;
								// Get this character
									if ( tCharacterPosition >= 0 ) {
										tCharacter = tString . Mid ( tCharacterPosition , 1 ) ;
									}
							}
					}
				if ( tReturnValue == TRUE ) {
					// tReturnValue == TRUE means there were spaces removed.
						// Quick & Dirty :
							// Add a space again, because this procedure was called in response to the backspace key being pressed
							// and I don't know how to stop the backspace key from being executed.
								tString = tBegin + " " + tEnd ;
								TextBox . SetWindowText ( tString ) ;
								tSelectionStart += 1 ;
								if ( tSelectionStart >= 0 ) {
									TextBox . SetSel ( tSelectionStart , tSelectionStart ) ;
								}
				}
				return tReturnValue ;
			};

		// Event Procedures
			
			// Text Box

				void CCreatorSourceFile::OnTextBoxChanged() {
					// Assign Text to Document
						TextBox . GetWindowText ( Document ( ) -> Code ) ;
				}

			// Buttons

				void CCreatorSourceFile :: OnParseButtonClicked ( )  {
					CString tString ;
					TextBox . GetWindowText ( tString ) ;
					if ( Document ( ) -> Parser -> ShowMessages == TRUE ) {
						MessageBox ( ( LPCTSTR ) tString, ApplicationName ( ) + " - Parse" ) ;
					}
					Document ( ) -> Parser -> Text = tString;
					// tDocument -> Parser -> ShowMessages = TRUE ; 
					Document ( ) -> Parser -> Parse ( ) ;
				}

				void CCreatorSourceFile :: OnReplaceCreatorButtonClicked ( ) {
					Document ( ) -> Parser -> Creator -> QuickAndDirtyReplaceCreator ( Document ( ) -> Parser -> Structure -> cccRelatedLists ( ) -> Item ( "Classes" ) -> cccItem ( 0 ) ) ;
					Document ( ) -> Parser -> Structure = 0 ;
				}

				void CCreatorSourceFile :: OnShowMessagesButtonClicked ( ) {
					Document ( ) -> Parser -> ShowMessages = TRUE ; 
				}

				void CCreatorSourceFile :: OnNoMessagesButtonClicked ( ) {
					Document ( ) -> Parser -> ShowMessages = FALSE ; 
				}

		// Base Class Event Procedures

			BOOL CCreatorSourceFile::PreTranslateMessage ( MSG* pMsg ) {
				// Control special keys
					switch ( pMsg -> message ) {
						case WM_KEYDOWN :
							switch ( pMsg -> wParam ) {
								case 17 : // Ctrl
									Ctrl = TRUE ;
									break ;
								case 16 : // Shift
									Shift = TRUE ;
							}
							break ;
						case WM_KEYUP :
							switch ( pMsg -> wParam ) {
								case 17 : // Ctrl
									Ctrl = FALSE ;
									break ;
								case 16 : // Shift
									Shift = FALSE ;
							}
							break ;
					}
				// Control TextBox keys
					if ( GetFocus ( ) == ( CWnd* ) & TextBox ) { 
						if ( pMsg -> message == WM_KEYDOWN ) { 
							// Ctrl
								if ( Ctrl == TRUE ) {
									switch ( pMsg -> wParam ) {
										case VK_C :
											TextBox . Copy ( ) ;
											return FALSE ;
										case VK_V :
											TextBox . Paste ( ) ;
											return FALSE ;
										case VK_X :
											TextBox . Cut ( ) ;
											return FALSE ;
									}
								}
							// No control keys
								switch ( pMsg -> wParam ) {
									case VK_SPACE :
										if ( Ctrl == FALSE && Shift == FALSE ) {
											// InsertText ( " " ) ; // Insert only one space instead, because returning false next does not stop the space key from adding a space
											InsertText ( LargeSpace ( ) . Left ( LargeSpace ( ) . GetLength ( ) - 1 ) ) ; // Insert one space less instead, because returning false next does not stop the space key from adding a space
											return FALSE ;
										}
										break ;
									case VK_BACK :
										if ( DeleteLargeSpace ( ) == TRUE ) {
											return FALSE ;
											break ;
										} ;
								}
						}
					} 
				return CFormView::PreTranslateMessage(pMsg);
			}

			void CCreatorSourceFile::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
			{
				CCreatorSourceFileDoc* tDocument ;
				tDocument = ( CCreatorSourceFileDoc* ) this -> GetDocument ( ) ;
				TextBox . SetWindowText ( tDocument -> Code ) ;
			}
