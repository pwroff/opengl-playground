#include "core/Engine.h"
#include <iostream>
#include "core/Shader.h"
#include "core/Texture2D.h"
#include "core/Input.h"
#include "core/Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "objects/Cube.h"
#include "objects/BaseLighting.h"
#include "core/Level.h"

class CubesLevel : public Level
{
	BaseLighting* lighting;
	std::vector<IObject*> sceneObjects;
public:
	void Init() override
	{
		lighting = new BaseLighting;
		lighting->Scale = glm::vec3(0.05f);
		lighting->Position.y = 0.75f;
		lighting->Position.x = 0.75f;
		lighting->Position.z = 1.75f;

		glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
		};
		for (unsigned int i = 0; i < 10; i++)
		{
			Cube *c = new Cube;

			c->Init();
			c->Position = cubePositions[i];
			c->light = lighting;
			sceneObjects.push_back(c);
		}
	}

	void Update(float deltaTime) override
	{
		lighting->Update(deltaTime);
		for (size_t i = 0; i < sceneObjects.size(); i++)
		{
			sceneObjects[i]->Update(deltaTime);
		}
	}

	void Render() override
	{
		lighting->Render();
		for (size_t i = 0; i < sceneObjects.size(); i++)
		{
			sceneObjects[i]->Render();
		}
	}
};

int run()
{
	Vec2<uint> winSize(800, 600);
	Engine e(winSize);
	CubesLevel level;
	level.Init();
	Camera * camera = Camera::GetInstance();
	camera->Position = glm::vec3(0.0f, 0.0f, 3.0f);
	auto rendFunc = [&](float deltaTime)
	{
		camera->Tick(deltaTime);
		// render
		// ------
		level.Update(deltaTime);
		level.Render();

	};
	// render loop
	// -----------
	e.Run(rendFunc);

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------
	
	return 0;
}

int main(int argc, char ** argv)
{
	int r = run();
	if (r != 0)
	{
		system("pause");
	}
	return r;
}
