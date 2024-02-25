
#include "Music.h"

Music::Music() {

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

bool Music::loadSoundEffects(const string& fruitPath, const string& wallCollisionPath, const string& clickPath) {

    fruitSound = Mix_LoadWAV(fruitPath.c_str());
    wallCollisionSound = Mix_LoadWAV(wallCollisionPath.c_str());
    bodyCollisionSound = Mix_LoadWAV(clickPath.c_str());

    if (fruitSound == nullptr || wallCollisionSound == nullptr || bodyCollisionSound == nullptr) {
        cout << "Error on sound" << endl;
        return false;
    }
    return true; 
}

void Music::play() {
    Mix_PlayMusic(music, -1) == -1; 
}

void Music::playFruitSound(const string& filePath) {
    Mix_PlayChannel(-1, fruitSound, 0);
}

void Music::playCollisionSound(const string& filePath) {
    Mix_PlayChannel(-1, wallCollisionSound, 0);
}

void Music::playClickSound(const string& filePath) {
    Mix_PlayChannel(-1, bodyCollisionSound, 0);
}

Music::~Music() {
    Mix_FreeMusic(music);
    Mix_FreeChunk(fruitSound);
    Mix_FreeChunk(wallCollisionSound);
    Mix_FreeChunk(bodyCollisionSound);
    Mix_CloseAudio();
}