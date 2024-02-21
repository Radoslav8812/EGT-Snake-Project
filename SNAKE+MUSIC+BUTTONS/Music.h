
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <SDL_mixer.h>

using namespace std;

#include <SDL_mixer.h>
#include <string>

class Music {

private:
    Mix_Music* music;

public:
    Music();
    ~Music();

    bool loadMusic(const string& filePath);
    void play();
    void pause();
    void resume();
    void stop();
};

#endif 