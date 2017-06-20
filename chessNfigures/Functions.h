#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "Constants.h"

class Functions
{

SDL_Window * gWindow = NULL;
SDL_Renderer * gRenderer = NULL;
SDL_Texture * boardTexture = NULL;
SDL_Texture * figuresTexture = NULL;

SDL_Rect chessButtons[8][8];
std::vector <SDL_Rect> figures;

enum FigureSprites
{
	BLACK_ROOK,
	BLACK_BISHOP,
	BLACK_QUEEN,
	BLACK_KING,
	BLACK_KNIGHT,
	BLACK_PAWN,
	WHITE_ROOK,
	WHITE_BISHOP,
	WHITE_QUEEN,
	WHITE_KING,
	WHITE_KNIGHT,
	WHITE_PAWN
};


void init()
{
	SDL_Init(SDL_INIT_VIDEO);


	gWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);


	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);


	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}


SDL_Texture * loadTexture(std::string path)
{

	SDL_Surface * loadedSurface = IMG_Load(path.c_str());


	SDL_Texture * loadedTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);


	SDL_FreeSurface(loadedSurface);

	return loadedTexture;
}

void loadMedia()
{
	boardTexture = loadTexture("ChessBoard.png");
	figuresTexture = loadTexture("chess-figures.png");
}

void cropFigures()
{
	SDL_Rect tempRect = {0, 0, FIGURE_WIDTH, FIGURE_HEIGHT};
	for (int i = 0; i < 2; i++)
	{
		tempRect.x = 0;
		for (int j = 0; j < 6; j++)
		{
			figures.push_back(tempRect);
			tempRect.x += FIGURE_WIDTH;
		}
		tempRect.y += FIGURE_HEIGHT;
	}

}

void setFigures()
{
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_ROOK], &chessButtons[0][0]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_KNIGHT], &chessButtons[0][1]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_BISHOP], &chessButtons[0][2]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_QUEEN], &chessButtons[0][3]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_KING], &chessButtons[0][4]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_BISHOP], &chessButtons[0][5]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_KNIGHT], &chessButtons[0][6]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_ROOK], &chessButtons[0][7]);

	for (int i = 0; i < 8; i++)
	{
		SDL_RenderCopy(gRenderer, figuresTexture, &figures[BLACK_PAWN], &chessButtons[1][i]);
	}

	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_ROOK], &chessButtons[7][0]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_KNIGHT], &chessButtons[7][1]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_BISHOP], &chessButtons[7][2]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_QUEEN], &chessButtons[7][3]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_KING], &chessButtons[7][4]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_BISHOP], &chessButtons[7][5]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_KNIGHT], &chessButtons[7][6]);
	SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_ROOK], &chessButtons[7][7]);

	for (int i = 0; i < 8; i++)
	{
		SDL_RenderCopy(gRenderer, figuresTexture, &figures[WHITE_PAWN], &chessButtons[6][i]);
	}
}

void cropChessPositions()
{
	SDL_Rect tempRect = {0, 0, CHESSB_WIDTH, CHESSB_HEIGHT};
	for (int i = 0; i < 8; i++)
	{
		tempRect.x = 0;
		for (int j = 0; j < 8; j++)
		{
			chessButtons[i][j] = tempRect;
			tempRect.x += CHESSB_WIDTH;
		}
		tempRect.y += CHESSB_HEIGHT;
	}
}

};

#endif
