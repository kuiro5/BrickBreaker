

/*#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include <iostream>
#include <fstream>

#include "resource.h"

SDL_Surface *loadImage(std::string filename) //Thank you Lazy Foo
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str()); 
    if (loadedImage != NULL) //convert format for faster blitting
    {
        optimizedImage = SDL_DisplayFormat(loadedImage); 
        SDL_FreeSurface(loadedImage);
		if (optimizedImage != NULL) //allows for transperancy
		{
			Uint32 colorkey = SDL_MapRGB(optimizedImage->format, 0xFF, 0, 0xFF);
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
		}
    }
	else
	{
		error("Couldn't open " + filename);
	}
    return optimizedImage;
}

void blit(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip)
//thanks again Lazy Foo
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(source, clip, destination, &offset);
}

void printText(int x, int y, std::string words, int r, int g, int b)
{
	SDL_Color color = {r, g, b};
	message = TTF_RenderText_Solid(font, words.c_str(), color);
	blit(x, y, message, screen);
	SDL_FreeSurface(message);
}

bool init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) { return false; } //initialize and check for errors
	screen = SDL_SetVideoMode(640, 512, 32, SDL_SWSURFACE);
	if (screen == NULL) { return false; } //check for errors
	if( TTF_Init() == -1 ) { return false; } 
	SDL_WM_SetCaption("Paddle Bang!", NULL); 	
	SDL_Surface *icon = loadImage("data/icon.png");
	SDL_WM_SetIcon(icon, NULL);
	SDL_FreeSurface(icon);
	return true; //everything worked right
}

void close()
{
	//clean up!
	if (tiles != NULL)
		SDL_FreeSurface(tiles);
	if (font != NULL)
		TTF_CloseFont(font); 

	TTF_Quit(); 
	SDL_Quit();
}

int error(std::string err) //report errors into a file and exit
{
	std::ofstream file;
	file.open("errorlog.txt", std::ios::out | std::ios::trunc);
	file << err;
	file << "\nPlease redownload Paddle Bang!";
	file.close();
	close();
	return 0;
}
*/