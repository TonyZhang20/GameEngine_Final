//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateDevice.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateDevice::StateDevice()
		:poD3DDevice {nullptr}
	{
	}

	StateDevice::~StateDevice()
	{
		SafeRelease(this->poD3DDevice);
		this->poD3DDevice = nullptr;
	}

}

// --- End of File ---
