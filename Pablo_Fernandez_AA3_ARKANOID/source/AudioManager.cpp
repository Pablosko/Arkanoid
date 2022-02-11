#include "AudioManager.h"
AudioManager* AudioManager::_instance;
AudioManager::AudioManager()
{
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);

	MenuMusic = Mix_LoadMUS("resources/music/menuMusic.wav");
	GameMusic = Mix_LoadMUS("resources/music/gameMusic.wav");

	lifeLose = Mix_LoadWAV("resources/music/effects/lifeLose.wav");
	ballHit = Mix_LoadWAV("resources/music/effects/ballHit.wav");
}

AudioManager* AudioManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new AudioManager();

	return _instance;
}

void AudioManager::PlayEffect(Mix_Chunk* effect)
{
	if (nullifiedAudio)
		return;
	Mix_PlayChannel(-1, effect, 0);
}

void AudioManager::PlayMusic(Mix_Music* music)
{
	if (nullifiedAudio)
		return;
	StopMusic();

	backgroundMusic = music;
	Mix_PlayMusic(backgroundMusic, -1);
}
void AudioManager::StopMusic()
{
	if (backgroundMusic != nullptr)
		Mix_FreeMusic(backgroundMusic);
}
void AudioManager::NullAudio()
{
	nullifiedAudio = true;
	StopMusic();
}




