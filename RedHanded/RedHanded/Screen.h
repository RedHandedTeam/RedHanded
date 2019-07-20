#ifndef SCREEN_H
#define SCREEN_H

class Screen
{

public:

	Screen() {}
	virtual ~Screen() {}

public:

	virtual bool Initialize(int width = 1920, int height = 1080) = 0;
	virtual void Clear()										 = 0;
	virtual void Present()										 = 0;
	virtual void Shutdown()										 = 0;

private:

	//??

};

#endif