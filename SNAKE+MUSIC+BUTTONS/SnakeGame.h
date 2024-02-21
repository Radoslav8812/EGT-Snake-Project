#pragma once

#include <deque>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <string>
#include <iostream>
#include <vector>
#include <iterator>

#include "Music.h"


using namespace std;

const int ROWS = 40;
const int COLS = 40;
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
    deque <pair<int, int>> bodyQue; // body
    vector <pair<int, int>> fruitsVect; // fruits

    int fruitRow;
    int fruitCol;
    int fruitsEaten;
    int points;
    bool startedMoving;
    int initialDelay;
    int speed;
    bool isPause;

    SDL_Window* window;
    SDL_Renderer* renderer;

    void controller();
    void update();
    void render();
    bool checkCollision();
    bool isOppositeDirection(Direction dir1, Direction dir2);
    //void checkForPauseBtn();
    //void spawnAdditionalFruit();
    bool isFruitOnSnakeBody(int row, int col);
    vector<pair<int, int>> fruitsPositions;

    //music
    Music backgroundMusic;
    
    // buttons
    SDL_Rect startButtonRect;
    SDL_Rect infoButtonRect;
    bool inInfoMode;
   

    TTF_Font* font;
    SDL_Color textColor;
    SDL_Surface* startTextSurface;
    SDL_Surface* infoTextSurface;
    SDL_Texture* startTextTexture;
    SDL_Texture* infoTextTexture;
    SDL_Texture* infoTexture;

    SDL_Color redTextColor = { 255, 0, 0, 255 }; 
    // Function to render text on the screen
    void renderText(const char* text, int x, int y);

public:
    SnakeGame();
    ~SnakeGame();

    bool isPaused() const;
    void togglePause();

    void initBackgroundMusic();
    void renderButtons();
    void initCoverInfo();

    void run();
};