#ifndef GAME_H_
#define GAME_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "ArrayList.h"
#include <stdbool.h>


typedef enum 
{
	SINGLE_PLAY,
	MULT_PLAY
}Mode;

typedef struct Play
{
	ArrayList* parts;
	unsigned totalParts;
	int points;	
}*ObjPlay;

typedef struct Game
{
	SDL_Surface* background;
	unsigned time;
	bool(*Run)(struct Game*, Mode);
}*ObjGame;

ObjGame newGame(const char* background, const char* iconPlayOne, const char* iconPlayTwo);


#endif