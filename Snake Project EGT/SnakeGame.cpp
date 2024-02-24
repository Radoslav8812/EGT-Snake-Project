#include "SnakeGame.h"
#include "Music.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int startButtonClickTime = 0;
bool startButtonClicked = false;

int infoButtonClickTime = 0;
bool infoButtonClicked = false;

int initialSpeed = 100;

SnakeGame::SnakeGame() {

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	initBackgroundMusic();

	fruitsEaten = 0;
	points = 0;
	
	isPause = false;
	startedMoving = false;
	isGameRunning = false;
	inInfoMode = false;
													 // +400 space for buttons
	window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, COLS * TILE_SIZE + 400, ROWS * TILE_SIZE, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	snake.row = ROWS / 2;
	snake.col = COLS / 2;
	snake.direction = RIGHT;

	srand(time(nullptr));

	fruitRow = rand() % ROWS;
	fruitCol = rand() % COLS;
	fruitsVect.push_back(make_pair(fruitRow, fruitCol));

	bodyQue.push_front(make_pair(snake.row, snake.col));
	lastDirection = RIGHT;

	int buttonAreaCenterX = COLS * TILE_SIZE + 200;
	int buttonAreaCenterY = ROWS * TILE_SIZE / 2;
	int buttonWidth = 300;
	int buttonHeight = 150;

	int startButtonX = buttonAreaCenterX - buttonWidth / 2;
	int startButtonY = buttonAreaCenterY - buttonHeight / 2 - 150;
	startButtonRect = { startButtonX, startButtonY, buttonWidth, buttonHeight };

	int infoButtonX = buttonAreaCenterX - buttonWidth / 2;
	int infoButtonY = buttonAreaCenterY - buttonHeight / 2 + 150;  
	infoButtonRect = { infoButtonX, infoButtonY, buttonWidth, buttonHeight };

	font = TTF_OpenFont("C:/Users/User/Desktop/fonts/ariblk.ttf", 50); 

	startTextSurface = TTF_RenderText_Blended(font, "Start", textColor);
	infoTextSurface = TTF_RenderText_Blended(font, "Game Info", textColor);

	startTextTexture = SDL_CreateTextureFromSurface(renderer, startTextSurface);
	infoTextTexture = SDL_CreateTextureFromSurface(renderer, infoTextSurface);

	SDL_FreeSurface(startTextSurface);
	SDL_FreeSurface(infoTextSurface);
}

bool SnakeGame::isPaused() const {
	return isPause;
}
void SnakeGame::togglePause() {

	if (startedMoving) {
		isPause = !isPause;
	}
}

void SnakeGame::run() {

	while (true) {
		if (isGameRunning && !isPause) {
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
			//if (!isGameRunning) {
			//	/*isGameRunning = true;
			//	isPause = false;
			//	startedMoving = true;*/
			//}
			Direction newDirection = lastDirection;

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

			if (!isOppositeDirection(snake.direction, newDirection)) {
				snake.direction = newDirection;
				lastDirection = newDirection;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {

			if (e.button.button == SDL_BUTTON_LEFT) {
				int mouseX = e.button.x;
				int mouseY = e.button.y;

				if (mouseX >= startButtonRect.x && mouseX <= startButtonRect.x + startButtonRect.w && mouseY >= startButtonRect.y && mouseY <= startButtonRect.y + startButtonRect.h) {
					cout << "Start button clicked!" << endl;
					startButtonClicked = true;
					startButtonClickTime = SDL_GetTicks();
					isGameRunning = true;
					isPause = false;
					startedMoving = true;
				}
				else if (mouseX >= infoButtonRect.x && mouseX <= infoButtonRect.x + infoButtonRect.w && mouseY >= infoButtonRect.y && mouseY <= infoButtonRect.y + infoButtonRect.h) {
					cout << "Info button clicked!" << endl;
					infoButtonClicked = true;
					infoButtonClickTime = SDL_GetTicks();
					isPause = true;
				}
			}
		}
	}

	if (isGameRunning && startedMoving && !isPause) {

		bodyQue.push_front(make_pair(snake.row, snake.col));

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

bool SnakeGame::isFruitOnSnakeBody(int row, int col) {

	for (auto& segment : bodyQue) {
		if (segment.first == row && segment.second == col) {
			return true;
		}

	}
	for (auto& food : fruitsVect) {
		if (food.first == row && food.second == col) {
			return true;
		}
	}

	fruitsVect.push_back(make_pair(row, col));
	return false;
}

bool SnakeGame::isOppositeDirection(Direction d1, Direction d2) {

	return (d1 == UP && d2 == DOWN) || (d1 == DOWN && d2 == UP) || (d1 == LEFT && d2 == RIGHT) || (d1 == RIGHT && d2 == LEFT);
}

bool SnakeGame::checkCollision() {
	if (snake.row < 0 || snake.row >= ROWS || snake.col < 0 || snake.col >= COLS) {
		return true;
	}
	return false;
}

void SnakeGame::update() {

	if (checkCollision()) {
		cout << "Game Over! You collided with the wall." << endl;
		exit(0);
	}
	if (bodyQue.size() > 1) {
		for (auto it = bodyQue.begin() + 1; it != bodyQue.end(); it++) {
			if (it->first == snake.row && it->second == snake.col) {
				cout << "Collision in the body." << endl;
				exit(0);
			}
		}
	}

	bool isEaten = false;
	auto it = fruitsVect.begin();
	while (it != fruitsVect.end()) {

		if (snake.row == it->first && snake.col == it->second) {

			it = fruitsVect.erase(it);
			isEaten = true;
			bodyQue.push_front(make_pair(snake.row, snake.col));

			fruitsEaten++;
			points++;

			if (fruitsEaten % 3 == 0) {
				initialSpeed -= 3;
			}
			break;
		}
		else {

			++it;
		}
	}

	if (isEaten && fruitsVect.size() < 1) {

		int numOfFruits = rand() % 2 + 1;

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

	if (soundManager.loadMusic("C:/Users/User/Desktop/Mp3's/Stars.mp3")) {

		soundManager.play();
	}
}

void SnakeGame::renderText(const char* text, int x, int y, SDL_Color textColor) {

	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text, textColor);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}

void SnakeGame::renderButtons() {

	int currentTime = SDL_GetTicks();

	if (isGameRunning && !isPause) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	}

	SDL_RenderFillRect(renderer, &startButtonRect);
	renderText("Start", startButtonRect.x + 10, startButtonRect.y + 10, textColor);

	int infoButtonDuration = currentTime - infoButtonClickTime;
	if (infoButtonClicked && infoButtonDuration < 200) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); 
		infoButtonClicked = false;
	}

	SDL_RenderFillRect(renderer, &infoButtonRect);
	renderText("Game Info", infoButtonRect.x + 10, infoButtonRect.y + 10, textColor);
}

void SnakeGame::render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	if (inInfoMode) {
<<<<<<< HEAD
=======

>>>>>>> 14cb627732ea3a8fdec00acb35344c4ff74b9955
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
		SDL_Rect borderRect = { 0, 0, COLS * TILE_SIZE, ROWS * TILE_SIZE };
		SDL_RenderDrawRect(renderer, &borderRect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_Rect headRect = { snake.col * TILE_SIZE, snake.row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
		SDL_RenderFillRect(renderer, &headRect);

		SDL_SetRenderDrawColor(renderer, 0, 200, 0, 255);
		for (const auto& segment : bodyQue) {
			SDL_Rect bodyRect = { segment.second * TILE_SIZE, segment.first * TILE_SIZE, TILE_SIZE, TILE_SIZE };
			SDL_RenderFillRect(renderer, &bodyRect);
		}
		
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); 
		for (int i = 0; i < fruitsVect.size(); i++) {
			SDL_Rect fruitRect = { fruitsVect.at(i).second * TILE_SIZE, fruitsVect.at(i).first * TILE_SIZE, TILE_SIZE, TILE_SIZE };
			SDL_RenderFillRect(renderer, &fruitRect);
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_Rect buttonAreaRect = { COLS * TILE_SIZE, 0, 400, ROWS * TILE_SIZE };
		SDL_RenderFillRect(renderer, &buttonAreaRect);

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		SDL_Rect buttonAreaBorderRect = { COLS * TILE_SIZE, 0, 400, ROWS * TILE_SIZE };
		SDL_RenderDrawRect(renderer, &buttonAreaBorderRect);
   
		renderButtons();
		
		SDL_Color greenColor = { 0, 255, 0, 255 };
		string pointsText = "Points: " + to_string(fruitsEaten);

		SDL_Surface* pointsSurface = TTF_RenderText_Blended(font, pointsText.c_str(), greenColor);
		SDL_Texture* pointsTexture = SDL_CreateTextureFromSurface(renderer, pointsSurface);

		SDL_Rect pointsRect = { COLS * TILE_SIZE + 10, 10, pointsSurface->w, pointsSurface->h };

		SDL_RenderCopy(renderer, pointsTexture, NULL, &pointsRect);
<<<<<<< HEAD
=======

		SDL_Rect pointsRect = { COLS * TILE_SIZE + 10, 10, pointsSurface->w, pointsSurface->h }; 

		SDL_RenderCopy(renderer, pointsTexture, NULL, &pointsRect);

>>>>>>> 14cb627732ea3a8fdec00acb35344c4ff74b9955

		SDL_FreeSurface(pointsSurface);
		SDL_DestroyTexture(pointsTexture);
	}
	SDL_RenderPresent(renderer);
}
SnakeGame::~SnakeGame() {
	SDL_DestroyRenderer(renderer);
<<<<<<< HEAD
	SDL_DestroyWindow(window);
	
	SDL_Quit();
}
=======
	SDL_DestroyWindow(window);	
	SDL_Quit();
	SDL_DestroyTexture(infoTexture);
	SDL_Quit();
}

>>>>>>> 14cb627732ea3a8fdec00acb35344c4ff74b9955
