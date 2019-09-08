#pragma once
#include "core.h"
#include <functional>

class Engine
{
public:
	Engine(Vec2<uint> winsize);
	~Engine();
	void Run(std::function<void(float)> rendFunc);
private:
	bool Init();
	void Cleanup();
private:
	Vec2<uint> windowSize;
	GLFWwindow * window = NULL;
};
