#pragma once
#include "core.h"
#include <map>

class Input
{

private:
	GLFWwindow * window = NULL;

public:
	Input(GLFWwindow * win);
	~Input();
	void Update();

public:
	static std::map<int, bool> KeyPressed;
	static bool MouseMoved;
	static bool MouseOnePreesed;
	static bool MouseTwoPreesed;
	static bool MouseThreePreesed;
	static float MouseX;
	static float MouseY;
};

