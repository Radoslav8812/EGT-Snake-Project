
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
    Mix_Chunk* fruitSound;
    Mix_Chunk* wallCollisionSound;
    Mix_Chunk* bodyCollisionSound;

public:
    Music();
    ~Music();

    bool loadMusic(const string& filePath);
    bool loadSoundEffects(const string& fruitPath, const string& wallCollisionPath, const string& clickPath);
   
    void play();
    void playFruitSound(const string& filePath);
    void playCollisionSound(const string& filePath);
    void playClickSound(const string& filePath);
};

#endif 