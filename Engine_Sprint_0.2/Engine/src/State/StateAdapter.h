//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_ADAPTER_H
#define STATE_ADAPTER_H

#include <d3d11.h>

namespace Azul
{
	class StateAdapter
	{
	public:
		StateAdapter();
		StateAdapter(const StateAdapter &) = delete;
		StateAdapter &operator = (const StateAdapter &) = delete;
		virtual ~StateAdapter();

		IDXGIAdapter *poDXGAdapter;
	};

}
#endif 

// --- End of File ---
