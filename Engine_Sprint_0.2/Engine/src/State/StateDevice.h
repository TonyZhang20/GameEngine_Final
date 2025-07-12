//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_DEVICE_H
#define STATE_DEVICE_H

#include <d3d11.h>

namespace Azul
{
	class StateDevice
	{
	public:
		StateDevice();
		StateDevice(const StateDevice &) = delete;
		StateDevice &operator = (const StateDevice &) = delete;
		virtual ~StateDevice();


		ID3D11Device *poD3DDevice;
	};

}
#endif 

// --- End of File ---
