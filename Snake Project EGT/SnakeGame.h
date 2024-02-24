#pragma once


#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <deque>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

#include "Music.h"


using namespace std;

const int ROWS = 40;
const int COLS = 60;
const int TILE_SIZE = 20;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Snake {
    int row;
    int col;
    Direction direction;
};

class SnakeGame {

private:

    Direction lastDirection;
    Snake snake; 
    deque <pair<int, int>> bodyQue;
    vector <pair<int, int>> fruitsVect; 
    vector<pair<int, int>> fruitsPositions;  

    int fruitRow;
    int fruitCol;
    int fruitsEaten;
    int points;
    int initialDelay;

    bool startedMoving;
    bool isPause;
    bool isGameRunning;
    bool inInfoMode;

    void controller();
    void update();
    void render();
    bool checkCollision();
    void displayGameOver();
    bool isOppositeDirection(Direction d1, Direction d2);
    bool isFruitOnSnakeBody(int row, int col);
    
    Music soundManager;
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Rect startButtonRect;
    SDL_Rect infoButtonRect;
    TTF_Font* font;
    SDL_Color textColor;
    SDL_Surface* startTextSurface;
    SDL_Surface* infoTextSurface;
    SDL_Texture* startTextTexture;
    SDL_Texture* infoTextTexture;
    SDL_Texture* infoTexture;
  
    void renderText(const char* text, int x, int y, SDL_Color textColor);

public:
    SnakeGame();
    ~SnakeGame();

    bool isPaused() const;

    void togglePause();

    void initBackgroundMusic();

    void renderButtons();

    void run();
};