#ifndef FACTORY_H
#define FACTORY_H

#include "ScreenDX11.h"
#include "MeshDX11.h"

#include "ScreenGL.h"
#include "MeshGL.h"

struct Factory
{
	virtual Screen* CreateScreen(int arg1, int arg2, bool arg3 = false) = 0;
	virtual Mesh* CreateMesh() = 0;
};

struct FactoryDX11 : public Factory
{
	ScreenDX11* screenAPI;
	Screen* CreateScreen(int arg1, int arg2, bool arg3 = false) 
	{ 
		screenAPI = new ScreenDX11(arg1, arg2);
		return screenAPI;
	}
	Mesh* CreateMesh() { return new MeshDX11(screenAPI); }
};

struct FactoryGL : public Factory
{
	ScreenGL* screenAPI;
	Screen* CreateScreen(int arg1, int arg2, bool arg3 = false) 
	{ 
		screenAPI = new ScreenGL(arg1, arg2, arg3);
		return screenAPI;
	}
	Mesh* CreateMesh() { return new MeshGL(); }
};

#endif 
