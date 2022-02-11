#pragma once
#include "Renderer.h"
class Animation2D : public Renderer
{
	int _currentFrame;
	int totalFrames;
	float currentTime;
	float timeBetweenFrames;
	float speed;
public:
	Animation2D(std::string _path, RenderManager* renderManager, int total_frames);
	virtual void Update(double elapsedTime) override;
	void Play(float _speed);
	void NextFrame();
	void SetFrame(int frame);
	bool loop;
};

