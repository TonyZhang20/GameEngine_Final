//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef STATE_BLEND_H
#define STATE_BLEND_H

#include <d3d11.h>

namespace Azul
{
	class StateBlend
	{
	public:
		enum class Mode
		{
			AlphaEnabled,
			AlphaDisabled,
			Uninitialized
		};

	public:
		StateBlend();
		StateBlend(const StateBlend &) = delete;
		StateBlend &operator = (const StateBlend &) = delete;
		virtual ~StateBlend();

		void Initialize(Mode mode);
		void Activate();

		ID3D11BlendState *poD3DBlendState;
		Mode mMode;
	};

}
#endif 

// --- End of File ---
