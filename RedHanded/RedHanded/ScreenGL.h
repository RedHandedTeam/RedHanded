#ifndef SCREEN_GL_H
#define SCREEN_GL_H

#include <Windows.h>
#include "Screen.h"

class ScreenGL : public Screen
{

public:

	ScreenGL();
	virtual ~ScreenGL() {}

public:

	virtual bool Initialize(int width, int height);
	virtual void Clear();
	virtual void Present();
	virtual void Shutdown();

private:

	HWND m_windowHandle;
	HDC m_deviceContext;
	HGLRC m_renderContext;

};

#endif