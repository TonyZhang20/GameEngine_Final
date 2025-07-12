//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "StateDebug.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateDebug::StateDebug()
		:poD3DDebug {nullptr}
	{
	}

	StateDebug::~StateDebug()
	{
		SafeRelease(this->poD3DDebug);
		this->poD3DDebug = nullptr;
	}

}

// --- End of File ---
