#include "Screen.h"

Screen::Screen()
{
	m_instanceHandle = static_cast<HINSTANCE>(GetModuleHandle(nullptr));
	m_windowHandle = nullptr;

	m_height = 0;
	m_width = 0;
}

Screen::~Screen()
{
	//destroy window
	DestroyWindow(m_windowHandle);

	//unregister window
	UnregisterClass("WindowClass", m_instanceHandle);
}

long CALLBACK ProcessWindowEvent(HWND windowHandle, unsigned int message, unsigned int wParam, long lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(windowHandle, message, wParam, lParam);
}

bool Screen::Initialize(const std::string& windowTitle, SCREEN_RESOLUTIONS resolution)
{
	//calculate standard resolution of window
	m_height = resolution;
	m_width = (m_height / ASPECT_RATIO_H) * ASPECT_RATIO_W;

	//set the center position of window
	int windowX = CW_USEDEFAULT;
	int windowY = CW_USEDEFAULT;

	//set the rectangular dimensions of window
	RECT windowRect;
	windowRect.left = 0;
	windowRect.right = m_width;
	windowRect.top = 0;
	windowRect.bottom = m_height;

	//set the properties of the window 
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = ProcessWindowEvent;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = m_instanceHandle;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	windowClass.lpszMenuName = nullptr;
	windowClass.lpszClassName = "WindowClass";
	windowClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	//register the windows class with the OS and if there
	//was an error, display error message and return false
	if (!RegisterClassEx(&windowClass))
	{
		MessageBox(m_windowHandle, "Application window could not be created.",
			"Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//set style of window and adjust it within the OS
	unsigned long windowStyle = WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	AdjustWindowRectEx(&windowRect, windowStyle, false, 0);

	//after all the above pilava create the actual application window
	//this is the main application window therefore it has no parent
	m_windowHandle = CreateWindowEx(0, "WindowClass", windowTitle.c_str(),
									windowStyle, windowX, windowY, m_width, m_height,
									nullptr, nullptr, m_instanceHandle, nullptr);

	//if application window could not be created, display error message and return false
	if (!m_windowHandle)
	{
		MessageBox(m_windowHandle, "Application window could not be created.",
								   "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	return true;
}
