
#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "SDL.h"

#include "level.h"

class game
{
public:
	game();
	~game();

	int gameLoop();
	int showHighScores();
	void showCredits();
private:
	int gameOver();

	SDL_Event event;
	std::vector<level> levels;
	int highScores[3];
	std::string names[3];
	unsigned int lvl;
	SDL_Rect livesClip;
	int lives;
};

#endif
