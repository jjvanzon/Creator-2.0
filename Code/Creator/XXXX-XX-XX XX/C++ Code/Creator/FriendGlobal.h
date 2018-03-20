//
//	Creator . Friend Global
//
//		Header File
//
//		Author: Jan-Joost van Zon
//		Date: Tuesday, August 2, 2005
//
// -----
//
//	Comment:
//
//		Can't seem to declare global variables.
//
// -----

// Includes

	#include "stdafx.h"

// Defines

	#define VK_A 0x41 // A key code
	#define VK_B 0x42 // B key code
	#define VK_C 0x43 // C key code
	#define VK_D 0x44 // D key code
	#define VK_E 0x45 // E key code
	#define VK_F 0x46 // F key code
	#define VK_G 0x47 // G key code
	#define VK_H 0x48 // H key code
	#define VK_I 0x49 // I key code
	#define VK_J 0x4A // J key code
	#define VK_K 0x4B // K key code
	#define VK_L 0x4C // L key code
	#define VK_M 0x4D // M key code
	#define VK_N 0x4E // N key code
	#define VK_O 0x4F // O key code
	#define VK_P 0x50 // P key code
	#define VK_Q 0x51 // Q key code
	#define VK_R 0x52 // R key code
	#define VK_S 0x53 // S key code
	#define VK_T 0x54 // T key code
	#define VK_U 0x55 // U key code
	#define VK_V 0x56 // V key code
	#define VK_W 0x57 // W key code
	#define VK_X 0x58 // X key code
	#define VK_Y 0x59 // Y key code
	#define VK_Z 0x5A // Z key code

// Properties

	int LargeSpaceSize ( ) ;
	CString LargeSpace ( ) ;
	CString ApplicationName ( ) ;
	CString Version ( ) ;
	CString RegistryLocation ( ) ;
	CString CreatorProductionSourceCodeFilePath ( ) ;
	CString CreatorDevelopmentSourceCodeFilePath ( ) ;
	CString TreeControlProductionCreatorCodeFilePath ( ) ;
	CString GetRegistryValue ( CString aValueName ) ;

// Methods

	BOOL IndexValid ( long aIndex , long aDimension ) ;

	// CString* LoadString ( CString aFilePath ) ;
	// void SaveString ( CString* aText , CString aFilePath ) ;

// Miscellaneous

	CString GetLastErrorDescription ( DWORD aLastErrorDoubleWord ) ;
