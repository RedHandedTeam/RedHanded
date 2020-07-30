#ifndef SCREEN_DX11_H
#define SCREEN_DX11_H

#include "Screen.h"

class ScreenDX11 : public Screen
{

public:

	ScreenDX11(int lowest = 6, int highest = 6);
	virtual ~ScreenDX11() {}

public:

	virtual bool Initialize(const std::string& windowTitle, SCREEN_RESOLUTIONS resolution);
	virtual void Clear();
	virtual void Present();
	virtual void Shutdown();

	Microsoft::WRL::ComPtr<ID3D11Device>& GetDevice() { return m_device; }
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>& GetDeviceContext() { return m_deviceContext; }

private:

	Microsoft::WRL::ComPtr<ID3D11Device> m_device;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_deviceContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_renderTargetView;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> m_depthStencilView;
	
	std::vector<D3D_FEATURE_LEVEL> m_compatibleLevels;
};

#endif

