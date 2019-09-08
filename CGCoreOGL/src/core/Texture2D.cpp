#include "core/Texture2D.h"
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

Texture2D::Texture2D(Vec2<uint> texsize, uint nChannels)
{
	size = texsize;
	channels = nChannels;
}

Texture2D::~Texture2D()
{
	if (data)
	{
		stbi_image_free(data);
		data = nullptr;
	}
	loaded = false;
}

void Texture2D::createGPUResource()
{
	if (data)
	{
		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, channels == 3 ? GL_RGB : GL_RGBA, size.x, size.y, 0, channels == 3 ? GL_RGB : GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		loaded = true;
		stbi_image_free(data);
		data = nullptr;
	}
	
}

void Texture2D::setData(uchar * bdata)
{
	data = bdata;
}

void Texture2D::use(int slot)
{
	if (loaded)
	{
		glActiveTexture(slot);
		glBindTexture(GL_TEXTURE_2D, ID);
	}
}

Texture2D Texture2D::FromFile(char * path)
{
	int width;
	int height;
	int nrChannels;
	stbi_set_flip_vertically_on_load(true);
	uchar* data = stbi_load(path, &width, &height, &nrChannels, 0);

	if (data == nullptr)
	{
		std::cout << "Failed to load texture: " << path << "\n";
	}
	Texture2D tex({ (uint)width, (uint)height }, (uint)nrChannels);
	tex.setData(data);
	tex.createGPUResource();

	return tex;
}
