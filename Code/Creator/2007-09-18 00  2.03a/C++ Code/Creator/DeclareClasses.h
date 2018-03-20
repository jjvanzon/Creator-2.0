//
//	Creator . Declare Classes
//
//		Author: Jan-Joost van Zon
//		Date: Wednesday, August 3, 2005 - Thursday, April 12, 2007
//
// -----

// Classes

	class FlatListInMemory ;
	class StackInMemory ;
	class HoleListInMemory ;

	class CStructure ;
	class CClass ;
	class CClasses ;
	class CClassAttributes ;
	class CClassAttribute ;
	class CRelatedClasses ;
	class CRelatedClass ;
	class CRelations ;
	class CRelation ;
	class CRelationClass ;
	class CItem ;
	class CItemAttributes ;
	class CItemAttribute ;
	class CRelatedItems ;
	class CRelatedItem ;
	class CRelatedLists ;
	class CRelatedList ;
	class CItemMethods ;
	class CItemMethod ;

	class gccCCreator ;
	class ggcCCreator ;
	class gggCCreator ;
	class CCreator ;

	class CParser ;

    class CFlatListOnDisk ;
	class CStackOnDisk ;
	class CHoleListOnDisk ;

    class CDiskStorageClass ;
	class CDiskStorageItemAttributes ;
	class CDiskStorageItemAttribute ;
	class CDiskStorageRelatedItems ;
	class CDiskStorageRelatedItem ;
	class CDiskStorageRelatedLists ;
	class CDiskStorageRelatedList ;

	class CItemOnDisk ;
	class CItemAttributesOnDisk ;
	class CItemAttributeOnDisk ;
	class CRelatedItemsOnDisk ;
	class CRelatedItemOnDisk ;
	class CRelatedListsOnDisk ;
	class CRelatedListOnDisk ;

// Header File References

	#include <afxtempl.h>
	#include "Windows.h"

	#include "FriendGlobal.h"
	#include "FileFunctions.h"

	#include "..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\FlatListInMemory.h"
	#include "..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\StackInMemory.h"
	#include "..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\HoleListInMemory.h"

	#include "cccCreator.h"
	#include "gccCreator.h"
	#include "ggcCreator.h"
	#include "gggCreator.h"
	#include "Creator.h"

	#include "Parser.h"

    #include "..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CFlatListOnDisk.h"
	#include "..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CStackOnDisk.h"
	#include "..\..\..\..\..\Storage\Basic Data Structures\2007-09-18 00  2.03a\CHoleListOnDisk.h"

    #include "CDiskStorageClass.h"
	#include "CDiskStorageItemAttributes.h"
	#include "CDiskStorageItemAttribute.h"
	#include "CDiskStorageRelatedItems.h"
	#include "CDiskStorageRelatedItem.h"
	#include "CDiskStorageRelatedLists.h"
	#include "CDiskStorageRelatedList.h"

	#include "CItemOnDisk.h"
	#include "CItemAttributesOnDisk.h"
	#include "CItemAttributeOnDisk.h"
	#include "CRelatedItemsOnDisk.h"
	#include "CRelatedItemOnDisk.h"
	#include "CRelatedListsOnDisk.h"
	#include "CRelatedListOnDisk.h"
