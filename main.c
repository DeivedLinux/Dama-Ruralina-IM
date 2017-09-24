#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game.h"
#include <stdbool.h>


int main(int argc, char *argv[])
{
	ObjGame game;
	static Mode mode;
	bool isRunning = true;


	game = newGame("Tabuleiro.png","PeaoOne.png","PeaoTwo.png");

    while(isRunning)
    {
    	isRunning = game->Run(game,mode);
    }

	return 0;
}