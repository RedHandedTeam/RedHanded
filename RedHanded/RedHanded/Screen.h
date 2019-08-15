#ifndef SCREEN_H
#define SCREEN_H

#include "Utilities.h"

class Screen
{

public:

	Screen();
	virtual ~Screen() {}

public:

	virtual bool Initialize(const char* windowTitle, int width = 1920, int height = 1080) = 0;
	virtual void Clear()																  = 0;
	virtual void Present()																  = 0;
	virtual void Shutdown()																  = 0;

protected:

	int m_width;
	int m_height;

	static LRESULT CALLBACK ProcessInput(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		//nothing here - we will create a Input Manager later!
		//process all other default messages and return that result
		return DefWindowProc(windowHandle, message, wParam, lParam);
	}
};

#endif