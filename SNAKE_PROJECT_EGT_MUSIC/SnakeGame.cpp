#include "SnakeGame.h"
#include "Music.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float initialSpeed = 200;

SnakeGame::SnakeGame()  {

	fruitsEaten = 0;
	isPause = false;
	startedMoving = false;
	speed = 1;

	SDL_Init(SDL_INIT_VIDEO);
	initBackgroundMusic();
	                                                                                                // +400 space for buttons
	window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, COLS * TILE_SIZE + 400, ROWS * TILE_SIZE, SDL_WINDOW_SHOWN);
	//window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Initialize the snake
	snake.row = ROWS / 2;
	snake.col = COLS / 2;
	snake.direction = RIGHT;

	// Initialize the fruit position
	srand(time(nullptr));

	fruitRow = rand() % ROWS;
	fruitCol = rand() % COLS;
	fruitsVect.push_back(make_pair(fruitRow, fruitCol));

	bodyQue.push_front(make_pair(snake.row, snake.col));
	lastDirection = RIGHT;
}

SnakeGame::~SnakeGame() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void SnakeGame::run() {

	while (true) {

		if (!isPause) {
			update();
		}
		controller();
		render();
		SDL_Delay(initialSpeed);
	}
}

void SnakeGame::controller() {

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			exit(0);
		}
		else if (e.type == SDL_KEYDOWN) {
			startedMoving = true;

			Direction newDirection = lastDirection; // Default to the last direction

			if (e.key.keysym.sym == SDLK_UP && snake.direction != DOWN) {
				newDirection = UP;
			}
			else if (e.key.keysym.sym == SDLK_DOWN && snake.direction != UP) {
				newDirection = DOWN;
			}
			else if (e.key.keysym.sym == SDLK_LEFT && snake.direction != RIGHT) {
				newDirection = LEFT;
			}
			else if (e.key.keysym.sym == SDLK_RIGHT && snake.direction != LEFT) {
				newDirection = RIGHT;
			}
			else if (e.key.keysym.sym == SDLK_RIGHT && snake.direction != LEFT) {
				newDirection = RIGHT;
			}
			// Check if the new direction is not opposite to the last direction
			if (!isOppositeDirection(snake.direction, newDirection)) {
				snake.direction = newDirection;
				lastDirection = newDirection;
			}
		}

		if (e.button.button == SDL_BUTTON_LEFT && e.type == SDL_MOUSEBUTTONUP) {	
			cout << "paused" << endl;
			isPause = !isPause;
		}
	}
	if (startedMoving && !isPause) {
		// Save the current head position to the body deque
		bodyQue.push_front(make_pair(snake.row, snake.col));

		// Move the head based on the direction
		if (snake.direction == UP && snake.row > 0) {
			snake.row--;	
		}
		else if (snake.direction == DOWN && snake.row < ROWS - 1) {
			snake.row++;
		}
		else if (snake.direction == LEFT && snake.col > 0) {
			snake.col--;
		}
		else if (snake.direction == RIGHT && snake.col < COLS - 1) {
			snake.col++;
		}		
		bodyQue.pop_back();
	}
}

bool SnakeGame::isOppositeDirection(Direction dir1, Direction dir2) {

	return (dir1 == UP && dir2 == DOWN) || (dir1 == DOWN && dir2 == UP) || (dir1 == LEFT && dir2 == RIGHT) || (dir1 == RIGHT && dir2 == LEFT);
}

bool SnakeGame::isFruitOnSnakeBody(int row, int col) {

	for (auto& segment : bodyQue) { // is on snake

		if (segment.first == row && segment.second == col) {
			return true;
		}

	}
	for (auto& food : fruitsVect) {  // is on other food

		if (food.first == row && food.second == col) {
			return true;
		}
	}

	fruitsVect.push_back(make_pair(row, col));
	return false;
}

bool SnakeGame::checkCollision() {
	return snake.row < 0 || snake.row >= ROWS || snake.col < 0 || snake.col >= COLS;
}

void SnakeGame::update() {

	if (checkCollision()) {
		cout << "Game Over! You collided with the wall." << std::endl;
		exit(0);
	}
	// Check if the snake hits its own body
	if (bodyQue.size() > 1) {

		for (auto it = bodyQue.begin() + 1; it != bodyQue.end(); it++) {

			if (it->first == snake.row && it->second == snake.col) {
				cout << "Collision in the body." << endl;
				exit(0);
			}
		}
	}

	bool activateOR = false;
	auto it = fruitsVect.begin();
	while (it != fruitsVect.end()) {

		if (snake.row == it -> first && snake.col == it -> second) {

			it = fruitsVect.erase(it);
			activateOR = true;
			bodyQue.push_front(make_pair(snake.row, snake.col));

			fruitsEaten++;

			if (fruitsEaten % 3 == 0) {
				speed++;
			}
			initialSpeed -= 20;
			break;
		}
		else {

			++it;
		}
	}

	if (activateOR && fruitsVect.size() < 1) {

    	int numOfFruits = rand() % 2 + 1; // random betweem 1 - 2;

		for (int i = 0; i < numOfFruits; i++) {

			int fruitRowNew = rand() % ROWS;
			int fruitColNew = rand() % COLS;

			while (isFruitOnSnakeBody(fruitRowNew, fruitColNew)) {

				fruitRowNew = rand() % ROWS;
				fruitColNew = rand() % COLS;
			}
		}
	}
}

void SnakeGame::initBackgroundMusic() {
	
	if (backgroundMusic.loadMusic("C:/Users/User/Desktop/Mp3's/Goth.mp3")) {
		backgroundMusic.play();
	}
}

void SnakeGame::render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 
	SDL_RenderClear(renderer);

	// Draw snake 
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); 
	SDL_Rect headRect = { snake.col * TILE_SIZE, snake.row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
	SDL_RenderFillRect(renderer, &headRect);

	// Draw snake body
	SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255); // Darker green for the body
	for (const auto& segment : bodyQue) {
		SDL_Rect bodyRect = { segment.second * TILE_SIZE, segment.first * TILE_SIZE, TILE_SIZE, TILE_SIZE };
		SDL_RenderFillRect(renderer, &bodyRect);
	}

	// Draw fruit
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set fruit color to red

	for (int i = 0; i < fruitsVect.size(); i++) {

		SDL_Rect fruitRect = { fruitsVect.at(i).second * TILE_SIZE, fruitsVect.at(i).first * TILE_SIZE, TILE_SIZE, TILE_SIZE };
		SDL_RenderFillRect(renderer, &fruitRect);
	}

	SDL_RenderPresent(renderer);
}


