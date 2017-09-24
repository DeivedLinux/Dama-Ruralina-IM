#include "Game.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Part
{
	SDL_Surface* icon;
	int x; 
	int y;
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

	game->background = SDL_LoadBMP(_background);
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

static bool RunGame(struct Game* game, Mode mode, ObjPlay playOne, ObjPlay playTwo)
{
	
	SDL_Event event;

    
	SDL_BlitSurface(game->background,NULL,screenSurface,NULL); 

	return true;
}
