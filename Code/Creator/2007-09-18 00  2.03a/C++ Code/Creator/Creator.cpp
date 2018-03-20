//
// Creator . Creator
//
//		Totally generic Creator loaded from code file.
//
//		Implementation File
//
//		Author: Jan-Joost van Zon
//		Date: Friday, May 4, 2007 - Friday, May 4, 2007
//
// -----

// Includes

	#include "stdafx.h"
	#include "DeclareClasses.h"

// Classes

	// C Creator

		// Constructor & Destructor
			
			CCreator :: CCreator ( ) {
				// Initialize Pointers
					YourStructure = 0 ;
				// Create Objects
					gggMyCreator = new gggCCreator ;
					gggMyData = new CItem ;
				// Other Initialization
 					gggMyData -> GenericClass ( gggMyCreator -> gggYourStructure ) ;
					Load ( ) ;
			} ;

			CCreator :: ~CCreator ( ) {
				// Unbuild ( ) ; // Unload?
				delete gggMyData ;
				delete gggMyCreator ;
			} ;

		// Private
			
			// Methods
				
				void CCreator :: Load ( ) {
					// Get Path
						CString tCreatorProductionSourceCodeFilePath ;
						tCreatorProductionSourceCodeFilePath = CreatorProductionSourceCodeFilePath ( ) ;
						if ( FileExists ( tCreatorProductionSourceCodeFilePath ) == FALSE ) {
							MessageBox ( 0 , "Creator Production Source Code File not found. Please adapt the registry setting HKEY_LOCAL_MACHINE\\" + RegistryLocation ( ) + "\\CreatorProductionSourceCodeFilePath" , ApplicationName ( ) , 0 ) ;
						}
					// Load Text File
						CString* tString ;
						tString = LoadString ( tCreatorProductionSourceCodeFilePath ) ;
					// Parse
						CParser* tParser ;
						tParser = new CParser ;
						tParser -> gggCreator = gggMyCreator ;
						// Shame I need to copy the string
							tParser -> Text = *tString ;
							delete tString ; 
						tParser -> Parse ( ) ;
					// Parser Structure is My Data
					    gggMyData = tParser -> Structure ;
					// Delete Parser
						tParser -> Structure = 0 ; // Release Parser's ownership of the Structure it produced
						delete tParser ;
					// Assign Your Structure
						YourStructure = gggMyData -> RelatedLists ( ) -> Item ( "Classes" ) -> Item ( 0 ) ;
					// PARSE AGAIN!
						// TOTALLY QUICK & DIRTY, I DON'T EVEN KNOW WHAT HALF THE CODE ABOVE IS FOR!
						// Get Path
							// CString tCreatorProductionSourceCodeFilePath ;
							tCreatorProductionSourceCodeFilePath = CreatorProductionSourceCodeFilePath ( ) ;
							if ( FileExists ( tCreatorProductionSourceCodeFilePath ) == FALSE ) {
								MessageBox ( 0 , "Creator Production Source Code File not found. Please adapt the registry setting HKEY_LOCAL_MACHINE\\" + RegistryLocation ( ) + "\\CreatorProductionSourceCodeFilePath" , ApplicationName ( ) , 0 ) ;
							}
						// Load Text File
							// CString* tString ;
							tString = LoadString ( tCreatorProductionSourceCodeFilePath ) ;
						// Parse
							// CParser* tParser ;
							tParser = new CParser ;
							tParser -> Creator = this ;
							// Shame I need to copy the string
								tParser -> Text = *tString ;
								delete tString ; 
							tParser -> Parse ( ) ;
						// Parser Structure is My Data
							gggMyData = tParser -> Structure ;
						// Delete Parser
							tParser -> Structure = 0 ; // Release Parser's ownership of the Structure it produced
							delete tParser ;
						// Assign Your Structure
							YourStructure = gggMyData -> RelatedLists ( ) -> Item ( "Classes" ) -> Item ( 0 ) ;
				} ;

				void CCreator :: QuickAndDirtyReplaceCreator ( CItem* aStructureClass ) {
					YourStructure = aStructureClass ;
				} ;

				CItem* CCreator :: LoadStructure ( CString aFilePath ) {
					// Load Text File
						CString* tString ;
						tString = LoadString ( aFilePath ) ;
					// Get Folder Of File Path
						int tCharacterIndex = aFilePath . ReverseFind ( '\\' ) ;
						CString tFolder ;
						if ( tCharacterIndex != -1 ) {
							tFolder = aFilePath . Left ( tCharacterIndex ) ;
						}
					// Parse
						// Create Parser
							CParser* tParser = new CParser ;
						// Assign Creator to Parser
							tParser -> Creator = this ;
						// Assign Text to Parser
							// Shame I need to copy the string
								tParser -> Text = *tString ;
								delete tString ; 
						// Assign Folder to Parser
							tParser -> Folder = tFolder ;
						// Parse 
							tParser -> Parse ( ) ;
					// Parser Structure is what I will return
						CItem* tReturnValue ;
						tReturnValue = tParser -> Structure ;
					// Assign Path to Structure Structure
						CItemAttribute* tFolderItemAttribute = tReturnValue -> ItemAttributes ( ) -> Item ( "Folder" ) ;
						if ( tFolderItemAttribute != 0 ) {
							tFolderItemAttribute -> Value ( tFolder ) ;
						}
					// Compile Methods
						tParser -> CompileMethods ( ) ; // Quick & Dirty place to call it. I call it here, because I need the folder to be assigned first.
					// Delete Parser
						tParser -> Structure = 0 ; // Release Parser's ownership of the Structure it produced
						delete tParser ;
					// Return Structure
						return tReturnValue ;
				} ;
