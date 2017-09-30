#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include <stdbool.h>

static const unsigned SCREEN_WIDTH = 700;
static const unsigned SCREEN_HEIGHT = 700;


int main(int argc, char *argv[])
{
	ObjGame game;
	static Mode mode;
	bool isRunning = true;
	SDL_Window* window = NULL;
	ObjPlay playOne;
	ObjPlay playTwo;
	unsigned long long start;

	if(SDL_Init(SDL_INIT_VIDEO))
	{
		puts("falha ao iniciar sdl");
		exit(1);
	}
	else
	{
		window = SDL_CreateWindow("Dama Ruralina",SDL_WINDOWPOS_UNDEFINED, 
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, 
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN); 
		if(window == NULL)
		{
			printf("Error %i\n",SDL_GetError());
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
		}
	}

	IMG_Init(IMG_INIT_PNG);

	game = newGame("Tabuleiro.png","PeaoOne.v1.png","PeaoTwo.v1.png");
    loadSelectImg("PeaoOneSelect.v1.png", "PeaoTwoSelect.v1.png");
    
    playOne = newPlay();
    playTwo = newPlay();

    initPlays(playOne, playTwo);

    while(isRunning)
    {   
    	start = SDL_GetTicks();
    	isRunning = game->Run(game, mode, playOne, playTwo);
    	SDL_UpdateWindowSurface(window);

    	if((1000u/FPS) > (SDL_GetTicks() - start))
        	SDL_Delay((1000u/FPS) - (SDL_GetTicks() - start));
    }

    SDL_FreeSurface(screenSurface);
    SDL_DestroyWindow(window);
    destroyGame(game, playOne, playTwo);
    SDL_Quit();
  
	return 0;
}