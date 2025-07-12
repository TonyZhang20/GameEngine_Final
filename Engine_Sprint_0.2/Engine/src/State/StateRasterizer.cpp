//----------------------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include <d3dcompiler.h>
#include "StateRasterizer.h"
#include "StateDirectXMan.h"

namespace Azul
{
	StateRasterizer::StateRasterizer()
		: poD3DRasterizerState{nullptr}
	{
	}

	void StateRasterizer::Initialize(D3D11_FILL_MODE _FillMode, D3D11_CULL_MODE _CullMode)
	{
		// Setup rasterizer state.
		D3D11_RASTERIZER_DESC rasterizerDesc;
		memset(&rasterizerDesc, 0, sizeof(D3D11_RASTERIZER_DESC));

		rasterizerDesc.AntialiasedLineEnable = FALSE;
		rasterizerDesc.CullMode = _CullMode;//D3D11_CULL_FRONT; //D3D11_CULL_NONE;

		rasterizerDesc.DepthBias = 0;
		rasterizerDesc.DepthBiasClamp = 0.0f;
		rasterizerDesc.DepthClipEnable = TRUE;
		rasterizerDesc.FillMode = _FillMode;//D3D11_FILL_SOLID;
		rasterizerDesc.FrontCounterClockwise = FALSE;
		rasterizerDesc.MultisampleEnable = FALSE;

		// To Do add scissor rectangle... its faster
		rasterizerDesc.ScissorEnable = FALSE;
		rasterizerDesc.SlopeScaledDepthBias = 0.0f;

		// Create the rasterizer state object.
		HRESULT hr;
		hr = StateDirectXMan::GetDevice()->CreateRasterizerState(&rasterizerDesc, &this->poD3DRasterizerState);
		assert(SUCCEEDED(hr));
	}

	void StateRasterizer::Activate()
	{
		assert(this->poD3DRasterizerState);
		StateDirectXMan::GetContext()->RSSetState(this->poD3DRasterizerState);
	}

	StateRasterizer::~StateRasterizer()
	{
		SafeRelease(this->poD3DRasterizerState);
		this->poD3DRasterizerState = nullptr;
	}

}

// --- End of File ---
