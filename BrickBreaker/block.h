
#ifndef BLOCK_H
#define BLOCK_H

#include "SDL.h"

class block
{
public:
	block(int col, int x, int y);

	void update(int bX, int bY);
	void draw();
	int myX();
	int myY();
	bool gone();
	void makeAlive();
private:
	bool alive;
	SDL_Rect rect;
	SDL_Rect clip;
};

#endif