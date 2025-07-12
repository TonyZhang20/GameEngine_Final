//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "StateAdapterOutput.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateAdapterOutput::StateAdapterOutput()
		:poDXGAdapterOutput {nullptr}
	{
	}

	StateAdapterOutput::~StateAdapterOutput()
	{
		SafeRelease(this->poDXGAdapterOutput);
		this->poDXGAdapterOutput = nullptr;
	}

}

// --- End of File ---
