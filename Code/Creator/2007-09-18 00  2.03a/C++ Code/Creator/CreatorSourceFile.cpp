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
	#include "CreatorApp.h"
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
	DDX_Control(pDX, IDC_SHOWMESSAGESBUTTON, ShowMessagesButton);
	DDX_Control(pDX, IDC_REPLACECREATORBUTTON, ReplaceCreatorButton);
	DDX_Control(pDX, IDC_PARSEBUTTON, ParseButton);
	DDX_Control(pDX, IDC_NOMESSAGESBUTTON, NoMessagesButton);
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
	ON_WM_PAINT()
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


// Classes

	// Document
		
		// Constructor & Destructor

			CCreatorSourceFileDoc :: CCreatorSourceFileDoc ( ) {
				Creator = new CCreator ;
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
				// Remeber Scroll Position
					RememberScrollPosition ( ) ;
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
				// Restore Scroll Position
					RestoreScrollPosition ( ) ;
			}

			BOOL CCreatorSourceFile :: DeleteLargeSpace ( ) {
				// Remeber Scroll Position
					RememberScrollPosition ( ) ;
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
				// Restore Scroll Position
					RestoreScrollPosition ( ) ;
				return tReturnValue ;
			};

		// Retaining Scroll Position ( Unbelievably Complicated )

			void CCreatorSourceFile :: RememberScrollPosition ( ) {
				// Preparation
					// Get Text Box Position
						LPRECT tClientRect = new RECT ;
						TextBox . GetClientRect ( tClientRect ) ;
					// Assume Line Height
						int tLineHeight = 13 ;
					// Calculate Visible Lines
						VisibleLinesInTextBox = ( tClientRect -> bottom + 1) / tLineHeight ;
				// Get Original Position
					// Declarations
						int tSelectionStart ;
						int tSelectionEnd ;
						CPoint tPoint ;
					// Get Caret Position
						TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
					// Get Character Position of Top Left Character
						tPoint . x = 0 ;
						tPoint . y = 0 ;
						int tTopLeftLineAndChar = TextBox . CharFromPos ( tPoint ) ;
					// Get Top Line
						int tTextBoxTopLineA = HIWORD ( tTopLeftLineAndChar ) ;
					// Calculate Bottom Line
						TextBoxBottomLineA = tTextBoxTopLineA + VisibleLinesInTextBox - 1 ;
			} ;

			void CCreatorSourceFile :: RestoreScrollPosition ( ) {
				// Get New Position
					// Declarations
						int tSelectionStart ;
						int tSelectionEnd ;
						CPoint tPoint ;
					// Get Caret Position
						TextBox . GetSel ( tSelectionStart , tSelectionEnd ) ;
					// Get Character Position of Top Left Character
						tPoint . x = 0 ;
						tPoint . y = 0 ;
						int tTopLeftLineAndCharB = TextBox . CharFromPos ( tPoint ) ;
					// Get Top Line
						int TextBoxTopLineB = HIWORD ( tTopLeftLineAndCharB ) ;
					// Calculate Bottom Line
						TextBoxBottomLineB = TextBoxTopLineB + VisibleLinesInTextBox - 1 ;
				// Scroll
					// If Text Box Bottom Line smaller than Expansion Bottom Line
						if ( TextBoxBottomLineB < TextBoxBottomLineA ) {
							// Tiny bug :
								// Somehow this 'if' is entered also when the expanded content just 
								// fits with the current scroll position, but then the tPositionsToScroll stays zero.
							// Calculate Positions To Scroll
								int tDesiredScrollPosition = TextBoxBottomLineA - VisibleLinesInTextBox + 1 ;
								int tCurrentScrollPosition = TextBox . GetScrollPos ( SB_VERT) ;
								int tPositionsToScroll = tDesiredScrollPosition - tCurrentScrollPosition + 1 ; // !!! Added + 1 compared to the method used in Tree Control . Expand
							// Scroll
								TextBox . LineScroll ( tPositionsToScroll ) ;
						}
			} ;


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
					Document ( ) -> Parser -> Parse ( ) ;
				}

				void CCreatorSourceFile :: OnReplaceCreatorButtonClicked ( ) {
					Document ( ) -> Parser -> Creator -> QuickAndDirtyReplaceCreator ( Document ( ) -> Parser -> Structure -> RelatedLists ( ) -> Item ( "Classes" ) -> Item ( 0 ) ) ;
					Document ( ) -> Parser -> Structure = 0 ;
				}

				void CCreatorSourceFile :: OnShowMessagesButtonClicked ( ) {
					Document ( ) -> Parser -> ShowMessages = TRUE ; 
				}

				void CCreatorSourceFile :: OnNoMessagesButtonClicked ( ) {
					Document ( ) -> Parser -> ShowMessages = FALSE ; 
				}

		// Base Class Event Procedures ( / Overrides )

			BOOL CCreatorSourceFile::PreTranslateMessage ( MSG* pMsg ) {
				// Control Special Keys
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
				// Control Text Box keys
					if ( GetFocus ( ) == ( CWnd* ) & TextBox ) { 
						if ( pMsg -> message == WM_KEYDOWN ) { 
							// Ctrl
								if ( Ctrl == TRUE ) {
									switch ( pMsg -> wParam ) {
										case VK_C :
											TextBox . Copy ( ) ;
											return TRUE ;
										case VK_V :
											TextBox . Paste ( ) ;
											return TRUE ;
										case VK_X :
											TextBox . Cut ( ) ;
											return TRUE ;
									}
								}
							// No control keys
								switch ( pMsg -> wParam ) {
									case VK_SPACE :
										if ( Ctrl == FALSE && Shift == FALSE ) {
											InsertText ( LargeSpace ( ) ) ; 
											return TRUE ;
										}
										break ;
									case VK_BACK :
										if ( DeleteLargeSpace ( ) == TRUE ) {
											return TRUE ;
											break ;
										} ;
								}
						}
					} 
				return CFormView::PreTranslateMessage(pMsg);
			}

			void CCreatorSourceFile::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)  {
				CCreatorSourceFileDoc* tDocument ;
				tDocument = ( CCreatorSourceFileDoc* ) this -> GetDocument ( ) ;
				TextBox . SetWindowText ( tDocument -> Code ) ;
			}

			void CCreatorSourceFile :: OnPaint ( ) {
				CPaintDC dc ( this ) ; // device context for painting
				RECT tRectange ;
				GetClientRect ( & tRectange ) ;
				TextBox . MoveWindow ( 0 , 0 , tRectange . right , tRectange . bottom - 28 ) ;
				NoMessagesButton . MoveWindow ( tRectange.right - 94 , tRectange.bottom - 24 , 90 , 20 ) ;
				ShowMessagesButton . MoveWindow ( tRectange.right - 188 , tRectange.bottom - 24 , 90 , 20 ) ;
				ReplaceCreatorButton . MoveWindow ( tRectange.right - 282 , tRectange.bottom - 24 , 90 , 20 ) ;
				ParseButton . MoveWindow ( tRectange.right - 376 , tRectange.bottom - 24 , 90 , 20 ) ;
			} ;

			void CCreatorSourceFile :: OnInitialUpdate()  {
				// Call Base
					CFormView :: OnInitialUpdate ( ) ;
				// Quick Fix : I use OnInitialUpdate, because I can't find anything that better represents OnLoad.
					TextBox . SetLimitText ( 4294967295 ) ;
			} ;
