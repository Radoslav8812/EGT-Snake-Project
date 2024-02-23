
#include "Music.h"

Music::Music() : music(nullptr) {

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {

        cerr << "Mixer Error: " << Mix_GetError() << endl;
    }

    music = nullptr;
    fruitSound = nullptr;
    wallCollisionSound = nullptr;
    bodyCollisionSound = nullptr;
}


bool Music::loadMusic(const string& filePath) {

    music = Mix_LoadMUS(filePath.c_str());

    if (music == nullptr) {
        cerr << "Failed to load music!" << endl;
        return false;
    }
    return true;
}

bool Music::loadSoundEffects(const string& fruitPath, const string& wallCollisionPath, const string& bodyCollisionPath) {
    // Load sound effects
    fruitSound = Mix_LoadWAV(fruitPath.c_str());
    wallCollisionSound = Mix_LoadWAV(wallCollisionPath.c_str());
    bodyCollisionSound = Mix_LoadWAV(bodyCollisionPath.c_str());

    if (fruitSound == nullptr || wallCollisionSound == nullptr || bodyCollisionSound == nullptr) {
        cout << "Error on sound" << endl;
        return false;
    }

    return true;
}

void Music::play() {

    if (Mix_PlayMusic(music, -1) == -1) {
        cerr << "Failed to play music!" << endl;
    }
}

void Music::playFruitSound(const string& filePath) {
    Mix_PlayChannel(-1, fruitSound, 0);
}

void Music::playWallCollisionSound(const string& filePath) {
    Mix_PlayChannel(-1, wallCollisionSound, 0);
}

void Music::playBodyCollisionSound(const string& filePath) {
    Mix_PlayChannel(-1, bodyCollisionSound, 0);
}


Music::~Music() {
    // Free the music and sound effects
    Mix_FreeMusic(music);
    Mix_FreeChunk(fruitSound);
    Mix_FreeChunk(wallCollisionSound);
    Mix_FreeChunk(bodyCollisionSound);

    // Quit SDL Mixer
    Mix_CloseAudio();
}