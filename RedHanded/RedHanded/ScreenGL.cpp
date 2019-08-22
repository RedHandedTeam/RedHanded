#include "ScreenGL.h"

ScreenGL::ScreenGL(int major, int minor, bool isCoreContext)
{
	//assign OpenGL profile to compatibile or core profile based on flag passed 
	int profile = (isCoreContext) ? WGL_CONTEXT_CORE_PROFILE_BIT_ARB
		                          : WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB;

	//set the attributes for creating a modern OpenGL context 
	//the final 0 value in the vector indicates the end point
	m_attributes[0] = WGL_CONTEXT_MAJOR_VERSION_ARB;
	m_attributes[1] = major;
	m_attributes[2] = WGL_CONTEXT_MINOR_VERSION_ARB;
	m_attributes[3] = minor;
	m_attributes[4] = WGL_CONTEXT_PROFILE_MASK_ARB;
	m_attributes[5] = profile;

	m_deviceContext = nullptr;
	m_renderContext = nullptr;
}

bool ScreenGL::Initialize(const std::string& windowTitle, SCREEN_RESOLUTIONS resolution)
{
	Screen::Initialize(windowTitle, resolution);

	//first create the device context using application window created earlier
	m_deviceContext = GetDC(m_windowHandle);

	//set the properties of the RGBA color modes and buffers and OpenGL compatibility
	PIXELFORMATDESCRIPTOR pixelFormatClass;
	pixelFormatClass.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelFormatClass.nVersion = 1;
	pixelFormatClass.dwFlags = PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER;
	pixelFormatClass.iPixelType = PFD_TYPE_RGBA;
	pixelFormatClass.cDepthBits = 32;
	pixelFormatClass.cStencilBits = 32;

	//set the pixel format so that the device and render context can work together
	int pixelFormat = ChoosePixelFormat(m_deviceContext, &pixelFormatClass);
	SetPixelFormat(m_deviceContext, pixelFormat, &pixelFormatClass);

	//create temporary OpenGL rendering context using device context
	//this context is only used to acquire the extension 
	//function to enable us to create a MODERN OpenGL context
	HGLRC tempContext = wglCreateContext(m_deviceContext);

	//enable the temporary rendering context  
	wglMakeCurrent(m_deviceContext, tempContext);

	//acquire extension function for modern OpenGL 
	PFNWGLCREATECONTEXTATTRIBSARBPROC wglCreateContextAttribsARB =
    reinterpret_cast<PFNWGLCREATECONTEXTATTRIBSARBPROC>(wglGetProcAddress("wglCreateContextAttribsARB"));

	//if extension function is not found, then modern OpenGL is not supported
	if (!wglCreateContextAttribsARB)
	{
		MessageBox(m_windowHandle, "Your graphics card does not support modern OpenGL.",
			                       "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//create the modern OpenGL context using the extension function
	m_renderContext = wglCreateContextAttribsARB(m_deviceContext, NULL, m_attributes.data());

	//if OpenGL context could not be created, display error message and return false
	//display a generic context error message here for now (change later!)
	if (!m_renderContext)
	{
		MessageBox(m_windowHandle, "OpenGL context could not be created. The context is "
			                       "either invalid or not supported by your graphics card.",
			                       "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//destroy the temporary context as we no longer need it
	wglDeleteContext(tempContext);

	//enable the final rendering context  
	wglMakeCurrent(m_deviceContext, m_renderContext);

	//initialize GLAD and if it fails, display error message and return false
	if (!gladLoadGL())
	{
		MessageBox(m_windowHandle, "GLAD could not be initialized.",
			                       "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//create viewport using the stored width and height
	glViewport(0, 0, m_width, m_height);

	//display and update the window for the first time
	ShowWindow(m_windowHandle, SW_SHOW);
	UpdateWindow(m_windowHandle);

	return true;
}

void ScreenGL::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void ScreenGL::Present()
{
	SwapBuffers(m_deviceContext);
}

void ScreenGL::Shutdown()
{
	//disable the rendering context  
	wglMakeCurrent(m_deviceContext, nullptr);

	//destroy the rendering context
	wglDeleteContext(m_renderContext);
}