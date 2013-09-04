/*
#include "menu.h"

#include <string>

#include "SDL.h"
#include "SDL_ttf.h"
#include "resource.h"

menu::menu(std::string tit, std::string op1, std::string op2, std::string op3, std::string op4)
{ 
	//colors for SDL_ttf
	lBlue.b = 255;
	lBlue.g = 255;
	lBlue.r = 0;

	green.b = 0;
	green.g = 255;
	green.r = 0;
	
	blue.b = 255;
	blue.g = 0;
	blue.r = 0;

	//the options
	optionStrings[0] = op1;
	optionStrings[1] = op2;
	optionStrings[2] = op3;
	optionStrings[3] = op4;

	//render the title and options
	title = TTF_RenderText_Solid(font, tit.c_str(), blue);
	opts[0] = TTF_RenderText_Solid(font, optionStrings[0].c_str(), lBlue);
	opts[1] = TTF_RenderText_Solid(font, optionStrings[1].c_str(), lBlue);
	opts[2] = TTF_RenderText_Solid(font, optionStrings[2].c_str(), lBlue);
	opts[3] = TTF_RenderText_Solid(font, optionStrings[3].c_str(), lBlue);

	//the y values for each option
	optsY[0] = 110;
	optsY[1] = 210;
	optsY[2] = 310;
	optsY[3] = 410;

	back = loadImage("data/menuBack.png");
}

menu::~menu()
{
	//clean up
	SDL_FreeSurface(title);
	SDL_FreeSurface(opts[0]);
	SDL_FreeSurface(opts[1]);
	SDL_FreeSurface(opts[2]);
	SDL_FreeSurface(opts[3]);
	SDL_FreeSurface(back);
}

int menu::show()
{
	int mouseX = 0;
	int mouseY = 0;
	SDL_GetMouseState(&mouseX, &mouseY); //get mouse x and y
	while(SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return 4; //return STATE_EXIT
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				for (int x = 0; x < 4; x++)
				{
					if (mouseX < 225+opts[x]->w && mouseX > 225 && //if mouse is over the surface
						mouseY < optsY[x]+opts[x]->h && mouseY > optsY[x]) //of an option
					{
						return x+1; //return number of option that mouse is over
					}
				}
			}
		}
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				return 4; //return STATE_EXIT
			}
		}
	}

	//update menu
	for (int x = 0; x < 4; x++)
	{
		if (mouseX < 225+opts[x]->w && mouseX > 225 && //if mouse is over the surface
			mouseY < optsY[x]+opts[x]->h && mouseY > optsY[x]) //of an option
		{
			opts[x] = TTF_RenderText_Solid(font, optionStrings[x].c_str(), green); //make it green
		}
		else
		{
			opts[x] = TTF_RenderText_Solid(font, optionStrings[x].c_str(), lBlue); //make it blue
		}
	}

	//update screen
	blit(0, 0, back, screen);

	blit(225, 10, title, screen);
	blit(225, 110, opts[0], screen);
	if (optionStrings[1] != "NULL")
		blit(225, 210, opts[1], screen);
	if (optionStrings[2] != "NULL")
		blit(225, 310, opts[2], screen);
	if (optionStrings[3] != "NULL")
		blit(225, 410, opts[3], screen);

	SDL_Flip(screen);

	return 0;
}
*/