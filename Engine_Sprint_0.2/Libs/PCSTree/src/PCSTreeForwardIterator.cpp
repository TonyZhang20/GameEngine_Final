//-----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------- 

#include "PCSTreeForwardIterator.h"

namespace Azul
{
	PCSTreeForwardIterator::PCSTreeForwardIterator(PCSNode *rootNode)
	{
		this->root = rootNode;
	}

	PCSNode *PCSTreeForwardIterator::First()
	{
		current = this->root;
		return this->root;
	}

	PCSNode *PCSTreeForwardIterator::Next()
	{
		current = current->GetForward();
		return current;
	}

	bool PCSTreeForwardIterator::IsDone()
	{
		return current == nullptr;
	}

	PCSNode *PCSTreeForwardIterator::Current()
	{
		return  current;
	}

}

// ---  End of File ---
