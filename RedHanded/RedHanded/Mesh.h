#ifndef MESH_H
#define MESH_H

#include "Utilities.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Color.h"
#include "Matrix.h"

struct Vertex
{
	Vector3<float> position;
	Vector3<float> normal;
	Vector2<float> uv;
	Color color;
};

struct Material
{
	float shininess;
	float transparency;
	Color ambient;
	Color diffuse;
	Color specular;
};

class Mesh
{

public:

	Mesh();
	virtual ~Mesh();

protected:

	static void Load();
	static void Load(std::string id);
	static void UnLoad();
	static void UnLoad(std::string id);

protected:

	static std::map<std::string, std::pair<std::list<Vertex>, Material>> MeshData;
};

#endif
