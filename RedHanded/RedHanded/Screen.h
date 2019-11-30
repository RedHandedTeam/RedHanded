#ifndef SCREEN_H
#define SCREEN_H

#define ASPECT_RATIO_W 16
#define ASPECT_RATIO_H 9

#include "Utilities.h"

typedef enum SCREEN_RESOLUTIONS {
	HD = 720,
	HD_PLUS = 900,
	FHD = 1080,
	QHD = 1440,
	UHD = 2160
} SCREEN_RESOLUTIONS;

class Screen
{

public:

	Screen();
	virtual ~Screen();

public:

	virtual bool Initialize(const std::string& windowTitle, SCREEN_RESOLUTIONS resolution);
	virtual void Clear() = 0;
	virtual void Present() = 0;
	virtual void Shutdown() = 0;

protected:
	
	HINSTANCE m_instanceHandle;
	HWND m_windowHandle;
	int m_height;
	int m_width;
};

#endif