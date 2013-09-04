#include "SDL.h"

int main( int argc, char* args[] )
{
    //Start SDL
    SDL_Init( SDL_INIT_EVERYTHING );
    
    //Quit SDL
    SDL_Quit();
    
    return 0;    
}

/*#include <cstdlib>
#include <ctime>

#include "SDL.h"
//#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include "resource.h"
#include "game.h"
#include "menu.h"

//Constants
const int STATE_MENU = 0;
const int STATE_GAME = 1;
const int STATE_HIGH = 2;
const int STATE_OPTS = 3;
const int STATE_EXIT = 4;

//global variables so they can be used in multiple places
SDL_Surface *screen = NULL; 
SDL_Surface *tiles = NULL;
SDL_Surface *message = NULL;

TTF_Font *font = NULL;

int score = 0;

void main()
{
	srand((unsigned)time(0));
	if(!init())
	{
		SDL_Quit();
	}

	bool quit = false;
	int time = SDL_GetTicks();
	int gameState = STATE_MENU;

	tiles = loadImage("tiles.png");

	font = TTF_OpenFont("data-latin.ttf", 28);

		game mGame;

	menu mainMenu("Paddle Bang!", "Play", "High Scores", "Options", "Exit");
	menu optionMenu("Options", "Toggle Music", "Toggle Sound Effects", "Return", "NULL");

	while (!quit)
	{
		time = SDL_GetTicks();
		if (gameState == STATE_MENU)
		{
			SDL_ShowCursor(SDL_ENABLE); //show cursor
			gameState = mainMenu.show();
		}
		else if (gameState == STATE_GAME)
		{
			SDL_ShowCursor(SDL_DISABLE); //don't show cursor
			gameState = mGame.gameLoop();
		}
		else if (gameState == STATE_HIGH)
		{
			SDL_ShowCursor(SDL_DISABLE); //don't show cursor
			gameState = mGame.showHighScores();
		}
		else if (gameState == STATE_OPTS)
		{
			SDL_ShowCursor(SDL_ENABLE);
			gameState = optionMenu.show();
			if (gameState == 0)
				gameState = 3; //keep STATE_OPTS
			else if (gameState == 1)
			{
				gameState = 3; //keep STATE_OPTS
			}
			else if (gameState == 2)
			{
				gameState = 3; //keep STATE_OPTS
			}
			else if (gameState == 3)
				gameState = STATE_MENU; //goto STATE_MENU
		}
		else if (gameState == STATE_EXIT)
			quit = true;
		if ((SDL_GetTicks()-time) < 1000/60) //frame rate: 60
			SDL_Delay((1000/60)-(SDL_GetTicks()-time));
	}

	mGame.showCredits();

	close();

	system("pause");
}
*/