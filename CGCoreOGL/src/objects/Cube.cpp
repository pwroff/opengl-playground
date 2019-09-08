#include "Cube.h"
#include "core/Camera.h"
#include <iostream>

using namespace std;

char texPath[] = "assets/textures/wall.jpg";
char tex2Path[] = "assets/textures/awesomeface.png";
Texture2D *texture1 = nullptr;
Texture2D *texture2 = nullptr;

uint Cube::GetBuffer()
{
	static bool initialized = false;
	static uint VBO;
	if (!initialized)
	{
		initialized = true;
		float vertices[] = {
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f, 0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 0.0f, -1.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f, -1.0f, 0.0f, 0.0f,

			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
			 0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 0.0f, -1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			 0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 0.0f, -1.0f, 0.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 0.0f
		};
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	}
	return VBO;
}

Cube::Cube()
	:Color(1.0f, 0, 0, 1.0f)
{
	
	std::vector<ShaderBit> sbits =
	{
		{"assets/shaders/vertexBasic.vert.glsl", GL_VERTEX_SHADER},
		{"assets/shaders/fragmentBasic.frag.glsl", GL_FRAGMENT_SHADER}
	};
	shaderProgram = Shader(sbits);
	if (texture1 == nullptr)
	{ 
		texture1 = &Texture2D::FromFile(texPath);
		texture2 = &Texture2D::FromFile(tex2Path);
	}
}

void Cube::Init()
{
	glGenVertexArrays(1, &VAO);
	VBO = Cube::GetBuffer();
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindVertexArray(VAO);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture coord attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// normal coord attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void Cube::Update(float deltaTime)
{
	this->IObject::Update(deltaTime);

	Rotation.x += 5.0f*deltaTime;
	Rotation.y += 10.0f*deltaTime*VAO;
	Rotation.z += 10.0f*deltaTime;
}

void Cube::Render()
{
	this->IObject::Render();
	shaderProgram.use();
	
	shaderProgram.setInt("texture1", 0);
	shaderProgram.setInt("texture2", 1);

	texture1->use(GL_TEXTURE0);
	texture2->use(GL_TEXTURE1);

	Camera camera = *Camera::GetInstance();
	
	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), camera.Aspect, 0.01f, 100.0f);
	shaderProgram.setMat4("projection", projection);

	// camera/view transformation
	glm::mat4 view = camera.GetViewMatrix();
	shaderProgram.setMat4("view", view);
	glBindVertexArray(VAO);

	glm::mat4 model = this->Moveable::GetModel();

	shaderProgram.setMat4("model", model);
	shaderProgram.setVec4("objectColor", Color);

	if (light)
	{
		shaderProgram.setVec4("lightColor", light->Color);
		shaderProgram.setVec3("lightPosition", light->Position);
		shaderProgram.setVec4("uWarmColor", glm::vec4(0.25f, 0.25f, 0.45f, 1.0f));
		shaderProgram.setVec3("uEyePosition", camera.Position);
	}

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

Cube::~Cube()
{
	glDeleteVertexArrays(1, &VAO);
}
