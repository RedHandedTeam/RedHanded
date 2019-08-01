#include <iostream>
#include "ScreenGL.h"


int main()
{

	ScreenGL testScreen(3, 1, false);

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