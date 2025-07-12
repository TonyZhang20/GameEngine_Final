//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef MAN_BASE_H
#define MAN_BASE_H
#include "Manager_DLLInterface.h"
#include "ListBase.h"
#include "Iterator.h"

namespace Azul
{
	class ManBase
	{
	protected:
		//----------------------------------------------------------------------
		// Constructor
		//----------------------------------------------------------------------
		MANAGER_LIBRARY_API ManBase(ListBase *poActive, ListBase *poReserve, int InitialNumReserved = 5, int DeltaGrow = 2);
		MANAGER_LIBRARY_API virtual ~ManBase();

		//----------------------------------------------------------------------
		// Base methods - called in Derived class but lives in Base
		//----------------------------------------------------------------------
		MANAGER_LIBRARY_API void baseSetReserve(int reserveNum, int reserveGrow);

		MANAGER_LIBRARY_API DLink *baseAddToFront();
		MANAGER_LIBRARY_API DLink *baseAddToEnd();

		MANAGER_LIBRARY_API Iterator *baseGetActiveIterator();
		MANAGER_LIBRARY_API Iterator *baseGetReserveIterator();

		MANAGER_LIBRARY_API DLink *baseFind(DLink *pNodeTarget);

		MANAGER_LIBRARY_API void baseRemove(DLink *pNodeBase);

		MANAGER_LIBRARY_API void baseDump();

		//----------------------------------------------------------------------
		// Abstract methods - the "contract" Derived class must implement
		//----------------------------------------------------------------------
		MANAGER_LIBRARY_API virtual DLink *derivedCreateNode() = 0;

		//----------------------------------------------------------------------
		// Protected methods - helpers
		//----------------------------------------------------------------------
		MANAGER_LIBRARY_API void proFillReservedPool(int count);

		//----------------------------------------------------------------------
		// Data:
		//----------------------------------------------------------------------
		ListBase *poActive;
		ListBase *poReserve;

		int mDeltaGrow;
		int mTotalNumNodes;
		int mNumReserved;
		int mNumActive;

	};
}

#endif

//--- End of File ---
