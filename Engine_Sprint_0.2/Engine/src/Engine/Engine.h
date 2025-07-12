//--------------------------------------------------------------
// Copyright 2025, Ed Keenan, all rights reserved.
//--------------------------------------------------------------
#ifndef ENGINE_H
#define ENGINE_H

#include <d3d11.h>
#include "StateDepthStencil.h"
#include "StateRasterizer.h"
#include "StateBlend.h"
#include "StateViewport.h"
#include "StateDepthStencilBuffer.h"
#include "StateDepthStencilView.h"
#include "StateRenderTargetView.h"

namespace Azul
{
	class Engine
	{
	public:
		static const BOOL ENABLE_VSYNC = true;

	public:
		Engine(const char* pName, int width, int height);

		Engine() = delete;
		Engine(const Engine&) = delete;
		Engine& operator = (const Engine&) = delete;
		virtual ~Engine();


		virtual bool LoadContent() = 0;
		virtual void UnloadContent() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;
		virtual	void ClearDepthStencilBuffer() = 0;

		void Cleanup();



		int InitApplication(HINSTANCE hInstance, int cmdShow);
		int InitDirectX(HINSTANCE hInstance, BOOL vSync);
		static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
		int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow);

		void Present(bool vSync);
		static DXGI_RATIONAL QueryRefreshRate(UINT screenWidth, UINT screenHeight, BOOL vsync);
		int Run();

		HWND g_WindowHandle;

		// Direct3D device and swap chain.
		//ID3D11Device* g_d3dDevice;
		//ID3D11DeviceContext* g_d3dDeviceContext;
		//IDXGISwapChain* g_d3dSwapChain;

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

		const char* pName;
		const int mWindowWidth;
		const int mWindowHeight;

	};


	// Convenience macro for releasing COM objects.
	#define SafeRelease(x) { if(x){ x->Release(); x = 0; } }
}



#endif

// --- End of File ---
