#ifndef DIRECTX_RENDERER_H
#define DIRECTX_RENDERER_H

#include "RendererBsae.h"

#include "StateDepthStencil.h"
#include "StateRasterizer.h"
#include "StateBlend.h"
#include "StateViewport.h"
#include "StateDepthStencilBuffer.h"
#include "StateDepthStencilView.h"
#include "StateRenderTargetView.h"

#include <d3d11.h>

namespace Azul
{
	class DirectXRenderer : public RendererBsae
	{
	public:
		DirectXRenderer();

		bool Init(void* hwnd, bool vSync) override;
		void RenderFrame() override;



	private:
		void ClearDepthStencilBuffer();
		void SetDefaultTargetMode();

	private:
		StateRenderTargetView mStateRenderTargetView;
		StateDepthStencilView mDepthStencilView;
		StateDepthStencilBuffer mDepthStencilBuffer;
		StateBlend mBlendStateOff;
		StateBlend mBlendStateAlpha;
		StateDepthStencil mStateDepthStencil;
		StateRasterizer mStateRasterizerSolid;
		StateRasterizer mStateRasterizerWireframe;
		StateViewport mViewport;

		D3D11_VIEWPORT g_Viewport;

		bool mVSync = false;
	};

	#define SafeRelease(x) { if(x){ x->Release(); x = 0; } }
}

#endif