#include <iostream>

#include "Color.h"
#include "Matrix.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Vector2.h"

#include "Factory.h"

int main()
{
	Factory* factory = new FactoryDX11;

	Screen* screen = factory->CreateScreen(0, 6);
	if (!screen->Initialize("Test", HD))
		return 0;

	Mesh* mesh = factory->CreateMesh();

	bool hasReceived; tagMSG tag;
	tag.message = WM_NULL;

	PeekMessage(&tag, 0, 0U, 0U, PM_NOREMOVE);

	while (tag.message != WM_QUIT)
	{
		// Process window events.
		// Use PeekMessage() so we can use idle time to render the scene. 
		hasReceived = (PeekMessage(&tag, 0, 0U, 0U, PM_REMOVE) != 0);

		if (hasReceived)
		{
			// Translate and dispatch the message
			TranslateMessage(&tag);
			DispatchMessage(&tag);
		}
		else
		{
			screen->Clear();
			screen->Present();
		}
	}

	screen->Shutdown();
	return 0;

}