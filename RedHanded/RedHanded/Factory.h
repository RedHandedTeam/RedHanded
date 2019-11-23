#ifndef FACTORY_H
#define FACTORY_H

#include "ScreenDX11.h"
#include "MeshDX11.h"

#include "ScreenGL.h"
#include "MeshGL.h"

struct Factory
{
	virtual Screen* CreateScreen(int arg1, int arg2) = 0;
	virtual Mesh* CreateMesh() = 0;
};

struct FactoryDX11 : public Factory
{
	Screen* CreateScreen(int arg1, int arg2) { return new ScreenDX11(arg1, arg2); }
	Mesh* CreateMesh() { return new MeshDX11; }
};

struct FactoryGL : public Factory
{
	Screen* CreateScreen(int arg1, int arg2) { return new ScreenGL(arg1, arg2); }
	Mesh* CreateMesh() { return new MeshGL; }
};

#endif 
