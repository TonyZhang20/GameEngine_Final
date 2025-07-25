#include "WindowsWindow.h"
#include <cvt/wstring>
#include <d3d11.h>
#include <d3dcompiler.h>

namespace Azul
{
	static WindowsWindow* s_MainWindowInstance = nullptr;
	LPCSTR WindowName = "EngineWindowClass";

	bool WindowsWindow::Create()
	{

		if (!CreateWindowClass() || !CreateWindowInstance())
		{
			assert(false && "Failed to create Win64 window.");
			return false;
		}

		Show();
		UpdateWindow(hwnd);

		return true;
	}

	void WindowsWindow::Destroy()
	{
		if (hwnd)
		{
			DestroyWindow(hwnd);
			hwnd = nullptr;
		}

		if (m_Data.Title)
		{
			delete[] m_Data.Title;
			m_Data.Title = nullptr;
		}

		UnregisterClass(TEXT("AzulWindowClass"), instance);
	}

	void WindowsWindow::Show()
	{
		ShowWindow(hwnd, SW_SHOW);
	}

	void WindowsWindow::Hide()
	{
		ShowWindow(hwnd, SW_HIDE);
	}

	void WindowsWindow::SetTitle(const char* title)
	{
		if (hwnd)
		{
			SetWindowTextA(hwnd, title);
		}

		if (m_Data.Title)
		{
			delete[] m_Data.Title;
			m_Data.Title = nullptr;
		}

		size_t len = strlen(title) + 1;
		m_Data.Title = new char[len];
		strcpy_s(m_Data.Title, len, title);
	}

	void WindowsWindow::OnUpdate()
	{
		MSG msg = {};

		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	WindowsWindow::WindowsWindow(HINSTANCE hInstance, const WindowProps& props)
		: instance( hInstance)
	{
		this->Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		this->Destroy();
	}

	LRESULT WindowsWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT paintStruct;
		HDC hDC;

		switch (uMsg)
		{
		case WM_PAINT:
		{
			hDC = BeginPaint(hwnd, &paintStruct);
			EndPaint(hwnd, &paintStruct);
		}
		break;

		case WM_SIZE:
		{
			UINT width = LOWORD(lParam);
			UINT height = HIWORD(lParam);
			
			//Event Send - Size Change

			break;
		}

		case WM_CHAR:
		{
			if (wParam == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}
			break;
		}
		break;

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
		break;

		default:
			break;
		}

		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	bool WindowsWindow::CreateWindowClass()
	{

		WNDCLASSEX wndClass = { 0 };
		wndClass.cbSize = sizeof(WNDCLASSEX);
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.lpfnWndProc = this->WindowProc;
		wndClass.hInstance = this->instance;
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndClass.hIcon = nullptr;
		wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
		wndClass.lpszMenuName = nullptr;
		wndClass.lpszClassName = WindowName;
		wndClass.hIconSm = nullptr;


		if (!RegisterClassEx(&wndClass))
		{
			DWORD err = GetLastError();

			std::wstring msg = L"RegisterClassEx failed. Error code: " + std::to_wstring(err);
			MessageBoxW(nullptr, msg.c_str(), L"Error", MB_OK | MB_ICONERROR);

			assert(false && "Failed to register window class.");

			return false;
		}

		return true;
	}

	bool WindowsWindow::CreateWindowInstance()
	{
		RECT windowRect = { 0, 0, (LONG)m_Data.Width, (LONG)m_Data.Height };
		AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

		hwnd = CreateWindowA(WindowName, this->m_Data.Title,
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			windowRect.right - windowRect.left,
			windowRect.bottom - windowRect.top,
			nullptr, nullptr, instance, nullptr);

		return hwnd != nullptr;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		this->m_Data.Height = props.Height;
		this->m_Data.Width = props.Width;
		this->m_Data.Title = props.Title;

		m_Data.VSync = true;
	}

}
