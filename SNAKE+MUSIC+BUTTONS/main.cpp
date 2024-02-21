#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
#include "SnakeGame.h"

using namespace std;

int main(int argc, char* argv[]) {
    
    SnakeGame game;
    game.run();

    return 0;
}