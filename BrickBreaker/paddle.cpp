/*
#include "SDL.h"
#include "resource.h"

#include "paddle.h"

paddle::paddle()
{
	clip.x = 329; //clip of paddle sprite in tiles.png
	clip.y = 0;
	clip.w = 128;
	clip.h = 64;

	rect.x = 256; //paddle's coordinates
	rect.y = 445;
}

void paddle::update()
{
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&x, &y); //get mouse x and y
	if (x < 100) //if it's not inside the wall bounderies
		rect.x = 37;
	else if (x > 410)
		rect.x = 345;
	else
		rect.x = x-64; //set paddle x to mouse x
}

void paddle::draw()
{
	SDL_BlitSurface(tiles, &clip, screen, &rect);
}

int paddle::myX()
{
	return rect.x;
}
*/