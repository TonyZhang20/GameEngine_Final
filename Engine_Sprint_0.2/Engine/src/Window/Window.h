#ifndef WINDOW_H
#define WINDOW_H

#include "MathEngine.h"
#include "Event.h"
#include <cstring>
#include <functional>

#include "RendererBsae.h"

namespace Azul
{
	enum class WindowType
	{
		Main, Child, Browser, Tool
	};

	struct WindowProps
	{
		char* Title;
		unsigned int Width;
		unsigned int Height;

		/// <summary>
		/// </summary>
		/// <param name="title">Deep Copy</param>
		WindowProps(const char* title = "Azul Engine",
			unsigned int width = 1280, unsigned int height = 720)
			: Width(width), Height(height)
		{
			size_t len = std::strlen(title) + 1;  // +1 为终止符 '\0'
			Title = new char[len];

			strcpy_s(Title, len, title);
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		Window() = default;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;
		virtual void OnRenderer() = 0;

		virtual void Show() = 0;
		virtual void Hide() = 0;
		
		virtual void SetTitle(const char* title) = 0;
		virtual void SetRenderer(RendererBsae* renderer) = 0;

		virtual void* GetNativeHandle() const = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

		virtual bool Create() = 0;
		virtual void Destroy() = 0;

		virtual bool IsOpen() const = 0;

	protected:
		RendererBsae* mRenderer = nullptr;
	};
}

#endif