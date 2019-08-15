#ifndef SCREEN_GL_H
#define SCREEN_GL_H

#include "Screen.h"

class ScreenGL : public Screen
{

public:

	ScreenGL(int major = 4, int minor = 0, bool isCoreContext = false);
	virtual ~ScreenGL() {}

public:

	virtual bool Initialize(std::string windowTitle, SCREEN_RESOLUTIONS resolution);
	virtual void Clear();
	virtual void Present();
	virtual void Shutdown();

private:

	HDC m_deviceContext;
	HGLRC m_renderContext;

	std::array<int, 7> m_attributes;
};

#endif