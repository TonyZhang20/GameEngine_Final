//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_DEBUG_H
#define STATE_DEBUG_H

#include <d3d11.h>

namespace Azul
{
	class StateDebug
	{
	public:
		StateDebug();
		StateDebug(const StateDebug &) = delete;
		StateDebug &operator = (const StateDebug &) = delete;
		virtual ~StateDebug();

		ID3D11Debug *poD3DDebug;
	};

}
#endif 

// --- End of File ---
