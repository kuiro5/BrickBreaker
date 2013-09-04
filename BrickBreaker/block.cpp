/*
#include "SDL.h"
#include "resource.h"

#include "block.h"

block::block(int col, int x, int y)
{
	alive = true;
	switch (col) //get clip for color
	{
	case 0: //yellow
		clip.x = 0;
		clip.y = 66;
		clip.w = 60;
		clip.h = 29;
		break;
	case 1: //pink
		clip.x = 66;
		clip.y = 66;
		clip.w = 60;
		clip.h = 29;
		break;
	case 2: //green
		clip.x = 0;
		clip.y = 97;
		clip.w = 60;
		clip.h = 29;
		break;
	case 3: //orange
		clip.x = 66;
		clip.y = 97;
		clip.w = 60;
		clip.h = 29;
		break;
	case 4: //red
		clip.x = 0;
		clip.y = 128;
		clip.w = 60;
		clip.h = 29;
		break;
	case 5: //light blue
		clip.x = 66;
		clip.y = 128;
		clip.w = 60;
		clip.h = 29;
		break;
	case 6: //brown
		clip.x = 0;
		clip.y = 159;
		clip.w = 60;
		clip.h = 29;
		break;
	case 7: //purple
		clip.x = 66;
		clip.y = 159;
		clip.w = 60;
		clip.h = 29;
		break;
	}
	rect.x = x; //block's coordinates
	rect.y = y;
}

void block::update(int bX, int bY)
{
	if (alive)
	{
		if (bX+12 > rect.x && bX < rect.x+60 && bY+12 > rect.y && bY < rect.y+29) //ball collision
		{
			alive = false;
			score += 10;
		}
	}
}

void block::draw()
{
	if (alive)
		SDL_BlitSurface(tiles, &clip, screen, &rect);
}

int block::myX()
{
	if (alive)
		return rect.x;
	else
		return 0;
}

int block::myY()
{
	if (alive)
		return rect.y;
	else
		return 0;
}

bool block::gone()
{
	if (alive)
		return false;
	else
		return true;
}

void block::makeAlive()
{
	alive = true;
}
*/