#include "SnakeGame.h"
#include "Music.h"
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

float initialSpeed = 200;

SnakeGame::SnakeGame() {

	fruitsEaten = 0;
	points = 0;
	isPause = false;
	startedMoving = false;
	speed = 1;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
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

	// Initialize button positions in the middle of the button area
	int buttonAreaCenterX = COLS * TILE_SIZE + 200;  // Adjust as needed
	int buttonAreaCenterY = ROWS * TILE_SIZE / 2;

	// Initialize button positions in the middle of the button area
	int buttonWidth = 200;
	int buttonHeight = 50;

	// Start button
	int startButtonX = buttonAreaCenterX - buttonWidth / 2;
	int startButtonY = buttonAreaCenterY - buttonHeight / 2 - 60;  // Adjust the vertical position as needed
	startButtonRect = { startButtonX, startButtonY, buttonWidth, buttonHeight };

	// Info button
	int infoButtonX = buttonAreaCenterX - buttonWidth / 2;
	int infoButtonY = buttonAreaCenterY - buttonHeight / 2 + 10;  // Adjust the vertical position as needed
	infoButtonRect = { infoButtonX, infoButtonY, buttonWidth, buttonHeight };

	inInfoMode = false;

	TTF_Init();
	font = TTF_OpenFont("C:/Users/User/Desktop/fonts/arial.ttf", 24); // Replace with the actual path to your font file and desired font size

	if (!font) {
		// Handle font loading error
		cout << "Failed to load font!" << endl;
	}

	// Render text labels
	startTextSurface = TTF_RenderText_Blended(font, "Start", textColor);
	infoTextSurface = TTF_RenderText_Blended(font, "Game Info", textColor);

	// Convert text surfaces to textures
	startTextTexture = SDL_CreateTextureFromSurface(renderer, startTextSurface);
	infoTextTexture = SDL_CreateTextureFromSurface(renderer, infoTextSurface);

	// Free the surfaces
	SDL_FreeSurface(startTextSurface);
	SDL_FreeSurface(infoTextSurface);
}


bool SnakeGame::isPaused() const{
	return isPause;
}
void SnakeGame::togglePause() {

	if (startedMoving) {
		isPause = !isPause;
	}
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
			// Check if the new direction is not opposite to the last direction
			if (!isOppositeDirection(snake.direction, newDirection)) {
				snake.direction = newDirection;
				lastDirection = newDirection;
			}
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			// Check if the left mouse button was clicked
			if (e.button.button == SDL_BUTTON_LEFT) {
				int mouseX = e.button.x;
				int mouseY = e.button.y;

				// Check if the click is within the start button
				if (mouseX >= startButtonRect.x && mouseX <= startButtonRect.x + startButtonRect.w &&
					mouseY >= startButtonRect.y && mouseY <= startButtonRect.y + startButtonRect.h) {
					// Handle start button click
					cout << "Start button clicked!" << endl;
					// Add your start button functionality here

					// Example: Resume the game by setting isPause to false
					isPause = false;
				}

				// Check if the click is within the info button
				else if (mouseX >= infoButtonRect.x && mouseX <= infoButtonRect.x + infoButtonRect.w &&
					mouseY >= infoButtonRect.y && mouseY <= infoButtonRect.y + infoButtonRect.h) {
					// Handle info button click
					cout << "Info button clicked!" << endl;
					// Add your info button functionality here
					isPause = true; // Toggle pause when info button is clicked for demonstration
				}
			}
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

		if (snake.row == it->first && snake.col == it->second) {

			it = fruitsVect.erase(it);
			activateOR = true;
			bodyQue.push_front(make_pair(snake.row, snake.col));

			fruitsEaten++;
			points++;

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

void SnakeGame::initCoverInfo() {
	// Load your info image
	SDL_Surface* infoSurface = IMG_Load("C:/Users/User/Desktop/4.png");
	if (!infoSurface) {
		// Handle image loading error
		cout << "Failed to load cover image! SDL_image Error: " << IMG_GetError() << endl;
	}
	else {
		infoTexture = SDL_CreateTextureFromSurface(renderer, infoSurface);
		if (!infoTexture) {
			// Handle texture creation error
			cout << "Failed to create texture from cover image! SDL Error: " << SDL_GetError() << endl;
		}
		SDL_FreeSurface(infoSurface);
	}
}

void SnakeGame::renderButtons() {
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set color to white for buttons

	// Render start button
	SDL_RenderFillRect(renderer, &startButtonRect);
	renderText("Start", startButtonRect.x + 10, startButtonRect.y + 10); // Adjust the position as needed

	// Render info button
	SDL_RenderFillRect(renderer, &infoButtonRect);
	renderText("Game Info", infoButtonRect.x + 10, infoButtonRect.y + 10); // Adjust the position as needed
}

void SnakeGame::renderText(const char* text, int x, int y) {
	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text, textColor);
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

	SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

	SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}

void SnakeGame::render() {

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	// If the game is paused, render the info cover
	if (isPause) {
		SDL_Rect infoRect = { 0, 0, COLS * TILE_SIZE, ROWS * TILE_SIZE };
		SDL_RenderCopy(renderer, infoTexture, NULL, &infoRect);
	}
	else {
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
			SDL_Rect fruitRect = { fruitsVect.at(i).second * TILE_SIZE, fruitsVect.at(i).first * TILE_SIZE, TILE_SIZE,
								  TILE_SIZE };
			SDL_RenderFillRect(renderer, &fruitRect);
		}
		//render points:
		renderText(("Points: " + to_string(fruitsEaten)).c_str(), COLS * TILE_SIZE + 10, 10);
	}

	// Render buttons
	renderButtons();
	SDL_RenderPresent(renderer);
}

SnakeGame::~SnakeGame() {

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_DestroyTexture(infoTexture); // Add this line
	SDL_Quit();
}
