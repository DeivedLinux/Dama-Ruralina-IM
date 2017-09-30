#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef enum
{
	Peao,
	Dama
}PartType;

typedef struct Part
{
	SDL_Surface* icon;
	SDL_Rect rect;
}*ObjPart;

static const SDL_Surface* iconPlayOne = NULL; 
static const SDL_Surface* iconPlayTwo = NULL;
SDL_Surface* screenSurface = NULL;

static ObjPart newPart(int x, int y, SDL_Surface* icon);
static bool RunGame(struct Game* game, Mode mode, ObjPlay playOne, ObjPlay playTwo);
static bool movementIsValid(ObjPlay playOne, ObjPlay playTwo);
static void updateSurface(ObjPlay playOne, ObjPlay playTwo, struct Game* game);

ObjGame newGame(const char* _background, const char* _iconPlayOne, const char* _iconPlayTwo)
{
	ObjGame game = NULL;

	game = (ObjGame)malloc(sizeof(struct Game));

	game->background = IMG_Load(_background);
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
	part->rect.w = 85+part->rect.x;
	part->rect.h = 85+part->rect.y;
	part->icon = icon;

	return part;
}

void initPlays(ObjPlay playOne, ObjPlay playTwo)
{
	unsigned i,index = 0;
	ObjPart part;
	unsigned linesCounter = 0;
	ObjPlay plays[2];
	SDL_Surface* icons[2];

	plays[0] = playOne;
	plays[1] = playTwo;

	icons[0] = iconPlayOne;
	icons[1] = iconPlayTwo;

    while(linesCounter <= 7)
    {
		for(i = 88; i < 800; i += 175)
		{
			part = newPart(i, linesCounter*87.5f,icons[index]);
			plays[index]->parts->addArray(part, &plays[index]->parts->list);
		}

		linesCounter += 1;

		if(linesCounter == 3u)
		{
			linesCounter += 2;
			index += 1;
		}

		for(i = 0; i < 715; i += 175)
		{
			part = newPart(i, linesCounter*87.5,icons[index]);
			plays[index]->parts->addArray(part, &plays[index]->parts->list);
		}
		linesCounter += 1;
	}
}

static void updateSurface(ObjPlay playOne, ObjPlay playTwo, struct Game* game)
{
	List* list;

	for(list = playOne->parts->list; list != NULL; list = list->next)
	{
		SDL_BlitSurface((((ObjPart)(list->information))->icon), NULL,game->background, 
			           &(((ObjPart)(list->information))->rect)); 

	}
    
	for(list = playTwo->parts->list; list != NULL; list = list->next)
	{
		SDL_BlitSurface((((ObjPart)(list->information))->icon), NULL,game->background, 
			           &(((ObjPart)(list->information))->rect)); 
	}
}

static bool RunGame(struct Game* game, Mode mode, ObjPlay playOne, ObjPlay playTwo)
{
	
	SDL_Event event;
	
	while(SDL_PollEvent(&event) != 0 )
    {
        if(event.type == SDL_Quit)
        {
        
        }
        
        switch(event.type)
        {
            case SDL_KEYDOWN:
                
                switch(event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:

                    return false;

                    break;
                    
                    case SDLK_RETURN:
                           
                    break;
                }
            break;
        }     
    }
    
    updateSurface(playOne, playTwo, game);
	SDL_BlitSurface(game->background,NULL,screenSurface,NULL); 
	
	return true;
}
