#include "MeshDX11.h"

MeshDX11::MeshDX11(ScreenDX11* api)
{
	this->api = api;
	//================================================================================================
	const Vertex vertices[]
	{
		Vector3<float>(-0.5f, -0.5f, 0.0f),
		Vector3<float>(0.0f, 0.5f, 0.0f),
		Vector3<float>(0.5f,-0.5, 0.0f)
	};
	
	D3D11_BUFFER_DESC bufferDesc;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(vertices);
	bufferDesc.MiscFlags = 0;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.StructureByteStride = sizeof(Vertex);
	D3D11_SUBRESOURCE_DATA subResource;
	subResource.pSysMem = vertices;

	

	api->GetDevice()->CreateBuffer(&bufferDesc, &subResource, &vertexBuffer["test"]);


	Microsoft::WRL::ComPtr<ID3DBlob> blob; 
	//===================================================================================================
	Microsoft::WRL::ComPtr<ID3D11PixelShader> pixelShader;
	D3DReadFileToBlob(L"PixelShader.cso", &blob);

	api->GetDevice()->CreatePixelShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, &pixelShader);
	api->GetDeviceContext()->PSSetShader(pixelShader.Get(), nullptr, 0);
	//=================================================================================================
	
	Microsoft::WRL::ComPtr<ID3D11VertexShader> vertexShader;
	D3DReadFileToBlob(L"VertexShader.cso", &blob);

	api->GetDevice()->CreateVertexShader(blob->GetBufferPointer(), blob->GetBufferSize(), nullptr, &vertexShader);
	api->GetDeviceContext()->VSSetShader(vertexShader.Get(), nullptr, 0);
	//==================================================================================================

	Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
	D3D11_INPUT_ELEMENT_DESC layoutDesc[] =
	{
		{ "Position", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};
	api->GetDevice()->CreateInputLayout(layoutDesc, std::size(layoutDesc), blob->GetBufferPointer(), blob->GetBufferSize(), &inputLayout);
	api->GetDeviceContext()->IASetInputLayout(inputLayout.Get());

	//================================================================================================
}

void MeshDX11::Draw()
{
	const UINT stride = sizeof(Vertex);
	const UINT offset = 0;
	//=====================================================================================================
	api->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	api->GetDeviceContext()->IASetVertexBuffers(0, 1, vertexBuffer["test"].GetAddressOf(), &stride, &offset);
	api->GetDeviceContext()->Draw(3, 0);
}

MeshDX11::~MeshDX11()
{
}
