#pragma once
#include "core.h"

class Texture2D
{
private:
	uint ID;
	Vec2<uint> size;
	uint channels;
	uchar * data = nullptr;
	bool loaded = false;

public:
	Texture2D(Vec2<uint> texsize, uint nChannels);
	~Texture2D();
	void createGPUResource();
	void setData(uchar * bdata);
	void use(int slot = GL_TEXTURE0);

	static Texture2D FromFile(char * path);
};
