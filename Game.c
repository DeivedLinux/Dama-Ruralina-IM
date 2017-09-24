#include "Game.h"
#include <stdio.h>


typedef struct Part
{
	SDL_Surface* icon;
	int x; 
	int y;
}*ObjPart;

static SDL_Surface* iconPlayOne = NULL; 
static SDL_Surface* iconPlayTwo = NULL;

static ObjPart newPart(int x, int y, SDL_Surface* icon);
static bool RunGame(struct Game* game, Mode mode);
static bool movementIsValid(ObjPlay playOne, ObjPlay playTwo);


ObjGame newGame(const char* background, const char* iconPlayOne, const char* iconPlayTwo)
{
	
}