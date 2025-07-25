#include "DirectXRenderer.h"
#include "StateDirectXMan.h"
#include "Colors.h"

namespace Azul
{
	DirectXRenderer::DirectXRenderer()
		:
		mStateRenderTargetView(),
		mDepthStencilView(),
		mDepthStencilBuffer(),
		mStateDepthStencil(),
		mBlendStateOff(),
		mBlendStateAlpha(),
		mStateRasterizerSolid(),
		mStateRasterizerWireframe(),
		mViewport()
	{
		
	}

	bool DirectXRenderer::Init(void* pHWND, bool vSync)
	{
		HWND hwnd = (HWND)pHWND;
		RECT clientRect;

		GetClientRect(hwnd, &clientRect);

		unsigned int clientWidth = clientRect.right - clientRect.left;
		unsigned int clientHeight = clientRect.bottom - clientRect.top;

		StateDirectXMan::Create(hwnd, vSync);

		// The Direct3D device and swap chain were successfully created.
		// Now we need to initialize the buffers of the swap chain.
		// Next initialize the back buffer of the swap chain and associate it to a 
		// render target view.
		this->mStateRenderTargetView.Initialize();

		// Create the depth buffer for use with the depth/stencil view.
		this->mDepthStencilBuffer.Initialize(clientWidth, clientHeight);
		this->mDepthStencilView.Initialize(this->mDepthStencilBuffer);

		// Setup depth/stencil state.
		D3D11_DEPTH_STENCIL_DESC depthStencilStateDesc{ 0 };

		depthStencilStateDesc.DepthEnable = TRUE;
		depthStencilStateDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
		depthStencilStateDesc.DepthFunc = D3D11_COMPARISON_LESS;
		// not using any stencil... its disabled
		depthStencilStateDesc.StencilEnable = FALSE;

		// Setup depth/stencil state.
		this->mStateDepthStencil.Initialize();

		// Setup blends state
		this->mBlendStateOff.Initialize(StateBlend::Mode::AlphaDisabled);

		// Disables Blending.... 
		this->mBlendStateAlpha.Initialize(StateBlend::Mode::AlphaEnabled);

		// Setup rasterizer state.
		this->mStateRasterizerSolid.Initialize(D3D11_FILL_SOLID, D3D11_CULL_FRONT);
		this->mStateRasterizerWireframe.Initialize(D3D11_FILL_WIREFRAME, D3D11_CULL_FRONT);

		// Initialize the viewport to occupy the entire client area.
		this->mViewport.Initialize(clientWidth, clientHeight);

		return true;
	}

	void DirectXRenderer::RenderFrame()
	{
		ClearDepthStencilBuffer();
		SetDefaultTargetMode();
	}

	void DirectXRenderer::ClearDepthStencilBuffer()
	{
#ifdef _DEBUG
		const Vec4 ClearColor = Colors::LightBlue;
#else
		const Vec4 ClearColor = Colors::Wheat;
#endif

		float clearDepth = 1.0f;
		uint8_t clearStencil = 0;

		this->mStateRenderTargetView.Clear(ClearColor);
		this->mDepthStencilView.Clear(clearDepth, clearStencil);
	}

	void DirectXRenderer::SetDefaultTargetMode()
	{
		//--------------------------------------------------------
		// Set (point to ) the Rasterizers functions to be used
		//--------------------------------------------------------
		//g_d3dDeviceContext->RSSetState(g_d3dRasterizerState);
		this->mStateRasterizerSolid.Activate();

		//--------------------------------------------------------
		// Set (point to ) the Viewport to be used
		//--------------------------------------------------------
		//g_d3dDeviceContext->RSSetViewports(1, &g_Viewport);
		this->mViewport.Activate();

		//--------------------------------------------------------
		// Set (point to ) render target
		//      Only one Target, this maps to Pixel shader
		// --------------------------------------------------------
		//g_d3dDeviceContext->OMSetRenderTargets(1, &g_d3dRenderTargetView, g_d3dDepthStencilView);
		this->mStateRenderTargetView.Activate(this->mDepthStencilView);


		//--------------------------------------------------------
		// Set blend target
		//--------------------------------------------------------
		this->mBlendStateOff.Activate();

		//--------------------------------------------------------
		// Set Depth functions to be used
		//--------------------------------------------------------
		this->mStateDepthStencil.Activate();
	}
}