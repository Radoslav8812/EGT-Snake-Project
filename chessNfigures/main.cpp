#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Functions.h"
#include "Constants.h"

using namespace std;

int main(int argc, char *argv[])
{
	init();

	loadMedia();

	SDL_RenderClear(gRenderer);

	bool quit = false;
	SDL_Event e;

	SDL_RenderCopy(gRenderer, boardTexture, NULL, NULL);

	cropFigures();
	cropChessPositions();

	setFigures();

	while(!quit)
	{
		while(SDL_PollEvent(&e)!=0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_RenderPresent(gRenderer);
	}
	return 0;
}
