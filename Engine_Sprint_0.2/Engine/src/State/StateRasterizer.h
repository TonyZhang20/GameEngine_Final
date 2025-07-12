//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_RASTERIZER_H
#define STATE_RASTERIZER_H

#include <d3d11.h>

namespace Azul
{
	class StateRasterizer
	{
	public:
		StateRasterizer();
		StateRasterizer(const StateRasterizer &) = delete;
		StateRasterizer &operator = (const StateRasterizer &) = delete;
		virtual ~StateRasterizer();

		void Initialize(D3D11_FILL_MODE FillMode, D3D11_CULL_MODE CullMode);
		
		void Activate();

		ID3D11RasterizerState *poD3DRasterizerState;
	};

}
#endif 

// --- End of File ---
