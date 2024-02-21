
#include "Music.h"

Music::Music() : music(nullptr) {

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {

        cerr << "Mixer Error: " << Mix_GetError() << endl;
    }
}

Music::~Music() {

    if (music != nullptr) {
        Mix_FreeMusic(music);
    }
    Mix_CloseAudio();
}

bool Music::loadMusic(const string& filePath) {

    music = Mix_LoadMUS(filePath.c_str());

    if (music == nullptr) {
        cerr << "Failed to load music!" << endl;
        return false;
    }
    return true;
}

void Music::play() {

    if (Mix_PlayMusic(music, -1) == -1) {
        cerr << "Failed to play music!" << endl;
    }
}

void Music::pause() {
    Mix_PauseMusic();
}

void Music::resume() {
    Mix_ResumeMusic();
}

void Music::stop() {
    Mix_HaltMusic();
}
