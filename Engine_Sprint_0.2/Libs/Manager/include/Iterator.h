//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef ITERATOR_H
#define ITERATOR_H

#include "Manager_DLLInterface.h"
#include "DLink.h"

namespace Azul
{
	class Iterator
	{
	public:
		MANAGER_LIBRARY_API virtual DLink *Next() = 0;
		MANAGER_LIBRARY_API virtual bool IsDone() = 0;
		MANAGER_LIBRARY_API virtual DLink *First() = 0;
		MANAGER_LIBRARY_API virtual DLink *Curr() = 0;
	};
}

#endif

// --- End of File ---
