//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateBlend.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateBlend::StateBlend()
		: poD3DBlendState{nullptr},
		mMode{Mode::Uninitialized}
	{
	}

	void StateBlend ::Initialize(Mode mode)
	{
		CD3D11_BLEND_DESC BlendState;
		ZeroMemory(&BlendState, sizeof(CD3D11_BLEND_DESC));

		switch(mode)
		{
		case Mode::AlphaDisabled:

			// Disables Blending.... 
			BlendState.RenderTarget[0].BlendEnable = FALSE;
			// not using the Alpha channel... not using it on target texel
			BlendState.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
			
			break;

		case Mode::AlphaEnabled:

			// Correct setting for standard alpha-blended rendering to a texture with transparency
			// 
			// dest.rgb = dest.rgb * (1 - src.a) + src.rgb * src.a
			// SrcBlend = SRC_ALPHA
			// DestBlend = INV_SRC_ALPHA
			// BlendOp = ADD
			// 
			// dest.a = dest.a * 0 + src.a * 0
			// SrcBlendAlpha = ZERO
			// DestBlendAlpha = ZERO
			// BlendOpAlpha = ADD
			//
			// Final-Color = (src-TexelColor) x SourceBlend + (dest-CurrentPixelColor) x DestBlend

			BlendState.RenderTarget[0].BlendEnable = TRUE;
			BlendState.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;
			BlendState.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA;
			BlendState.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;

			BlendState.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ZERO;
			BlendState.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ONE;
			BlendState.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;

			// not using the Alpha channel... not using it on target texel
			BlendState.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
			
			break;

		default:
			assert(false);
		}

		// Create the Blend state object.
		HRESULT hr;
		hr = StateDirectXMan::GetDevice()->CreateBlendState(&BlendState, &this->poD3DBlendState);
		assert(SUCCEEDED(hr));
	}

	void StateBlend::Activate()
	{
		assert(this->poD3DBlendState);
		float blendFactor[4] = {0.0f, 0.0f, 0.0f, 0.0f};
		UINT sampleMask = 0xffffffff;
		StateDirectXMan::GetContext()->OMSetBlendState(this->poD3DBlendState, blendFactor, sampleMask);
	}

	StateBlend::~StateBlend()
	{
		SafeRelease(this->poD3DBlendState);
		this->poD3DBlendState = nullptr;
	}

}

// --- End of File ---
