
#ifndef RESOURCE_H
#define RESOURCE_H

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>

extern SDL_Surface *screen;
extern SDL_Surface *tiles;
extern SDL_Surface *message;

extern TTF_Font *font;

extern int score;


SDL_Surface *loadImage(std::string filename);
void blit(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
void printText(int x, int y, std::string words, int r, int g, int b);
bool init();
void close();
int error(std::string err);

#endif