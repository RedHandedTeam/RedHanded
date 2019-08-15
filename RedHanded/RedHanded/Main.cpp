#include <iostream>
#include "ScreenGL.h"
#include "ScreenDX11.h"

int main()
{
	ScreenDX11 testScreen(0, 7);

	if (!testScreen.Initialize("Test", 640, 480))
		return 0;

	while (1)
	{
		testScreen.Clear();
		testScreen.Present();
	}

	testScreen.Shutdown();

	system("pause");
	return 0;

}