/*
#include <cstdlib>
#include <ctime>

#include "SDL.h"
#include "SDL_mixer.h"
#include "resource.h"

#include "ball.h"

ball::ball()
{
	clip.x = 198; //clip for the ball sprite in tiles.png
	clip.y = 132;
	clip.w = 12;
	clip.h = 12;

	rect.x = 290; //ball's coordinates
	rect.y = 430;

	xVel = rand()%8-4; //random beginning velocity between -4 and 4
	if (xVel == 0) //don't want the ball going straight up to start
		xVel = 1;
	yVel = -4;
	moving = false;
	moved = false;
}

void ball::update(int pX, int bX, int bY)
{
	if (moving)
	{
		if (!moved)
		{
			rect.x += xVel;
			rect.y += yVel;
			moved = true;
			if (rect.x < 55) //wall collision - left
			{
				xVel = -xVel;
				rect.x = 55;
			}
			if (rect.x > 443) //wall collision - right
			{
				xVel = -xVel;
				rect.x = 443;
			}
			if (rect.y < 25) //wall collision - top
			{
				yVel = -yVel;
				rect.y = 25;
			}
			if ((rect.x+12 > pX+20 && rect.x < pX+110) &&
				((rect.y+12 > 475 && rect.y+12 < 485))) //paddle collision - top
			{
				yVel = -yVel;

				//change balls x velocity depending on where it hit the paddle
				if (rect.x < pX+30)
					xVel = -4;
				else if (rect.x < pX+40)
					xVel = -3;
				else if (rect.x < pX+55)
					xVel = -2;
				else if (rect.x < pX+65)
					xVel = -1;
				else if (rect.x < pX+70)
					xVel = 0;
				else if (rect.x < pX+75)
					xVel = 1;
				else if (rect.x < pX+90)
					xVel = 2;
				else if (rect.x < pX+100)
					xVel = 3;
				else if (rect.x < pX+110)
					xVel = 4;
			} 
		}
		if ((rect.x+12 > bX && rect.x < bX+60) && 
			((rect.y+12 > bY && rect.y+12 < bY+5) || 
			(rect.y > bY+24 && rect.y < bY+29))) //block collision - top and bottom
		{
			yVel = -yVel;
		}
		if ((rect.y+12 > bY && rect.y < bY+29) && 
			((rect.x+12 > bX && rect.x+12 < bX+5) || 
			(rect.x > bX+55 && rect.x < bX+60))) //block collision - sides
		{
			xVel = -xVel;
		}
	} else { //not moving so put above paddle
		rect.y = 450;
		rect.x = pX+60;
	}
}

void ball::draw()
{
	SDL_BlitSurface(tiles, &clip, screen, &rect);
	moved = false;
}

void ball::move()
{
	moving = true;
}

void ball::reset()
{
	moving = false;
	xVel = rand()%8-4; //reset velocity
	if (xVel == 0)
		xVel = 1;
	yVel = -4;
}

int ball::myX()
{
	return rect.x;
}

int ball::myY()
{
	return rect.y;
}
*/