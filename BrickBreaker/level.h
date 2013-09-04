
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "SDL.h"
#include "paddle.h"
#include "ball.h"
#include "block.h"

class level
{
public:
	level(int bls[11][6], int numBalls, int bg, std::string nam);

	void update(SDL_Event event);
	void draw();
	void back();
	bool empty();
	bool dead();
	void reset();
private:
	paddle paddle1;
	std::vector<ball> balls;
	std::vector<block> blocks;
	SDL_Rect bClip[5];
	SDL_Rect wClip[5];
	int walls[8][10];
	int backCol;
	std::string name;
};

#endif
