//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "StateAdapter.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateAdapter::StateAdapter()
		:poDXGAdapter {nullptr}
	{
	}

	StateAdapter::~StateAdapter()
	{
		SafeRelease(this->poDXGAdapter);
		this->poDXGAdapter = nullptr;
	}

}

// --- End of File ---
