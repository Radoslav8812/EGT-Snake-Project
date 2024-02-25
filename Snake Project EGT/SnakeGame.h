#pragma once
#include "Music.h"

#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <deque>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
const int ROWS = 40;
const int COLS = 60;
const int TILE_SIZE = 24;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
enum GameState {
    GAME_INITIAL,
    GAME_RUNNING,
    GAME_PAUSED,
    GAME_OVER,
    GAME_INACTIVE
    
};
enum ButtonState {
    BTN_ACTIVE,
    BTN_INACTIVE,
    BTN_PRESSED
};
struct Snake {
    int row;
    int col;
    Direction direction;
};

class SnakeGame {

private:
    GameState gameState;
    GameState prevGameState;
    ButtonState btnsState;
    Direction lastDirection;

    Snake snake; 
    deque <pair<int, int>> bodyQue;
    vector <pair<int, int>> fruitsVect; 
    
    int fruitRow;
    int fruitCol;
    int fruitsEaten;
    int points;
    int initialDelay;
    int pointFieldX;
    int pointFieldY;

    bool startedMoving;
    bool isPause;
    bool isGameRunning;
    bool inInfoMode;
    
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
    SDL_Texture* infoRulesTexture;
    SDL_Texture* backgroundTexture;
    SDL_Texture* buttonsBackgroundTexture;
    SDL_Texture* snakeFruitTexture;
    
    SDL_Rect rectBGR;
    SDL_Rect drectBGR;
    SDL_Rect rectRules;
    SDL_Rect dRectRules;

    void controller();
    void update();
    void render();
    bool checkCollision();
    bool isOppositeDirection(Direction d1, Direction d2);
    bool isFruitOnSnakeBodyOrAnotherFruit(int row, int col);
    bool isPaused();
    void togglePause();
    void initBackgroundMusic();
    void renderButtons();
    void InitStartingParameters();
    void renderText(const char* text, int x, int y, SDL_Color textColor);
    SDL_Texture* renderBackground(const char* path);
  
public:
    SnakeGame();
    ~SnakeGame();

    void run();
};