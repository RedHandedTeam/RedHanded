#include "ScreenDX11.h"

ScreenDX11::ScreenDX11(int lowest, int highest)
{
	//the feature level tells DirectX the minimum level of hardware your app supports 
	//with D3D_FEATURE_LEVEL_9_1 as the lowest and D3D_FEATURE_LEVEL_11_1 as the highest possible
	std::array<D3D_FEATURE_LEVEL, 7> levels = {
	D3D_FEATURE_LEVEL_9_1,
	D3D_FEATURE_LEVEL_9_2,
	D3D_FEATURE_LEVEL_9_3,
	D3D_FEATURE_LEVEL_10_0,
	D3D_FEATURE_LEVEL_10_1,
	D3D_FEATURE_LEVEL_11_0,
	D3D_FEATURE_LEVEL_11_1
	};

	for (int i = lowest; i < highest; i++)
	{
		m_compatibleLevels.push_back(levels[i]);
	}
	
	m_instanceHandle = (HINSTANCE)GetModuleHandle(NULL);
	m_windowHandle = nullptr;
	m_device = nullptr;
	m_deviceContext = nullptr;
}

bool ScreenDX11::Initialize(const char* windowTitle, int width, int height)
{
	//set the center position of window
	int windowX = CW_USEDEFAULT;
	int windowY = CW_USEDEFAULT;

	//set the rectangular dimensions of window
	RECT windowRect;
	windowRect.left = 0;
	windowRect.right = width;
	windowRect.top = 0;
	windowRect.bottom = height;

	//set the properties of the window 
	WNDCLASSEX windowClass;
	windowClass.cbSize = sizeof(WNDCLASSEX);
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpfnWndProc = ProcessInput; //[TODO: add a proper Input Manager here later]
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = 0;
	windowClass.hInstance = m_instanceHandle;
	windowClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	windowClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
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
	DWORD windowStyle = WS_OVERLAPPEDWINDOW | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU;
	AdjustWindowRectEx(&windowRect, windowStyle, false, 0);

	//after all the above pilava create the actual application window
	//this is the main application window therefore it has no parent
	m_windowHandle = CreateWindowEx(0, "WindowClass", windowTitle, windowStyle, windowX, windowY, width, height,
									nullptr, nullptr, m_instanceHandle, nullptr);

	//if application window could not be created, display error message and return false
	if (!m_windowHandle)
	{
		MessageBox(m_windowHandle, "Application window could not be created.",
								   "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//***********************
	//DirectX11 specific setup
	//***********************

	//this flag adds support for surfaces with a color-channel ordering different
	//from the API default. It is required for compatibility with Direct2D
	UINT deviceFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
	#if defined(DEBUG) || defined(_DEBUG)
		deviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
	#endif

	//create swapchain properties
	DXGI_SWAP_CHAIN_DESC swapChainDescriptor;
	ZeroMemory(&swapChainDescriptor, sizeof(DXGI_SWAP_CHAIN_DESC));
	swapChainDescriptor.Windowed = TRUE;
	swapChainDescriptor.BufferCount = 2;
	swapChainDescriptor.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
	swapChainDescriptor.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDescriptor.SampleDesc.Count = 1;   
	swapChainDescriptor.SampleDesc.Quality = 0; 
	swapChainDescriptor.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
	swapChainDescriptor.OutputWindow = m_windowHandle;

	//create DirectX device and device context and swapchain using
	//the compatibility flags, quality settings, and swapchane properties
	D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, deviceFlags,
								  m_compatibleLevels.data(), m_compatibleLevels.size(), D3D11_SDK_VERSION, &swapChainDescriptor,
								  m_swapChain.GetAddressOf(), m_device.GetAddressOf(), &m_featureLevel, m_deviceContext.GetAddressOf());

	//if the GPU feature level is not found, then adjust to lower supported settings
	if (!m_featureLevel)
	{
		MessageBox(m_windowHandle, "Your graphics card does not support this DirectX feature level.",
								   "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//if DirectX context could not be created, display error message and return false
	//display a generic context error message here for now (change later!)
	if (!m_deviceContext || !m_device)
	{
		MessageBox(m_windowHandle, "DirectX context could not be created. The context is "
			                       "either invalid or not supported by your graphics card.",
			                       "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//if DirectX context failed to create a swapchain
	if (!m_swapChain)
	{
		MessageBox(m_windowHandle, "A SwapChain could not be created with the current context.",
								   "Error", MB_ICONERROR | MB_OK);
		return false;
	}

	//configure the back buffer
	D3D11_TEXTURE2D_DESC backBufferDescriptor;
	m_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)m_backBuffer.GetAddressOf());
	m_backBuffer->GetDesc(&backBufferDescriptor);

	//create a depth-stencil view for use with 3D rendering if needed
	CD3D11_TEXTURE2D_DESC depthStencilDesc(DXGI_FORMAT_D24_UNORM_S8_UINT,
										   static_cast<UINT> (backBufferDescriptor.Width),
										   static_cast<UINT> (backBufferDescriptor.Height),
										   1, 1, D3D11_BIND_DEPTH_STENCIL);

	//parse the depth texture settings
	m_device->CreateTexture2D(&depthStencilDesc, nullptr, m_depthStencil.GetAddressOf());
	CD3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc(D3D11_DSV_DIMENSION_TEXTURE2D);

	//create depth and render target buffer
	m_device->CreateDepthStencilView(m_depthStencil.Get(), &depthStencilViewDesc, m_depthStencilView.GetAddressOf());
	m_device->CreateRenderTargetView(m_backBuffer.Get(), nullptr, m_renderTargetView.GetAddressOf());
	
	//create viewport using the back buffer dimensions
	ZeroMemory(&m_viewport, sizeof(D3D11_VIEWPORT));
	m_viewport.Height = (float)backBufferDescriptor.Height;
	m_viewport.Width = (float)backBufferDescriptor.Width;
	m_viewport.MinDepth = 0;
	m_viewport.MaxDepth = 1;

	m_deviceContext->RSSetViewports(1, &m_viewport);
	
	//display and update the window for the first time
	ShowWindow(m_windowHandle, SW_SHOW);
	UpdateWindow(m_windowHandle);

	//store width and height properties for later 
	//use when setting up 2D and 3D projections
	m_width = width;
	m_height = height;

	return true;
}

void ScreenDX11::Clear()
{
	//clear the render target and the z-buffer.
	const float black[] = { 0.f,0.f,0.f, 1.000f };
	m_deviceContext->ClearRenderTargetView(m_renderTargetView.Get(), black);
	m_deviceContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	// Set the render target.
	m_deviceContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());
}

void ScreenDX11::Present()
{
	m_swapChain->Present(1, 0);
}

void ScreenDX11::Shutdown()
{
	//release the render target view based on the back buffer:
	m_renderTargetView.Reset();

	//release depth stencil view and depth buffer:
	m_depthStencilView.Reset();
	m_depthStencil.Reset();

	//release the back buffer itself:
	m_backBuffer.Reset();

	//release the devices context resources:
	m_deviceContext->Flush();

	//destroy window
	DestroyWindow(m_windowHandle);

	//unregister window
	UnregisterClass("WindowClass", m_instanceHandle);
}
