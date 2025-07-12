//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "StateFactory.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateFactory::StateFactory()
		:poDXGFactory {nullptr}
	{
	}

	StateFactory::~StateFactory()
	{
		SafeRelease(this->poDXGFactory);
		this->poDXGFactory = nullptr;
	}

}

// --- End of File ---
