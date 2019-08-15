#include <iostream>
#include "ScreenGL.h"
#include "ScreenDX11.h"

int main()
{
	ScreenDX11 testScreen(0, 6);
	//ScreenGL testScreen(4, 0);
	if (!testScreen.Initialize("Test", HD))
		return 0;

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
			testScreen.Clear();
			testScreen.Present();
		}
	}

	testScreen.Shutdown();

	system("pause");
	return 0;

}