#ifndef MESH_DX11_H
#define MESH_DX11_H

#include "ScreenDX11.h"
#include "Mesh.h"

class MeshDX11 : public Mesh
{

public:

	MeshDX11(ScreenDX11* api);
	void Draw();
	virtual ~MeshDX11();

private:

	std::map<std::string, Microsoft::WRL::ComPtr<ID3D11Buffer>> vertexBuffer;
	ScreenDX11* api;
};

#endif