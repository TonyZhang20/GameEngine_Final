//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_ADAPTER_OUTPUT_H
#define STATE_ADAPTER_OUTPUT_H

#include <d3d11.h>

namespace Azul
{
	class StateAdapterOutput
	{
	public:
		StateAdapterOutput();
		StateAdapterOutput(const StateAdapterOutput &) = delete;
		StateAdapterOutput &operator = (const StateAdapterOutput &) = delete;
		virtual ~StateAdapterOutput();


		IDXGIOutput *poDXGAdapterOutput;
	};

}
#endif 

// --- End of File ---
