#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Moveable
{
public:
	
	glm::vec3 Position;
	glm::vec3 Rotation;
	glm::vec3 Scale;
	Moveable()
		:Position(0.0f), Rotation(0.0f), Scale(1.0f)
	{}
	glm::mat4 GetModel()
	{
		glm::mat4 model = glm::identity<glm::mat4>();

		model = glm::translate(model, Position);
		model = glm::rotate(model, glm::radians(Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, Scale);
		return model;
	}
};
