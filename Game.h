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
	bool(*Run)(struct Game*, Mode, ObjPlay, ObjPlay);
}*ObjGame;

extern const SDL_Surface* screenSurface;
extern const unsigned FPS;

ObjGame newGame(const char* _background, const char* _iconPlayOne, const char* _iconPlayTwo);
ObjPlay newPlay(void);
void loadSelectImg(const char* _iconPlayOneSelect, const char* _iconPlayTwoSelect);
void destroyGame(ObjGame game, ObjPlay playOne, ObjPlay playTwo);
void initPlays(ObjPlay playOne, ObjPlay playTwo);

#endif