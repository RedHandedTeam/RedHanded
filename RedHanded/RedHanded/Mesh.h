#ifndef MESH_H
#define MESH_H

#include "Vector3.h"
#include "Vector2.h"
#include <string>
#include <map>
#include <list>

struct Vertex
{
	Vector3<float> position;
	Vector3<float> color;
	Vector3<float> normal;
	Vector2<float> uv;
};

struct Material
{
	float shininess;
	float transparency;
	Vector3<float> ambient;
	Vector2<float> diffuse;
	Vector2<float> specular;
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
