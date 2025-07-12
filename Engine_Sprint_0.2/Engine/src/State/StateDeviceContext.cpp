//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateDeviceContext.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateDeviceContext::StateDeviceContext()
		:poD3DDeviceContext {nullptr}
	{
	}


	StateDeviceContext::~StateDeviceContext()
	{
		SafeRelease(this->poD3DDeviceContext);
		this->poD3DDeviceContext = nullptr;
	}

}

// --- End of File ---
