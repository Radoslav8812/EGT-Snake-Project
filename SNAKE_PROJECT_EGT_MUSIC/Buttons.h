#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

class Buttons {

private:

public:
	Buttons();
	~Buttons();

	SDL_Texture* buttonTexture;
	SDL_Rect srect;
	SDL_Rect drect;
	bool isSelected = false; // track mouse over the button

	
	void update(); // pass mouse by reference
};