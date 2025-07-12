//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#ifndef PCSTREE_ITERATOR_H
#define PCSTREE_ITERATOR_H

#include "PCSNode.h"
#include "PCSTreeIterator.h"
#include "PCSTree_DLLInterface.h"

namespace Azul
{
	class PCSTreeIterator
	{
	public:

		PCSTREE_LIBRARY_API PCSTreeIterator() = default;
		PCSTREE_LIBRARY_API PCSTreeIterator(const PCSTreeIterator &) = delete;
		PCSTREE_LIBRARY_API PCSTreeIterator &operator = (const PCSTreeIterator &) = delete;
		PCSTREE_LIBRARY_API virtual ~PCSTreeIterator() = default;

		PCSTREE_LIBRARY_API virtual PCSNode *First() = 0;
		PCSTREE_LIBRARY_API virtual PCSNode *Next() = 0;
		PCSTREE_LIBRARY_API virtual bool IsDone() = 0;
		PCSTREE_LIBRARY_API virtual PCSNode *Current() = 0;
	};
}

#endif

// ---  End of File ---------------
