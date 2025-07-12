//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateSwapChain.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateSwapChain::StateSwapChain()
		:poD3DSwapChain {nullptr}
	{
	}


	StateSwapChain::~StateSwapChain()
	{
		SafeRelease(this->poD3DSwapChain);
		this->poD3DSwapChain = nullptr;
	}

}

// --- End of File ---
