//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef	DLINK_ITERATOR_H
#define	DLINK_ITERATOR_H

#include "Manager_DLLInterface.h"
#include "Iterator.h"

namespace Azul
{
	class DLinkIterator : public Iterator
	{
	public:
		MANAGER_LIBRARY_API DLinkIterator();

		MANAGER_LIBRARY_API virtual DLink *Next() override;
		MANAGER_LIBRARY_API virtual bool IsDone() override;
		MANAGER_LIBRARY_API virtual DLink *First() override;
		MANAGER_LIBRARY_API virtual DLink *Curr() override;

		MANAGER_LIBRARY_API void Reset(DLink *pHead);

	private:
		void privClear();

	public:
		DLink *pHead;
		DLink *pCurr;
		bool bDone;
	};
}

#endif

// --- End of File ---

