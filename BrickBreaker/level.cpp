/*
#include <sstream>
#include <string>
#include <fstream>

#include "SDL.h"
#include "SDL_ttf.h"

#include "game.h"
#include "resource.h"
#include "level.h"
#include "menu.h"

game::game()
{
	lives = 3;

	//load files
	std::ifstream file;
	file.open("levels.txt");
	if (!file)
		error("Couldn't open levels.txt");

	int numLvls;
	file >> numLvls;

	for (int lvls = 0; lvls < numLvls; lvls++) //for each level
	{
		std::string levelName;
		int numBalls;
		int bgColor;
		int levelArray[11][6];
		
		file >> levelName;
		file >> numBalls;
		file >> bgColor;

		for (int y = 0; y < 11; y++)
			for (int x = 0; x < 6; x++)
				file >> levelArray[y][x];
		levels.push_back(level(levelArray, numBalls, bgColor, levelName));
	}
	file.close();

	livesClip.x = 329; //clip for the life sprite
	livesClip.y = 66;
	livesClip.w = 30;
	livesClip.h = 11;

	lvl = 0; //start at level 0

	file.open("highScores.dat", std::ios::in | std::ios::binary);
	if (!file)
	{
		for (int x = 0; x < 3; x++)
			highScores[x] = 0;
		for (int x = 0; x < 3; x++)
			names[x] = "PaddleKing!";
	}
	else
	{
		file.read((char*) &highScores, sizeof(highScores));
		file.read((char*) &names, sizeof(names));
	}
	file.close();
}

game::~game()
{
	//save high scores
	std::ofstream file;
	file.open("highScores.dat", std::ios::out | std::ios::binary);
	file.write((char*) &highScores, sizeof(highScores));
	file.write((char*) &names, sizeof(names));
	file.close();
}

int game::gameLoop()
{
	while(SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			return 4; //return STATE_EXIT
		}
		else if (event.type == SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				return 0; //return STATE_MENU
			}
		}
		levels[lvl].update(event);
	}

	levels[lvl].draw();

	printText(515, 350, "Lives:", 0, 255, 255);
	for(int x = 0; x < lives; x++)
		if (x < 4)
			blit(475+x*40, 400, tiles, screen, &livesClip); //first line
		else
			blit(475+(x-4)*40, 425, tiles, screen, &livesClip); //second line

	printText(515, 200, "Score:", 0, 255, 255);

	//convert score to a string and output it
	std::stringstream out;
	std::string SScore;
	out << score;
	SScore = out.str();
	printText(515, 230, SScore, 0, 255, 255);

	if (levels[lvl].empty())
	{	
		score += 100;
		if ((lvl+1)%5 == 0 && lives < 9)
			lives++; //every 5 levels the player earns a life!

		if (lvl < levels.size()-1) //next level
		{
			lvl++;
		}
		else //go to first level
		{
			lvl = 0;
			for (unsigned int x = 0; x < levels.size(); x++)
				levels[x].reset();
		}
	}

	if (levels[lvl].dead())
	{
		lives--;
		if (lives == 0)
		{
			int ret = gameOver();
			if (ret)
				return ret;

			//reset variables
			lvl = 0;
			score = 0;
			lives = 3;
			for (unsigned int x = 0; x < levels.size(); x++)
				levels[x].reset();
		}
	}

	SDL_Flip(screen);
	return 1;
}

int game::gameOver()
{
	SDL_EnableUNICODE(SDL_ENABLE);

	int highScoreRank = 0;
	std::string name = "";
	Uint32 time = SDL_GetTicks(); //to maintain fps

	//make background
	SDL_Surface *back = loadImage("menuBack.png");

	//update scores
	if (score > highScores[0])
	{
		highScores[2] = highScores[1];
		highScores[1] = highScores[0];
		highScores[0] = score;
		highScoreRank = 1;
	} 
	else if (score > highScores[1])
	{
		highScores[2] = highScores[1];
		highScores[1] = score;
		highScoreRank = 2;
	} 
	else if (score > highScores[2])
	{
		highScores[2] = score;
		highScoreRank = 3;
	}

	if (highScoreRank) //if player got a highScore
	{
		while (1)
		{
			//get input
			while(SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					return 4; //return STATE_EXIT
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_RETURN)
					{
						if (highScoreRank == 1)
						{
							names[2] = names[1];
							names[1] = names[0];
							names[0] = name;
						}
						else if (highScoreRank == 2)
						{
							names[2] = names[1];
							names[1] = name;
						}
						else if (highScoreRank == 3)
						{
							names[2] = name;
						}
						return 0; //return
					}
					if (name.length() < 16) //limit size of name
					{
						if(event.key.keysym.unicode == (Uint16)' ') //space key
						{
							name += (char)event.key.keysym.unicode; //add to string
						}
						else if(event.key.keysym.unicode >= (Uint16)'0' &&
								event.key.keysym.unicode <= (Uint16)'9') //numbers
						{
							name += (char)event.key.keysym.unicode; //add to string
						}
						else if(event.key.keysym.unicode >= (Uint16)'A' &&
								event.key.keysym.unicode <= (Uint16)'Z') //Uppercase letters
						{
							name += (char)event.key.keysym.unicode; //add to string
						}
						else if(event.key.keysym.unicode >= (Uint16)'a' &&
								event.key.keysym.unicode <= (Uint16)'z') //Lowercase letters
						{
							name += (char)event.key.keysym.unicode; //add to string
						}
					}
					if (event.key.keysym.sym == SDLK_BACKSPACE && !name.empty())
						name.erase(name.length()-1);
				}
			}

			blit(0, 0, back, screen);

			printText(225, 10, "Congratulations!", 0, 0, 255);
			printText(150, 110, "You have a new high score!", 0, 255, 0);
			printText(100, 210, "Enter name: ", 0, 255, 0);
			if (!name.empty())
				printText(255, 210, name, 0, 255, 0);

			SDL_Flip(screen);
			if ((SDL_GetTicks()-time) < 1000/60) //frame rate: 60
				SDL_Delay((1000/60)-(SDL_GetTicks()-time));
		}
	}
	else //not a high score
	{
		blit(0, 0, back, screen);

		printText(250, 10, "GAME OVER!", 0, 0, 255);
		printText(175, 110, "Good luck next time!", 0, 255, 0);

		printText(175, 410, "Press ESC to Return", 0, 255, 0);

		SDL_Flip(screen);
		while (1)
		{
			//get input
			while(SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					return 4; //return STATE_EXIT
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						return 0; //return
					}
				}
			}			
		}
	}

	return 0;

	SDL_FreeSurface(back);
	SDL_EnableUNICODE(SDL_DISABLE);
}

int game::showHighScores()
{
	//make and show background
	SDL_Surface *back = loadImage("data/menuBack.png");
	blit(0, 0, back, screen);
	SDL_FreeSurface(back);

	printText(225, 10, "High Scores:", 0, 0, 255);

	//for each high score: turn it into a string and output it
	for (int x = 0; x < 3; x++)
	{
		std::stringstream out;
		std::string highScore;
		out << highScores[x];
		highScore = names[x] + ": " + out.str();
		printText(225, 10+100*(x+1), highScore, 0, 255, 255);
	}
	
	printText(185, 410, "Press ESC to Return", 0, 255, 0);

	SDL_Flip(screen);
	while (1)
	{
		//get input
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return 4; //return STATE_EXIT
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					return 0; //return STATE_MENU
				}
			}
		}
	}
}

void game::showCredits()
{
	//make and show background
	SDL_Surface *back = loadImage("menuBack.png");
	blit(0, 0, back, screen);
	SDL_FreeSurface(back);

	printText(250, 10, "Credits:", 0, 0, 255);	
	printText(200, 70, "Programming: Corrob", 0, 255, 0);
	printText(185, 130, "Graphics: SpriteLib GPL", 0, 255, 0);
	printText(220, 180, "Music: Corrob", 0, 255, 0);
	printText(215, 240, "Sound Effects:", 0, 255, 0);
	printText(200, 300, "SimplytheBest.net", 0, 255, 0);
	printText(230, 360, "ESC to Exit", 0, 255, 255);

	SDL_Flip(screen);
	while (1)
	{
		//get input
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					return;
				}
			}
		}
	}
}

*/