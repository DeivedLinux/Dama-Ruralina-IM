#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Part
{
	SDL_Surface* icon;
	SDL_Rect rect;
}*ObjPart;

static SDL_Surface* iconPlayOne = NULL; 
static SDL_Surface* iconPlayTwo = NULL;
SDL_Surface* screenSurface = NULL;

static ObjPart newPart(int x, int y, SDL_Surface* icon);
static bool RunGame(struct Game* game, Mode mode, ObjPlay playOne, ObjPlay playTwo);
static bool movementIsValid(ObjPlay playOne, ObjPlay playTwo);


ObjGame newGame(const char* _background, const char* _iconPlayOne, const char* _iconPlayTwo)
{
	ObjGame game = NULL;

	game = (ObjGame)malloc(sizeof(struct Game));

	game->background = IMG_Load(_background);;
	game->time = 0;
	game->Run = RunGame;
	iconPlayOne = IMG_Load(_iconPlayOne);
	iconPlayTwo = IMG_Load(_iconPlayTwo);

    return game;
}

ObjPlay newPlay(void)
{
	ObjPlay play = NULL;

	play = (ObjPlay)malloc(sizeof(struct Play));

	play->parts = newArrayList();
	play->totalParts = 0;
	play->points = 0;

	return play;
}

void destroyGame(ObjGame game, ObjPlay playOne, ObjPlay playTwo)
{
	SDL_FreeSurface(game->background);
	free(game);
	SDL_FreeSurface(iconPlayTwo);
	SDL_FreeSurface(iconPlayOne);
	playTwo->parts->destroyList(&playTwo->parts->list);
	playOne->parts->destroyList(&playOne->parts->list);
	free(playOne);
	free(playTwo);
}

static ObjPart newPart(int x, int y, SDL_Surface* icon)
{
	ObjPart part;

	part = (ObjPart)malloc(sizeof(struct Part));
	part->rect.x = x;
	part->rect.y = y;
	part->rect.w = 100;
	part->rect.h = 100;
	part->icon = icon;

	return icon;
}

void initPlays(ObjPlay playOne, ObjPlay playTwo)
{
	unsigned i,index = 0;
	ObjPart part;
	unsigned linesCounter = 0;
	ObjPart plays[2];
	SDL_Surface* icons[2];

	plays[0] = playOne;
	plays[1] = playTwo;

	icons[0] = iconPlayOne;
	icons[1] = iconPlayTwo;


    while(linesCounter < 7)
    {
		for(i = 0; i < 4; i++)
		{
			part = newPart(1+i*100, linesCounter*100,icons[index]);
			plays[index]->parts->addArray(part, &plays[index]->parts->list);
		}

		linesCounter += 1;

		if(linesCounter == 3u)
		{
			linesCounter += 2;
			index += 1;
		}

		for(i = 0; i < 4; i++)
		{
			part = newPart(1+i*100, linesCounter*100,icons[index]);
			plays[index]->parts->addArray(part, &plays[index]->parts->list);
		}
		linesCounter += 1;
	}
	
}

static bool RunGame(struct Game* game, Mode mode, ObjPlay playOne, ObjPlay playTwo)
{
	
	SDL_Event event;

    
	SDL_BlitSurface(game->background,NULL,screenSurface,NULL); 

	return true;
}
