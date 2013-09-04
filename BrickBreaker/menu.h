
#ifndef MENU_H
#define MENU_H

#include <string>

#include "SDL.h"

class menu
{
public:
	menu(std::string tit, std::string op1, std::string op2, std::string op3, std::string op4);
	~menu();

	int show();
private:
	SDL_Event event;
	SDL_Surface *title;
	SDL_Surface *opts[4];
	int optsY[4];
	std::string optionStrings[4];
	SDL_Surface *back;
	SDL_Color lBlue;
	SDL_Color green;
	SDL_Color blue;
};

#endif