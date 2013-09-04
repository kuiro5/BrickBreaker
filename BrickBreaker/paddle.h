
#ifndef PADDLE_H
#define PADDLE_H

#include "SDL.h"

class paddle
{
public:
	paddle();

	void update();
	void draw();
	int myX();
private:
	SDL_Rect rect;
	SDL_Rect clip;
};

#endif