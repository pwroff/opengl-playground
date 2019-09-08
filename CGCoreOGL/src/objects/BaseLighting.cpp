#include "BaseLighting.h"
#include "core.h"
#include "Cube.h"
#include "core/Camera.h"

BaseLighting::BaseLighting()
	:
	Color(1.0f)
{
	std::vector<ShaderBit> sbits = {
		{"assets/shaders/vertexBasic.vert.glsl", GL_VERTEX_SHADER},
		{"assets/shaders/fragmentLight.frag.glsl", GL_FRAGMENT_SHADER}
	};
	shaderProgram = Shader(sbits);
}

void BaseLighting::Init()
{
	uint VBO = Cube::GetBuffer();
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	// we only need to bind to the VBO, the container's VBO's data already contains the correct data.
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// set the vertex attributes (only position data for our lamp)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void BaseLighting::Update(float deltaTime)
{
}

void BaseLighting::Render()
{
	shaderProgram.use();
	glBindVertexArray(VAO);
	Camera camera = *Camera::GetInstance();

	glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), camera.Aspect, 0.01f, 100.0f);
	shaderProgram.setMat4("projection", projection);

	// camera/view transformation
	glm::mat4 view = camera.GetViewMatrix();
	shaderProgram.setMat4("view", view);
	glBindVertexArray(VAO);

	glm::mat4 model = this->Moveable::GetModel();

	shaderProgram.setMat4("model", model);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

BaseLighting::~BaseLighting()
{
}
