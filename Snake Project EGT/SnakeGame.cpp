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
int initialSpeed = 150;

SnakeGame::SnakeGame() {

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	initBackgroundMusic();
	InitStartingParameters();

	window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, COLS * TILE_SIZE + 400, ROWS * TILE_SIZE, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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
	isGameRunning = false;

	rectBGR.h = COLS * TILE_SIZE;
	rectBGR.w = COLS * TILE_SIZE;
	rectBGR.x = 0;
	rectBGR.y = 0;

	drectBGR.h = COLS * TILE_SIZE;
	drectBGR.w = COLS * TILE_SIZE;
	drectBGR.x = 0;
	rectBGR.y = 0;

	rectRules.h = COLS * TILE_SIZE;
	rectRules.w = COLS * TILE_SIZE;
	rectRules.x = 0;
	rectRules.y = 0;

	dRectRules.h = COLS * TILE_SIZE;
	dRectRules.w = COLS * TILE_SIZE;
	dRectRules.x = 0;
	dRectRules.y = 0;

	snakeFruitTexture = renderBackground("C:/Users/User/Desktop/redApple1.png");
	infoRulesTexture = renderBackground("C:/Users/User/Desktop/nnRules1.jpg");
	buttonsBackgroundTexture = renderBackground("C:/Users/User/Desktop/carb.png");
	backgroundTexture = renderBackground("C:/Users/User/Desktop/nn.jpg");
	soundManager.loadSoundEffects("C:/Users/User/Desktop/Mp3's/eatSound.wav", "C:/Users/User/Desktop/Mp3's/wallSound.mp3", "C:/Users/User/Desktop/Mp3's/click.wav");
}

bool SnakeGame::isPaused()  {
	return isPause;
}
void SnakeGame::togglePause() {

	if (startedMoving) {
		isPause = !isPause;
	}
}

bool SnakeGame::isOppositeDirection(Direction d1, Direction d2) {

	return (d1 == UP && d2 == DOWN) || (d1 == DOWN && d2 == UP) || (d1 == LEFT && d2 == RIGHT) || (d1 == RIGHT && d2 == LEFT);
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
					if (btnsState == BTN_INACTIVE) {
						return;
					}
					if (gameState == GAME_INACTIVE || prevGameState != gameState && prevGameState == GAME_INACTIVE) {
						InitStartingParameters();
					}
					btnsState = BTN_PRESSED;
					cout << "Start button clicked!" << endl;
					startButtonClicked = true;
					startButtonClickTime = SDL_GetTicks();
					isGameRunning = true;
					isPause = false;
					startedMoving = true;
					soundManager.playClickSound("C:/Users/User/Desktop/Mp3's/click.wav");
					prevGameState = gameState;
					gameState = GAME_RUNNING;
				}
				else if (mouseX >= infoButtonRect.x && mouseX <= infoButtonRect.x + infoButtonRect.w && mouseY >= infoButtonRect.y && mouseY <= infoButtonRect.y + infoButtonRect.h) {

					if (gameState != GAME_PAUSED) {
						cout << "Info button clicked!" << endl;
						infoButtonClicked = true;
						isPause = true;
						soundManager.playClickSound("C:/Users/User/Desktop/Mp3's/click.wav");
						prevGameState = gameState;
						gameState = GAME_PAUSED;
						btnsState = BTN_ACTIVE;
					}
					else {
						gameState = prevGameState;
					}
					infoButtonClickTime = SDL_GetTicks();
				}
			}
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {

			int mouseX = e.button.x;
			int mouseY = e.button.y;
			if (mouseX >= startButtonRect.x && mouseX <= startButtonRect.x + startButtonRect.w && mouseY >= startButtonRect.y && mouseY <= startButtonRect.y + startButtonRect.h) {
				if (gameState == GAME_RUNNING) {
					btnsState = BTN_INACTIVE;
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

bool SnakeGame::isFruitOnSnakeBodyOrAnotherFruit(int row, int col) {

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

bool SnakeGame::checkCollision() {

	if (snake.row <= 0 || snake.row >= ROWS - 1 || snake.col <= 0 || snake.col >= COLS - 1) {
		return true;
	}
	return false;
}

void SnakeGame::update() {

	if (checkCollision() && gameState == GAME_RUNNING) {

		cout << "Game Over! You collided with the wall." << endl;
		prevGameState = gameState;
		gameState = GAME_OVER;
	}
	else if (bodyQue.size() >= 1 && gameState == GAME_RUNNING) {

		for (auto it = bodyQue.begin() + 1; it != bodyQue.end(); it++) {
			if (it->first == snake.row && it->second == snake.col) {
				cout << "Collision in the body." << endl;
				prevGameState = gameState;
				gameState = GAME_OVER;
			}
		}
	}
	if (gameState == GAME_OVER) {

		isGameRunning = false;
		btnsState = BTN_ACTIVE;
		pointFieldX = COLS * TILE_SIZE / 2 - 100;
		pointFieldY = ROWS * TILE_SIZE / 2 + 25;
		soundManager.playCollisionSound("C:/Users/User/Desktop/Mp3's/wallSound.mp3");
		prevGameState = gameState;
		gameState = GAME_INACTIVE;
	}

	bool isEaten = false;
	auto it = fruitsVect.begin();
	while (it != fruitsVect.end()) {

		if (snake.row == it->first && snake.col == it->second) {

			it = fruitsVect.erase(it);
			isEaten = true;
			bodyQue.push_front(make_pair(snake.row, snake.col));
			soundManager.playFruitSound("C:/Users/User/Desktop/Mp3's/eatSound.wav");
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

			while (isFruitOnSnakeBodyOrAnotherFruit(fruitRowNew, fruitColNew)) {
				fruitRowNew = rand() % ROWS;
				fruitColNew = rand() % COLS;
			}
		}
	}
}

void SnakeGame::initBackgroundMusic() {

	if (soundManager.loadMusic("C:/Users/User/Desktop/Mp3's/BackGroundSound.mp3")) {
		soundManager.play();
		Mix_VolumeMusic(64);
	}
}

SDL_Texture* SnakeGame::renderBackground(const char* path) {

	SDL_Surface* surface = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture;
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

	if (btnsState == BTN_INACTIVE) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	else if (btnsState == BTN_ACTIVE){
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}
	SDL_RenderFillRect(renderer, &startButtonRect);
	renderText("Start", startButtonRect.x + 75, startButtonRect.y + 33, textColor);
	//----------------------------
	int infoButtonDuration = currentTime - infoButtonClickTime;
	if (infoButtonClicked && infoButtonDuration < 200) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}
	else {
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		infoButtonClicked = false;
	}
	SDL_RenderFillRect(renderer, &infoButtonRect);
	renderText("Game Info", infoButtonRect.x + 10, infoButtonRect.y + 33, textColor);	
}

void SnakeGame::render() {

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, backgroundTexture, &rectBGR, &drectBGR);

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

	/*SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	for (int i = 0; i < fruitsVect.size(); i++) {
		SDL_Rect fruitRect = { fruitsVect.at(i).second * TILE_SIZE, fruitsVect.at(i).first * TILE_SIZE, TILE_SIZE, TILE_SIZE };
		SDL_RenderFillRect(renderer, &fruitRect);
	}*/
	// Render snake fruit image texture instead of filled rectangles
	for (int i = 0; i < fruitsVect.size(); i++) {
		SDL_Rect fruitRect = { fruitsVect.at(i).second * TILE_SIZE, fruitsVect.at(i).first * TILE_SIZE, TILE_SIZE, TILE_SIZE };
		SDL_RenderCopy(renderer, snakeFruitTexture, NULL, &fruitRect);
	}

	SDL_Rect buttonAreaRect = { COLS * TILE_SIZE, 0, 400, ROWS * TILE_SIZE };
	SDL_RenderFillRect(renderer, &buttonAreaRect);
	SDL_RenderCopy(renderer, buttonsBackgroundTexture, nullptr, &buttonAreaRect);

	renderButtons();

	SDL_Color greenColor = { 0, 255, 0, 255 };
	string pointsText = "Points: " + to_string(fruitsEaten);

	SDL_Surface* pointsSurface = TTF_RenderText_Blended(font, pointsText.c_str(), greenColor);
	SDL_Texture* pointsTexture = SDL_CreateTextureFromSurface(renderer, pointsSurface);

	SDL_Rect pointsRect = { pointFieldX, pointFieldY, pointsSurface->w, pointsSurface->h };

	SDL_RenderCopy(renderer, pointsTexture, NULL, &pointsRect);
	SDL_FreeSurface(pointsSurface);
	SDL_DestroyTexture(pointsTexture);

	if (gameState == GAME_OVER || gameState == GAME_INACTIVE) {
		SDL_Color redColor = { 255, 0, 0, 255 };
		renderText("Game Over!", COLS * TILE_SIZE / 2 - 100, ROWS * TILE_SIZE / 2 - 35, redColor);
	}

	if (gameState == GAME_PAUSED) {
		SDL_RenderCopy(renderer, infoRulesTexture, &rectRules, &dRectRules);
	}
	SDL_RenderPresent(renderer);
}

void SnakeGame::InitStartingParameters() {

	fruitsEaten = 0; 
	points = 0;

	pointFieldX = COLS * TILE_SIZE + 10;
	pointFieldY = 10;

	isPause = false;
	startedMoving = false;
	inInfoMode = false;

	snake.row = ROWS / 2;
	snake.col = COLS / 2;
	snake.direction = static_cast<Direction>(rand() % 3 + 1);

	srand(time(nullptr));

	fruitRow = rand() % ROWS;
	fruitCol = rand() % COLS;

	fruitsVect.clear();
	fruitsVect.push_back(make_pair(fruitRow, fruitCol));

	bodyQue.clear();
	bodyQue.push_front(make_pair(snake.row, snake.col));

	lastDirection = RIGHT;
	
	gameState = GAME_INITIAL;
	prevGameState = gameState;
	btnsState = BTN_ACTIVE;
}

SnakeGame::~SnakeGame() {
	SDL_DestroyTexture(startTextTexture);
	SDL_DestroyTexture(infoTextTexture);
	SDL_DestroyTexture(snakeFruitTexture);
	SDL_DestroyTexture(infoRulesTexture);
	SDL_DestroyTexture(buttonsBackgroundTexture);
	SDL_DestroyTexture(backgroundTexture);
	TTF_CloseFont(font);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}