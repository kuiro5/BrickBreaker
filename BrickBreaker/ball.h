
#ifndef BALL_H
#define BALL_H

#include "SDL.h"

class ball
{
public:
	ball();

	void update(int pX, int bX, int bY);
	void draw();
	void move();
	void reset();
	int myX();
	int myY();
private:
	SDL_Rect rect;
	SDL_Rect clip;
	bool moving;
	bool moved;
	int xVel;
	int yVel;
};

#endif;