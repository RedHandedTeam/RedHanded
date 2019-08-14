#ifndef SCREEN_GL_H
#define SCREEN_GL_H

#include <Windows.h>
#include <vector>
#include "Screen.h"

class ScreenGL : public Screen
{

public:

	ScreenGL(int major = 4, int minor = 0, bool isCoreContext = false);
	virtual ~ScreenGL() {}

public:

	virtual bool Initialize(const char* windowTitle, int width, int height);
	virtual void Clear();
	virtual void Present();
	virtual void Shutdown();

private:

	HWND m_windowHandle;
	HDC m_deviceContext;
	HGLRC m_renderContext;

	std::vector<int> m_attributes;

};

#endif