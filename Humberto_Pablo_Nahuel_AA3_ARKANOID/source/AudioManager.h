#pragma once
#include <string>
#include <map>
#include <vector>
#include "SDL.h"
#include "SDL_audio.h"
#include "SDL_mixer.h"
#include "Vector2D.h"

class AudioManager
{
private:
	AudioManager();
	static AudioManager* _instance;
	Mix_Music* backgroundMusic;

public:
	Mix_Music* MenuMusic;
	Mix_Music* GameMusic;

	Mix_Chunk* lifeLose;
	Mix_Chunk* ballHit;
	bool nullifiedAudio;
	static AudioManager* GetInstance();
	void PlayEffect(Mix_Chunk* effect);
	void PlayMusic(Mix_Music* music);
	void NullAudio();
	void StopMusic();
	

};
