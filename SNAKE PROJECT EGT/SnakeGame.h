#pragma once

#include <deque>
#include <SDL.h>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

const int ROWS = 40;
const int COLS = 60;
const int TILE_SIZE = 20;
const int SPEED_INCREASE_THRESHOLD = 3; // Increase speed every 3 fruits

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

    deque<pair<int, int>> body; // body

    vector < pair<int, int>> fruitsVect; // fruits
    int fruitRow;
    int fruitCol;
    int fruitsEaten;
    bool startedMoving;
    int initialDelay;
    bool isPause;
    int speed;
    

    SDL_Window* window;
    SDL_Renderer* renderer;

    void controller();
    void update();
    void render();
    bool checkCollision();
    bool isOppositeDirection(Direction dir1, Direction dir2);
    void checkForPauseBtn();
    //void spawnAdditionalFruit();
    bool isFruitOnSnakeBody(int row , int col);
    vector<pair<int, int>> fruitsPositions;

public:
    SnakeGame();
    ~SnakeGame();

    void run();
};