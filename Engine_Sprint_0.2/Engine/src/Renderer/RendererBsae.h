#ifndef RENDERBASE_H
#define RENDERBASE_H

//window class will hold a renderer base
//duty is to render dx11 for window class

namespace Azul
{
	class RendererBsae
	{
	public:
		virtual bool Init(void* hwnd, bool vSync) = 0;
		virtual void RenderFrame() = 0;
		virtual ~RendererBsae() {}
	};
}


#endif